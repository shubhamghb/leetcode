class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int a=1;
        while(a*(a+1)/2<=grades.size())a++;
        return a-1;
    }
};

//https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/solutions/2357892/it-s-just-maths-o-1-c-python-java-solution-one-line-solution/