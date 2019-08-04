#include<iostream>
#include<algorithm> 
#include "SortTestHelper.h"

using namespace std;

//选择排序,从小到大排序 
template<typename T>
void selectionSort(T arr[], int n){
	for(int i = 0; i < n; i++){
		int minIndex = i; 
		for(int j = i + 1; j < n; j++)
			if(arr[j] < arr[minIndex])
			minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}

int main(){
	
	int n = 1000;
	int *arr = SortTestHelper::generateRandomArrary(n, 0, n);
	selectionSort(arr, n);
	SortTestHelper::printArrary(arr, n);
	
	delete[] arr;
	return 0;
}
