/*
 * =====================================================================================
 *
 *       Filename:  perms.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/07/2014 19:58:10
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

long long D[20][250] = { {-1} };
bool debug = false; 

void printMatrix()
{
	int c; 
	for (int r = 0; r < 20; r++) {
		c = 0;
		while (c < 250 && D[r][c] != 0)
		{
			cout << D[r][c] << ' ';
			c ++; 
		}
		cout << endl;
	}
}

void clearMatrix()
{
	int c; 
	for (int r = 0; r < 20; r++) {
		c = 0;
		while (c < 250 && D[r][c] != 0)
		{
			D[r][c] = 0;
			c ++; 
		}
		D[r][0] = -1;
	}
	
}

void prefillMatrix()
{
	D[0][0] = 0;

	D[1][0] = 1;

	D[2][0] = 1; D[2][1] = 1; 

	D[3][0] = 1; D[3][1] = 2; D[3][2] = 2; D[3][3] = 1; 

	D[4][0] = 1; D[4][1] = 3; D[4][2] = 5; D[4][3] = 6; 
	D[4][4] = 5; D[4][5] = 3; D[4][6] = 1;  
}

void llenarFila(int n)
{
	int j = -1; 
	int fila = n; 	
	int maxIndex = 0;
	while(D[fila-1][0] == -1){
		fila -= 1; 
	}
	if (debug) {
		cout << "La fila " << fila << " es la primera que no esta llena."<<endl;
	}

	//maxIndex is the index of the last value from the last filled row
	for (int i = 0; D[fila-1][i] != 0; i++) {
		maxIndex = i;
	}
	if (debug) {
		cout << "La ultima columna llena de la fila anterior es la " <<maxIndex<<endl;
	}

	//Now I can fill in the first unfilled row
	//And with it, I can fill up until n
	while (fila <= n){
		int maxk = maxIndex + fila;
		D[fila][0] = 1; 
		for (int k = 1; k < maxk ; k++) {
			D[fila][k] = D[fila][k-1] + D[fila-1][k]; 
			if (k == fila) {
				// D[fila][k] -= D[fila-1][k%fila]; 
				j = 0; 
			}
			if (k >= fila) {
				D[fila][k] -= D[fila-1][j]; 
				j ++; 
			}
		}
		maxIndex = maxk - 1; 
		fila++;
	}
}

long long perms(int n, int k)
{
	if (D[n][0] != -1) {
		//la fila ya esta llena
		return D[n][k];
	}else{
		//tengo que llenar la fila
		llenarFila(n);
		return D[n][k];
	}
}

int main(int argc, const char *argv[])
{
	//n is the amount of numbers to calculate permutations
	//k is the amount of inversions that I am looking for
	int n, k; 	
	//given this two variables I will output the number of permutations
	//of n numbers that have exactly k inversions.
	//clear matrix
	clearMatrix();	
	prefillMatrix();
	cin >> n >> k;
	while (!( n == 0 && k == 0 ))
	{
		cout << perms(n, k) <<endl;

		if (debug) {
			printMatrix();
		}

		cin >> n >> k;
	}

	return 0;
}
