/*
 * =====================================================================================
 *
 *       Filename:  Audiophobia.cpp
 *
 *    Description:  The loudness or intensity level of sound is usually measured in 
 *    decibels and sound having intensity level 130 decibels or higher is considered
 *    painful. THe intensity level of normal conversation is 60-65 decibels and that
 *    of heavy traffic is 70-80 decibels. 
 *
 *    Consider a city map where the edges refer to streets and the nodes refer to 
 *    crossings. The integer on each edge is the average intensity level of sound
 *    in the corresponding street. 
 *
 *    Get the minimum path to go from one node to another... given the nodes, that is.
 *
 *        Version:  1.0
 *        Created:  02/24/2014 09:47:43 PM
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

int crossings, streets;
int streetDecibelGraph[1000][1000];
const int infinity = -1;
bool debug = false; 

void init0s(){
	for (int r = 0; r < 1000; r++) {
		for (int c = 0; c < 1000; c++) {
			streetDecibelGraph[r][c] = 0;
		}
	}
}

void printGraph(){
	for (int r = 0; r < crossings; r++) {
		for (int c = 0; c < crossings; c++) {
			cout<<streetDecibelGraph[r][c]<<' ';
		}
		cout<<endl;
	}
}

void clearMap(){
	for (int r = 0; r < crossings; r++) {
		for (int c = 0; c < crossings; c++) {
			if (r == c) {
				streetDecibelGraph[r][c] = 0;
			}else{
				streetDecibelGraph[r][c] = infinity;
			}
		}
	}
	if (debug) {
		cout<<"Map cleared..."<<endl;
		printGraph();
	}
}

void fillMap(){
	int n1, n2, d; //r=row; c=column; d=decibels; node1, node2 and arch
	for (int i = 0; i < streets; i++) {
		cin>>n1>>n2>>d;
		n1--; n2--;
		streetDecibelGraph[n1][n2] = streetDecibelGraph[n2][n1] = d; 
	}		
	if (debug) {
		cout<<"Map filled..."<<endl;
		printGraph();
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

void floydTheMap(){
	for (int k = 0; k < crossings; k++) {
		for (int i = 0; i < crossings; i++) {
			for (int j = 0; j < crossings; j++) {
				streetDecibelGraph[i][j] = min(streetDecibelGraph[i][j], streetDecibelGraph[i][k], streetDecibelGraph[k][j]);
			}
		}
	}
	if (debug) {
		cout<<"Map Floyed..."<<endl;
		printGraph();
	}
}

int minimumSoundIntensityLevel(int n1, int n2){
	return streetDecibelGraph[n1][n2];
}

int main(int argc, const char *argv[])
{
	int cases, queries;

	cin>>cases; 
	int count = 0;
	while (count < cases) {
		cin>>crossings>>streets>>queries;
		clearMap();
		fillMap();

		floydTheMap();

		cout<<"Case "<<count + 1<<":"<<endl;
		int start, end;
		for (int i = 0; i < queries; i++) {
			cin>>start>>end;
			start--; end--;
			int minimum = minimumSoundIntensityLevel(start, end);
			if (minimum != infinity) {
				cout<<minimum<<endl;
			}else {
				cout<<"no path"<<endl;
			}
		}			
		
		count++;		
	}
	return 0;
}
