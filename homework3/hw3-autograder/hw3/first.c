#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, char* argv[])
{
	FILE* fp = fopen(argv[1], "r");

	unsigned short Number;

	fscanf(fp, "%hu\n", &Number);

	int a, b;

	char[5] word;

	while(fscanf(fp, "%s\t%d\t%d\m", &word, &a, &b) == 3){
		if(strcmp(word, "comp") == 0){
			int position = ;

		}
		else if(strcmp(word, "get") == 0){
			int position = 2^a;
		}
		else if(strcmp(word, "set") == 0){
		}
		else{
		}
	}

}
