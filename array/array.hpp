#include<iostream>

template<typename T, int N>
class Array{
    private:
    T data[N];

    public:
    Array(T);
    Array(T, T);
    void show();

};


template<typename T, int N>
Array<T,N>::Array(T x){
    for(int i = 0 ; i < N; i++){
        data[i] = x;
    }
}

template<typename T, int N>
Array<T, N>::Array(T x, T y){
    for(int i = 0; i <N; i+=2){
        data[i] = x;
        data[i+1] = y;
    }
}


template<typename T, int N>
void Array<T,N>::show()
{
        for(int i = 0; i < N; i++)
        {
            std::cout<<data[i];
        } 
}