#ifndef VECTOR_H
#define VECTOR_H

//vector.h

#include <cassert>

template <class T>
class Vector
{
private:
    unsigned int my_size;
    unsigned int my_capacity;
    T * buffer;
public:
    typedef T * iterator;
    
    Vector(unsigned int size = 0, const T & initial = T()); //Default constructor
    Vector(const Vector<T> & v);                            //copy constructor
    Vector(Vector<T> && v);                                 //move constructor
    ~Vector();                                              //destructor
    Vector<T> & operator=(const Vector<T> & v);             //copy assignment
    Vector<T> & operator=(Vector<T> && v);                  //move assignemt

    unsigned int capacity() const;
    unsigned int size() const;
    bool empty() const;
    
    iterator begin();                      //return iterator to the first element
    iterator end();                        //return iterator to past last element
    T & front();                           //return reference to first element 
    T & back();                            //return reference to last element 
    void push_back(const T & value);       
    void pop_back();

    void reserve(unsigned int capacity);   //adjust capacity
    void resize(unsigned int size);        //adjust size
    
    T & operator[](unsigned int index);    
    void erase(iterator);            //erase elem iterator to (shift from iterator)
};

//default constructor
template <class T>
Vector<T>::Vector(unsigned int size, const T & initial)
{
    my_size = size;
    my_capacity = size;
    if(size == 0) {
        buffer = nullptr;
    } else {
        buffer = new T[size];
        assert(buffer != nullptr);
    }

    for(int i = 0; i < my_size; i++) {
        buffer[i] = v.bufer[i];
    }
}

//move constructor
template <class T>
Vector<T>::Vector(Vector<T> && v): my_size{v.my_size}, my_capacity{v.my_capacity}, buffer{v.bffer}
{
    v.my_size = 0;
    v.my_capacity = 0;
    v.buffer = nullptr;
}

template <class T>
Vector<T>::~Vector()
{
    my_size = 0;
    my_capacity = 0;
    delete [] buffer;
}

//copy assignment
Vector<T> & Vector<T>::operator=(const Vector<T> & v)
{
    T * temp = new T[v.my_capacity];
    assert(temp != nullptr);

    for (int i = 0l i < v.my_size; i++) {
        temp[i] = v.buff[i];
    }

    delete [] buffer;
    buffer = temp;
    my_size = v.my_size;
    my_capacity = v.my_capacity;

    return *this;
/*  alternate implementation 
    Vector<T> copy = v;
    swap(*this, copy);
    return *this;
*/
}

//move assignment
template <class T>
Vector<T> & Vector<T>::operator=(Vector<T? && v)
{
/*  alternate implementation
    swap(my_size, v.my_size);
    swap(my_capacity, v.my_capacity);
    swap(buffer, v.buffer);
*/
    my_size = v.my_size;i
