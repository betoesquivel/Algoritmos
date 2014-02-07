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

bool debug = false;

int mat[MAXSIZE][MAXSIZE]; 	//pointer tu square matrix
int visited[MAXSIZE][MAXSIZE]; 	//pointer tu square matrix
int n;      //size of squared matrix (power of 2)
int firstCellRow;//coordinates for initial cell 
int firstCellColumn;
int triomineNumbers[MAXSIZE*10];

void fillNumbers(){
	for (int i = 0; i < MAXSIZE*10; i++) {
		triomineNumbers[i] = i; 
	}
	triomineNumbers[0] = -1;
}

int getUnusedNumber(){
	int temp = -1;
	for (int i = 0; i < MAXSIZE*10; i++) {
		if (triomineNumbers[i]!=-1) {
			temp = triomineNumbers[i];
			triomineNumbers[i] = -1;	
			break;
		}
	}
	return temp;
}

/* Prints the matrix mat */
void printMatrix(){
	if (debug) {
		cout<<"Matrix..."<<endl;
	}
	string espacios = " " ;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if(mat[r][c]/10>0){
				espacios = " ";
			}else{
				espacios = "  ";
			}
			cout<<mat[r][c]<<espacios;
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
		quadrant = (quadrant == 1) ? 1:2; 
	}else{
		//it is in the bottom half quadrant 3 or 4
		quadrant = (quadrant == 1) ? 4:3; 
	}
	if (debug) {
		cout<<"Quadrant found: " <<quadrant<<endl;
	}
	return quadrant; 
}

/* Paints triomines recursively in matrix given an initial cell and the size of the 
 * submatrix to paint... until the whole matrix is filled. 
 * r = row; c = column; size = size of submatrix; 
 * infRow and infColumn = first row  and column of submatrix */
void paintTriomine(int r, int c, int infRow, int infColumn, int size){

	if (debug) {
		visited[r][c] += 1; 
		printMatrix();
		printVisited();
	}

	if(size >= 2)
	{
		//contains the quadrant of the cell
		int q = findQuadrant(r-infRow, c-infColumn, size); 

		//calculate coordinates of center 2x2 matrix in this submatrix sizexsize
		int bottomRow, topRow, rightColumn, leftColumn;
		topRow = leftColumn = (size-1)/2; 
		bottomRow = rightColumn = topRow+1; 

		//adjust the coordinates of the center matrix, based on it position in
		//its container submatrix...
		bottomRow += infRow;
		topRow += infRow; 
		rightColumn += infColumn; 
		leftColumn += infColumn;


		//get infRow and infColumn of a quadrant in this submatrix
		if (debug) {
			cout<<"Q1 inf limits: " <<endl;
			cout<<"Row: " <<topRow - (size - 1)/2<<endl;
			cout<<"Column: " <<rightColumn<<endl;

			cout<<"Q2 inf limits: " <<endl;
			cout<<"Row: " <<topRow - (size - 1)/2<<endl;
			cout<<"Column: " <<leftColumn - (size - 1)/2<<endl;

			cout<<"Q3 inf limits: " <<endl;
			cout<<"Row: " <<bottomRow<<endl;
			cout<<"Column: " <<leftColumn - (size - 1)/2<<endl;

			cout<<"Q4 inf limits: " <<endl;
			cout<<"Row: " <<bottomRow<<endl;
			cout<<"Column: " <<rightColumn<<endl;
		}

		//modify triomine counter since I am printing another triomine
		int triomineCounter = getUnusedNumber();
		switch(q){
			case 1: 
				mat[topRow][leftColumn] = triomineCounter;
				mat[bottomRow][leftColumn] = triomineCounter;
				mat[bottomRow][rightColumn] = triomineCounter;
				triomineCounter++;
					paintTriomine(r, c, topRow - (size - 1)/2, rightColumn,  size/2); 
				paintTriomine(topRow, leftColumn, topRow - (size - 1)/2, leftColumn - (size - 1)/2,  size/2); 
				paintTriomine(bottomRow, leftColumn, bottomRow, leftColumn - (size - 1)/2, size/2); 
				paintTriomine(bottomRow, rightColumn, bottomRow, rightColumn, size/2); 
				break;
			case 2: 
				mat[topRow][rightColumn] = triomineCounter;
				mat[bottomRow][rightColumn] = triomineCounter;
				mat[bottomRow][leftColumn] = triomineCounter;
				triomineCounter++;
					paintTriomine(r, c, topRow - (size - 1)/2, leftColumn - (size - 1)/2,  size/2); 
				paintTriomine(topRow, rightColumn, topRow - (size - 1)/2, rightColumn, size/2); 
				paintTriomine(bottomRow, rightColumn, bottomRow, rightColumn, size/2); 
				paintTriomine(bottomRow, leftColumn, bottomRow, leftColumn - (size - 1)/2, size/2); 
				break;
			case 3: 
				mat[bottomRow][rightColumn] = triomineCounter;
				mat[topRow][rightColumn] = triomineCounter;
				mat[topRow][leftColumn] = triomineCounter;
				triomineCounter++;
					paintTriomine(r, c, bottomRow, leftColumn - (size - 1)/2,  size/2); 
				paintTriomine(bottomRow, rightColumn, bottomRow, rightColumn, size/2); 
				paintTriomine(topRow, rightColumn, topRow - (size - 1)/2, rightColumn, size/2); 
				paintTriomine(topRow, leftColumn, topRow - (size - 1)/2, leftColumn - (size - 1)/2, size/2); 
				break;
			case 4: 
				mat[bottomRow][leftColumn] = triomineCounter;
				mat[topRow][leftColumn] = triomineCounter;
				mat[topRow][rightColumn] = triomineCounter;
				triomineCounter++;
					paintTriomine(r, c, bottomRow, rightColumn,  size/2); 
				paintTriomine(bottomRow, leftColumn, bottomRow, leftColumn - (size - 1)/2, size/2); 
				paintTriomine(topRow, leftColumn, topRow - (size - 1)/2, leftColumn - (size - 1)/2, size/2); 
				paintTriomine(topRow, rightColumn, topRow - (size - 1)/2, rightColumn, size/2); 
				break;
		}
	}else{

	}
}

int main(int argc, const char *argv[])
{
	cout<<"Introduce matrix size: "<<endl;
	cin>>n; 	

	cout<<"Introduce first filled cell: "<<endl;
	cin>>firstCellRow>>firstCellColumn;

	fillNumbers();
	paintTriomine(firstCellRow, firstCellColumn, 0, 0, n); 
	printMatrix();

	return 0;
}
