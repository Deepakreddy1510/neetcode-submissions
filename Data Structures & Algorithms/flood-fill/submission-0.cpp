class Solution {
public:
    void dfs(vector<vector<int>>& image,int x,int y,int oldColor,int color){
        int n = image.size();
        int m = image[0].size();

        if(x >= n || x < 0 || y < 0 || y >= m || image[x][y] != oldColor){
            return;
        }

        image[x][y] = color;
        dfs(image,x-1,y,oldColor,color);
        dfs(image,x,y+1,oldColor,color);
        dfs(image,x+1,y,oldColor,color);
        dfs(image,x,y-1,oldColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] == color){
            return image;
        }
        int oldColor = image[sr][sc];
        dfs(image,sr,sc,oldColor,color);
        return image;
    }
};