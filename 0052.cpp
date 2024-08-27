class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<vector<int>>> solutions;
        set<int> used_cols;
        set<int> used_diagonals;
        set<int> used_diagonals_2;
        vector<vector<int>> starter(n, vector<int>(n));
        helper(starter, 0, used_cols, used_diagonals, used_diagonals_2, n, solutions);

        vector<vector<string>> final_solution;
        for (int i = 0; i < solutions.size(); ++i) {
            vector<string> current_solution;
            for (int j = 0; j < n; ++j) {
                string current_string = "";
                for (int k = 0; k < n; ++k) {
                    if (solutions[i][j][k] == 1) {
                        current_string += "Q";
                    } else {
                        current_string += ".";
                    }
                }
                current_solution.push_back(current_string);
            }
            final_solution.push_back(current_solution);
        }
        return final_solution.size();
    }

    void helper(vector<vector<int>> current, int num_placed, set<int> used_cols, set<int> used_diagonals, set<int> used_diagonals_2, int n, vector<vector<vector<int>>>& solutions) {
        std::cout << "New one: " << std::endl;
        for (int i = 0; i < current.size(); ++i) {
            for (int j = 0; j < current[0].size(); ++j) {
                std::cout << current[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Stack: ";

        for (const auto& item : used_cols) {
            std::cout << item << " ";
        }
        std::cout << std::endl << std::endl;


        if (num_placed == n) {
            solutions.push_back(current);
        }
        for (int i = 0; i < current.size(); ++i) {
            if (used_cols.find(i) == used_cols.end() &&
                used_diagonals.find(i + num_placed) == used_diagonals.end() &&
                used_diagonals_2.find(i - num_placed) == used_diagonals_2.end()) {
                used_cols.insert(i);
                used_diagonals.insert(i + num_placed);
                used_diagonals_2.insert(i - num_placed);
                current[num_placed][i] = 1;
                helper(current, num_placed + 1, used_cols, used_diagonals, used_diagonals_2, n, solutions);
                used_cols.erase(i);
                used_diagonals.erase(i + num_placed);
                used_diagonals_2.erase(i - num_placed);
                current[num_placed][i] = 0;
            }
        }
    }
};
