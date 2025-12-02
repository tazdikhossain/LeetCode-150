class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (!dict.count(endGene)) return -1;   // end must be in bank
        
        queue<pair<string,int>> q;
        q.push({startGene, 0});
        
        unordered_set<string> visited;
        visited.insert(startGene);
        
        vector<char> chars = {'A','C','G','T'};
        
        while (!q.empty()) {
            auto [gene, steps] = q.front();
            q.pop();
            
            if (gene == endGene) return steps;
            
            string next = gene;
            for (int i = 0; i < 8; i++) {
                char old = next[i];
                for (char c : chars) {
                    if (c == old) continue;
                    next[i] = c;
                    
                    if (dict.count(next) && !visited.count(next)) {
                        visited.insert(next);
                        q.push({next, steps + 1});
                    }
                }
                next[i] = old;
            }
        }
        
        return -1;
    }
};
