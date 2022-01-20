#include <iostream>
#include "list.h"
using std::cout;
using std::endl;


List::List() {
	first = nullptr;
	list_size = 0;
}

List::~List() {
	if (empty()) {
		return;
	}
	Node *temp = first->next;
	while (temp != nullptr) {
		temp = temp->next;
		free(first->next);
		first->next = temp;
	}		
	free(first);
}

bool List::exists(int d) const {
	if (first == nullptr) {
		return false;
	}
	Node temp = *first;
	while(temp.next != nullptr) {
		if (temp.value == d) {
			return true;
		}
		temp = *(temp.next);
	}
	return temp.value == d;
}

int List::size() const {
	return list_size;
}

bool List::empty() const {
	return first == NULL;
}

void List::insertFirst(int d) {
	Node *res = (Node*) malloc(sizeof(Node));
	res->value = d;
	if (first == nullptr) {
		first = res;
		// cout << first->value << endl;
	} else {
		res->next = first;
		first  = res;
		// cout << first->value << endl;
	}
	list_size++;
}

void List::remove(int d, DeleteFlag df) {
	if (!empty()) {
		// check if first is value
		Node *temp = first;
		if (temp->value == d && df == List::DeleteFlag::EQUAL) {
			first = first->next;
			free(temp);
			list_size--;
			return;
		} else if (temp->value < d && df == List::DeleteFlag::LESS)
		{
			first = first->next;
			free(temp);
			list_size--; 						
			return;
		} else if (temp->value > d && df == List::DeleteFlag::GREATER)
		{
			first = first->next; 
			free(temp); 
			list_size--; 
			return;
		}
		Node *prev = first;
		temp = temp->next;		
		while(temp != nullptr) {
			if (temp->value == d && df == List::DeleteFlag::EQUAL) {
				prev->next = temp->next;
				free(temp);
				list_size--;
				return;
			} else if (temp->value < d && df == List::DeleteFlag::LESS)
			{
				prev->next = temp->next;
				free(temp);
				list_size--;
				return;
			} else if (temp->value > d && df == List::DeleteFlag::GREATER)
			{
				prev->next = temp->next;
				free(temp);
				list_size--;
				return;
			}
			prev = temp;
			temp = temp->next;
		}				
	}
	
}

void List::print() const {
	if (first == nullptr) {
		return;
	}
	Node temp = *first;
	while (temp.next != nullptr) {
		cout << temp.value << ", ";
		temp = *temp.next;
	}
	cout << temp.value << endl;	
}

