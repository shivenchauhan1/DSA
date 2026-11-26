class Solution {
public:
    bool solve(vector<int>& matchsticks,vector<int>& sides,int idx,int target){
        if(idx==matchsticks.size()) return true;
        for(int i=0;i<4;i++){
            if(sides[i]+matchsticks[idx]>target) continue;
            if(i>0&&sides[i]==sides[i-1]) continue;
            sides[i]+=matchsticks[idx];
            if(solve(matchsticks,sides,idx+1,target)) return true;
            sides[i]-=matchsticks[idx];
            if(sides[i]==0) break;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks){
        int sum=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(sum%4!=0) return false;
        int target=sum/4;
        sort(matchsticks.rbegin(),matchsticks.rend());
        if(matchsticks[0]>target) return false;
        vector<int> sides(4,0);
        return solve(matchsticks,sides,0,target);
    }
};