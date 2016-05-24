int Port()
{

	int IOAddress=0,Port_ByteData=0;
	unsigned short Port_WordData;
	unsigned long Port_DWordData;
	switch(CommandArray[Port_CmdID].ParameterCount)
	{
		case 1:
		if(CommandArray[Port_CmdID].ParameterValue[0]<0x10000)
		{
			IOAddress=CommandArray[Port_CmdID].ParameterValue[0];
			Port_ByteData=ByteReadPort(IOAddress);
			printf("%02X\r\n",Port_ByteData);
		}
		else
		{printf("Command:Port(IOAddress,WriteValue)\nPort 'IOAddress' should blow 0x10000.\n");}		
		break;
		
		case 2:	
		if(CommandArray[Port_CmdID].ParameterValue[0]<0x10000)
		{
			if(CommandArray[Port_CmdID].ParameterValue[1]<0x100)
			{
				IOAddress=CommandArray[Port_CmdID].ParameterValue[0];
				Port_ByteData=CommandArray[Port_CmdID].ParameterValue[1];
				Port_ByteData=ByteWritePort(IOAddress,Port_ByteData);
			}
			else
			{
				//HTtest09/19/2007->
				//printf("Command:Port(IOAddress,WriteValue)\nPort 'WriteValue' should blow 0x100.\n");//HTtest09/19/2007--
				if(CommandArray[Port_CmdID].ParameterValue[1]<0x10000)
				{
					IOAddress=CommandArray[Port_CmdID].ParameterValue[0];
					Port_WordData=(unsigned short)CommandArray[Port_CmdID].ParameterValue[1];
					Port_WordData=WordWritePort(IOAddress,Port_WordData);
				}
				else
				{
					IOAddress=CommandArray[Port_CmdID].ParameterValue[0];
					Port_DWordData=(unsigned long)CommandArray[Port_CmdID].ParameterValue[1];
					Port_DWordData=DWordWritePort(IOAddress,Port_DWordData);
				}
				//HTtest09/19/2007<-
			}	
		}
		else
		{printf("Command:Port(IOAddress,WriteValue)\nPort'IOAddress' should blow 0x10000.\n");}			
		break;
		
		default:
		;
	}

	return 0;
	
}

int BPort()
{

	int IOAddress=0,Port_ByteData=0;
	switch(CommandArray[BPort_CmdID].ParameterCount)
	{
		case 1:
		if(CommandArray[BPort_CmdID].ParameterValue[0]<0x10000)
		{
			IOAddress=CommandArray[BPort_CmdID].ParameterValue[0];
			Port_ByteData=ByteReadPort(IOAddress);
			printf("%02X\r\n",Port_ByteData);
		}
		else
		{printf("Command:Bport(IOAddress,WriteValue)\nBport 'IOAddress' should blow 0x10000.\n");}		
		break;
		
		case 2:	
		if(CommandArray[BPort_CmdID].ParameterValue[0]<0x10000)
		{
			
			if(CommandArray[BPort_CmdID].ParameterValue[1]<0x100)
			{
				IOAddress=CommandArray[BPort_CmdID].ParameterValue[0];
				Port_ByteData=CommandArray[BPort_CmdID].ParameterValue[1];
				Port_ByteData=ByteWritePort(IOAddress,Port_ByteData);
			}
			else
			{printf("Command:Bport(IOAddress,WriteValue)\nBport 'WriteValue' should blow 0x100.\n");}	
		}
		else
		{printf("Command:Bport(IOAddress,WriteValue)\nBport'IOAddress' should blow 0x10000.\n");}			
		break;
		
		default:
		;
	}

	return 0;
	
}


