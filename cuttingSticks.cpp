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
int cutsArray[100];
int optimizedCutsMatrix[1000][1000];
bool debug = false; 

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
		cout<<"Finished printing..."<<endl;
	}
}

/* Returns the minimum cut cost from every permutation */
int min(int i, int j){
	int minimum = INT_MAX; 
	for (int x = i; x < j; x++) {
		int sum = optimizedCutsMatrix[i][x] + optimizedCutsMatrix[x+1][j];
		minimum = (sum < minimum) ? sum : minimum; 
		if (debug) {
			cout<<optimizedCutsMatrix[i][x]<<' '<<optimizedCutsMatrix[x+1][j]<<endl;
			cout<<"Minimum until now: "<<minimum<<endl;
		}
	}

	//suma de los cuts de i hasta j
	for (int x = i; x <= j; x++) {
		minimum += cutsArray[x];
	}

	if (debug) {
		cout<<"Final minimum from i to j: "<<minimum<<endl;
	}

	return minimum; 
}

void optimizeTheMatrixCuts(){
	
	for (int diag=1; diag < matrixLength; diag++){
		if (debug) {
			cout<<"Diag No. "<<diag<<endl;
		}
		for (int i = 0; i < matrixLength-diag; i++) {
			int j = i + diag;
			optimizedCutsMatrix[i][j] = min(i, j); 
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
	return optimizedCutsMatrix[0][cuts];
}

int main(int argc, const char *argv[])
{
	cin>>length; 
	while (length != 0) {
		cin>>cuts;
		matrixLength = cuts + 1; 
		if (debug) {
			cout<<"Cuts: "<<cuts<<" MatrixLength: "<<matrixLength<<endl;
		}
		fillCutsArray();
		optimizeTheMatrixCuts();
		cout<<"The minimum cutting is "<<minimumCost()<<"."<<endl;

		cin>>length; 
	}
	return 0;
}


