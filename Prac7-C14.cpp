/*
Experiment 14 : There are flight paths between cities. If there is a flight between City A and City B then there is an edge between the cities. 
The cost of the edge can be the time that flight take to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph.
The node can be represented by the airport name or name of the city. Use adjacency list representation of the graph or use adjacency matrix representation of the graph.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter No. of cities";
    cin>>n;
    string cities[n];
    int adj[n][n] = {0,0};
    for(int i = 0; i<n; i++)
    {
        cout<<"Enter City Name "<<i<<endl;
        cin>>cities[i];
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n; j++)
        {
            cout<<"Enter Distance Between "<<cities[i]<<" and "<<cities[j]<<endl;
            cin>>adj[i][j];
            adj[j][i] = adj[i][j];
        }
    }

    //display
    cout<<endl;
    for(auto i : cities)
    {
        cout<<"\t"<<i<<"\t";
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<cities[i]<<"\t";
        for (int j = 0; j < n; j++)
        {
            cout<<"\t"<<adj[i][j]<<"\t";
        }
        cout<<endl;
    }
    
    return 0;
}