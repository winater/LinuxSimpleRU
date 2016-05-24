WORD Wmem()
{
	WORD wMemReadValue = 0;
        long PhyAddr,LinerAddr,BlkSize;

	switch(CommandArray[Word_Mem_CmdID].ParameterCount)
	{
	  case 1:
		if(InitMemMgr())
                {
		  PhyAddr = (PBYTE)CommandArray[Word_Mem_CmdID].ParameterValue[0];
		  //BlkSize = CommandArray[Word_Mem_CmdID].ParameterValue[1];
		  BlkSize = sizeof(WORD);
                  //printf("PhyAddr = %04x, BlkSize = %04x\n", PhyAddr,BlkSize);
		  LinerAddr = MapPhysToLin(PhyAddr, BlkSize);
			
		  printf("--MemRead = %04x\n", *(WORD*)LinerAddr);
                  wMemReadValue = *(WORD*)LinerAddr;
		  UnmapPhysicalMemory(PhyAddr, BlkSize);
	        }

        	CleanMemMgr();
                break;
	  case 2:
		if(InitMemMgr())
                {
		  PhyAddr = (PBYTE)CommandArray[Word_Mem_CmdID].ParameterValue[0];
		  //BlkSize = CommandArray[Word_Mem_CmdID].ParameterValue[1];
		  BlkSize = sizeof(WORD);
		  wMemReadValue = CommandArray[Word_Mem_CmdID].ParameterValue[1];
                  //printf("PhyAddr = %04x, BlkSize = %04x\n", PhyAddr,BlkSize);
		  LinerAddr = MapPhysToLin(PhyAddr, BlkSize);
			
		  printf("--Before = %04x\n", *(WORD*)LinerAddr);
                  *(WORD*)LinerAddr = wMemReadValue;
                  printf("--After = %04x\n", *(WORD*)LinerAddr);
		  UnmapPhysicalMemory(PhyAddr, BlkSize);
	        }

        	CleanMemMgr();
                break;
          default:
                printf("Word(): ParameterCount = %d\n", CommandArray[Word_Mem_CmdID].ParameterCount);
        }

	return wMemReadValue;
}
