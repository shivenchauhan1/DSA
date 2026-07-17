class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        long long mx=*max_element(nums.begin(),nums.end());
        vector<int> mp(mx+1,0); // stores the frequency of the values in the nums
        for(int i:nums)
        mp[i]++;

        vector<long long> cnt(mx+1,0);
        // the index of cnt is actually the GCD of 2 numbers and the value at i is the frequency of occurance of that GCD
        for(int i=mx;i>=1;i--)
        {
            long long curr=0;
            for(int k=i;k<=mx;k+=i) // inclusion of all pairs
            curr+=mp[k];
            cnt[i]=curr*(curr-1)/2;
            for(int k=2*i;k<=mx;k+=i) // exclude pairs covered by greater GCD
            cnt[i]-=cnt[k];
        }

        // now convert to prefix sum of frequencies
        for(int i=1;i<=mx;i++)
        cnt[i]+=cnt[i-1];
        vector<int> sol;
        for(auto it:queries)
        sol.push_back(lower_bound(cnt.begin(),cnt.end(),it+1)-cnt.begin()); // store the index i.e the GCD 
        return sol;
    }
};