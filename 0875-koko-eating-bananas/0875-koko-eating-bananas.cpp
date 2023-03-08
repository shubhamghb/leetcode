// class Solution {
// public:
// int hrstaken(vector<int>& piles, int bananasPerHour){
//     long long totalhrs=0;
//     for(int i=0;i<piles.size();i++){
//         int hrspile=ceil(piles[i] / (double)bananasPerHour);
//         totalhrs+=hrspile;
//     }
//     return totalhrs;
// }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n=piles.size();
//         sort(piles.begin(),piles.end());
//         int high=piles[n-1],low=1,k=0;
//         while(low<=high){
//             int mid=(low+high)/2;
//             long long hrstoeatall=hrstaken(piles,mid);

//             if(hrstoeatall<=h){
//                 k=mid; //best till now
//                 high=mid-1;
//             }
//             else low=mid+1;
//         }
//         return k;
//     }
// };
class Solution {
public:
    bool eatAll(vector<int>&piles, int h,int speed){
        int curr=0;
        for(double num:piles){
            double hours=num/speed;
            curr+=ceil(hours);
        }
        return curr<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxspeed=*max_element(piles.begin(),piles.end()), minspeed=1; // setting range for binary search
        
        while(maxspeed>minspeed){
            int mid=(maxspeed+minspeed)/2;
            if(eatAll(piles,h,mid)) maxspeed=mid; // if mid is enough to all bananas than minspeed to mid will have the minimum value.
            else minspeed=mid+1; // if mid is not enough than minimum value will lie between mid+1 to maxspeed
        }
        return minspeed;        
    }
};