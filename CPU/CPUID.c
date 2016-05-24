long CpuID()
{
        uint32_t n;
        system("modprobe cpuid");

	switch(CommandArray[CPUID_CmdID].ParameterCount)
	{
	  case 1:
		printf("Leaf     Subleaf    EAX            EBX            ECX            EDX            \n");
		for (n = 0; n <= 0xffff; n++) 
		{
		  dump_levels(CommandArray[CPUID_CmdID].ParameterValue[0], n << 16);
		}
                break;
          default:
                printf("CPUID(PreocessorNum)\n");
        }
	return 0;
	
}
