#include <vector>
#include <map>
#include <deque>
#include <iostream>

using std::vector, std::map, std::pair, std::deque, std::make_pair;

class Solution {
private:
    static constexpr int VISITED = -1;
    int gothrough(vector<pair<vector<int>, int>> &nodes, int idx) {
        int min = nodes[idx].second;
        if (min == VISITED) {
            return 10000;
        }
        nodes[idx].second = VISITED;
        for (auto node : nodes[idx].first) {
            int cur = gothrough(nodes, node);
            if (cur < min) {
                min = cur;
            }
        }
        return min;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<vector<int>, int>> nodes(n);
        for (auto road : roads) {
            nodes[road[0] - 1].first.push_back(road[1] - 1);
            nodes[road[1] - 1].first.push_back(road[0] - 1);
            if (!nodes[road[0] - 1].second || road[2] < nodes[road[0] - 1].second) {
                nodes[road[0] - 1].second = road[2];
            }
            if (!nodes[road[1] - 1].second || road[2] < nodes[road[1] - 1].second) {
                nodes[road[1] - 1].second = road[2];
            }
        }
        auto res = gothrough(nodes, 0);
        return res;
    }
};

int main()
{
    int n = 9;
    vector<vector<int>> roads = {{6,2,7},{3,7,2},{9,6,5},{2,4,9},{7,8,7},{8,4,5},{6,1,10}};
    std::cout << Solution().minScore(n, roads);
}