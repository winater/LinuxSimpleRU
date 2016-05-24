
long DealCommand(long CommandID)
{	
	long	RetValue=0;
	switch(CommandID)
	{
		case BPCI_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			BPCI();
			break;
		case WPCI_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			WPCI();
			break;
		case DPCI_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			DPCI();
			break;
		case PCIDUMP_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			PCIDump();
			break;
		case LSTPCI_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			LSTPCI();
			break;
		case SVIDSSID_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			SVIDSSID();
			break;
		case Port_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			Port();
			break;
		case BPort_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			BPort();
			break;
		case WPort_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			WPort();
			break;
		case DPort_CmdID:
			if(UserCmdFlag==1)
			printf("-%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			DPort();
			break;
		case Byte_Mem_CmdID:
			printf("Bmem(MemAddr [,WriteValue])\n--Run:%s\r\n",CommandArray[CommandID].ParameterBuffer);
                        CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			Bmem();
			break;
		case Word_Mem_CmdID:
			printf("Wmem(MemAddr [,WriteValue])\n--Run:%s\r\n",CommandArray[CommandID].ParameterBuffer);
                        CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			Wmem();
			break;
		case Dword_Mem_CmdID:
			printf("Dmem(MemAddr [,WriteValue])\n--Run:%s\r\n",CommandArray[CommandID].ParameterBuffer);
                        CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			Dmem();
			break;
		case MemDump_CmdID:
			printf("MemDump(StartBaseAddress,Length)\n--Run:%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			MemDump();
			break;
		case CPUID_CmdID:
			printf("CPUID(PreocessorNum)\n--Run:%s\r\n",CommandArray[CommandID].ParameterBuffer);
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
                        CpuID();
			break;
		case MSR_CmdID:
			printf("MSR(PreocessorNum,MSRAddress [,WriteValue])\n--Run:%s\r\n",CommandArray[CommandID].ParameterBuffer);//Test
			CommandArray[CommandID].ParameterCount=DealParameter(CommandArray[CommandID].ParameterBuffer,CommandArray[CommandID].ParameterValue);
			MSR();
			break;
		case Help_CmdID:
			printf("Help :\r\n");
			Help();
			break;
		case Exit_CmdID:
			Exit();
			break;
		 default:
			printf("This Cmd is unavailable\r\n");
			break;
	}
	return RetValue;
}

