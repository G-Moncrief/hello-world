/*
    PROBLEM: remove duplicates from and unsorted linked list
	
	SOLUTION:  iterate through linked list at O(1) space and O(N^2) time
	
*/

#include <iostream>
#include <unordered_map>
#include <random>


//BELOW IS THE SETUP FOR THE LINKED LIST
struct Node {
	int data = 0;
	Node * next = nullptr;
};

/**
 * [insert - insert a node at the head of list]
 * @param head [head of the list]
 * @param data [new node's data]
 */
void insert( Node * & head, int data )
{
	Node * newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}

/**
 * [printList Helper routine to print list]
 * @param head [head of the list]
 */
void printList( Node * head ) {
	while( head ) {
		std::cout << head->data << "-->";
		head = head->next;
	}
	std::cout << "nullptr" << std::endl;
}

//generate a random int between min and max
/**
 * [random_range helper routine to generate a random number between min and max (including)]
 * @param  min [min of range]
 * @param  max [max of range]
 * @return     [A random number between min and max]
 */
static inline int random_range(const int min, const int max) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(mt);
}
//END SETUP FOR LINKED LIST

//method with space complexity O(1) and time complexity O(n^2)

//starts at head of linked list and checks data against linked list.
//if found it skips that node and links to the next.
void rem_dup (Node *head)
{
	if (head == nullptr || ( head && (head->next == nullptr)))
		return;
	Node *curr = head;
	while(curr) {
		Node *runner = curr;
		while (runner->next != nullptr){
			if (runner->next->data == curr->data)
				runner->next = runner->next->next;
			else
				runner = runner->next;
		}
		curr = curr->next;
	}
}

int main() {
	std::cout << "Method 1 : \n";
	Node * head = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		insert(head, random_range(1,7));
	}
	printList(head);
	rem_dup(head);
	printList(head);
}
	
