class Solution {
public: vector<vector<int>>ans;
void fnc(int i,vector<int>&nums, vector<int>& temp){ 
    if(i==nums.size()) ans.push_back(temp);
    else{
        //to take ith element
        temp.push_back(nums[i]);
        fnc(i+1,nums,temp);
        temp.pop_back();
        //to not take it
        fnc(i+1,nums,temp);

    }

}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        fnc(0,nums,temp);
        return ans;
    }
};