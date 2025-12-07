
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
                IMPORT main
					
				LDR sp, =(0x20000000 + 0x10000)
				BL	   main
				
                ENDP
					
				END