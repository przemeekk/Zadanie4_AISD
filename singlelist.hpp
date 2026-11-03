#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

#include <iostream>     
#include <cassert>    
#include <cstddef>

template <typename T>
struct SingleNode {
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {} 
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() = default; 
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList(); 

    SingleList(const SingleList& other); 
    SingleList(SingleList&& other); 

    SingleList& operator=(const SingleList& other); 
    SingleList& operator=(SingleList&& other); 

    bool empty() const { return head == nullptr; }
    bool full() const { return false; }
    std::size_t size() const; 
    void push_front(const T& item); 
    void push_front(T&& item); 
    void push_back(const T& item); 
    void push_back(T&& item); 
    T& front() { assert(!empty()); return head->value; } 
    const T& front() const { assert(!empty()); return head->value; }
    T& back() { assert(!empty()); return tail->value; } 
    const T& back() const { assert(!empty()); return tail->value; }
    void pop_front(); 
    void pop_back(); 
    void clear(); 
    void display() const; 
    void display_reversed(); 
    void reverse(); 

    T& operator[](std::size_t pos); 
    const T& operator[](std::size_t pos) const; 
    void erase(std::size_t pos);
    int index(const T& item); 
    void insert(std::size_t pos, const T& item); 
    void insert(std::size_t pos, T&& item); 
};

template <typename T>
SingleList<T>::~SingleList() {
    clear();
}

template <typename T>
SingleList<T>::SingleList(const SingleList& other) : head(nullptr), tail(nullptr) {
    SingleNode<T> *node = other.head;
    while (node != nullptr) {
        push_back(node->value);
        node = node->next;
    }
}

template <typename T>
SingleList<T>::SingleList(SingleList&& other) : head(other.head), tail(other.tail) {
    other.head = nullptr;
    other.tail = nullptr;
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(const SingleList& other) {
    if (this == &other) return *this;
    clear();
    SingleNode<T> *node = other.head;
    while (node != nullptr) {
        push_back(node->value);
        node = node->next;
    }
    return *this;
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(SingleList&& other) {
    if (this == &other) return *this;
    clear();
    head = other.head;
    tail = other.tail;
    other.head = nullptr;
    other.tail = nullptr;
    return *this;
}

template <typename T>
std::size_t SingleList<T>::size() const {
    std::size_t count = 0;
    SingleNode<T> *node = head;
    while (node != nullptr) {
        ++count;
        node = node->next;
    }
    return count;
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_front(T&& item) {
    if (!empty()) {
        head = new SingleNode<T>(std::move(item), head);
    } else {
        head = tail = new SingleNode<T>(std::move(item));
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(T&& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(std::move(item));
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(std::move(item));
    }
}

template <typename T>
void SingleList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void SingleList<T>::display() const {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head; 
    if (head == tail) { 
        head = tail = nullptr;
    } else { 
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail; 
    if (head == tail) { 
        head = tail = nullptr;
    } else { 
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

#endif