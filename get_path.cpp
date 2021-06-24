#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

int main()
{
    string path;
    path = getenv("path");
    cout<<"pathvar = "<<path<<endl;
    return 0;
}