 //_____________________________________INCLUDE_FILE_____________________________________________  
 		#include <stdio.h>
		#include <sys/io.h>
		#include <unistd.h>

//_____________________________________DEFINE____________________________________________________
		//LruMainDefine
		#define PublicBufferLen	0x400	//1k
		//LruMainData
		int	UserCmdFlag=0;
		char	PublicBuffer[PublicBufferLen];
		#include "LinuxRU.Link"
//______________________________________Main_____________________________________________________
int main(int argc, char *argv[])
{
	int	RetValue=0; 

	iopl(3);	//Open Access IO right
	UserCmdFlag=0;
	InitCommand();
	if  (argc>1)
	{
	UserCmdFlag=1;
	DealUserCmd(argc,argv);;
	}
	else
	{
	 Help();
	 printf("Input you command :\r\n");

	 while(ExitFlag==0)
	 	{
		 printf("-");
		 GetUserInputCommand();
		}
		
	}
	iopl(0);	//Close Access IO right
	return	RetValue;
}
