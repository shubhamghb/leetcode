class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        for(auto x:nums)mp[x]++;
        for(auto& it :mp){
            // if(it.second==1 && !find(nums.begin(),nums.end(),it+1) && !find(nums.begin(),nums.end(),it-1) ) ans.push_back(it);
            int c=0;
            if(it.second==1){
                if(mp[it.first-1]) c++;
                if(mp[it.first+1]) c++;
            }
            if(c==0 && it.second==1){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};