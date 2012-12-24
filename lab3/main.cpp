#include <iostream>
#include "fraction.h"

using namespace std;

int main()
{
    Fraction test(4,4);
    Fraction test2(2,5);
    Fraction test3(1);
    test.print();
    if(test3==1){
        cout<<"true";
    }
    cout<<endl;
    return 0;
}
