#include<iostream>
#include<vector>
using namespace std;
#define endl "\n"
#define ll long long
#define ld long double

int main(){
	
	cout << "Time the service has been used for (hrs) : ";
	ld observe; cin >> observe;

	cout << "Total number of tests made : ";
	ll tests; cin >> tests;
	
	cout << "Number of failures: ";
	ll n; cin >> n;
	if(n <= 1){
		cout << "INVALID INPUT\n";
		exit(0);
	}
	
	vector<ld> vec(n, 0), recover(n, 0);
	ld interval_sum = 0;
	ld fix_sum = 0;
	cout << "Enter the instances when failures occured along with the time to repair them\n";
	
	for(int i = 0; i < n; i++){
		cout << "Enter the time of occurance of error "<<i+1<<" : "; cin >> vec[i];
		cout << "Recovery time of error "<<i+1<<" : "; cin >> recover[i];
		
		if(i > 0){
			interval_sum += vec[i] - vec[i-1];
		}
		
		fix_sum += recover[i];
	}
	
	ld MTFF = (interval_sum)/((ld)(n-1));
	ld MTTR = (fix_sum)/((ld)n);
	ld MTBR = MTFF + MTTR;
	
	//in T time, n errors occured
	//in a UNIT TIME; n/T * 1
	ld ROCOF = ((ld)n)/observe;
	
	ld POFOD = ((ld)n)/((ld)tests);
	
	// observe => observe - time_to_fix_errors
	//100 => (observe - time_to_fix_errors)/(observe) * 100
	ld AVAIL = (((ld)(observe - fix_sum))/((ld)observe)) * 100;
	
	cout << "\nSoftware reliability metrics calculated\n\n";
	cout << "  Mean Time to Failure (MTTF) : " << MTFF << endl;
	cout << "  Mean Time to Repair (MTTR) : " << MTTR << endl;
	cout << "  Mean Time Between Failure (MTBR) : " << MTBR << endl;
	cout << "  Rate of occurrence of failure (ROCOF) : " << ROCOF << endl;
	cout << "  Probability of Failure on Demand (POFOD) : " << POFOD << endl;
	cout << "  Availability (AVAIL) : " << AVAIL << endl;
	
	return 0;
}





