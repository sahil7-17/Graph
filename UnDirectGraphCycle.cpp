 // Function to detect cycle in an undirected graph Using BFS.
     bool detect(int src, vector<vector<int>>&adj,int visited[]){
         
         visited[src] = 1;
         queue<pair<int,int>>q;
         q.push({src,-1});
         while(!q.empty()){
             int node = q.front().first;
             int parent = q.front().second;
             
             q.pop();
             for(auto adjacent : adj[node]){
                 if(!visited[adjacent]){
                     visited[adjacent] = 1;
                     q.push({adjacent,node});
                 }
                 else if(parent != adjacent){
                     return true;
                 }
             }
         }
         return false;
     }
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        int visited[v] = {0};
        
        for(int i= 0;  i<v; i++){
            if(!visited[i]){
                if(detect(i,adj,visited)) return true;
            }
        }
        return false;
        
    }
