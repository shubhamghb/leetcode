class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int groupSize) {
        int n = nums.size();
        if(n%groupSize!=0) return false;

        map<int,int> mp;
        for(auto x: nums) mp[x]++;

        while(!mp.empty()) {
            // Pick the smallest element available
            auto v = mp.begin()->first;

            // Check if all from [v...v+k-1] present in map
            for(int i=0;i<groupSize;i++) {
                if(!mp.count(v+i)) return false;
                // if present, decrement their frequency, and delete it if it reaches 0
                if(--mp[v+i] == 0) mp.erase(v+i);
            }
        }

        // If map still has numbers => not all numbers can be partitioned
        return mp.empty();
    }
};