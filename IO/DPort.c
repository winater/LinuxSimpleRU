unsigned long DPort()
{

	unsigned int IOAddress=0;
	unsigned long Port_DWordData=0;
	switch(CommandArray[DPort_CmdID].ParameterCount)
	{
		case 1:
		if(CommandArray[DPort_CmdID].ParameterValue[0]<0x10000)
		{
			IOAddress=(unsigned int )CommandArray[DPort_CmdID].ParameterValue[0];
			Port_DWordData=DWordReadPort(IOAddress);
			printf("%lX\r\n",Port_DWordData);
		}
		else
		{printf("Command:WPort(IOAddress,WriteValue)\nWPort 'IOAddress' should blow 0x10000.\n");}		
		break;
		
		case 2:	
		if(CommandArray[DPort_CmdID].ParameterValue[0]<0x10000)
		{
			IOAddress=CommandArray[DPort_CmdID].ParameterValue[0];
			Port_DWordData=(unsigned long)CommandArray[DPort_CmdID].ParameterValue[1];
			Port_DWordData=DWordWritePort(IOAddress,Port_DWordData);
		}
		else
		{printf("Command:WPort(IOAddress,WriteValue)\nWPort'IOAddress' should blow 0x10000.\n");}			
		break;
		
		default:
		;
	}

	return 0;
	
}

