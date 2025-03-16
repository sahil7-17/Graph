vector<int> topologicalSort(vector<vector<int>>& adj) {
    int v = adj.size();  // Graph mein total vertices (nodes) ki sankhya nikaalo
    
    vector<int> inDegree(v);  // Har node ka in-degree (incoming edges) track karne ke liye vector
    queue<int> q;  // Nodes ko process karne ke liye queue
    
    // Step 1: Har node ke liye in-degree calculate karo
    for(int i = 0; i < v; i++){
        for(auto it : adj[i]){  // Adjacent nodes ke liye loop
            inDegree[it]++;  // Us node ka in-degree badhao
        }
    }
    
    // Step 2: Jitne bhi nodes ka in-degree 0 hai, unhe queue mein daalo
    for(int i = 0; i < v; i++){
        if(inDegree[i] == 0){  // Agar node ka in-degree 0 hai
            q.push(i);  // To us node ko queue mein daal do, kyunki yeh node pehle process hoga
        }
    }
    
    vector<int> topo;  // Topological sort ka result store karne ke liye vector
    
    // Step 3: Queue mein se ek node nikaalo aur usse process karo
    while(!q.empty()){
        int node = q.front();  // Queue se node nikaalo
        q.pop();  // Us node ko queue se hatao
        
        topo.push_back(node);  // Is node ko result mein add karo
        
        // Us node ke saare neighbors ko process karo
        for(auto it : adj[node]){
            inDegree[it]--;  // Us neighbor ka in-degree kam karo
            if(inDegree[it] == 0){  // Agar uska in-degree 0 ho jaye
                q.push(it);  // To us node ko queue mein daal do
            }
        }
    }
    
    return topo;  // Final topological sort return karo
