class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.first == b.first) return a.first > b.first;
        return a.first < b.first;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> mp;

        for(int num : nums){
            string n = to_string(num);
            string new_n = "";

            for(char ch : n){
                new_n += to_string(mapping[ch - '0']);
            }
            mp.push_back({stoi(new_n),num});
        }

        //debug starts
        for(auto i : mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        sort(mp.begin(),mp.end(),cmp); // sort
        for(auto i : mp){
            cout<<i.first<<" "<<i.second<<endl;
        }
        //debug ends

        vector<int> ans;
        for(auto i : mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};