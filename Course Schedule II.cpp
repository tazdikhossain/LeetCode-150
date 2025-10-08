class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);  // adjacency list
        vector<int> indegree(numCourses, 0);    // count of incoming edges
        vector<int> result;

        // Build the graph
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);
            indegree[course]++;
        }

        // Queue for courses with no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Process the courses
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            result.push_back(curr);

            for (int neighbor : graph[curr]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If we processed all courses, return result
        if (result.size() == numCourses) {
            return result;
        }

        // Cycle detected
        return {};
    }
};
