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

using namespace std;

const int SIZE = 1000000;
int acumulated_primes_until_index[SIZE];
vector<int> primes;

bool is_prime(int n){
	int half = n/2;
	for (int i = 0; primes[i] <= half; i++) {
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
	// cout<<"I prefill my array and vector..."<<endl;
	prefill_first_primes();	
	// cout<<"I prefilled my array and vector..."<<endl;
	int count = 12, acumulated_primes = 5;
	while (count < SIZE) {
		// cout<<"I check if "<<count<<" is a prime..."<<endl;
		if(is_prime(count)){
			cout<<count<<" is a prime..."<<endl;
			primes.push_back(count);
			// cout<<"I added "<<count<<" to primes..."<<endl;
			acumulated_primes++;
		}
		// cout<<"I added "<<acumulated_primes<<" to acumulated primes until index..."<<endl;
		acumulated_primes_until_index[count] = acumulated_primes;
		count++;		
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
