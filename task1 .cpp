//#ifndef POLYNIMIAL_H
//#def POLYNOMIAL_H

#include <iostream>
#include <string>

using namespace std;

class Polynomial{
	
	private:
		
		int *cof; //co-efficient
		int size;
	
	public:
		
		Polynomial() // constructor
		{
			cof=new int[1];
			size=0;
		}
		void addTerm(int c, int s) 
		{
			*(cof+s)=c;
			size=s;
		}
		int getDegree(){
			return size;
		}
		int getCoefficient(int p){
			int a;
			if(p<=size && p>=0){
				a=*(cof+p);
			}
			else{
				cout << "power is invalid";
				a=0;
			}
			return a;
		}
		friend ostream& operator<<(ostream &out, Polynomial &p) 
		{
			for(int i=0; i<=p.size; i++){
        		out << "+" << p.getCoefficient(i) << "x^" << i;
			}
			out<<endl;
            return out;
        }
        void display(){
        	for(int i=0; i<=size; i++){
        		cout << "+" << *(cof+i) << "x^" << i ;
			}
			cout<<endl;
		}
        void clear(){
        	for(int i=0; i<=size; i++){
        		*(cof+i)=0;
			}
		}
		Polynomial derivative()
		{
			Polynomial a;
			int x=-1;
			for(int i=0; i<=size; i++){
				a.addTerm((*(cof+i))*i,x);
				x++;
			}
			return a;
		}
		void setCoefficient(int nc, int e)
		{
			addTerm(nc, e);
		}
		void addToCoefficient(int c, int p){
			int a=*(cof+p);
			*(cof+p)=a+c;
		}
       ~Polynomial()
        {
       	    delete[] cof;
	    }
	   Polynomial(const Polynomial &p) //copy constructor
	    {
	   	    size=p.size;
	   	    cof=new int[size+1];
	   	    for(int i=0; i<=size; i++){
	   	    	cof[i]=p.cof[i];
			}
	    }
//	    Polynomial antiDerivative()
//	    {
//	    	Polynomial p;
//	    	for(int i=0; i<=size+1; i++){
//	    		p.addTerm((*(cof+i))/i,i+1);
//			}
//			p.size=size+1;
//			return p;
//		}
};
 int main()
 {
	Polynomial p;
    int n;
	cout << "enter the coefficient and its power"<< endl;
	int a;
	cin >> a >> n;
	p.addTerm(a,n);

	int m;
	cout << "enter the coefficient and its power"<< endl;
	int l;
	cin >> m >> l;
	p.addTerm(m,l);
	
	int x;
	cout << "enter the coefficient and its power"<< endl;
	int y;
	cin >> x >> y;
	p.addTerm(x,y);
	
	int u;
	cout << "enter the coefficient and its power"<< endl;
	int v;
	cin >> u >> v;
	p.addTerm(u,v);
	
	cout << p;

    cout << "after get coefficient "<< endl;
    cout << p.getCoefficient(1);
    
    cout << endl <<"highest degree" << endl;
    cout << p.getDegree() << endl;
    
    p.setCoefficient(5,4);
    cout<< "after set coefficient" << endl;
    p.display();
    
//    p.antiDerivative();
//    cout << p;

    cout << "after add to co-efficient" << endl;
    p.addToCoefficient(1,4);
    p.display();
    
    cout << "after derivative"<< endl;  
    p.derivative().display();
    
    p.clear();
    cout << "After clear"<<endl;
    p.display();
 }

//#endif