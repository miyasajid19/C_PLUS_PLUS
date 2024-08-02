#include<iostream>
int main()
{
    std :: string s,t,u;
    s="hello ";
    t=s+ "sajid ";// strings in c++ can be concatenated via plus operator unlike in c where we have to use builtin functions like strcat(str1,str2)
    u="All i want was the love and what i get is the pain";
    std:: cout<<s<<std::endl<<t<<std::endl<<u<<std::endl;
    std:: cout<<"the length  of "<< u << " is "<<u.size()<<std::endl;
    std:: cout<<"the character in index 5 is "<<t[4];
    return 0;
}