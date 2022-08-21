#ifndef NODE
#define NODE

class Node {
private:
    Node *prev;
    char symb;

public:
    Node();

    Node(char symb, Node *prev);

    char getSymb() const;

    void setSymb(char symb);

    Node* getPrev() const;

    void setPrev(Node *prev);

   // ~Node();
};

#endif
