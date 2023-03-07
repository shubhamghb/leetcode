// class Solution {
// public:
//     long long minimumTime(vector<int>& time, int totalTrips) {
//         sort(time.begin(),time.end());
//         int ctr=0,sum=0,a=0;
//         while(a<totalTrips){
//             for(int i=0;i<time.size();i++) {
//                 if(sum>=totalTrips) return ctr;
//                 else{
//                     sum+=a/time[i];
                
//                 cout<<sum<<endl;
//                     ctr++;
//                     a++;
//                 }
                
//             }
//         }
//         return ctr;
//     }
// };
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        
        long long left=0,right=totalTrips*(long long)time[0],ans=right;
        while(left<right){
            long long mid=(left+right)/2;
            long long count=0;
            for(int i=0;i<time.size();++i){
                count+=mid/time[i];  // checking if that mid can fultill totaltrips or not by adding all 
            //  possible no of trips performed by all buses with mid time 
                
            } 
            if(count>=totalTrips){
                ans=min(ans,mid); // minimising time
                right=mid;
            }else{
                left=mid+1;
            }
            
        }
        return ans;
    }
};