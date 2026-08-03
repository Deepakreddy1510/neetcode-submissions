class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        int left = 0;
        int right = n-1;
        while(left <= right){
            int num1 = numbers[left];
            int num2 = numbers[right];
            if(num1 + num2 == target){
                ans.push_back(left+1);
                ans.push_back(right+1);
                return ans;
            }
            else if(num1 + num2 > target){
                right--;
            }
            else{
                left++;
            }
        }
        return ans;
    }
};
