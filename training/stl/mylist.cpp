#include <iostream>
#include <string>
#include <list>

using namespace std;

int main() {
    list<string> mylist;
    mylist.insert(mylist.end(), "one");
    mylist.insert(mylist.end(), "two");
    mylist.insert(mylist.end(), "three");
    for (list<string>::iterator li = mylist.begin(); li != mylist.end(); ++li)
        cout << (*li) << endl;
}
