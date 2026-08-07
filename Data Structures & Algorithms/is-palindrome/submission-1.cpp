class Solution {
public:
    bool isPalindrome(string s) {

        string t;


        for(int i =0;i<s.size();i++){
            if(isalnum(s[i])){
                t+=tolower(s[i]);

            }
        }

        int n = t.size()-1;

        int j = 0;

        while(j<n){
            if(t[j] != t[n]){
                return false;
            }
            j++;
            n--;
        }

        return true;
        
    }
};
