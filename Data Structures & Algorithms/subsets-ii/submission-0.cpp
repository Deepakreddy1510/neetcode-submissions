class Solution {
public:
    void Recur(vector<int>& nums,int index,vector<int>& current,vector<vector<int>>& ans){
        ans.push_back(current);

        for(int i=index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]){
                continue;
            }

            // take nums[i]
            current.push_back(nums[i]);
            Recur(nums,i+1,current,ans);
            // Backtrack
            current.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> current;
        Recur(nums,0,current,ans);
        return ans;
    }
};