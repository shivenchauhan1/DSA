class Solution {
public:
    int minimumXORSum(vector<int>& nums1,vector<int>& nums2){
        int n=nums1.size();
        vector<int> dp(1<<n,INT_MAX);
        dp[0]=0;
        for(int mask=0;mask<(1<<n);mask++){
            int i=__builtin_popcount(mask);
            if(i==n) continue;

            for(int j=0;j<n;j++){
                if(!(mask&(1<<j))){
                    int newMask=mask|(1<<j);
                    dp[newMask]=min(dp[newMask],dp[mask]+(nums1[i]^nums2[j]));
                }
            }
        }
        return dp[(1<<n)-1];
    }
};