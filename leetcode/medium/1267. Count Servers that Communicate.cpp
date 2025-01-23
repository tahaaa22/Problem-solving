#########First approach##############
class Solution {
public:
  bool isValid(pair<int, int> cell, int rows, int columns)
    {
        return cell.first >= 0 && cell.second >= 0 && cell.first < rows &&
            cell.second < columns;
    };
  int countServers(vector<vector<int>>& grid) 
    {
       int row = grid.size();
       int column = grid[0].size();
       int dx[4] = { 0,0,1,-1 };
       int dy[4] = { 1,-1,0,0 };
       int count = 0;
       vector <vector<int>> visited(row, vector<int>(column, -1));
       queue<pair<int, int>> bfs;
       for (int i = 0; i < row; ++i)
       {
           for (int j = 0; j < column; ++j)
           {
               if (grid[i][j])
               {
                   bfs.push({i,j});
               }
           }
       }
       while (!bfs.empty())
       {
           pair<int, int> currentpair = bfs.front();
           bfs.pop();
           for (int d = 0; d < 4; ++d)
           {
               pair<int, int>neighbourpair = currentpair;
               while (isValid({neighbourpair.first + dx[d], neighbourpair.second + dy[d]}, row, column))
               {
                   neighbourpair = { neighbourpair.first + dx[d], neighbourpair.second + dy[d] };
                   if (grid[neighbourpair.first][neighbourpair.second] && visited[neighbourpair.first][neighbourpair.second] == -1)
                   {
                      visited[neighbourpair.first][neighbourpair.second] = 0;
                       count++;
                   }
                      
               }
      
           }
       }
         return count;
      }
};

##############Better approach###############
class Solution {
public:

    int countServers(vector<vector<int>>& grid) {
        vector <int> rowcount (size(grid), 0);
        vector <int> columncount(size(grid[0]), 0);

        for(int row = 0; row < size(grid); ++row)
            for(int column = 0; column < size(grid[0]); ++column)
                if(grid[row][column])
                {
                    rowcount[row]++;
                    columncount[column]++;
                }
                
        int servercounter = 0;
        for(int row = 0; row < size(grid); ++row)
            for(int column = 0; column < size(grid[0]); ++column)
                if(grid[row][column])
                {
                    servercounter += rowcount[row] > 1 || columncount[column] > 1;
                }
                
        return servercounter;
    }
};
