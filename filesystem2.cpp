#include<iostream>
#include<experimental/filesystem>
#include <fstream>
#include <bitset>
#include <string>
namespace fs=std::experimental::filesystem;
void printpermission(fs::perms p)
{
    std::cout << ((p & fs::perms::owner_read) != fs::perms::none ? "r" : "-")
                << ((p & fs::perms::owner_write) != fs::perms::none ? "w" : "-")
                << ((p & fs::perms::owner_exec) != fs::perms::none ? "x" : "-")
                << ((p & fs::perms::group_read) != fs::perms::none ? "r" : "-")
                << ((p & fs::perms::group_write) != fs::perms::none ? "w" : "-")
                << ((p & fs::perms::group_exec) != fs::perms::none ? "x" : "-")
                << ((p & fs::perms::others_read) != fs::perms::none ? "r" : "-")
                << ((p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
                << ((p & fs::perms::others_exec) != fs::perms::none ? "x" : "-")
                << '\n';
}
int main()
{ 
std::ofstream("perm.txt");
    std::cout<<"perm.txt has permissions:"<<std::endl;
    printpermission(fs::status("perm.txt").permissions());
    /*Changing Permissions
     */
    fs::permissions("perm.txt",fs::perms::owner_exec | fs::perms::group_write|fs::perms::add_perms);
    printpermission(fs::status("perm.txt").permissions());
    fs::remove("perm.txt");
}
