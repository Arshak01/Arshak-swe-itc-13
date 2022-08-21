#include "LList.hpp"
#include <iostream>


    List::List(){
        head == NULL;
        tail == NULL;
    }

    List::List(List& list){
        Node* temp = list.head;
        while(temp!=NULL) {
            list.pushFront(temp->data);
            temp=temp->next;
        }
    }

    void List::pushFront(int element){
        Node *newTemp = new Node;
        newTemp->data=element;
        if(head==NULL) {
        head=newTemp;
        newTemp->prev=NULL;
        newTemp->next=NULL;
        tail=newTemp;
        } else {
        newTemp->next=head;
        newTemp->prev=NULL;
        head->prev=newTemp;
        head=newTemp;
        }   
    }

    void List::pushBack(int element){
        Node *newTemp = new Node;
        newTemp->data = element;
        if(head==NULL) {
        head=newTemp;
        newTemp->prev=NULL;
        newTemp->next=NULL;
        tail=newTemp;

        } else {
        newTemp->prev=tail;
        tail->next=newTemp;
        newTemp->next=NULL;
        tail=newTemp;
        }   
    }

    void List::popBack(){
        if(head == NULL)
            return;
        Node* temp = new Node;
        if(head == tail) {
            temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            return;
        } else {
            temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
        }
    }

    void List::popFront(){
        if(head == NULL)
            return;
        Node* temp = new Node;
        if(head == tail) {
            temp = head;
            head = NULL;
            tail = NULL;
            delete temp;
            return;
        } else {
            temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
        }
    }

    void List::insert(int index, int data) {
        Node* newTemp = new Node();
	    newTemp->data = data;
	    newTemp->next = NULL;
	    newTemp->prev = NULL;
	    if(index == 0) {
            pushFront(data);
	    } else {
			Node* temp = head;
			for (int i = 1; i < index; i++) {
				if (temp != NULL)
					temp = temp->next;
			}
			newTemp->next = temp->next;
			newTemp->prev = temp;
			temp->next = newTemp;
		}
	}

    void List::remove(int element){
        Node *temp = new Node;
        temp=head;
        while(temp->data != element) {
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }

    void List::printList() {
        Node *temp = new Node;
        temp=head;
    while(temp!=NULL) {
        std::cout <<"->"<< temp->data;
        temp=temp->next;
    }
    std::cout<<std::endl;
    }
