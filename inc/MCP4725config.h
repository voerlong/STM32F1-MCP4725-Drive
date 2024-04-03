#ifndef MCP4725CONFIG_H
#define MCP4725CONFIG_H

//设置IIC的IO口
//IIC的SCL端口设置
#define IIC_SCL_GPIOx 				IIC_GPIOB
#define IIC_SCL_PIN 					IIC_PIN_10

//IIC的SDA端口设置
#define IIC_SDA_GPIOx 				IIC_GPIOB
#define IIC_SDA_PIN 					IIC_PIN_11

//DAC参考电压（MCP4725参考电压一般都是电源正极）（单位：毫伏）
#define DAC_VREF      				5000

//初始化时，DAC输出的电压（单位：毫伏）
#define DAC_SET_OYT_VOLTAGE 	2500

//设置DAC地址信息
#define DAC_ADDRESS 					0XC0

#endif
