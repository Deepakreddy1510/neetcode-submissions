class Solution {
public:
    void Recur(string& current,int open,int close,vector<string>& ans,int n){
        if(open == n && close == n){
            ans.push_back(current);
            return;
        }

        if(open < n){
            current.push_back('(');
            Recur(current,open+1,close,ans,n);
            current.pop_back();
        }

        if(open > close){
            current.push_back(')');
            Recur(current,open,close+1,ans,n);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string current;
        Recur(current,0,0,ans,n);
        return ans;
    }
};
