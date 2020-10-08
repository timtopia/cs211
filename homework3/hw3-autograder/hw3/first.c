#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[])
{
	FILE* fp = fopen(argv[1], "r");

	unsigned short Number;

	fscanf(fp, "%hu\n", &Number);

	int a, b;

	char word[5];

	while(fscanf(fp, "%s\t%d\t%d\n", &word[0], &a, &b) == 3){
		if(strcmp(word, "comp") == 0){
			int x = 1;
			x = x << a;
			int or = Number|x;
			if(or == Number){
				Number = Number - x;
				printf("%hu\n", Number);	
			}
			else{
				printf("%hu\n", or);
				Number = or;
			}	
		}
		else if(strcmp(word, "get") == 0){
			int temp = Number;
			Number = Number >> a;
			if(Number % 2 == 0){
				printf("0\n");
			}
			else if(Number % 2 == 1){
				printf("1\n");
			}
			Number = temp;
		}
		else if(strcmp(word, "set") == 0){
			if(b == 0){
				int x = 1;
				x = x << (a-1);
				if((Number|x) == Number){
					Number = Number - x;
				}
				printf("%hu\n", Number);
			}
			else{
				int x = 1;
				x = x << a;
				if((Number|x) == Number){
					printf("%hu\n", Number);
				}
				else{
					printf("%hu\n", Number + x);
				}
			}
		}
		else{
		
		}
	}
}
