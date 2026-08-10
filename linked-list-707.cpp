class MyLinkedList {
private:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int v): val(v), next(nullptr) {}
    };
    int size;
    ListNode* dummyHead;
public:
    MyLinkedList() {
        dummyHead = new ListNode(0);
        size = 0;
    }
    
    int get(int index) {
        if (index >= size) return -1;
        ListNode* curr = dummyHead->next;
        int count = 0;
        while (count != index) {
            count++;
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = dummyHead->next;
        dummyHead->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* curr = dummyHead;
        while (curr->next != nullptr) curr = curr->next;
        curr->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index == size) addAtTail(val);
        else if (index > size) return;
        else {
            ListNode* curr = dummyHead;
            int count = 0;
            while (count < index) {
                count++;
                curr = curr->next;
            }
            ListNode* newNode = new ListNode(val);
            newNode->next = curr->next;
            curr->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index >= size) return;
        ListNode* curr = dummyHead;
        int count = 0;
        while (count < index) {
            count++;
            curr = curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */