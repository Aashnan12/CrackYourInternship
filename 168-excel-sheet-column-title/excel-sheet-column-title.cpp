class Solution {
public:
    string convertToTitle(int num) {
        string result = "";
        while(num > 0){
            num--;
            char ch = 'A' + (num%26);
            result = ch + result;
            num /= 26;
        }
        return result;
    }
};