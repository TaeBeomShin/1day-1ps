#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_COMMAND_SIZE 50

int IsCorrectInput(char* command);
void PrintUserCommand(char command);

int main()
{	
	char cmdLine[ MAX_COMMAND_SIZE ] = { 0, };

	while( gets( cmdLine ) ){
		if(IsCorrectInput(cmdLine)){
			puts("inspection\n");
			PrintUserCommand(cmdLine[0]);
			if(cmdLine[0]=='e') break;
		}
	}
}

int IsCorrectInput(char* command){
	if(command=="copy"||command=="delete"||command=="format"||command=="help"||command=="ext") return TRUE;
	
	return FALSE;
}

void PrintUserCommand(char command){
	switch(command){
		case 'c' :
            puts("copy");
            break;

         case 'd' :
            puts("delete");
            break;

         case 'f' :
            puts("format");
            break;

         case 'h' :
            puts("help");
            break;

         case 'e' :
            puts("exit");
	}
}

