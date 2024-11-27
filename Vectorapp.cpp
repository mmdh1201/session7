#include <iostream>
#include <stdexcept> // For exception handling
#include <utility>
#include "Vectorref.cpp"
using namespace mine;


int main() {
    try{
    Vector<int> vec;
    vec.push_back(3);
    vec.push_back(4);

    for (auto i:vec){
        cout << i << " ";
    }
    std::cout<<std::endl;
    int n = vec.at(3);
    
    }
    catch (const std::out_of_range &e){
        std::cout<< e.what()<<std::endl;
    }
}