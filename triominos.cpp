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
int firstCellRow;
int firstCellColumn;//coordinates for initial cell 

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

/* Returns true if the cell at mat[row,column] is still in range to paint 
 * its corresponding triomine */
bool canPaint(int row, int column, int q){
	bool itCanPaint = false;
	switch(q) {
		case 1:
			if (row%2 == 0 && column%2 != 0) {
				itCanPaint = true; 
			}else{
				itCanPaint = false; 
			}
		       break;
		case 2:
			if (row%2 == 0 && column%2 == 0) {
				itCanPaint = true; 
			}else{
				itCanPaint = false; 
			}
		       break;
		case 3:
			if (row%2 != 0 && column%2 == 0) {
				itCanPaint = true; 
			}else{
				itCanPaint = false; 
			}
		       break;
		case 4:
			if (row%2 != 0 && column%2 != 0) {
				itCanPaint = true; 
			}else{
				itCanPaint = false; 
			}
		       break;

	}
	//if I am at the center quadrant then I can paint
	if(
	   (row == ( n/2 - 1 ) && column == ( n/2-1 ) && q == 2) || 
	   ( row == ( n/2 - 1 ) && column == n/2  && q == 1)   || 
	   ( row == n/2     && column == ( n/2-1 ) && q == 3) || 
	   ( row == n/2     && column == n/2  && q == 4)    

	  ){
		if (debug) {
			cout<<"center quadrant"<<endl;
		}
		itCanPaint = true; 
	}
	// if(row >= (n/2 - 1) && row <= (n/2) &&
	//    column >= (n/2 - 1) && column <= (n/2)){
	// 	return true; 
	// }else if (row >= 0 && row <= (n/2 - 1) &&
	//           column >= 0 && column <= (n/2 - 1)){
	// 	return true; 
	// }else if (row >= (n/2) && row <= (n - 1) &&
	//           column >= (n/2) && column <= (n - 1)){
	// 	return true; 
	// }else{
	// 	return false; 
	// }
	
	return itCanPaint; 

}

/* Paints triomines recursively in matrix given an initial cell
 * in a 2x2 submatrix of the matrix and its position in that submatrix
 * until the whole matrix is filled. r = row; c = column; q = quadrant; */
void paintTriomine(int r, int c, int q){
	if (debug) {
		cout<<"Triomine counter: "<<triomineCounter<<endl;
		printMatrix();
		printVisited();
	}
	if(canPaint(r, c, q)){
		switch(q){
			case 1:
				mat[r+1][c] = triomineCounter; 	
				mat[r+1][c-1] = triomineCounter; 	
				mat[r][c-1] = triomineCounter; 	

				triomineCounter++;

				//if i haven't painted this cell yet
				if(visited[r][c] < 1){
					visited[r][c] += 1; 
					paintTriomine(r, c, 3);
				}

				paintTriomine(r+1, c, 2); 
				paintTriomine(r+1, c-1, 1);
				paintTriomine(r, c-1, 4);


				break;
			case 2: 
				mat[r+1][c] = triomineCounter; 	
				mat[r+1][c+1] = triomineCounter; 	
				mat[r][c+1] = triomineCounter; 	

				triomineCounter++;

				if(visited[r][c] < 1){
					visited[r][c] += 1; 
					paintTriomine(r, c, 4);
				}

				paintTriomine(r+1, c, 1); 
				paintTriomine(r+1, c+1, 2);
				paintTriomine(r, c+1, 3);

				break;
			case 3:
				mat[r-1][c] = triomineCounter; 	
				mat[r-1][c+1] = triomineCounter; 	
				mat[r][c+1] = triomineCounter; 	

				triomineCounter++;

				if(visited[r][c] < 1){
					visited[r][c] += 1; 
					paintTriomine(r, c, 1);
				}

				paintTriomine(r-1, c, 4); 
				paintTriomine(r-1, c+1, 3);
				paintTriomine(r, c+1, 2);

				break;
			case 4:
				mat[r-1][c] = triomineCounter; 	
				mat[r-1][c-1] = triomineCounter; 	
				mat[r][c-1] = triomineCounter; 	

				triomineCounter++;
				if(visited[r][c] < 1){
					visited[r][c] += 1; 
					paintTriomine(r, c, 2);
				}

				paintTriomine(r-1, c, 3); 
				paintTriomine(r-1, c-1, 4);
				paintTriomine(r, c-1, 1);

				break;
		}
	}else{
		if (debug) {
			cout<<r<<' '<<c<<" can't paint..."<<endl;
		}
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
void paintMatrix(int row, int column, int size){
	int quadrant = findQuadrant(row, column, size);
	if(size > 2){
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
		paintMatrix(row, column, size / 2); 
	}else {
		//I found the size 2 initial matrix
		paintTriomine(firstCellRow, firstCellColumn, quadrant);
	}
}

int main(int argc, const char *argv[])
{
	cout<<"Introduce matrix size: "<<endl;
	cin>>n; 	

	cout<<"Introduce first filled cell: "<<endl;
	cin>>firstCellRow>>firstCellColumn;
	paintMatrix(firstCellRow, firstCellColumn, n); 


	return 0;
}
