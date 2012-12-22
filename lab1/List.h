
class Node {
public:	
	Node(int i) {
		val=i;
		prev=next=NULL;
	}
	~Node() {};
	int val;
	Node *prev, *next;
};

class List {
private:
	Node *first_node;
	Node *cur_node;
	int length;
public:
	List () {
		first_node=cur_node=NULL;
		length=0;
	}
	~List();
	List* add(int item);
	List* remove(Node *a); 
	List* remove();
	List* print(char c);
	List* print();
	Node* get(int pos);
	List* replace(Node *a, Node *b); 
	List* insertBefore(Node *a, Node *target);
	List* insertAfter(Node *a, Node *target);
	List* next();
	List* prev();
	bool EOL();
	bool Search(int val);
};

List::~List() { 
	if (first_node) {
		Node *tmp_node = first_node;
		while (tmp_node->next) {
			tmp_node = tmp_node->next;
			delete tmp_node->prev;
		}
		delete tmp_node;
	}
	first_node = NULL;
}

List* List::add(int item) { 
	Node *tmp_node = new Node(item);
	if (first_node) {
		tmp_node->next = cur_node->next;
		if (tmp_node->next) tmp_node->next->prev = tmp_node;
		cur_node->next = tmp_node;
		tmp_node->prev = cur_node;
	} else {
		first_node = tmp_node;
	}
	cur_node = tmp_node;
	length++;
	return this;
}

List* List::remove() {
	if (first_node) {
		Node *tmp_node = cur_node;
		if (cur_node->next) {
			cur_node->next->prev = cur_node->prev;
		}
		if (cur_node->prev) {
			cur_node->prev->next = cur_node->next;
		}
		cur_node = cur_node->prev;
		delete tmp_node;
		length--;
	}
	return this;
}

List* List::remove(Node *a) {
	if (first_node) {
		if (a->next) {
			a->next->prev = a->prev;
		}
		if (a->prev) {
			a->prev->next = a->next;
		}
		if (a == first_node) first_node = first_node->next;
		if (a == cur_node) cur_node = cur_node->prev;
		delete a;
		length--;
	}
	return this;
}

List* List::print(char c) {
	Node *tmp_node = first_node;
	if (!c) c=' ';
	while (tmp_node) {
		cout<<tmp_node->val;
		cout<<c;
		tmp_node = tmp_node->next;
	}
	cout<<"\n";
	return this;
}

List* List::print() {
	Node *tmp_node = first_node;
	char c=' ';
	while (tmp_node) {
		cout<<tmp_node->val;
		cout<<c;
		tmp_node = tmp_node->next;
	}
	cout<<"\n";
	return this;
}

Node* List::get(int pos) {
	Node *tmp_node = first_node;
	if (length>pos) {
		for (;pos>0;pos--) tmp_node = tmp_node->next;
		return tmp_node;
	}
	return 0;
}

List* List::replace(Node *a, Node *b) { 
	if (a->next && a->next != b) a->next->prev = b;
	if (a->prev && a->prev != b) a->prev->next = b;
	if (!a->prev) first_node = b;

	if (b->next && b->next != a) b->next->prev = a;
	if (b->prev && b->prev != a) b->prev->next = a;
	if (!b->prev) first_node = a;

	if (a->next != b && b->next != a) {
		Node *tmp_prev = b->prev, *tmp_next = b->next;
		b->prev = a->prev;
		b->next = a->next;
		a->prev = tmp_prev;
		a->next = tmp_next;
	} else if (a->next == b) {
		a->next = b->next;
		b->prev = a->prev;
		a->prev = b;
		b->next = a;
	} else {
		b->next = a->next;
		a->prev = b->prev;
		b->prev = a;
		a->next = b;
	}
	return this;
}

List* List::insertBefore(Node *a, Node *target) { 
	if (a->prev) a->prev->next = a->next;
	else first_node = a->next;
	if (a->next) a->next->prev = a->prev;

	if (target->prev) target->prev->next = a;
	else first_node = a;

	a->next = target;
	a->prev = target->prev;
	target->prev = a;
	return this;
}

List* List::insertAfter(Node *a, Node *target) { 
	if (a->prev) a->prev->next = a->next;
	else first_node = a->next;
	if (a->next) a->next->prev = a->prev;

	if (target->next) target->next->prev = a;

	a->next = target->next;
	a->prev = target;
	target->next = a;
	return this;
}

List* List::next() {
	if (cur_node->next) cur_node=cur_node->next;
	return this;
}

List* List::prev() {
	if (cur_node->prev) cur_node=cur_node->prev;
	return this;
}

bool List::EOL() {
	return cur_node->next;
}

bool List::Search(int val) {
	int left=0, right=length-1, i;
	Node *i_node;

	while (left<=right) {
		i = (right+left)/2;
		i_node = get(i);
		if (val < i_node->val) {
			right = i-1;
		} else if (val > i_node->val) {
			left = i+1;
		}
		else return true;
	}
	return false;
}



