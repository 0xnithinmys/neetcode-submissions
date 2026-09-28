class WordDictionary {
   public:
    bool isend;
    WordDictionary* child[26];

    WordDictionary() {
        isend = false;
        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }

    void addWord(string word) {
        WordDictionary* t = this;

        for (auto i : word) {
            int idx = i - 'a';

            if (t->child[idx] == nullptr) {
                t->child[idx] = new WordDictionary();
            }
            t = t->child[idx];
        }

        t->isend = true;
    }

    bool dfs(WordDictionary* t, string s, int x) {
        if (x == s.size()) {
            return t->isend;
        }

        char c = s[x];

        if (c != '.') {
            int idx = c - 'a';

            if (t->child[idx] == nullptr) {
                return false;
            }

            t = t->child[idx];
            return dfs(t, s, x + 1);
        }

        //.case

        for (int i = 0; i < 26; i++) {
            if (t->child[i] != nullptr) {
                if (dfs(t->child[i], s, x + 1)) return true;
            }
        }

        return false;
    }

    bool search(string word) {
        WordDictionary* t = this;

        return dfs(t, word, 0);
    }
};
