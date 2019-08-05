//
//	Created by Rong Dai on 8/4/19
//
#include<iostream>
#include<algorithm> 
#include "SortTestHelper.h"
//ѡ������Ͳ������� 
//��������Խ������������Ч�ʷǳ��� 

using namespace std;

//ѡ������,��С�������� 
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

//��������
template<typename T>
void insertSort(T arr[], int n){
	
	for(int i = 1; i < n; i++){
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ�� 
		T tmp = arr[i];
		int j;
		for(j = i; j > 0 && (arr[j - 1] > tmp); j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
} 
int main(){
	
	int n = 10000;
	int *arr = SortTestHelper::generateRandomArrary(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArrary(arr,n); 
	
	//selectionSort(arr, n);
	//SortTestHelper::printArrary(arr, n);
	
	SortTestHelper::testSort("Selection Sort", selectionSort, arr, n); 
	SortTestHelper::testSort("Insert Sort", insertSort, arr2, n); 
	
	delete[] arr;
	delete[] arr2;
	return 0;
}
