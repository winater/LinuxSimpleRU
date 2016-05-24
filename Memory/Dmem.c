DWORD Dmem()
{
	DWORD wMemReadValue = 0;
        long PhyAddr,LinerAddr,BlkSize;

	switch(CommandArray[Dword_Mem_CmdID].ParameterCount)
	{
	  case 1:
		if(InitMemMgr())
                {
		  PhyAddr = (PBYTE)CommandArray[Dword_Mem_CmdID].ParameterValue[0];
		  //BlkSize = CommandArray[Dword_Mem_CmdID].ParameterValue[1];
		  BlkSize = sizeof(DWORD);
                  //printf("PhyAddr = %x, BlkSize = %x\n", PhyAddr,BlkSize);
		  LinerAddr = MapPhysToLin(PhyAddr, BlkSize);
			
		  printf("--MemRead = %08x\n", *(DWORD*)LinerAddr);
                  wMemReadValue = *(DWORD*)LinerAddr;
		  UnmapPhysicalMemory(PhyAddr, BlkSize);
	        }

        	CleanMemMgr();
                break;
	  case 2:
		if(InitMemMgr())
                {
		  PhyAddr = (PBYTE)CommandArray[Dword_Mem_CmdID].ParameterValue[0];
		  //BlkSize = CommandArray[Dword_Mem_CmdID].ParameterValue[1];
		  BlkSize = sizeof(DWORD);
		  wMemReadValue = CommandArray[Dword_Mem_CmdID].ParameterValue[1];
                  //printf("PhyAddr = %x, BlkSize = %x\n", PhyAddr,BlkSize);
		  LinerAddr = MapPhysToLin(PhyAddr, BlkSize);
			
		  printf("--Before = %08x\n", *(DWORD*)LinerAddr);
                  *(DWORD*)LinerAddr = wMemReadValue;
                  printf("--After = %08x\n", *(DWORD*)LinerAddr);
		  UnmapPhysicalMemory(PhyAddr, BlkSize);
	        }

        	CleanMemMgr();
                break;
          default:
                printf("Dword(): ParameterCount = %d\n", CommandArray[Dword_Mem_CmdID].ParameterCount);
        }

	return wMemReadValue;
}
