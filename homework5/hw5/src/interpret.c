#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ASCIIconversion 97

int main(int argc, char* argv[])
{
	char text[100][64];
	FILE* fp = fopen(argv[1], "r");
	int i = 0;
	while(fgets(text[i], 64, fp)!=NULL){
		i++;
	}
	int registers[4];
	for(int j = 0; j<i; j++){
		//printf("%s", text[j]);
		char line[64];
		strcpy(line, text[j]);
		char command[6];
		char op1[8];
		char op2[8];
		char op3[8];
		strcpy(command, strtok(line, " "));
		if(command[0]=='\n'){
			continue;
		}
		if(strcmp(command, "mov")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			int reg = op2[0]-ASCIIconversion;
			if(isdigit(op1[0])!=0){
				registers[reg] = atoi(op1);
			}
			else{
				registers[reg] = registers[op1[0]-ASCIIconversion];
			}
		}
		else if(strcmp(command, "add")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			int reg = op2[0]-ASCIIconversion;
			if(isdigit(op1[0])!=0){
				registers[reg] = atoi(op1)+registers[reg];
			}
			else{
				registers[reg] = registers[op1[0]-ASCIIconversion] + registers[reg];
			}
		}	
		else if(strcmp(command, "sub")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			int reg = op2[0]-ASCIIconversion;
			if(isdigit(op1[0])!=0){
				registers[reg] = registers[reg]-atoi(op1);
			}
			else{
				registers[reg] = registers[reg]-registers[op1[0]-ASCIIconversion];
			}
		}
		else if(strcmp(command, "mul")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			int reg = op2[0]-ASCIIconversion;
			if(isdigit(op1[0])!=0){
				registers[reg] = registers[reg]*atoi(op1);
			}
			else{
				registers[reg] = registers[reg]*registers[op1[0]-ASCIIconversion];
			}
		}
		else if(strcmp(command, "div")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			int reg = op2[0]-ASCIIconversion;
			if(isdigit(op1[0])!=0){
				registers[reg] = atoi(op1)/registers[reg];
			}
			else{
				registers[reg] = registers[op1[0]-ASCIIconversion]/registers[reg];
			}
		}
		else if(strcmp(command, "jmp")==0){
			strcpy(op1, strtok(NULL, " "));
			j = atoi(op1)-1; 
		}
		else if(strcmp(command, "je")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			strcpy(op3, strtok(NULL, " "));
			int line = atoi(op1)-1;
			int x,y;
			if(isdigit(op2[0])!=0){
				x = atoi(op2);
			}
			else{
				x = registers[op2[0]-ASCIIconversion];
			}
			if(isdigit(op3[0])!=0){
				y = atoi(op3);
			}
			else{
				y = registers[op3[0]-ASCIIconversion];
			}
			if(x==y){
				j = line;
			}
		}
		else if(strcmp(command, "jne")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			strcpy(op3, strtok(NULL, " "));
			int line = atoi(op1)-1;
			int x,y;
			if(isdigit(op2[0])!=0){
				x = atoi(op2);
			}
			else{
				x = registers[op2[0]-ASCIIconversion];
			}
			if(isdigit(op3[0])!=0){
				y = atoi(op3);
			}
			else{
				y = registers[op3[0]-ASCIIconversion];
			}
			if(x!=y){
				j = line;
			}
		}
		else if(strcmp(command, "jg")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			strcpy(op3, strtok(NULL, " "));
			int line = atoi(op1)-1;
			int x,y;
			if(isdigit(op2[0])!=0){
				x = atoi(op2);
			}
			else{
				x = registers[op2[0]-ASCIIconversion];
			}
			if(isdigit(op3[0])!=0){
				y = atoi(op3);
			}
			else{
				y = registers[op3[0]-ASCIIconversion];
			}
			if(x>y){
				j = line;
			}
		}
		else if(strcmp(command, "jge")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			strcpy(op3, strtok(NULL, " "));
			int line = atoi(op1)-1;
			int x,y;
			if(isdigit(op2[0])!=0){
				x = atoi(op2);
			}
			else{
				x = registers[op2[0]-ASCIIconversion];
			}
			if(isdigit(op3[0])!=0){
				y = atoi(op3);
			}
			else{
				y = registers[op3[0]-ASCIIconversion];
			}
			if(x>=y){
				j = line;
			}
		}
		else if(strcmp(command, "jl")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			strcpy(op3, strtok(NULL, " "));
			int line = atoi(op1)-1;
			int x,y;
			if(isdigit(op2[0])!=0){
				x = atoi(op2);
			}
			else{
				x = registers[op2[0]-ASCIIconversion];
			}
			if(isdigit(op3[0])!=0){
				y = atoi(op3);
			}
			else{
				y = registers[op3[0]-ASCIIconversion];
			}
			if(x<y){
				j = line;
			}
		}
		else if(strcmp(command, "jle")==0){
			strcpy(op1, strtok(NULL, " "));
			strcpy(op2, strtok(NULL, " "));
			strcpy(op3, strtok(NULL, " "));
			int line = atoi(op1)-1;
			int x,y;
			if(isdigit(op2[0])!=0){
				x = atoi(op2);
			}
			else{
				x = registers[op2[0]-ASCIIconversion];
			}
			if(isdigit(op3[0])!=0){
				y = atoi(op3);
			}
			else{
				y = registers[op3[0]-ASCIIconversion];
			}
			//printf("\n%d %d\n", x, y);
			if(x<=y){
				j = line;
			}
		}
		else if(strcmp(command, "read")==0){
			strcpy(op1, strtok(NULL, " "));
			char input[6];
			fgets(input, 6, stdin);
			registers[op1[0]-ASCIIconversion] = atoi(input);
		}
		else if(strcmp(command, "print")==0){
			strcpy(op1, strtok(NULL, " "));
			if(isdigit(op1[0])!=0){
				printf("%d", atoi(op1));
			}
			else{
				printf("%d\n", registers[op1[0]-ASCIIconversion]);
			}
		}
		//printf("%d\n", j);	
	}

}
