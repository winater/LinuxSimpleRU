SVIDSSID()
{
	DumpAllDeviceSvidSid();
	return 0;
}

long	DumpAllDeviceSvidSid()
{	
	long	RetValue=0,MultiFunctionFlag;
	long	BusNum=0,DevNum=0,FunNum=0,RegNum=0;	
	FILE	*fp;
	
	//char	DumpString[]={"SVID_SSID_Location :		SVID_SSID_Value	:	Ignore_SVID_SSID // Fill['Yes'Or NULL]"};
	char	DumpString2[]={"SVID_SSID_Location  		SVID_SSID_Value	 	"};
	printf("%s\r\n",DumpString2);
	for(BusNum=0;BusNum<=0xff;BusNum++) //!
	{
		for(DevNum=0,MultiFunctionFlag=0;DevNum<=31;DevNum++)
		{	
			for(FunNum=0;FunNum<=7;FunNum++)
			{			
				//HtTest++->
				if(FunNum==0)
					{
					MultiFunctionFlag=CheckPciDeviceIfOrNotMultiFunction(BusNum,DevNum);
					DumpDeviceSvidSsid(BusNum,DevNum,FunNum);
					}
				else
					{
						if(MultiFunctionFlag==1)
						{
						DumpDeviceSvidSsid(BusNum,DevNum,FunNum);
						}

					}
				//HtTest++<-
			}
		}
			
	}


return	0;
}
unsigned int	DumpDeviceSvidSsid	(long Bus_dump,long Dev_dump,long Fun_dump)
	{
		unsigned int		RetValue;
		RetValue=CheckPciDeviceIfOrNotExist(Bus_dump,Dev_dump,Fun_dump);
		if(RetValue!=0xffff&&RetValue!=0x0)
		{
				if((RetValue=CheckCapabiliteStatus(Bus_dump,Dev_dump,Fun_dump))==0x10)
				{	DumpBridgeDevSvidSid(Bus_dump,Dev_dump,Fun_dump);
						
				}
				else
				{	DumpGeneralDeviceSvidSid(Bus_dump,Dev_dump,Fun_dump);
						
				}
				//DumpPciDeviceCount=DumpPciDeviceCount+1;
		}
		return 0;
	}
unsigned int		DumpBridgeDevSvidSid(long Bus_Bri,long Dev_Bri,long Fun_Bri)
{
		unsigned int		RetValue,Bridgeflag=0;
		unsigned int		SVID=EOF,SSID=EOF;
		int			CapabiliteID=0xffff;
		long			CapabiliteReg=0;

		CapabiliteID=0xffff;
		CapabiliteReg=0;
		Bridgeflag=0;

		RetValue=ReadPciDevClassCode(Bus_Bri,Dev_Bri,Fun_Bri);

		if((RetValue>=0x0600&&RetValue<=0x0604)||(RetValue>=0x0800&&RetValue<=0x0803))
			{//[BridgeNoAddCode]
				CapabiliteReg=ReadReg34CapListPointerValue(Bus_Bri,Dev_Bri,Fun_Bri);				

				while(((CapabiliteID&0xff00)!=0)&&(Bridgeflag!=1))
				{
					CapabiliteID=WordReadPCI(Bus_Bri,Dev_Bri,Fun_Bri,CapabiliteReg);
					
					if((CapabiliteID&0x00ff)==0x0d)//use02 test ok This Set Bridgeflag=1;
						{
							Bridgeflag=1;
							SVID=WordReadPCI(Bus_Bri,Dev_Bri,Fun_Bri,CapabiliteReg=CapabiliteReg+4);		
							SSID=WordReadPCI(Bus_Bri,Dev_Bri,Fun_Bri,CapabiliteReg=CapabiliteReg+2);
							printf("Bus %02lX Dev %02lX Fun %02lX Reg %02lx \tSVID=%04X SSID=%04X",Bus_Bri,Dev_Bri,Fun_Bri,CapabiliteReg-2,SVID,SSID);//test out put)
							printf("\t");
							CheckPCIDeviceClassCode(Bus_Bri,Dev_Bri,Fun_Bri);
							printf("\r\n");					
						}
					CapabiliteReg=(CapabiliteID&0xff00)>>8;
				}
						
				if(Bridgeflag!=1)
					{
						//CheckGeneralPciDeviceSvidSid(Bus_Bri,Dev_Bri,Fun_Bri);
						DumpGeneralDeviceSvidSid(Bus_Bri,Dev_Bri,Fun_Bri);
					}
					
						
			}
		else
			{
				//CheckGeneralPciDeviceSvidSid(Bus_Bri,Dev_Bri,Fun_Bri,fp);
				DumpGeneralDeviceSvidSid(Bus_Bri,Dev_Bri,Fun_Bri);
			}
		
		return	0;
}
//[Sub6.13_pci]
unsigned int		DumpGeneralDeviceSvidSid(long Bus_Gen,long Dev_Gen,long Fun_Gen )
{
	unsigned int		RetValue;
	unsigned int		SVID=EOF,SSID=EOF;
	SVID=ReadReg2cSvid(Bus_Gen,Dev_Gen,Fun_Gen);
	SSID=ReadReg2fSsid(Bus_Gen,Dev_Gen,Fun_Gen);
	printf("Bus %02lX Dev %02lX Fun %02lX Reg 2C \tSVID=%04X SSID=%04X",Bus_Gen,Dev_Gen,Fun_Gen,SVID,SSID);//test out put
	printf("\t");
	CheckPCIDeviceClassCode(Bus_Gen,Dev_Gen,Fun_Gen);
	printf("\r\n");
	return 0;
}



