
                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
				EXPORT  __Vectors

__Vectors       DCD     0               ; Top of Stack
                DCD     Reset_Handler              ; Reset Handler

				AREA    |.text|, CODE, READONLY
 ; Reset handler
Reset_Handler   PROC
				EXPORT Reset_Handler		[WEAK]

                ;/* 使能GPIOB */
                LDR		r0, =0x40021000 + 0x18
                LDR     r1, [r0]
                ORR		r1, r1,#(1<<3)
                STR		r1,[r0]

                ;/* 设置 pin mode ， 设置为 输出 引脚 */
                LDR		r0, =(0x40010C00 + 0)
                LDR     r1, [r0]
                ORR		r1, r1,#(1<<0)
                STR		r1,[r0]
MainLoop
                ; 地址为 PortB  ODR 寄存器
                LDR		r0, =(0x40010C00 + 0x0C)
                LDR     r1, [r0]
                ORR		r1, r1,#(1<<0)
                STR		r1,[r0]
                BL      Delay

                LDR		r0, =(0x40010C00 + 0x0C)
                LDR     r1, [r0]
                BIC		r1, r1,#(1<<0)
                STR		r1,[r0]
                BL      Delay
                B       MainLoop

Delay
	            LDR R0, =200000
DelayLoop
                SUBS R0, #1
                BNE  DelayLoop
                BX   lr
                NOP

                ENDP
					
				END