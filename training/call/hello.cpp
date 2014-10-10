#include <iostream>
#include <string>

class foo
{
public: 
    foo(const char * name)
    {
        this->name = std::string(name);
    }

    __declspec(noinline)
    void speak()
    {
        std::cout << "Hello, my name is " << name << std::endl;
    }

private:
    std::string name;
};

int main()
{
    foo * fred = new foo("fred");
    fred->speak();
    delete fred;
    return 0;
}
