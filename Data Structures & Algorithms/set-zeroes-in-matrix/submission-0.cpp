class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[0][j]=0;
                    if(i>0)
                    matrix[i][0]=0;
                    else rowZero = true;
                }
            }
        }
        for(int i=1; i<rows; i++)
        {
            for(int j=1; j<cols; j++)
            {
                if(matrix[0][j]==0||matrix[i][0]==0)
                matrix[i][j]=0;
            }
        }
        if(matrix[0][0]==0) //checks for first col
        {
            for(int i=0; i<rows; i++)
            matrix[i][0]=0;
        }
        if(rowZero)//checks for first row
        {
            for(int c=0; c<cols; c++)
            {
                matrix[0][c]=0;
            }
        }
    }
};
