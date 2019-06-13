#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

// Justin Pulido
// BinarySearchTree.h
// The BinarySearchTree is used as a template file so that it
// can be used in different porgrams. It creates the functions
// to sort through the Tree and be able to grab the largest or
// smallest number within the tree as well as returning the 
// nodes or deleting or removing them. 
// Big O(n) is constant time
// 100% COMPLTE

#include <iostream>
#include <ostream>
#include <cassert>

using namespace std;

// Binary Search Tree, no duplicate element 

template <typename Comparable>
class BinarySearchTree
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
	void insert(Comparable && x, BinaryNode * & t);
	void remove(const Comparable & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode * t) const;
	BinaryNode * findMax(BinaryNode * t) const;
	bool contains(const Comparable & x, BinaryNode * t) const;
	void makeEmpty(BinaryNode * & t);
	void printTree(ostream & out, BinaryNode * t, string indent, const string & tag) const; //added indent and tag
	BinaryNode * clone(BinaryNode * t) const;
	void inorder(BinaryNode * t) const;
    void preorder(BinaryNode * t) const;
    void postorder(BinaryNode * t) const;
public:
	BinarySearchTree(): root{nullptr} { }
	BinarySearchTree(const BinarySearchTree & rhs) { root = clone(rhs.root); }
	BinarySearchTree(BinarySearchTree && rhs);
	~BinarySearchTree() { makeEmpty(root); }
	BinarySearchTree & operator=(const BinarySearchTree & rhs);
	BinarySearchTree & operator=(BinarySearchTree && rhs);

	const Comparable & findMin() const;
	const Comparable & findMax() const;
	bool contains(const Comparable & x) const;
	bool isEmpty() const { return root == nullptr; }
	void printTree(ostream & out = cout) const;

	void makeEmpty() { makeEmpty(root); }
	void insert(const Comparable & x) { insert(x, root); }
	void insert(Comparable && x) { insert(move(x), root); }
	void remove(const Comparable & x) { remove(x, root); }
	void inorder() const { inorder(root); }
	void postorder() const { postorder(root); }
	void preorder() const { preorder(root); }
};

//Big O(n) constant time
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::clone(BinaryNode * t) const
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
BinarySearchTree<Comparable>::BinarySearchTree(BinarySearchTree && rhs)
{
	root = rhs.root;     // root = move(rhs.root); not necessary 
    rhs.root == nullptr; //since root is a pointer
}

template <typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=(const BinarySearchTree & rhs)
{
	BinarySearchTree copy = rhs; //uses copy constructor
	swap(*this, copy);
	return *this;
}

template <typename Comparable>
BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=(BinarySearchTree && rhs)
{
	root = rhs.root;
	rhs.root = nullptr;
	return *this;
}

template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMin() const
{
	BinaryNode * t = findMin(root);
	
	if(t == nullptr) {
		return t->element;
	}
	return t->element;
}

//Big O(logn) 
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::findMin(BinaryNode * t) const
{
	if(t == nullptr) {
		return nullptr;
	}
	if(t->left == nullptr) {
		return t;
	}
	return findMin(t->left); //left-side
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(ostream & out) const
{
	cout << "Print Tree: " << endl;
	printTree(out, root, "", "");
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(ostream & out, BinaryNode * t, string indent, const string & tag) const
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
void BinarySearchTree<Comparable>::insert(const Comparable & x, BinaryNode * & t)
{
	if(t == nullptr) {
		t = new BinaryNode{ x, nullptr, nullptr };
		assert(t);
	} else if(x < t->left) {
		insert(move(x), t->left);
	} else if(x > t->element) {
		insert(move(x), t->right);
	} else {
		; // duplicate, do nothing
	}
}

//LNR
template <typename Comparable>
void BinarySearchTree<Comparable>::inorder(BinaryNode * t) const
{
	if(t == nullptr) {
		return ;
	}
	
	inorder(t->left);
	cout << t->element << " ";
	inorder(t->right);
}

//Big O(n) constant time
template <typename Comparable>
const Comparable & BinarySearchTree<Comparable>::findMax() const
{
	BinaryNode * t = findMax(root);

	if(t != nullptr) {
		return t->element;
	}

	return t->element;
}

//Big O(logn) 
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode * BinarySearchTree<Comparable>::findMax(BinaryNode * t) const
{
	if(t == nullptr) {
		return nullptr;
	}
	if(t->right == nullptr) {
		return t;
	}

	return findMax(t->right);
}

template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x) const
{
	return contains(x, root);
}

//Big O(n) 
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode * t) const
{
	if(t == nullptr) {
		return false;
	} else if(x < t->element) {
		return contains(x, t->left);
	} else if(t->element > x) {
		return contains(x, t->right);
	} else {
		return true;
	}
}

//Big O(n)
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode * & t)
{
	if(t != nullptr) {
		makeEmpty(t->left);
		makeEmpty(t->right);
		delete t;
	}
	t = nullptr;
}

//Big O(logn)
template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x, BinaryNode * & t)
{
	if(t == nullptr) {
		return ; //nothing found
	}
	if(x < t->element) {
		remove(x, t->left);
	} else if(t->element < x) {
		remove( x, t->right);
	} else if (t->left != nullptr && t->right != nullptr) {
		t->element = findMin(t->right)->element;
		remove(t->element, t->right);
	} else {
		BinaryNode * oldNode = t;
		t = (t->left != nullptr) ? t->left : t->right;
		delete oldNode;
	}
}

//Big O(n)
template <typename Comparable>
void BinarySearchTree<Comparable>::insert(Comparable && x, BinaryNode * & t)
{
	if(t == nullptr) {
		t = new BinaryNode{move(x), nullptr, nullptr};
	} else if(x < t->element) {
		insert(move(x), t->left);
	} else if(x > t->element) {
		insert(move(x), t->right);
	} else {
		; // do nothing, duplicate
	}
}

//Big O(n) constant time
template <typename Comparable>
void BinarySearchTree<Comparable>::preorder(BinaryNode * t) const
{
    if(t == nullptr) {
        return ;
    }
    cout << t->element << " ";
    preorder(t->left);
    preorder(t->right);
}

//Big O(n) constant time
template <typename Comparable>
void BinarySearchTree<Comparable>::postorder(BinaryNode * t) const
{
    if(t == nullptr) {
        return ;
    }
    postorder(t->left);
    postorder(t->right);
    cout << t->element << " ";
}

#endif
