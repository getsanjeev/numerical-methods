#include <iostream>
using namespace std;

void gauss_siedel(){	
	int n;
	cout<<"Welcome, we have our equation in the form of --- x   Ax = B   x---"<<endl<<endl<<endl;	
	cout<<"enter the dimension of matrix  A"<<endl;
	cin>>n;
	float arrayA[n][n];
	float arrayB[n];
	float arrayX[n];

	cout<<"enter the A matrix"<<endl;
	for(int i = 0;i<n;i++){
		for (int j =0;j<n;j++){
			cin>>arrayA[i][j];
		}		
	}

	cout<<"enter the B matrix"<<endl;
	for (int j =0;j<n;j++){
		cin>>arrayB[j];
	}

	cout<<"initialising array X to be 0"<<endl;
	for (int j =0;j<n;j++){
		arrayX[j] = 0;
	}

	cout<<"your input matrix is:"<<endl;
	for(int i = 0;i<n;i++){
		for (int j =0;j<n;j++){
			cout<<arrayA[i][j]<<"     ";
		}
		cout<<arrayB[i]<<endl;
	}

	cout<<"SOLVING....."<<endl;
	int iterations = 0;
	float sum;

	while(iterations < 5){
		for(int i = 0;i<n;i++){
			sum = 0;
			for(int k = 0;k<n;k++){				
				if(k!=i){
					cout<<"value of a "<<arrayA[i][k]<<" "<<arrayX[k]<<endl;
					sum = sum + arrayX[k]*arrayA[i][k];
				}
			}
			cout<<"value of sum is : "<<sum<<endl;		
			arrayX[i] = (arrayB[i] - sum)/arrayA[i][i];
			for (int j =0;j<n;j++){
			cout<<arrayX[j]<<" ";
		}
		}		
		//cout<<iterations<<endl;
	iterations = iterations  +1;
}

for (int j =0;j<n;j++){
	cout<<arrayX[j]<<" ";
}



}

int main(){
	gauss_siedel();


}

