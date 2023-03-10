class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        long ans=(long(k)*(long(k+1)))/2; 
        unordered_set<int>s(nums.begin(),nums.end());
        nums.clear();
        for(auto &i:s)
            nums.push_back(i); 
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            // if you have added a number in nums that was already present in nums then remove that and add next candidate that is k+1
          if(nums[i]<=k ){
                ans-=nums[i];
                ans+=k+1;
                k++;
            }
            else break;
        }
        return ans;
    }
};