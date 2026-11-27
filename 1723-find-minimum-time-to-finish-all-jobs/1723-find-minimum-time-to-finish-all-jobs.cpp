class Solution {
public:
    bool solve(vector<int>& jobs,vector<int>& workers,int idx,int limit){
        if(idx==jobs.size()) return true;
        unordered_set<int> seen;
        for(int i=0;i<workers.size();i++){
            if(workers[i]+jobs[idx]>limit) continue;
            if(seen.count(workers[i])) continue;
            seen.insert(workers[i]);
            workers[i]+=jobs[idx];
            if(solve(jobs,workers,idx+1,limit)) return true;
            workers[i]-=jobs[idx];
            if(workers[i]==0) break;
        }
        return false;
    }

    int minimumTimeRequired(vector<int>& jobs,int k){
        sort(jobs.rbegin(),jobs.rend());
        int low=jobs[0];
        int high=accumulate(jobs.begin(),jobs.end(),0);
        while(low<high){
            int mid=low+(high-low)/2;
            vector<int> workers(k,0);
            if(solve(jobs,workers,0,mid))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};