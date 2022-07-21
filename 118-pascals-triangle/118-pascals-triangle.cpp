class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> V(numRows);
        V[0].push_back(1);
        for(int i = 1; i < numRows; ++i)
        {
            V[i].push_back(1);
            for(int j = 1; j < V[i-1].size(); ++j)
            {
                V[i].push_back(V[i-1][j]+V[i-1][j-1]);
            }
            V[i].push_back(1);
        }
        return V;
    }
};