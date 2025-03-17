  vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
  int n = adj.size();
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair
  <int,int>>>pq;    //Min heap to store the {dist,node}
  
  vector<int>result(n,INT_MAX);
  result[src] = 0;      //Mark the source as distance 0 
  pq.push({0,src});   //Push the source with distance 0 because from source to source the distance will be 0 
  
  while(!pq.empty()){   //
      int dist = pq.top().first;    //distance
      int node = pq.top().second;   //Weight
      
      pq.pop();
      
      for(auto it : adj[node]){   //Traverse the neighbours
          int adjNode = it.first;  //Neighbour node 
          int wt = it.second;      //Weeoght of the neighbour node 
          
          if(dist + wt < result[adjNode]){   // if weight of the node and weight of the neighbour node is less than the result[adjNode] that was INT_MAX earlier then upadte the node 
              result[adjNode] = dist+wt;
              pq.push({dist+wt,adjNode});
          }
      }
  }
  return result;
 
 
        
        
        
