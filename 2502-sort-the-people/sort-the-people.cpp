class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> mp;
        for(int i=0;i<names.size();i++){
            mp[heights[i]] = names[i];
        }
        int idx = 0;
        for(auto i = mp.rbegin() ; i != mp.rend() ; i++){
            names[idx++] = i->second;
        }
        return names;
    }
};