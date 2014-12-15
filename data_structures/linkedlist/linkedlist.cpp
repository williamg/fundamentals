#include<cstdlib>
#include<assert.h>
#include "linkedlist.h"

LinkedList::~LinkedList() {
	while(this->head != NULL) {
		node* tmp = this->head;
		this->head = tmp->next;
		delete tmp;
	}
}

LinkedList::LinkedList() {
	this->head = NULL;
}

void LinkedList::insert(void* data) {
	assert(!this->contains(data));

	node* newNode = new node;
	newNode->data = data;
	newNode->next = this->head;
	this->head = newNode;

	assert(this->contains(data));
}

void LinkedList::remove(void* data) {
	assert(this->contains(data));

	node* prev = NULL;
	node* cur = this->head;
	while(cur->data != data) {
		prev = cur;
		cur = cur->next;

		// If cur is null that means we went through the whole list without
		// finding the data, but this isn't possible since we've already
		// asserted that our list contains the data
		assert(cur != NULL);
	}
	
	if (prev == NULL)
		this->head = cur->next;
	else
		prev->next = cur->next;

	delete cur;
}

bool LinkedList::contains(void* data) {
	node* cur = this->head;
	while(cur != NULL) {
		if(cur->data == data)
			return true;
		cur = cur->next;
	}

	return false;
}
