// Problem: 1. Dreaming
// Contest: IOI 2013

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>

#include "dreaming.h"

/*
Global:

• PARENTS = vect. keeps track of parents
• COLORS =  vect. keeps of visited nodes
• DIST = (vect of pair<int, int>). NODE X -> DISTANCE TO ROOT
• ADJ = (vect of v<pair<int,int>>). adjacency list of the OG graph
• max_distance = ll. used to identify tree diameter
• ending_vertex = int. NODE WHERE DFS ENDS

*/
using namespace std;

using ll = long long int;

vector<bool> vis(1e6 + 5, false);
vector<int> parents(1e6 + 5, -1);
vector<int> colors(1e6 + 5, 0);
vector<pair<int, int> > dist(1e6+5);
vector<vector<pair<int, int> > > adj(1e6+100);
ll max_distance = -1;
int ending_vertex = -1;


/*void printDist(int n) {
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": Distance = " << dist[i].first << endl;
    }
}*/

void dfs(int vertex, int parent, int id){

    //cout << "ITERATION: " << vertex << "\n";
    //printDist(5);
    //cout << "\n";

    if(id == 2){
        vis[vertex] = true;
    }

    if(dist[vertex].first >= max_distance){
        max_distance = dist[vertex].first;
        ending_vertex = vertex;
    }

    for(auto neighbour: adj[vertex]){
        int next_vertex = neighbour.first;
        int travel_time = neighbour.second;

        if(next_vertex == parent){
            continue;
        }

        if(vis[next_vertex]){
            continue;
        }

        parents[next_vertex] = vertex;

        dist[next_vertex].first = dist[vertex].first + travel_time;
        
        //dist[next_vertex].first = dist[vertex].first + travel_time;
        dfs(next_vertex, vertex, id);
    }
}




int travelTime(int n, int m, int l, int A[], int B[], int T[]){

    for(int i = 0; i<m; i++){
        //converting everything to be a part of the adj data struct i know better
        int u = A[i];
        int v = B[i];
        int weight = T[i];

        pair<int, int> x;
        pair<int, int> y;
        x.first = v;
        x.second = weight;

        y.first = u;
        y.second = weight;
        adj[u].push_back(x);
        adj[v].push_back(y);
    }
    


    int R1 = -2e9+100;
    int R2 = -2e9+100;
    int R3 = -2e9+100;
    int D1 = -2e9+100;
    int radius = -1;

    vector<int> diameter;
    
    //int ctr = 0;

    for(int i = 0; i<n; i++){
        //ITERATING THROUGHOUT EACH VERTEX INSIDE THE GRAPH
        if(vis[i] == true){
            continue;
        }  
        //ctr++;

        dfs(i, -1, 1);

        //printDist(n);
        //cout << "STARTS AT: " << ending_vertex << "\n"; 

        parents[ending_vertex] = -1;
        dist[ending_vertex].first = 0;
        max_distance = -1;

        dfs(ending_vertex, -1, 2);

        //cout << "\n------\n";

        //cout << "ENDS AT: " << ending_vertex << "\n";
        //printDist(n);

        diameter.clear();

        int p = ending_vertex;
        
        diameter.push_back(p);

        int sum_of_diameter = dist[ending_vertex].first;
        while(p != -1){
            diameter.push_back(parents[p]);
            p = parents[p];
        }

        
        //extra -1 woopsie
        diameter.pop_back();

        //reverse to go from the actual start to end order that i just like idk
        reverse(diameter.begin(), diameter.end());

        radius = sum_of_diameter;
        int d_size = diameter.size();

        if(d_size==0){
            ending_vertex = colors[i];
        }

        /*cout << "MAIN ROOT OF 2ND DFS: " << ending_vertex << "\n";
        cout << "SUM OF DIAMETER: " << sum_of_diameter << "\n";
        cout << "TREE DIAMETER\n";*/

        D1 = max(D1, sum_of_diameter);

        /*for(int j = 0; j<diameter.size(); j++){
            cout << diameter[j] << " ";
        }
        cout << "\n";*/

        for(int j=0; j<diameter.size(); j++){
            int index = diameter[j];
            //cout << "COMPARING: " << radius << " AND THE MAXIMUM OF " << dist[index].first << " " << sum_of_diameter - dist[index].first << "\n";
            radius = min(radius, max(dist[index].first, sum_of_diameter - dist[index].first));
        }

        //cout << "RADIUS: " <<  radius  << "\n";

        if(radius > R1){
            R3 = R2;
            R2 = R1;
            R1 = radius;
        }
        else if(radius > R2){
            R3 = R2;
            R2 = radius;
        }
        else if(radius > R3){
            R3 = radius;
        }

        //cout  << "\n~~~~\n";
    }

    //cout << "TOP 3 MOST LARGEST OF RADII:\n";
    //cout << R1 << " " << R2 << " " << R3 << "\n";

    if(n-m == 1){
        return D1;
    }
    else if(n-m == 2){
        return max(D1, R1+R2+l);
    }
    else{
        return max(D1, max(R1+R2+l, R2+R3+ (2*l)));
    }


    //return 0;
}

/*int main(){
    
    n = # of vertices
    m = # of edges
    l = edge weight of new bridge
    A = 1st endpoint
    B = 2nd endpoint
    T = 1st and 2nd's edge weight
    //int n, m, l;
    //cin >> n >> m >> l;

    int A[n];
    int B[n];
    int T[n];

    for(int i =0; i<m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        A[i] = x;
        B[i] = y;
        T[i] = z;
    }

    cout << travelTime(n, m, l, A, B, T);
}*/
