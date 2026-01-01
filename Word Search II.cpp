class Solution {
public:
    struct TrieNode {
        TrieNode* children[26];
        string word;  // store full word at terminal node

        TrieNode() {
            memset(children, 0, sizeof(children));
        }
    };

    vector<string> result;
    int m, n;

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx])
                    node->children[idx] = new TrieNode();
                node = node->children[idx];
            }
            node->word = w;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (c == '#' || node->children[c - 'a'] == nullptr)
            return;

        node = node->children[c - 'a'];

        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear(); // avoid duplicates
        }

        board[i][j] = '#'; // mark visited

        if (i > 0) dfs(board, i - 1, j, node);
        if (j > 0) dfs(board, i, j - 1, node);
        if (i < m - 1) dfs(board, i + 1, j, node);
        if (j < n - 1) dfs(board, i, j + 1, node);

        board[i][j] = c; // restore
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        TrieNode* root = buildTrie(words);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }
};
