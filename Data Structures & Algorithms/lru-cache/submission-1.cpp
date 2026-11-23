struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
public:
    int size;
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        size = 0;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
};

class LRUCache {
private:
    unordered_map<int, Node*> node_map;
    DoublyLinkedList DLL;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (node_map.count(key) > 0) {
            int value = node_map[key]->value;
            detach(node_map[key]);
            addFront(node_map[key]);
            return value;
        }
        return -1;
    }

    void detach(Node* n) {
        n->next->prev = n->prev;
        n->prev->next = n->next;
    }

    void addFront(Node* n) {
        n->next = DLL.head->next;
        n->prev = DLL.head;
        DLL.head->next->prev = n;
        DLL.head->next = n;
    }

    void removeLeastUsed() {
        Node* leastUsed = DLL.tail->prev;
        int key = leastUsed->key;
        node_map.erase(key);
        detach(leastUsed);
        delete leastUsed;
        DLL.size--;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (node_map.count(key) == 0 && DLL.size == capacity) {
            removeLeastUsed();
            Node* n = new Node(key, value);
            addFront(n);
            node_map[key] = n;
            DLL.size++;

        } else if (node_map.count(key) > 0) {
            Node* n = node_map[key];
            n->value = value;
            detach(n);
            addFront(n);

        } else {
            Node* n = new Node(key, value);
            addFront(n);
            node_map[key] = n;
            DLL.size++;
        }
    }
};
