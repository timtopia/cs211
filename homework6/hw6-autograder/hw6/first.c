#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
 
typedef struct Cacheline{
	int valid;
	int replacement;
	long tag;
} Cacheline;


int power_of_2(int n);

int associativityComp(char* str);

int checkParams(int argc, char* argv[]);

int main(int argc, char* argv[])
{
	int params = checkParams(argc, argv);
	if(params == 1){
		return 0;
	}
	//set up params

	
	FILE* fp = fopen(argv[5], "r");
	
	unsigned long useless;
	char command;
	unsigned long memory;

	int size = atoi(argv[1]);
	int blocksize = atoi(argv[4]);
	int assoc = 0;
	if(strcmp(argv[2], "direct") == 0){
		assoc = 1;
	}
	else if(strcmp(argv[2], "assoc") == 0){
		assoc = size/blocksize;
	}
	else{
		char* temp;
		temp = strtok(argv[2],":");
		temp = strtok(NULL, ":");
		assoc = atoi(temp);
	}

	char replacement[5];
	strcpy(replacement, argv[3]);

	int numlines = size/blocksize;
	int setnumber = numlines/assoc;
	

	int blockbits = log2(blocksize);
	int setbits = log2(setnumber);
	int setcomp = pow(2,setbits)-1;
	//CREATION OF THE CACHE
	
	Cacheline* cache[setnumber][assoc];
	for(int i = 0; i<setnumber; i++){
		for(int j = 0; j<assoc; j++){
			cache[i][j] = malloc(sizeof(Cacheline));
			cache[i][j]->valid = 0;
		}
	}

	//Findings
	int MemoryReads = 0, MemoryWrites = 0, CacheHits = 0, CacheMisses = 0;
	//loop through
	int count = 0;
	while(fscanf(fp, "%lx: %c %lx", &useless, &command, &memory) == 3){
		count++;
		int tempcount = count;
		memory = memory>>blockbits;
		int set = memory & setcomp;
		memory = memory>>setbits;
		int test = 0, test2 = test;
		for(int i = 0; i < assoc; i++){
			if(cache[set][i]->tag == memory){
				if(strcmp(replacement, "lru") == 0){
					cache[set][i]->replacement = count;
				}
				test++;
				CacheHits++;
				if(command == 'W'){
					MemoryWrites++;
				}
				break;
			}
		}
		if(test != test2){continue;}
		for(int i = 0; i < assoc; i++){
			if(cache[set][i]->valid == 0){
				cache[set][i]->valid = 1;
				CacheMisses++;
				MemoryReads++;
				if(command == 'W'){
					MemoryWrites++;
				}
				tempcount++;
				cache[set][i]->replacement = count;
				cache[set][i]->tag = memory;
				break;
			}
		}
		if(count!=tempcount){continue;}
		Cacheline* temporary;
		CacheMisses++;
		int linepos;
		temporary = cache[set][0];
		linepos = 0;
		MemoryReads++;
		for(int i = 1; i < assoc; i++){
			if(cache[set][i]->replacement < temporary->replacement){
				temporary = cache[set][i];
				linepos = i;
			}		
		}
		if(command == 'W'){
			MemoryWrites++;
		}
		Cacheline* newLine = malloc(sizeof(Cacheline));
		newLine->valid = 1;
		newLine->replacement = count;
		newLine->tag = memory;
		free(cache[set][linepos]);
		cache[set][linepos] = newLine;
	}	


	//Free cache sim
	for(int i = 0; i<setnumber; i++){
		for(int j = 0; j<assoc; j++){
				free(cache[i][j]);
		}
	}
	//Final Print
	printf("Memory reads: %d\nMemory writes: %d\nCache hits: %d\nCache misses: %d\n", MemoryReads, MemoryWrites, CacheHits, CacheMisses);
}

int checkParams(int argc, char *argv[]){
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
	
	//check if argument 5 is right (file)
	FILE* fp = fopen(argv[5], "r");
	if(fp == NULL){
		printf("error\n");
		return 1;
	}	
	return 0;
	//printf("CHECKS CLEARNED\n");

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
