class MinStack {
public:

    vector<int> v; 
    std::multiset<int> ms; 
    MinStack() : v{} , ms{} {
        
    }
    
    void push(int val) {
        this->v.push_back(val); 
        this->ms.insert(val); 
    }
    
    void pop() {
        int val = top(); 
        this->v.pop_back(); 
        this->ms.erase(ms.find(val)); 
    }
    
    int top() {
        return this->v[v.size() - 1]; 
    }
    
    int getMin() {
        return *(this->ms.begin()); 
    }
};
