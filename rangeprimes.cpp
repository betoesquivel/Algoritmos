
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool debug = false; 

vector<int> primes; 
int lowerBoundPrime;
int upperBoundPrime;

/* Checks if a number is prime by checking divisibility
 * with all previous primes in vector primes up until 
 * square root of n. */
bool is_prime(int n){
	int limit = sqrt(n);
	for (int i = 0; primes[i] <= limit; i++) {
		if (n%primes[i]==0) {
			return false;
		}
	}
	return true;
}

/* Finds primes and adds them to vector primes
 * until num is passed. At the end, lower_bound and upper_bound
 * contain the smallest range delimited by primes in which 
 * num is contained.   */
void findPrimesUntilNum(int num){
	lowerBoundPrime = primes[primes.size()-1];
	int count = primes[primes.size()-1] + 1;//counter that starts looking for primes to add..

	bool rangeFound = false; 
	while (!rangeFound) {
		if(is_prime(count)){
			if (debug) {
				cout<<"Prime: "<<count<<endl;
			}

			if(count == num) {
				lowerBoundPrime = upperBoundPrime = count; 
				rangeFound = true; 
			}else{
				primes.push_back(count);
				if(count > num){
					upperBoundPrime = count; 
					rangeFound = true; 
				}else{
					lowerBoundPrime = count; 
				}
			}

		}
		count++;		
	}
	if (debug) {
		cout<<"Finished..."<<endl;
		cout<<"Upper: "<<upperBoundPrime<<endl;
		cout<<"Lower: "<<lowerBoundPrime<<endl;
	}
}

/* Performs a binary search until it finds
 * the range of primes in which the num parameter lays. */
void binarySearchForPrimeRange(int num){
	int first, last; //binary search indexes
	first = 0;
	last = primes[primes.size()-1];

	bool rangeFound = false; 

	while(!rangeFound){
		int mid = (first + last)/2;

		if( ( last - first ) == 1){
			rangeFound = true; 
		}else {

			if (num == primes[mid]){
				first  = last = mid; 
				rangeFound = true; 
			}else{
				if (num < primes[mid]){
					last = mid - 1;
				}else{
					first = mid + 1; 
				}
			}
			
		}
	}

	lowerBoundPrime = primes[first];
	upperBoundPrime = primes[last];
}

int main(int argc, const char *argv[])
{
	//add first prime to list...
	primes.push_back(2);	

	int cases, number; 

	cin>>cases;
	int count = 0;//while counter
	while (count < cases) {
		cin>>number;
		int lastPrimeFound = primes[primes.size()-1];
		if(number>lastPrimeFound){
			findPrimesUntilNum(number);
		}else{
			if(number == lastPrimeFound){
				lowerBoundPrime = upperBoundPrime = lastPrimeFound;
			}else{
				binarySearchForPrimeRange(number);
			}
		}
		cout<<lowerBoundPrime<<' '<<upperBoundPrime<<endl;
		count++;		
	}
	return 0;
}
