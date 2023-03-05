class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int> mp;
        int n=s.size();
        int left=0,right=0,ctr=0;
        while(right<n){
            mp[s[right]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1 && left<=right){
               mp[s[left]]--;
               ctr+=n-right;
               left++;
           }
           right++;
       }
       return ctr;
    }
};