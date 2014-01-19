/*
 * =====================================================================================
 *
 *       Filename:  howmanyprimes.cpp
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
#include "ArbolAVL.h"
bool debug = true; 

const int SIZE = 1000000;
int acumulated_primes_until_index[SIZE];
vector<int> primes;
ArbolAVL<int> composites;

bool divisible5(int n){
	return (n%10 == 5) ? true:false;
}
bool is_prime(int n){
	
	if(composites.existe(n)){
		return false;
	}else{
		if(n%2==0){
			return false; 
		}else if(n%3==0){
			return false;
		}else if(divisible5(n)){
			return false;
		}

		int half = sqrt(n);
		for (int i = 3; primes[i] <= half; i++) {
			if (n%primes[i]==0) {
				return false;
			}
		}
		return true;
	}
}

void addPrime(int n){
	int new_composite = n;
	primes.push_back(n);

	new_composite+=n;
	while(new_composite<SIZE){
		if (debug) {
			cout<<"Composite: "<<new_composite<<endl;
		}
		composites.insertar(new_composite);
		new_composite+=n;
	}
}

void prefill_first_primes(){
	primes.push_back(2);
	primes.push_back(3);
	primes.push_back(5);
	primes.push_back(7);
	primes.push_back(11);
	
	acumulated_primes_until_index[0] = 0;
	acumulated_primes_until_index[1] = 0;
	acumulated_primes_until_index[2] = 1;
	acumulated_primes_until_index[3] = 2;
	acumulated_primes_until_index[4] = 2;
	acumulated_primes_until_index[5] = 3;
	acumulated_primes_until_index[6] = 3;
	acumulated_primes_until_index[7] = 4;
	acumulated_primes_until_index[8] = 4;
	acumulated_primes_until_index[9] = 4;
	acumulated_primes_until_index[10] = 4;
	acumulated_primes_until_index[11] = 5;
}

void find_primes(){
	prefill_first_primes();	
	int count = 12, acumulated_primes = 5;
	while (count < SIZE) {
		if(is_prime(count)){
			if (debug) {
				cout<<"Prime: "<<count<<endl;
			}

			if (count>1000000) {
				addPrime(count);
			}else{
				primes.push_back(count);
			}
			acumulated_primes++;
		}
		acumulated_primes_until_index[count] = acumulated_primes;
		count++;		
	}
	if (debug) {
		cout<<"Terminado..."<<endl;
		cout<<acumulated_primes<<endl;
	}
}

int get_number_of_primes(int a, int b){
	return acumulated_primes_until_index[b] - acumulated_primes_until_index[a-1];
}

int main(){
	find_primes();
	int a, b; 
	cin>>a>>b;
	while(a!=0 && b!=0){
		cout<<get_number_of_primes(a,b)<<endl;
		cin>>a>>b;		
	}	
}
