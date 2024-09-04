class Solution {
public:
    // Directions: north, east, south, west
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int startx = 0, starty = 0, direction = 0, max_distance = 0;

        unordered_set<string> st;
        for (auto& obstacle : obstacles) {
            st.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        for (int command : commands) {
            if (command == -2) {
                // Turn left
                direction = (direction + 3) % 4;
            } else if (command == -1) {
                // Turn right
                direction = (direction + 1) % 4;
            } else {
                // Move forward
                for (int i = 0; i < command; ++i) {
                    int tempx = startx + dir[direction][0];
                    int tempy = starty + dir[direction][1];
                    if (st.find(to_string(tempx) + "," + to_string(tempy)) != st.end()) {
                        break;  // Stop moving if there's an obstacle
                    }
                    startx = tempx;
                    starty = tempy;
                    max_distance = max(max_distance, startx * startx + starty * starty);
                }
            }
        }

        return max_distance;
    }
};