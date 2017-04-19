#<p>Simple Read&amp;Write utility for Linux</p>
<p>  The utility accesses some computer hardwares, including PCI/PCIE Index/Data, Memory, I/O Port, CPU MSR Register,CPUID.<br />  <br /><span style="font-size: 15px;"><strong>Note:</strong></span><br />  The Project constructs with Visual eBios Tool. In all probability, it is inconvenient to see the project structure now.<br /> <br /><span style="font-size: 15px;"><strong>Qiuck Start:</strong></span><br />  1. Download LinuxRU<br />  2. LinuxRu is the executable utility.</p>
<p><span style="font-size: 15px;"><strong>Build it:</strong></span><br />  1. Clone the project.<br />  2. Using LinuxRU.mak to make it.</p>
<p><span style="font-size: 15px;"><strong>Help:</strong></span><br />  Below is the List of Command (all commands will ignore case).<br />  <span style="font-size: 14px;"><strong>NOTE: [WriteValue] is necessary if you want to command "Write". Otherwise the command means "Read".</strong></span></p>
<table style="height: 529px; border: 0px solid #ffffff; width: 817px; background-color: #ffffff;" border="0">
<tbody>
<tr>
<td style="text-align: left;"><strong>For Help/Exit :</strong>&nbsp;</td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Help</td>
<td>--Will display help information.</td>
</tr>
<tr>
<td>EXIT</td>
<td>--Will exit the utility.</td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
</tr>
<tr>
<td><strong>For PCI/PCIE :</strong></td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Bpci(Bus,Dev,Fun,Offset[,WriteValue])</td>
<td>--Read/Write a Byte from/to (Bus,Dev,Fun,Offset).</td>
</tr>
<tr>
<td>Wpci(Bus,Dev,Fun,Offset[,WriteValue])</td>
<td>--Read/Write a Word from/to (Bus,Dev,Fun,Offset).</td>
</tr>
<tr>
<td>Dpci(Bus,Dev,Fun,Offset[,WriteValue])</td>
<td>--Read/Write a Dword from/to (Bus,Dev,Fun,Offset).</td>
</tr>
<tr>
<td>PCIDump(Bus,Dev,Fun,StartReg,Len)</td>
<td>--Dump specified PCI/PCIE device(Bus,Dev,Fun) data from (StartReg) to StartReg+(Len).</td>
</tr>
<tr>
<td>LSTPCI</td>
<td>--List all PCI/PCIE Devices with VDID&amp;DVID.</td>
</tr>
<tr>
<td>SVIDSSID</td>
<td>--List all PCI/PCIE Devices with SVID&amp;SSID.</td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
</tr>
<tr>
<td><strong>For IO Port :</strong></td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Port(IOAddress[,WriteValue-B/W/D])</td>
<td>--Read/Write a Byte/Word/DWord from/to (IOAddress).</td>
</tr>
<tr>
<td>Bport(IOAddress[,WriteValue-B])</td>
<td>--Read/Write a Byte from/to (IOAddress).</td>
</tr>
<tr>
<td>Wport(IOAddress[,WriteValue-W])</td>
<td>--Read/Write a Word from/to (IOAddress).</td>
</tr>
<tr>
<td>Dport(IOAddress[,WriteValue-D])</td>
<td>--Read/Write a DWord from/to (IOAddress).</td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
</tr>
<tr>
<td><strong>For Memory :</strong></td>
<td>&nbsp;</td>
</tr>
<tr>
<td>Bmem(MemAddr[,WriteValue])</td>
<td>--Read/Write a Byte from/to (MemAddr).</td>
</tr>
<tr>
<td>Wmem(MemAddr[,WriteValue])</td>
<td>--Read/Write a Word from/to (MemAddr).</td>
</tr>
<tr>
<td>Dmem(MemAddr[,WriteValue])</td>
<td>--Read/Write a Dword from/to (MemAddr).</td>
</tr>
<tr>
<td>MemDump(StartBaseAddress,Length)</td>
<td>--Dump Memory data from (StartBaseAddress) to StartBaseAddress+(Length).</td>
</tr>
<tr>
<td>&nbsp;</td>
<td>&nbsp;</td>
</tr>
<tr>
<td colspan="2"><strong>For CPU/MSR :</strong>&nbsp;(The main source code of this part is from https://01.org/zh/msr-tools)</td>
</tr>
<tr>
<td>CPUID(PreocessorNum)</td>
<td>--Dump CPUID data of (PreocessorNum).</td>
</tr>
<tr>
<td>MSR(PreocessorNum,MSRAddress[,WriteValue])</td>
<td>--Read/Write a Data from/to (PreocessorNum,MSRAddress).</td>
</tr>
</tbody>
</table>
