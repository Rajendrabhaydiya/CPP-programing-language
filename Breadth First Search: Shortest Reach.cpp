#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 1<<30
class Graph {
    public:
        vector<vector<int> > adj;
        int V;
        Graph(int n) {
            adj = vector<vector<int> >(n , vector<int>());
            V = n;
        }
    
        void add_edge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> dist( V , INF );
            vector<bool> seen( V , false);
            queue<int> Q;
            dist[start] = 0;
            Q.push(start);
            seen[ start ] = true;
            while( !Q.empty() ){
                int current = Q.front(); Q.pop();
                for( int i = 0 ; i < adj[current].size() ; ++i ){
                    int neighbour = adj[current][i];
                    if( !seen[neighbour] && dist[ neighbour ] > dist[ current ] + 1 ){
                        dist[ neighbour ] = dist[ current ] + 1;
                        Q.push( neighbour );
                        seen[ neighbour ] = true;
                    }
                }
            }
            
            for( int i = 0 ; i <  V ; ++i ){
                if( i != start ){
                    if( dist[i] == INF ) dist[i] = -1;
                    else dist[i] *= 6;
                }
            }
            return dist;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
