class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> temp={31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
        int alicestmon = (arriveAlice[1]-'0') + (arriveAlice[0]-'0') * 10;
        int alicestday = (arriveAlice[4]-'0') + (arriveAlice[3]-'0') * 10;
        int aliceendmon = (leaveAlice[1]-'0') + (leaveAlice[0]-'0') * 10;
        int aliceendday = (leaveAlice[4]-'0') + (leaveAlice[3]-'0') * 10;
        int bobstmon = (arriveBob[1]-'0') + (arriveBob[0]-'0') * 10;
        int bobstday = (arriveBob[4]-'0') + (arriveBob[3]-'0') * 10;
        int bobendmon = (leaveBob[1]-'0') + (leaveBob[0]-'0') * 10;
        int bobendday = (leaveBob[4]-'0') + (leaveBob[3]-'0') * 10;
        int alicest = (alicestmon == 1 ? 0 : temp[alicestmon-2]) + alicestday;
        int aliceend = (aliceendmon == 1 ? 0 : temp[aliceendmon-2]) + aliceendday;
        int bobst = (bobstmon == 1 ? 0 : temp[bobstmon-2]) + bobstday;
        int bobend = (bobendmon == 1 ? 0 : temp[bobendmon-2]) + bobendday;
        if(aliceend< bobst || bobend < alicest) return 0;

        return abs(max(alicest,bobst)-min(aliceend,bobend))+1;
    }   
};