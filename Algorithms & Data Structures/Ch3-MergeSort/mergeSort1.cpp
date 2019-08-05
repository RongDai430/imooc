//
//	Created by Rong Dai on 8/5/19
//
//�鲢����
//���֣����Ӷ�ΪO(lgN)
//�鲢�����Ӷ�ΪO(N)

#include<iostream>
#include<algorithm>
#include "SortTestHelper.h"
#include "InsertSort.h"
using namespace std;


//��arr[l...mid]��arr[mid+1...r]�ϲ� 
template<typename T>
void __merge(T arr[], int l, int mid, int r){
	T aux[r - l + 1];	//��ʱ�Ĵ������ 
	for(int i = l; i <= r; i++) aux[i - l] = arr[i];
	
	int i = l, j = mid + 1;
	for(int k = l; k <= r; k++){
		if(i > mid){				//���ж�Խ������ 
			arr[k] = aux[j - l];
			j++;
		}
		else if(j > r){
			arr[k] = aux[i - l];
			i++;
		}
		else if(aux[i - l] < aux[j - l]){
			arr[k] = aux[i - l];
			i++;
		}
		else{
			arr[k] = aux[j - l];
			j++;
		}
	}
}

//�ݹ�����,��arr[l....r]��Χ�������� 
template<typename T>
void __mergeSort(T arr[], int l, int r){
	
	//if(l >= r) return;
	
	if(r - l <= 15){					//��r-l��Сʱ��ѡȡ�������������С���ֵĵݹ�鲢���� 
		insertSort_lr(arr, l, r);		//��Ϊ����С����ʱ���������������Ը��󣬲�������Ч�ʸ��� 
		return;
	}
	
	int mid = (r - l)/2 + l;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	if(arr[mid] <= arr[mid + 1]) return; //�鲢������Ż��������������е��㷨 
	__merge(arr, l, mid, r); 
}

template<typename T>
void mergeSort(T arr[], int n){
	__mergeSort(arr, 0, n - 1); 
}
 
int main(){
	
	int n = 50000;
	int *arr1 = SortTestHelper::generateRandomArrary(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArrary(arr1, n); 
	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertSort, arr2, n);
	
	delete[] arr1;
	delete[] arr2;
	
	return 0;
} 
