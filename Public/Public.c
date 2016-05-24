
long WritePublicBuffer(char WriteValue)
{	
	long    RetValue=0;
	long	BufferSize=0;
	long	n;
	BufferSize=sizeof(PublicBuffer);
		//printf("BufferSize=%lx\n",BufferSize);//Test
	for(n=0;n<BufferSize;n++)
	{
		PublicBuffer[n]=WriteValue;
			//printf(" SUB01-04 ImageLayoutFileName[%04ld]=%d\n",n,ImageLayoutFileName[n]);//test	
	}
	return RetValue;
}

long ClearPublicBuffer()
{
	WritePublicBuffer('\0');
}

