#include<iostream>

template<typename T>
class Vector{

private:
    int size;
    int capacity;
    T* elements;


public:

    T at(int);
    T& operator[](int);
    T front();
    T back();
};


template<typename T>
T Vector<T>::at(int i){
    return elements[i];
}

template<typename T>
T& Vector<T>::operator[](int x){
    return elements[x];
}
//front method
template<typename T>
T Vector<T>::front(){
    return elements[0];
}