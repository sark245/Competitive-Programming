class Solution {
public:
    vector<bool> vis;
    int n;
    vector<vector<int>> res, g;
    void dfs(int v, vector<int>& path){
        path.push_back(v);
        if(v == n-1){
            res.push_back(path);
        }
        
        vis[v] = true;
        for(auto to : g[v]){
            if(!vis[to]){
                dfs(to, path);
            }
        }
        
        vis[v] = false;
        path.pop_back();
              
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        g = graph;
        n = g.size();
        vis.resize(n, false);
        
        vector<int> path;
        dfs(0, path);
        return res;
    }
};
