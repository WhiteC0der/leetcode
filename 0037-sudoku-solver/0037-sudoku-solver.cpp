class Solution {
public:
    bool isValid(int i,int j,char val,vector<vector<char>>& board){
        for(int k=0;k<board.size();k++){
            if(board[i][k]==val){
                return false;
            }
            if(board[k][j]==val){
                return false;
            }
            if(board[3*(i/3)+(k/3)][3*(j/3)+(k%3)]==val) return false;
        }

        return true;
    }
    bool solver(vector<vector<char>> &board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(char ch='1';ch<='9';ch++){
                        if(isValid(i,j,ch,board)){
                        board[i][j]=ch;
                            if(solver(board)) return true;
                        }
                        board[i][j]='.';
                    }
                    return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};