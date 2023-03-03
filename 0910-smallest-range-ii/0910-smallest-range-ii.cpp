class Solution 
{
public:
    int smallestRangeII(vector<int>& A, int K)  
    {  
        sort(A.begin(), A.end());
        int res = A[A.size() - 1] - A[0];
        int left = A[0] + K, right = A[A.size() - 1] - K;
        for (int i = 0; i < A.size() - 1; i++) 
        
        {
            int maxi = max(A[i] + K, right), mini = min(left, A[i + 1] - K);
            res = min(res, maxi - mini);
        }
        return res; 
    }

};
/*For sorted A, say A[i] is the largest i that goes up. Then A[0] + K, A[i] + K, A[i+1] - K, A[A.length - 1] - K are the only relevant values for calculating the answer: every other value is between one of these extremal values.*/