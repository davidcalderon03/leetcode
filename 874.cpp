class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int max_dist = 0;
        set<vector<int>> obstacles_as_set;
        queue<int> commands_as_queue;
        for (int command : commands) commands_as_queue.push(command);
        for (vector<int> obstacle : obstacles) obstacles_as_set.insert(obstacle);
        helper(x, y, commands_as_queue, obstacles_as_set, 0, 0, max_dist);
        std::cout << "X: " << x << std::endl;
        std::cout << "Y: " << y << std::endl;
        return max_dist;
    }

    void helper(int x, int y, queue<int>& commands, set<vector<int>>& obstacles, int current_command, int direction, int& max_dist) {
        if (x * x + y * y > max_dist) max_dist = x * x + y * y;
        std::cout << "Direction: " << direction << std::endl;
        if (current_command == 0 && commands.size() == 0) {
            return;
        } else if (current_command == 0) {
            current_command = commands.front();
            std::cout << "New command: " << current_command << std::endl;
            commands.pop();
        }
        if (current_command == -1) {
            direction = (direction + 1) % 4;
            current_command = 0;
        } else if (current_command == -2) {
            direction --;
            if (direction == -1) direction = 3;
            current_command = 0;
        } else {
            current_command--;
            int new_x = x;
            int new_y = y;
            if (direction == 0) new_y++;
            else if (direction == 1) new_x++;
            else if (direction == 2) new_y--;
            else if (direction == 3) new_x--;
            else std::cout << "ERROR" << std::endl;
            if (!obstacles.contains({new_x, new_y})) {
                x = new_x;
                y = new_y;
            }
        }
        helper(x, y, commands, obstacles, current_command, direction, max_dist);


    }
};
