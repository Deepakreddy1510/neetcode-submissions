class Solution {
public:
    int climbStairsRec(int i,vector<int>& dp){
        if(dp[i] != -1){
            return dp[i];
        }
        return dp[i] = climbStairsRec(i-1,dp) + climbStairsRec(i-2,dp);
    }
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        vector<int>dp(n+1,-1);
        dp[1] = 1;
        dp[2] = 2;
        return climbStairsRec(n,dp);
    }
};
