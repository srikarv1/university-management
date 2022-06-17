/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
//Equations used: -
//E = Ab*(kLOC^Bb)
//D = Cb*(E^Db)
//P = E/D
// E is effort in person-months
// D is development time in months
// kLOC is estimated number of lines of code
//P- Total number of persons required to accomplish the project

#include<iostream>
#include<stdio.h>
#include<string>
#include<math.h>
using namespace std;
void CalCOCOMObas(float model[][4],int category, int kLOC){
	float E,D,P;
	E = model[category][0]*pow(kLOC,model[category][1]);
	D = model[category][2]*pow(E,model[category][3]);
	P = E/D;
	cout<<"Effort = "<<E<<" person-month\n"; 
    cout<<"Development Time = "<<D<<" months"; 
    printf("\nPerson estimation =  %0.0f persons approximately",P);
}
int main(){
	//In the table shown below the rows represent the catrgory i.e. Organic,Semi-Detached,Embedded
	// and the rows represent the constant values i.e. Ab , Bb , Cb , Db
	float model[3][4] = {{2.4,1.05,2.5,0.38},
						 {3.0,1.12,2.5,0.35},
						 {3.6,1.20,2.5,0.32}};
	// A string to store the category
	//Organic,Semi-Detached,Embedded
	string a;
	a = "semi-detached";
	if(a.compare("organic")==0){
		CalCOCOMObas(model,0,5);
	}else if(a.compare("semi-detached")==0){
		CalCOCOMObas(model,1,5);
	}else if(a.compare("embedded")==0){
		CalCOCOMObas(model,2,5);
	}
	return 0;
}

