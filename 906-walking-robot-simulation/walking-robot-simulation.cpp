using ll = long long;

class Solution {
public:
    pair<int, int> new_cord(int x, int y, char dir, int k) {
        switch (dir) {
        case 'n': y += k; break;
        case 'e': x += k; break;
        case 'w': x -= k; break;
        case 's': y -= k; break;
        }
        return {x, y};
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        ll x = 0, y = 0;
        vector<char> dirns = {'n', 'e', 's', 'w'};
        int dir = 0;

        // Convert obstacles to a set of pairs for faster lookup
        set<pair<int, int>> obstacle_set;
        for (auto& o : obstacles) {
            obstacle_set.insert({o[0], o[1]});
        }

        int max_dist = 0;

        for (auto i : commands) {
            if (i == -1) {
                dir = (dir + 1) % 4;
            }
            else if (i == -2) {
                dir = (dir + 3) % 4;  // equivalent to (dir - 1 + 4) % 4 to handle negative
            }
            else {
                for (int step = 0; step < i; ++step) {
                    pair<int, int> next_step = new_cord(x, y, dirns[dir], 1);
                    if (obstacle_set.find(next_step) != obstacle_set.end()) {
                        break; // stop moving if an obstacle is found
                    }
                    x = next_step.first;
                    y = next_step.second;
                    int dist = (x*x) + (y*y);
                    max_dist = max(max_dist,dist);
                }
            }
        }

        return max_dist;
    }
};
