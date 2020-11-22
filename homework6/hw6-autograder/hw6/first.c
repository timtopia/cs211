#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

int power_of_2(int n);

int associativityComp(char* str);

int main(int argc, char* argv[])
{
	int chachesize,lineperset;
	
	//check if argument count is right
	if(argc != 6){
		printf("error\n");
		return 1;
	}

	//check if argument 1 is right(number, power of 2)
	if(isdigit(argv[1][0]) == 0){
		printf("error\n");
		return 1;
	}
	if(power_of_2(atoi(argv[1])) == false){
		printf("error\n");
		return 1;
	}
	
	//check if argument 2 is right("direct" or "assoc" or "assoc:(power of 2)")
	if(strcmp(argv[2], "direct") != 0 && strcmp(argv[2], "assoc") != 0){
		char temp[strlen(argv[2])];
		strcpy(temp, argv[2]);
		if(strlen(temp) < 5){
			printf("error\n");
			return 1;
		}
		else{
			char * wow;
			wow = strtok(temp, ":");
			if(strcmp(wow, "assoc")!=0){
				printf("error\n");
				return 1;
			}
			char * yeeb;
			yeeb = (strtok(NULL, " "));
			if(yeeb == NULL){
				printf("error\n");
				return 1;
			}
			else{
				if(isdigit(yeeb[0])==0){
					printf("error\n");
					return 1;
				}
				else{
					if(power_of_2(atoi(yeeb))==true){
					}
					else{
						printf("error\n");
						return 1;
					}
				}
			}
		}
	}
	
	//check if argument 3 is right("lru" or "fifo")
	if(strcmp(argv[3], "lru") != 0 && strcmp(argv[3], "fifo") != 0){
		printf("error\n");
		return 1;
	}

	//check if argument 4 is right (power of 2 integer)
	if(power_of_2(atoi(argv[4])) == false || isdigit(argv[4][0] == 0)){
		printf("error\n");
		return 1;
	}

	printf("CHECKS CLEARNED\n");

	
}

int power_of_2(int n)
{
	if(n <= 0){
		return false;
	}
	return (ceil(log2(n)) == floor(log2(n)));
}

int associativityComp(char* str){
	if(strcmp(str, "direct") == 0){
		return true;
	}
	else if(strcmp(str, "assoc") == 0){
		return true;
	}
	else if(power_of_2(atoi(str+6))){
		return true;
	}
	return false;
}
