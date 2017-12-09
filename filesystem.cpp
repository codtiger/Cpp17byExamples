#include <iostream>
#include <experimental/filesystem>
#include <fstream>
#include <bitset>
#include <string>
namespace fs=std::experimental::filesystem;
int main()
{
    //fs::remove_all("sandbox/");
    /*getting current path
    */
    std::cout<<"current path"<<fs::current_path()<<std::endl;
    fs::path p=fs::current_path();
    /*extracting file name
    */
    p+="/variant.cpp";
    std::cout<<"filename"<<p.filename()<<std::endl;
    /*renaming one file*/
    std::ofstream file("./1.txt");
    if(file.is_open())
        file.close();
    fs::rename("./1.txt","./2.txt");
    std::string path=fs::current_path();
    /*iterating over the items in a file
    */
    for(auto& t:fs::directory_iterator(path))
        std::cout<<t<<std::endl;
    /*replacing file extension and creating new file
    */
    file.open(fs::path("2.txt").replace_extension(".cpp"));
    if(!file.is_open())
        std::cout<<"Error opening file"<<std::endl;
    std::string s="include<iostream>\n int main()\n{\nstd::cout<<\"Hello Worl<<std::endl;\n return 0;}";
    file<<s;
    file.close();
    /*create directory and remove it
    */
    fs::path dir=fs::current_path();
    std::cout<<dir<<std::endl;
    fs::create_directories(dir/"first/second/third");
    int n=fs::remove_all(dir/"first");
    std::cout<<"Removed "<<n<<" directories"<<std::endl;
    /*copy files to another directory
    */
    fs::path filepath=fs::current_path()/"2.txt";
    std::cout<<fs::file_size(filepath)<<std::endl;
    fs::path directory="/usr/local";
    try{
        std::cout<<fs::file_size(directory)<<std::endl;
    }
    catch(fs::filesystem_error& er)
    {
        std::cout<<er.what()<<std::endl;
    }
    /*directory space information 
    */
    fs::space_info space=fs::space("/usr/local");
    std::cout<<"free space "<<space.free<<std::endl
    <<"capacity "<<space.capacity<<std::endl
    <<"available space "<<space.available<<std::endl;
    /*copy file
    */
    std::ofstream("newfile.txt").put('1');
    fs::create_directory("dir");
    fs::copy_file("./newfile.txt","dir/newfile2.txt");
    std::cout<<std::ifstream("dir/newfile2.txt").rdbuf()<<std::endl;
    fs::create_directory("dir/a");
    try{
        fs::copy_file("dir/a","dir/b");
    }
    catch(fs::filesystem_error& er)
    {
        std::cout<<er.what()<<std::endl;

    }

}

