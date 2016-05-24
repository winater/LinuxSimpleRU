//ReadPCI
char ByteReadPCI(unsigned long Bus,unsigned long Dev,unsigned long Fun,unsigned long Reg)
{
	unsigned long	PciConfigAddress=0x80000000;
	unsigned long	PciRegOffset=0;
	unsigned int	IOAddress;
	char		PCI_ByteData;
	Bus=Bus<<16;
	Dev=Dev<<11;
	Fun=Fun<<8;
	PciRegOffset=Reg&03;
	IOAddress=0x0CFC+PciRegOffset;
	Reg=Reg&0xfc;
	PciConfigAddress=Bus|Dev|Fun|Reg|0x80000000;
	DWordWriteReadPort(0x0CF8,PciConfigAddress);
	PCI_ByteData=(char)ByteReadPort(IOAddress);
	return PCI_ByteData;
}

unsigned short WordReadPCI(unsigned long Bus,unsigned long Dev,unsigned long Fun,unsigned long Reg)
{
	unsigned long	PciConfigAddress=0x80000000;
	unsigned long	PciRegOffset=0;
	unsigned int	IOAddress;
	unsigned short	PCI_WordData;
	Bus=Bus<<16;
	Dev=Dev<<11;
	Fun=Fun<<8;
	PciRegOffset=Reg&02;
	IOAddress=0x0CFC+PciRegOffset;
	Reg=Reg&0xfc;
	PciConfigAddress=Bus|Dev|Fun|Reg|0x80000000;
	DWordWriteReadPort(0x0CF8,PciConfigAddress);
	PCI_WordData=WordReadPort(IOAddress);
	return PCI_WordData;
}

unsigned long DWordReadPCI(unsigned long Bus,unsigned long Dev,unsigned long Fun,unsigned long Reg)
{	
	unsigned long	PciConfigAddress=0x80000000;
	unsigned long	PciRegOffset=0;
	unsigned int	IOAddress;
	unsigned long	PCI_DWordData;
	Bus=Bus<<16;
	Dev=Dev<<11;
	Fun=Fun<<8;
	PciRegOffset=Reg&00;
	IOAddress=0x0CFC+PciRegOffset;
	Reg=Reg&0xFC;
	PciConfigAddress=Bus|Dev|Fun|Reg|0x80000000;
	DWordWriteReadPort(0x0CF8,PciConfigAddress);
	PCI_DWordData=DWordReadPort(IOAddress);
	return PCI_DWordData;

}
//WriteReadPCI
unsigned short ByteWriteReadPCI(unsigned long Bus,unsigned long Dev,unsigned long Fun,unsigned long Reg,unsigned short PCI_ByteData)
{
	unsigned long	PciConfigAddress=0x80000000;
	unsigned long	PciRegOffset=0;
	unsigned int	IOAddress;

	Bus=Bus<<16;
	Dev=Dev<<11;
	Fun=Fun<<8;
	PciRegOffset=Reg&03;
	IOAddress=0x0CFC+PciRegOffset;
	Reg=Reg&0xfc;
	PciConfigAddress=Bus|Dev|Fun|Reg|0x80000000;
	DWordWriteReadPort(0x0CF8,PciConfigAddress);
	PCI_ByteData=ByteWriteReadPort(IOAddress,PCI_ByteData);
	return PCI_ByteData;
	
}

unsigned short WordWriteReadPCI(unsigned long Bus,unsigned long Dev,unsigned long Fun,unsigned long Reg,unsigned short PCI_WordData)
{	unsigned long	PciConfigAddress=0x80000000;
	unsigned long	PciRegOffset=0;
	unsigned int	IOAddress;
	
	Bus=Bus<<16;
	Dev=Dev<<11;
	Fun=Fun<<8;
	PciRegOffset=Reg&02;
	IOAddress=0x0CFC+PciRegOffset;
	Reg=Reg&0xfc;
	PciConfigAddress=Bus|Dev|Fun|Reg|0x80000000;
	DWordWriteReadPort(0x0CF8,PciConfigAddress);
	PCI_WordData=WordWriteReadPort(IOAddress,PCI_WordData);
	return PCI_WordData;

}

unsigned long DWordWriteReadPCI(unsigned long Bus,unsigned long Dev,unsigned long Fun,unsigned long Reg,unsigned long PCI_DWordData)
{
	unsigned long	PciConfigAddress=0x80000000;
	unsigned long	PciRegOffset=0;
	unsigned int	IOAddress;

	Bus=Bus<<16;
	Dev=Dev<<11;
	Fun=Fun<<8;
	PciRegOffset=Reg&00;
	IOAddress=0x0CFC+PciRegOffset;
	Reg=Reg&0xFC;
	PciConfigAddress=Bus|Dev|Fun|Reg|0x80000000;
	DWordWriteReadPort(0x0CF8,PciConfigAddress);
	PCI_DWordData=DWordWriteReadPort(IOAddress,PCI_DWordData);
	return PCI_DWordData;
}
unsigned short CheckPciDeviceIfOrNotExist(unsigned long Bus,unsigned long Dev,unsigned long Fun)
{
unsigned short	PCI_WordData;
PCI_WordData=DWordReadPCI(Bus,Dev,Fun,0);
return PCI_WordData;
}

unsigned int		CheckPciDeviceIfOrNotMultiFunction(long Bus_Mul,long Dev_Mul)
{	unsigned int		RetValue;
	
	RetValue=WordReadPCI(Bus_Mul,Dev_Mul,0,0);
	if(RetValue!=0xFFFF&&RetValue!=0)
		{
			RetValue=WordReadPCI(Bus_Mul,Dev_Mul,0,0x0E);
			RetValue=RetValue&0x80;
			if(RetValue==0x80)
				{		
					RetValue=1;
				}
			else
				{
					RetValue=0;
				}
		}
return	RetValue;
}

unsigned	int		CheckCapabiliteStatus(long Bus_CP,long Dev_CP,long Fun_CP)
{	int		RetValue;
	RetValue=WordReadPCI(Bus_CP,Dev_CP,Fun_CP,06);
				
	return	RetValue=RetValue&0x10;
}

//[Sub6.3_pci]
	unsigned int		ReadReg2cSvid(long Bus_2C,long Dev_2C ,long Fun_2C)
	{	unsigned int		RetValue;
		RetValue=WordReadPCI(Bus_2C,Dev_2C,Fun_2C,0x2C);
		return	RetValue;
	}
//[Sub6.4_pci]
	unsigned int		ReadReg2fSsid(long Bus_2F,long Dev_2F ,long Fun_2F)
	{	unsigned  int		RetValue;
		RetValue=WordReadPCI(Bus_2F,Dev_2F,Fun_2F,0x2E);
		return	RetValue;
	}
	unsigned 	int		ReadReg34CapListPointerValue(long Bus_CPV,long Dev_CPV ,long Fun_CPV)
	{	unsigned int		RetValue;
		RetValue=WordReadPCI(Bus_CPV,Dev_CPV,Fun_CPV,0x34);
		RetValue=RetValue&0xff;
		return	RetValue;
	}
//[Sub6.7_pci]
	unsigned int		ReadPciDevClassCode(long Bus_CC,long Dev_CC,long Fun_CC)
	{	unsigned int		RetValue;
		RetValue=WordReadPCI(Bus_CC,Dev_CC,Fun_CC,0x0A);		
		return	RetValue;
	}
