/* 
 * 
 * This code calculates the house price of a house by learing from
 * training data. It uses pseudo inverse of a given matrix to find the 
 * weight of different features.
 * 
 * Predicted Price : Y = W0 + W1*x1 + W2*X2 + W3*X3 + W4*X4
 * Weight Matrix : W = pseudoInv(X)*Y
 * pseudoInv(X) = inverse(transpose(X)*X) * transpose(X)  
 * 
 * weight(w) = pseudoInv(X) * Y
 * 			where	X = Input data matrix
 * 					Y = Target vector
 * 
 */
 
#include<stdio.h>
#include<stdlib.h>

// all methods declarations
double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2);
double** transposeMatrix(double** mat, int row, int col);
double** inverseMatrix(double **matA, int dimension);
void printMatrix(double **matrix, int row, int col);

// main method starts here
int main(int argc, char** argv){
	
	FILE* fp = fopen(argv[1], "r");

	int rows;
	int cols;

	fscanf(fp, "%d\n", &cols);
	cols++;
	fscanf(fp, "%d\n", &rows);
	
	double** chart = malloc(rows*sizeof(double*));
	for(int i = 0; i < rows; i++){
		chart[i] = malloc(cols*sizeof(double));
	}

	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
			fscanf(fp, "%le, ", &chart[r][c]);
		}
		fscanf(fp, "\n");	
	}

	return 0;
}

double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2)
{
	double** result=malloc(r1*sizeof(double*)); 
    
	// your code goes here
   	for (int i = 0; i<r1; i++){
		result[i] = malloc(c2*sizeof(double));
	}

	for (int i = 0; i < r1; i++){
		for (int j = 0; j < c2; j++){
			int temp = 0;
			for(int k = 0; k < c1; k++){
				for(int l = 0; l < r2; l++){
					temp += matA[i][k] * matA[l][j];
				}
			}
			result[i][j] = temp;
		}
	}


	return result;
}


double** transposeMatrix(double** mat, int row, int col)
{
  	
	double** matTran=malloc(col*sizeof(double*)); 
    
	// your code goes here
	
	for (int i = 0; i<col; i++){
		matTran[i] = malloc(row*sizeof(double));
	}

	for (int i = 0; i<col; i++){
		for(int j = 0; j<row; j++){
			matTran[i][j] = mat[j][i];
		}
	}

	return matTran;        
}


double** inverseMatrix(double **matA, int dimension)
{

	double** matI=malloc(dimension*sizeof(double*)); 

	// your code goes here
	
	

    
	return matI;
}

void printMatrix(double **matrix, int row, int col)
	for(int r = 0; r < rows; r++){
		for(int c = 0; c < cols; c++){
		       	printf("%le ", chart[r][c];
		}
		printf("\n");
        }

}
