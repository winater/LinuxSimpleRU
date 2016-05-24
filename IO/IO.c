//IO Byte Access
int ByteReadPort(int IOAddress)
{
	int Port_ByteData;
	Port_ByteData=inb(IOAddress);
	return Port_ByteData;
}

int ByteWritePort(int IOAddress,int Port_ByteData)
{
	outb(Port_ByteData,IOAddress);
	return Port_ByteData;
}

int ByteWriteReadPort(int IOAddress,int Port_ByteData)
{
	outb(Port_ByteData,IOAddress);
	Port_ByteData=inb(IOAddress);
	return Port_ByteData;
}
//IO Word Access
unsigned short WordReadPort(unsigned int IOAddress)
{
	unsigned short Port_WordData;
	Port_WordData=inw(IOAddress);
	return Port_WordData;
}
unsigned short WordWritePort(int IOAddress,unsigned short Port_WordData)
{
	outw(Port_WordData,IOAddress);
	return Port_WordData;
}
unsigned short WordWriteReadPort(int IOAddress,unsigned short Port_WordData)
{
	outw(Port_WordData,IOAddress);
	Port_WordData=inw(IOAddress);
	return Port_WordData;
}

//IO DWord Access
unsigned long DWordReadPort(unsigned int IOAddress)
{
	unsigned long Port_DWordData;
	Port_DWordData=inl(IOAddress);
	return Port_DWordData;
}

unsigned long DWordWritePort(int IOAddress,unsigned long Port_DWordData)
{
	outl(Port_DWordData,IOAddress);
	return Port_DWordData;
}

unsigned long DWordWriteReadPort(int IOAddress,unsigned long Port_DWordData)
{
	outl(Port_DWordData,IOAddress);
	Port_DWordData=inl(IOAddress);
	return Port_DWordData;
}
