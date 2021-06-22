#include<iostream>

using namespace std;

class linkedList {
public:
	linkedList() {
		first=new Node();
		first->value = NULL;
	}
	linkedList(int value) {
		first = new Node();
		first->value= value;
	}

	void push(int value) {
		Node *newNode=new Node();
		newNode->value =value;
		newNode->next = first;
		first = newNode;
	}

	bool isEmpty() {
		if (first == nullptr) {
			return true;
		}
		return false;
	}

	int pop() {
		if (isEmpty() == false) {
			int retVal = first->value;
			Node* temp = first->next;
			delete first;
			first = temp;
			return retVal;
		}
		else {
			return NULL;
		}
	}

	

private:
	
	//inner class
	class Node {
	public:
		Node* next=NULL;
		int value;
		Node() {
			cout << "created\n";
		}
		~Node() {
			cout << "destroyed\n";
		}
	};

	Node* first=nullptr;
};


void arrChange(int * arr) {
	int arrNew[20];
	cout << arr<<"\n";
	delete[] arr;
	arr = arrNew;
	cout << arr << "\n";
}

int main() {
	linkedList l1(0);
	l1.push(1);
	l1.push(2);
	l1.push(3);
	l1.push(4);
	cout<<l1.pop()<<" pop\n";
	cout << l1.pop() << " pop\n";
	l1.push(5);
	l1.push(6);
	//cout << l1.isEmpty() << " \n";
	cout << l1.pop() << " pop\n";
	cout << l1.pop() << " pop\n";
	cout << l1.pop() << " pop\n";
	cout << l1.pop() << " pop\n";
	cout << l1.pop() << " pop\n";
	cout << l1.pop() << " pop\n";


	return 0;
}