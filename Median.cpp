/*
 * =====================================================================================
 *
 *       Filename:  Median.cpp
 *
 *    Description:  median of two sorted arays.
 *
 *        Version:  1.0
 *        Created:  14/03/14 20:19:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jose Alberto Esquivel Patino (),
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */
 
#include <iostream>
#include <cmath>
 
using namespace std;
int arr1[105];
int arr2[105];
int tam;
 
int min(int a, int b){
        return (a<b) ? a:b;
}
int max(int a, int b){
        return (a>b) ? a:b;
}
 
double mediana(int inf1, int sup1, int inf2, int sup2){
 
        int size = sup1 - inf1 + 1;
        int m1, m2;
        if (size > 2) {
                //condiciones y recursion
                m1 = ceil ( (inf1 + sup1) / 2.0 );                             
                m2 = floor ( (inf2 + sup2) / 2.0 );                            
 
                if (arr1[m1] < arr2[m2]) {
                        return mediana(m1, sup1, inf2, m2);                            
                }else{
                        return mediana(inf1, m1, m2, sup2);
                }
 
        }else{
                //caso base
                m1 = min(arr1[inf1], arr1[sup1]);
                m2 = max(arr2[inf2], arr2[sup2]);
               
                return ( m1+m2 ) / 2.0;
        }
}
 
int main(int argc, const char *argv[])
{
        int casos;
        cin>>casos;
       
        while(casos>0) {
 
                cin>>tam;
 
                for(int a = 0; a<tam; a++) {
                        cin>>arr1[a];
                }

		for(int b = 0; b<tam; b++) {
                        cin>>arr2[b];
                }
 
                cout << "La mediana es: "<< mediana(0, tam-1, 0, tam-1) << endl;
               
                casos--;
        }
       
        return 0;              
}
