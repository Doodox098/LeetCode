#include <iostream>
#include <vector>
#include <algorithm>

class MyCalendarTwo {
private:
    std::vector<int> starts;
    std::vector<int> ends;
    int count_interval;
public:
    MyCalendarTwo() {
        starts = {};
        ends = {};
        count_interval = 0;
    }

    bool book(int start, int end) {
        std::vector<int> intersections_starts = {};
        std::vector<int> intersections_ends = {};
        int intersections_count = 0;
        for (int i = 0; i < count_interval; i++) {
            if((start >= starts[i] && start < ends[i])
                    || (starts[i] >= start && starts[i] < end)) {
                intersections_starts.vector::push_back(std::max(start, starts[i]));
                intersections_ends.vector::push_back(std::min(end, ends[i]));
                intersections_count++;
            }
        }
        for (int i = 0; i < intersections_count - 1; i++) {
            for (int j = i + 1; j < intersections_count; j++) {
                if((intersections_starts[i] >= intersections_starts[j] && intersections_starts[i] < intersections_ends[j])
                   || (intersections_starts[j] >= intersections_starts[i] && intersections_starts[j] < intersections_ends[i])) {
                    return false;
                }
            }
        }
        starts.vector::push_back(start);
        ends.vector::push_back(end);
        count_interval++;
        return true;
    }
};

int main() {
    auto* obj = new MyCalendarTwo();
//    std::cout << obj->book(10, 20) << ' ';
//    std::cout << obj->book(50, 60) << ' ';
//    std::cout << obj->book(10, 40) << ' ';
//    std::cout << obj->book(5, 15) << ' ';
//    std::cout << obj->book(5, 10) << ' ';
//    std::cout << obj->book(25, 55) << ' ';

    std::cout << obj->book(26, 35) << ' ';
    std::cout << obj->book(26, 32) << ' ';
    std::cout << obj->book(25, 32) << ' ';
    std::cout << obj->book(18, 26) << ' ';
    std::cout << obj->book(40, 45) << ' ';
    std::cout << obj->book(19, 26) << ' ';
    std::cout << obj->book(48, 50) << ' ';
    std::cout << obj->book(1, 6) << ' ';
    std::cout << obj->book(46, 50) << ' ';
    std::cout << obj->book(11, 18) << ' ';

    return 0;
}
