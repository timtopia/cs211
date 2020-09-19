#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	int i, count;

	count = atoi(argv[1]);
	for (i = 0; i < count; i++){
		printf("Hello %d\n", i);
	}
}
