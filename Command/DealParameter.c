//CMD (xx,xx,xx,xx,xx,xx,xx);
long DealParameter(char ParameterBuffer[],unsigned long ParameterValue[ParameterLen])
{
	long RetValue=0,n=0,T=0;//RetValue=0!
	char *PRMT;
	char StoreChar;
	long NextFlag;
	unsigned long DataStore;

	PRMT=ParameterBuffer;
	do
	{	
	PRMT+=1;
	}
	while(*PRMT!='\0'&&*PRMT!='(') ;
		//printf("*PRMT=%c\n",*PRMT);//Test OK
	if(*PRMT=='(')
	{
		n=0;
		while(*PRMT!='\0'&&*PRMT!=')'&&*PRMT!='\n'&&*PRMT!='\r'&&n<ParameterLen)
		{
			ParameterValue[n]=0;
			NextFlag=0;
			while(*PRMT!=','&&*PRMT!='\0'&&*PRMT!=')'&&*PRMT!='\n'&&*PRMT!='\r')
			{
				if(*PRMT!=' ')//Throw !
				{	StoreChar=0x0;
					//printf("StoreChar=%C\n",*PRMT);//Test
					StoreChar=ChangeOneAsciiToValue(*PRMT);
					
					if(StoreChar!=EOF)
					{
					DataStore=0;
					DataStore=(unsigned long)StoreChar;
					DataStore=(DataStore&0x0F);
					ParameterValue[n]=(ParameterValue[n]<<4)|DataStore;
                                        //printf("ParameterValue[%d]=%x,DataStore=%x\n",n,ParameterValue[n],DataStore);//Test
					NextFlag=1;
					}
				}
				PRMT+=1;//++	???		
			}
			if(*PRMT==',')//Skip ','
			PRMT+=1;//++ ???

			if(NextFlag==1)//Set Next ParameterValue[]
			{ n+=1;
			  RetValue+=1;
			}
			
		}

		while(*PRMT==' '||*PRMT==')')//Throw; 
		{PRMT+=1;}
		
			//printf("N=%ld\n",n);//Test
		
		if(*PRMT=='=')//Detect '='
		{	PRMT+=1;//Skip '='
			
			ParameterValue[n]=0;
			while(*PRMT!=','&&*PRMT!='\0'&&*PRMT!=')'&&*PRMT!='\n'&&*PRMT!='\r')
			{
				if(*PRMT!=' ')//Throw !
				{	StoreChar=0x0;
					StoreChar=ChangeOneAsciiToValue(*PRMT);
					if(StoreChar!=EOF)
					{
					DataStore=0x0;
					DataStore=(unsigned long)StoreChar;
					DataStore=(DataStore&0x0000000F);
					ParameterValue[n]=(ParameterValue[n]<<4)|DataStore;
					NextFlag=1;
					}
				}
				PRMT+=1;//++			
			}

			if(NextFlag==1)//Set Next ParameterValue[]
			{ n+=1;
			 RetValue+=1;
			}
		}


		
	}
	else
	{
		printf("Warning: No find '(' in '%s' command .\r\n",ParameterBuffer);
		RetValue=EOF;
	}
	//printf("ParameterValue[0]=%lX\n",ParameterValue[0] );
	//for(n=0;n<ParameterLen;n++)//Test OK
	//{printf("ParameterValue[%ld]=%lX \nRetValue=%ld\n",n,ParameterValue[n],RetValue);}//Test OK
	return RetValue;
}


