LSTPCI()
{	
	unsigned long Bus,Dev,Fun,Reg;
	unsigned short HeaderType;

	//printf("List All Exist PCI Fun .\r\n");
	printf("BusNO. DevNO. FunNO.\tVendorID  DeviceID\tDeviceInformation\r\n\r\n");
	for(Bus=0;Bus<0x100;Bus++)
	{
		for(Dev=0;Dev<32;Dev++)
		{
			for(Fun=0;Fun<0x8;Fun++)
			{
			if(Fun==0)
				{
				HeaderType=WordReadPCI(Bus,Dev,Fun,0x0E);
				HeaderType=HeaderType&0x0080;
				LSTPCIFun(Bus,Dev,Fun);
				}
			else
				{
				if(HeaderType==0x80)
				LSTPCIFun(Bus,Dev,Fun);
				}
			}
		}
	}
	printf("\r\n");
	return 0;
}
long LSTPCIFun(unsigned long Bus,unsigned long Dev,unsigned long Fun)
{
unsigned short VendorID,DeviceID;
VendorID=WordReadPCI(Bus,Dev,Fun,0);
DeviceID=WordReadPCI(Bus,Dev,Fun,2);
if(VendorID!=0&&VendorID!=0xFFFF)
	{
	printf("%02X\t%02X\t%02X\t %04X\t   %04X\t\t",Bus,Dev,Fun,VendorID,DeviceID);
	CheckPCIDeviceClassCode(Bus,Dev,Fun);
	printf("\r\n");
	}

}
