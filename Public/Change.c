
char	ChangeOneAsciiToValue(char ChangeAscii)
	{	
		char		n=EOF;
		if((ChangeAscii>='0')&&(ChangeAscii<='9'))
		{n='A';
		}
		if((ChangeAscii>='A')&&(ChangeAscii<='F'))
		{n='B';
		}
		if((ChangeAscii>='a')&&(ChangeAscii<='f'))
		{n='C';
		}
		switch(n)
			{	case	'A':
						ChangeAscii=ChangeAscii-0x30;			
						break;
				case	'B':
						ChangeAscii=ChangeAscii-0x37;				
						break;
				case	'C':
						ChangeAscii=ChangeAscii-0x57;			
						break;
				default		:
						ChangeAscii=EOF;				
			}	
		return	ChangeAscii;
	}
