  //Find Shortest Distance in Undirected Graph Using Simple BFS
vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();  // Number of vertices
    vector<int> dist(n, INT_MAX);  // Initialize distance array to infinity
    queue<int> q;
    
    dist[src] = 0;  // Distance to the source node is 0
    q.push(src);     // Push the source node into the queue
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto it : adj[node]) {  // Traverse all the neighbors of the current node
            if (dist[node] + 1 < dist[it]) {  // If a shorter path to the neighbor is found
                dist[it] = dist[node] + 1;  // Update the distance
                q.push(it);  // Push the neighbor into the queue for further processing
            }
        }
    }
    
    // Replace all the unreachable nodes (those with INT_MAX) with -1
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = -1;  // If not reachable, mark as -1
        }
    }
    
    return dist;  // Return the distances array
}
