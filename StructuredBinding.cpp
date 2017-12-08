#include <iostream>
#include <tuple>
#include <chrono>
#include <ctime>
#include <vector>
std::pair<int,int> divide(const int &a,const int &b)
{
    int remainder=a%b;
    int fraction=a/b;
    return std::pair<int,int>(fraction,remainder);
}
std::tuple<std::string,std::chrono::system_clock::time_point,unsigned int>
 stock_info(const std::string &name)
{
    /*simple return for the sake of this example*/
    return std::tuple<std::string,std::chrono::system_clock::time_point,unsigned int>
    (name,std::chrono::system_clock::now(),300000);
}
struct Employee
{
    std::string name;
    std::string familyname;
    unsigned long salary;
    int id;
    Employee(std::string nm,std::string fm,unsigned sal,int id)
    :name(nm),familyname(fm),salary(sal),id(id)
    {

    };
};
int main()
{
    /*before cpp17
    */
    const auto result(divide(10,3));
    std::cout<<"fraction is "<<result.first<<" and remainder is "<<result.second<<std::endl;
    /*cpp17's own structured binding
    */
    auto [fraction,remainder]=divide(12,4);
    std::cout<<"fraction is "<<fraction<<" and remainder is "<<remainder<<std::endl;
    /*for tuples*/
    const auto [name,time,price]=stock_info("COMP");
    time_t tt=std::chrono::system_clock::to_time_t(time);
    tm utc_tm=*gmtime(&tt);
    std::cout<<"name:"<<name<<"\t"<<"current time:"<<utc_tm.tm_year+1900<<"/"
    <<utc_tm.tm_mon<<"/"<<utc_tm.tm_mday<<"\tprice:"<<price<<std::endl;
    /*fields of a struct*/
    std::vector<Employee> employees;
    employees.emplace_back("Ali","Sadeghi",1000000,3024);
    employees.emplace_back("Mahdi","Shokoohi",2000000,3025);
    for( auto& [name,familyname,salary,id] : employees)
        std::cout<<name<<"\t"<<familyname<<"\t"<<salary<<"\t"<<id<<std::endl;
    return 0;
}