class KthLargest {
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int k_val; // store k

public:
    KthLargest(int k, vector<int>& nums) {
        k_val = k;
        for (int n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k_val) {
            pq.pop();
        }
        return pq.top(); 
    }
};