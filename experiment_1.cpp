#include <bits/stdc++.h>
using namespace std;
// Adding Global Variables to help in counting
int number_operations = 0;
int depth = 0;
void complexRec(int n)
{

    if (n <= 2)
    {
        number_operations++;
        return;
    }

    int p = n;
    while (p > 0)
    {
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i] = i ^ p;
            // Increment the no. of operations
            number_operations++;
        }
        p >>= 1;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++)
    {
        small[i] = i * i;
        // Increment the no. of operations
        number_operations++;
    }

    if (n % 3 == 0)
    {
        reverse(small.begin(), small.end());
        // Increment the no. of operations
        number_operations++;
    }
    else
    {
        reverse(small.begin(), small.end());
        // Increment the no. of operations
        number_operations++;
    }

    complexRec(n / 2);
    complexRec(n / 2);
    complexRec(n / 2);
    depth++;

}
int calc_depth(int n)
{
    int count = 0;
    while(n>0)
    {
        n = n / 3;
        count++;
    }
    return count + 1;
}
//Main Function added to aid in running the code
int main()
{
    int numb;
    cin >> numb;
    complexRec(numb);
    cout << "No. of Operations: " << number_operations << endl;
    cout << "Depth of Tree: " << calc_depth(numb) << endl;
    return 0;
}
// Recursive Relation
// T(n) = 3*T(n/2) + n*log(n)

// Time Complexity : O(n^(log (3) base 2))s
