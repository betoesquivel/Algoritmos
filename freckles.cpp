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
#include <iomanip>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

bool debug = false;

class FreckleConnection
{
	private:
		int startFreckleIndex;
		int endFreckleIndex;
		double inkUsed;
	public:
		FreckleConnection();
		FreckleConnection(int startFreckleIndex, int endFreckleIndex, double inkUsed);

		int getStartFreckleIndex()const {return startFreckleIndex;}
		int getEndFreckleIndex()const {return endFreckleIndex;}
		double getInkUsed()const {return inkUsed;}
		bool operator>(/* const FreckleConnection& f1,  */const FreckleConnection& f2)const
		{
			if (debug) {
				cout << " Comparison of " <<inkUsed<<'>' <<f2.getInkUsed() <<endl;
				cout << (getInkUsed() > f2.getInkUsed()) <<endl;
			}
			return getInkUsed() > f2.getInkUsed() ; 
		}
		bool operator<(/* const FreckleConnection& f1,  */const FreckleConnection& f2)const
		{
			if (debug) {
				cout << " Comparison of " <<inkUsed<<'<' <<f2.getInkUsed() <<endl;
				cout << (getInkUsed() < f2.getInkUsed()) <<endl;
			}
			return getInkUsed() < f2.getInkUsed() ; 
		}
		friend ostream &operator<<(ostream &out, FreckleConnection f1)
		{
			out<<"start: " <<f1.getStartFreckleIndex()<<endl;
			out<<"end: " <<f1.getEndFreckleIndex()<<endl;
			out<<"ink: " <<f1.getInkUsed()<<endl;
			return out; 
		}			
		// friend bool operator>(const FreckleConnection& f1, const FreckleConnection& f2);
		// friend bool operator<(const FreckleConnection& f1, const FreckleConnection& f2);
};


FreckleConnection::FreckleConnection(int start, int end, double ink)
{
	startFreckleIndex = start;
	endFreckleIndex = end;
	inkUsed = ink;
}

void printAllConnections(priority_queue<FreckleConnection, vector<FreckleConnection>, greater<FreckleConnection> >q)
{
	priority_queue<FreckleConnection, vector<FreckleConnection>, greater<FreckleConnection> > newPQ = q; 
	cout<<"QUEUE::"<<endl;
	while (!newPQ.empty())
	{
		cout<<newPQ.top()<<endl;
		newPQ.pop();
	}
}

// struct lessThanByInk
// {
// 
// 	bool operator<(const FreckleConnection& f1, const FreckleConnection& f2)const
// 	{
// 		return f1.getInkUsed() < f2.getInkUsed() ; 
// 	}
// 
// };
// 
// struct greaterThanByInk
// {
// 
// 	bool operator>(const FreckleConnection& f1, const FreckleConnection& f2)const
// 	{
// 		return f1.getInkUsed() > f2.getInkUsed() ; 
// 	}
// 
// };
double calculateInk(double x1, double y1, double x2, double y2)
{
	return sqrt( pow((y2 - y1), 2) + pow((x2 - x1), 2) );
}
double calculateMinimumAmountOfInk(double *frecklesX, double *frecklesY, int numFreckles)
{
	priority_queue< FreckleConnection, vector<FreckleConnection>, greater<FreckleConnection> > connections;
	bool *isConnected = new bool[numFreckles];
	for (int i = 0; i < numFreckles; i++) {
		isConnected[i] = false;
	}
	int start = 0; //index of the freckle to start with
	int end; 
	double ink;
	for (int i = 1; i < numFreckles; i++) {
		end = i;
		ink = calculateInk(frecklesX[start], frecklesY[start], frecklesX[end], frecklesY[end]);		
		FreckleConnection newConnection(start, end, ink);
		connections.push(newConnection);
	}
	isConnected[0] = true;

	double totalInk = 0;
	while (!connections.empty())
	{
		start = connections.top().getStartFreckleIndex();
		end = connections.top().getEndFreckleIndex();
		ink = connections.top().getInkUsed();
		if (debug) {
			printAllConnections(connections);
		}
		//reviso que la destination no este visitada
		if (!isConnected[end]) {
			//conecto la freckle
			isConnected[end] = true;
			//sumo la tinta usada para esto
			totalInk += ink;
			if (debug) {
				cout << "MINIMUM not connected " <<start<<endl;
				cout << "start: " <<start<<endl;
				cout << "end: " <<end<<endl;
				cout << "ink: " <<ink<<endl;
			}

			//saco la conexion
			connections.pop();

			//agrego las conexiones del nuevo lugar al que llegue
			start = end; 
			//agrego el resto de las conexiones desde start
			for (int i = 0; i < numFreckles; i++) {
				if (!isConnected[i])
				{
					ink = calculateInk(frecklesX[start], frecklesY[start], frecklesX[i], frecklesY[i]);		
					end = i;
					FreckleConnection newConnection(start, end, ink);
					connections.push(newConnection);
				}
			}
		}else
		{
			connections.pop();
		}
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
		cout << fixed << setprecision(2);
		cout << calculateMinimumAmountOfInk(frecklesX, frecklesY, numFreckles) << endl;
		delete [] frecklesX;
		delete [] frecklesY;
		cases--;
	}
	return 0;
}


