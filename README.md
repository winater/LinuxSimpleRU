# LinuxSimpleRU
Simple Read&amp;Write utility for Linux

  This utility access some computer hardwares, including PCI/PCIE Index/Data, Memory, I/O Port, CPU MSR Register,CPUID.
  
Note:
  The Project constructs with Visual eBios Tool. In all probability, it is inconvenient to see the project structure now.
 
Qiuck Start:
  1. Download LinuxRU
  2. Typing ./LinuxRu from the file directory.
  3. Use it.

Build it:
  1. Clone the project.
  2. Using LinuxRU.mak to make.

Help:
  Below is the List of Command (all commands will ignore case).
  NOTE: [WriteValue] is necessary if you want to command "Write". Otherwise the command means "Read". 

For Help/Exit : 
  Help --Will display help information.
  EXIT --Will exit the utility. 
 
For PCI/PCIE : 
  Bpci(Bus,Dev,Fun,Offset[,WriteValue]) --Read/Write a Byte from/to (Bus,Dev,Fun,Offset).
  Wpci(Bus,Dev,Fun,Offset[,WriteValue]) --Read/Write a Word from/to (Bus,Dev,Fun,Offset).
  Dpci(Bus,Dev,Fun,Offset[,WriteValue]) --Read/Write a Dword from/to (Bus,Dev,Fun,Offset).
  PCIDump(Bus,Dev,Fun,StartReg,Len)     --Dump specified PCI/PCIE device(Bus,Dev,Fun) data from (StartReg) to StartReg+(Len). 
  LSTPCI                                --List all PCI/PCIE Devices with VDID&DVID. 
  SVIDSSID                              --List all PCI/PCIE Devices with SVID&SSID.
 
For IO Port :
  Port(IOAddress[,WriteValue-B/W/D])    --Read/Write a Byte/Word/DWord from/to (IOAddress).
  Bport(IOAddress[,WriteValue-B])       --Read/Write a Byte from/to (IOAddress).
  Wport(IOAddress[,WriteValue-W])       --Read/Write a Word from/to (IOAddress).
  Dport(IOAddress[,WriteValue-D])       --Read/Write a DWord from/to (IOAddress).
 
For Memory :
  Bmem(MemAddr[,WriteValue])            --Read/Write a Byte from/to (MemAddr).
  Wmem(MemAddr[,WriteValue])            --Read/Write a Word from/to (MemAddr).
  Dmem(MemAddr[,WriteValue])            --Read/Write a Dword from/to (MemAddr).
  MemDump(StartBaseAddress,Length)      --Dump Memory data from (StartBaseAddress) to StartBaseAddress+(Length). 
 
For CPU/MSR : (The main source code of this part is from https://01.org/zh/msr-tools)
  CPUID(PreocessorNum)                  --Dump CPUID data of (PreocessorNum).
  MSR(PreocessorNum,MSRAddress[,WriteValue]) --Read/Write a Data from/to (PreocessorNum,MSRAddress).

