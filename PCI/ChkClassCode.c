//_____________________________________Define___________________________________________________
		//ClassCode
		#define WriteFileFlag	1
		#define ClassCodeReg			0x0A
		#define ClassCodeInterfaceReg	0x08
		#define BaseCode00	  0x00	
		#define BaseCode01	  0x01
		#define BaseCode02	  0x02
		#define BaseCode03	  0x03
		#define BaseCode04	  0x04
		#define BaseCode05	  0x05
		#define BaseCode06	  0x06
		#define BaseCode07	  0x07
		#define BaseCode08	  0x08
		#define BaseCode09	  0x09
		#define BaseCode0A	  0x0A
		#define BaseCode0B	  0x0B
		#define BaseCode0C	  0x0C
		#define BaseCode0D	  0x0D
		#define BaseCode0E	  0x0E
		#define BaseCode0F	  0x0F
		#define BaseCode10	  0x10
		#define BaseCode11	  0x11
		#define BaseCode12	  0x12
		#define BaseCode13	  0x13

//_____________________________________ClassCode________________________________________________
unsigned int CheckPCIDeviceClassCode(long Bus,long Dev,long Fun)  //,FILE *fp)
{
	unsigned int	RetValue=0;
	unsigned int	BaseClassCode=0,SubClassCode,ClassCodeInterface;
	RetValue=WordReadPCI(Bus,Dev,Fun,ClassCodeReg)	;
	BaseClassCode=(RetValue&0x0FF00)>>8;
	SubClassCode=(RetValue&0x00FF);
	//	printf("BaseClassCode=%X\nSubClassCode=%X\n",BaseClassCode,SubClassCode);//Test
	RetValue=WordReadPCI(Bus,Dev,Fun,ClassCodeInterfaceReg)	;
	ClassCodeInterface=(RetValue&0x0FF00)>>8;
		//printf("ClassCodeInterface=%X\n",ClassCodeInterface);//Test
	switch(BaseClassCode)
	{	case	BaseCode00:
			CheckBaseCode00(SubClassCode,ClassCodeInterface);  //,fp);					
			break;
		case	BaseCode01:
			CheckBaseCode01(SubClassCode,ClassCodeInterface);  //,fp);							
			break;

		case	BaseCode02:
			CheckBaseCode02(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode03:
			CheckBaseCode03(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode04:
			CheckBaseCode04(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode05:
			CheckBaseCode05(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode06:
			CheckBaseCode06(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode07:
			CheckBaseCode07(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode08:
			CheckBaseCode08(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode09:
			CheckBaseCode09(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode0A:
			CheckBaseCode0A(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode0B:
			CheckBaseCode0B(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode0C:
			CheckBaseCode0C(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode0D:
			CheckBaseCode0D(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode0E:
			CheckBaseCode0E(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode0F:
			CheckBaseCode0F(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode10:
			CheckBaseCode10(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		case	BaseCode11:
			CheckBaseCode11(SubClassCode,ClassCodeInterface);  //,fp);						
			break;
		default		:
			ReservedBaseClassCode()	;		//Reserved Class Code 
	}
	
    return RetValue;

}

unsigned int CheckBaseCode00(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf("currently implemented devices");			//currently implemented devices

						
						//fprintf(ClsssCodeFP,"currently implemented devices \n");
						
						break;
				case	0x01:
						printf("VGA-compatible device");			//VGA-compatible device
						
						//fprintf(ClsssCodeFP,"VGA-compatible device \n");
						
						break;
				case	0x80:
									//none
						break;
				default		:
						printf(" ");
						//fprintf(ClsssCodeFP," \n");
				ReservedClassCode()		;
						
			}	
	return RetValue;
}

unsigned int CheckBaseCode01(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf("SCSI controller");			//SCSI bus controller
						
						//fprintf(ClsssCodeFP,"SCSI controller \n");
						
						break;
				case	0x01:
						printf("IDE controller");			//IDE controller (see Note 1)
						
						//fprintf(ClsssCodeFP,"IDE controller \n");
						
						break;
				case	0x02:

						printf("Floppy controller ");			//Floppy disk controller	
						
						//fprintf(ClsssCodeFP,"Floppy controller \n");
						
						break;
				case	0x03:
						printf("IPI bus controller");
									//IPI bus controller
						
						//fprintf(ClsssCodeFP,"IPI bus controller \n");
						
						break;
				case	0x04:
						printf("RAID controller ");
									//RAID controller
						
						//fprintf(ClsssCodeFP,"RAID controller \n");
						
						break;
				case	0x05:
						printf("ATA controller ");
									//ATA controller (Interface)
						
						//fprintf(ClsssCodeFP,"ATA controller \n");
						
						break;
				case	0x06:
						printf("SATA controller ");
									//Serial ATA controller每(Interface)
						
						//fprintf(ClsssCodeFP,"SATA controller \n");
						
						break;
				case	0x07:
						printf("SCSI (SAS) controller ");
									//Serial Attached SCSI (SAS) controller
						
						//fprintf(ClsssCodeFP,"SCSI (SAS) controller \n");
						
						break;
				case	0x80:
						printf("Other mass storage controller ");
									//Other mass storage controller
						
						//fprintf(ClsssCodeFP,"Other mass storage controller \n");
						
						break;

				default		:
						printf(" ");
						//fprintf(ClsssCodeFP," \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}


unsigned int CheckBaseCode02(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf("Ethernet controller ");
									//Ethernet controller
						
						//fprintf(ClsssCodeFP,"Ethernet controller \n");
						
						break;
				case	0x01:
						printf("Token Ring controller ");
									//Token Ring controller
						
						//fprintf(ClsssCodeFP,"Token Ring controller \n");
						
						break;
				case	0x02:
						printf("FDDI controller ");
									//FDDI controller
						
						//fprintf(ClsssCodeFP,"FDDI controller \n");
						
						break;
				case	0x03:
						printf("ATM controller ");
									//ATM controller
						
						//fprintf(ClsssCodeFP,"ATM controller \n");
						
						break;
				case	0x04:
						printf("ISDN controller ");
									//ISDN controller
						
						//fprintf(ClsssCodeFP,"ISDN controller \n");
						
						break;
				case	0x05:
						printf("WorldFip controller ");
									//WorldFip controller
						
						//fprintf(ClsssCodeFP,"WorldFip controller \n");
						
						break;
				case	0x06:
						printf("PICMG 2.14 Multi Computing ");
									//PICMG 2.14 Multi Computing
						
						//fprintf(ClsssCodeFP,"PICMG 2.14 Multi Computing \n");
						
						break;
				case	0x80:
						printf("Other network controller ");
									//Other network controller
						
						//fprintf(ClsssCodeFP,"Other network controller \n");
						
						break;
				default		:
						printf(" ");
						//fprintf(ClsssCodeFP," \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode03(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
					switch(ClassCodeInterface)
						{
							case 0x00:
								printf("VGA-compatible controller ");	//0.VGA-compatible controller.
								
								//fprintf(ClsssCodeFP,"VGA-compatible controller \n");
								
								break;
							case 0x01:
								printf("8514-compatible controller ");	//1.8514-compatible controller(InterFace)
								
								//fprintf(ClsssCodeFP,"8514-compatible controller \n");
								
								break;			
						}
									
						break;
				case	0x01:
						printf("XGA controller ");
									//XGA controller
						
						//fprintf(ClsssCodeFP,"XGA controller \n");
						
						break;
				case	0x02:
						printf("3D controller ");
									//3D controller
						
						//fprintf(ClsssCodeFP,"3D controller \n");
						
						break;
				case	0x80:
						printf("Other display controller ");
									//Other display controller
						
						//fprintf(ClsssCodeFP,"Other display controller \n");
						
						break;
				default		:
						printf("Display controller ");
						//fprintf(ClsssCodeFP,"Display controller \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode04(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf("Video device ");
									//Video device
						
						//fprintf(ClsssCodeFP,"Video device \n");
						
						break;
				case	0x01:
						printf("Audio device ");
									//Audio device
						
						//fprintf(ClsssCodeFP,"Audio device \n");
						
						break;
				case	0x02:
						printf("Computer telephony device ");
									//Computer telephony device
						
						//fprintf(ClsssCodeFP,"Computer telephony device \n");
						
						break;
				case	0x80:
						printf("Other multimedia device ");
									//Other multimedia device
						
						//fprintf(ClsssCodeFP,"Other multimedia device \n");
						
						break;
				default		:
						printf("Multimedia device ");
						//fprintf(ClsssCodeFP,"Multimedia device \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode05(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf("RAM ");
									//RAM
						
						//fprintf(ClsssCodeFP,"RAM \n");
						
						break;
				case	0x01:
						printf("Flash ");
									//Flash
						
						//fprintf(ClsssCodeFP,"Flash \n");
						
						break;
				case	0x80:
						printf("Other memory controller ");
									//Other memory controller
						
						//fprintf(ClsssCodeFP,"Other memory controller \n");
						
						break;
				default		:
						printf("Memory controller ");
						//fprintf(ClsssCodeFP,"Memory controller \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode06(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf("Host bridge ");
									//Host bridge
						
						//fprintf(ClsssCodeFP,"Host bridge \n");
						
						break;
				case	0x01:
						printf("ISA bridge ");
									//ISA bridge
						
						//fprintf(ClsssCodeFP,"ISA bridge \n");
						
						break;
				case	0x02:
						printf("EISA bridge ");
									//EISA bridge
						
						//fprintf(ClsssCodeFP,"EISA bridge \n");
						
						break;
				case	0x03:
						printf("MCA bridge ");
									//MCA bridge
						
						//fprintf(ClsssCodeFP,"MCA bridge \n");
						
						break;
				case	0x04:
							switch(ClassCodeInterface)
												{	
													//InterFace:
													case	0x00:	//0.PCI-to-PCI bridge,
													printf("P2P bridge ");
													
													//fprintf(ClsssCodeFP,"P2P bridge \n");
													
																
													break;

													case	0x01:	//01 Subtractive Decode PCI-to-PCIbridge 
													printf("Sub Decode P2P bridge  ");
													
													//fprintf(ClsssCodeFP,"Sub Decode P2P bridge \n");
													
																
													break;

													default		:
													printf("P2P bridge ");
													//fprintf(ClsssCodeFP,"P2P bridge \n");
														;
												}		
									
						break;
				case	0x05:
						printf("PCMCIA bridge ");
									//PCMCIA bridge
						
						//fprintf(ClsssCodeFP,"PCMCIA bridge \n");
						
						break;
				case	0x06:
						printf("NuBus bridge ");
									//NuBus bridge
						
						//fprintf(ClsssCodeFP,"NuBus bridge \n");
						
						break;
				case	0x07:
						printf("CardBus bridge ");
									//CardBus bridge
						
						//fprintf(ClsssCodeFP,"CardBus bridge \n");
						
						break;
				case	0x08:
						printf("RACEway bridge ");
									//RACEway bridge (see below)
						
						//fprintf(ClsssCodeFP,"RACEway bridge \n");
						
						
						break;
				case	0x09:
						printf("Semi-transparent P2P bridge ");
									//Semi-transparent PCI-to-PCI bridge
						
						//fprintf(ClsssCodeFP,"Semi-transparent P2P bridge \n");
						
						
						break;
				case	0x0A:
						printf("InfiniBand-to-PCI host bridge ");
									//InfiniBand-to-PCI host bridge
						
						//fprintf(ClsssCodeFP,"InfiniBand-to-PCI host bridge \n");
						
						break;
				case	0x80:
						printf("Other bridge device ");
									//Other bridge device
						
						//fprintf(ClsssCodeFP,"Other bridge device \n");
						
						break;
				default		:
						printf("Bridge device ");
						//fprintf(ClsssCodeFP,"Bridge device \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode07(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:

					switch(ClassCodeInterface)
												{	
													//InterFace:
													case	0x00:	//00 Generic XT-compatible serial controlle
													printf("Generic XT-compatible serial controlle ");
													
													//fprintf(ClsssCodeFP,"Generic XT-compatible serial controlle \n");
													
																
													break;

													case	0x01:	//01 16450-compatible serial controller
													printf("16450-compatible serial controller ");
													
													//fprintf(ClsssCodeFP,"16450-compatible serial controller \n");
													
																
													break;

													case	0x02:	//02 16550-compatible serial controller
													printf("16550-compatible serial controller ");
													
													//fprintf(ClsssCodeFP,"16550-compatible serial controller \n");
													
															
													break;

													case	0x03:	//03 16650-compatible serial controller
													printf("16650-compatible serial controller ");
													
													//fprintf(ClsssCodeFP,"16650-compatible serial controller \n");
													
																
													break;

													case	0x04:	//04 16750-compatible serial controller
													printf("16750-compatible serial controller ");
													
													//fprintf(ClsssCodeFP,"16750-compatible serial controller \n");
													
																
													break;

													case	0x05:	//05 16850-compatible serial controller
													printf("16850-compatible serial controller ");
													
													//fprintf(ClsssCodeFP,"16850-compatible serial controller \n");
													
																						
													break;

													case	0x06:	//06 16950-compatible serial controller	
													printf("16850-compatible serial controller	 ");
													
													//fprintf(ClsssCodeFP,"16850-compatible serial controller \n");
													
															
													break;

													default		:
													printf("Compatible serial controller ");
													//fprintf(ClsssCodeFP,"Compatible serial controller \n");
														;
												}		
													
						break;
				case	0x01:
				switch(ClassCodeInterface)
															{	
																//InterFace:
																case	0x00:	//00 Parallel port
																printf("Parallel port ");
																
																//fprintf(ClsssCodeFP,"Parallel port \n");
																
																												
																break;

																case	0x01:	//01 Bi-directional parallel port
																printf("Bi-directional parallel port ");
																
																//fprintf(ClsssCodeFP,"Bi-directional parallel port \n");
																
																													
																break;

																case	0x02:	//02 ECP 1.X compliant parallel port
																printf("ECP 1.X compliant parallel port ");
																
																//fprintf(ClsssCodeFP,"ECP 1.X compliant parallel port \n");
																
																		
																break;

																case	0x03:	//03 IEEE1284 controller
																printf("IEEE1284 controller ");
																
																//fprintf(ClsssCodeFP,"IEEE1284 controller \n");
																
																		
																break;

																case	0xFE:	//FE IEEE1284 target device (not a controller)
																printf("IEEE1284 target device ");
																
																//fprintf(ClsssCodeFP,"IEEE1284 target device \n");
																
																			
																break;

																default		:
																printf(" ");
																//fprintf(ClsssCodeFP," \n");
																	;
															}

						break;
				case	0x02:
						printf(" ");
									//Multiport serial controller
						break;
				case	0x03:
				switch(ClassCodeInterface)
												{	//InterFace:
													case	0x00://00 Generic modem
													printf("Generic modem ");
													
													
													//fprintf(ClsssCodeFP,"Generic modem \n");
													
																
													break;

													case	0x01://01 Hayes compatible modem, 16450-compatible interface (see below)
													printf("16450-compatible ");
													
													
													//fprintf(ClsssCodeFP,"16450-compatible \n");
													
																
													break;

													case	0x02:	//02 Hayes compatible modem, 16550-compatible interface (see below)
													printf("16550-compatible ");
															
													
													//fprintf(ClsssCodeFP,"16550-compatible \n");
													
													break;

													case	0x03:	//03 Hayes compatible modem, 16650-compatible interface (see below)
													printf("16650-compatible ");
														
													
													//fprintf(ClsssCodeFP,"16650-compatible \n");
														
													break;

													case	0x04:	//04 Hayes compatible modem, 16750-compatible interface (see below)	
													printf("16750-compatible ");
																
													
													//fprintf(ClsssCodeFP,"16750-compatible \n");
														
													break;

													default		:
													printf(" ");
													//fprintf(ClsssCodeFP," \n");
														;
												}
						break;
				case	0x04:
						printf("GPIB (IEEE 488.1/2) controller ");
									//GPIB (IEEE 488.1/2) controller
						
						//fprintf(ClsssCodeFP,"GPIB (IEEE 488.1/2) controller \n");
						
						break;
				case	0x05:
						printf("Smart Card ");
									//Smart Card
						
						//fprintf(ClsssCodeFP,"Smart Card \n");
						
						break;
				case	0x80:
						printf("Other communications device ");
									//Other communications device
						
						//fprintf(ClsssCodeFP,"Other communications device \n");
						
						break;
				default		:
						printf("Communications device ");
						//fprintf(ClsssCodeFP,"Communications device \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode08(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
				switch(ClassCodeInterface)
									{	//InterFace:
										case	0x00:	//00 Generic 8259 PIC
										printf("Generic 8259 PIC ");
										
										//fprintf(ClsssCodeFP,"eneric 8259 PIC \n");
										
												
										break;

										case	0x01:	//01 ISA PIC
										printf("ISA PIC ");
										
										//fprintf(ClsssCodeFP,"ISA PIC \n");
										
												
										break;

										case	0x02:	//02 EISA PIC
										printf("EISA PIC ");
										
										//fprintf(ClsssCodeFP,"EISA PIC \n");
										
												
										break;

										case	0x10:	//10 I/O APIC interrupt controller
										printf("I/O APIC interrupt controller ");
										
										//fprintf(ClsssCodeFP,"I/O APIC interrupt controller \n");
										
													
										break;

										case	0x20:	//20 I/O(x) APIC interrupt controller
										printf("I/O(x) APIC interrupt controller ");
										
										//fprintf(ClsssCodeFP,"I/O(x) APIC interrupt controller \n");
										
													
										break;

										default		:
										printf("Interrupt controller ");
										//fprintf(ClsssCodeFP,"Interrupt controller \n");
											;
									}								
						break;
				case	0x01:
					switch(ClassCodeInterface)
										{	//InterFace:
											case	0x00://00 Generic 8237 DMA controller
											printf("Generic 8237 DMA controller ");
											
											//fprintf(ClsssCodeFP,"Generic 8237 DMA controller \n");
											
													
											break;

											case	0x01://01 ISA DMA controller
											printf("ISA DMA controller ");
											
											//fprintf(ClsssCodeFP,"ISA DMA controller \n");
											
													
											break;

											case	0x02://02 EISA DMA controller
											printf("EISA DMA controller ");
											
											//fprintf(ClsssCodeFP,"EISA DMA controller \n");
											
																		
											break;

											default		:
												printf("DMA controller ");
												//fprintf(ClsssCodeFP,"DMA controller \n");
												;
										}				
						break;
				case	0x02:
					switch(ClassCodeInterface)
										{	
											//InterFace:
											case	0x00:	//00 Generic 8254 system timer
											printf("Generic 8254 system timer ");
											
											//fprintf(ClsssCodeFP,"Generic 8254 system timer \n");
											
														
											break;

											case	0x01:	//01 ISA system timer
											printf("ISA system timer ");
											
											//fprintf(ClsssCodeFP,"ISA system timer \n");
											
														
											break;

											case	0x02:	//02 EISA system timers (two timers)
											printf("EISA system timers ");
											
											//fprintf(ClsssCodeFP,"EISA system timers \n");
											
														//none
											break;

											default		:
											printf("System timers ");
											//fprintf(ClsssCodeFP,"System timers \n");
												;
										}	
						break;
				case	0x03:
								//InterFace:
				switch(ClassCodeInterface)
									{	
										case	0x00:	//00 Generic RTC controller
										printf("Generic RTC controller ");
												
										
										//fprintf(ClsssCodeFP,"Generic RTC controller \n");
										
										break;

										case	0x01:	//01 ISA RTC controller
										printf("ISA RTC controller ");
										
										
										//fprintf(ClsssCodeFP,"ISA RTC controller \n");
												
										break;

										default		:
										printf("RTC controller ");
										//fprintf(ClsssCodeFP,"RTC controller \n");
											;
									}

						break;
				case	0x04: 
						printf("Generic PCI Hot-Plug controller ");
								//Generic PCI Hot-Plug controller
						
						//fprintf(ClsssCodeFP,"Generic PCI Hot-Plug controller \n");
						
						break;
				case	0x05:
						printf("SD Host controller ");
								//SD Host controller
						
						//fprintf(ClsssCodeFP,"SD Host controller \n");
						
						break;
				case	0x80:
						printf("Other system peripheral ");
								//Other system peripheral
						
						//fprintf(ClsssCodeFP,"Other system peripheral \n");
						
						break;
				default		:
						printf("System peripheral ");
						//fprintf(ClsssCodeFP,"System peripheral \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode09(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf(" Keyboard controller");
								//Keyboard controller
						
						//fprintf(ClsssCodeFP,"Keyboard controller \n");
						
						break;
				case	0x01:
						printf("Digitizer (pen) ");
								//Digitizer (pen)
						
						//fprintf(ClsssCodeFP,"Digitizer (pen) \n");
						
						break;
				case	0x02:
						printf("Mouse controller ");
								//Mouse controller
						
						//fprintf(ClsssCodeFP,"Mouse controller \n");
						
						break;
				case	0x03:
						printf("Scanner controller ");
								//Scanner controller
						
						//fprintf(ClsssCodeFP,"Scanner controller \n");
						
						break;
				case	0x04:
				switch(ClassCodeInterface)
									{	
											//InterFace:
										case	0x00://00 Gameport controller (generic)
										printf("Gameport controller ");
										
										//fprintf(ClsssCodeFP,"Gameport controller \n");
										
												
										break;

										case	0x01://01 Gameport controller (see below)
										printf("Gameport controller ");
										
										//fprintf(ClsssCodeFP,"Gameport controller  \n");
										
																
										break;

										default		:
										printf(" ");
										//fprintf(ClsssCodeFP," \n");
											;
									}	
								//
						break;
				case	0x80:
						printf("Other input controller ");
								//Other input controller
						
						//fprintf(ClsssCodeFP,"Other input controller \n");
						
						break;
				default		:
						printf("Input controller ");
						//fprintf(ClsssCodeFP,"Input controller \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode0A(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	00:
						printf("Generic docking station ");
						
						//fprintf(ClsssCodeFP,"Generic docking station \n");
						
					
								//Generic docking station
						break;
				case	0x01:
					
								//
						break;

				case	0x80:
						printf("Other type of docking station ");
								//Other type of docking station
						
						//fprintf(ClsssCodeFP,"Other type of docking station \n");
						
						break;

				default		:
						printf("Type of docking station ");
						//fprintf(ClsssCodeFP,"Type of docking station \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode0B(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf("386 ");
									//386
						
						//fprintf(ClsssCodeFP,"386 \n");
						
						break;
				case	0x01:
						printf("486 ");
									//486
						
						//fprintf(ClsssCodeFP,"486 \n");
						
						break;
				case	0x02:
						printf("Pentium ");
									//Pentium
						
						//fprintf(ClsssCodeFP,"Pentium \n");
						
						break;

				case	0x10:
						printf("Alpha ");
					
									//Alpha
						
						//fprintf(ClsssCodeFP,"Alpha  \n");
						
						break;
				case	0x20:
						printf("PowerPC ");
									//PowerPC
						
						//fprintf(ClsssCodeFP,"PowerPC \n");
						
						
						break;
				case	0x30:
						printf("MIPS ");
									//MIPS
						
						//fprintf(ClsssCodeFP,"MIPS \n");
						
						break;
				case	0x40:
						printf("Co-processor ");
									//Co-processor
						
						//fprintf(ClsssCodeFP,"Co-processor \n");
						
						break;
				case	0x80:
						//printf(" ");
									//none
						break;
				default		:
						printf(" ");
						//fprintf(ClsssCodeFP," \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode0C(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
	switch(ClassCodeInterface)
						{	
								//interface
							case	0x00:	//00 IEEE 1394 (FireWire)
							printf("IEEE 1394 (FireWire) ");
							
							//fprintf(ClsssCodeFP,"IEEE 1394 (FireWire) \n");
							
									
							break;

							case	0x10:	//10 IEEE 1394 following the 1394 OpenHCI specification
							printf("IEEE 1394 following the 1394 OpenHCI ");
							
							//fprintf(ClsssCodeFP,"IEEE 1394 following the 1394 OpenHCI \n");
							
									
							break;

							default		:
							printf(" ");
							//fprintf(ClsssCodeFP," \n");
								;
						}

							
							
						break;
				case	0x01:
						printf("ACCESS.bus ");
								// ACCESS.bus
						
						//fprintf(ClsssCodeFP,"ACCESS.bus \n");
						
						break;
				case	0x02:
						printf("SSA ");
								//SSA
						
						//fprintf(ClsssCodeFP,"SSA \n");
						
						break;
				case	0x03:
								//interface
					switch(ClassCodeInterface)
						{	
							case	0x00:	//00 Universal Serial Bus (USB) followingthe Universal Host ControllerSpecification
							printf("USB ");
							
							//fprintf(ClsssCodeFP,"USB \n");
							
										
							break;

							case	0x10:	//10 Universal Serial Bus (USB) following the Open Host Controller Specification
							printf("USB ");
										//none
							
							//fprintf(ClsssCodeFP,"USB \n");
							
							break;

							case	0x20:	//20 USB2 host controller following the Intel Enhanced Host Controller Interface
							printf("USB2 host controller ");
							
							//fprintf(ClsssCodeFP,"USB2 host controller \n");
							
										
							break;

							case	0x80:	//80 Universal Serial Bus with no specific programming interface
							printf("Universal Serial Bus  ");
							
							//fprintf(ClsssCodeFP,"Universal Serial Bus \n");
							
									
							break;

							case	0xFE:	//FE USB device (not host controller)
							printf("USB device ");
							
							//fprintf(ClsssCodeFP,"USB device \n");
							
										
							break;

							default		:
							printf("USB ");
							//fprintf(ClsssCodeFP,"USB \n");
								;
						}
							
						break;
				case	0x04:
						printf("Fibre Channel ");
								//Fibre Channel
						
						//fprintf(ClsssCodeFP,"Fibre Channel \n");
						
						break;
				case	0x05:
						printf("SMBus ");
								//SMBus (System Management Bus)
						
						//fprintf(ClsssCodeFP,"SMBus \n");
						
						break;
				case	0x06:
						printf("InfiniBand ");
								//InfiniBand
						
						//fprintf(ClsssCodeFP,"InfiniBand \n");
						
						break;
				case	0x07:

								//interface
						switch(ClassCodeInterface)
						{	
							case	0x00:	//00 IPMI SMIC 
							printf("IPMI SMIC ");
							
							//fprintf(ClsssCodeFP,"IPMI SMIC \n");
							
										//none
							break;

							case	0x01://01 IPMI Kybd Controller Style
							printf("IPMI Kybd Controller Style ");
										//none
							
							//fprintf(ClsssCodeFP,"IPMI Kybd Controller Style \n");
							
							break;

							case	0x02://02 IPMI Block Transfer 
							printf("IPMI Block Transfer  ");
							
							//fprintf(ClsssCodeFP,"IPMI Block Transfer \n");
							
										//none
							break;

							default		:
							printf(" ");
							//fprintf(ClsssCodeFP," \n");
								;
						}			
								 
								
						break;
				case	0x08:
						printf("SERCOS ");
								//SERCOS Interface Standard (IEC 61491)
						
						//fprintf(ClsssCodeFP,"SERCOS \n");
						
						
						break;
				case	0x09:
						printf("CANbus ");
								//CANbus
						
						//fprintf(ClsssCodeFP,"CANbus \n");
						
						break;
				case	0x80:

						break;
				default		:
						printf(" ");
						//fprintf(ClsssCodeFP," \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode0D(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf("iRDA compatible controller ");
								// iRDA compatible controller
						
						//fprintf(ClsssCodeFP,"iRDA compatible controller \n");
						
						break;
				case	0x01:
						printf("Consumer IR controller ");
								// Consumer IR controller
						
						//fprintf(ClsssCodeFP,"Consumer IR controller \n");
						
						break;
				case	0x10:
						printf("RF controller ");
								// RF controller
						
						//fprintf(ClsssCodeFP,"RF controller \n");
						
						break;	
				case	0x11:
						printf("Bluetooth ");
								// Bluetooth
						
						//fprintf(ClsssCodeFP,"Bluetooth \n");
						
						break;
				case	0x12:
						printf("Broadband ");
								// Broadband
						
						//fprintf(ClsssCodeFP,"Broadband \n");
						
						
						break;
				case	0x20:
						printf("Ethernet (802.11a每5 GHz) ");
								// Ethernet (802.11a 每 5 GHz)
						
						//fprintf(ClsssCodeFP,"Ethernet (802.11a每5 GHz) \n");
						
						
						break;
				case	0x21:
						printf("Ethernet (802.11b每2.4 GHz) ");
								// Ethernet (802.11b 每 2.4 GHz)
						
						//fprintf(ClsssCodeFP,"Ethernet (802.11b每2.4 GHz) \n");
						
						break;
				case	0x80:
						printf("Other type of wireless controller ");
								// Other type of wireless controller
						
						//fprintf(ClsssCodeFP,"Other type of wireless controller \n");
						
						break;
				default		:
						printf(" ");
						//fprintf(ClsssCodeFP," \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode0E(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	00:
						printf("Message FIFO at offset 040h ");
								//Message FIFO at offset 040h
						
						//fprintf(ClsssCodeFP,"Message FIFO at offset 040h \n");
						
						break;
				case	0x80:
						
								//none
						break;
				default		:
				printf("Intelligent I/O (I2O)");		;//Intelligent I/O (I2O) Architecture Specification 1.0
						
				//fprintf(ClsssCodeFP,"Intelligent I/O (I2O) \n");
						
						
			}
	return RetValue;
}

unsigned int CheckBaseCode0F(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
							//none
								
						break;
				case	0x01:
						printf("TV ");
								//TV
						
						//fprintf(ClsssCodeFP,"TV \n");
						
						break;
				case	0x02:
						printf("Audio ");
								//Audio
						
						//fprintf(ClsssCodeFP,"Audio \n");
						
						break;
				case	0x03:
						printf("Voice ");
								//Voice
						
						//fprintf(ClsssCodeFP,"Voice \n");
						
						break;
				case	0x04:
						printf("Data ");
								//Data
						
						//fprintf(ClsssCodeFP,"Data \n");
						
						break;
				case	0x80:
					
						break;
				default		:
						printf(" ");
						//fprintf(ClsssCodeFP," \n");
				//ReservedClassCode()		
					;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode10(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:
						printf("Network and computing en/decryption ");
						
						//fprintf(ClsssCodeFP,"Network and computing en/decryption \n");
						
					
								//Network and computing en/decryption
						break;
				case	0x10:
						printf("Entertainment en/decryption ");
						
						//fprintf(ClsssCodeFP,"Entertainment en/decryption \n");
						
						
								//Entertainment en/decryption
						break;

				case	0x80:
						printf("Other en/decryption ");
						
						//fprintf(ClsssCodeFP,"Other en/decryption \n");
						
								//Other en/decryption
						break;
				default		:
						printf(" ");
						//fprintf(ClsssCodeFP," \n");
				//ReservedClassCode()		
					;
						
			}
	return RetValue;
}

unsigned int CheckBaseCode11(unsigned int SubClassCode,unsigned int ClassCodeInterface)  //,FILE *ClsssCodeFP)
{
	unsigned 	int	RetValue=0;
	switch(SubClassCode)
			{	case	0x00:	
						printf("DPIO modules ");
								//DPIO modules
						
						//fprintf(ClsssCodeFP,"DPIO modules \n");
						
						break;
				case	0x01:
						printf("Performance counters ");
						
								//Performance counters
						
						//fprintf(ClsssCodeFP,"Performance counters \n");
						
						break;
				case	0x10:
						printf("Communications synchronization plus time and frequency test/measurement ");
								//Communications synchronization plus time and frequency test/measurement
						
						//fprintf(ClsssCodeFP,"Communications synchronization plus time and frequency test/measurement \n");
						
						break;

				case	0x20:
						printf("Management card ");
								//Management card
						
						//fprintf(ClsssCodeFP,"Management card \n");
						
						break;
				case	0x80:
						printf("Other data acquisition/signal processing controllers ");
								//Other data acquisition/signal processing controllers
						
						//fprintf(ClsssCodeFP,"Other data acquisition/signal processing controllers \n");
						

						break ;

				default		:

						printf(" ");
						//fprintf(ClsssCodeFP," \n");
				ReservedClassCode()		;
						
			}
	return RetValue;
}

unsigned int ReservedBaseClassCode()	
{
	unsigned 	int	RetValue=0;

	return RetValue;
}


unsigned int ReservedClassCode()
{
	unsigned 	int	RetValue=0;

	return RetValue;
}
