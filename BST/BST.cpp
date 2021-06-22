#include<iostream>

using namespace std;

template <typename Key,typename Val>
class BST {
public:
	void put(Key key, Val val) {
		root = move(put(root, key, val));
	}
	Val getKey(Key key) {
		shared_ptr<Node> x = root;
		while (x != nullptr) {
			int cmp = comp(x->getKey(),key);
			if (cmp > 0) { x = x -> left; }
			else if (cmp < 0) { x = x->right; }
			else { return x->getVal(); }
		}
		return NULL;
	}

private:
	class Node {
	private:
		Key key;
		Val val;
	public:
		shared_ptr<Node> left;
		shared_ptr<Node> right;
		Node(Key key, Val val) {
			this->key= key;
			this->val = val;
			this->left = nullptr;
			this->right = nullptr;
		}
		~Node() {
		}
		Key getKey() {
			return this->key;
		}
		void setVal(Val val) {
			this->val = val;
		}
		Val getVal() {
			return this->val;
		}
	};
	int comp(Key key1,Key key2) {
		if (key1 > key2) { return 1; }
		else if (key1 < key2) { return -1; }
		else { return 0; }
	}
	shared_ptr<Node> put(shared_ptr<Node> node, Key key, Val val) {
		if (node == nullptr) { shared_ptr<Node> newNode = make_unique<Node>(key, val); return  newNode; }
		
		int cmp=comp(node->getKey(),key);
		if (cmp >0) {
			node->left = put(node->left, key, val);
		}
		else if (cmp < 0) {
			node->right = put(node->right, key, val);
		}
		else {
			node->setVal (val);
		}
		return node;
	}
	shared_ptr<Node> root=0;
};

int main() {
	BST <int,int>bst;
	bst.put(1, 1);
	
	bst.put(2, 4);
	bst.put(4, 8);
	bst.put(0, 6);
	bst.put(2, 6);

	cout << bst.getKey(4) << " val\n";
	cout << bst.getKey(3) << " val\n";
	cout << bst.getKey(2) << " val\n";
	cout << bst.getKey(4) << " val\n";
	cout << bst.getKey(3) << " val\n";
	cout << bst.getKey(2) << " val\n";
	bst.put(-1, 20);
	cout << bst.getKey(2) << " val\n";
	cout << bst.getKey(-1) << " val\n";

	return 0;
}