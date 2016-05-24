#define format 16
long MemDump()
{
        long PhyAddr,LinerAddr,BlkSize,i;

        //printf("MemDump\n");
	switch(CommandArray[MemDump_CmdID].ParameterCount)
	{
	  case 2:
		if(InitMemMgr())
                {
		  PhyAddr = (PBYTE)CommandArray[MemDump_CmdID].ParameterValue[0];
		  BlkSize = CommandArray[MemDump_CmdID].ParameterValue[1];
		  //BlkSize = sizeof(BYTE);
                  //printf("PhyAddr = %04x, BlkSize = %04x\n", PhyAddr,BlkSize);
		  LinerAddr = MapPhysToLin(PhyAddr, BlkSize);
                  //Format
		  for (i = 0; i < format; i++)
		  {
                    if (i == 0) printf("     ");
		    printf("%02x ", i);
		  }
                  printf("\n");
		  for (i = 0; i < BlkSize; i++)
		  {
		    if (i % format == 0) 
                      {
                        //if ((i / format) > 0 ) 
                        printf("\n");
                        printf("%02x   ",i);   
                      }
                      printf("%02x ", *(BYTE*)(LinerAddr + i));
		  }
                  printf("\n");
		  UnmapPhysicalMemory(PhyAddr, BlkSize);
	        }

        	CleanMemMgr();
                break;
          default:
                printf("MemDump(): ParameterCount = %d\n", CommandArray[MemDump_CmdID].ParameterCount);
        }

	return 1;
	
	
	
	return 0;
}
