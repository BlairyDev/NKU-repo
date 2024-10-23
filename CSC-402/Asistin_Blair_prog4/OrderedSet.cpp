//
// Created by blairasistin on 10/21/24.
//

#include "OrderedSet.h"

OrderedSet::OrderedSet() = default;

OrderedSet::OrderedSet(mySet &S) {
    this->size = S.getsize();
    this->elts = S.getelts();

}

bool OrderedSet::addelt(int x) {
    if(isempty()) {
        elts.push_back(x);
        size++;
        SortSet();
        return true;
    }
    else {
        if(!isfound(x)) {
            elts.push_back(x);
            size++;
            SortSet();
            return true;
        }
    }

    return false;
};


OrderedSet OrderedSet::Union(OrderedSet OS) {
    mySet ms = mySet::Union(OS);

    OrderedSet temp = OrderedSet( ms );

    temp.SortSet();

    return temp;
}



OrderedSet OrderedSet::Intersection(OrderedSet OS) {
    mySet ms = mySet::Intersection(OS);

    OrderedSet temp = OrderedSet( ms );

    temp.SortSet();

    return temp;
}

OrderedSet OrderedSet::Difference(OrderedSet OS) {
    mySet ms = mySet::Difference(OS);

    OrderedSet temp = OrderedSet( ms );

    temp.SortSet();

    return temp;
}

void OrderedSet::SortSet() {

    sort(elts.rbegin(), elts.rend());

}

ostream & operator<<(ostream &os, OrderedSet & OS) {
    if(!OS.getelts().empty()) {
        int trackLines = 0;

        cout << "{ ";

        for(int i = (OS.getsize())-1; i >= 0; i--) {

            if(trackLines == 10) {
                cout << "\n";
            }
            cout << OS.getelts()[i] << " ";

            trackLines++;
        }

        cout << "}";
    }
    else {
        return cout << "Set is EMPTY" << endl;
    }
    return cout << "Set is EMPTY" << endl;
}


