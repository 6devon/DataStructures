#include<iostream>

template<typename T>
class Vector{

private:
    int size; //current number of elements
    int capacity; //capacity of vector
    T* elements; //stores adress of vector


public:
    Vector();
    Vector(int initialCapacity);
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    ~Vector();
    void push_back(const T& element);
    void resize();
    int f_size();

    // T at(int);
    T& operator[](int index);
    // T front();
    // T back();
    //T* data();
};
//constructors implementation
template<typename T>
Vector<T>::Vector(): elements(nullptr), size(0), capacity(0){ //null pointer value is used to indicate that a pointer does not point ro aany valid memory adress
}
template<typename T>
Vector<T>::Vector(int initialCapacity): elements(nullptr), size(0), capacity(initialCapacity){ //null pointer value is used to indicate that a pointer does not point or any valid memory adress
    elements = new T[capacity];
}

//copy constructor
//copy constructor creates new Vector object by making a deep copy of existing Vector object
//deep copy -> allocates new memory for object
//shallow copy -> shares the same memory space
template<typename T>
Vector<T>::Vector(const Vector& other): elements(nullptr), size(other.size), capacity(other.capacity){
    elements = new T[capacity];
    for(int i = 0; i < size; ++i){
        elements[i] = other.elements[i];
    }
}

//assigment operator
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector& other){
    if(this != &other){
        delete[] elements;
        size = other.size();
        capacity = other.capacity;
        elements = new T[capacity];
        for(int i = 0; i < size; ++i){
            elements[i] = other.elements[i];
        }
    }
    return *this;
}

//destructor implementation
template<typename T>
Vector<T>::~Vector(){
    delete[] elements;
}

template <typename T>
void Vector<T>::push_back(const T& element){
    if(size == capacity){
        resize();
    }
    elements[size] = element;
    ++size;
}

template <typename T>
void Vector<T>::resize(){
    int newCapacity = (capacity == 0) ? 1 : capacity * 2;
    T* newElements = new T[newCapacity];
    for(int i = 0; i < size; ++i){
        newElements[i] = elements[i];
    }
    delete[] elements;
    elements = newElements;
    capacity = newCapacity;
}

template <typename T>
int Vector<T>::f_size() {return this -> size;}

template <typename T> 
T& Vector<T>::operator[](int index){
    if(index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

// template<typename T>
// T Vector<T>::at(int i){
//     return elements[i];
// }

// template<typename T>
// T& Vector<T>::operator[](int x){
//     return elements[x];
// }
// //front method
// template<typename T>
// T Vector<T>::front(){
//     return elements[0];
// }

// //back method
// template<typename T>
// T Vector<T>::back(){
//     return elements[capacity -1];
// }