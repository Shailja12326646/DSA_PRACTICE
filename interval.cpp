class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& nums, vector<int>& n) {
        nums.push_back(n);
        sort(nums.begin(),nums.end());
        vector <vector<int>>ans;
        for (int i=0;i<nums.size();i++)
        {
            if (ans.empty()|| nums[i][0]>ans.back()[1])
             ans.push_back(nums[i]);
            else
             ans.back()[1]=max(ans.back()[1],nums[i][1]); 
        }
        return ans;
    }
};
