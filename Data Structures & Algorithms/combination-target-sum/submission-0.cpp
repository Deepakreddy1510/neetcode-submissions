class Solution {
public:
    void solve(vector<int>& nums,int index,int remaining,vector<int>& current,vector<vector<int>>& ans){
        if(remaining == 0){
            ans.push_back(current);
            return;
        }
        if(remaining < 0 || index == nums.size()){
            return;
        }

        if(nums[index] <= remaining){
            current.push_back(nums[index]);
            solve(nums,index,remaining-nums[index],current,ans);
            current.pop_back();
        }

        solve(nums,index+1,remaining,current,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(nums,0,target,current,ans);
        return ans;
    }
};
