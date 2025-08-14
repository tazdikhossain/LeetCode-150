class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || s.empty()) return result;
        
        int wordLen = words[0].size();
        int wordCountTotal = words.size();
        int totalLen = wordLen * wordCountTotal;
        int sLen = s.size();
        
        if (totalLen > sLen) return result;
        
        unordered_map<string, int> wordCount;
        for (auto &w : words) wordCount[w]++;
        
        // Try starting from each offset within one word length
        for (int offset = 0; offset < wordLen; ++offset) {
            int left = offset, right = offset, count = 0;
            unordered_map<string, int> seen;
            
            while (right + wordLen <= sLen) {
                string word = s.substr(right, wordLen);
                right += wordLen;
                
                if (wordCount.count(word)) {
                    seen[word]++;
                    count++;
                    
                    // If a word appears too many times, move left pointer
                    while (seen[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                    
                    // Found a valid window
                    if (count == wordCountTotal) {
                        result.push_back(left);
                        // Move left pointer forward
                        string leftWord = s.substr(left, wordLen);
                        seen[leftWord]--;
                        count--;
                        left += wordLen;
                    }
                } else {
                    // Reset if invalid word found
                    seen.clear();
                    count = 0;
                    left = right;
                }
            }
        }
        
        return result;
    }
};
