#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
} Node;

int main(int argc, char* argv[]){
	Node* head = NULL;
	FILE* fp = fopen(argv[1], "r");
	//printf("File FOUND\n");
	if(fp == NULL){
		fclose(fp);
		printf("error\n");
		return 0;
	}
	char action;
	int data, count = 0;
	while(fscanf(fp, "%c\t%d\n", &action, &data) == 2){
		
		//insert
		if(action == 'i'){
			//printf("INSERT\n");
			count++;
			Node* temp = (Node*)malloc(sizeof(Node));
			temp->data = data;
			temp->next = NULL;
                	if(head == NULL){
                        	head = temp;
                	}
			else{
				Node* follower = NULL;
				Node* pointer = head;
				while(&pointer->data != NULL){
					if(temp->data <= pointer->data){
						if(follower == NULL){
							temp->next = head;
							head = temp;
							break;
						}
						else{
							follower->next = temp;
							temp->next = pointer;
							break;	
						}
					}
					follower = pointer;
					pointer = pointer->next;
				}
				if(follower!= NULL)
					follower->next = temp;
			
			}
		}

		//delete
		if(action == 'd'){
			//printf("DELETE\n");
			Node* pointer = head;
			//printf("%d\n", pointer->data);
			Node* follower = NULL;
			while(pointer!= NULL){
				if(pointer->data == data){
					Node* tmp;
					if(follower == NULL){
						count--;
						tmp = head;
						head = pointer->next;
						free(tmp);
						break;
					}
					else{
						count--;
						tmp = follower->next;
						follower->next = pointer->next;
						free(tmp);
						break;
					}
				}
				follower = pointer;
				pointer = pointer->next;
			}
		}
	}
	printf("%d\n", count);
	if(head!= NULL){
		Node* ptr = head;
		int last = head->data-1;
		while(ptr!=NULL){
			if(ptr->data != last){
				printf("%d\t", ptr->data);
				last = ptr->data;
			}
			head = ptr->next;
			free(ptr);
			ptr = head;
		}	
	}	
	printf("\n");
	fclose(fp);
}
