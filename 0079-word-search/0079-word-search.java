class Solution {
    private int[] diri={0,-1,0,1};
    private int[] dirj={-1,0,1,0};
    private boolean search(int i,int j,int curr,char[][] board,String word){
        if(curr== word.length()){
            return true;
        }
        char ch=board[i][j];
        board[i][j]='$';
        for(int k=0;k<4;k++){
            int ni=i+diri[k];
            int nj=j+dirj[k];
            if(ni>=0 && ni<board.length && nj>=0 && nj<board[0].length && board[ni][nj]==word.charAt(curr)){
                if(search(ni,nj,curr+1,board,word)) return true;       
            }
        }

        board[i][j]=ch;

        return false;
    }
    public boolean exist(char[][] board, String word) {
        int m=board.length;
        int n=board[0].length;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){  
                if(board[i][j]==word.charAt(0)){
                    if(search(i,j,1,board,word)) return true;
                }
            }
        }

        return false;
    }
}