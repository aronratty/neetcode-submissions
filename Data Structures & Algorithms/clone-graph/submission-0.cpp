class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr) {
            return NULL; 
        }

        unordered_map<Node*, Node*> mp;
        queue<Node*> q; 

        mp[node] = new Node(node->val); 
        q.push(node); 

        while(!q.empty()) {
            Node* front = q.front();
            q.pop(); 

        
            for(auto n : front->neighbors) {
                if(mp.find(n) == mp.end()) {
                    mp[n] = new Node(n->val); 
                    q.push(n); 
                }

                mp[front]->neighbors.push_back(mp[n]); 
            }
        }

        
        return mp[node]; 
    }
};