long HelpCommandID(long CommandID)
{	
	long	RetValue=0;
	switch(CommandID)
	{
		case BPCI_CmdID:
			printf("Bpci(Bus,Dev,Fun,Offset[,WriteValue])\r\n");
			break;
		case WPCI_CmdID:
			printf("Wpci(Bus,Dev,Fun,Offset[,WriteValue])\r\n");
			break;
		case DPCI_CmdID:
			printf("Dpci(Bus,Dev,Fun,Offset[,WriteValue])\r\n");
			break;
		case PCIDUMP_CmdID:
			printf("PCIDump(Bus,Dev,Fun,StartReg,Len)\r\n");
			break;
		case LSTPCI_CmdID:
			printf("LSTPCI:List all PCI/PCIE Devices with VDID&DVID.\r\n");
			break;
		case SVIDSSID_CmdID:
			printf("SVIDSSID:List all PCI/PCIE Devices with SVID&SSID.\r\n");
			break;
		case Port_CmdID:
			printf("Port(IOAddress[,WriteValue-B/W/D])\r\n");
			break;
		case BPort_CmdID:
			printf("Bport(IOAddress[,WriteValue-B])\r\n");
			break;
		case WPort_CmdID:
			printf("Wport(IOAddress[,WriteValue-W])\r\n");
			break;
		case DPort_CmdID:
			printf("Dport(IOAddress[,WriteValue-D])\r\n");
			break;
		case Byte_Mem_CmdID:
			printf("Bmem(MemAddr[,WriteValue])\r\n");
			break;
		case Word_Mem_CmdID:
			printf("Wmem(MemAddr[,WriteValue])\r\n");
			break;
		case Dword_Mem_CmdID:
			printf("Dmem(MemAddr[,WriteValue])\r\n");
			break;
		case MemDump_CmdID:
			printf("MemDump(StartBaseAddress,Length)\r\n");
			break;
		case CPUID_CmdID:
			printf("CPUID(PreocessorNum)\r\n");
			break;
		case MSR_CmdID:
			printf("MSR(PreocessorNum,MSRAddress[,WriteValue])\r\n");
			break;
		case Help_CmdID:
			printf("Help\r\n");
			break;
		case Exit_CmdID:
			printf("EXIT\r\n");
			break;
		default:
			printf("This Cmd is unavailable\r\n");
			break;
	}
	return RetValue;
}

long Help()
{
	long CommandID;
        printf("-------------------------------------------------------------\n");
	printf("CommandGroup    CommandList(Ignore Case)\n");
        printf("-------------------------------------------------------------\n");
	for(CommandID=0;CommandID<=CmdStrucArrayCount;CommandID++)
	{
	    if(CommandArray[CommandID].InitFlag!=0)
	    {
                switch(CommandID/10)
                {
                   case 1:
                           printf("[PCI/PCIE ]\t",CommandID);
                           break;
                   case 2:
                           printf("[IO Port  ]\t",CommandID);
                           break;
                   case 3:
                           printf("[Memory   ]\t",CommandID);
                           break;
                   case 4:
                           printf("[CPU/MSR  ]\t",CommandID);
                           break;
                   default:
                           printf("[Help/Exit]\t",CommandID);
                           break;
                }
		HelpCommandID(CommandID);
	    }
	}
}
