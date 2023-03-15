#include<iostream>

template<typename T, int N>
class Array{
    private:
    T data[N];


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

template<typename T, int N>
T Array<T, N>::at(int i){
    return data[i];
}

template<typename T, int N>
T Array<T, N>::front(){
    return data[0];
}

template<typename T, int N>
T Array<T, N>::back(){
    return data[N - 1];
}

template<typename T, int N>
T Array<T, N>::at(int i){
    return data[i];
}