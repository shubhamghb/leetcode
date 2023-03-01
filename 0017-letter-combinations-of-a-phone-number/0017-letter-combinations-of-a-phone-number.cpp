class Solution {
public:
 vector<string> solve(string &digits,map<int,string>&mp,int idx){
         
        if(idx==digits.size()) return {""};
          
        vector<string>temp=solve(digits,mp,idx+1);
        vector<string>ans;
        for(auto x:mp[digits[idx]-'0']){
            for(auto y:temp){
                ans.push_back(x+y);
            }
        }
        return ans;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        map<int,string>mp; 
           mp[2]="abc";
           mp[3]="def";
           mp[4]="ghi";
           mp[5]="jkl";
           mp[6]="mno";
           mp[7]="pqrs";
           mp[8]="tuv";
           mp[9]="wxyz";
    
        if(digits.size()==0){
              return res;
        }
       return  solve(digits,mp,0);  
    }
};