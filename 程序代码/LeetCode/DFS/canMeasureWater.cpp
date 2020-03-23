#include<iostream>
#include<vector>
#include<stack>
#include<unordered_set>
#include<set>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        stack<pair<int,int>> stk;
        set<pair<int,int>> seen;
        //hash_set不能装pair，所以这里要用set，但是会出现超时
        stk.push(make_pair(0,0));
        while(!stk.empty()){
            if (seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.insert(stk.top());

            pair<int,int> a=stk.top();
            stk.pop();
            if(a.first==z||a.second==z||a.first+a.second==z) return true;
            // 把 X 壶灌满。
            stk.emplace(x, a.second);
            // 把 Y 壶灌满。
            stk.emplace(a.first, y);
            // 把 X 壶倒空。
            stk.emplace(0, a.second);
            // 把 Y 壶倒空。
            stk.emplace(a.first, 0);
            // 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
            stk.emplace(a.first - min(a.first, y - a.second), a.second + min(a.first, y - a.second));
            // 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
            stk.emplace(a.first + min(a.second, x - a.first), a.second - min(a.second, x - a.first));            
        }

        return false;
    }
};

using PII = pair<int, int>;

class Solution2 {
public:
    bool canMeasureWater(int x, int y, int z) {
        stack<PII> stk;
        stk.emplace(0, 0);
        auto hash_function = [](const PII& o) {return hash<int>()(o.first) ^ hash<int>()(o.second);};
        unordered_set<PII, decltype(hash_function)> seen(0, hash_function);       
        while (!stk.empty()) {
            if (seen.count(stk.top())) {
                stk.pop();
                continue;
            }
            seen.emplace(stk.top());
            
            auto [remain_x, remain_y] = stk.top();
            stk.pop();
            if (remain_x == z || remain_y == z || remain_x + remain_y == z) {
                return true;
            }
            // 把 X 壶灌满。
            stk.emplace(x, remain_y);
            // 把 Y 壶灌满。
            stk.emplace(remain_x, y);
            // 把 X 壶倒空。
            stk.emplace(0, remain_y);
            // 把 Y 壶倒空。
            stk.emplace(remain_x, 0);
            // 把 X 壶的水灌进 Y 壶，直至灌满或倒空。
            stk.emplace(remain_x - min(remain_x, y - remain_y), remain_y + min(remain_x, y - remain_y));
            // 把 Y 壶的水灌进 X 壶，直至灌满或倒空。
            stk.emplace(remain_x + min(remain_y, x - remain_x), remain_y - min(remain_y, x - remain_x));
        }
        return false;
    }
};