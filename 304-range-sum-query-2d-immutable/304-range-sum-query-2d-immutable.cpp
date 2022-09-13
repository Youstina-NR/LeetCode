class NumMatrix {
public:
   // vector<vector<int>> M;
    vector<vector<int>> P;
    NumMatrix(vector<vector<int>>& matrix) {
        P = matrix;
        for(int i = 1; i < P.size(); i++)
        {
            P[i][0] += P[i-1][0] ;
        }
        for(int j = 1; j < P[0].size(); j++)
        {
            P[0][j] += P[0][j-1] ;
        }
        
        
        for(int i = 1; i < P.size() ; i++)
        {
            for(int j = 1; j < P[0].size(); j++)
            {
                P[i][j] = P[i][j] + P[i][j-1] + P[i-1][j] - P[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = P[row2][col2];
        bool f1 = false, f2 = false;
        if(row1 > 0)
        {
            f1 = true;
            sum -= P[row1-1][col2];
        }
        if(col1 > 0)
        {
            f2 = true;
            sum -= P[row2][col1-1];
        }
        if(f1&&f2)
            sum += P[row1-1][col1-1];
        
        
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */