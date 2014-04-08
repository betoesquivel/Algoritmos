#include <iostream>

using namespace std;

/*
 * 
 * Análisis y Diseño de Algoritmos
 * Profesor: Luis Humberto Gonzalez
 * Proyecto 2
 * Problema Railroad
 * Programación Dinámica
 * 
 * José Alberto Esquivel Patiño		A01139626
 * Hugo León Garza					A01139720
 * 
 */

bool mat[2005][2005];
int t1[1005];
int t2[1005];
int orden[2005];

int main() {
	
	mat[0][0] = true;
	
	int n1, n2;
	cin>>n1>>n2;
	
	while(n1 != 0 && n2 != 0) {
		
		for(int i=0; i<n1; i++) {
			cin>>t1[i];
		}
		
		for(int i=0; i<n2; i++) {
			cin>>t2[i];
		}
		
		for(int i=0; i<n1+n2; i++) {
			cin>>orden[i];
		}
		
		for(int i=1; i<=n1; i++) {
			mat[0][i] = mat[0][i-1] && ( t1[i-1] == orden[i-1] );
		}
		
		for(int j=1; j<=n2; j++) {
			mat[j][0] = mat[j-1][0] && ( t2[j-1] == orden[j-1] );
		}
		
		// Aquí se realiza el llenado de la matriz
		// "i" es para renglones
		// "j" es para columnas
		for(int j=1; j<=n1+n2; j++) {
			
			for(int i=1; i<=n1+n2; i++){
				mat[j][i] = ( mat[j][i-1] && ( t1[i-1] == orden[i+j-1] ) )	||	( mat[j-1][i] && ( t2[j-1] == orden[i+j-1] ) );
			}
			
		}
		
		// /*
		for(int j=0; j<=n1+n2; j++) {
			
			for(int i=0; i<=n1+n2; i++) {
				cout<<mat[j][i];
			}
			cout<<endl;
		}
		// */
		
		if(mat[n1][n2])
			cout<<"possible"<<endl;
		else 
			cout<<"not possible"<<endl;
		
		
		cin>>n1>>n2;
	}



	return 0;	
}
