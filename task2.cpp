#include <iostream>
#include <string>

using namespace std;

class ND{
	private:
		int dsize;
		int pro;
		int *data;
		int d[100]; //dimensions
	public:
		ND(int n, int arr[]){
			dsize=n;
			pro=1;
			for(int i=0; i<n; i++){
				d[i]=arr[i];
				pro*=arr[i];
			}
			data= new int[pro];
			for(int i=0; i<pro; i++){
				cin >> data[i];
			}
		}
		int calculateindex(int a[]){
			int x=0;
			int r=1;
			int p=0;
			for(int i=0; i<dsize; i++){
				r=1;
				for(int j=i+1; j<dsize; j++){
			    	r*=d[j];
		        }
		        p=r*a[i];
		        x+=p;
			}
			return x;
		}
		~ND(){
			delete[] data;
		}
		void setValue(int a[], int v){
			int x=0;
			int r=1;
			int p=0;
			for(int i=0; i<dsize; i++){
				r=1;
				for(int j=i+1; j<dsize; j++){
			    	r*=d[j];
		        }
		        p=r*a[i];
		        x+=p;
			}
			data[x]=v;
		}
		int getValue(int a[]){
			int x=0;
			int r=1;
			int p=0;
			for(int i=0; i<dsize; i++){
				r=1;
				for(int j=i+1; j<dsize; j++){
			    	r*=d[j];
		        }
		        p=r*a[i];
		        x+=p;
			}
			return data[x];
		}
};

int main(){
	int dim[3]={2,2,3};
	ND a(3, dim);
	int index[3]={1,1,2};
	cout << a.calculateindex(index) << endl;
	a.setValue(index, 2);
	cout<<a.getValue(index);
	return 0;
	
}