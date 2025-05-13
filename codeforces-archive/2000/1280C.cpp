//Problem C. Jeremy Bearimy
//Contest: Codeforces Round 607 (Div. 1)

#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

/*void debug(int start){
    cout << start << "\n";
}*/

void dfs(int start, int parent, vector<vector<pair<int, ll> > > &adj, vector<ll> &s){
    //cout << "START AND PARENT:\n";
    /*debug(start);
    debug(parent);*/



    s[start] = 1;

    /*if(visited[start] == true){
        return;
    }

    visited[start] = true;*/

    for(auto neighbour: adj[start]){
        int neighbour_node = neighbour.first;
        //cout << "CHECK NEIGHBOUR:\n";
        //debug(neighbour_node);
        if(neighbour_node == parent){
            continue; //skip the parent nod
        }
        dfs(neighbour_node, start, adj, s);
        s[start] += s[neighbour_node];
    }
}


void solve(){
    ll n;
    cin >> n;
    vector<vector<pair<int,ll> > > adj(2*n);
    //vector<bool> visited(2*n - 1, false);
    //store the size of the subtrees connected to each node
    vector<ll> s(2*n);

    for(int i = 0; i<2*n-1; i++){
        ll a, b, weight;
        cin >> a >> b >> weight;
        a--;
        b--;
        adj[a].push_back(make_pair(b, weight));
        adj[b].push_back(make_pair(a, weight));
        //cout << "RECEIVED: " << a << " " << b << "\n";
    }


    dfs(0, -1, adj, s);

    /*for(int i = 0; i<s.size(); i++){
        cout << i << ": " << s[i] << "\n";
    }*/

    ll maxx = 0;
    ll minn = 0;

    //cout << "\n";
    for(int i = 0; i<adj.size(); i++){
        //cout << i << ": ";
        for(int j = 0; j<adj[i].size(); j++){
            //cout << adj[i][j].first << " ";
            //cout << "TESTING A AND B FOR: " << i << " " << adj[i][j].first << "\n";
            ll A = i;
            ll B = adj[i][j].first;
            //cout << A << " " << B << "\n";
            A = s[A];
            B = s[B];
            //cout << A << " " << B << "\n";

            ll times = min(A, B);
            times = min(times, 2*n - times);

            //cout << "Minimal Size of Connected Component: " << times << " " << 2*n-times << "\n";
            
           // times = min(times, 2*n - times);
            /*cout << "Weights: " << adj[i][j].second << "\n";*/
            maxx += times * adj[i][j].second;
            minn += (times%2) * adj[i][j].second;

            /*cout << "WE'RE ADDING: +" << times*adj[i][j].second << " and +" << (times%2) * adj[i][j].second << "\n";
            cout << "\n";*/
        }
        //cout << "\n";
    }

    cout << minn/2 << " " << maxx/2 << "\n";


}




int main(){
    ll T;
    cin >> T;

    for(int i = 0; i<T; i++){
        solve();
    }
}
