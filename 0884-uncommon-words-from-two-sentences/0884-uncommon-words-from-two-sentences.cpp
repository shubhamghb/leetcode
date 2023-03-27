class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int>mp;
        stringstream ss1(s1),ss2(s2);
        string word1,word2;
        while(ss1>>word1) mp[word1]++;
        while(ss2>>word2) mp[word2]++;
        vector<string>ans;
        for(auto x:mp){
            if(x.second==1) ans.push_back(x.first);
        }
        return ans;
        
    }
};