#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        // color[m][c][turn]: 0 = Draw/Unknown, 1 = Mouse Win, 2 = Cat Win
        // turn: 1 = Mouse's turn, 2 = Cat's turn
        int color[50][50][3] = {0};
        int degree[50][50][3] = {0};

        // Initialize degrees for each state
        for (int m = 0; m < n; ++m) {
            for (int c = 0; c < n; ++c) {
                degree[m][c][1] = graph[m].size();
                degree[m][c][2] = graph[c].size();
                for (int node : graph[c]) {
                    if (node == 0) {
                        // Cat cannot move to hole (node 0)
                        degree[m][c][2]--;
                        break;
                    }
                }
            }
        }

        // Queue for BFS propagation: store {m, c, turn, result}
        queue<vector<int>> q;

        // Populate terminal states
        for (int i = 0; i < n; ++i) {
            for (int t = 1; t <= 2; ++t) {
                // Mouse at Hole -> Mouse Wins (1)
                color[0][i][t] = 1;
                q.push({0, i, t, 1});

                // Cat catches Mouse -> Cat Wins (2)
                if (i != 0) {
                    color[i][i][t] = 2;
                    q.push({i, i, t, 2});
                }
            }
        }

        // Retrograde BFS
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int m = curr[0], c = curr[1], turn = curr[2], result = curr[3];

            // Target state reached?
            if (m == 1 && c == 2 && turn == 1) return result;

            // Find all parent states that can transition into the current state
            int prev_turn = (turn == 1) ? 2 : 1;

            if (prev_turn == 1) { // Previous turn was Mouse
                for (int prev_m : graph[m]) {
                    if (color[prev_m][c][1] != 0) continue; // Already decided

                    // If Mouse can move to a winning state for Mouse
                    if (result == 1) {
                        color[prev_m][c][1] = 1;
                        q.push({prev_m, c, 1, 1});
                    } 
                    // Decrement remaining degree
                    else if (--degree[prev_m][c][1] == 0) { // All moves lead to Cat Win
                        color[prev_m][c][1] = 2;
                        q.push({prev_m, c, 1, 2});
                    }
                }
            } else { // Previous turn was Cat
                for (int prev_c : graph[c]) {
                    if (prev_c == 0 || color[m][prev_c][2] != 0) continue; // Already decided or invalid

                    // If Cat can move to a winning state for Cat
                    if (result == 2) {
                        color[m][prev_c][2] = 2;
                        q.push({m, prev_c, 2, 2});
                    } 
                    // Decrement remaining degree
                    else if (--degree[m][prev_c][2] == 0) { // All moves lead to Mouse Win
                        color[m][prev_c][2] = 1;
                        q.push({m, prev_c, 2, 1});
                    }
                }
            }
        }

        // If initial state (1, 2, Mouse's turn) isn't resolved, it's a draw
        return color[1][2][1];
    }
};