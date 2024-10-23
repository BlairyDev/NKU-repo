#include <iostream>
#include <fstream>
#include "mySet.h"
#include "OrderedSet.h"
using namespace std;

int main() {

    mySet S1, S2, S3, S4, S5, S6;
    OrderedSet OS1, OS2, OS3, OS4, OS5, OS6;

    string inputFile;


    cout << "Please enter a path to an input file: ";
    cin >> inputFile;

    ifstream inf1(inputFile);

    if(!inf1) {
        cout << "Error opening file " << inputFile << endl;
        return -1;
    }

    int num;

    while(inf1 >> num) {
        S1.addelt(num);
    }

    inf1.close();

    cout << "Please enter a path to a second input file: ";
    cin >> inputFile;

    ifstream inf2(inputFile);

    if(!inf2) {
        cout << "Error opening file " << inputFile << endl;
        return -1;
    }

    while(inf2 >> num) {
        S2.addelt(num);
    }

    inf2.close();

    cout << endl;

    cout << "MySet S1 Contents" << endl;
    cout << endl;
    cout << S1 << endl;
    cout << endl;

    cout << "MySet S2 Contents" << endl;
    cout << endl;
    cout << S2 << endl;

    cout << endl;

    cout << "MySet S3 Contents" << endl;
    cout << endl;

    cout << S3 << endl;


    cout << "After UNION Operation of S1 and S2" << endl;
    S3 = S1.Union(S2);
    cout << "MySet S3 Contents" << endl;

    cout << S3 << endl;

    cout << endl;

    cout << "MySet S1 Contents" << endl;
    cout << endl;
    cout << S1 << endl;

    cout << endl;

    cout << "MySet S2 Contents" << endl;
    cout << endl;
    cout << S2 << endl;

    cout << endl;

    cout << "After INTERSECTION Operation of S1 and S2" << endl;
    S4 = S1.Intersection(S2);
    cout << "MySet S4 Contents" << endl;
    cout << S4 << endl;

    cout << endl;

    cout << "MySet S1 Contents" << endl;
    cout << endl;
    cout << S1 << endl;

    cout << endl;

    cout << "MySet S2 Contents" << endl;
    cout << endl;
    cout << S2 << endl;

    cout << endl;

    cout << "After DIFFERENCE Operation of S1 and S2" << endl;
    S5 = S1.Difference(S2);
    cout << "MySet S5 Contents" << endl;
    cout << S5 << endl;

    cout << endl;

    cout << "MySet S1 Contents" << endl;
    cout << endl;
    cout << S1 << endl;

    cout << endl;

    cout << "MySet S2 Contents" << endl;
    cout << endl;
    cout << S2 << endl;

    cout << endl;

    S6 = S1.Union(S2);

    if(S6 == S3) {
        cout << "S3 and S6 ARE EQUAL" << endl;
    }
    else {
        cout << "S3 and S6 ARE NOT EQUAL" << endl;
    }

    if(S1 == S6) {
        cout << "S1 and S6 ARE EQUAL" << endl;
    }
    else {
        cout << "S1 and S6 ARE NOT EQUAL" << endl;
    }
    cout << "Please enter a path to a third input file: ";
    cin >> inputFile;

    ifstream inf3(inputFile);

    if(!inf3) {
        cout << "Error opening file " << inputFile << endl;
        return -1;
    }

    while(inf3 >> num) {

        if(S1.addelt(num)) {
            cout << num << " was successfully added to S1" << endl;
        }
        else {
            cout << num << " ALREADY PRESENT IN S1" << endl;
        }
    }

    inf3.close();

    cout << endl;

    cout << "S1 AFTER ADDITION of elements" << endl;
    cout << "MySet S1 Contents" << endl;

    cout << endl;

    cout << S1 << endl;

    cout << endl;

    cout << "Please enter a path to an fourth file: ";
    cin >> inputFile;

    ifstream inf4(inputFile);

    if(!inf4) {
        cout << "Error opening file " << inputFile << endl;
        return -1;
    }

    while(inf4 >> num) {

        if(S1.deleteelt(num)) {
            cout << num << " was successfully deleted to S1" << endl;
        }
        else {
            cout << num << " NOT FOUND" << endl;
        }
    }

    inf4.close();

    cout << endl;

    cout << "S1 AFTER DELETION of elements" << endl;
    cout << "MySet S1 Contents" << endl;
    cout << endl;
    cout << S1 << endl;

    cout << endl;

    cout << "OUTPUT FOR ORDERED SETS" << endl;

    cout << endl;

    cout << "Please enter a path to an input file: ";
    cin >> inputFile;

    ifstream inf5(inputFile);

    if(!inf5) {
        cout << "Error opening file " << inputFile << endl;
        return -1;
    }

    while(inf5 >> num) {
        OS1.addelt(num);
    }

    inf5.close();

    cout << "Please enter a path to a second input file: ";
    cin >> inputFile;

    ifstream inf6(inputFile);

    if(!inf6) {
        cout << "Error opening file " << inputFile << endl;
        return -1;
    }

    while(inf6 >> num) {
        OS2.addelt(num);
    }

    inf6.close();

    cout << "BEFORE OPERATIONS" << endl;
    cout << "OrderedSet OS1 Contents" << endl;
    cout << endl;
    cout << OS1 << endl;

    cout << endl;

    cout << "OrderedSet OS2 Contents" << endl;
    cout << endl;
    cout << OS2 << endl;

    cout << endl;

    cout << "OrderedSet OS3 Contents" << endl;
    cout << endl;

    cout << OS3 << endl;

    cout << "After UNION Operation of OS1 and OS2" << endl;
    cout << "OrderedSet OS3 Contents" << endl;

    OS3 = OS1.Union(OS2);

    cout << endl;

    cout << OS3 << endl;

    cout << endl;

    cout << "OrderedSet OS1 Contents" << endl;
    cout << endl;
    cout << OS1 << endl;

    cout << endl;

    cout << "OrderedSet OS2 Contents" << endl;
    cout << endl;
    cout << OS2 << endl;

    cout << endl;

    cout << "After INTERSECTION Operation of OS1 and OS2" << endl;
    cout << "OrderedSet OS4 Contents" << endl;

    OS4 = OS1.Intersection(OS2);

    cout << endl;

    cout << OS4 << endl;

    cout << endl;

    cout << "After DIFFERENCE Operation of OS1 and OS2" << endl;
    cout << "OrderedSet OS5 Contents" << endl;

    cout << endl;

    OS5 = OS1.Difference(OS2);

    cout << OS5 << endl;

    cout << endl;

    OS6 = OS1.Union(OS3);

    cout << OS6 << endl;

    if(OS3 == OS6) {
        cout << "S3 and S6 ARE EQUAL" << endl;
    }
    else {
        cout << "S3 and S6 ARE NOT EQUAL" << endl;
    }

    if(OS1 == OS6) {
        cout << "S1 and S6 ARE EQUAL" << endl;
    }
    else {
        cout << "S1 and S6 NOT ARE EQUAL" << endl;
    }

    cout << "Please enter a path to a third input file: ";
    cin >> inputFile;

    ifstream inf7(inputFile);

    if(!inf7) {
        cout << "Error opening file " << inputFile << endl;
        return -1;
    }

    while(inf7 >> num) {
        if(OS1.addelt(num)) {
            cout << num << " was successfully added to OS1" << endl;
        }
        else {
            cout << num << " ALREADY PRESENT IN OS1" << endl;
        }
    }

    inf7.close();

    cout << endl;

    cout << "OS1 AFTER ADDITION of elements" << endl;
    cout << "OrderedSet OS1 Contents" << endl;
    cout << endl;

    cout << OS1 << endl;

    cout << endl;

    cout << "Please enter a path to a fourth input file: ";
    cin >> inputFile;

    ifstream inf8(inputFile);

    if(!inf8) {
        cout << "Error opening file " << inputFile << endl;
        return -1;
    }

    while(inf8 >> num) {

        if(OS1.deleteelt(num)) {
            cout << num << " was successfully deleted to OS1" << endl;
        }
        else {
            cout << num << " NOT FOUND" << endl;
        }
    }

    cout << endl;

    cout << "OS1 AFTER DELETION of elements" << endl;
    cout << "OrderedSet OS1 Contents" << endl;
    cout << endl;

    cout << OS1 << endl;

    cout << endl;

    cout << "PROGRAM COMPLETE" << endl;


    return 0;
}
