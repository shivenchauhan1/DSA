class Solution {
public:
    int ans=0;

    void solve(vector<vector<int>>& score,int idx,int mask,int sum){
        if(idx==score.size()){
            ans=max(ans,sum);
            return;
        }

        for(int j=0;j<score.size();j++){
            if(!(mask&(1<<j))){
                solve(score,idx+1,mask|(1<<j),sum+score[idx][j]);
            }
        }
    }

    int maxCompatibilitySum(vector<vector<int>>& students,vector<vector<int>>& mentors){
        int m=students.size();
        int n=students[0].size();
        vector<vector<int>> score(m,vector<int>(m,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(students[i][k]==mentors[j][k])
                        score[i][j]++;
                }
            }
        }

        solve(score,0,0,0);
        return ans;
    }
};