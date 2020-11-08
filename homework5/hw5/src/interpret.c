#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCIIconversion 97

int main(int argc, char* argv[])
{
	char text[100][64];
	FILE* fp = fopen(argv[1], "r");
	int i = 0;
	while(fgets(text[i], 64, fp)!=NULL){
		i++;
	}
	for(int j = 0; j<i; j++){
		printf("%s", text[j]);
		char command[6];
		char op1[8];
		char op2[8];
		char op3[8];
		strcpy(command, strtok(text[j], " "));
		printf("%s\n", command);
	}

}
