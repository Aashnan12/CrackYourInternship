class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int i=1,j=0;
        int n = arr.size();

        while(i<n){
            if(arr[i-1] == arr[i]){
                i++;
            }
            else{
                j++;
                arr[j] = arr[i];
                i++;
            }
        }
        return j+1;
    }
};