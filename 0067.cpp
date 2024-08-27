class Solution {
public:
    string addBinary(string a, string b) {
        int i = 0, j = 0;
        int carry = 0;
        string result = "";
        while (i < a.length() || j < b.length()) {
            int current = carry;
            if (i < a.length() && a.at(a.length() - 1 - i) == '1') {
                current++;
            }
            if (j < b.length() && b.at(b.length() - 1 - j) == '1') {
                current++;
            }
            switch(current) {
                case 0: result = "0" + result; carry = 0; break;
                case 1: result = "1" + result; carry = 0; break;
                case 2: result = "0" + result; carry = 1; break;
                case 3: result = "1" + result; carry = 1; break;
            }
            i++; j++;
        }
        if (carry == 1) result = "1" + result;
        return result;
    }
};
