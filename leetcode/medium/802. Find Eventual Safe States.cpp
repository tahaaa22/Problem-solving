bool DFS(int index, unordered_map<int, bool>&status, vector<vector<int>>& graph)
{
    if (status.find(index) != status.end())
        return status[index];
    status[index] = false;
    for (auto& neighbor : graph[index])
    {
        if (!DFS(neighbor, status, graph))
        {
            return status[index];
        }
    }
    status[index] = true;
    return true;

}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int nodes = graph.size();
    vector<int> result;
    unordered_map<int, bool> status;

    for (int i = 0; i < nodes; ++i)
    {
        if (DFS(i, status,graph))
        {
            result.push_back(i);
        }
    }
    return result;
}
