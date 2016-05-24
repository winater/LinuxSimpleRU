long InitCommand()
{	
	long RetValue;

//BPCI
	StringCopy(CommandArray[BPCI_CmdID].CommandSignature,"BPCI");
	CommandArray[BPCI_CmdID].CommandID=BPCI_CmdID;
	CommandArray[BPCI_CmdID].InitFlag=EOF;
//WPCI
	StringCopy(CommandArray[WPCI_CmdID].CommandSignature,"WPCI");
	CommandArray[WPCI_CmdID].CommandID=WPCI_CmdID;
	CommandArray[WPCI_CmdID].InitFlag=EOF;
//DPCI
	StringCopy(CommandArray[DPCI_CmdID].CommandSignature,"DPCI");
	CommandArray[DPCI_CmdID].CommandID=DPCI_CmdID;
	CommandArray[DPCI_CmdID].InitFlag=EOF;
//PCIDUMP
	StringCopy(CommandArray[PCIDUMP_CmdID].CommandSignature,"PCIDUMP");
	CommandArray[PCIDUMP_CmdID].CommandID=PCIDUMP_CmdID;
	CommandArray[PCIDUMP_CmdID].InitFlag=EOF;
//LSTPCI
	StringCopy(CommandArray[LSTPCI_CmdID].CommandSignature,"LSTPCI");
	CommandArray[LSTPCI_CmdID].CommandID=LSTPCI_CmdID;
	CommandArray[LSTPCI_CmdID].InitFlag=EOF;
//SVIDSSID
	StringCopy(CommandArray[SVIDSSID_CmdID].CommandSignature,"SVIDSSID");
	CommandArray[SVIDSSID_CmdID].CommandID=SVIDSSID_CmdID;
	CommandArray[SVIDSSID_CmdID].InitFlag=EOF;
//Port
	StringCopy(CommandArray[Port_CmdID].CommandSignature,"PORT");
	CommandArray[Port_CmdID].CommandID=Port_CmdID;
	CommandArray[Port_CmdID].InitFlag=EOF;
//BPort
	StringCopy(CommandArray[BPort_CmdID].CommandSignature,"BPORT");
	CommandArray[BPort_CmdID].CommandID=BPort_CmdID;
	CommandArray[BPort_CmdID].InitFlag=EOF;
//WPort
	StringCopy(CommandArray[WPort_CmdID].CommandSignature,"WPORT");
	CommandArray[WPort_CmdID].CommandID=WPort_CmdID;
	CommandArray[WPort_CmdID].InitFlag=EOF;
//Dport
	StringCopy(CommandArray[DPort_CmdID].CommandSignature,"DPORT");
	CommandArray[DPort_CmdID].CommandID=DPort_CmdID;
	CommandArray[DPort_CmdID].InitFlag=EOF;
//BMEM
	StringCopy(CommandArray[Byte_Mem_CmdID].CommandSignature,"BMEM");
	CommandArray[Byte_Mem_CmdID].CommandID=Byte_Mem_CmdID;
	CommandArray[Byte_Mem_CmdID].InitFlag=EOF;
//WMEM
	StringCopy(CommandArray[Word_Mem_CmdID].CommandSignature,"WMEM");
	CommandArray[Word_Mem_CmdID].CommandID=Word_Mem_CmdID;
	CommandArray[Word_Mem_CmdID].InitFlag=EOF;
//DMEM
	StringCopy(CommandArray[Dword_Mem_CmdID].CommandSignature,"DMEM");
	CommandArray[Dword_Mem_CmdID].CommandID=Dword_Mem_CmdID;
	CommandArray[Dword_Mem_CmdID].InitFlag=EOF;
//MemDump
	StringCopy(CommandArray[MemDump_CmdID].CommandSignature,"MEMDUMP");
	CommandArray[MemDump_CmdID].CommandID=MemDump_CmdID;
	CommandArray[MemDump_CmdID].InitFlag=EOF;
//CPUID
	StringCopy(CommandArray[CPUID_CmdID].CommandSignature,"CPUID");
	CommandArray[CPUID_CmdID].CommandID=CPUID_CmdID;
	CommandArray[CPUID_CmdID].InitFlag=EOF;
//MSR
	StringCopy(CommandArray[MSR_CmdID].CommandSignature,"MSR");
	CommandArray[MSR_CmdID].CommandID=MSR_CmdID;
	CommandArray[MSR_CmdID].InitFlag=EOF;
//Exit
	StringCopy(CommandArray[Exit_CmdID].CommandSignature,"EXIT");
	CommandArray[Exit_CmdID].CommandID=Exit_CmdID;
	CommandArray[Exit_CmdID].InitFlag=EOF;
//Help
	StringCopy(CommandArray[Help_CmdID].CommandSignature,"HELP");
	CommandArray[Help_CmdID].CommandID=Help_CmdID;
	CommandArray[Help_CmdID].InitFlag=EOF;

	return RetValue;
}




