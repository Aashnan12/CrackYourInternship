class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int sum = 0;
        int i = a.size()-1;
        int j = b.size()-1;

        while(i>=0 || j>=0 || sum){
            if(i>=0){
                sum += a[i--] - '0';
            }
            if(j>=0){
                sum += b[j--] - '0';
            }
            result += (sum % 2) + '0';
            sum = sum/2;
        }
        reverse(result.begin(),result.end());
        return result;
    }
};