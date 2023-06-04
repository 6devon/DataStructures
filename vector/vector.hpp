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
    ~Vector();
    // T at(int);
    // T& operator[](int);
    // T front();
    // T back();
    //T* data();
};
//constructors implementation
template<typename T>
Vector<T>::Vector(): elements(nullptr), size(0), capacity(0){ //null pointer value is used to indicate that a pointer does not point ro aany valid memory adress
}
template<typename T>
Vector<T>::Vector(int initialCapacity): elements(nullptr), size(0), capacity(initialCapacity){ //null pointer value is used to indicate that a pointer does not point ro aany valid memory adress
    elements = new T[capacity];
}

//destructor implementation
template<typename T>
Vector<T>::~Vector(){
    delete[] elements;
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