#include "../classNode/classNode.h"

class Stack {
        private:
                Node* top;
                int size;
        public:
                Stack();
                ~Stack();

                void push(char num);
                void pop();
                void displayStack();
                bool isEmpty();
                char topEl();
                int stackSize();
};

