#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int  linSearch(int arr[], int n, int value){
    for(int i = 0; i < n; i++) {
        if(arr[i] == value){
            return i;
        }
    }
    return -1;
}


//recursive approach
int binSearch(int arr[], int left, int right, int value)
{
   if (right >= left) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value)
            return mid;
        if (arr[mid] > value)
            return binSearch(arr, left, mid - 1, value);
        return binSearch(arr, mid + 1, right, value);
    }
    return -1;
}
  
int main()
{
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int value;
    cout<<"Enter value to be searched: "<<endl;
    cin >> value;

    auto start = high_resolution_clock::now();
    //Linear Search was performed here
    int linSearchResult = linSearch(arr, n, value);
    if(linSearchResult==-1){
        cout<<"Element not found in array using linear search."<<endl;
    }
    else{
        cout << value << " was found at " << linSearchResult+1 << "in array using linear search" << endl;
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken in microseconds " << duration.count() << endl << endl;

    //Binary Search was performed here
    start = high_resolution_clock::now();
    int binSearchResult = binSearch(arr, 0, n - 1, value);
    if(binSearchResult==-1){
        cout<<"Element not found in array using Binary Search"<<endl;
    }
    else{
        cout << value << " was found at " << binSearchResult+1 << "in array using Binary search" << endl;
    }
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken in microseconds " << duration.count() << endl << endl;
    return 0;
}
