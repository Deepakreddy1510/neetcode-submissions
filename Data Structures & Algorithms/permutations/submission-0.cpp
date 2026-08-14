class Solution {
public:
    void Recur(vector<int>& nums,vector<bool>& used,vector<int>& current,vector<vector<int>>& ans){
        if(current.size() == nums.size()){
            ans.push_back(current);
            return;
        }

        for(int i=0; i < nums.size(); i++){
            if(used[i] == true){
                continue;
            }
            // take nums[i]
            current.push_back(nums[i]);
            used[i] = true;
            Recur(nums,used,current,ans);
            used[i] = false;
            current.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(),false);

        Recur(nums,used,current,ans);
        return ans;
    }
};
