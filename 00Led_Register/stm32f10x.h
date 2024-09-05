// 用来存放STM32寄存器映射的代码

/* Peripheral  base addresses */
#define  PERIPH_BASE            ((unsigned int)0x40000000)

/* APB2 bus peripheral base address */
#define  APB2PERIPH_BASE        (PERIPH_BASE + 0x10000)

/* AHB peripheral base address */
#define  AHBPERIPH_BASE         (PERIPH_BASE + 0x20000)

/* GPIOB Peripheral base address */
#define  GPIOB_BASE             (APB2PERIPH_BASE + 0x0C00) 

/* GPIOB Peripheral base address , pointer type */
#define  GPIOB_CRL              *(unsigned int*)(GPIOB_BASE + 0x00)
#define  GPIOB_CRH              *(unsigned int*)(GPIOB_BASE + 0x04)
#define  GPIOB_IDR              *(unsigned int*)(GPIOB_BASE + 0x08)
#define  GPIOB_ODR              *(unsigned int*)(GPIOB_BASE + 0x0C)
#define  GPIOB_BSRR             *(unsigned int*)(GPIOB_BASE + 0x10)
#define  GPIOB_BRR              *(unsigned int*)(GPIOB_BASE + 0x14)
#define  GPIOB_LCKR             *(unsigned int*)(GPIOB_BASE + 0x18)

/* RCC peripheral base address */
#define  RCC_BASE               (AHBPERIPH_BASE + 0x1000)

/* RCC APB2 peripheral clock enable register (RCC_APB2ENR) */
#define  RCC_APB2ENR            *(unsigned int*)(RCC_BASE + 0x18)

