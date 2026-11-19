
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);

        for(char t : tasks) {
            count[t - 'A']++;
        }

        priority_queue<int> maxheap;

        for(int c : count) {
            if(c > 0) {
                maxheap.push(c);
            }
        }

        queue<pair<int, int>> q;

        int time = 0;

        while(!maxheap.empty() || !q.empty()) {
            if(maxheap.empty() && !q.empty()) {
                time = q.front().second;
                maxheap.push(q.front().first);
                q.pop();
            } else {

                if(!q.empty() && q.front().second <= time) {
                    maxheap.push(q.front().first);
                    q.pop(); 
                }

                int topCount = maxheap.top();
                maxheap.pop();
                topCount--;

                if(topCount > 0) {
                    q.push({topCount, time + n + 1});
                }

                time++;
            }
        }

        return time;
    }
};
