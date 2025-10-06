class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto& pre : prerequisites) {
            graph[pre[1]].push_back(pre[0]);  // edge: pre[1] -> pre[0]
        }
        
        vector<int> visited(numCourses, 0);  // 0=unvisited, 1=visiting, 2=visited
        
        // DFS function to detect cycle
        function<bool(int)> dfs = [&](int node) {
            if (visited[node] == 1) return true;  // cycle detected
            if (visited[node] == 2) return false; // already processed

            visited[node] = 1;  // mark as visiting
            for (int neighbor : graph[node]) {
                if (dfs(neighbor)) return true;
            }
            visited[node] = 2;  // mark as visited
            return false;
        };

        for (int i = 0; i < numCourses; ++i) {
            if (dfs(i)) return false;  // cycle found
        }
        return true;  // no cycle
    }
};
