class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i=0; i < n; i++){
            if(mp.find(nums[i]) == mp.end()){
                mp[nums[i]] = 1;
            }
            else{
                mp[nums[i]] += 1;
            }
        }
        vector<pair<int,int>> vec(mp.begin(),mp.end());

        sort(vec.begin(), vec.end(),
            [](const auto &a,const auto &b){
                return a.second > b.second;
            });

        for(auto &p: vec){
            if(k == 0) break;
            ans.push_back(p.first);
            k--;
        }
        return ans;
    }
};
