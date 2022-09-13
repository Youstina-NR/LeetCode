class Solution {
public:
    
   typedef pair<int, int> intPair;
    
    int V;
    list<intPair> *adj;
    
    int shortestPath(int src)
    {
        priority_queue< intPair, vector <intPair> , greater<intPair> > pq;
        
        vector<int> dist(V, INT_MAX);
        pq.push(make_pair(0, src));
        dist[src] = 0;
        while (!pq.empty())
        {
            
            int u = pq.top().second;
            pq.pop();

            
            list< pair<int, int> >::iterator i;
            
            for (i = adj[u].begin(); i != adj[u].end(); i++)
            {
                
                int v = (*i).first;
                int weight = (*i).second;
                
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
                
            }
        }
        int res = INT_MIN;
        for (int i = 1; i < V; i++)
        {
           
            if(dist[i] == INT_MAX )
                return -1;
            if(dist[i] > res)
                res = dist[i];
        }
        return res;
        
    }
    
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        V = n+1;
        adj = new list<intPair>[V];
        for(auto l : times)
        {
            adj[l[0]].push_back(make_pair(l[1],l[2]));
        }
        
        
        return shortestPath(k);
    }
    
    
};