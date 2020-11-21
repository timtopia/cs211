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
	if(argc != 6){
		printf("error\n");
		return 1;
	}
	if(isdigit(argv[1][0]) == 0){
		printf("error\n");
		return 1;
	}
	if(power_of_2(atoi(argv[1])) == false){
		printf("error\n");
		return 1;
	}
	
}

int power_of_2(int n)
{
	if(n <= 0){
		return false;
	}
	return (ceil(log2(n)) == floor(log2(n)));
}
