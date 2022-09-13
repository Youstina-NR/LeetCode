class Solution {
public:
    int N;
    struct Point{
      int x,y;  
    };

    struct qNode{
      Point pt;
      int dist;
    };

    bool isValid(int row, int col)
    {
        return row >= 0 && row < N && col >= 0 && col < N; 
    }

    int rowNum [8] = {-1, 0, 0, 1, -1, 1, -1, 1};
    int colNum [8] = {0, -1, 1, 0, -1, -1, 1, 1};

    int BFS(vector<vector<int>>& grid, Point src, Point dest)
    {
        bool visited[N][N];
        memset(visited,false,sizeof(visited));

        visited[src.x][src.y] = true;

        queue<qNode>q;

        qNode s = {src,1};
        q.push(s);

        qNode curr;
        while(!q.empty())
        {
            curr = q.front();
            Point pt = curr.pt;

            if (pt.x == dest.x && pt.y == dest.y)
                return curr.dist;
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int row = pt.x + rowNum[i];
                int col = pt.y + colNum[i];


                if (isValid(row, col) && grid[row][col] == 0 &&
                   !visited[row][col])
                {

                    visited[row][col] = true;
                    qNode Adjcell = { {row, col},
                                          curr.dist + 1 };
                    q.push(Adjcell);
                }
            }
        }


        return -1;


    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            N = grid.size();
            if(grid[0][0] == 1 || grid[N-1][N-1] == 1)
                return -1;

            Point src = {0,0};
            Point dest = {N-1,N-1};

            return BFS(grid, src, dest);

        
    }
};