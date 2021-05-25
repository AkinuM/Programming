#include <iostream>
using namespace std;

template<typename keyType, typename valueType>
class bst {
private:
	class node {
	public:
		node* prevNode;
		node* leftNode;
		node* rightNode;
		pair<keyType, valueType> data;
		int level = 1;

		node(keyType key, valueType value, int prevLevel) {
			data.first = key;
			data.second = value;
			leftNode = NULL;
			rightNode = NULL;
			level += prevLevel;
		}
	};

	node* root;
	int bstSize = 0;

public:
	bst() {
		root = NULL;
	}

	void insert(keyType key, valueType value) {
		bstSize++;
		if (root == NULL) {
			root = new node(key, value, 0);
			root->prevNode = NULL;
		}
		else {
			node *tempNode, *lastNode = root;
			if (root->data.first > key) {
				tempNode = root->leftNode;
			}
			else {
				tempNode = root->rightNode;
			}
			while (1) {
				if (tempNode == NULL) {
					tempNode = new node(key, value, lastNode->level);
					tempNode->prevNode = lastNode;
					if (lastNode->data.first > key) {
						lastNode->leftNode = tempNode;
					}
					else {
						lastNode->rightNode = tempNode;
					}
					break;
				}
				else if (tempNode->data.first > key) {
					lastNode = tempNode;
					tempNode = tempNode->leftNode;
				}
				else {
					lastNode = tempNode;
					tempNode = tempNode->rightNode;
				}
			}
		}
	}

	node *find(keyType key) {
		node *tempNode;
		if (root->data.first > key) {
			tempNode = root->leftNode;
		}
		else if (root->data.first < key) {
			tempNode = root->rightNode;
		}
		else {
			return root;
		}
		if (tempNode == NULL) {
			return NULL;
		}
		while (tempNode->data.first != key) {
			if (tempNode == NULL) {
				return NULL;
			}
			else if (tempNode->data.first > key) {
				tempNode = tempNode->leftNode;
			}
			else {
				tempNode = tempNode->rightNode;
			}
		}
		return tempNode;
	}

	void erase(keyType key) {
		bstSize--;
		node *tempNode = find(key);
		if (tempNode == root) {
			if (tempNode->rightNode != NULL) {
				tempNode = next(root->data.first);
				if (tempNode->rightNode != NULL) {
					tempNode->prevNode->leftNode = tempNode->rightNode;
					tempNode->rightNode->prevNode = tempNode->prevNode;
				}
				else if (tempNode->prevNode != root) {
					tempNode->prevNode->leftNode = NULL;
				}
				else {
					root->rightNode = NULL;
				}
				tempNode->leftNode = root->leftNode;
				tempNode->rightNode = root->rightNode;
				tempNode->prevNode = NULL;
				if (root->leftNode != NULL) {
					root->leftNode->prevNode = tempNode;
				}
				if (root->rightNode != NULL) {
					root->rightNode->prevNode = tempNode;
				}
				delete root;
				root = tempNode;
			}
			else if (tempNode->leftNode != NULL) {
				root = tempNode->leftNode;
				delete root->prevNode;
				root->prevNode = NULL;
			}
			else {
				delete root;
				root = NULL;
			}
		}
		else {
			if (tempNode->prevNode->rightNode == tempNode) {
				if (tempNode->leftNode != NULL) {
					if (tempNode->rightNode != NULL) {
						tempNode->prevNode->rightNode = tempNode->leftNode;
						tempNode->leftNode->rightNode = tempNode->rightNode;
						tempNode->leftNode->prevNode = tempNode->prevNode;
						tempNode->rightNode->prevNode = tempNode->leftNode;
					}
					else {
						tempNode->prevNode->rightNode = tempNode->leftNode;
						tempNode->leftNode->prevNode = tempNode->prevNode;
					}
				}
				else if (tempNode->rightNode != NULL) {
					tempNode->prevNode->rightNode = tempNode->rightNode;
					tempNode->rightNode->prevNode = tempNode->prevNode;
				}
				else {
					tempNode->prevNode->rightNode = NULL;
				}
			}
			else if (tempNode->leftNode != NULL) {
				if (tempNode->rightNode != NULL) {
					tempNode->prevNode->leftNode = tempNode->rightNode;
					tempNode->rightNode->leftNode = tempNode->leftNode;
					tempNode->rightNode->prevNode = tempNode->prevNode;
					tempNode->leftNode->prevNode = tempNode->rightNode;
				}
				else {
					tempNode->prevNode->leftNode = tempNode->rightNode;
					tempNode->rightNode->prevNode = tempNode->prevNode;
				}
			}
			else if (tempNode->rightNode != NULL) {
				tempNode->prevNode->leftNode = tempNode->leftNode;
				tempNode->leftNode->prevNode = tempNode->prevNode;
			}
			else {
				tempNode->prevNode->leftNode = NULL;
			}
			delete tempNode;
		}
	}

	valueType &operator[](keyType key) {
		return find(key)->data.second;
	}

	node *next(keyType key) {
		node *tempNode = find(key);
		if (tempNode->rightNode == NULL) {
			while (tempNode != root) {
				if (tempNode->prevNode->leftNode == tempNode) {
					return tempNode->prevNode;
				}
				else {
					tempNode = tempNode->prevNode;
				}
			}
			return NULL;
		}
		else {
			tempNode = tempNode->rightNode;
		}
		while (tempNode->leftNode != NULL) {
			tempNode = tempNode->leftNode;
		}
		return tempNode;
	}

	node *prev(keyType key) {
		node *tempNode = find(key);
		if (tempNode->leftNode == NULL) {
			while (tempNode != root) {
				if (tempNode->prevNode->rightNode == tempNode) {
					return tempNode->prevNode;
				}
				else {
					tempNode = tempNode->prevNode;
				}
			}
			return NULL;
		}
		else {
			tempNode = tempNode->leftNode;
		}
		while (tempNode->rightNode != NULL) {
			tempNode = tempNode->rightNode;
			tempNode->level = 1;
		}
		return tempNode;
	}

	int size() {
		return bstSize;
	}

	bool empty() {
		if (root == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}

	void clear() {
		while (root != NULL) {
			erase(root->data.first);
		}
	}
};