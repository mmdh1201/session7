#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdexcept>
#include <utility>
using namespace std;

namespace mine{
    template <typename T>
class Vector{
    T* data;
    size_t capacity;
    size_t size;
    public:
        Vector();//constructor
        Vector(size_t);
        Vector(size_t,T&);
        Vector(const Vector&);//copy constructor
        Vector(Vector&&) noexcept;//move constructor
        ~Vector();
        Vector& operator=(const Vector&);//copy assinment
        Vector& operator=(Vector&&)noexcept;//move assinment
        Vector& operator--();
        Vector& operator--(T);
        Vector& operator+=(const Vector&);
        Vector& operator++();
        Vector& operator++(T);
        void push_back(const T&);
        void push_back(T&&);
        void pop_back();
        T& front();
        T& back();
        T& at(size_t)const;
        T& operator[](size_t);
        const T& operator[](size_t) const;
        size_t get_size() const;
        size_t get_capacity() const;
        bool isempty() const;
        void clear();
        void resize(size_t);
        void reserve(size_t);
        class Iterator{
            T* ptr;
            public:
                Iterator(T*);
                T& operator*()const;
                T* operator->()const;
                Iterator& operator++();
                Iterator operator++(int);
                Iterator& operator--();
                Iterator operator--(int);
                bool operator==(const Iterator&)const;
                bool operator!=(const Iterator&)const; 
        };
    Iterator begin();
    Iterator end();
};
}


#endif