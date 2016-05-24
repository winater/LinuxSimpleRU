
//GetUserCommand1
long DetectAndDealCommand(char UserCMD[])
{
	long	RetValue=0;
	long 	CommandID=0;

	for(CommandID=0;CommandID<CmdStrucArrayCount;CommandID++)
	{
		if(CommandArray[CommandID].InitFlag!=0)
		{
			RetValue=CommandStringCmp(CommandArray[CommandID].CommandSignature,UserCMD);
			if(RetValue==0)
			{
			 ClearString (CommandArray[CommandID].ParameterBuffer,ParameterBufferLen);
			 StringCopy(CommandArray[CommandID].ParameterBuffer,UserCMD);
			 
			 DealCommand(CommandID);
			}
			
		}
	}
	return RetValue;
}

long DealUserCmd(int Argc_deal,char *Argv_deal[])
{	
	long i;
	for(i=1;i<Argc_deal;i++)
	{
		DetectAndDealCommand(Argv_deal[i]);
	}
}

long SendCommand(char SendCMD[])
{
	DetectAndDealCommand(SendCMD);
	return 0;
}

//GetUserCommand2
long GetUserInputCommand()
{	
	long CmdCharCount=0;
	long BufferSize=0;
	char StoreChar;
	BufferSize=sizeof(PublicBuffer);
	
	ClearPublicBuffer();
	for(CmdCharCount=0;CmdCharCount<(ParameterBufferLen-1)&&CmdCharCount<BufferSize;CmdCharCount++)
	{
		StoreChar=getchar();	
		PublicBuffer[CmdCharCount]=StoreChar;
		if(PublicBuffer[CmdCharCount]=='\n')
		{
		PublicBuffer[CmdCharCount]='\0';
		break;
		}
	}
	SendCommand(PublicBuffer);
}


