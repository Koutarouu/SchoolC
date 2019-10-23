#include<iostream>
using namespace std;

class ResizableArray{
	private:
		int length; //longitud inicial
		int *items;
		int size;
		void ensureExtraCapacity();		
	public:
		ResizableArray();
		int Size();
		void set(int index, int item);
		void append(int item);
		int get(int index);
};

ResizableArray::ResizableArray(){
	length=8;
	items = new int[length];
	size = 0;
}

void ResizableArray::ensureExtraCapacity() {
	if (size == length) {
		int *copy = new int[size*2];
		for(int i=0; i<size; i++){
			copy[i] = items[i];
		}
		items = copy;
		length *= 2;
	}
}

int ResizableArray::Size(){
	return size;
}

void ResizableArray::set(int index, int item){
	if(index < 0 || index >= size){
		cout<<"Invalid Index"<<endl;
		return;
	}
	items[index] = item;
}

void ResizableArray::append(int item){
	ensureExtraCapacity();
	items[size] = item;
	size++;
}

int ResizableArray::get(int index){
	if(index < 0 || index >= size){
		cout<<"Invalid Index"<<endl;
		return -1;
	}
	return items[index];
}

//Left Rotation

int main(){
	ResizableArray a,rotate;
	int n,d,x;
	
	cin>>n>>d;
	
	for(int i=0; i<n; i++){
		cin>>x;
		a.append(x);
	}
	
	for(int i=d; i<n; i++){
		rotate.append(a.get(i));
	}
	for(int i=0; i<d; i++){
		rotate.append(a.get(i));
	}
	
	for(int i=0; i<n; i++){
		cout<<rotate.get(i)<<' ';
	}
	return 0;
}
