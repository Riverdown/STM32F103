#ifndef __DRIVER_I2C_H__
#define __DRIVER_I2C_H__

#include "stm32f1xx_hal.h"
#include "main.h"

#define OLED_ADDR                       (0x78)
#define OLED_WRITE                      (0x00)
#define OLED_READ                       (0x01)
#define OLED_WRITECMD                   (0x00)
#define OLED_WRITEDATA                  (0x40)

#define SCL_PORT                        GPIOF 
#define SDA_PORT                        GPIOF 

#define SCL_L                           HAL_GPIO_WritePin(SCL_PORT, SCL_Pin, GPIO_PIN_RESET)
#define SCL_H                           HAL_GPIO_WritePin(SCL_PORT, SCL_Pin, GPIO_PIN_SET)
#define SDA_L                           HAL_GPIO_WritePin(SDA_PORT, SDA_Pin, GPIO_PIN_RESET)  
#define SDA_H                           HAL_GPIO_WritePin(SDA_PORT, SDA_Pin, GPIO_PIN_SET)

#define SDA_READ                        HAL_GPIO_ReadPin(SDA_PORT, SDA_Pin)

extern void I2C_ReInit(void);
extern void I2C_Start(void);
extern void I2C_Stop(void);
extern void I2C_WriteByte(uint8_t data);
extern uint8_t I2C_ReadByte(uint8_t ack);
extern int I2C_GetAck(void);
extern void I2C_Ack(void);
extern void I2C_NegativeAck(void);



#endif

