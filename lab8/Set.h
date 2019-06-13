#ifndef SET_H
#define SET_H

// Justin Pulido
// Set.h
// The Set is used as a template file so that it
// can be used in different porgrams. It creates the functions
// to sort through the Tree and be able to grab the largest or
// smallest number within the tree as well as returning the 
// nodes or deleting or removing them. 
// now implementing iterators in the The class as well as changing variables 
// When it iterates through the tree, it will find the number and in the 
// main it will decide if it wants to keep it or remove it. 
// Big O(n) is constant time
// 100% COMPLTE

#include <iostream>
#include <ostream>
#include <cassert>

using namespace std;

// Set, no duplicate element 
template <typename Comparable> class Set_iterator;

template <typename Comparable>
class Set
{
public:
	typedef Set_iterator<Comparable> iterator;
private:
	struct BinaryNode
	{
		Comparable element;
        BinaryNode * parent;
		BinaryNode * left;
		BinaryNode * right;
	
		BinaryNode(const Comparable & theElement, BinaryNode * p, BinaryNode * lt, BinaryNode * rt):
            element{theElement}, parent{p}, left{lt}, right{rt} { }
        BinaryNode(Comparable && theElement, BinaryNode * p, BinaryNode * lt, BinaryNode * rt):
            element{move(theElement)}, parent{p}, left{lt}, right{rt} { }
	};
	
	BinaryNode * root;
	unsigned int theSize;
	bool contains(const Comparable & x, BinaryNode * t) const;
	void remove(const Comparable & x, BinaryNode * & t);

    iterator insert(const Comparable & x, BinaryNode * p, BinaryNode * & t);
    iterator insert(Comparable && x, BinaryNode * p, BinaryNode * & t);
	void erase(const Comparable & x, BinaryNode * & t);
	BinaryNode * findMin(BinaryNode * t) const;
	BinaryNode * findMax(BinaryNode * t) const;
	unsigned int count(const Comparable & x, BinaryNode * t) const;
	void makeEmpty(BinaryNode * & t);
	void printTree(ostream & out, BinaryNode * t, string indent, const string & tag) const; //added indent and tag
	BinaryNode * clone( BinaryNode * t) const;
	void inorder(BinaryNode * t) const;
    void preorder(BinaryNode * t) const;
    void postorder(BinaryNode * t) const;

	iterator find(const Comparable & x, BinaryNode * t) const;
public:	
	Set(): root{nullptr}, theSize{0} { }
	Set(const Set & rhs) { root = clone(rhs.root); theSize = rhs.theSize; }
	Set(Set && rhs);
	~Set() { makeEmpty(root); }
	Set & operator=(const Set & rhs);
	Set & operator=(Set && rhs);
    unsigned int size() const { return theSize; }
	unsigned int count(const Comparable & x) const;

	const Comparable & findMin() const;
	const Comparable & findMax() const;
	bool empty() const { return root == nullptr; }
	void printTree(ostream & out = cout) const;
	bool contains(const Comparable & x) const;

	void clear() { makeEmpty(root); theSize = 0; }
	iterator insert(const Comparable & x) { return insert(x, nullptr, root); }
    iterator insert(Comparable && x) { return insert(move(x), nullptr, root); }
	void erase(const Comparable & x) { erase(x, root); }
	void erase(iterator itr);
	void makeEmpty() { makeEmpty(root); }
	void remove(const Comparable & x) { remove(x, root); }

	iterator begin() const; // for in-order traversal
    iterator end() const { return iterator(nullptr); }
    iterator find(const Comparable & x) const { return find(x, root); }
	
	void inorder() const { inorder(root); }
	void postorder() const { postorder(root); }
	void preorder() const { preorder(root); }
friend class Set_iterator<Comparable>;
};

//Big O(logn)
template <typename Comparable>
void Set<Comparable>::remove(const Comparable & x, BinaryNode * & t)
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

template <typename Comparable>
bool Set<Comparable>::contains(const Comparable & x) const
{
	return contains(x, root);
}

//Big O(n) 
template <typename Comparable>
bool Set<Comparable>::contains(const Comparable & x, BinaryNode * t) const
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
void Set<Comparable>::erase(Set<Comparable>::iterator itr) // itr is undefined on function return
{
    if (itr == end()) {
        return; // do nothing
	}

    BinaryNode * temp;
    if (itr.current->left != nullptr && itr.current->right != nullptr) { // two children
        // left-slide from right
        temp = itr.current->right;
        while (temp->left != nullptr) { 
            temp = temp->left;
		}
        itr.current->element = temp->element; 
    } else { // one or no child
        temp = itr.current;
	}

    // adjust child pointer
    BinaryNode *p = temp->parent;
    if (p != nullptr) {
        if (p->left == temp) {
            p->left = (temp->left != nullptr) ? temp->left : temp->right;
        } else {
            p->right = (temp->left != nullptr) ? temp->left : temp->right;
		}
	}

    // adjust parent pointer
    if (temp->left != nullptr) {
        temp->left->parent = p;
    } else if (temp->right != nullptr) {
        temp->right->parent = p;
	}
    delete temp;
    theSize--;
}

//Big O(logn)
template <typename Comparable>
typename Set<Comparable>::iterator Set<Comparable>::begin() const 
{
    BinaryNode * current = root;
    while (current and current->left)
        current = current->left;
    return iterator(current);
}

//Big O(logn)
template <typename Comparable>
typename Set<Comparable>::iterator Set<Comparable>::insert(Comparable && x, BinaryNode * p, BinaryNode * & t)
{
    if (t == nullptr) {
        t = new BinaryNode{ move(x), p, nullptr, nullptr };
        assert(t);
        theSize++;
        return t;
    } else if (x < t->element) {
        return insert(move(x), t, t->left);
    } else if (x > t->element) {
        return insert(move(x), t, t->right);
    } else {
        return t; // duplicate, do nothing
	}
}

//Big O(n) constant time
template <typename Comparable>
typename Set<Comparable>::BinaryNode * Set<Comparable>::clone(BinaryNode * t) const
{
	if(t == nullptr) {
		return nullptr;
	} else {
		BinaryNode * temp = new BinaryNode{t->element, nullptr, clone(t->left), clone(t->right)};
		assert(temp);
		if(temp->left != nullptr) {
			temp->left->parent = temp;
		}
		if(temp->right != nullptr) {
			temp->right->parent = temp;
		}
		return temp;
	}
}

template <typename Comparable>
Set<Comparable>::Set(Set && rhs): root{rhs.root}, theSize{rhs.theSize}
{
	rhs.root = nullptr;
	rhs.theSize = 0;
}

template <typename Comparable>
Set<Comparable> & Set<Comparable>::operator=(const Set & rhs)
{
	Set copy = rhs; //uses copy constructor
	swap(*this, copy);
	return *this;
}

template <typename Comparable>
Set<Comparable> & Set<Comparable>::operator=(Set && rhs)
{
	root = rhs.root;
	rhs.root = nullptr;
	return *this;
}

template <typename Comparable>
const Comparable & Set<Comparable>::findMin() const
{
	BinaryNode * t = findMin(root);
	
	if(t == nullptr) {
		return t->element;
	}
	return t->element;
}

//Big O(logn) 
template <typename Comparable>
typename Set<Comparable>::BinaryNode * Set<Comparable>::findMin(BinaryNode * t) const
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
void Set<Comparable>::printTree(ostream & out) const
{
	cout << "Print Tree: " << endl;
	printTree(out, root, "", "");
}

template <typename Comparable>
void Set<Comparable>::printTree(ostream & out, BinaryNode * t, string indent, const string & tag) const
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
typename Set<Comparable>::iterator Set<Comparable>::insert(const Comparable & x, BinaryNode * p, BinaryNode * & t)
{
    if (t == nullptr) {
        t = new BinaryNode{ x, p, nullptr, nullptr };
        assert(t);
        theSize++;
        return t;
    } else if (x < t->element) {
        return insert(x, t, t->left);
    } else if (x > t->element) {
        return insert(x, t, t->right);
    } else {
        return t; // duplicate, do nothing
	}
}

//LNR
template <typename Comparable>
void Set<Comparable>::inorder(BinaryNode * t) const
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
const Comparable & Set<Comparable>::findMax() const
{
	BinaryNode * t = findMax(root);

	if(t != nullptr) {
		return t->element;
	}

	return t->element;
}

//Big O(logn) 
template <typename Comparable>
typename Set<Comparable>::BinaryNode * Set<Comparable>::findMax(BinaryNode * t) const
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
unsigned int Set<Comparable>::count(const Comparable & x) const
{
	return count(x, root);
}

//Big O(n) 
template <typename Comparable>
unsigned int Set<Comparable>::count(const Comparable & x, BinaryNode * t) const
{
	if(t == nullptr) {
		return 0;
	} else if(x < t->element) {
		return count(x, t->left);
	} else if(t->element > x) {
		return count(x, t->right);
	} else {
		return 1;
	}
}

//Big O(n)
template <typename Comparable>
void Set<Comparable>::makeEmpty(BinaryNode * & t)
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
void Set<Comparable>::erase(const Comparable & x, BinaryNode * & t)
{
    if (t == nullptr)
        return; // not found, do nothing

    if (x < t->element)
        erase(x, t->left);
    else if (x > t->element)
        erase(x, t->right);
    else if (t->left != nullptr && t->right != nullptr) // two children
    {
        t->element = findMin(t->right)->element; // findMin() performs left-slide from right
        erase(t->element, t->right);
    } else { // one or no child
        BinaryNode *oldNode = t;
        BinaryNode *p = t->parent;
        t = (t->left != nullptr) ? t->left : t->right;
        if (t != nullptr)
            t->parent = p;
        delete oldNode;
        theSize--;
    }
}

//Big O(n) constant time
template <typename Comparable>
void Set<Comparable>::preorder(BinaryNode * t) const
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
void Set<Comparable>::postorder(BinaryNode * t) const
{
    if(t == nullptr) {
        return ;
    }
    postorder(t->left);
    postorder(t->right);
    cout << t->element << " ";
}

template <typename Comparable>
class Set_iterator
{
public:
    typedef typename Set<Comparable>::BinaryNode BinaryNode;

    Set_iterator() = default;
    Set_iterator(const Set_iterator & it) = default;
    Set_iterator(Set_iterator && it) = default;
    ~Set_iterator() = default;
    Set_iterator & operator=(const Set_iterator & itr) = default;
    Set_iterator & operator=(Set_iterator && itr) = default;

    Set_iterator(BinaryNode * t): current{t} { }

    bool operator==(Set_iterator itr) const { return current == itr.current; }
    bool operator!=(Set_iterator itr) const { return current != itr.current; }
    Set_iterator & operator++(); // inorder traversal, pre-increment
    Set_iterator operator++(int); // inorder traversal, post-increment
    Comparable & operator*() { return current->element; }
protected:
    BinaryNode * current;

friend class Set<Comparable>;
};


template <typename Comparable>
Set_iterator<Comparable> & Set_iterator<Comparable>::operator++() // inorder traversal, pre-increment
{
    if (current->right) { // if right child exists, left slide from right child
        current = current->right;
        while (current->left)
            current = current->left;
    } else {
        BinaryNode * child = current;
        current = current->parent;
        while (current && current->right == child) {
            // coming up from the right child, don't visit the parent
            child = current;
            current = current->parent;
        }
    }
    return *this;
}

//O(n)
template <typename Comparable>
Set_iterator<Comparable> Set_iterator<Comparable>::operator++(int)
{
    Set_iterator<Comparable> clone(*this);
    ++(*this);
    return clone;
}

//finding the number by using iterators
//O(logn)
template <typename Comparable>
typename Set<Comparable>::iterator Set<Comparable>::find(const Comparable & x, BinaryNode * t) const
{
	if(t == nullptr) {
		return iterator{};
	} else if(x < t->element) {
		return find(x, t->left);
	} else if(x > t->element) {
		return find(x, t->right);
	} else {
		return iterator{t};
	}
}

#endif
