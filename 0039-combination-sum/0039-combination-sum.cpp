class Solution {
public:  
vector<vector<int>>ans;

void fnc(vector<int>&A, int B, vector<int>&v,int i){
    
    if(B==0) ans.push_back(v);
    if(i==A.size()) return;
    
    while(i<A.size() && B-A[i]>=0){
        v.push_back(A[i]);
        fnc(A,B-A[i],v,i);
        i++;
        v.pop_back();
    }
}
  
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      sort(candidates.begin(),candidates.end());

      //Remove Duplicates  
      set<int>s (candidates.begin(),candidates.end());
      candidates.assign(s.begin(),s.end());

      vector<int>v;
      fnc(candidates,target,v,0);
      return ans;
        
    }
};
