// #include<iostream>
// using namespace std;
// int main()
// {
//     for(unsigned i=7;i>=0;--i)
//     {
//         cout<<i<<endl;
//     }
//     return 0;
// }

// #include <iostream>
// #include <fstream>

// int main() {
//     std::ifstream file("nonexistent_file.txt");

//     if (!file) {
//         std::cerr << "Error: Could not open the file 'nonexistent_file.txt'" << std::endl;
//         return 1; // Return a non-zero value to indicate an error
//     }

//     // Rest of the program (if file opened successfully)
//     std::cout << "File opened successfully." << std::endl;

//     return 0; // Return 0 to indicate successful completion
// }
#include<iostream>
int main()
{
    std:: cout<<5e4<<std::endl;
    std:: cout<<5E-4<<std::endl;
    std::cout<<3.1415E-434f<<std::endl;
    std:: cout<<sizeof(short);
    std:: cout<<sizeof(short int);
    std:: cout<<sizeof(int);
    std:: cout<<sizeof(long long);
    
}