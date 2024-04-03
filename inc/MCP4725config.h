#ifndef MCP4725CONFIG_H
#define MCP4725CONFIG_H

//����IIC��IO��
//IIC��SCL�˿�����
#define IIC_SCL_GPIOx 				IIC_GPIOB
#define IIC_SCL_PIN 					IIC_PIN_10

//IIC��SDA�˿�����
#define IIC_SDA_GPIOx 				IIC_GPIOB
#define IIC_SDA_PIN 					IIC_PIN_11

//DAC�ο���ѹ��MCP4725�ο���ѹһ�㶼�ǵ�Դ����������λ��������
#define DAC_VREF      				5000

//��ʼ��ʱ��DAC����ĵ�ѹ����λ��������
#define DAC_SET_OYT_VOLTAGE 	2500

//����DAC��ַ��Ϣ
#define DAC_ADDRESS 					0XC0

#endif
