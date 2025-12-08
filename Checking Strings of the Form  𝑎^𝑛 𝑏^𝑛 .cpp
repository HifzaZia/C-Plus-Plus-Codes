#include<iostream>
#include<string>

using namespace std;

template <typename T>
class Stack{

    private:
    int cap; //capacity
    T *data;
    int size;
    void resize_cap(int a);

    public:
    Stack(int c=10);
    bool isFull();
    bool isEmpty();
    void push(T a);
    T pop();
    T getTop();
    int topValueIndex();
    Stack(const Stack &s);
    Stack(Stack &&s);
    Stack &operator=(const Stack &s);
    ~Stack();
};

template<typename T>
void Stack<T>::resize_cap(int a){
        T *arr;
        arr=new T[cap];
        for(int i=0; i<size; i++){
            arr[i]=data[i];
        }
        delete[] data;
        data=nullptr;
        cap=cap+a;
        data=new T[cap];
        for(int i=0; i<size; i++){
            data[i]=arr[i];
        }
        delete[] arr;
        arr=nullptr;
    }
template<typename T>
Stack<T>::Stack(int c){
        cap=c;
        data=new T[cap];
        size=0;
    }
template<typename T>    
bool Stack<T>::isFull(){
        if(size==cap)
        return true;
        else
        return false;
    }
template<typename T>    
bool Stack<T>::isEmpty(){
        if(size==0)
        return true;
        else
        return false;
    }
template<typename T>    
void Stack<T>::push(T a){
        if(isFull()){
        resize_cap(100);
        }
        data[size]=a;
        size++;
            
    }
template<typename T>    
T Stack<T>::pop(){
        if(isEmpty()){
            cout << "stack is empty" <<endl;
            return T();
        }
        else{
            T a= data[size-1];
            size--;
            return a;
        }
    }
template<typename T>    
T Stack<T>::getTop(){
        if(isEmpty()){
        	cout << "stack is empty" << endl;
        	return T();
		}
        else
        return data[size-1];
    }
template<typename T>   
int Stack<T>::topValueIndex(){
    return size-1;
}
template<typename T>    
Stack<T>::Stack(const Stack &s){ //copy constructor(deep copy)
        cap=s.cap;
        size=s.size;
        data=new T[cap];
        for (int i=0; i<size; i++){
        data[i]=s.data[i];
        }
    }
template<typename T>    
Stack<T>::Stack(Stack &&s){ //move contructor
        data=s.data;
        s.data=nullptr;
        size=s.size;
        s.size=0;
        cap=s.cap;
        s.cap=0;
    }
template<typename T>    
Stack<T>& Stack<T>::operator=(const Stack &s){ //assignment operator(deep copy)
        if(this==&s){
            return *this;
        }
        else{
            cap=s.cap;
            size=s.size;
            delete[] data;
            data=new T[cap];
            for (int i=0; i<size; i++){
            data[i]=s.data[i];
            }
        }
        return *this;
    }   
template<typename T>    
Stack<T>::~Stack(){
        cap=0;
        delete[] data;
        data=nullptr;
        size=0;
}

bool checkString(string s){
	bool b=0;
	int len=s.length();
	int l=s.length()/2;
	if(len%2 != 0 || s[l-1]>s[l]){
		return 0;
	}
	char c1=s[0];
	for(int i=0; i<l; i++){
		if(s[i]==c1){
			b=1;
		}
		else{
			return 0;
		}
	}
	char c2=s[l];
	for(int i=l; i<len; i++){
		if(s[l]==c2){
			b=1;
		}
		else{
			return 0;
		}
	}
	return 1;
}
int main(){
	string b;
	b="aaabbb";
    cout << checkString(b);
    
    string c;
	c="bbbaaa";
    cout << checkString(c);
    
    string d;
	d="ababab";
    cout << checkString(d);
    
    string e;
	e="abababa";
    cout << checkString(e);

	}
