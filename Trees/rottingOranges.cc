class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh_oranges = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        int minute = 0;
        vector<pair<int,int>> direction = { {-1,0}, {1,0}, {0,1}, {0,-1} };
        
        if (grid.empty()) {
            return minute;
        }
        
        for (int i=0; i < rows; i++) {
            for (int j=0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i,j));
                } else if (grid[i][j] == 1) {
                    fresh_oranges++;
                }
            }
        }
        if (fresh_oranges == 0) {
            return minute;
        }
        
        while (!q.empty()) {
            minute++;
            int qlen = q.size();
            pair<int,int> p;

            for (int i=0; i < qlen; i++) {
                p = q.front();
                q.pop();

                for (auto d : direction) {
                    int x = p.first + d.first;
                    int y = p.second + d.second;
                    
                    if (x >= 0 && x < rows && y >= 0 && y < cols && 
                        grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push(make_pair(x,y));
                        //cout << "Adding to Q : " << x << "," << y << endl;
                        fresh_oranges--;
                    }
                }
            }
        }
        return (fresh_oranges == 0) ? minute-1 : -1;
    }
};
