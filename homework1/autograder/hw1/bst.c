#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int number;
	struct Node* left;
	struct Node* right;
}Node;

void printInorder(Node* node){
	if(node == NULL)
		return;

	printInorder(node->left);

	printf("%d\t", node->number);

	printInorder(node->right);
	
	free(node);
}

int main(int argc, char* argv[]){
	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL){
		fclose(fp);
		printf("error\n");
		return 0;
	}
	int data;
	Node* head = NULL;
	while(fscanf(fp, "i\t%d\n", &data) == 1){
		Node* temp = (Node*)malloc(sizeof(Node));
		temp->number = data;
		temp->right = NULL;
		temp->left = NULL;
		if(head == NULL){
			head = temp;
			continue;
		}
		else{
		
			Node* ptr = head;
			Node* follower = NULL;
			//find place
			while(ptr!= NULL){
				follower = ptr;
				if(ptr->number > temp->number)
					ptr = ptr->left;
				else if(ptr->number < temp->number)
					ptr = ptr->right;
				else
					break;
			}
			if(ptr != NULL){
				free(temp);
				continue;
			}
			else{
				if(temp->number> follower->number)
					follower->right = temp;
				else
					follower->left = temp;
			}	
		}
	}

	//in-order traversal and freeing
	printInorder(head);
	
	printf("\n");
	fclose(fp);
}
