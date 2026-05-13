class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0;
        int counter=0;
        int i=0;
        while(i<events.size() && counter!=10){
            if(events[i]=="W"){
                counter++;
            }else{
                if(events[i]=="WD" || events[i]=="NB"){
                    score++;
                }else{
                    score+=events[i][0]-'0';
                }
            }
            i++;
        }

        return {score,counter};
    }
};