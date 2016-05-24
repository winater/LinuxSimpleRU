long StringCopy(char DST[],char SRC[])
{
	long 	RetValue;
	char	*DST_P;
	char	*SRC_P;

	for(SRC_P=SRC,DST_P=DST;*SRC_P!='\0';SRC_P++,DST_P++)
	{	
	*DST_P=*SRC_P;	
	}

	//printf("SRC_P=%c DST_P=%c SRC=%s DST=%s\n",*SRC_P,*DST_P,SRC,DST);//Test OK
	return RetValue;
}

long CheckStringLength(char STR[])
{	
	long 	RetValue;
	char *STR_P;
	STR_P=STR;
	for(RetValue=0;*STR_P!='\0';STR_P++,RetValue++)
	{}
	#if TestStringLength
	printf("StrinLen=%02ld '%s'\n",RetValue,STR);//Test OK
	#endif
	return RetValue;
}

char	CapsOneChar(char CapsChar)		
{
	char    RetValue=0;

	if('a'<=CapsChar&&CapsChar<='z')
		{
			CapsChar-=0x20;
		}
	RetValue=CapsChar;
		//printf("CapsChar=%c\n",CapsChar);//Test OK
	return	RetValue;
}

long StringCmp(char DST[],char SRC[])
{
	long 	RetValue=0,n;
	long	DST_LEN,SRC_LEN;
	char	*DST_P;
	char	*SRC_P;

	DST_LEN=CheckStringLength(DST);
	SRC_LEN=CheckStringLength(SRC);
	if(DST_LEN==SRC_LEN)
	{
		for(SRC_P=SRC,DST_P=DST;*SRC_P!='\0'&&*DST_P!='\0'&&RetValue!=EOF;SRC_P++,DST_P++)
		{
			if(*DST_P!=*SRC_P&&*DST_P!=*SRC_P+0x20&&*DST_P+0x20!=*SRC_P)
			{
			RetValue=EOF;
			}
		}
	}
	else
	{
		RetValue=EOF;
	}
		//printf("RetValue=%ld\n",RetValue);//Test OK
	return RetValue;
}

long CommandStringCmp(char DST[],char SRC[])
{
	long 	RetValue=0,n;
	long	DST_LEN,SRC_LEN;
	char	*DST_P;
	char	*SRC_P;

	DST_LEN=CheckStringLength(DST);
	for(SRC_P=SRC,DST_P=DST,n=0;n<DST_LEN&&*DST_P!='\0'&&RetValue!=EOF;SRC_P++,DST_P++)
	{
		if(*DST_P!=*SRC_P&&*DST_P!=*SRC_P+0x20&&*DST_P+0x20!=*SRC_P)
		{
		RetValue=EOF;
		}
	}
	if(('A'<=*SRC_P&&*SRC_P<='Z')||('a'<=*SRC_P&&*SRC_P<='z'))
	{RetValue=EOF;}
		//printf("RetValue=%ld SRC_P=%c\n",RetValue,*SRC_P);//Test OK
	return RetValue;
}

long ClearString (char STR[],long ClearLen)
{	
	int n;
	char *Clear;
	Clear=STR;

	for(n=0;n<ClearLen;n++,Clear++)
	{
	 *Clear='\0';
	}
	return 0;
}


