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
	//Making chart of binary
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
	
	//getting the names of the variables
	char inputnames[inputvariables][30];
	for(int i = 0; i < inputvariables; i++){
		fscanf(fp, "%s ", inputnames[i]);
	}	
	
	fscanf(fp, "\n");

	int outputvariables;
	fscanf(fp, "OUTPUTVAR %d ", &outputvariables);
	int outputchart[rows][outputvariables];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < outputvariables; j++){
			outputchart[i][j] = 0;
		}
	}

	char outputnames[outputvariables][30];
	for(int i = 0; i < outputvariables; i++){
		fscanf(fp, "%s ", outputnames[i]);
	}	
	
	fscanf(fp, "\n");
	
	char command[6];
	char input1[64];
	char input2[64];
	char input3[64];

	int tempvariables = 100;
	int tempchart[rows][tempvariables];

	char tempnames[tempvariables][30];
	for(int i = 0; i < tempvariables; i++){
		strcpy(tempnames[i], "");
	}
	
	/*
	for(int i = 0; i < inputvariables; i++){
		printf("%s ", inputnames[i]);
	}
	for(int i = 0; i < outputvariables; i++){
		printf("%s ", outputnames[i]);
	}
	printf("\n");	
	*/

	int forTheLoop = fscanf(fp, "%s%s%s", command, input1, input2);
	int tempfinal = 0;
	while(forTheLoop == 3){
		int input1copy[rows];
		int input2copy[rows];
		int outputcopy[rows];
		char output[10];
		if(strcmp("NOT", command) != 0){
			forTheLoop++;
			fscanf(fp,"%s",input3);
		}
		if(forTheLoop==3){
			for(int i = 0; i < inputvariables; i++){
				if(strcmp(input1, inputnames[i]) == 0){
					for(int j = 0; j < rows; j++){
						input1copy[j] = inputchart[j][i];
					}
				}
			}
			for(int i = 0; i < tempfinal; i++){
				if(strcmp(input1, tempnames[i]) == 0){
					for(int j = 0; j < rows; j++){
						input1copy[j] = tempchart[j][i];
					}
				}
			}
			strcpy(output, input2);
		}
		else{
			for(int i = 0; i < inputvariables; i++){
				if(strcmp(input1, inputnames[i]) == 0){
					for(int j = 0; j < rows; j++){
						input1copy[j] = inputchart[j][i];
					}
				}
			}
			for(int i = 0; i < tempfinal; i++){
				if(strcmp(input1, tempnames[i]) == 0){
					for(int j = 0; j < rows; j++){
						input1copy[j] = tempchart[j][i];
					}
				}
			}
			for(int i = 0; i < inputvariables; i++){
				if(strcmp(input2, inputnames[i]) == 0){
					for(int j = 0; j < rows; j++){
						input2copy[j] = inputchart[j][i];
					}
				}
			}
			for(int i = 0; i < tempfinal; i++){
				if(strcmp(input2, tempnames[i]) == 0){
					for(int j = 0; j < rows; j++){
						input2copy[j] = tempchart[j][i];
					}
				}
			}
			strcpy(output, input3);
		}
		//for(int i = 0; i<rows; i++){
		//	printf("%d %d\n", input1copy[i], input2copy[i]);
		//}

		if(strcmp(command, "NOT") == 0){
			for(int i = 0; i < rows; i++){
				if(input1copy[i] == 0){
					outputcopy[i] = 1;
				}
				else{
					outputcopy[i] = 0;
				}
			}
		}
		else if(strcmp(command, "AND") == 0){
			for(int i = 0; i < rows; i++){
				outputcopy[i] = input1copy[i]&input2copy[i];
			}
		}
		else if(strcmp(command, "OR") == 0){
			for(int i = 0; i < rows; i++){
				outputcopy[i] = input1copy[i]|input2copy[i];
			}
		}
		else if(strcmp(command, "NAND") == 0){
			for(int i = 0; i < rows; i++){
				outputcopy[i] = input1copy[i]&input2copy[i];
			}
			for(int i = 0; i < rows; i++){
				if(outputcopy[i] == 0){
					outputcopy[i] = 1;
				}
				else{
					outputcopy[i] = 0;
				}
			}		
		}
		else if(strcmp(command, "NOR") == 0){
			for(int i = 0; i < rows; i++){
				outputcopy[i] = input1copy[i]|input2copy[i];
			}
			for(int i = 0; i < rows; i++){
				if(outputcopy[i] == 0){
					outputcopy[i] = 1;
				}
				else{
					outputcopy[i] = 0;
				}
			}
		}
		else if(strcmp(command, "XOR") == 0){
			for(int i = 0; i < rows; i++){
				outputcopy[i] = input1copy[i]^input2copy[i];
			}
		}
		
		//for(int i = 0; i < rows; i++){
		//	printf("%d\n", outputcopy[i]);
		//}

		int outputCopied = 1;
		for(int i = 0; i < outputvariables; i++){
			if(strcmp(output, outputnames[i]) == 0){
				for(int j = 0; j < rows; j++){	
					outputchart[j][i] = outputcopy[j];
				}
				outputCopied = 0;
			}
		}
		for(int i = 0; i < tempfinal; i++){
			if(strcmp(output, tempnames[i]) == 0){
				for(int j = 0; j < rows; j++){
					tempchart[j][i] = outputcopy[j];
				}
				outputCopied = 0;
			}
		} 
		if(outputCopied){
			strcpy(tempnames[tempfinal], output);
			for(int i = 0; i < rows; i++){
				tempchart[i][tempfinal] = outputcopy[i];
			}
			tempfinal++;
			
		}
		//printf("%sLOOP%d\n",command, forTheLoop);
		forTheLoop = fscanf(fp, "%s%s%s\n", command, input1, input2); 
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
