// // class Solution {
// // public:
    
// //     int fact(int n)
// // {
// //     // single line to find factorial
// //     return (n==1 || n==0) ? 1: n * fact(n - 1); 
// // }
  
// //     int countWays(vector<vector<int>>& ranges) {
// //         sort(ranges.begin(),ranges.end());
// //         int ctr=1;
// //         int n=ranges.size();
// //         int t=ranges.size();
// //         for(int i=0;i<n-1;i++){
// //             if((ranges[i][1]>ranges[i+1][0] && ranges[i][1]<ranges[i+1][1]) || (ranges[i][0]>ranges[i+1][0] && ranges[i][0]<ranges[i+1][1])) ctr++;
// //             if((ranges[i+1][0]>ranges[i][0] && ranges[i+1][0]<ranges[i][1]) || (ranges[i+1][1]>ranges[i][0] && ranges[i+1][1]<ranges[i][1]))
// //                 ctr++;
// //             else continue;            
// //         }
// //         cout<<ctr;
// //         int non=t-ctr+1;
// //         int ans=fact(non)/(fact(non-2));
// //         return ans;
// //     }
// // };


// class Solution {
// public:
//     int power(int i,int j,int p){
//     if(j==0){
//         return 1;
//     }
//     if(j==1){
//         return i;
//     }
//     long long  ans=power(i,j/2,p);
//     ans=(ans*ans)%p;
//     if(j%2==1){
//         ans=(ans*i)%p;
//     }
//     return ans;
// }
//     int countWays(vector<vector<int>>& ranges) {
//         sort(ranges.begin(),ranges.end());
//         vector<vector<int>> ans;
//         for(auto &i: ranges){
//             if(ans.size()==0 or ans.back()[1]<i[0]){
//                 ans.push_back(i);
//             }
//             else{
//                 ans.back()[1]=max(ans.back()[1],i[1]);
//             }
//         }
//         // long long ans=0;
//         int sz=ans.size();
//         return power(2,sz,1e9+7);
//         
//     }
// };

#define mod 1000000007
#define ll long long int

class Solution {
public:
    
    // It means a^n % p
    ll power(ll a, ll n, ll p){
       ll res = 1;
        while(n){
            if(n%2 == 1){
                res = (res * a)%p;
                n--;
            }else{
                a = (a * a)%p;
                n = n/2;
            }
        }
        return res;
    }
    
    int countWays(vector<vector<int>>& ranges) {
        ll ans = 0;
        
        sort(ranges.begin(), ranges.end());
        
        vector<vector<int>> temp;
        temp.push_back({ranges[0]});
        for(int i=1;i<ranges.size();i++){
            int last_fir = temp[temp.size()-1][0];
            int last_val = temp[temp.size()-1][1];
            
            if(ranges[i][0] > last_val){
                temp.push_back(ranges[i]);
            }else{
                temp.pop_back();
                int final_last = max(last_val, ranges[i][1]);
                temp.push_back({last_fir, final_last});
            }
        }
        ans = power(2, temp.size(), mod);
        
        return (int)ans;
        
    }
};