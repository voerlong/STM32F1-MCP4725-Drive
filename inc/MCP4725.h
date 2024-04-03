#ifndef MCP4725_H
#define MCP4725_H

#include "stm32f10x.h"
#include "delay.h"
#include "sys.h"
#include "MCP4725config.h"

//选择GPIO口
#define IIC_GPIOA 0
#define IIC_GPIOB 1
#define IIC_GPIOC	2
#define IIC_GPIOD 3
#define IIC_GPIOE 4
#define IIC_GPIOF 5
#define IIC_GPIOG 6

//选PIN脚
#define IIC_PIN_0 0
#define IIC_PIN_1 1
#define IIC_PIN_2 2
#define IIC_PIN_3 3
#define IIC_PIN_4 4
#define IIC_PIN_5 5
#define IIC_PIN_6 6
#define IIC_PIN_7 7
#define IIC_PIN_8 8
#define IIC_PIN_9 9
#define IIC_PIN_10 10
#define IIC_PIN_11 11
#define IIC_PIN_12 12
#define IIC_PIN_13 13
#define IIC_PIN_14 14
#define IIC_PIN_15 15



//宏定义重定义
#if IIC_SCL_PIN == IIC_PIN_0
	#define IIC_SCL_PIN_NEW	GPIO_Pin_0
#elif	IIC_SCL_PIN == IIC_PIN_1
	#define IIC_SCL_PIN_NEW	GPIO_Pin_1
#elif	IIC_SCL_PIN == IIC_PIN_2
	#define IIC_SCL_PIN_NEW	GPIO_Pin_2
#elif	IIC_SCL_PIN == IIC_PIN_3
	#define IIC_SCL_PIN_NEW	GPIO_Pin_3
#elif	IIC_SCL_PIN == IIC_PIN_4
	#define IIC_SCL_PIN_NEW	GPIO_Pin_4
#elif	IIC_SCL_PIN == IIC_PIN_5
	#define IIC_SCL_PIN_NEW	GPIO_Pin_5
#elif	IIC_SCL_PIN == IIC_PIN_6
	#define IIC_SCL_PIN_NEW	GPIO_Pin_6
#elif	IIC_SCL_PIN == IIC_PIN_7
	#define IIC_SCL_PIN_NEW	GPIO_Pin_7
#elif	IIC_SCL_PIN == IIC_PIN_8
	#define IIC_SCL_PIN_NEW	GPIO_Pin_8
#elif	IIC_SCL_PIN == IIC_PIN_9
	#define IIC_SCL_PIN_NEW	GPIO_Pin_9
#elif	IIC_SCL_PIN == IIC_PIN_10
	#define IIC_SCL_PIN_NEW	GPIO_Pin_10
#elif	IIC_SCL_PIN == IIC_PIN_11
	#define IIC_SCL_PIN_NEW	GPIO_Pin_11
#elif	IIC_SCL_PIN == IIC_PIN_12
	#define IIC_SCL_PIN_NEW	GPIO_Pin_12
#elif	IIC_SCL_PIN == IIC_PIN_13
	#define IIC_SCL_PIN_NEW	GPIO_Pin_13
#elif	IIC_SCL_PIN == IIC_PIN_14
	#define IIC_SCL_PIN_NEW	GPIO_Pin_14
#elif	IIC_SCL_PIN == IIC_PIN_15
	#define IIC_SCL_PIN_NEW	GPIO_Pin_15
#endif

#if IIC_SDA_PIN == IIC_PIN_0
	#define IIC_SDA_PIN_NEW	GPIO_Pin_0
#elif	IIC_SDA_PIN == IIC_PIN_1
	#define IIC_SDA_PIN_NEW	GPIO_Pin_1
#elif	IIC_SDA_PIN == IIC_PIN_2
	#define IIC_SDA_PIN_NEW	GPIO_Pin_2
#elif	IIC_SDA_PIN == IIC_PIN_3
	#define IIC_SDA_PIN_NEW	GPIO_Pin_3
#elif	IIC_SDA_PIN == IIC_PIN_4
	#define IIC_SDA_PIN_NEW	GPIO_Pin_4
#elif	IIC_SDA_PIN == IIC_PIN_5
	#define IIC_SDA_PIN_NEW	GPIO_Pin_5
#elif	IIC_SDA_PIN == IIC_PIN_6
	#define IIC_SDA_PIN_NEW	GPIO_Pin_6
#elif	IIC_SDA_PIN == IIC_PIN_7
	#define IIC_SDA_PIN_NEW	GPIO_Pin_7
#elif	IIC_SDA_PIN == IIC_PIN_8
	#define IIC_SDA_PIN_NEW	GPIO_Pin_8
#elif	IIC_SDA_PIN == IIC_PIN_9
	#define IIC_SDA_PIN_NEW	GPIO_Pin_9
#elif	IIC_SDA_PIN == IIC_PIN_10
	#define IIC_SDA_PIN_NEW	GPIO_Pin_10
#elif	IIC_SDA_PIN == IIC_PIN_11
	#define IIC_SDA_PIN_NEW	GPIO_Pin_11
#elif	IIC_SDA_PIN == IIC_PIN_12
	#define IIC_SDA_PIN_NEW	GPIO_Pin_12
#elif	IIC_SDA_PIN == IIC_PIN_13
	#define IIC_SDA_PIN_NEW	GPIO_Pin_13
#elif	IIC_SDA_PIN == IIC_PIN_14
	#define IIC_SDA_PIN_NEW	GPIO_Pin_14
#elif	IIC_SDA_PIN == IIC_PIN_15
	#define IIC_SDA_PIN_NEW	GPIO_Pin_15
#endif

#if IIC_SCL_GPIOx == IIC_GPIOA
	#define IIC_SCL_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOA
	#define IIC_SCL_GPIOx_NEW GPIOA
	#define IIC_SCL    PAout(IIC_SCL_PIN) //SCL
#elif IIC_SCL_GPIOx == IIC_GPIOB
	#define IIC_SCL_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOB
	#define IIC_SCL_GPIOx_NEW GPIOB
	#define IIC_SCL    PBout(IIC_SCL_PIN) //SCL
#elif IIC_SCL_GPIOx == IIC_GPIOC
	#define IIC_SCL_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOC
	#define IIC_SCL_GPIOx_NEW GPIOC
	#define IIC_SCL    PCout(IIC_SCL_PIN) //SCL
#elif IIC_SCL_GPIOx == IIC_GPIOD
	#define IIC_SCL_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOD
	#define IIC_SCL_GPIOx_NEW GPIOD
	#define IIC_SCL    PDout(IIC_SCL_PIN) //SCL	
#elif IIC_SCL_GPIOx == IIC_GPIOE
	#define IIC_SCL_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOE
	#define IIC_SCL_GPIOx_NEW GPIOE
	#define IIC_SCL    PEout(IIC_SCL_PIN) //SCL
#elif IIC_SCL_GPIOx == IIC_GPIOF
	#define IIC_SCL_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOF
	#define IIC_SCL_GPIOx_NEW GPIOF
	#define IIC_SCL    PFout(IIC_SCL_PIN) //SCL
#elif IIC_SCL_GPIOx == IIC_GPIOG
	#define IIC_SCL_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOG
	#define IIC_SCL_GPIOx_NEW GPIOG
	#define IIC_SCL    PGout(IIC_SCL_PIN) //SCL
#endif



#if IIC_SDA_GPIOx == IIC_GPIOA
	#define IIC_SDA_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOA
	#define IIC_SDA_GPIOx_NEW GPIOA
	#define IIC_SDA    PAout(IIC_SDA_PIN) //SDA	 
	#define READ_SDA   PAin(IIC_SDA_PIN)  //输入SDA 
#elif IIC_SDA_GPIOx == IIC_GPIOB
	#define IIC_SDA_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOB
	#define IIC_SDA_GPIOx_NEW GPIOB
	#define IIC_SDA    PBout(IIC_SDA_PIN) //SDA	 
	#define READ_SDA   PBin(IIC_SDA_PIN)  //输入SDA 
#elif IIC_SDA_GPIOx == IIC_GPIOC
	#define IIC_SDA_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOC
	#define IIC_SDA_GPIOx_NEW GPIOC
	#define IIC_SDA    PCout(IIC_SDA_PIN) //SDA	 
	#define READ_SDA   PCin(IIC_SDA_PIN)  //输入SDA 
#elif IIC_SDA_GPIOx == IIC_GPIOD
	#define IIC_SDA_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOD
	#define IIC_SDA_GPIOx_NEW GPIOD
	#define IIC_SDA    PDout(IIC_SDA_PIN) //SDA	 
	#define READ_SDA   PDin(IIC_SDA_PIN)  //输入SDA 
#elif IIC_SDA_GPIOx == IIC_GPIOE
	#define IIC_SDA_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOE
	#define IIC_SDA_GPIOx_NEW GPIOE
	#define IIC_SDA    PEout(IIC_SDA_PIN) //SDA	 
	#define READ_SDA   PEin(IIC_SDA_PIN)  //输入SDA 
#elif IIC_SDA_GPIOx == IIC_GPIOF
	#define IIC_SDA_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOF
	#define IIC_SDA_GPIOx_NEW GPIOF
	#define IIC_SDA    PFout(IIC_SDA_PIN) //SDA	 
	#define READ_SDA   PFin(IIC_SDA_PIN)  //输入SDA 
#elif IIC_SDA_GPIOx == IIC_GPIOG
	#define IIC_SDA_RCC_GPIOx_NEW	 RCC_APB2Periph_GPIOG
	#define IIC_SDA_GPIOx_NEW GPIOG
	#define IIC_SDA    PGout(IIC_SDA_PIN) //SDA	 
	#define READ_SDA   PGin(IIC_SDA_PIN)  //输入SDA 
#endif

//IIC所有操作函数
void IIC_Init(void);                //初始化IIC的IO口				 
void IIC_Start(void);				//发送IIC开始信号
void IIC_Stop(void);	  			//发送IIC停止信号
void IIC_Send_Byte(u8 txd);			//IIC发送一个字节
u8 IIC_Read_Byte(unsigned char ack);//IIC读取一个字节
u8 IIC_Wait_Ack(void); 				//IIC等待ACK信号
void IIC_Ack(void);			        //IIC发送ACK信号
void IIC_NAck(void);				//IIC不发送ACK信号

void SDA_IN(void);
void SDA_OUT(void);

void IIC_Write_One_Byte(u8 daddr,u8 addr,u8 data);
u8 IIC_Read_One_Byte(u8 daddr,u8 addr);	  


//主要函数
void MCP4725_Init(void); //DAC初始化函数
void MCP4725_WriteData_Digital(u16 data);//写入数据
void MCP4725_WriteData_Voltage(u16 Vout);//写入电压(单位：毫伏)

#endif
