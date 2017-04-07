// C++ implementation of Radix Sort
//Author/reference: http://www.geeksforgeeks.org/radix-sort/
#include<iostream>
#include <time.h>
#include <stdio.h>
using namespace std;

// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] of size n using
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

/*
 * Inform the time elapsed from the start of the stress loop until its end
 */
void print_time(clock_t start_time, clock_t end_time, int value)
{
	printf("Time on Stress Loop,vector with size = %d: %lf s\n",value, (double) (end_time - start_time)/CLOCKS_PER_SEC);
}

// Driver program to test above functions
int main()
{
    void radixTest(int value);
    void statisticInformation(int value);
    for(int aux =2; aux<70;aux++){
      statisticInformation(aux);
    }

    return 0;
}
void radixTest(int value){
  int arr[] = {10101010,11111111,12121212,13131313,14141414,15151515,16161616,17171717,18181818,19191919,20202020,21212121,22222222,23232323,24242424,25252525,26262626,27272727,28282828,29292929,30303030,31313131,32323232,33333333,34343434,35353535,36363636,37373737,38383838,39393939,40404040,41414141,42424242,43434343,44444444,45454545,46464646,47474747,48484848,49494949,50505050,51515151,52525252,53535353,54545454,55555555,56565656,57575757,58585858,59595959,60606060,61616161,62626262,63636363,64646464,65656565,66666666,67676767,68686868,69696969,70707070,71717171,72727272,73737373,74747474,75757575,76767676,77777777,78787878,79797979};
  int n = sizeof(arr)/sizeof(arr[0]);
  radixsort(arr, value);
}

void statisticInformation(int value){

  clock_t start_time = clock();
  int aux;
  for(aux = 0; aux< 100000; aux++){
    radixTest(value);
  }
  clock_t end_time = clock();
  print_time(start_time, end_time, value);

}
