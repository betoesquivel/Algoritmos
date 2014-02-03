/*
 * =====================================================================================
 *
 *       Filename:  triominos.cpp
 *
 *    Description:  Problem from Algorythms class. Given a nxn (where n is power of 2
 *    sized) matrix) and a cell (r,c) in matrix. Paint the whole matrix writing only
 *    triominios (L shapes using 3 cells).
 *
 *        Version:  1.0
 *        Created:  02/03/2014 16:50:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jose Alberto Esquivel Patino (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int *mat; 	//pointer tu square matrix
int triomineCounter = 1;      //counts the triomines painted in matrix to print output.
int n;      //size of squared matrix (power of 2)
int firstCellRow, int firstCellColumn;//coordinates for initial cell 

/* Prints the matrix mat */
void printMatrix(){
	for (int r = 0; r < n; r++) {
		for (c = 0; c < n; c++) {
			cout<<mat[r][c]<<' ';
		}
		cout<<endl;
	}
}

/* Returns true if the cell at mat[row,column] is still in range to paint 
 * its corresponding triomine */
bool canPaint(int row, int column){
	if(row >= (n/2 - 1) && row <= (n/2) &&
	   column >= (n/2 - 1) && column <= (n/2)){
		return true; 
	}else if (row >= 0 && row <= (n/2 - 1) &&
	          column >= 0 && column <= (n/2 - 1)){
		return true; 
	}else if (row >= (n/2) && row <= (n - 1) &&
	          column >= (n/2) && column <= (n - 1)){
		return true; 
	}else{
		return false; 
	}

}

/* Paints triomines recursively in matrix given an initial cell
 * in a 2x2 submatrix of the matrix and its position in that submatrix
 * until the whole matrix is filled. r = row; c = column; q = quadrant; */
void paintTriomine(int r, int c, int q){
	mat[r][c] = triomineCounter;
	if(canPaint(r, c)){
		switch(q){
			case 1:
			case 2: 
			case 3:
			case 4:
		}
		triomineCounter++;
	}	
}

/* Returns the quadrant of cell in a size by size matrix */
int findQuadrant(int row, int column, int size){
	int q = -1;
	if (row < (size / 2)) {
		//cell is in quadrants either 1 or 2
		if(column < (size/2)){
			//cell is in quadrant 2
			q = 2; 
		}else{
			//cell is in quadrant 1
			q = 1; 
		}
	}else{
		//cell is in quadrants either 1 or 2
		if(column < (size/2)){
			//cell is in quadrant 2
			q = 3; 
		}else{
			//cell is in quadrant 1
			q = 4; 
		}
	}
	return q; 
}

/* searches recursively for the size 2 matrix in which the firstCell is located and
 * a triomine can be painted. After it finds it, it calls paintTriomine() */
void paintMatrix(int row, int column, int quadrant, int size){
	int quadrant;
	if(size > 2){
		quadrant = findQuadrant(row, column, size);
		switch (quadrant){
			case 1: column += size / 2; 
				break;
			case 2: 
				break;
			case 3: row += size / 2; 
				break;
			case 4: column += size / 2; 
				row += size / 2;
				break;
		}
		paintMatrix(row, column, quadrant, size / 2); 
	}else {
		//I found the size 2 initial matrix
		paintTriomine(int firstCellRow, int firstCellColumn, int quadrant);
	}
}

int main(int argc, const char *argv[])
{
	
	return 0;
}
