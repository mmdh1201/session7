#ifndef WEAPON_H
#define WEAPON_H
#include <iostream>
#include <utility>
using namespace std;
class weapon{
    protected:
        static int id;
        size_t power;
        int level;
        size_t durability;
    public:
        weapon();
        weapon(size_t,size_t);
        virtual pair<size_t,int> Power();
        virtual size_t Dur();
        virtual int getid();
};
class blade:public weapon{
    size_t sharpness;
    size_t level;
    size_t magiclevel;
    bool pair;
public:
    blade();
    blade(size_t,size_t,bool);
    int getid();
    std::pair<size_t,int> Power();

};


#endif