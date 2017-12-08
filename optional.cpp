#include <iostream>
#include <experimental/optional>
#include<string>
namespace exp=std::experimental;
using namespace std;
exp::optional<string> create(bool b)
{
if(b)
return "NEW STRING";
    return {};
}
int main()
{
std::cout<<"create (false) empty"<<create(false).value_or("empty")<<std::endl;
if(auto str=create(true))
{
std::cout<<"create(true)"<<*str<<std::endl;
}
return 0;
}

