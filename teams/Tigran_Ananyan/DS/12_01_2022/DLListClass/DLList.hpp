struct Node {
    int data;
    Node* next;
    Node* prev;

    Node();

    Node(int);


};

struct DLList {
    int size = 0;
    Node* head;
    Node* tail;

    DLList();

    DLList(const DLList& d);

    ~DLList();

    void pushBack(int);

    void pushFront(int);

    void popBack();

    void popFront();

    void insert(int, int);

    void remove(int);

    void print();
};
