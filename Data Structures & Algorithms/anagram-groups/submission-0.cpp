class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> u;
        
        for (string s : strs) {
            string k = s;
            sort(k.begin(), k.end());
            u[k].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& i : u) {
            result.push_back(i.second);
        }

        return result;
    }
};
