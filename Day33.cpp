class Solution {
    int maximumDetonationHelp(int node, vector<int> &vis, vector<vector<int>> &adj){
        vis[node] = 1;
        int cnt = 1;

        for(auto nbr : adj[node]){
            if(!vis[nbr]) cnt += maximumDetonationHelp(nbr, vis, adj);
        }
        return cnt;
    }
public:
    int maximumDetonation(vector<vector<int>>& bs) {
        int n = bs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                long long r2 = pow(bs[i][0] - bs[j][0], 2) + pow(bs[i][1] - bs[j][1], 2);
                if( r2 <= pow(bs[i][2], 2) ) adj[i].push_back(j);
                if( r2 <= pow(bs[j][2], 2) ) adj[j].push_back(i);
            }
        }

        int maxi = 0;
        for(int i=0; i<n; i++){
            vector<int> vis(n, 0);
            maxi = max(maxi, maximumDetonationHelp(i, vis, adj));
        }
        return maxi;
    }
};
