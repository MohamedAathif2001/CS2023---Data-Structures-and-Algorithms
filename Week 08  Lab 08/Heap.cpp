#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int maxIndex = root;  // taking root as maximum index
    int left = 2*root + 1;  // left for finding left child ndex
    int right = 2*root + 2;  // right for finding right child index

    if (left < n && arr[left] > arr[maxIndex])
    {   
        maxIndex = left; // if left child value is higher take it as maximum
    }

    if (right < n && arr[right] > arr[maxIndex])
    {
        maxIndex = right; // if right child value is higher take it as mimmum
    }   
 
    if (root != maxIndex) 
    {
        int value = arr[root]; // if root and maxIndex values are not equal swapping the values
        arr[root] = arr[maxIndex];
        arr[maxIndex] = value;
 
        heapify(arr, n, maxIndex); // using recursion to heapify sub tres
    }      
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{

    // build heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i); // using heapify to create a max heap for the array  
    }
  
    // extracting elements from heap one by one
    for (int i = n-1; i >= 0; i--) 
    {
        int currentRoot = arr[0]; //swapping root value with last value
        arr[0] = arr[i];
        arr[i] = currentRoot;
  
        heapify(arr, i, 0); // max heapify is called to maintain heap property
    }

}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    int n;
    cout << "Enter number of elements in heap: ";
    cin >> n; // taking number of elements in heap as useer input
    cout<<""<<endl;

    int heap_arr[n];
    srand(time(0)); 

    for (int i = 0; i < n; i++) 
    {
        heap_arr[i] = rand() % 100; // filling the array with random integers between 0 and 99
    }

    cout<<"Input array :"<<endl;
    displayArray(heap_arr,n);

    cout<<""<<endl;
  
    heapSort(heap_arr, n);
  
    cout << "Sorted array :"<<endl;
    displayArray(heap_arr, n);
    cout<<""<<endl;
}