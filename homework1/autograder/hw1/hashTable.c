#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

int main(int argc, char* argv[]){
	FILE* fp = fopen(argv[1], "r");
	int data;
	int collisions = 0, searches = 0;
	char action;
	Node* hashmap[10000];
	for(int i = 0; i<10000; i++)
		hashmap[i] = NULL;
	while(fscanf(fp, "%c\t%d\n", &action, &data)==2){
		//INSERT
		if((action == 'i')){
			Node* temp = (Node*)malloc(sizeof(Node));
			temp->data = data;
			temp->next = NULL;
			int key = data%10000;
			if(key < 0)
				key = key + 10000;
			if(hashmap[key] == NULL){
				hashmap[key] = temp;
			}
			else{
				collisions++;
				Node* ptr = hashmap[key];
				Node* follower = NULL;
				while(ptr!=NULL){
					follower = ptr;
					ptr = ptr->next;
				}
				follower->next = temp;
			}
		}
		//SEARCH
		else if((action == 's')){
			int key = data%10000;
			if(key<0)
				key = key + 10000;
			if(hashmap[key] == NULL){}
			else{
				Node* ptr = hashmap[key];
				while(ptr!=NULL){
					if(ptr->data == data){
						searches++;
						break;
					}
					ptr = ptr->next;
				}
			}
		}
	}
	//CLEAN
	for(int i = 0; i < 10000; i++){
		if(hashmap[i] == NULL)
			continue;
		else{
			Node* ptr = hashmap[i];
			Node* tmp = NULL;
			while(ptr!=NULL){
				tmp = ptr;
				ptr = ptr->next;
				free(tmp);
			}
		}
	}
	//PRINTS
	//collisions
	printf("%d\n", collisions);
	//searches
	printf("%d\n", searches);
	fclose(fp);
}
