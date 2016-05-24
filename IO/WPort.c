int WPort()
{

	unsigned int IOAddress=0;
	unsigned short Port_WordData=0;
	switch(CommandArray[WPort_CmdID].ParameterCount)
	{
		case 1:
		if(CommandArray[WPort_CmdID].ParameterValue[0]<0x10000)
		{
			IOAddress=(unsigned int )CommandArray[WPort_CmdID].ParameterValue[0];
			Port_WordData=WordReadPort(IOAddress);
			printf("%02X\r\n",Port_WordData);
		}
		else
		{printf("Command:WPort(IOAddress,WriteValue)\nWPort 'IOAddress' should blow 0x10000.\n");}		
		break;
		
		case 2:	
		if(CommandArray[WPort_CmdID].ParameterValue[0]<0x10000)
		{
			
			if(CommandArray[WPort_CmdID].ParameterValue[1]<0x10000)
			{
				IOAddress=CommandArray[WPort_CmdID].ParameterValue[0];
				Port_WordData=(unsigned short)CommandArray[WPort_CmdID].ParameterValue[1];
				Port_WordData=WordWritePort(IOAddress,Port_WordData);
			}
			else
			{printf("Command:WPort(IOAddress,WriteValue)\nWPort 'WriteValue' should blow 0x10000.\n");
			//printf("WriteValue=%LX\n",CommandArray[WPort_CmdID].ParameterValue[1]);//Test
			}	
		}
		else
		{printf("Command:WPort(IOAddress,WriteValue)\nWPort'IOAddress' should blow 0x10000.\n");}			
		break;
		
		default:
		;
	}

	return 0;
	
}



