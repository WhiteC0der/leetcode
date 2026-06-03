class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans=INT_MAX;
        int time=0;
        for(int i=0;i<landStartTime.size();i++){
            for(int j=0;j<waterStartTime.size();j++){
                time=landStartTime[i];
                time+=landDuration[i];
                if(time<waterStartTime[j]){
                    time=waterStartTime[j];
                }
                time+=waterDuration[j];
                ans=min(ans,time);
                

                time=waterStartTime[j];
                time+=waterDuration[j];
                if(time<landStartTime[i]){
                    time=landStartTime[i];
                }
                time+=landDuration[i];
                ans=min(ans,time);
            }
        }

        return ans;
    }
};