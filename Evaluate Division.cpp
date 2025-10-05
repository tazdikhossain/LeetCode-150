#include <unordered_map>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    // Graph: variable -> list of neighbors and the associated weight
    unordered_map<string, vector<pair<string, double>>> graph;

    // DFS helper function
    bool dfs(string curr, string target, unordered_set<string>& visited, double& result, double product) {
        if (visited.count(curr)) return false;
        visited.insert(curr);

        if (curr == target) {
            result = product;
            return true;
        }

        for (auto& [neighbor, weight] : graph[curr]) {
            if (dfs(neighbor, target, visited, result, product * weight)) {
                return true;
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Build the graph
        for (int i = 0; i < equations.size(); ++i) {
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].emplace_back(b, val);
            graph[b].emplace_back(a, 1.0 / val);
        }

        vector<double> results;

        for (auto& query : queries) {
            string start = query[0], end = query[1];

            if (!graph.count(start) || !graph.count(end)) {
                results.push_back(-1.0);
            } else if (start == end) {
                results.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double result = -1.0;
                dfs(start, end, visited, result, 1.0);
                results.push_back(result);
            }
        }

        return results;
    }
};
