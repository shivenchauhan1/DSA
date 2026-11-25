class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        if(n<2)return 0;
        int mn=*min_element(nums.begin(),nums.end());
        int mx=*max_element(nums.begin(),nums.end());
        if(mn==mx)return 0;
        int size=max(1,(mx-mn)/(n-1));
        int count=(mx-mn)/size+1;
        vector<int> bmin(count,INT_MAX),bmax(count,INT_MIN);
        vector<bool> used(count,false);
        for(int x:nums) {
            int i=(x-mn)/size;
            bmin[i]=min(bmin[i],x);
            bmax[i]=max(bmax[i],x);
            used[i]=true;
        }
        int ans=0,prev=mn;
        for(int i=0;i<count;i++) {
            if(!used[i])continue;
            ans=max(ans,bmin[i]-prev);
            prev=bmax[i];
        }
        return ans;
    }
};