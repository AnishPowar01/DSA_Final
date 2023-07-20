class Solution {
private:
    void dfs(int sr, int sc, int initialColor, int color, vector<vector<int>>& image, vector<vector<int>>& ans,int deltaRow[],int deltaCol[] )
    {
        ans[sr][sc] = color;

        int n = image.size();
        int m = image[0].size();

        for(int i = 0; i<4; i++)
        {
            int nrow = sr + deltaRow[i];
            int nCol = sc + deltaCol[i];

            if(nrow>=0 && nrow<n && nCol>=0 && nCol<m && ans[nrow][nCol]!=color && image[nrow][nCol] ==initialColor)
            {
                dfs(nrow,nCol, initialColor, color, image,ans,deltaRow,deltaCol);
            }

        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        vector<vector<int>> ans = image;

        int initialColor = image[sr][sc];

        int deltaRow[] = {-1,0,1,0};

        int deletaCol[]= {0,-1,0,1};

        dfs(sr,sc,initialColor, color,image,ans,deltaRow,deletaCol);


        return ans;
        
    }
};