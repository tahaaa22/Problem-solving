class Solution {
    public:
bool isValid(pair<int, int> cell, int rows, int columns){
    return cell.first >= 0 && cell.second >= 0 && cell.first < rows &&
        cell.second < columns;}

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int column = isWater[0].size();
    int row = isWater.size();
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0 , 0};

    queue <pair<int,int>> bfs;
    vector<vector<int>> result(row, vector<int>(column, -1));

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < column; ++j)
        {
            if (isWater[i][j])
            {
                result[i][j] = 0;
                pair<int, int> currentpair = {i,j};
                bfs.push(currentpair);
            }
        }
    }

    int heightlevel = 1; // incrementing this for each time we enque a cell
    while (!bfs.empty())
    {
        int currentlayer = bfs.size();
        for (int i = 0; i < currentlayer; ++i)
        {
            pair<int, int> currentpair = bfs.front();
            bfs.pop();
            
            for (int d = 0; d < 4; d++)
            {
                pair<int, int>neighborpair = { currentpair.first + dx[d], currentpair.second + dy[d] };
                if (isValid(neighborpair, row, column) && result[neighborpair.first][neighborpair.second] == -1)
                {
                    result[neighborpair.first][neighborpair.second] = heightlevel;
                    bfs.push(neighborpair);

                }
            }
        }
        heightlevel++;
    }

    return result;
}
};
