class Solution {
public:
    list<int> *adj;
    int V;
    
    vector<vector<int>> res;
    
    void bridgeUtil(int u, bool visited[], int disc[], int low[], int parent[])
    {
        
        static int time = 0;
     
        visited[u] = true;
     
        disc[u] = low[u] = ++time;
     
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = *i;  
     
            if (!visited[v])
            {
                parent[v] = u;
                bridgeUtil(v, visited, disc, low, parent);
     
                low[u]  = min(low[u], low[v]);
     
                if (low[v] > disc[u])
                {  
                    res.push_back({u,v});
                }
            }
     
            
            else if (v != parent[u])
                low[u]  = min(low[u], disc[v]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if(connections.size() <=2 )
            return connections;
        
        V = n;
        adj = new list<int>[V];
        
        for(auto L : connections)
        {
            adj[L[0]].push_back(L[1]);
            adj[L[1]].push_back(L[0]);
        }
        
        bool visited[V];
        int *disc = new int[V];
        int *low = new int[V];
        int parent[V];
        
        memset(visited,false,sizeof(visited));
        memset(parent,-1,sizeof(parent));
        
        
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                bridgeUtil(i, visited, disc, low, parent);
        return res;
    }
};