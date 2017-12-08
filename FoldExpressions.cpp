#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
template <typename ... T>
auto sum(T ... args)
{
    return (args+ ... );
}
template<typename R,typename ... T>
auto num_occurence(const R& range,T ... values)
{
    return (std::count(std::begin(range),std::end(range),values )+ ...);
}
template <typename A,typename ... T>
void insert_multiple(std::vector<A> &v,T ... items)
{
    (v.push_back(items), ...);
}
template <typename T, typename ... Ts>
bool insert_all(T &set, Ts ... ts)
{
return (set.insert(ts).second && ...);
}
template<typename ... T>
void print_multiple(T& ... s)
{
    (std::cout<< ... << s);
    std::cout<<std::endl;
}
int main()
{
std::cout<<sum(5,4,3,2,1)<<std::endl;
std::vector<int> v={1,2,3,4,5,6,7,8,9};
std::cout<<num_occurence(v,5,8,10,2,-1)<<std::endl;
std::vector<std::string> words;
insert_multiple(words,"Hello","Welcome","Goodbye","Wait","Stop");
for(auto& i:words)
    std::cout<<i<<std::endl;
std::set<int> set;
bool inserted=insert_all(set,1,3,5,3,7,9,1);
std::cout<<(inserted?"All Values inserted":"Some values were dupliace")<<std::endl;
set.clear();
inserted=insert_all(set,1,2,4,5);
std::cout<<(inserted?"All Values inserted":"Some values were dupliace")<<std::endl;
print_multiple("Welcome ","to ","cpp ","17");
}