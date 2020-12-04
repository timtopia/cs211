#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE* fp = fopen(argv[1], "r");
	int inputvariables;
	fscanf(fp, "INPUTVAR %d ", &inputvariables);
	int rows = pow(2, inputvariables);
	int inputchart[rows][inputvariables];
	for(int i = 0; i < rows; i++){
		int number = i;
		for(int j = inputvariables; j > 0; j--){
			int temp = 1;
			if((temp&number) == 1){
				inputchart[i][j-1] = 1;
			}
			else{
				inputchart[i][j-1] = 0;
			}
			number = number>>1;
		}
	}
	
	char* inputnames[inputvariables];
	for(int i = 0; i < inputvariables; i++){
		fscanf(fp, "%s ", inputnames[i]);
	}	
	
	fscanf(fp, "\n");

	int outputvariables;
	fscanf(fp, "OUTPUTVAR %d ", &outputvariables);
	int outputchart[rows][outputvariables];

	char* outputnames[outputvariables];
	for(int i = 0; i < outputvariables; i++){
		fscanf(fp, "%s ", outputnames[i]);
	}	
	
	fscanf(fp, "\n");

	char command[5];
	char input1[64];
	char input2[64];
	char input3[64];

	int tempvariables = 100;
	int tempchart[rows][tempvariables];

	char* tempnames[tempvariables];
	for(int i = 0; i < tempvariables; i++){
		strcpy(tempnames[i], "");
	}
	int forTheLoop = fscanf(fp, "%s %s %s %s\n", command, input1, input2, input3);
	while(forTheLoop >= 3){
		int* in1;
		int* in2;
		int* out;
		//special action for the NOT
		if(forTheLoop == 3){
			for(int i = 0; i < inputvariables; i++){
			}		
		}
		else{
		}


		
		if(strcmp(command, "NOT") == 1){
		}
		else if(strcmp(command, "AND") == 1){
		}
		else if(strcmp(command, "OR") == 1){
		}
		else if(strcmp(command, "NAND") == 1){
		}
		else if(strcmp(command, "NOR") == 1){
		}
		else if(strcmp(command, "XOR") == 1){
		}
		forTheLoop = fscanf(fp, "%s %s %s %s\n", command, input1, input2, input3); 
	}




	for(int i = 0; i < rows; i++){
		for(int j = 0; j < inputvariables; j++){
			printf("%d ",inputchart[i][j]);
		}
		for(int j = 0; j < outputvariables; j++){
			printf("%d ",outputchart[i][j]);
		}
		printf("\n");
	}
}
