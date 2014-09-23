#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<int, string> mymap;
    mymap[1] = "Map1";
    mymap[2] = "Map2";
    mymap[3] = "Map3";
    mymap[4] = "Map4";
    mymap[5] = "Map5";
    for (map<int,string>::iterator mi = mymap.begin(); mi != mymap.end(); ++mi)
        cout << (*mi).first << ": " << (*mi).second << endl;
}
