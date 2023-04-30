#include <vector>
#include <map>
#include <deque>
#include <iostream>

using std::vector, std::map, std::pair, std::deque, std::make_pair;

class Solution {
private:
    struct Node
    {
        unsigned id{};
        bool visited{};
        map<unsigned, pair<Node*, unsigned>> connections{};
        Node(unsigned id):id(id), visited(false){};
        void connect(Node* other, unsigned dst) {
            if (connections.try_emplace(other->id, other, dst).second)
                other->connections.try_emplace(id, this, dst);
        }
    };
    unsigned gothrough(Node* cur) {
        unsigned min = 10000;
        if (!cur->visited) {
            cur->visited = true;
            for (auto &elem: cur->connections) {
                if (elem.second.second < min)
                    min = elem.second.second;
                auto res = gothrough(elem.second.first);
                if (res < min)
                    min = res;
            }
        }
        return min;
    }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<Node*> nodes;
        for (int i = 0; i < n; ++i) {
            Node* new_node = new Node(i);
            nodes.push_back(new_node);
        }
        for (auto road : roads) {
            nodes[road[0] - 1]->connect(nodes[road[1] - 1], road[2]);
        }
        auto res = gothrough(nodes[0]);
        for (auto node : nodes) {
            delete node;
        }
        return res;
    }
};

int main()
{
    int n = 9;
    vector<vector<int>> roads = {{6,2,7},{3,7,2},{9,6,5},{2,4,9},{7,8,7},{8,4,5},{6,1,10}};
    std::cout << Solution().minScore(n, roads);
}

