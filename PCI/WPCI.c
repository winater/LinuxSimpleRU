long WPCI()
{
	unsigned long Bus;
	unsigned long Dev;
	unsigned long Fun;
	unsigned long Reg;
	unsigned short PCI_WordData;
	switch(CommandArray[WPCI_CmdID].ParameterCount)
	{
		case 1:
		if(CommandArray[WPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[WPCI_CmdID].ParameterValue[0];
			Dev=0;
			Fun=0;
			Reg=0;
			printf("-Bus %02lX, Dev 00, Fun 00, Reg 00\n",Bus);
		}
		else
		{
			printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}		
		break;
		
		case 2:	
		if(CommandArray[WPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[WPCI_CmdID].ParameterValue[0];
			if(CommandArray[WPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[WPCI_CmdID].ParameterValue[1];
			Fun=0;
			Reg=0;
			printf("-Bus %02lX, Dev %02lX, Fun 00, Reg 00\n",Bus,Dev);
			}
			else
			{
			printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
			printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		case 3:
		if(CommandArray[WPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[WPCI_CmdID].ParameterValue[0];
			if(CommandArray[WPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[WPCI_CmdID].ParameterValue[1];
				if(CommandArray[WPCI_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[WPCI_CmdID].ParameterValue[2];
				Reg=0;
				printf("-Bus %02lX, Dev %02lX, Fun %02lX, Reg 00\n",Bus,Dev,Fun);
				}
				else
				{printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nFun NO. should blow 0x8\n");//Test
				}
				
			}
			else
			{
			printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
		printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		case 4:
		if(CommandArray[WPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[WPCI_CmdID].ParameterValue[0];
			if(CommandArray[WPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[WPCI_CmdID].ParameterValue[1];
				if(CommandArray[WPCI_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[WPCI_CmdID].ParameterValue[2];
					if(CommandArray[WPCI_CmdID].ParameterValue[3]<0x100)//Fun
					{
					Reg=CommandArray[WPCI_CmdID].ParameterValue[3];
					}
					else
					{printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nReg NO. should blow 0x100\n");//Test
					}
				}
				else
				{printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nFun NO. should blow 0x8\n");//Test
				}
				
			}
			else
			{
			printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
		printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		case 5:
		if(CommandArray[WPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[WPCI_CmdID].ParameterValue[0];
			if(CommandArray[WPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[WPCI_CmdID].ParameterValue[1];
				if(CommandArray[WPCI_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[WPCI_CmdID].ParameterValue[2];
					if(CommandArray[WPCI_CmdID].ParameterValue[3]<0x100)//Fun
					{
					Reg=CommandArray[WPCI_CmdID].ParameterValue[3];
						if(CommandArray[WPCI_CmdID].ParameterValue[4]<0x10000)//WritreValue
						{PCI_WordData=(unsigned short)CommandArray[WPCI_CmdID].ParameterValue[4];
							//printf("PCI_WordData=%02X\n",PCI_WordData);//TestOK
						PCI_WordData=WordWriteReadPCI(Bus,Dev,Fun,Reg,PCI_WordData);
						}
						else
						{printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\n'WriteValue' should blow 0x10000\n");//Test
						}
					}
					else
					{printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nReg NO. should blow 0x100\n");//Test
					}
				}
				else
				{printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nFun NO. should blow 0x8\n");//Test
				}
				
			}
			else
			{
			printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
		printf("Command:WPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
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
	if(CommandArray[WPCI_CmdID].ParameterCount<5)
	{
	PCI_WordData=(unsigned short)WordReadPCI(Bus,Dev,Fun,Reg);
	}

	printf("%04X\n",PCI_WordData);
	return 0;
}
