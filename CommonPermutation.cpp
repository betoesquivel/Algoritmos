/*
 * =====================================================================================
 *
 *       Filename:  CommonPermutation.cpp
 *
 *    Description:  Given two strings of lowercase letters A and B, print the longest string X composed of lowercase letters such that there exists a permutation of X which is a subsequence of A, and there is also exists a permutation of X which is a subsequence of B.
 *
 *        Version:  1.0
 *        Created:  02/19/2014 23:18:31
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

int main(int argc, const char *argv[])
{
	int cases; 
	
	//consist of at most 1000 lowercase letters...
	string word1, word2;

	cin>>cases; 
	cin>>word1>>word2; 
	while(cases > 0){
		
		cin>>word1>>word2;
		cases--; 
	}
	return 0;
}
