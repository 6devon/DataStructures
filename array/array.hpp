#include<iostream>


// template<typename T, int N>
// class Iterator;
template<typename Array>
class ArrayIterator{

    public:
    using ValueType = typename Array::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

    public:
    ArrayIterator(PointerType ptr)
        : m_Ptr(ptr) {}
    ArrayIterator& operator++();
    ArrayIterator operator++(int);
    ArrayIterator& operator--();
    ArrayIterator operator--(int);
    ReferenceType operator[](int);
    ReferenceType operator->();
    ReferenceType operator*();
    
    
    private:
        PointerType m_Ptr;

};

template<typename T, int N>
class Array{
    private:
    T data[N];
    T x;

    public:
    using ValueType = T;
    using Iterator = ArrayIterator<Array>;

    public:
    Array();
    Array(T);
    Array(T, T);
    Array(const Array&);
    void show();
    T operator[](int) const;
    T at(int);
    T front();
    T back();
    T* get_data();
    void swap_with_index(int,int);
    
 //   T plus+ (int) const;

    int size();
    
    Iterator begin();
    Iterator end();

};

//default constructor
template<typename T, int N>
Array<T,N>::Array(){
    T default_value{};
    for(int i = 0; i < N; i++){
        data[i] = default_value;
    }

}

//constructor with parameter
template<typename T, int N>
Array<T,N>::Array(T x){
    for(int i = 0 ; i < N; i++){
        data[i] = x;
    }
}
//constructor with two parameters
template<typename T, int N>
Array<T, N>::Array(T x, T y){
    for(int i = 0; i <N; i+=2){
        data[i] = x;
        data[i+1] = y;
    }
}
//copy constructor
template<typename T, int N>
Array<T, N>::Array(const Array& x){
    for(int i = 0; i < N; i++){
        data[i] = x[i];
    }
}
//overload[] operator
template<typename T, int N>
T Array<T, N>::operator[](int x) const{
    return data[x];
}
//show method
template<typename T, int N>
void Array<T,N>::show(){
    for(int i = 0; i < N; i++){
        std::cout<<data[i];
    } 
}
//at method
template<typename T, int N>
T Array<T, N>::at(int i){
    return data[i];
}
//front method
template<typename T, int N>
T Array<T, N>::front(){
    return data[0];
}
//back method
template<typename T, int N>
T Array<T, N>::back(){
    return data[N - 1];
}

//data method
template<typename T, int N>
T* Array<T, N>::get_data(){
    return data;
}

//size method
template<typename T, int N>
int Array<T,N>::size(){
    return N;
}

//begin method
template<typename T, int N>
ArrayIterator<Array<T,N>> Array<T, N>::begin(){
    return ArrayIterator<T>(data);
}

//end method
template<typename T, int N>
ArrayIterator<Array<T,N>> Array<T, N>::end(){
    return ArrayIterator<T>(&data[N -1]);
}

//postincrementaction
template<typename Array>
ArrayIterator<Array>& ArrayIterator<Array>::operator++(){
    m_Ptr++;
    return *this;
    }

//preincrementation
template<typename Array>
ArrayIterator<Array> ArrayIterator<Array>::operator++(int){
    ArrayIterator<Array> iterator = *this;
    ++(*this);
    return iterator;
    }

//postdecrementation
template<typename Array>
ArrayIterator<Array>& ArrayIterator<Array>::operator--(){
    m_Ptr--;
    return *this;
    }

//predecrementation
template<typename Array>
ArrayIterator<Array> ArrayIterator<Array>::operator--(int){
    ArrayIterator<Array> iterator = *this;
    --(*this);
    return iterator;
    }


template<typename T, int N>
std::ostream& operator<<(std::ostream& os, const Array<T, N>& ar){
    for(int i = 0; i < N; i++){
        os << ar[i] << " ";
    }
    os << std::endl;
    return os;
}

template<typename T, int N>
void Array<T,N>::swap_with_index(int index1, int index2){
    auto temp = data[index1];
    data[index1] = data[index2];
    data[index2] = temp;
}

// template<typename Array>
// ArrayIterator<Array>::ReferenceType ArrayIterator<Array>::operator[](int index){
//     return *(m_Ptr + index);
// //or return *(m_Ptr[index]);

// }
// template<typename Array>
// ArrayIterator<Array>::ReferenceType ArrayIterator<Array>:: operator->(){
//     return m_Ptr;
// //or return *(m_Ptr[index]);

// }
// template<typename Array>
// ArrayIterator<Array>::ReferenceType ArrayIterator<Array>:: operator*(){
//     return *m_Ptr;
//}

// TO BE DONE

// bool operator==(const VectorIterator& other) const{
//     return m_Ptr == other.m_Ptr;
// }

// bool operator==(const VectorIterator& other) const{
//     return !(*this == other);
// }

