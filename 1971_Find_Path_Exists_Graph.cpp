// My approach but chatGPT coded and not optimal solution

class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    bool dfs(int curr, int destination) {
        if (curr == destination) return true;

        visited[curr] = true;

        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, destination)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {

        adj.resize(n);
        visited.resize(n, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return dfs(source, destination);
    }
};






// Leetcode optimal solution

class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n);
        
        for (int i = 0; i < n; i++)
            parent[i] = i;
        
        for (auto &edge : edges) {
            int root1 = find(edge[0], parent);
            int root2 = find(edge[1], parent);
            
            if (root1 != root2)
                parent[root1] = root2;
        }
        
        return find(source, parent) == find(destination, parent);
    }
};