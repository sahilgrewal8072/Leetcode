class TrieNode {
public:
    TrieNode* arr[26];
    bool flag;

    TrieNode() {
        flag = false;
        for (int i = 0; i < 26; i++) {
            arr[i] = nullptr;
        }
    }

    TrieNode* getValue(int ind) {
        return arr[ind];
    }

    void setValue(int ind, TrieNode* node) {
        arr[ind] = node;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool dfs(string& word, int index, TrieNode* node) {
        if (index == word.size()) return node->flag;

        char c = word[index];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                TrieNode* next = node->getValue(i);
                if (next && dfs(word, index + 1, next)) return true;
            }
            return false;
        } else {
            TrieNode* next = node->getValue(c - 'a');
            if (!next) return false;
            return dfs(word, index + 1, next);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* p = root;
        for (char c : word) {
            int ind = c - 'a';
            if (!p->getValue(ind)) {
                p->setValue(ind, new TrieNode());
            }
            p = p->getValue(ind);
        }
        p->flag = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};
