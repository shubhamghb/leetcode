class Solution {
public:
int n;
int calscore(vector<int>&nums,int i,int j,int chance){
    if(i>j) return 0;
    if(chance==0){
        return max(nums[i]+calscore(nums,i+1,j,1),nums[j]+calscore(nums,i,j-1,1));
    }
    else return min(calscore(nums,i+1,j,0),calscore(nums,i,j-1,0));
}
    bool PredictTheWinner(vector<int>& nums) {
        long long tsum=0;
        n=nums.size();
        for(int i=0;i<nums.size();i++) tsum+=nums[i];
        
        long long p1=calscore(nums,0,n-1,0);
        long long p2=tsum-p1;
        return (p1>=p2);
    }
};