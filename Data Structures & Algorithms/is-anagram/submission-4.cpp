class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char,int> u;


        for(char i : s){
            u[i]++;
        }


        for(char i: t ){
            if(u[i]> 0){
                u[i]--;
            }else{
                return false;
            }
        }

        for(auto i : u){
            if(i.second > 0)return false;
        }


        return true;


      
        
    }
};
