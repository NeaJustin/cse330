#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

// Justin Pulido
// BinarySearch.h
// The BinarySearch is used as a template file so that it
// can be used in different porgrams. It creates a tree
// however, it is not an actual binary tree. It will 
// see how many nodes there are and the amount of leaves
// and full nodes. It will also check to see if it satisfies 
// the properties of a binary search tree. 
// Big O(n) is constant time
// 100% COMPLTE

#include <iostream>
#include <ostream>
#include <cassert>
#include <queue>

using namespace std;

// Binary Search Tree, no duplicate element 

template <typename Comparable>
class BinarySearch
{
private:
	struct BinaryNode
	{
		Comparable element;
		BinaryNode * left;
		BinaryNode * right;
	
		BinaryNode(const Comparable & theElement, BinaryNode * lt, BinaryNode * rt):
			element{theElement}, left{lt}, right{rt} { }
		BinaryNode(Comparable && theElement, BinaryNode * lt, BinaryNode * rt):
			element{move(theElement)}, left{lt}, right{rt} { }
	};
	
	
	BinaryNode * root;
	
	void insert(const Comparable & x, BinaryNode * & t);
	void printTree(ostream & out, BinaryNode * t, string indent, const string & tag) const; //added indent and tag
	int node(BinaryNode * & t);
	int leaf(BinaryNode * & t);
	int fullnode(BinaryNode * & t); 
	bool Btree(BinaryNode * & t);
	BinaryNode * clone(BinaryNode * t) const;
	
public:
	BinarySearch(): root{nullptr} { }
	BinarySearch(const BinarySearch & rhs) { root = clone(rhs.root); }
	BinarySearch(BinarySearch && rhs);

	void printTree(ostream & out = cout) const;
	int count() {fullnode(root);}
	int leaf() {leaf(root);}
	int node() {node(root);}
	bool Btree() {Btree(root);}

	void insert(const Comparable & x) { insert(x, root); }
};

//Big O(n) constant time
template <typename Comparable>
typename BinarySearch<Comparable>::BinaryNode * BinarySearch<Comparable>::clone(BinaryNode * t) const
{
	if(t == nullptr) {
		return nullptr;
	} else {
		BinaryNode * newNode = new BinaryNode{t->element, clone(t->left), clone(t->right)};
		assert(newNode);
		return newNode;
	}
}

template <typename Comparable>
BinarySearch<Comparable>::BinarySearch(BinarySearch && rhs)
{
	root = rhs.root;     // root = move(rhs.root); not necessary 
    rhs.root == nullptr; //since root is a pointer
}


template <typename Comparable>
void BinarySearch<Comparable>::printTree(ostream & out) const
{
	cout << "Print Tree: " << endl;
	printTree(out, root, "", "");
}

template <typename Comparable>
void BinarySearch<Comparable>::printTree(ostream & out, BinaryNode * t, string indent, const string & tag) const
{
	if(t == nullptr) {
		return;
	}
	out << indent << tag << t->element << endl;
	indent += "    ";
	printTree(out, t->left, indent, "L ");
	printTree(out, t->right, indent, "R ");
}

//Big O(n) constant time
template <typename Comparable>
void BinarySearch<Comparable>::insert(const Comparable & x, BinaryNode * & t)
{
    BinaryNode * newNode = new BinaryNode(x, nullptr, nullptr);
    assert(newNode);

    if (t == nullptr) {
        t = newNode;
        return;
    }

    queue<BinaryNode *> q;
    q.push(t);

    // level order traversal until an empty place is found
    while (!q.empty()) {
        BinaryNode* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            cout << "left: " << temp->left->element << " ";
            break;
        } else {
            q.push(temp->left);
		}

        if (!temp->right) {
            temp->right = newNode;
            cout << "right: " << temp->right->element << " ";
            break;
        } else {
            q.push(temp->right);
		}
    }
}

//Big O(n) constant time
template <typename Comparable>
int BinarySearch<Comparable>::node(BinaryNode * & t) 
{
	int count = 0;

    if (t == nullptr) {
        return 0;
    }

    queue<BinaryNode *> q;
    q.push(t);

    while (!q.empty()) {
        BinaryNode* temp = q.front();
        q.pop();
		count++;
		
		//ran into trouble using !temp->left and !temp->right
		//did not count the nodes properly.
        if (temp->left != nullptr) {
            q.push(temp->left);
        } 
        if (temp->right != nullptr) {
        	q.push(temp->right);
        }
    }
	return count;
}

//Big O(n) constant time
template <typename Comparable>
int BinarySearch<Comparable>::leaf(BinaryNode * & t) 
{
	int count = 0;

    if (t == nullptr) {
        return 0;
    }

    queue<BinaryNode *> q;
    q.push(t);

    while (!q.empty()) {
        BinaryNode* temp = q.front();
        q.pop();

		//same problem as before where the leafs were not being counted 
		//properly
        if (temp->left != nullptr) {
            q.push(temp->left);
        } 
        if (temp->right != nullptr) {
        	q.push(temp->right);
        }
        if(temp->left == nullptr && temp->right == nullptr) {
            count++;
        }
    }
	return count;
}

//Big O(n) constant time
template <typename Comparable>
int BinarySearch<Comparable>::fullnode(BinaryNode * & t) 
{
	int count = 0;

    if (t == nullptr) {
        return 0;
    }

    queue<BinaryNode *> q;
    q.push(t);

    while (!q.empty()) {
        BinaryNode* temp = q.front();
        q.pop();

        if (temp->left != nullptr) {
            q.push(temp->left);
        } 
        if (temp->right != nullptr) {
        	q.push(temp->right);
        }
        if(temp->left != nullptr && temp->right != nullptr) {
            count++;
        }
    }
	return count;
}

//Big O(n) still constant since it is going through the nodes
//one by one each time to the right
template <typename Comparable>
bool BinarySearch<Comparable>::Btree(BinaryNode * & t) 
{

	if(t == nullptr) {
		return false;
	}

    cout << "this is: " << t->element << endl;
	//created a temp to hold a null to be able to compare with 
	//the node itself. 
	BinaryNode* temp = nullptr;
	
	if(t) { 
		if(t != nullptr) {
            cout << t->element << endl;
			return false;
		}
		else if(temp != NULL && t->left->element <= temp->left->element) {
			return false;
		}
		//setting the temp equal to the node
		temp = t;
        cout << temp << endl; // checking temp
		//calling the function recursively
		return Btree(t->left);
	}
	return true;
}

#endif
