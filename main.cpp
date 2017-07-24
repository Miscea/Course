#include <iostream>
#include "Grasm.h"
#include "GrasmElem.h"
#include <math.h>
using namespace std;

int main()
{
    int i;
    int j;
    GrasmElem test[7];
    for(i = 0; i < 7; ++i)
    {
        int deg[6];
        for(j = 0; j < 6; ++j)
        {
            if((i!=0) &&(j==i-1))
            {
                deg[j] = 1;
            }
            else
            {
                deg[j] = 0;
            }
        }
        test[i].elems[0](1.0, pow(2, i), deg);
    }
    int subst[6];
    // Add subst basis generator and adjust it to test array

    cout << "Hello world!" << endl;
    return 0;
}
