//Problem E. Tree and Hamiltonian Path 2
//Contest: AtCoder Beginner Contest 361 (Denso Create Programming Contest 2024)

#include <bits/stdc++.h>


using namespace std;


/* How to Memorize a DFS:
1. VISITED ALREADY — If the current_node has been visited already, return nothing.
2. VISIT *IT* ALREADY – You visit the current node and update to true.
3. */


void dfs(int current_node, long long int current_distance, long long int &max_distance, int &ending, vector<vector<pair<int, int> > > &adj, vector<bool> &visited){

    if (visited[current_node] == true){
        return;
    }

    visited[current_node] = true;

    if(current_distance > max_distance){
       // max_distance = max(max_distance, current_distance);
       max_distance = current_distance;
       ending = current_node;

    }
   // max_distance = max(max_distance, current_distance);



    /*for(auto neighbour: adj[current_node]){
        dfs(neighbour, adj, visited_already);
    }*/

    for(int i = 0; i<adj[current_node].size(); i++){
        int neighbour = adj[current_node][i].first; //note that first is the endpoint of the edge
        int weight = adj[current_node][i].second;
       // cout << "\tboom!\n";
       // cout << "FROM " << current_node << " TO " << neighbour << ", WHICH HAS A WEIGHT OF " << weight << "\n"; 
       // cout << "Total Weight Right Now: " << current_distance + weight << "\n";
        
        dfs(neighbour, current_distance + weight, max_distance, ending, adj, visited);
    }
}



int main(){
    int N;
    cin >> N;

    long long int edge_sum = 0;

    vector<vector<pair<int, int> > > adj (N);
    vector<bool> visited (N, false);

    for(int i = 0; i<N-1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edge_sum += c;
        
        adj[b].push_back(make_pair(a,c));
        adj[a].push_back(make_pair(b,c));
    }

    long long int max_distance = 0;
    int ending = 0;
    dfs(0, 0, max_distance, ending, adj, visited);


    /*cout << "\nending_node: " << ending << "\n";
    cout << "max_distance: " << max_distance << "\n";*/
    max_distance = 0;
    int ending2 = 0;

    fill(visited.begin(), visited.end(), false);

   // cout << "\nlet's see if this DFS is even running \n";
    dfs(ending, 0, max_distance, ending2, adj, visited);

   // cout << "EDGE " << ending << " –> " << ending2 << " GIVES A FINALIZED DIAMETER OF " << max_distance << "\n"; 

    cout << 2*edge_sum - max_distance << "\n";

    
}