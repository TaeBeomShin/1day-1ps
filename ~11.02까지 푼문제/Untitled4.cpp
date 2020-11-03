#include<stdio.h>

void asterisk(int i)
{
	if(i>1){
		asterisk(i/3);
		asterisk(i/3);
	}
	printf("*");
}

int main(){
	asterisk(9);
}
