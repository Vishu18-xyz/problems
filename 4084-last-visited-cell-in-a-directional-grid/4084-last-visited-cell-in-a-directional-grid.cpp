class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();

        int currCellX = 0, currCellY = 0;

        while (true) {
            char move = grid[currCellX][currCellY];
            grid[currCellX][currCellY] = 'X';

            int x = currCellX, y = currCellY;

            if (move == 'L') {
                y--;
            } else if (move == 'R') {
                y++;
            } else if (move == 'U') {
                x--;
            } else if (move == 'D') {
                x++;
            }

            if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 'X') {
                break;
            }

            currCellX = x;
            currCellY = y;
        }

        return {currCellX, currCellY};
    }
};