SET PATH=d:\CodeIDE\Keil_v5\ARM\ARMCC\Bin;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\WINDOWS\System32\OpenSSH\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;d:\Program Files\Git\cmd;D:\SDK\mingw64\bin;C:\Program Files\dotnet\;D:\SDK\miniconda3\Scripts;D:\Program Files\nodejs\;D:\SDK\miniconda3;D:\SDK\jdk-24\bin;;d:\Programs\cursor\resources\app\bin;%SystemRoot%\system32;%SystemRoot%;%SystemRoot%\System32\Wbem;%SYSTEMROOT%\System32\WindowsPowerShell\v1.0\;%SYSTEMROOT%\System32\OpenSSH\;C:\Users\Feng\AppData\Local\Microsoft\WindowsApps;;C:\Users\Feng\AppData\Roaming\npm;D:\Programs\Microsoft VS Code\bin;D:\Programs\cursor\resources\app\bin
SET ARMCC5_ASMOPT=--diag_suppress=9931
SET ARMCC5_CCOPT=--diag_suppress=9931
SET ARMCC5_LINKOPT=--diag_suppress=9931
SET CPU_TYPE=STM32F103ZE
SET CPU_VENDOR=STMicroelectronics
SET UV2_TARGET=led_c
SET CPU_CLOCK=0x00B71B00
"d:\CodeIDE\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\main.__i"
"d:\CodeIDE\Keil_v5\ARM\ARMCC\Bin\ArmAsm" --Via ".\objects\start._ia"
"d:\CodeIDE\Keil_v5\ARM\ARMCC\Bin\ArmCC" --Via ".\objects\uart_bsp.__i"
"d:\CodeIDE\Keil_v5\ARM\ARMCC\Bin\ArmLink" --Via ".\Objects\feng_led.lnp"
"d:\CodeIDE\Keil_v5\ARM\ARMCC\Bin\fromelf.exe" ".\Objects\feng_led.axf" --i32combined --output ".\Objects\feng_led.hex"
