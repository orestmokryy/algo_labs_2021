#include <bits/stdc++.h>
using namespace std;

bool findSumOfThree(int Array[], int arr_size, int sum)
{
    int left, right;
    sort(Array, Array + arr_size);
    
    for (int i = 0; i < arr_size - 2; i++) {      
        left = i + 1;  
        right = arr_size - 1; 
        while (left < right) {
            if (Array[i] + Array[left] + Array[right] == sum) {
                printf("Sum elements are %d, %d, %d", Array[i],
                       Array[left], Array[right]);
                return true;
            }
            else if (Array[i] + Array[left] + Array[right] < sum)
                left++;
            else 
                right--;
        }
    }   
    return false;
}
 

int main()
{
    int Array[] = { 1, 4, 45, 6, 10, 8 };
    int sum = 22;
    int arr_size = sizeof(Array) / sizeof(Array[0]);
 
    findSumOfThree(Array, arr_size, sum);
 
    return 0;
}