class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string start = "";
        std::vector<string> result;
        generateParenthesisHelper(n, n, start, result);
        return result;
    }
    void generateParenthesisHelper(int remainingOpen, int remainingClosed, string current, std::vector<string>& result) {
        if (!remainingOpen && !remainingClosed) {
            result.push_back(current);
            return;
        }
        if (remainingOpen > 0) {
            string copy1 = current;
            copy1.append("(");
            generateParenthesisHelper(remainingOpen - 1, remainingClosed, copy1, result);
        }
        if (remainingClosed > 0 && remainingClosed > remainingOpen) {
            string copy2 = current;
            copy2.append(")");
            generateParenthesisHelper(remainingOpen, remainingClosed - 1, copy2, result);
        }
    }
};
