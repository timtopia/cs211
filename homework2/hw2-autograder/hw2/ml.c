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

#define PRICE_COUNT 1

// all methods declarations
double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2);
double** transposeMatrix(double** mat, int row, int col);
double** inverseMatrix(double **matA, int dimension);
void printMatrix(double **matrix, int row, int col);
void clearMatrix(double **matrix, int row);

// main method starts here
int main(int argc, char** argv){
	
	FILE* fp = fopen(argv[1], "r");

	int Xrows;
	int Xcols;

	fscanf(fp, "%d\n", &Xcols);
	fscanf(fp, "%d\n", &Xrows);
	
	double** mat = malloc(Xrows*sizeof(double*));
	for(int i = 0; i < Xrows; i++){
		mat[i] = malloc(Xcols*sizeof(double));
	}

	double** Y = malloc(Xrows*sizeof(double*));
	for(int i = 0; i < Xrows; i++){
		Y[i] = malloc(sizeof(double));
	}
	int Yrows = Xrows;
	//int Ycols = PRICE_COUNT;

	for(int r = 0; r < Xrows; r++){
		for(int c = 0; c < Xcols + 1; c++){
			if(c<Xcols){
				fscanf(fp, "%le, ", &mat[r][c]);
			}
			else{
				fscanf(fp, "%le, ", &Y[r][0]);
			}
		}
		fscanf(fp, "\n");	
	}

	double** matTrans = transposeMatrix(mat, Xrows, Xcols);
	
	int XTrows = Xcols;
	int XTcols = Xrows;	

	printMatrix(mat, Xrows, Xcols);
	printMatrix(matTrans, XTrows, XTcols);

	clearMatrix(matTrans, XTrows);
	clearMatrix(mat, Xrows);
	clearMatrix(Y, Yrows);
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

void printMatrix(double **matrix, int row, int col){
	printf("\n");
	for(int r = 0; r < row; r++){
		for(int c = 0; c < col; c++){
		       	printf("%le ", matrix[r][c]);
		}
		printf("\n");
        }
	printf("\n");
}

void clearMatrix(double **matrix, int row){
	for(int r = 0; r < row; r++){
		free(matrix[r]);
	}
	free(matrix);
}
