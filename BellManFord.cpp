  /*
       We'll run the loop for V-1 time becuase bellman ford says run the loop 
       for v-1 time and you will eventually arive at your answer
       
       IMPORTANT
       to find the loop we will run one more time the loop after runing v-1 time 
       if any changes happen to our distance array that means there is a negative weight cycle
       
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        
        vector<int>dist(V,1e8); //first all the distance are infinite 
        dist[src] = 0;         //mark the source distance as 0
        for(int count = 1; count <= V-1; count++){  
            for(auto &edge : edges){
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        
        //To detect a negative cycle
        
        for(auto &edge : edges){
            int u  = edge[0];
            int v = edge[1];
            int wt = edge[2];
            
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        
       return dist; 
    }
