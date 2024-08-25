class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.compare("0") == 0 || num2.compare("0") == 0) return "0";
        std::vector<string> adding;
        std::vector<char> digits;
        string result;
        for (int i = num1.length() - 1; i >= 0; --i) {
            string current;
            int carry = 0;
            int filled_zeroes = num1.length() - 1 - i;
            current.insert(0, filled_zeroes, '0'); // Insert filled_zeroes amount of times
            for (int j = num2.length() - 1; j >= 0; --j) {
                char c1 = num1.at(i);
                char c2 = num2.at(j);
                int digit1 = c1 - '0';
                int digit2 = c2 - '0';
                int multiplied = digit1 * digit2 + carry;
                carry = multiplied / 10;
                multiplied = multiplied % 10;
                current.insert(0, 1, char(multiplied + '0'));
            }
            if (carry > 0) {
                current.insert(0, 1, char(carry + '0'));
            }
            adding.push_back(current);
        }
        int carry = 0;
        int place = 0;
        for (string s : adding) {
            std::cout << s << std::endl;
        }
        while (true) {
            int sum = carry;
            int valid = false;
            for (int i = 0; i < adding.size(); ++i) {
                if ((signed int)(adding[i].length() - 1 - place) >= 0) {
                    valid = true;
                    char c1 = adding[i].at(adding[i].length() - 1 - place);
                    sum += c1 - '0';
                }
            }
            if (!valid && carry == 0) break;
            carry = sum / 10;
            sum = sum % 10;
            digits.insert(digits.begin(), char(sum + '0'));
            place++;
            if (!valid) break;
        }
        for (int i = 0; i < digits.size(); ++i) {
            result.push_back(digits[i]);
        }
        return result;
    }
};
