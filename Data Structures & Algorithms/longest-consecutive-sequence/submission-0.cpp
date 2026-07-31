class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int maxlen = 0;

        for(int num:st){
            if(!st.count(num-1)){
                int curr = num;
                int len = 1;
                
                while(st.count(curr+1)){
                    curr++;
                    len++;
                }
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};
