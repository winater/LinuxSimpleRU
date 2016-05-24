long PCIDump()
{
	unsigned long Bus;
	unsigned long Dev;
	unsigned long Fun;
	unsigned long Reg;
	unsigned long Length;
	unsigned long Limit;
	unsigned short	PCI_WordData,HeaderType;//Use Detect Device If Or Not Exist
	switch(CommandArray[PCIDUMP_CmdID].ParameterCount)
	{
		case 1:
		if(CommandArray[PCIDUMP_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[PCIDUMP_CmdID].ParameterValue[0];
			Dev=0;
			Fun=0;
			Reg=0;
			Length=0x100;
			printf("-Bus %02lX, Dev 00, Fun 00, Reg 00\r\n",Bus);
		}
		else
		{
			printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nBus NO. should blow 0x100\r\n");//Test
		}		
		break;
		
		case 2:	
		if(CommandArray[PCIDUMP_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[PCIDUMP_CmdID].ParameterValue[0];
			if(CommandArray[PCIDUMP_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[PCIDUMP_CmdID].ParameterValue[1];
			Fun=0;
			Reg=0;
			Length=0x100;
			printf("-Bus %02lX, Dev %02lX, Fun 00, Reg 00\r\n",Bus,Dev);
			}
			else
			{
			printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nDev NO. should blow 0x20\r\n");//Test
			}
		}
		else
		{
			printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nBus NO. should blow 0x100\r\n");//Test
		}	
		break;

		case 3:
		if(CommandArray[PCIDUMP_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[PCIDUMP_CmdID].ParameterValue[0];
			if(CommandArray[PCIDUMP_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[PCIDUMP_CmdID].ParameterValue[1];
				if(CommandArray[PCIDUMP_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[PCIDUMP_CmdID].ParameterValue[2];
				Reg=0;
				Length=0x100;
				printf("-Bus %02lX, Dev %02lX, Fun %02lX, Reg 00\r\n",Bus,Dev,Fun);
				}
				else
				{printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nFun NO. should blow 0x8\r\n");//Test
				}
				
			}
			else
			{
			printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nDev NO. should blow 0x20\r\n");//Test
			}
		}
		else
		{
		printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nBus NO. should blow 0x100\r\n");//Test
		}	
		break;

		case 4:
		if(CommandArray[PCIDUMP_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[PCIDUMP_CmdID].ParameterValue[0];
			if(CommandArray[PCIDUMP_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[PCIDUMP_CmdID].ParameterValue[1];
				if(CommandArray[PCIDUMP_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[PCIDUMP_CmdID].ParameterValue[2];
					if(CommandArray[PCIDUMP_CmdID].ParameterValue[3]<0x100)//Fun
					{
					Reg=CommandArray[PCIDUMP_CmdID].ParameterValue[3];
					Length=0x100-Reg;
					}
					else
					{printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nReg NO. should blow 0x100\r\n");//Test
					}
				}
				else
				{printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nFun NO. should blow 0x8\r\n");//Test
				}
				
			}
			else
			{
			printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nDev NO. should blow 0x20\r\n");//Test
			}
		}
		else
		{
		printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nBus NO. should blow 0x100\r\n");//Test
		}	
		break;

		case 5:
		if(CommandArray[PCIDUMP_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[PCIDUMP_CmdID].ParameterValue[0];
			if(CommandArray[PCIDUMP_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[PCIDUMP_CmdID].ParameterValue[1];
				if(CommandArray[PCIDUMP_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[PCIDUMP_CmdID].ParameterValue[2];
					if(CommandArray[PCIDUMP_CmdID].ParameterValue[3]<0x100)//Fun
					{
					Reg=CommandArray[PCIDUMP_CmdID].ParameterValue[3];
					Length=(unsigned long)CommandArray[PCIDUMP_CmdID].ParameterValue[4];	
					Limit=Reg+Length;
					if(Limit>0x100)
						{
						Length=0x100-Reg;
						printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\n'Reg'+'Length' should blow 0x100\r\n");//Test
						}
					
					}
					else
					{printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nReg NO. should blow 0x100\r\n");//Test
					}
				}
				else
				{printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nFun NO. should blow 0x8\r\n");//Test
				}
				
			}
			else
			{
			printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nDev NO. should blow 0x20\r\n");//Test
			}
		}
		else
		{
		printf("Command:PCIDump(Bus,Dev,Fun,Offset,Length)Or=Length\nBus NO. should blow 0x100\r\n");//Test
		}	
		break;

		default:
			Bus=0;
			Dev=0;
			Fun=0;
			Reg=0;
			Length=0x100;
			printf("-PCIDump(0,0,0,0,0x100)\r\n");
		;
	}

	PCI_WordData=CheckPciDeviceIfOrNotExist(Bus,Dev,Fun);
	if(Fun!=0)
	{
	HeaderType=WordReadPCI(Bus,Dev,0,0x0E);
	HeaderType=HeaderType&0x0080;
		if(HeaderType==0x80)
			{
				if(PCI_WordData!=0xFFFF)
				{
				PCIDump_Fun(Bus,Dev,Fun,Reg,Length);
				}
				else
				{
				printf("This device fun not exist !\r\n");
				}
			}
		else
			{
			printf("This device not multi-function device !\r\n");
			}
	}
	else
	{
		if(PCI_WordData!=0xFFFF)
		{
		PCIDump_Fun(Bus,Dev,Fun,Reg,Length);
		}
		else
		{
		printf("This Device Fun Not Exist !\r\n");
		}
	}
	return 0;
}

long PCIDump_Fun(unsigned long Bus,unsigned long Dev,unsigned long Fun,unsigned long Reg,unsigned long Length)
{
	unsigned long Limit,DisplayData;
	unsigned long Offset=0x00,Offset1=0;
	unsigned long PCI_DWordData,Line,Mod;

	Mod=Reg%4;
	if(Mod!=0)
	{Reg=Reg&0xFC;}
	Mod=Length%4;
	if(Mod<4&&Mod!=0)
	{Length=(Length-Mod)+4;}
	Limit=Reg+Length;

	Offset=Reg;
	Offset1=Offset+0xF;
	printf("Offset :  03 -- 00 07 -- 04 0B -- 08 0F -- 0C\r\n%02X -- %02X  ",Offset,Offset1);
	
	for(Line=0;Reg<Limit;)
	{
	PCI_DWordData=DWordReadPCI(Bus,Dev,Fun,Reg);
	PCI_DWordData=PCI_DWordData&0xFFFFFFFF;
	printf("%08X ",PCI_DWordData);
	Reg+=4;
	Line+=1;
	if(Line==4)
		{
		Line=0;
		Offset=Reg;
		//Control Display
		if((Limit-Offset)>=0xF)
		{Offset1=Offset+0xF;}
		else
		{Offset1=Offset+(Limit-Offset-1);}
		if(Offset1<Limit&&Limit>Offset)
		printf("\r\n%02X -- %02X  ",Offset,Offset1);
		}
	}
	printf("\r\r\n");	
	return 0;
}
