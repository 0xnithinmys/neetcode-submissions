class PrefixTree {
public:
    PrefixTree* child[26];
    bool isend;

    PrefixTree() {
        isend = false;

        for (int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }

    void insert(string word) {
        PrefixTree* t = this;

        for (char c : word) {
            int idx = c - 'a';

            if (t->child[idx] == nullptr) {
                t->child[idx] = new PrefixTree();
            }

            t = t->child[idx];
        }

        t->isend = true;
    }

    bool search(string word) {
        PrefixTree* t = this;

        for (char c : word) {
            int idx = c - 'a';

            if (t->child[idx] == nullptr) {
                return false;
            }

            t = t->child[idx];
        }

        return t->isend;
    }

    bool startsWith(string prefix) {
        PrefixTree* t = this;

        for (char c : prefix) {
            int idx = c - 'a';

            if (t->child[idx] == nullptr) {
                return false;
            }

            t = t->child[idx];
        }

        return true;
    }
};