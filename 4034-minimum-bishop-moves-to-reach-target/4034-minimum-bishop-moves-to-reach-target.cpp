class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        int si=source[0];
        int sj=source[1];
        int ti=target[0];
        int tj=target[1];
        if(((si+sj)%2) != ((ti+tj)%2)) return -1;
        if(si+sj == ti+tj || si-sj+8==ti-tj+8){
            return 1;
        }

        return 2;
    }
};