#include <iostream>
#include <stdexcept> // For exception handling
#include <utility>
#include "Vector.h"
using namespace mine;

template <typename T>
Vector<T>::Vector():data(nullptr),capacity(0),size(0){}

template <typename T>
Vector<T>::Vector(size_t count):
    data(nullptr),capacity(count),size(0){} 
template <typename T>
Vector<T>::Vector(size_t count,T& t):
    data(nullptr),capacity(count),size(count){
        data = new T[size];
        for (int i=0;i<size;i++){data[i]=t;}
    } 
template <typename T>
Vector<T>::Vector(const Vector& other)//copy constructor
    : data(new T[other.capacity]), size(other.size), capacity(other.capacity){
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
template <typename T>
Vector<T>::Vector(Vector&& other)noexcept//move constructor
        :data(other.data),size(other.size),capacity(other.capacity)
    {
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
    }
template <typename T>
Vector<T>::~Vector() //distructor
    {
        delete[] data;
    }

template <typename T>
void Vector<T>::reserve(size_t new_capacity){
    T* new_data = new T[new_capacity];
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = std::move(data[i]);
    }
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}
template <typename T>
void Vector<T>::resize(size_t count){
    if(size>=count){size = count;return;}
    reserve(count);
    T* new_data = new T[count];
    for (size_t i = 0; i < size; ++i) {
        new_data[i] = std::move(data[i]);
    }
    data = new_data;
    size = count;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this == &other) return *this;
    delete[] data;
    data = new T[other.capacity];
    size = other.size;
    capacity = other.capacity;

    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other)noexcept{
    if (this == &other) return *this;
        delete[] data;
        data = other.data;
        size = other.size;
        capacity = other.capacity;
        other.data = nullptr;
        other.size = 0;
        other.capacity = 0;
        return *this;
}
template <typename T>
Vector<T>& Vector<T>::operator--(){
    if(size<=0){
            throw out_of_range("Vector is empty!");
        }
    size--;
    data[0]=data[1];
}
template <typename T>
Vector<T>& Vector<T>::operator--(T){
    if(size<=0){
            throw out_of_range("Vector is empty!");
        }
    size--;
    data[size]=data[size-1];
}
template <typename T>
Vector<T>& Vector<T>::operator++(){
    size++;
        if(capacity<size){resize(size);}
        T* temp = data;
        delete data;
        data = new T[size];
        data[0]=1;
        for(int i=1;i<size;i++){
            data[i] = temp[i-1];
            }
}
template <typename T>
Vector<T>& Vector<T>::operator++(T){
    size++;
    if(capacity<size){resize(size);}
    T* temp = data;
    delete data;
    data = new T[size];
    data[size-1]=1;
    for(int i=0;i<size-1;i++){
        data[i] = temp[i];
    }
}
template <typename T>
Vector<T>& Vector<T>::operator+=(const Vector& other){
    if(data==nullptr||other.data==nullptr){
            throw out_of_range("Vector is empty!");
        }
        size_t tempsize = size;
        size+=other.get_size();
        if(capacity<size){resize(size);}
        T* temp = data;
        delete[] data;
        data = new T(size);
        for(int i=0;i<tempsize;i++){
            data[i] = temp[i];
        }
        for (int i=tempsize;i<size;i++){
            data[i] = other.data[size-tempsize-1];
        }
}

template <typename T>
void Vector<T>::push_back(const T& value) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity *= 2);
        }
        data[size++] = value;
}
template <typename T>
void Vector<T>::push_back(T&& value) {
        if (size == capacity) {
            resize(capacity == 0 ? 1 : capacity *= 2);
        }
        data[size++] = move(value);
}
template <typename T>
void Vector<T>::pop_back() {
    if (size > 0) {
        --size;
    } else {
        throw out_of_range("Vector is empty!");
    }
}
template <typename T>
T& Vector<T>::operator[](size_t index){
    if (index >= size) {
        throw out_of_range("Index out of range!");
    }
    return data[index];
}
template <typename T>
const T& Vector<T>::operator[](size_t index) const{
    if (index >= size) {
            throw std::out_of_range("Index out of range!");
    }
    return data[index];
}
template <typename T>
T& Vector<T>::at(size_t pos)const{
    if (pos>=size){throw out_of_range("Index given to at is out of range");}
    return data[pos];
}
template <typename T>
T& Vector<T>::front(){
    return data[size-1];
}
template <typename T>
T& Vector<T>::back(){
    return data[0];
}

template <typename T>
size_t Vector<T>::get_size() const {
    return size;
}
template <typename T>
size_t Vector<T>::get_capacity() const {
    return capacity;
}
template <typename T>
bool Vector<T>::isempty() const {
    return size == 0;
}
template <typename T>
void Vector<T>::clear(){
    size = 0;
    delete[] this->data;
    this->data = nullptr;
}
template <typename T>
Vector<T>::Iterator::Iterator(T* p):ptr(p){}

template <typename T>
T& Vector<T>::Iterator::operator*()const
{
    return *ptr;
}
template <typename T>
T* Vector<T>::Iterator::operator->()const
{
    return ptr;
}
template <typename T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator++()
{
    ++ptr;
    return *this;
}
template <typename T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator++(int)
{
    Iterator temp = *this; // Save the current state
    ++ptr;                // Advance the pointer
    return temp; 
}
template <typename T>
bool Vector<T>::Iterator::operator==(const Iterator& other)const
{
    return this->ptr == other.ptr;
}
template <typename T>
bool Vector<T>::Iterator::operator!=(const Iterator& other)const
{
    return this->ptr != other.ptr;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin(){
    return Iterator(data);
}
template <typename T>
typename Vector<T>::Iterator Vector<T>::end(){
    return Iterator(data+size);
}

    







