#include "driver_i2c.h"

static void I2C_Delay(uint32_t delay)
{
    volatile uint32_t t = delay;
    while(t--);
}
void I2C_ReInit(void)
{
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOF_CLK_ENABLE();

    HAL_GPIO_DeInit(SCL_PORT, SCL_Pin);
    HAL_GPIO_DeInit(SDA_PORT, SDA_Pin);

    /*Configure GPIO pins : PFPin PFPin PFPin PFPin
                           PFPin */
    GPIO_InitStruct.Pin = SCL_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_OD;

    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(SCL_PORT, &GPIO_InitStruct);
    
    GPIO_InitStruct.Pin = SDA_Pin;
    HAL_GPIO_Init(SDA_PORT, &GPIO_InitStruct);

}

void I2C_Start(void)
{
    SCL_H;
    SDA_H;
    I2C_Delay(100);
    SDA_L;
    I2C_Delay(100);
}

void I2C_Stop(void)
{
    SCL_H;
    SDA_L;
    I2C_Delay(100);
    SDA_H;
    I2C_Delay(100);
}
int I2C_GetAck(void)
{
    int i = 0;
    SCL_L;
    SDA_H;
    I2C_Delay(100);
    SCL_H;
    while (SDA_READ != 0)
    {
        i++;
        if (i == 1000)
        {
            return -1;
        }
    }    

    SCL_L;

    return 0;
}

void I2C_Ack(void)
{
    SCL_L;
    SDA_L;
    I2C_Delay(100);
    SCL_H;
    I2C_Delay(100);
}

void I2C_NegativeAck(void)
{
    SCL_L;
    SDA_H;
    I2C_Delay(100);
    SCL_H;
    I2C_Delay(100);
}

void I2C_WriteByte(uint8_t data)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        SCL_L;
        I2C_Delay(100);
        if (data & 0x80)
        {
            SDA_H;
        }
        else
        {
            SDA_L;
        }
        data <<= 1;
        SCL_H;
        I2C_Delay(100);
    }

    I2C_GetAck();
}

/**
 * @brief      Read a byte from I2C bus
 *
 * @return     uint8_t: The byte read from the I2C bus
 *
 * @note       The function will return the byte read from the I2C bus.
 *                If the byte read is not acknowledged, the function will return 0xFF.
 */
uint8_t I2C_ReadByte(uint8_t ack)
{
    uint8_t data = 0;
    SDA_H;
    for (uint8_t i = 0; i < 8; i++)
    {
        data <<= 1;
        SCL_L;
        I2C_Delay(100);
        SCL_H;
        if (SDA_READ != 0)
        {
            data |= 0x01;
        }
    }

    if (!ack)
    {
        I2C_Ack();
    }
    else
    {
        I2C_NegativeAck();
    }
    
    return data;
}

