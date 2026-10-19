class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        if(stones.size() == 0) {
            return 0; 
        }

        if(stones.size() == 1) {
            return stones[0]; 
        }

        std::priority_queue<int> pq;

        for(int s : stones) {
            pq.push(s); 
        }; 

        /*
        2 2 3 4 6
        2 2 2 3 
        1 2 2 
        1 

        */

        while(pq.size() > 1) {
            int x = pq.top(); 
            pq.pop(); 
            int y = pq.top(); 
            pq.pop(); 

            if(x == y) {
                continue; 
            } else {
                pq.push(abs(x - y));
            }
        }; 

        return pq.empty() ? 0 : pq.top(); 
    }
};
