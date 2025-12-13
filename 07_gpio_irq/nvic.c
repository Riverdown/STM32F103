
/* core_cm3.h */
typedef struct
{
  volatile unsigned int ISER[8];         /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register           */
  volatile unsigned int RESERVED0[24];   
  volatile unsigned int ICER[8];         /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register         */
  volatile unsigned int RSERVED1[24];    
  volatile unsigned int ISPR[8];         /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register          */
  volatile unsigned int RESERVED2[24];   
  volatile unsigned int ICPR[8];         /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register        */
  volatile unsigned int RESERVED3[24];   
  volatile unsigned int IABR[8];         /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register           */
  volatile unsigned int RESERVED4[56];   
  volatile unsigned char  IP[240];             /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
  volatile unsigned int RESERVED5[644];
  volatile unsigned int STIR;            /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register     */
}  NVIC_Type;



void nvic_init(void)
{
    NVIC_Type *nvic = (NVIC_Type *)0xE000E100;
    /* 1. Ê¹ÄÜÖÐ¶Ï EXTI0*/
    nvic->ISER[0] |= (1 << 6);
    

}

void nvic_clear_int(int irq_bit)
{
    NVIC_Type *nvic = (NVIC_Type *)0xE000E100;
    
    if (irq_bit <= 31)
    {
        nvic->ICPR[0] |= (1 << irq_bit);
    }
    
}

