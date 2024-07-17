class Solution {
public:
    void solve(vector<string>& result,string& temp,int open,int close,int n){
        if(temp.size() == 2*n){
            result.push_back(temp);
            return;
        }

        if(open < n){
            temp.push_back('(');
            solve(result,temp,open+1,close,n);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            solve(result,temp,open,close+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp;
        solve(result,temp,0,0,n);
        return result;
    }
};