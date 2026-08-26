class Solution {
public:
    bool exist(int u[], int need[]) {
        for (int i = 0; i < 128; i++) {
            if (u[i] < need[i])
                return false;
        }
        return true;
    }

    string minWindow(string s, string t) {

        int u[128] = {};
        int need[128] = {};

        for (char c : t)
            need[c]++;

        string mins = "";
        string k = "";

        int mini = INT_MAX;
        int j = 0;

        for (int i = 0; i < s.size(); i++) {

            u[s[i]]++;
            k += s[i];

            while (exist(u, need)) {

                if (i - j + 1 < mini) {
                    mini = i - j + 1;
                    mins = k;
                }

                u[s[j]]--;
                k.erase(k.begin());
                j++;
            }
        }

        return mins;
    }
};