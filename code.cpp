class Solution {
public:
unordered_map<string,vector<pair<string,double>>> graph;
    bool dfs(string src , string dst , unordered_set <string>&visited ,double &ans , double temp){
        if(src==dst){
            ans = temp;
            return true;
        }
        visited.insert(src);
        for(auto &val : graph[src]){
            string next = val.first;
            double weight = val.second;
            if(!visited.count(next)){
                if(dfs(next,dst,visited,ans,temp * weight)){
                    return true;
                }
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i=0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b,val});
            graph[b].push_back({a,1.0/val});
        }
        vector<double> ans1;
        for(auto & val : queries){
            string start = val[0];
            string end = val[1];
            if(!graph.count(start) || !graph.count(end)){
                ans1.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double ans = -1.0;
            dfs(start,end,visited,ans,1.0);
            ans1.push_back(ans);
        }
        return ans1;
    }
};
