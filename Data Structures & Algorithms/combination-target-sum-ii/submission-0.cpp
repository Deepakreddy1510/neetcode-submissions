class Solution {
public:
    void solve(vector<int>& candidates,int index,int remaining,vector<int>& current,vector<vector<int>>& ans){
        if(remaining == 0){
            ans.push_back(current);
            return;
        }

        for(int i=index; i < candidates.size(); i++){
            if(i > index && candidates[i] == candidates[i-1]){
                continue;
            }
            if(candidates[i] > remaining){
                break;
            }
            current.push_back(candidates[i]);
            solve(candidates,i+1,remaining-candidates[i],current,ans);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        solve(candidates,0,target,current,ans);
        return ans;
    }
};
