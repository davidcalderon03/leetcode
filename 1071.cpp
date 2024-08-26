class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string result = "";
        int n = min(str1.size(), str2.size());
        unordered_map<int, string> possibilities;
        while (str1.size() % n != 0 || str2.size() % n != 0) --n;
        while (n > 0) {
            possibilities[n] = str1.substr(0, n);
            --n;
            while (n > 0 && (str1.size() % n != 0 || str2.size() % n != 0)) --n;
        }
        
        for (const auto& [k, v] : possibilities) {
            string current1 = "";
            string current2 = "";
            for (int i = 0; i < str1.size() / k; ++i) {
                current1 += v;
            }
            for (int i = 0; i < str2.size() / k; ++i) {
                current2 += v;
            }
            if (current1 == str1 && current2 == str2 && result.size() < current2.size()) result = v;
        }
        return result;
    }
};
