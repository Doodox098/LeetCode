#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

using namespace std;
class Solution {
    struct DisjointSet {
        typedef map<int, map<int, int>> comp_t;
        vector<comp_t> graph{};
        void MakeSet(int &x) {
            comp_t new_m{};
            new_m.emplace(x, map<int, int>());
            graph.push_back(new_m);
        };
        int Find(int &x) {
            int i = 0;
            for (auto & component : graph) {
                if (component.find(x) != component.end())
                    return i;
                ++i;
            }
            MakeSet(x);
            return i;
        }
        void Union(int &x, int &y) {
            int dst = Find(x), src = Find(y);
            graph[dst].merge(graph[src]);
            auto it = graph.begin();
            advance(it, src);
            graph.erase(it);
        }
        void makeEdge(int &a, int &b, int &dst) {
            auto c1 = Find(a);
            auto c2 = Find(b);
            if (c1 != c2) {
                Union(a, b);
            }
            if (graph[c1][a].find(b) != graph[c1][a].end()) {
                if (graph[c1][a][b] > dst) {
                    graph[c1][a][b] = dst;
                    graph[c1][b][a] = dst;
                }
            } else {
                graph[c1][a][b] = dst;
                graph[c1][b][a] = dst;
            }
        }
    };
    int pathExists(DisjointSet::comp_t& component, int &a,  int &b, int &lim, list<int> &visited) {
        if (find(visited.begin(), visited.end(), a) != visited.end()) {
            return lim;
        }
        visited.push_back(a);
        map<int, int> &connections = component[a];
        int min = lim;
        for (auto &elem: connections) {
            if (elem.first == b) {
                if (elem.second < lim)
                    return elem.second;
                continue;
            }
            if (elem.second > lim) continue;
            int cur_min = pathExists(component, const_cast<int &>(elem.first), b, lim, visited);
            if (cur_min < min) {
                min = cur_min;
            }
        }
        return min;
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(), false);
        DisjointSet set;
        for (auto &edge : edgeList) {
            set.makeEdge(edge[0], edge[1], edge[2]);
        }
        auto it = ans.begin();
        for (auto &query : queries) {
            auto component = set.Find(query[0]);
            if (set.Find(query[1]) != component) {
                continue;
            }
            list<int> visited;
            *it = pathExists(set.graph[component], query[0], query[1], query[2], visited) != query[2];
            ++it;
        }
        return ans;
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> edgeList = {{0, 1, 2}, {1, 2, 4}, {2, 0, 8}, {1, 0, 16}};
    vector<vector<int>> queries = {{0, 1, 3}, {0, 2, 5}};
    vector<bool> ans = Solution().distanceLimitedPathsExist(n, edgeList, queries);
    for (auto e: ans) {
        cout << e;
    }
}