#include "stdafx.h"
#include <fstream>
#include <iostream> 
#define   arr_m 100  //(Nend-Nskip); 
 
 using namespace std; 
 
 
 int main(){ 
 	double x0 = 0.5; 
 	double x; 
 	int Nskip = 100; //Number of iterations to skip 
 	int Nend  = 200; //Number of total iterations 
	double rend;
	double rstep;
   	double arr_x[arr_m];

	ofstream out("output.dat");
	cout<<"rend: "; cin>>rend;
	cout<<"\t rstep:"; cin>>rstep;
	

 	for(double r=0; r <= rend; r += rstep)
	{ 
 	   x=x0; 
 	   for(int i=1; i <= Nskip; i++) 
 		   x = r*x*(1-x); 
 	   for(int i=Nskip+1; i <= Nend; i++)
	   { 
 	   		   x = r*x*(1-x); 
			   arr_x[i-(Nskip+1)]=x;
 	   		   //cout << r << "\t" << x << endl; 
		} 
	   for(int j=0; j<arr_m; j++)
	   {
		   cout<<"r: "<<r<<"arr_x["<<j+1<<"]= "<<arr_x[j]<<endl;
		   out<<"r: "<<r<<"arr_x["<<j+1<<"]= "<<arr_x[j]<<endl;
	   }
 	} 
 
 
 
	out.close();
	system("pause");
 	return 0; 
 } 

