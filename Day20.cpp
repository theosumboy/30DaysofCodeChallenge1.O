class Solution {
public:
    //solver
    #define graph unordered_map<string,vector<pair<string,double>>> 

    double solve(string src,string dest,graph map,unordered_map<string,bool> &vis){
        vis[src] = true;
        if(src == dest) return 1.0000;
        
        double res = -1.00;
        for(auto ch : map[src]){
            double temp = -1.0;
            if(!vis[ch.first]) temp = solve(ch.first,dest,map,vis);
            if(temp != -1.0) res = temp * ch.second;
        }
        return res;
    }
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& quer) {
        unordered_map<string,vector<pair<string,double>>> map;
        int n = eq.size();
        //creation of graph
        for(int i=0;i<n;i++){
            pair<string,double> p1,p2;
            p1 = {eq[i][1],val[i]};
            p2 = {eq[i][0],1.0/val[i]};
            map[eq[i][0]].push_back(p1);
            map[eq[i][1]].push_back(p2);
        }
        vector<double> res;
        for(auto qr : quer){
            unordered_map<string,bool> vis;
            if(map.find(qr[0]) == map.end()) res.push_back(-1.0000);
            else{
                double t = solve(qr[0],qr[1],map,vis);
                res.push_back(t);
                
            }
        }
        return res;
    }
};
