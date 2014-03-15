/*
 * =====================================================================================
 *
 *       Filename:  Investment.cpp
 *
 *    Description:  investmen tutoring247mty problem
 *
 *        Version:  1.0
 *        Created:  14/03/14 13:09:45
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jose Alberto Esquivel Patino A01139626
 *         Author2: Hugo Leon Garza A01139720
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;

int pricePerDay[100];//contains the price of the object to sell every day
int days; 
bool debug = false;

//returns which of the 3 numbers is greater
int greaterNum (int n1, int n2, int n3) {
	int greaterIndex = 1; 
	int g = n1; 
	if (n2 > n1) {
		g = n2; 
		greaterIndex = 2; 
	}
	if (n3 > g) {
		g = n3;
		greaterIndex = 3; 
	}

	if (debug) {
		cout<<"Calcule el mayor de: "<<n1<<' '<<n2<<' '<<n3<<endl;
		cout<<"Mayor = "<<g<<' '<<greaterIndex<<endl;
	}
	return greaterIndex; 
}

//inf y sup son los indices inferior y superior del arreglo 
//min y max son los indices del minimo y el maximo
void bestInvestment(int inf, int sup, int *min, int *max) {
	int size = sup - inf + 1; 
	int min1, max1, min2, max2; //buying and selling day from both halves
	if (size > 2) {
		int pivot = (inf + sup) / 2; 
		bestInvestment (inf, pivot-1, &min1, &max1); 
		bestInvestment (pivot, sup, &min2, &max2); 

		//modifico las variables min y max (son mis valores de retorno)
		int dif1, dif2, dif3; 
		dif1 = pricePerDay[max1] - pricePerDay[min1]; 
		dif2 = pricePerDay[max2] - pricePerDay[min2]; 
		dif3 = pricePerDay[min2] - pricePerDay[max1]; 
		int greaterDif = greaterNum(dif1, dif2, dif3);
		switch (greaterDif){
			case 1: 				
				*min = min1; 
				*max = max1; 
				//checo si el max puede ser uno de los otros
				*max = (pricePerDay[min2] >= pricePerDay[*max]) ? min2:*max; 
				*max = (pricePerDay[max2] >= pricePerDay[*max]) ? max2:*max; 
				break;
			case 2:
				*min = min2; 
				*max = max2; 
				//checo si el min puede ser uno de los otros
				*min = (pricePerDay[max1] <= pricePerDay[*min]) ? max1:*min; 
				*min = (pricePerDay[min1] <= pricePerDay[*min]) ? min1:*min; 
				break;
			case 3:
				*min = max1; 
				*max = min2; 
				//checo si mi min y mi max pueden ser los otros
				*min = (pricePerDay[min1] <= pricePerDay[*min]) ? min1:*min;
				*max = (pricePerDay[max2] >= pricePerDay[*max]) ? max2:*max; 
				break;
		}
	}else {
		//es menor o igual a 2
		if (size == 1) {
			*min = *max = inf; 
		}else{
			*min = inf; 
			*max = sup;
		}
	}
}

int main(int argc, const char *argv[])
{
	int cases; 
	cin >> cases; 

	int count = 0;
	int buyingDay, sellingDay; 
	int inf, sup;
	//me falta definir los valores iniciales
	//
	while (count < cases) {
		cin >> days;
		//lleno la lista de precios. 
		int i = 0; 
		while( i < days )
		{
			cin >> pricePerDay[i];
			i++;
		}

		inf = 0;
		sup = days - 1;

		//obtengo buyingDay y sellingDay enviandolos como ref
		bestInvestment (inf, sup, &buyingDay, &sellingDay); 
		buyingDay++; sellingDay++;
		cout<< "Buy in " << buyingDay << ", sell in " << sellingDay << endl;
		
		count++;		
	}
	
		
	return 0;
}

