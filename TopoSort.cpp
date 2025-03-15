class Solution {

  private:
  // DFS function to perform depth-first traversal and push nodes to stack in reverse topological order
  void dfs(vector<vector<int>>& adj, vector<int>& visited, int start, stack<int>& st) {
      visited[start] = 1; // Mark the current node as visited
    
      // Ab har adjacent node ko visit karo
      for(auto it : adj[start]){
          if(!visited[it]){  // Agar node visited nahi hai toh DFS call karo
              dfs(adj, visited, it, st);
          }
      }
      st.push(start); // Jab saare neighbors visit ho jaayein, node ko stack me daal do
  }

  public:
    // Function to return list containing vertices in Topological order
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int v = adj.size(); // Number of vertices
        vector<int> visited(v, 0); // Visited array to track visited nodes
        stack<int> st; // Stack to store the topologically sorted nodes
        
        // Har node ke liye DFS call karo agar node visited nahi hai
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                dfs(adj, visited, i, st); // DFS call for unvisited node
            }
        }
        
        // Stack me stored nodes ko reverse kar ke final answer me daalna hai
        vector<int> ans;
        while(!st.empty()){
            int node = st.top(); // Get the top node from stack
            ans.push_back(node); // Add it to the result vector
            st.pop(); // Remove the node from the stack
        }
        
        return ans; // Return the final topologically sorted order
    }
};

