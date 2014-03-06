/*
 * =====================================================================================
 *
 *       Filename:  cuttingSticks.cpp
 *
 *    Description:  You have to cut a wood stick into pieces. The most affordable company, The Analog Cutting Machinery, Inc. (ACM), charges money according to the length of the stick being cut. Their procedure of work requires that they only make one cut at a time.

It is easy to notice that different selections in the order of cutting can led to different prices. For example, consider a stick of length 10 meters that has to be cut at 2, 4 and 7 meters from one end. There are several choices. One can be cutting first at 2, then at 4, then at 7. This leads to a price of 10 + 8 + 6 = 24 because the first stick was of 10 meters, the resulting of 8 and the last one of 6. Another choice could be cutting at 4, then at 2, then at 7. This would lead to a price of 10 + 4 + 6 = 20, which is a better price.
 *
 *        Version:  1.0
 *        Created:  03/04/2014 13:39:30
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jose Alberto Esquivel Patino (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */


#include <iostream>
#include <climits>
using namespace std;

int length, cuts, matrixLength; 
int cutsArray[50];
int optimizedCutsMatrix[1000][1000];
const int infinity = -1;
bool debug = true; 

void init0s(){
	for (int r = 0; r < 1000; r++) {
		for (int c = 0; c < 1000; c++) {
			optimizedCutsMatrix[r][c] = 0;
		}
	}
}

void printArray(){
	for (int i = 0; i < matrixLength; i++) {
		cout<<cutsArray[i]<<' ';
	}
	cout<<endl;
}

void printMatrix(){
	for (int r = 0; r < matrixLength; r++) {
		for (int c = 0; c < matrixLength; c++) {
			cout<<optimizedCutsMatrix[r][c]<<' ';
		}
		cout<<endl;
	}
}

void clearMatrix(){
	for (int r = 0; r < matrixLength; r++) {
		for (int c = 0; c < matrixLength; c++) {
			if (r == c) {
				optimizedCutsMatrix[r][c] = 0;
			}
		}
	}
	if (debug) {
		cout<<"Matrix cleared..."<<endl;
		printMatrix();
	}
}

void fillCutsArray(){
	int previousCutPosition = 0, currentCutPosition; 
	for (int i = 0; i < cuts; i++) {
		cin>>currentCutPosition;
		cutsArray[i] = currentCutPosition - previousCutPosition;
		previousCutPosition = currentCutPosition;
	}		
	cutsArray[cuts] = length - previousCutPosition;
	if (debug) {
		cout<<"Cut array filled..."<<endl;
		printArray();
	}
}

/* Returns the bigger number of both received as parameters */
int max(int n1, int n2){
	return (n1 > n2) ? n1:n2; 
}

/* Returns the minimum between n1 or n2 + n3 handling infinity */
int min(int n1, int n2, int n3){
	if(n2 == infinity || n3 == infinity){
		return n1;
	}else{
		int bigger = max(n2,n3);
		if(n1 > bigger || n1 == infinity){
			return bigger;
		}else{
			return n1;
		}
	}
}

void optimizeTheMatrixCuts(){
	for (int k = 0; k < matrixLength; k++) {
		for (int i = 0; i < matrixLength; i++) {
			for (int j = 0; j < matrixLength; j++) {
				optimizedCutsMatrix[i][j] = min(optimizedCutsMatrix[i][j], optimizedCutsMatrix[i][k], optimizedCutsMatrix[k][j]);
			}
		}
	}
	if (debug) {
		cout<<"Matrix optimized..."<<endl;
		printMatrix();
	}
}

int minimumCuts(int n1, int n2){
	return optimizedCutsMatrix[n1][n2];
}

int minimumCost(){
	return optimizedCutsMatrix[cuts][cuts];
}

int main(int argc, const char *argv[])
{
	cin>>length; 
	while (length != 0) {
		cin>>cuts;
		matrixLength = cuts + 1; 
		fillCutsArray();
		
		// optimizeTheMatrixCuts();
		// cout<<"The minimum cutting is "<<minimumCost()<<endl;

		cin>>length; 
	}
	return 0;
}


