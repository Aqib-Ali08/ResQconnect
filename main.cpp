#include <iostream>
using namespace std;
int main()
{

    int sum = 0;
    for (int i = 1; i < 5; ++i)
    {
        sum = sum + i;
        cout << i << endl;
    }
    for (int i = 1; i < 5; i++)
    {
        sum = sum + i;
        cout << i << endl;
    }
}
/*
For Loop 1 (Detailed Explanation):
int i=1;: Initializes i with the value 1.

i<5;: Checks if i is less than 5. If true, the loop body is executed; otherwise, the loop terminates.

++i: Increments i by 1 before entering the loop body.

************************************************************************************

For Loop 2 (Detailed Explanation):
int i=1;: Initializes i with the value 1.

i<5;: Checks if i is less than 5. If true, the loop body is executed; otherwise, the loop terminates.

i++: Increments i by 1 after the loop body is executed.
*/