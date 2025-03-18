//Shorest Path in DAG using TopoSort  


// Function for topological sort using DFS
    void topoSort(vector<vector<pair<int, int>>>& adj, stack<int>& st, int start, vector<int>& visited) {
        visited[start] = 1;  // Mark the current node as visited
        
        // Visit all adjacent nodes
        for (auto it : adj[start]) {
            int dest = it.first;  // Get the destination node (it.first is the node)
            if (!visited[dest]) {
                topoSort(adj, st, dest, visited);  // Recursively call for the unvisited destination node
            }
        }
        
        // Push the node to the stack after visiting all its adjacent nodes
        st.push(start);
    }

public:
    // Function to find the shortest path in a directed acyclic graph (DAG)
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Build the graph
        vector<vector<pair<int, int>>> adj(V);  // Adjacency list (with destination node and weight)
        
        // Create the adjacency list from the edges
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];  // Starting node
            int v = edges[i][1];  // Ending node
            int wt = edges[i][2]; // Weight of the edge
            
            adj[u].push_back({v, wt});  // Add edge u -> v with weight wt
        }
        
        // Step 2: Topological Sort
        stack<int> st;
        vector<int> visited(V, 0);  // Initialize visited array
        
        // Perform topological sort for all unvisited nodes
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topoSort(adj, st, i, visited);  // Start DFS from unvisited node
            }
        }
        
        // Step 3: Initialize the distance array with INT_MAX (infinity)
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;  // Assuming node 0 as the source node
        
        // Step 4: Relax the edges in reverse topological order
        while (!st.empty()) {
            int node = st.top();  // Get the top node from stack
            st.pop();
            
            // Relax all edges from the current node
            for (auto it : adj[node]) {
                int v = it.first;  // Destination node
                int wt = it.second; // Weight of the edge
                
                // Update the distance if a shorter path is found
                if (dist[node] != INT_MAX && dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        
        // Replace INT_MAX with -1 for unreachable nodes
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;  // Mark unreachable nodes with -1
            }
        }

        // Return the shortest distances from the source node (node 0)
        return dist;
    }
