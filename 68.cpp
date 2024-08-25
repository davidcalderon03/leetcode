class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        while (i < words.size()) {
            string current_line = "";
            std::vector<string> words_for_line(0);
            std::vector<int> num_spaces(0);
            int space_used = 0;
            words_for_line.push_back(words[i]);
            space_used += words[i].length();
            ++i;
            while (i < words.size() && true) {
                if (space_used + 1 + words[i].length() <= maxWidth) {
                    words_for_line.push_back(words[i]);
                    num_spaces.push_back(1);
                    space_used += (1 + words[i].length());
                    ++i;
                } else {
                    break;
                }
            }

            // Distribute spaces out
            for (int j = 0; num_spaces.size() && 
                            i < words.size() && space_used < maxWidth; ++j) {
                num_spaces[j % num_spaces.size()]++;
                space_used++;
            }

            // Add all content to line
            for (int k = 0; k < words_for_line.size() - 1; ++k) {
                current_line += (words_for_line[k]);
                for (int z = 0; z < num_spaces[k]; ++z)  current_line += ' ';
            }
            if (words_for_line.size() > 0) current_line
            += words_for_line[words_for_line.size() - 1];
            while (current_line.length() < maxWidth) {
                current_line += ' ';
            }
            result.push_back(current_line);
        }
        return result;
    }
};
