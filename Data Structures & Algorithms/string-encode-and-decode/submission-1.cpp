class Solution {
public:

    string encode(vector<string>& strs) {

        string r;

        for(string s : strs){

            int sz = s.size();

            r+=to_string(sz)+'#';

            r+=s;

        }

        return r;




    }

    vector<string> decode(string s) {

        vector<string> r;

        int i = 0;

        while(i<s.size()){
            int j = s.find('#',i);

            int len = stoi(s.substr(i,j-i));

            i=j+1;
            r.push_back(s.substr(i,len));

            i+=len;

        }

        return r;







    }
};
