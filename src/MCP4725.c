#include "MCP4725.h"

//初始化IIC
void IIC_Init(void)
{					     
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(	IIC_SCL_RCC_GPIOx_NEW, ENABLE );	//使能GPIOA时钟
	   
	GPIO_InitStructure.GPIO_Pin = IIC_SCL_PIN_NEW;         // PB10 ->SCL
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ;   //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(IIC_SCL_GPIOx_NEW, &GPIO_InitStructure);
	GPIO_SetBits(IIC_SCL_GPIOx_NEW,IIC_SCL_PIN_NEW); 	//PA4,PA5 输出高，因为IIC空闲状态都是高电平
	
	RCC_APB2PeriphClockCmd(	IIC_SDA_RCC_GPIOx_NEW, ENABLE );	//使能GPIOB时钟
	GPIO_InitStructure.GPIO_Pin = IIC_SDA_PIN_NEW;         // PB11->SDA
	GPIO_Init(IIC_SDA_GPIOx_NEW, &GPIO_InitStructure);
	GPIO_SetBits(IIC_SDA_GPIOx_NEW,IIC_SDA_PIN_NEW); 	//PA4,PA5 输出高，因为IIC空闲状态都是高电平
}

//SDA设置为输入
void SDA_IN (void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(	IIC_SDA_RCC_GPIOx_NEW, ENABLE );	
    GPIO_InitStructure.GPIO_Pin = IIC_SDA_PIN_NEW; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING; 
    GPIO_Init(IIC_SDA_GPIOx_NEW, &GPIO_InitStructure);
}

//SDA设置为输出
void SDA_OUT(void)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(	IIC_SDA_RCC_GPIOx_NEW, ENABLE );	
    GPIO_InitStructure.GPIO_Pin = IIC_SDA_PIN_NEW; 
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP ; 
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(IIC_SDA_GPIOx_NEW, &GPIO_InitStructure);
}
//产生IIC起始信号
void IIC_Start(void)
{
	SDA_OUT();     //sda线设置为输出
	IIC_SDA=1;	  	  
	IIC_SCL=1;
	delay_us(10);
 	IIC_SDA=0;     //START:when CLK is high,DATA change form high to low 
	delay_us(10);
	IIC_SCL=0;     //钳住I2C总线，准备发送或接收数据 
}	  
//产生IIC停止信号
void IIC_Stop(void)
{
	SDA_OUT();//sda线输出
	IIC_SCL=0;
	IIC_SDA=0;//STOP:when CLK is high DATA change form low to high
 	delay_us(10);
	IIC_SCL=1; 
	IIC_SDA=1;//发送I2C总线结束信号
	delay_us(10);							   	
}
//等待应答信号到来
//返回值：1，接收应答失败
//        0，接收应答成功
u8 IIC_Wait_Ack(void)
{
	u8 ucErrTime=0;
	SDA_IN();      //SDA设置为输入  
	IIC_SDA=1;delay_us(2);	   
	IIC_SCL=1;delay_us(2);	
	while(READ_SDA)
	{
		ucErrTime++;
		if(ucErrTime>250)
		{
			IIC_Stop();
			return 1;
		}
	}
	IIC_SCL=0;//时钟输出0 	   
	return 0;  
} 
//产生ACK应答
void IIC_Ack(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=0;
	delay_us(5);
	IIC_SCL=1;
	delay_us(5);
	IIC_SCL=0;
}
//不产生ACK应答		    
void IIC_NAck(void)
{
	IIC_SCL=0;
	SDA_OUT();
	IIC_SDA=1;
	delay_us(5);
	IIC_SCL=1;
	delay_us(5);
	IIC_SCL=0;
}					 				     
//IIC发送一个字节
//返回从机有无应答
//1，有应答
//0，无应答			  
void IIC_Send_Byte(u8 txd)
{                        
    u8 t;   
	SDA_OUT(); 	    
    IIC_SCL=0;//拉低时钟开始数据传输
    for(t=0;t<8;t++)    //开始准备信号线
    {              
        //IIC_SDA=(txd&0x80)>>7;
		if((txd&0x80)>>7)
			IIC_SDA=1;
		else
			IIC_SDA=0;
		txd<<=1; 	  
		delay_us(5);   //对TEA5767这三个延时都是必须的
		IIC_SCL=1;
		delay_us(5); 
		IIC_SCL=0;	
		delay_us(5);
    }	 
} 	    
//读1个字节，ack=1时，发送ACK，ack=0，发送nACK   
u8 IIC_Read_Byte(unsigned char ack)
{
	unsigned char i,receive=0;
	SDA_IN();//SDA设置为输入
    for(i=0;i<8;i++ )
	{
        IIC_SCL=0; 
        delay_us(5);
		IIC_SCL=1;
        receive<<=1;
        if(READ_SDA)receive++;   
		delay_us(4); 
    }					 
    if (!ack)
        IIC_NAck();//发送nACK
    else
        IIC_Ack(); //发送ACK   
    return receive;
}

//初始化IIC接口
void MCP4725_Init(void)
{
	IIC_Init();
	MCP4725_WriteData_Voltage(DAC_SET_OYT_VOLTAGE);
}

//使用快速模式写命令写DAC寄存器
void MCP4725_WriteData_Voltage(u16 Vout)   //电压单位mV
{
  u8 temp;
	u16 Dn;
	Dn = ( 4096 * Vout) / DAC_VREF; //这里的VREF_5V宏定义为5000
	temp = (0x0F00 & Dn) >> 8;  //12位数据。0000XXXX XXXXXXXX 
	IIC_Start();
	IIC_Send_Byte(DAC_ADDRESS);      //器件寻址，器件代吗：1100； 地址位A2，A1，A0为 0 ， 0 ， 1；-> 1100 0010
	IIC_Wait_Ack();	 
	IIC_Send_Byte(temp); 	  //将高8位送到DAC寄存器
	IIC_Wait_Ack();	 
	IIC_Send_Byte(Dn);        //将低8位送到DAC寄存器
	IIC_Wait_Ack();	
	IIC_Stop();//产生一个停止条件  	
	delay_ms(10);	
}
 
void MCP4725_WriteData_Digital(u16 data)   //12位数字量
{
	u8 data_H=0,data_L=0;
	data_H = ( 0x0F00 & data) >> 8;
	data_L = 0X00FF & data ;
	IIC_Start();
	IIC_Send_Byte(DAC_ADDRESS);      //器件寻址，器件代吗：1100； 地址位A2，A1，A0为 0 ， 0 ， 0；-> 1100 0010
	IIC_Wait_Ack();	 
	IIC_Send_Byte(data_H); 	
	IIC_Wait_Ack();	 
	IIC_Send_Byte(data_L);
	IIC_Wait_Ack();	
	IIC_Stop();//产生一个停止条件  	
	delay_ms(10);	
}


