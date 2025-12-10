#ifndef __SYSTICK_H__
#define __SYSTICK_H__

typedef struct
{
  volatile unsigned int CTRL;            /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile unsigned int LOAD;            /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  volatile unsigned int VAL;             /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  volatile unsigned int CALIB;           /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;

#define SysTick_BASE        (0xE000E000 +  0x0010UL) 
#define SYSTICK_FRE   (8000000)

#define SysTick_CTRL_CLKSOURCE_Pos   2
#define SysTick_CTRL_CLKSOURCE_Msk  (1UL << SysTick_CTRL_CLKSOURCE_Pos)
#define SysTick_CTRL_TICKINT_Pos    1
#define SysTick_CTRL_TICKINT_Msk    (1UL << SysTick_CTRL_TICKINT_Pos)
#define SysTick_CTRL_ENABLE_Pos     0
#define SysTick_CTRL_ENABLE_Msk     (1UL << SysTick_CTRL_ENABLE_Pos)

#endif
