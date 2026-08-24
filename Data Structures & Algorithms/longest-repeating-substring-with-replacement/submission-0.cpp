class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> freq;

        int j = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            freq[s[i]]++;

            maxFreq = max(maxFreq, freq[s[i]]);

            int replacements = (i - j + 1) - maxFreq;

            while (replacements > k) {

                freq[s[j]]--;
                j++;

                replacements = (i - j + 1) - maxFreq;
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};