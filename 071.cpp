class Solution {
public:
    string simplifyPath(string path) {
        string final_path = "/";
        if (path.at(path.size() - 1) == '/') path = path.substr(0, path.size() - 1);
        for (int i = 1; i < path.size(); ++i) {
            if (path.at(i) == '/' && path.at(i - 1) == '/') {
                path = path.substr(0, i - 1) + path.substr(i);
                --i;
            }
        }
        vector<string> separated = separateByDelimiter(path, '/');
        for (int i = 0; i < separated.size(); ++i) {
            std::cout << separated[i];
        }

        stack<string> word_stack;

        for (int i = 0; i < separated.size(); ++i) {
            if (separated[i] == ".." && !word_stack.empty()) {
                word_stack.pop();
            } else if (separated[i] != ".." && separated[i] != ".") {
                word_stack.push(separated[i]);
            }
        }
        while (!word_stack.empty()) {
            final_path = "/" + word_stack.top() + final_path;
            word_stack.pop();
        }
        if (final_path.at(final_path.size() - 1) == '/' && final_path.size() > 1) {
            final_path = final_path.substr(0, final_path.size() - 1);
        }
        return final_path;
    }

    vector<string> separateByDelimiter(string s, char delimiter) {
        std::string current = "";
        vector<string> separated;
        for (int i = 0; i < s.length(); ++i) {
            if (s.at(i) == delimiter && current.length() > 0) {
                separated.push_back(current);
                current = "";
            } else if (s.at(i) != delimiter) {
                current += s.at(i);
            }
        }
        if (current.size() > 0) separated.push_back(current);
        return separated;
    }
};
