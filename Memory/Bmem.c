BYTE Bmem()
{
	BYTE wMemReadValue = 0;
        long PhyAddr,LinerAddr,BlkSize;

	switch(CommandArray[Byte_Mem_CmdID].ParameterCount)
	{
	  case 1:
		if(InitMemMgr())
                {
		  PhyAddr = (PBYTE)CommandArray[Byte_Mem_CmdID].ParameterValue[0];
		  //BlkSize = CommandArray[Word_Mem_CmdID].ParameterValue[1];
		  BlkSize = sizeof(BYTE);
                  //printf("PhyAddr = %04x, BlkSize = %04x\n", PhyAddr,BlkSize);
		  LinerAddr = MapPhysToLin(PhyAddr, BlkSize);
			
		  printf("--MemRead = %02x\n", *(BYTE*)LinerAddr);
                  wMemReadValue = *(BYTE*)LinerAddr;
		  UnmapPhysicalMemory(PhyAddr, BlkSize);
	        }

        	CleanMemMgr();
                break;
	  case 2:
		if(InitMemMgr())
                {
		  PhyAddr = (PBYTE)CommandArray[Byte_Mem_CmdID].ParameterValue[0];
		  //BlkSize = CommandArray[Word_Mem_CmdID].ParameterValue[1];
		  BlkSize = sizeof(BYTE);
		  wMemReadValue = CommandArray[Byte_Mem_CmdID].ParameterValue[1];
                  //printf("PhyAddr = %04x, BlkSize = %04x\n", PhyAddr,BlkSize);
		  LinerAddr = MapPhysToLin(PhyAddr, BlkSize);
			
		  printf("--Before = %02x\n", *(BYTE*)LinerAddr);
                  *(WORD*)LinerAddr = wMemReadValue;
                  printf("--After = %02x\n", *(BYTE*)LinerAddr);
		  UnmapPhysicalMemory(PhyAddr, BlkSize);
	        }

        	CleanMemMgr();
                break;
          default:
                printf("Byte(): ParameterCount = %d\n", CommandArray[Byte_Mem_CmdID].ParameterCount);
        }

	return wMemReadValue;
}
