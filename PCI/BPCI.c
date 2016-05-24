
long BPCI()
{
	unsigned long Bus;
	unsigned long Dev;
	unsigned long Fun;
	unsigned long Reg;
	unsigned short PCI_ByteData;
	switch(CommandArray[BPCI_CmdID].ParameterCount)
	{
		case 1:
		if(CommandArray[BPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[BPCI_CmdID].ParameterValue[0];
			Dev=0;
			Fun=0;
			Reg=0;
			printf("-Bus %02lX, Dev 00, Fun 00, Reg 00\n",Bus);
		}
		else
		{
			printf("Command:BPCI(BPCIBus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}		
		break;
		
		case 2:	
		if(CommandArray[BPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[BPCI_CmdID].ParameterValue[0];
			if(CommandArray[BPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[BPCI_CmdID].ParameterValue[1];
			Fun=0;
			Reg=0;
			printf("-Bus %02lX, Dev %02lX, Fun 00, Reg 00\n",Bus,Dev);
			}
			else
			{
			printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
			printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		case 3:
		if(CommandArray[BPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[BPCI_CmdID].ParameterValue[0];
			if(CommandArray[BPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[BPCI_CmdID].ParameterValue[1];
				if(CommandArray[BPCI_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[BPCI_CmdID].ParameterValue[2];
				Reg=0;
				printf("-Bus %02lX, Dev %02lX, Fun %02lX, Reg 00\n",Bus,Dev,Fun);
				}
				else
				{printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nFun NO. should blow 0x8\n");//Test
				}
				
			}
			else
			{
			printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
		printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		case 4:
		if(CommandArray[BPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[BPCI_CmdID].ParameterValue[0];
			if(CommandArray[BPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[BPCI_CmdID].ParameterValue[1];
				if(CommandArray[BPCI_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[BPCI_CmdID].ParameterValue[2];
					if(CommandArray[BPCI_CmdID].ParameterValue[3]<0x100)//Fun
					{
					Reg=CommandArray[BPCI_CmdID].ParameterValue[3];
					}
					else
					{printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nReg NO. should blow 0x100\n");//Test
					}
				}
				else
				{printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nFun NO. should blow 0x8\n");//Test
				}
				
			}
			else
			{
			printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
		printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		case 5:
		if(CommandArray[BPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[BPCI_CmdID].ParameterValue[0];
			if(CommandArray[BPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[BPCI_CmdID].ParameterValue[1];
				if(CommandArray[BPCI_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[BPCI_CmdID].ParameterValue[2];
					if(CommandArray[BPCI_CmdID].ParameterValue[3]<0x100)//Fun
					{
					Reg=CommandArray[BPCI_CmdID].ParameterValue[3];
						if(CommandArray[BPCI_CmdID].ParameterValue[4]<0x100)//WritreValue
						{PCI_ByteData=(unsigned short)CommandArray[BPCI_CmdID].ParameterValue[4];
							//printf("PCI_ByteData=%02X\n",PCI_ByteData);//TestOK
						PCI_ByteData=ByteWriteReadPCI(Bus,Dev,Fun,Reg,PCI_ByteData);
						}
						else
						{printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\n'WriteValue' should blow 0x100\n");//Test
						}
					}
					else
					{printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nReg NO. should blow 0x100\n");//Test
					}
				}
				else
				{printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nFun NO. should blow 0x8\n");//Test
				}
				
			}
			else
			{
			printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
		printf("Command:BPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		default:
			Bus=0;
			Dev=0;
			Fun=0;
			Reg=0;
			printf("-Bus 00, Dev 00, Fun 00, Reg 00\n",Bus);
		;
	}
	if(CommandArray[BPCI_CmdID].ParameterCount<5)
	{
	PCI_ByteData=(unsigned short)ByteReadPCI(Bus,Dev,Fun,Reg);
	}
	PCI_ByteData=PCI_ByteData&0x0FF;
	printf("%02X\n",PCI_ByteData);
	return 0;
}
