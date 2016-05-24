long MSR()
{
	switch(CommandArray[MSR_CmdID].ParameterCount)
	{
	  case 2:
		printf("--");
		rdmsr_on_cpu(CommandArray[MSR_CmdID].ParameterValue[0], CommandArray[MSR_CmdID].ParameterValue[1]);
		printf("\n");
                break;
	  case 3:
		printf("--");
		rdmsr_on_cpu(CommandArray[MSR_CmdID].ParameterValue[0], CommandArray[MSR_CmdID].ParameterValue[1]);
		wrmsr_on_cpu(CommandArray[MSR_CmdID].ParameterValue[0], CommandArray[MSR_CmdID].ParameterValue[1], CommandArray[MSR_CmdID].ParameterValue[2]);
		printf(" -> ");
		rdmsr_on_cpu(CommandArray[MSR_CmdID].ParameterValue[0], CommandArray[MSR_CmdID].ParameterValue[1]);
		printf("\n");
                break;
          default:
                printf("MSR(PreocessorNum,MSRAddress[,WriteValue])\n");
        }
	return 0;
}
