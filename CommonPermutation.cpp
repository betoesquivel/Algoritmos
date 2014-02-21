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

int min (int a, int b)
{
	return ( (a < b) ? a:b ); 
}

//returns the index of the letter in an array where a = 0 and so on...
int getLetterIndex(char c)
{
	return (c - 97); 
}

//Prints the common letters between s1 and s2
void printCommonPermutations(string s1, string s2)
{
	int letrasS1[26];
	int letrasS2[26];
	for (unsigned int i = 0; i < s1.length(); i++) {
		int letterIndex = getLetterIndex(s1[i]); 
		letrasS1[letterIndex] += 1; 
	}
	for (unsigned int i = 0; i < s2.length(); i++) {
		int letterIndex = getLetterIndex(s2[i]); 
		letrasS2[letterIndex] += 1; 
	}
	for (int i = 0; i < 26; i++) {
		if (letrasS1[i] > 0 && letrasS2[i] > 0) {
			char c = i + 97; 
			int coincidencias = min(letrasS1[i], letrasS2[i]); 	
			while (coincidencias > 0){
				cout<<c; 		
				coincidencias--;
			}
		}
	}
	cout<<endl;
}

int main(int argc, const char *argv[])
{
	int cases; 
	
	//consist of at most 1000 lowercase letters...
	string word1, word2;

	cin>>cases; 
	cin>>word1>>word2; 
	while(cases > 0){
		printCommonPermutations(word1, word2);
		cases--; 
		cin>>word1>>word2;
	}
	return 0;
}
