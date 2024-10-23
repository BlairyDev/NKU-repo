//
// Created by blairasistin on 10/21/24.
//

#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include "mySet.h"
using namespace std;


class OrderedSet : public mySet{

public:
    OrderedSet();

    OrderedSet( mySet &S);

    OrderedSet Union(OrderedSet OS);
    OrderedSet Intersection(OrderedSet OS);
    OrderedSet Difference(OrderedSet OS);
    bool addelt(int x);

    void SortSet();


};



