//
//	Created by Rong Dai on 8/6/19
//
//���ȶ��У���N��Ԫ����ȡ��ǰM�����O(NlogM)
//��,���ȶ��У���Ӻͳ���O(lgN) 

//�����ѵķ�ʽ���������� 
//��n��Ԫ�ز���նѣ��㷨���Ӷ�ΪO(NlogN) 
//Heapify�Ĺ��̣���arr[n/2]��ǰ����Ԫ��Shift Down���㷨���Ӷ�ΪO(n) 

//����
//����ĳ���ڵ��ֵ�����ڸ��ڵ��ֵ������һ����ȫ������

#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<cmath>
#include<cassert>
#include<typeinfo>

using namespace std;

template<typename Item>
class MaxHeap{
private:
	Item* data;
	int count;
	int capacity;
	void shiftUp(int k){		//Shift Up ������˽�У����븸�ڵ�ֱ�ӽ��� 
		while(k >1 && data[k/2] < data[k]){
			swap(data[k/2], data[k]);
			k/=2;
		}
	}
	
	void shiftDown(int k){		////Shift Down ������˽�У����뺢���д��ֱ�ӽ���
		while(k*2 <= count){	//�ж���û������
			int j = 2*k;		//data[k]��data[j]����
			if(j + 1 <= count && data[j + 1] > data[j])  j+=1;	//��ȫ������������û������ 
			if(data[k] >= data[j]) break;
			swap(data[k],data[j]);
			k = j; 
		} 
	}

public:
	//�Ѷ�����Ϊ1������ 
	MaxHeap(int capacity){	//������Ϊcapacity 
		data = new Item[capacity + 1];
		count = 0;
		this->capacity= capacity;
	}
	
	void insert(Item item){	//���Ԫ�أ�Shift up 
		assert(count + 1 <= capacity);
		data[++count] = item;
		shiftUp(count);
	}
	
	Item extractMax(){ 	//ȡ�����ֵ�����Ѷ�Ԫ�أ�Ȼ�󽻻��Ѷ��Ͷ�ĩ��ά����, Shift Down 
		assert(count > 0);
		Item ans = data[1];
		swap(data[1], data[count--]);
		shiftDown(1);
		return ans;
	}
	
	~MaxHeap(){				//�������� 
		delete [] data;
	}
	
	int size(){
		return count;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	

};

int main(){
	
	MaxHeap<int> maxheap = MaxHeap<int>(100);
	
	srand(time(NULL));
	for(int i = 0; i < 10; i++)
		maxheap.insert(rand()%10);
	while(!maxheap.isEmpty())
		cout<<maxheap.extractMax()<<" ";
	 
	return 0;
} 
