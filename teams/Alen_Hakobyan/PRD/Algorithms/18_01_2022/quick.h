#ifndef QUICK_H
#define QUICK_H
/**
 * @brief Class Node to create List
 */
class Node {
public:
	/// @param data of list
	int data;
	/// @param next of list element
	Node* next;
	/**
	 * @brief Node constructor to get @param value
	 */
	Node(int value);
};
/**
 * @brief Class Quick to sort list elements by value
 */
class Quick {
public:
	Node* head;
	Node* tail;
	Quick();
	~Quick();
	/**
	 * @brief pushNext function to push element inside list
	 * @param data input element
	 */
	void pushNext(int data);
	Node* lastNode();
	/**
	 * @brief position function to choose @param first for quicksort's partition algorithm and swaps it with the first item in a list.
	 * @param first The first element in the List
	 * @param last The last element in the list
	 */
	Node* position(Node* first, Node* last);
	/**
	 * @brief sort function for sorting list by pivot
	 */
	void sort(Node* first, Node* last);
	void printQuick();
};

#endif
