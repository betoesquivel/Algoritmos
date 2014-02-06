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
const int MAXSIZE = 32; 

bool debug = true;

int mat[MAXSIZE][MAXSIZE]; 	//pointer tu square matrix
int visited[MAXSIZE][MAXSIZE]; 	//pointer tu square matrix
int triomineCounter = 1;      //counts the triomines painted in matrix to print output.
int n;      //size of squared matrix (power of 2)
int firstCellRow;//coordinates for initial cell 
int firstCellColumn;

/* Prints the matrix mat */
void printMatrix(){
	if (debug) {
		cout<<"Matrix..."<<endl;
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cout<<mat[r][c]<<' ';
		}
		cout<<endl;
	}
}

/* Prints the matrix visited */
void printVisited(){
	if (debug) {
		cout<<"Visited..."<<endl;
	}
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cout<<visited[r][c]<<' ';
		}
		cout<<endl;
	}
}

/* Fills the matrix mat with 0s */
void fillMatrix(){
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			mat[r][c] = 0;
			visited[r][c] = 0;
		}
		cout<<endl;
	}
}

/* Finds the quadrant in which the cell is...
 * r = row; c = column; s = size;  */
int findQuadrant(int r, int c, int s) {
	int quadrant = 1; //start in first quadrant 

	if(c < s/2){
		//it is in the left half quadrants 2 or 3
		quadrant++;
	}else{
		//it is in the right half quadrants 1 or 4
		//do nothing...
	}
	if(r < s/2){
		//it is in the top half quadrants 1 or 2
		//do nothing...
	}else{
		//it is in the bottom half quadrants 3 or 4
		quadrant++;
	}
	return quadrant; 
}

/* Paints triomines recursively in matrix given an initial cell and the size of the 
 * submatrix to paint... until the whole matrix is filled. 
 * r = row; c = column; size = size of submatrix; 
 * infRow and infColumn = first row  and column of submatrix */
void paintTriomine(int r, int c, int infRow, int infColumn, int size){

	//fill visited cell with triomineCounter
	mat[r][c] = triomineCounter; 

	if (debug) {
		cout<<"Triomine counter: "<<triomineCounter<<endl;
		printMatrix();
		// printVisited();
	}

	if(size >= 2)
	{
		//contains the quadrant of the cell
		int q = findQuadrant(r-infRow, c-infColumn, size); 

		//calculate coordinates of center 2x2 matrix in this submatrix sizexsize
		int bottomRow, topRow, rightColumn, leftColumn;
		bottomRow = rightColumn = size / 2; 
		topRow = leftColumn = bottomRow - 1; 

		//adjust the coordinates of the center matrix, based on it position in
		//its container submatrix...
		bottomRow += infRow;
		topRow += infRow; 
		rightColumn += infColumn; 
		leftColumn += infColumn;

		//get infRow and infColumn of a quadrant in this submatrix

		//modify the size of the next matrix to be filled...
		size /= 2; 
		//modify triomine counter since I am printing another triomine
		triomineCounter++;
		switch(q){
			case 1: 
				paintTriomine(topRow, leftColumn, topRow - size, leftColumn - size,  size); 
				paintTriomine(bottomRow, leftColumn, bottomRow, leftColumn -  size, size); 
				paintTriomine(bottomRow, rightColumn, bottomRow, rightColumn, size); 
				break;
			case 2: 
				paintTriomine(topRow, rightColumn, topRow - size, rightColumn, size); 
				paintTriomine(bottomRow, rightColumn, bottomRow, rightColumn, size); 
				paintTriomine(bottomRow, leftColumn, bottomRow, leftColumn - size, size); 
				break;
			case 3: 
				paintTriomine(bottomRow, rightColumn, bottomRow, rightColumn, size); 
				paintTriomine(topRow, rightColumn, topRow - size, rightColumn, size); 
				paintTriomine(topRow, leftColumn, topRow - size, leftColumn - size, size); 
				break;
			case 4: 
				paintTriomine(bottomRow, leftColumn, bottomRow, leftColumn - size, size); 
				paintTriomine(topRow, leftColumn, topRow - size, leftColumn - size, size); 
				paintTriomine(topRow, rightColumn, topRow - size, rightColumn, size); 
				break;
		}
	}
}

int main(int argc, const char *argv[])
{
	triomineCounter = 0; 
	cout<<"Introduce matrix size: "<<endl;
	cin>>n; 	

	cout<<"Introduce first filled cell: "<<endl;
	cin>>firstCellRow>>firstCellColumn;
	paintTriomine(firstCellRow, firstCellColumn, 0, 0, n); 

	return 0;
}
