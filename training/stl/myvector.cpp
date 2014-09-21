#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> ss;
    ss.push_back("1");
    ss.push_back("2");
    ss.push_back("3");
    for (int i = 0; i < (int)ss.size(); i++)
        cout << ss[i] << endl;
}
