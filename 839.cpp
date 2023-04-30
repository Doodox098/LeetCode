#include <vector>
#include <string>
#include <list>
using namespace std;
using namespace std;
class Solution {
    int diff(string& a, string& b) {
        int cnt = 0;
        for (int i = 0; i < a.length() ; ++i) {
            if (a[i] != b[i]) ++cnt;
            if (cnt > 2)
                break;
        }
        return cnt;
    }
    bool belong(string & str, list<string> & group) {
        for (auto &elem : group) {
            if (diff(elem, str) <= 2) {
                return true;
            }
        }
        return false;
    }
public:
    int numSimilarGroups(vector<string>& strs) {
        vector<list<string>> groups;
        for (auto & str: strs) {
            vector <int> belongs_to{};
            auto group = groups.begin();
            for (int i = 0; i < groups.size(); ++i, ++group) {
                if (belong(str, *group)) {
                    belongs_to.push_back(i);
                }
            }
            if (belongs_to.empty()) {
                groups.emplace_back();
                (groups.end() - 1)->push_back(str);
                continue;
            }
            groups[belongs_to[0]].push_back(str);
            for (int i = 1; i < belongs_to.size(); ++i) {
                groups[belongs_to[0]].insert(groups[belongs_to[0]].end(),
                                             groups[belongs_to[i]].begin(), groups[belongs_to[i]].end());
                auto it = groups.begin();
                advance(it, belongs_to[i]);
                groups.erase(it);
            }
        }
        return groups.size();
    }
};

int main() {
    vector<string> strs = {"tars","rats","arts","star"};
    return Solution().numSimilarGroups(strs);
}