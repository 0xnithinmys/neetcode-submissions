class Solution {
public:
    string encode(vector<string>& strs) {
        string k = "";
        for (string& s : strs) {
            k += to_string(s.size()) + "#" + s;
        }
        return k;
    }

    vector<string> decode(string s) {
        vector<string> v;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (j < s.size() && s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            j++; 
            string str = s.substr(j, len);
            v.push_back(str);
            i = j + len;
        }
        return v;
    }
};
