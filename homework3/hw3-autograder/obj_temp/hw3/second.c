#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned short num = atoi(argv[1]);

	int last = 0;
	int ones = 0;
	int pairs = 0;

	while(num != 0){
		if (num % 2 == 0){
			last = 0;
		}
		else{
			ones++;
			if(last == 0){
				last = 1;
			}
			else {
				last = 0;
				pairs++;
			}

		}
		num = num >> 1;
	}
	
	if(ones % 2 == 0){
		printf("Even-Parity\t%hu\n", pairs);
	}
	else{
		printf("Odd-Parity\t%hu\n", pairs);
	}
}
