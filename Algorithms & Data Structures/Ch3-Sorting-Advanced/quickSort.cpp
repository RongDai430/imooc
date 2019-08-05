//
//	Created by Rong Dai on 8/5/19
//
//��������
//���ڻ����������У����������ʼ����Partition����
//�����кܶ��ظ�Ԫ�����У��������ŵ�Partition������������·���� 

#include<iostream>
#include<algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertSort.h"

using namespace std;

//��arr[l..r]�������ŵ�partition����
//��������ֵ��ʹ��arr[l..p-1] < arr[p]��arr[p+1...r] > arr[p] 
template<typename T> 
int __partition(T arr[], int l, int r){
	swap(arr[rand() % (r - l + 1) + l], arr[l]); //�����׼ֵ
	T v = arr[l];
	//arr[l+1...i) <= v; arr(j...r] >= v
	int i = l + 1, j = r;
	while(true){
		while(arr[i] < v && i <= r) i++;
		while(arr[j] > v && j >= l + 1) j--;
		if(i > j) break;
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
	//ѭ��������iͣ���ڵ�һ�����ڵ���v��������jͣ���ڵ�һ��С�ڵ���v������ 
	swap(arr[l], arr[j]);
	return j; 
}

//��arr[l..r]����partition����
//��������ֵ��ʹ��arr[l..p-1] < arr[p]��arr[p+1...r] > arr[p] 
template<typename T>
int __partition2(T arr[], int l, int r){		//��������Partition�������ظ�Ԫ�ؽ϶�����飬�ᵼ�����ҷָƽ�⣬Ч�ʵ��� 
	
	swap(arr[rand() % (r - l + 1) + l], arr[l]);	//�����Ż������ѡȡpartition��"��׼ֵ" 
													//�������л�������������м�����Ż�Ч��
													//��������Ժ󣬿��ŵĸ��Ӷ�����ֵΪO(NLogN) 
	
	T v = arr[l]; 
	//arr[l+1...j] < v; arr[j+1...i) >= v
	int j = l;
	for(int i = l + 1; i <= r; i++) {	//��ǰ���ǵ�������i 
		if(arr[i] >= v) continue;
		swap(arr[j + 1], arr[i]);
		j++;
	}
	swap(arr[l], arr[j]); 
	return j;
}



//��arr[l..r]���п������� 
template<typename T>
void __quickSort(T arr[], int l, int r){
	//if(l >= r) return;
	
	if(r - l <= 15){				//ͬ���ڵײ㣬��С����ʱʹ�ò������� 
		insertSort_lr(arr, l, r);
		return;
	}
	
	int p = __partition(arr, l , r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n){
	srand(time(NULL));
	__quickSort(arr, 0, n - 1); 
}

int main(){
	
	int n = 100000;
	int *arr1 = SortTestHelper::generateRandomArrary(n, 0, 10);
	int *arr2 = SortTestHelper::copyIntArrary(arr1, n);
	
	SortTestHelper::testSort("Merge Sort",mergeSort,arr1, n);
	SortTestHelper::testSort("Quick Sort",quickSort,arr2, n);
	
	delete[] arr1;
	delete[] arr2;
	
	return 0;
}
