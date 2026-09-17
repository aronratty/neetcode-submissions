#include <vector>
#include <stack>
#include <algorithm>
#include <ranges> // Required for std::views::zip

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        struct Car {
            int pos; 
            int vel; 
        };

        std::vector<Car> v; 

        for(const auto& [pos, vel] : std::views::zip(position, speed)) {
            v.push_back({pos, vel}); 
        }

        std::ranges::sort(v, [](const Car& a, const Car& b) { return a.pos < b.pos; });

        std::stack<double> s; 

        for(int i = v.size() - 1; i >= 0; i--) {
            
            double time = (double)(target - v[i].pos) / v[i].vel; 
            
            if(s.empty() || time > s.top()) {
                s.push(time); 
            }
        } 

        return s.size(); 
    }
};