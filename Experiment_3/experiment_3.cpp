#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main()
{
    int num_integers;
    cin >> num_integers;
    vector<char> my_arr(num_integers);
    for (int i = 0; i < num_integers; i++)
    {
        cin >> my_arr[i];
    }
    unordered_map<int, int> my_map;
    my_map[0] = -1;
    int current_balance = 0;
    int max_len = 0;
    for (int i = 0; i < num_integers; i++)
    {
        if (my_arr[i] == 'P') current_balance++;
        else current_balance--;

        if (my_map.count(current_balance)) max_len = max(max_len, i - my_map[current_balance]);
        else my_map[current_balance] = i;
    }
    cout << max_len << endl;
    return 0;
}
