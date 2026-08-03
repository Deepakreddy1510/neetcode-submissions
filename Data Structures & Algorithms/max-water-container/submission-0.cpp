class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;
        int left = 0;
        int right = n-1;
        while(left < right){
            int water = (right - left) * min(heights[right],heights[left]);
            maxi = max(maxi, water);
            if(heights[left] <= heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxi;
    }
};
