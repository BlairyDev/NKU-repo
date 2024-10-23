//
// Created by blairasistin on 10/21/24.
//

#include "mySet.h"


mySet::mySet() {
    size = 0;
}

bool mySet::isempty() {

    return elts.empty();
}

bool mySet::isfound(int x) {

    for(auto it = elts.begin(); it != elts.end(); ++it) {
        if((*it) == x) {
            return true;
        }
    }

    return false;
}

bool mySet::addelt(int x) {

    if(isempty()) {
       elts.push_back(x);
        size++;
        return true;
    }
    else {
        if(!isfound(x)) {
            elts.push_back(x);
            size++;
            return true;
        }
    }

    return false;

}

bool mySet::deleteelt(int x) {

    for(auto it = elts.begin(); it != elts.end(); ++it) {
        if((*it) == x) {
            elts.erase(it);
            size--;
            return true;
        }
    }

    return false;

}

vector<int> &mySet::getelts() {
    return elts;
}

void mySet::setelts(const vector<int> & S) {

    elts = S;

}


int mySet::getsize() {
    return size;
};

mySet mySet::Union(mySet &S) {

    mySet temp;


    for(auto it = elts.rbegin(); it != elts.rend(); ++it) {

        temp.elts.push_back(*it);
    }

    for(auto it = S.elts.rbegin(); it != S.elts.rend(); ++it) {

        if(!isfound(*it)) {
            temp.elts.push_back(*it);
        }
    }

    return temp;
}

mySet mySet::Intersection(mySet &S) {

    mySet temp;

    for(auto it = this->getelts().rbegin(); it != this->getelts().rend(); ++it) {

        if(S.isfound(*it)) {
            temp.getelts().push_back(*it);
        }
    }

    return temp;
}

mySet mySet::Difference(mySet &S) {

    mySet temp;

    for(auto it = getelts().rbegin(); it != getelts().rend(); ++it) {
        if(!S.isfound(*it)) {
            temp.getelts().push_back(*it);
        }
    }

    return temp;

}

ostream & operator<< (ostream & ost, mySet& S) {
    if(!S.getelts().empty()) {
        int trackLines = 0;

        cout << "{ ";

        for(int i = S.elts.size()-1; i >= 0; i--) {

            if(trackLines == 10) {
                cout << "\n";
            }
            cout << S.getelts()[i] << " ";

            trackLines++;
        }

        cout << "}";
    }
    else {
        return cout << "Set is EMPTY" << endl;
    }

}



bool mySet::operator==(mySet &other) {

    bool checkEqual = false;

    if(this->getsize() != other.getsize()) {
        return checkEqual;
    }
    else {
        for(auto it = getelts().begin(); it != getelts().end(); ++it) {
            if(other.isfound(*it)) {
                checkEqual = true;
            }
            else {
                checkEqual = false;
            }
        }
    }

    return checkEqual;

}
