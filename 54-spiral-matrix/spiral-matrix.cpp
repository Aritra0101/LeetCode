class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();

        int top=0, bottom=m-1, left=0, right=n-1;

        int i=0, j=0;
        while(top<=bottom && left<=right) {
            //LEFT
            if(top<=bottom)
            for(j=left; j<=right; j++) {
                // cout<<matrix[top][j]<<" ";
               res.emplace_back( matrix[top][j] );
            }
            top++;

            //DOWN
            if(left<=right)
            for(i=top; i<=bottom; i++) {
                // cout<<matrix[i][right]<<" ";
                res.emplace_back( matrix[i][right] );
            } 
            right--;

            //RIGHT
            if(top<=bottom)
            for(j=right; j>=left; j--) {
                // cout<<matrix[bottom][j]<<" ";
                res.emplace_back( matrix[bottom][j] );
            }
            bottom--;

            //UP
            if(left<=right)
            for(i=bottom; i>=top; i--) {
                // cout<<matrix[i][left]<<" ";
                res.emplace_back( matrix[i][left] );
            }
            left++;

            // cout<<endl;
            // cout<<"top = "<<top<<endl;
            // cout<<"bottom = "<<bottom<<endl;
            // cout<<"left = "<<left<<endl;
            // cout<<"right = "<<right<<endl;
            // cout<<endl;
        }

        return res;
    }
};