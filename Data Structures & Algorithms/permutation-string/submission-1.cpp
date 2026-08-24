class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.size() > s2.size())
            return false;

        vector<int> need(26, 0);
        vector<int> window(26, 0);

        for (char c : s1) {
            need[c - 'a']++;
        }

        int j = 0;

        for (int i = 0; i < s2.size(); i++) {

            window[s2[i] - 'a']++;

            if (i - j + 1 > s1.size()) {
                window[s2[j] - 'a']--;
                j++;
            }

            if (window == need) {
                return true;
            }
        }

        return false;
    }
};