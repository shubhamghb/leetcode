// Almost Working
// class Solution {
// public:
//     int minimumDeletions(vector<int>& nums) {
//         if(nums.size()==1) return 1;
//         int n=nums.size();
//         int max=*max_element(nums.begin(),nums.end());
//         int min=*min_element(nums.begin(),nums.end());
//         int maxidx=-1,minidx=-1;
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==max) maxidx=i;
//             if(nums[i]==min) minidx=i;
//         }
//         int ans=0,m1=0,m2=0,m3=0; 
//         if(maxidx>minidx){
//             m1=maxidx+1;
//         } else m1=minidx+1;
//         if(maxidx>minidx){
//             m2=n-minidx;;
//         } else m2=n-maxidx;
//         m3=maxidx+nums.size()-minidx+1;
//         cout<<m1<<m2<<m3;
//         if(m1<m2 && m1<m3) return m1;
//         if(m2<m3 && m2<m1) return m2;
//         if(m3<m2 && m3<m1) return m3;
        
//         return 0;
        
//     }
// };
 class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx = INT_MIN,mn = INT_MAX,mni,mxi,i,n=nums.size();
        for(i = 0; i < n; i++){
            if(nums[i]<mn){
                mn = nums[i];
                mni = i;
            }
            if(nums[i]>mx){
                mx = nums[i];
                mxi = i;
            }
        }
        if(mni<mxi){
            swap(mni,mxi);
        }
        return min({mxi+1+n-mni,n-mxi,mni+1});
    }
};