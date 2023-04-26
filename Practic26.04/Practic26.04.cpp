#include <iostream>
#include "Functor.h"
using namespace std;

#include <boost/scoped_ptr.hpp>
// scoped_ptr #include<boost>
void test_scoped() {
    boost::scoped_ptr<int> p1(new int(6));
    boost::scoped_ptr<int> p2(new int(4));
    
    // p1 = p2; - Error
}

// auto_ptr
void test_auto() {
    auto_ptr<int> p1(new int(12));
    auto_ptr<int> p2(new int(4));
    cout << *p2 << " " << *p1 << endl;
    p2 = p1;
    p2.reset(new int{ 67 });
    cout << *p2 << " ";
}

// unique_ptr
void test_unique() {
    unique_ptr<int> ptr(new int(6));
    unique_ptr<int[]> ptr1(make_unique<int[]>(55));
    cout << *ptr << endl;
    *ptr = 477;
    //ptr = ptr1;
    int* p = new int(5);
    //ptr = p;
}

// shared_ptr
void test_shared() {
    shared_ptr<int> p1(new int{ 3 });
    shared_ptr<int> p2;
    p2 = p1;
    cout << *p1 << " " << *p2 << endl;
    *p2 += 5;
    cout << *p1 << " " << *p2 << endl;
    cout << p1.get() << " " << p1;    
}

#include <list>
#include <algorithm>

bool isEven(int num) {
    return bool(num % 2);
}

int main()
{
    //test_auto();
    //test_unique();
    //test_shared();

    /*for (int i{1}; i <= 10; i++) {
        list<int> l(10);
        generate_n(l.begin(), l.size(), Functor(i));

        copy(l.begin(), l.end(), ostream_iterator<int>(cout, "\t"));
        cout << endl;
    }*/

    list<int> l;
    list<int>::iterator t;

    for (int i = 1; i <= 10; i++) {
        l.push_back(i);
    }
    copy(l.begin(), l.end(), ostream_iterator<int>(cout, "\t"));
    cout << endl;

    t = remove_if(l.begin(), l.end(), isEven);
    copy(l.begin(), t, ostream_iterator<int>(cout, "\t"));
    cout << endl;
}
