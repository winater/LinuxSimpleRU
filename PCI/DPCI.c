long DPCI()
{
	unsigned long Bus;
	unsigned long Dev;
	unsigned long Fun;
	unsigned long Reg;
	unsigned long PCI_DWordData;
	switch(CommandArray[DPCI_CmdID].ParameterCount)
	{
		case 1:
		if(CommandArray[DPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[DPCI_CmdID].ParameterValue[0];
			Dev=0;
			Fun=0;
			Reg=0;
			printf("-Bus %02lX, Dev 00, Fun 00, Reg 00\n",Bus);
		}
		else
		{
			printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//TestParameter
		}		
		break;
		
		case 2:	
		if(CommandArray[DPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[DPCI_CmdID].ParameterValue[0];
			if(CommandArray[DPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[DPCI_CmdID].ParameterValue[1];
			Fun=0;
			Reg=0;
			printf("-Bus %02lX, Dev %02lX, Fun 00, Reg 00\n",Bus,Dev);
			}
			else
			{
			printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
			printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		case 3:
		if(CommandArray[DPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[DPCI_CmdID].ParameterValue[0];
			if(CommandArray[DPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[DPCI_CmdID].ParameterValue[1];
				if(CommandArray[DPCI_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[DPCI_CmdID].ParameterValue[2];
				Reg=0;
				printf("-Bus %02lX, Dev %02lX, Fun %02lX, Reg 00\n",Bus,Dev,Fun);
				}
				else
				{printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nFun NO. should blow 0x8\n");//Test
				}
				
			}
			else
			{
			printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
		printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		case 4:
		if(CommandArray[DPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[DPCI_CmdID].ParameterValue[0];
			if(CommandArray[DPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[DPCI_CmdID].ParameterValue[1];
				if(CommandArray[DPCI_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[DPCI_CmdID].ParameterValue[2];
					if(CommandArray[DPCI_CmdID].ParameterValue[3]<0x100)//Fun
					{
					Reg=CommandArray[DPCI_CmdID].ParameterValue[3];
					}
					else
					{printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nReg NO. should blow 0x100\n");//Test
					}
				}
				else
				{printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nFun NO. should blow 0x8\n");//Test
				}
				
			}
			else
			{
			printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
		printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
		}	
		break;

		case 5:
		if(CommandArray[DPCI_CmdID].ParameterValue[0]<0x100)//Bus
		{
			Bus=CommandArray[DPCI_CmdID].ParameterValue[0];
			if(CommandArray[DPCI_CmdID].ParameterValue[1]<0x20)//Dev
			{
			Dev=CommandArray[DPCI_CmdID].ParameterValue[1];
				if(CommandArray[DPCI_CmdID].ParameterValue[2]<0x8)//Fun
				{
				Fun=CommandArray[DPCI_CmdID].ParameterValue[2];
					if(CommandArray[DPCI_CmdID].ParameterValue[3]<0x100)//Fun
					{
					Reg=CommandArray[DPCI_CmdID].ParameterValue[3];
						
					PCI_DWordData=(unsigned short)CommandArray[DPCI_CmdID].ParameterValue[4];
						//printf("PCI_DWordData=%02X\n",PCI_DWordData);//TestOK
					PCI_DWordData=DWordWriteReadPCI(Bus,Dev,Fun,Reg,PCI_DWordData);
						
						
					}
					else
					{printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nReg NO. should blow 0x100\n");//Test
					}
				}
				else
				{printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nFun NO. should blow 0x8\n");//Test
				}
				
			}
			else
			{
			printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nDev NO. should blow 0x20\n");//Test
			}
		}
		else
		{
		printf("Command:DPCI(Bus,Dev,Fun,Offset,WriteValue)Or=WriteValue\nBus NO. should blow 0x100\n");//Test
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
	if(CommandArray[DPCI_CmdID].ParameterCount<5)
	{
	PCI_DWordData=DWordReadPCI(Bus,Dev,Fun,Reg);
	}
	
	printf("%08lX\n",PCI_DWordData);
	return 0;
}
