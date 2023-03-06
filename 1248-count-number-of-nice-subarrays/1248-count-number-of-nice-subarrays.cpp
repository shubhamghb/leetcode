//TLE

// class Solution {
// public:
//     int numberOfSubarrays(vector<int>& nums, int k) {
//         int ctr=0;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]%2==1) nums[i]=1;
//             else nums[i]=0;
//         }
//         for (int i = 0; i<nums.size(); i++){
//         int sum = 0;
//             for (int j = i; j<nums.size(); j++){ 
//             sum += nums[j]; 
//             if (sum == k)
//             ctr++;
//             }
//         }

//     return ctr;
//     }
// };

/* EFFICIENT*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
 
       unordered_map<int,int>m;
       for(int i=0;i<nums.size();i++){
             if(nums[i]%2==1) nums[i]=1;
             else nums[i]=0;
       }
        int sum=0,ctr=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k)ctr++;
            if(m.find(sum-k)!=m.end()) ctr+=m[sum-k];
            m[sum]++;
        }
        return ctr;
    }
};

