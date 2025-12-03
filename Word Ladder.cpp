class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;

        unordered_set<string> beginSet, endSet, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int steps = 1;

        while (!beginSet.empty() && !endSet.empty()) {
            // Expand the smaller frontier
            if (beginSet.size() > endSet.size()) {
                swap(beginSet, endSet);
            }

            unordered_set<string> tempSet;

            for (auto word : beginSet) {
                string s = word;
                for (int i = 0; i < s.size(); i++) {
                    char original = s[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        s[i] = c;

                        if (endSet.count(s)) {
                            return steps + 1;
                        }

                        if (dict.count(s) && !visited.count(s)) {
                            tempSet.insert(s);
                            visited.insert(s);
                        }
                    }
                    s[i] = original;
                }
            }

            beginSet = tempSet;
            steps++;
        }

        return 0;
    }
};
