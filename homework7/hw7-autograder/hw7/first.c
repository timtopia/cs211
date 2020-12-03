#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
	FILE* fp = fopen(argv[1], "r");
	int variables;
	fscanf(fp, "INPUTVAR %d ", &variables);
	int rows = pow(2, variables);
	int chart[rows][variables + 1];

}
