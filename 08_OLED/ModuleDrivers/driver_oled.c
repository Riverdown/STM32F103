#include "driver_oled.h"
#include "driver_i2c.h"

void OLED_WriteCmd(uint8_t cmd)
{
    I2C_Start();
    I2C_WriteByte(OLED_ADDR | OLED_WRITE);
    I2C_WriteByte(OLED_WRITECMD);
    I2C_WriteByte(cmd);
    I2C_Stop();
}

void OLED_WriteData(uint8_t data)
{
    I2C_Start();
    I2C_WriteByte(OLED_ADDR | OLED_WRITE);
    I2C_WriteByte(OLED_WRITEDATA);
    I2C_WriteByte(data);
    I2C_Stop();
}

void OLED_WriteNBytes(uint8_t *data, uint8_t len)
{
    if (NULL == data)
        return;

    I2C_Start();
    I2C_WriteByte(OLED_ADDR | OLED_WRITE);
    I2C_WriteByte(OLED_WRITEDATA);

    for (uint8_t i = 0; i < len; i++)
    {
        I2C_WriteByte(data[i]);
    }
    
    I2C_Stop();
}