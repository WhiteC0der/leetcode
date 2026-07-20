class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                temp.push_back(grid[i][j]);
            }
        }
        k=k%temp.size();
        reverse(temp.begin(),temp.end());
        reverse(temp.begin(),temp.begin()+k);
        reverse(temp.begin()+k,temp.end());
        int l=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                grid[i][j]=temp[l++];
            }
        }

        return grid;
    }
};