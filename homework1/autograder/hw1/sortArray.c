#include <stdio.h>

int main(int argc, char* argv[]) {
	FILE* fp = fopen(argv[1], "r");
	int size;
	if(fp==NULL)
		return 0;
	fscanf(fp, "%d", &size);

	int unsorted[size];

	//scan file
	for (int i = 0; i < size; i++){
		int value;
		fscanf(fp, "%d ", &value);
		unsorted[i] = value;
	}
	fclose(fp);


	//segregateodds and evens
	int left = 0, right = size-1;
	while(left < right){
		while(unsorted[left]%2 == 0 && left < right)
			left++;

		while ((unsorted[right]%2 ==1||unsorted[right]%2 == -1) && left < right)
			right--;

		if (left < right){
			int temp = unsorted[left];
			unsorted[left] = unsorted[right];
			unsorted[right] = temp;
			left++;
			right--;
		}
	}

	//find index of first odd
	int firstOdd = -1;
	for(int i = 0; i < size; i++){
		if(unsorted[i]%2==1||unsorted[i]%2 == -1){
			firstOdd = i;
			break;
		}
	}


	//fix
	if(firstOdd != -1){
		//bubble sort evens
		for (int i = 0; i < firstOdd; i++){
			for (int j = i+1; j < firstOdd; j++){
				if(unsorted[j]<unsorted[i]){
					int temp = unsorted[j];
					unsorted[j] = unsorted[i];
					unsorted[i] = temp;
				}
			}
		}
		//reverse bubble odds
		for (int i = size-1; i > firstOdd-1; i--){
			for (int j = i-1; j > firstOdd-1; j--){
				if(unsorted[j]<unsorted[i]){
					int temp = unsorted[j];
					unsorted[j] = unsorted[i];
					unsorted[i] = temp;
				}
			}
		}
	}
	else{
		for (int i = 0; i < size; i++){
			for (int j = i+1; j < size; j++){
				if(unsorted[j]<unsorted[i]){
					int temp = unsorted[j];
					unsorted[j] = unsorted[i];
					unsorted[i] = temp;
				}
			}
		}
	}




	for (int i = 0; i<size; i++){
		printf("%d\t", unsorted[i]);
	}
	printf("\n");
}
