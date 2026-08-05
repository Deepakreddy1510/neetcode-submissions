class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> mpp(256,-1);

        int left = 0;
        int right = 0;
        int maxlen = 0;

        while(right < n){
            if(mpp[s[right]] != -1){
                if(mpp[s[right]] >= left){
                    left = mpp[s[right]] + 1;
                }
            }
            mpp[s[right]] = right;
            int len = right - left + 1;
            maxlen = max(maxlen, len);
            right ++;
        }

        return maxlen;
    }
};
