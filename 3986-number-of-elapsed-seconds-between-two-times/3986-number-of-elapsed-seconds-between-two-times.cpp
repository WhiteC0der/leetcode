class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        string sh= startTime.substr(0,2);
        string sm = startTime.substr(3,2);
        string ss = startTime.substr(6,2);
        string eh= endTime.substr(0,2);
        string em = endTime.substr(3,2);
        string es = endTime.substr(6,2);
        int st=0;
        int end=0;
        st= stoi(sh)*60*60 + stoi(sm)*60 +stoi(ss);
        end= stoi(eh)*60*60 + stoi(em)*60 +stoi(es);

        return sh <= eh ? end-st : end+24*60*60 -st;
    }
};