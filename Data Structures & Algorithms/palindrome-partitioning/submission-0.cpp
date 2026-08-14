class Solution {
public:
    bool isPalindrome(string s){
        int n = s.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void Recur(string s,int index,vector<string>& current,vector<vector<string>>& ans){
        if(index == s.size()){
            ans.push_back(current);
            return;
        }

        for(int i=index; i < s.size(); i++){

            string temp = s.substr(index,i - index + 1);
            if(isPalindrome(temp)){
                current.push_back(temp);
                Recur(s,i+1,current,ans);
                current.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        Recur(s,0,current,ans);
        return ans;
    }
};
