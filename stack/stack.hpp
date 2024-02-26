#include<iostream>
#include<stdexcept>

template<typename T>
class Stack
{
    private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& newData, Node* newNext = nullptr) : data(newData), next(newNext) {}
    };
    Node* topNode;
    int size;

    public:
    Stack();
    ~Stack();
    void push(const T&);
    T pop();
    bool empty() const;
    int getSize() const;
    T top() const;
};

template<typename T>
Stack<T>::Stack(): topNode(nullptr), size(0) {}

template<typename T>
Stack<T>::~Stack()
{
    while(!empty()){
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T& value)
{
    Node* newNode = new Node(value, topNode);
    topNode = newNode;
    ++size;
}

template<typename T>
T Stack<T>::pop()
{
    if(empty()){
        throw std::runtime_error("Stack is empty");
    }
    T data = topNode->data;
    Node* temp = topNode;
    topNode = topNode->next;
    delete temp;
    --size;
    return data;
}

template<typename T>
bool Stack<T>::empty() const
{
    return size == 0;
}

template<typename T>
int Stack<T>::getSize() const
{
    return size;
}

template<typename T>
T Stack<T>::top() const
{
    if(empty()){
        throw std::runtime_error("Stack is empty");
    }
    return topNode->data;
}


