/*
 * =====================================================================================
 *
 *       Filename:  RockyTheBeagle.cpp
 *
 *    Description:  Rocky the beagle in tutoring247
 *
 *        Version:  1.0
 *        Created:  24/03/14 16:08:27
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jose Alberto Esquivel Patino (), 
 *   Organization:  ITESM Campus Monterrey
 *
 * =====================================================================================
 */

// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
 
#include <stdio.h>
#include <iostream>
#include <limits.h>
 
// Number of vertices in the graph
#define V 50
 
using namespace std;

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
 
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
 
   return min_index;
}
 
// A utility function to print the constructed distance array
void printSolution(int dist[], int n)
{
   printf("Vertex   Distance from Source\n");
   for (int i = 0; i < V; i++)
      printf("%d \t\t %d\n", i, dist[i]);
}
 
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
int dijkstraMaxShortestPath(int graph[V][V], int src, int nodes)
{
     int dist[nodes];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
 
     bool sptSet[nodes]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
 
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < nodes; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
 
     // The biggest shortest path for the beagle starts being the source
     int maxShortestPath = src;

     // Find shortest path for all vertices
     for (int count = 0; count < nodes-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
 
       // Mark the picked vertex as processed
       sptSet[u] = true;
 
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < nodes; v++)
 
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v]){
		    dist[v] = dist[u] + graph[u][v];
		    maxShortestPath = (dist[v] > dist[maxShortestPath]) ? v:maxShortestPath;
	 }
     }
 
     // print the constructed distance array
     printSolution(dist, nodes);
     return maxShortestPath; 
}
 
// driver program to test above function
int main()
{
   int cases; 
   int count = 0;
   char X, Y;
   int  c; 
   int n, k; 
   int graph[V][V] ;
   cin >> cases; 
   while (count < cases) {
   	cin >> n >> k; 
	int i = 0;
	while (i < k) {
		cin >> X >> Y >> c; 
		graph[X - 'A'][Y - 'A'] = c; 	
		i++;		
	}
   	
        cout << "Case " << count + 1 << ": " << (char) ('A' + dijkstraMaxShortestPath(graph, 0, n)) << endl;
   	count++;		
   }
   /* Let us create the example graph discussed above */
                   
 
    return 0;
}