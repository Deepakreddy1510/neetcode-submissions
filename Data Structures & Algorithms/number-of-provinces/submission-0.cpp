class Solution {
public:
    void bfs(int start,vector<vector<int>>& adj,vector<int>& vis){
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0; i < adj[node].size();i++){
                if(!vis[i] && adj[node][i] == 1){
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int provinces = 0;
        vector<int> vis(n);

        for(int i=0; i < n; i++){
            if(!vis[i]){
                bfs(i,isConnected,vis);
                provinces++;
            }
        }
        return provinces;
    }
};