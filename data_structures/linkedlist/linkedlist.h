struct node {
	node* next;
	void* data;
};

class LinkedList {
	public:
		~LinkedList();
		LinkedList();

		void insert(void* data);
		void remove(void* data);
		bool contains(void* data);
	private:
		node* head;
};
