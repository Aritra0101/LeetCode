class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int val = 1;
        vector<vector<int>> res(n, vector<int>(n, 11));
        int startCol=0, endCol=n-1;
        int startRow=0, endRow=n-1;

        while(startCol<=endCol && startRow<=endRow) {
            if(startRow <= endRow)
                for(int j=startCol; j<=endCol; j++)
                    res[startRow][j] = val++;
            startRow++;

            if(startCol <= endCol)
                for(int i=startRow; i<=endRow; i++)
                    res[i][endCol] = val++;
            endCol--;

            if(startRow <= endRow)
                for(int j=endCol; j>=startCol; j--)
                    res[endRow][j] = val++;
            endRow--;

            if(startCol <= endCol)
                for(int  i=endRow; i>=startRow; i--)
                    res[i][startCol] = val++;
            startCol++;
        }

        return res;
    }
};