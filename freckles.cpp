/*
 * =====================================================================================
 *
 *       Filename:  freckles.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/16/2014 01:16:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jose Alberto Esquivel Patino (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class FreckleConnection
{
	private:
		int startFreckleIndex;
		int endFreckleIndex;
		double inkUsed;
	public:
		FreckleConnection();
		FreckleConnection(int startFreckleIndex, int endFreckleIndex, double inkUsed);

		int getStartFreckleIndex(){return startFreckleIndex;}
		int getEndFreckleIndex(){return endFreckleIndex;}
		double getInkUsed(){return inkUsed;}
		friend bool operator<(const FreckleConnection& f1, const FreckleConnection& f2);
};

FreckleConnection::FreckleConnection(int start, int end, double ink)
{
	startFreckleIndex = start;
	endFreckleIndex = end;
	inkUsed = ink;
}

bool operator<(const FreckleConnection& f1, const FreckleConnection& f2)
{
	return (f1.getInkUsed() < f2.getInkUsed()) ? true : false; 
}

double calculateInk(double x1, double y1, double x2, double y2)
{
	return sqrt( pow((y2 - y1), 2) + pow((x2 - x1), 2) );
}
double calculateMinimumAmountOfInk(double *frecklesX, double *frecklesY, int numFreckles)
{
	priority_queue<FreckleConnection> connections;
	bool *isConnected = new bool[numFreckles];
	for (int i = 0; i < numFreckles; i++) {
		isConnected[i] = false;
	}
	int start = 0; //index of the freckle to start with
	int end; 
	double ink;
	for (int i = 1; i < numFreckles; i++) {
		ink = calculateInk(frecklesX[start], frecklesY[start], frecklesX[i], frecklesY[i]);		
		end = i;
		FreckleConnection newConnection(start, end, ink);
		connections.push(newConnection);
	}
	isConnected[0] = true;

	double totalInk = 0;
	while (!connections.empty())
	{
		end = connections.top().getEndFreckleIndex();
		//reviso que la destination no este visitada
		if (!isConnected[end]) {
			//conecto la freckle
			isConnected[end] = true;
			//sumo la tinta usada para esto
			ink = connections.top().getInkUsed();
			totalInk += ink;

			//agrego el resto de las conexiones desde start
			start = connections.top().getStartFreckleIndex();
			for (int i = 0; i < numFreckles; i++) {
				if (!isConnected[i])
				{
					ink = calculateInk(frecklesX[start], frecklesY[start], frecklesX[i], frecklesY[i]);		
					end = i;
					FreckleConnection newConnection(start, end, ink);
					connections.push(newConnection);
				}
			}
		}
		connections.pop();
	}	
	return totalInk;
	
}
int main(int argc, const char *argv[])
{
	int cases, numFreckles; 
	double *frecklesX, *frecklesY;
	cin >> cases; 
	while(cases > 0) 
	{
		cin >> numFreckles;
		frecklesX = new double[numFreckles];
		frecklesY = new double[numFreckles];
		for (int i = 0; i < numFreckles; i++) {
			cin >> frecklesX[i] >> frecklesY[i];
		}
		cout << "Minimum: " <<calculateMinimumAmountOfInk(frecklesX, frecklesY, numFreckles) << endl;
		cases--;
	}
	return 0;
}


