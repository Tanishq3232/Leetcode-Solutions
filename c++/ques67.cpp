#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<int> bubbleSort(vector<int> a){
	
	for(int i=0;i<a.size()-1;i++){
		
		for(int j=0;j<a.size()-i-1;j++){
			if(a[j]>a[j+1]){
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	return a;
}

vector<int> insertionSort(vector<int> a){
	
	for(int i=1;i<a.size();++i){
		int j = i-1,key = a[i];
		while(j>-1 and a[j]>key){
			a[j+1] = a[j];
			j=j-1;
		}
		a[j+1] = key;
	}
	
	return a;
}

vector<int> selectionSort(vector<int> a){
	
	for(int i=0;i<a.size();i++){
		int min = i;
		for(int j = i+1;j<a.size();j++){
			if(a[min] > a[j]){
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	
	return a;
}




int main() {
    cout << "\033[1;31m======================================================================================================================\033[0m" << endl;
    cout << "\033[1;31m| SelectionSort insertionSort & bubbleSort ---- DSA LAB WORK 29/09/2021 ---- Submitted by: Vishal Teotia (19BME1133) |\033[0m" << endl;
    cout << "\033[1;31m======================================================================================================================\033[0m" << endl;
    int n;
    cout << " Enter the size of array : " << endl;
    cin >> n;
    cout << "Enter the elements of the array : " << endl;
    vector<int> arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    auto start = high_resolution_clock::now();
    vector<int> afterbubble = bubbleSort(arr);
    auto stop = high_resolution_clock::now();
    cout << "Array after bubbleSort : ";
    for(auto i: afterbubble){
        cout << i << " ";
    }
    cout << endl;
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken in microseconds " << duration.count() << endl << endl;
    start = high_resolution_clock::now();
    vector<int> afterinsertion = insertionSort(arr);
    stop = high_resolution_clock::now();
    cout << "Array after insetionSort : ";
    for(auto i: afterinsertion){
        cout << i << " ";
    }
    cout << endl;
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken in microseconds " << duration.count() << endl << endl;
    start = high_resolution_clock::now();
    vector<int> afterselection = selectionSort(arr);
    stop = high_resolution_clock::now();
    cout << "Array after selectionSort : ";
    for(auto i:afterselection){
        cout << i << " ";
    }
    cout << endl;
    duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken in microseconds " << duration.count() << endl << endl;
    return 0;
}
