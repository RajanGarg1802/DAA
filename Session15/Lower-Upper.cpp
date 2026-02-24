#include<iostream>
using namespace std;

int lowerbound(int arr[], int target,int arrsize)
{
    int temp;
    int left = 0;
    int right = arrsize - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] >= target)
        {
            right = mid - 1;
            temp = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return temp;
}

int upperbound(int arr[], int target, int arrsize)
{
    int temp;
    int left = 0;
    int right = arrsize - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            temp = mid;
        }
    }
    return temp;
}

int main() {
    int arr[] = {5,6,5,7,2,3};
    int arr2[] = {2,5,6,6,8};
    int arrsize = sizeof(arr)/sizeof(arr[0]);
    int arr2size = sizeof(arr2)/sizeof(arr2[0]);
    int sum = 11;
    int pairs = 0;
    for(int i = 0; i<arrsize; i++)
    {
        int left = 0;
        int right = arr2size-1;
        int target = sum - arr[i];
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(arr2[mid] == target)
            {
                int n = lowerbound(arr2, target, arrsize);
                int m = upperbound(arr2,target,arrsize);
                pairs += (m - n);
                break;
            }
            if(arr2[mid] > target) 
            {
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
    }
    cout << pairs;
    return 0;
}