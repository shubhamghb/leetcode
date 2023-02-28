class Solution {
public:
    bool sumGame(string num) {
        //Bob equal false, Alice diff true
        int n=num.size();
        int ctr1=0, ctr2=0, sum1=0, sum2=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i] == '?') ctr1++;
                else sum1 += (num[i]-'0');
            }
            else{
                if(num[i] == '?') ctr2++;
                else sum2 += (num[i]-'0');
            }
        }
        
        if(ctr1 + ctr2==0){
            if(sum1==sum2)  return false;
            else return true;
        }
        if((ctr1+ctr2)%2!=0) return true;
        
        cout<<ctr1<<" "<<ctr2<<" "<<sum1<<" "<<sum2;

        int diff=min(ctr1,ctr2);
        ctr1-=diff;
        ctr2-=diff;

        if(ctr1>0){
            if(sum1>sum2) return true;
            if(9*(ctr1/2)==sum2-sum1)return false;

        }
        else {
            if(sum2>sum1) return true;
            if(9*(ctr2/2)==sum1-sum2)return false;

        }
 
        return true;
    }
};
 