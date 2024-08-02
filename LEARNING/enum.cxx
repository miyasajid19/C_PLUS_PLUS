#include<iostream>
int main()
{
    // enum week {sunday=12,monday,tuesday, wednesday, thrusday, friday, saturday};
    // as a hint we write enumurators in capital form 
    enum week { SUNDAY,MONDAY,TUESDAY,WEDNESDAY,THRUSDAY,FRIDAY,SATURDAY};

    enum week day;
    day=FRIDAY;
    std :: cout<<day;
    return 0;
}