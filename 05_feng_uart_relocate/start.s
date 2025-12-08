
                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset
                AREA    RESET, DATA, READONLY
				EXPORT  __Vectors

__Vectors       DCD     0               ; Top of Stack
                DCD     0x08000009   ; Reset Handler

				AREA    |.text|, CODE, READONLY
 ; Reset handler
Reset_Handler   PROC
				IMPORT memcpy
				IMPORT memset
                IMPORT  Mymain
				IMPORT |Image$$RW_IRAM1$$Base|
				IMPORT |Image$$RW_IRAM1$$Length|
				IMPORT |Load$$RW_IRAM1$$Base|

				IMPORT |Image$$ER_IROM1$$Base|
				IMPORT |Image$$ER_IROM1$$Length|
				IMPORT |Load$$ER_IROM1$$Base|

				IMPORT |Image$$RW_IRAM1$$ZI$$Base|
				IMPORT |Image$$RW_IRAM1$$ZI$$Length|
				IMPORT memcpy

				LDR SP, =(0x20000000+0x10000)

				; relocate data section
				LDR R0, = |Image$$RW_IRAM1$$Base|    ; DEST
				LDR R1, = |Load$$RW_IRAM1$$Base|     ; SORUCE
				LDR R2, = |Image$$RW_IRAM1$$Length|  ; LENGTH
				BL memcpy

				; relocate code section
				LDR R0, = |Image$$ER_IROM1$$Base|    ; DEST
				LDR R1, = |Load$$ER_IROM1$$Base|     ; SORUCE
				LDR R2, = |Image$$ER_IROM1$$Length|  ; LENGTH
				BL memcpy

				LDR R0, = |Image$$RW_IRAM1$$ZI$$Base|    ; DEST
				LDR R1, = 0     ; len
				LDR R2, = |Image$$RW_IRAM1$$ZI$$Length|  ; len
				BL memset
				;BL	   Mymain
				LDR r0, =Mymain
				BLX r0
				
                ENDP
					
				END