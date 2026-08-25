class Solution {
public:
    int countPrimes(int n) {
        if(n<=1) return 0;
        int sq=sqrt(n);
        bool prime[n+1];
        memset(prime,true,sizeof(prime));
        
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i<=sq;i++){
            if(prime[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;

                }
            }
        }
        int count = 0;

        for(int i = 2; i < n; i++) {
            if(prime[i]) {
                count++;
            }
        }

        return count;


        
        
    }
};