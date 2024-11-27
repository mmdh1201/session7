#include <iostream>
#include "weapon.h"
int weapon::id = 0;
//weapon class
weapon::weapon(){id++;}
weapon::weapon(size_t p,size_t d):
    power(p),durability(d){id++;}
pair<size_t,int> weapon::Power(){
    return {power,level};
}
size_t weapon::Dur(){
    return durability;
}
int weapon::getid(){return id;}
//blade
blade::blade():
    weapon(1,10),sharpness(30),magiclevel(0),pair(0),level(0){}
blade::blade(size_t sh,size_t magic,bool p):
    weapon(1,10),sharpness(sh),magiclevel(magic),pair(p),level(0){}
int blade::getid(){
    return id+10000;
}

pair<size_t,int> blade::Power(){
    power*=sharpness;
    if(pair){power*=2;}
    if(magiclevel>0){power*=3;}
    if(power>100&&power<200){level = 2;}
    return {power,level};
}