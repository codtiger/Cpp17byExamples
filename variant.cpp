#include<iostream>
#include <variant>
#include <string>
#include <vector>
#include <type_traits>
using namespace std;
int main()
{
    variant<int,float> v=1.0f;
    variant<int,float> w=12.0f;
    try{
        float j=get<float>(w);
        cout<<"variant holds a float that is "<<j<<endl;
        int i=get<int>(v);
        cout<<"variant holds an integer that is"<<i<<endl;
    }
    catch(bad_variant_access &ex)
    {
        cout<<ex.what()<<endl;
    }
variant<string,bool> v2="abc";
cout<<holds_alternative<string>(v2)<<endl;
variant<string,bool> v3=move(string("abc"));
cout<<"the index held by v3 is "<<v3.index()<<endl;
using var=variant<int,double,string,bool>;
vector<var> vec{1.0,11,"there"s,true};
for(auto& arg:vec)
{
    var w=visit([](auto& i)->var{return i+i;},arg);
    if(holds_alternative<string>(w))
        cout<<std::get<string>(w)<<endl;
    else if(holds_alternative<int>(w))
        cout<<std::get<int>(w)<<endl;
    else if(holds_alternative<double>(w))
        cout<<std::get<double>(w)<<endl;
    else 
        cout<<get<bool>(w)<<endl;
}
    
return 0;
}