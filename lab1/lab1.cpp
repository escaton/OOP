//---------------------------------------------------------------------------

#include <iostream>
using namespace std;

#include "List.h"
//---------------------------------------------------------------------------

int main(int argc)
{
	List *l = new List();
	int i;

	int men;
    do
    {
        cout<<"1.Input list, while !=0\n";
        cout<<"2.Delete element with index i since=0. Input i\n";
        cout<<"3.Print sequence\n";
        cout<<"4.Exit\n";

        cin>>men;
        switch (men)
        {
            case 1:
                cout<<"1.Input sequence, while !=0\n";
                int x;
                cin>>x;
                while (x != 0) {
                	l->add(x);
                	cin>>x;
                }
            break;
            case 2:
               cout<<"2.Delete element since=0\n";
               int y;
               cin>>y;
               l->remove(l->get(y));
            break;
            case 3:
                cout<<"3.Print sequence\n";
                l->print();
            break;
           case 4:
                cout<<"4.Exit\n";

            break;

            default: ;
        }

    }
    while (men !=4);

	return 0;
}
//---------------------------------------------------------------------------
