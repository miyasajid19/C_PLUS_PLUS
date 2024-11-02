#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
class Directory
{
    // map<string, unsigned int,greater<string>> directory;//to store in desending order
    map<string, unsigned int> directory;

public:
    Directory() {}
    void addData(string name, unsigned int data)
    {
        directory[name] = data;
    }

    void Display()
    {
        for (auto x : directory)
        {
            cout << "Name : " << x.first << "\tPhone No. :: " << x.second << endl;
        }
    }
};
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    Directory dir;
    dir.addData("Uchiha Obito", 407);
    dir.addData("Hatake Kakashi", 432);
    dir.addData("Nohara Rin", 407432);
    dir.Display();
    return EXIT_SUCCESS;
}