#include<bits/stdc++.h>
using namespace std;

void DFS(int i, vector<vector<int>>& g, vector<bool>& visited) {
    if(visited[i]) return;
    visited[i] = true;
    for(int x: g[i]) DFS(x, g, visited);
}

int main() {

    int n, m; cin >> n >> m;
    vector< vector<int> > graph1 (n+1), graph2 (n+1);
    vector<bool> visited1 (n+1), visited2 (n+1);

    for(int i = 0; i<m; i++) {
        int a,b;
        cin >> a>> b;
        graph1[a].push_back(b);
        graph2[b].push_back(a);
    }


    DFS(1, graph1, visited1);
    DFS(1, graph2, visited2);

//     for(int i=0; i<=n; i++) cout<<visited1[i]<<" ";
//    cout<<endl;
//    for(int i=0; i<=n; i++) cout<<visited2[i]<<" ";
//    cout<<endl;
    for(int i = 2; i<=n; i++) {
        if(!visited1[i]) {
            cout << "NO\n1 " << i;
            return 0;
        }
    }

    for(int i = 2; i<=n; i++) {
        if(!visited2[i]) {
            cout << "NO\n" << i << " 1";
            return 0;
        }
    }

    cout << "YES";
}
