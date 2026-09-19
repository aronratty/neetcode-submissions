class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr; // Handle empty list

        Node* dummy = new Node(0); 
        Node* currNew = dummy; 
        Node* iter = head; 
        unordered_map<Node*, Node*> m; 

        while (iter != NULL) {
            Node* replace = new Node(iter->val); 
            currNew->next = replace; 
            m[iter] = replace;       
            
            iter = iter->next;  
            currNew = currNew->next; 
        }

    
        iter = head;
        currNew = dummy->next;
        while (iter != NULL) {
            if (iter->random != NULL) {
                currNew->random = m[iter->random];
            } else {
                currNew->random = nullptr;
            }
            
            iter = iter->next;
            currNew = currNew->next;
        }

        return dummy->next;
    }
};