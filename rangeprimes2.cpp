/*
 * =====================================================================================
 *
 *       Filename:  rangeprimes2.cpp
 *
 *    Description: 
 *
 *        Version:  1.0
 *        Created:  01/18/2014 10:16:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jose Alberto Esquivel Patino (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool debug = false; 

const int SIZE = 1000000;
int lowerBound[SIZE];
int upperBound[SIZE];
int lower;
int upper; 

vector<int> primes;

bool is_prime(int n){
	int limit = sqrt(n);
	for (int i = 0; primes[i] <= limit; i++) {
		if (n%primes[i]==0) {
			return false;
		}
	}
	return true;
}

void prefill_first_primes(){
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);
	primes.push_back(11);
	
	lowerBound[0] = 0;
	upperBound[0] = 2;
	lowerBound[1] = 0;
	upperBound[1] = 2;
	lowerBound[2] = 2;
	upperBound[2] = 2;
	lowerBound[3] = 3;
	upperBound[3] = 3;
	lowerBound[4] = 3;
	upperBound[4] = 5;
	lowerBound[5] = 5;
	upperBound[5] = 5;
	lowerBound[6] = 5;
	upperBound[6] = 7;
	lowerBound[7] = 7;
	upperBound[7] = 7;
	lowerBound[8] = 7;
	upperBound[8] = 11;
	lowerBound[9] = 7;
	upperBound[9] = 11;
	lowerBound[10] = 7;
	upperBound[10] = 11;
	lowerBound[11] = 11;
	upperBound[11] = 11;
}

void find_primes(){
	prefill_first_primes();	
	int count = 12;
	lower = 11; 
	upper = 11; 
	while (count < SIZE) {
		if(is_prime(count)){
			if (debug) {
				cout<<"Prime: "<<count<<endl;
			}
			lower = upper = count; 
			primes.push_back(count);

			//iterate backwards, changing my upperBound for all previous non prime numbers; 
			int backwardsIterator = count-1;
			while(upperBound[backwardsIterator]==-1){
				upperBound[backwardsIterator] = count; 
				backwardsIterator--;
			}
		}else{
			upper = -1;
		}
		lowerBound[count] = lower;
		upperBound[count] = upper;
		count++;		
	}
	if (debug) {
		cout<<"Terminado..."<<endl;
	}
}

int main(){
	find_primes();
	int cases; 
	cin>>cases;
	int x; 
	while(cases>0){
		cin>>x; 
		cout<<lowerBound[x]<<' '<<upperBound[x]<<endl;
		cases--;
	}	
}
