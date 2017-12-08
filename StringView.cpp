#include<iostream>
#include <experimental/string_view>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include <chrono>
using namespace std;
unsigned long int repitition=100000000;
int main()
{
    ifstream file("A Tale of Two Cities.txt"); 
    std::stringstream sstream;
    sstream<<file.rdbuf();
    string text=sstream.str();
    size_t size=text.size();
    std::random_device seed;
    std::seed_seq seedseq{seed(),seed(),seed(),seed(),seed()};
    std::default_random_engine engine(seedseq);
    uniform_int_distribution<> dis(0,size-40-1);
    vector<int> offset;
    std::string_view textview(text);
    for(unsigned long int i=0;i<repitition;i++)
        offset.push_back(dis(engine));
        /*Normal String*/
    auto then=chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    for(unsigned long int i=0;i<repitition;i++)
        text.substr(offset[i],40);
    auto now=chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    cout<<"Time for substr operation on normal string: "<<double((now-then).count())/1000<<" seconds"<<endl;
    /*String View*/

    then=chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    for(unsigned long int i=0;i<repitition;i++)
        textview.substr(offset[i],40);
    now=chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch());
    cout<<"Time for substr operation on string view: "<<double((now-then).count())/1000<<" seconds"<<endl;
    
}