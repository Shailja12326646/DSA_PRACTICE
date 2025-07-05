class Solution {
public:
    int findLucky(vector<int>& nums) {
        unordered_map<int,int>mp;
        for (auto num : nums)
        {
            mp[num]++;
        }
        int maxi=-1;
        for (auto it: mp)
        {
            if (it.first==it.second)
             maxi=max(maxi,it.second);
        }
        return maxi;
    }
};
