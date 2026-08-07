class Solution {
public:
    string addBinary(string a, string b) {

        int n1 = a.size() - 1;
        int n2 = b.size() - 1;

        string r = "";
        int carry = 0;

        while (n1 >= 0 || n2 >= 0 || carry) {

            int b1 = (n1 >= 0) ? a[n1] - '0' : 0;
            int b2 = (n2 >= 0) ? b[n2] - '0' : 0;

            int total = b1 + b2 + carry;

            r = char((total % 2) + '0') + r;
            carry = total / 2;

            n1--;
            n2--;
        }

        return r;
    }
};