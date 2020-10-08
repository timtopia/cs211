#include <stdio.h>
#include <stdlib.h>

int get(int number, int a);

int main(int argc, char* argv[])
{
	unsigned short num = atoi(argv[1]);
	
	for(int end = 0, beginning = 15; end < beginning; end++, beginning--){
		if(get(num, end) != get(num, beginning)){
			printf("Is-Palindrome\n");
			return 0;
		}
	}
	printf("Not-Palindrome\n");
}

int get(int number, int a){
	number = number >> a;
	if(number % 2 == 0){
		return 0;
	}
	else{
		return 1;
	}
}
