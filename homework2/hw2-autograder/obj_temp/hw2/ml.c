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

#define PRICE_COUNT 1; 

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
	
	//For the Cols of Ones;
	Xcols++;

	double** mat = malloc(Xrows*sizeof(double*));
	for(int i = 0; i < Xrows; i++){
		mat[i] = malloc(Xcols*sizeof(double));
	}

	double** Y = malloc(Xrows*sizeof(double*));
	for(int i = 0; i < Xrows; i++){
		Y[i] = malloc(sizeof(double));
	}
	int Yrows = Xrows;
	int Ycols = PRICE_COUNT;

	for(int r = 0; r < Xrows; r++){
		for(int c = 0; c < Xcols + 1; c++){
			if(c == 0){
				mat[r][0] = 1;
			}
			else if(c<Xcols){
				fscanf(fp, "%lf, ", &mat[r][c]);
			}
			else{
				fscanf(fp, "%lf, ", &Y[r][0]);
			}
		}
		fscanf(fp, "\n");	
	}

	//printMatrix(mat, Xrows, Xcols);

	fclose(fp);

	double** matTrans = transposeMatrix(mat, Xrows, Xcols);
	
	int XTrows = Xcols;
	int XTcols = Xrows;	

	double** squareMat = multiplyMatrix(matTrans, mat, XTrows, XTcols, Xrows, Xcols);
	int Sqdim = XTrows;
	
	double** inverseMat = inverseMatrix(squareMat, Sqdim);
	if(inverseMat == NULL){
		return 1;
	}


	double** temp = multiplyMatrix(inverseMat, matTrans, Sqdim, Sqdim, XTrows, XTcols);

	double** W = multiplyMatrix(temp, Y, Sqdim, Sqdim, Yrows, Ycols); 
	int Wrows = XTrows;
	int Wcols = PRICE_COUNT;

	
	//printMatrix(W, Wrows, Wcols);	

	FILE* ft = fopen(argv[2], "r");

	int TestRows;
	int TestCols = Wrows;
	
	fscanf(ft, "%d\n", &TestRows);	

	double** Test = malloc(TestRows*sizeof(double*));
	for(int i = 0; i < TestRows; i++){
		Test[i] = malloc(TestCols*sizeof(double));
	}
	
	//printMatrix(Test, TestRows, TestCols);	

	for(int r = 0; r < TestRows; r++){
	       for(int c = 0; c < TestCols; c++){
		       if(c == 0){
			       Test[r][0] = 1;
		       }
		       else{
			       fscanf(ft, "%lf, " , &Test[r][c]);
		       }			       
		}
		fscanf(ft, "\n");
	}
	fclose(ft);
	
	//printMatrix(Test, TestRows, TestCols);

	double** Answer = multiplyMatrix(Test, W, TestRows, TestCols, Wrows, Wcols);

	
	for(int r = 0; r < TestRows; r++){
		for(int c = 0; c < Wcols; c++){
			printf("%0.0lf\n", Answer[r][c]);
		}
	}	


	//printMatrix(mat, Xrows, Xcols);
	//printMatrix(matTrans, XTrows, XTcols);
	//printMatrix(squareMat, Sqdim, Sqdim);
	//printMatrix(inverseMat, Sqdim, Sqdim);
	//printMatrix(W, Wrows, Wcols);
	//printMatrix(Y, Yrows, Ycols);
	
	//printMatrix(Test, TestRows, TestCols);

	//printMatrix(Answer, TestRows, Wcols);


	clearMatrix(matTrans, XTrows);
	clearMatrix(mat, Xrows);
	clearMatrix(Y, Yrows);
	clearMatrix(squareMat, Sqdim);
	clearMatrix(inverseMat, Sqdim);
	clearMatrix(temp, Sqdim);
	clearMatrix(W, Wrows);
	clearMatrix(Test, TestRows);
	clearMatrix(Answer, TestRows);
	return 0;
}

double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2)
{
	double** result=malloc(r1*sizeof(double*)); 
    
	// your code goes here
   	for (int i = 0; i<r1; i++){
		result[i] = malloc(c2*sizeof(double));
	}
	
	for(int i = 0; i < r1; i++){
		for(int j = 0; j < c2; j++){
			result[i][j] = 0;
		}
	}
	
	for (int i = 0; i < r1; i++){
		for (int j = 0; j < c2; j++){
			for(int k = 0; k <r2; k++){
				result[i][j] += matA[i][k] * matB[k][j];
			}
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

	for(int i = 0; i < dimension; i++){
		matI[i] = malloc(2*dimension*sizeof(double));
	}

	

	for(int i = 0; i < dimension; i++){
		for(int j = 0; j< dimension; j++){
			matI[i][j] = matA[i][j];
			if(i == j){
				matI[i][j+dimension] = 1;	
			}
			else{
				matI[i][j+dimension] = 0;
			}
		}
	}

	//printMatrix(matI, dimension, dimension*2);

	for(int i = 0; i < dimension; i++){
		float makeToOne = matI[i][i];
		
		for(int j = 0; j< dimension * 2; j++){
			matI[i][j] = matI[i][j]/makeToOne;
		}

		//printMatrix(matI, dimension, dimension*2);

		for(int r = i+1; r < dimension; r++){
			double ratio = matI[r][i]/matI[i][i];
			for(int c = 0; c < dimension*2; c++){
				matI[r][c] = matI[r][c] - ratio*matI[i][c];
			}
		}

		//printMatrix(matI, dimension, dimension*2);
	}

	for(int i = dimension-1; i > -1; i--){
		for(int j = i-1; j > -1; j--){
			double ratio = matI[j][i]/matI[i][i];
			//printf("%f\n", ratio);
			for(int c = 0; c<dimension*2; c++){
				matI[j][c] = matI[j][c] - ratio * matI[i][c];
			}
		}
		//printMatrix(matI, dimension, dimension*2);

	}

	double** result = malloc(dimension*sizeof(double*));
	for(int i = 0; i < dimension; i++){
		result[i] = malloc(dimension*sizeof(double));
	}
	
	for(int i = 0; i < dimension; i++){
		for(int j = 0;  j < dimension; j++){
			result[i][j] = matI[i][j+dimension];
		}
	}	
    	
	clearMatrix(matI, dimension);

	return result;
}

void printMatrix(double **matrix, int row, int col){
	printf("\n");
	for(int r = 0; r < row; r++){
		for(int c = 0; c < col; c++){
		       	printf("%f ", matrix[r][c]);
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

