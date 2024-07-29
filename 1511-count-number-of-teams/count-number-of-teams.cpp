class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
    
    // Vectors to store the count of elements greater and smaller for each index
    std::vector<int> greater_count(n, 0);
    std::vector<int> smaller_count(n, 0);

    // Calculate the number of elements greater than the current element for each index
    for (int i = 0; i < n; ++i) {
        int count_greater = 0;
        for (int j = i + 1; j < n; ++j) {
            if (rating[j] > rating[i]) {
                count_greater++;
            }
        }
        greater_count[i] = count_greater;
    }

    // Calculate the number of elements smaller than the current element for each index
    for (int i = 0; i < n; ++i) {
        int count_smaller = 0;
        for (int j = i + 1; j < n; ++j) {
            if (rating[j] < rating[i]) {
                count_smaller++;
            }
        }
        smaller_count[i] = count_smaller;
    }

    int total_teams = 0;

    // Count increasing triplets
    for (int j = 0; j < n; ++j) {
        // Number of elements less than rating[j] to the left
        int left_smaller = 0;
        for (int i = 0; i < j; ++i) {
            if (rating[i] < rating[j]) {
                left_smaller++;
            }
        }
        // Number of elements greater than rating[j] to the right
        int right_greater = greater_count[j];
        total_teams += left_smaller * right_greater;
    }

    // Count decreasing triplets
    for (int j = 0; j < n; ++j) {
        // Number of elements greater than rating[j] to the left
        int left_greater = 0;
        for (int i = 0; i < j; ++i) {
            if (rating[i] > rating[j]) {
                left_greater++;
            }
        }
        // Number of elements smaller than rating[j] to the right
        int right_smaller = smaller_count[j];
        total_teams += left_greater * right_smaller;
    }

    return total_teams;
    }
};