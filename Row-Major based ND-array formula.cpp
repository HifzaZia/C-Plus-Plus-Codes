#include <iostream>
#include <string>

using namespace std;

void printND(int n){
	if(n<=0){
		cout << "dimensions are not correct" << endl;
		return; 
	}
	for(int i=1; i<=n; i++){
		cout << "+I" << i;
		for(int j=i+1; j<=n; j++){
			cout << "U" << j;
		}
	}
	cout << endl;
	return;
}

int main(){
	printND(3);
	printND(4);
	printND(0);
	return 0;
}
