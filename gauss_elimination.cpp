#include <iostream>
#include <string>

using namespace std;

int main()
{
	int dimensions;
	int no_of_equations;
	cout<<"Welcome, we have our equation in the form of --- x   Ax = B   x---"<<endl<<endl<<endl;	
	int p = 0;
	
	while(p==0)	
	{
		cout<<"Enter the no of dimensions of equations"<<endl;	
		cin>>dimensions;
		if(dimensions < 1)
		{
			cout<<"Invalid no of dimensions"<<endl;
		}
		else
		{
			p = 1;
		}
	}	
	dimensions = dimensions+1;
	
	while(p==1)	
	{
		cout<<"Enter the no of equations"<<endl;
		cin>>no_of_equations;	
		if(no_of_equations < 1)
		{
			cout<<"Invalid no of equations"<<endl;
		}
		else
		{
			p = 0;
		}
	}	

	float coefficient_matrix [no_of_equations][dimensions];

	for (int i = 0;i<no_of_equations;i++)
	{
		cout<<"Enter the coefficient of equation "<<i+1<<" :"<<endl<<endl;
		for (int j = 0;j<dimensions;j++)
		{
			cin>>coefficient_matrix[i][j];
		}
		cout<<"Your equation becomes:"<<endl;
		for(int k =0;k<dimensions;k++)
		{
			if(k==dimensions-2)
			{
				cout<<coefficient_matrix[i][k]<<"x"<<k<<" = ";
			}
			else if (k==dimensions-1)
			{
				cout<<coefficient_matrix[i][k];
			}
			else
			{
				cout<<coefficient_matrix[i][k]<<"x"<<k<<"  + ";
			}			
		}
		cout<<endl<<endl;
	}

	/*for (int i = 0;i<no_of_equations;i++ )
	{
		for(int j =0;j<dimensions;j++)
		{
			cout<<coefficient_matrix[i][j]<<" ";
		}
		cout<<endl;
	}*/	

	float initial_max;
	int index;

	//MAIN------------------

	for(int i = 0;i<no_of_equations;i++)		
	{
		initial_max = -111111;		
		index = 0;

		//Getting the maximum element for ivot position		
		for(int counter = i;counter<no_of_equations;counter++)
		{
			if(coefficient_matrix[counter][i] > initial_max)
			{
				initial_max = coefficient_matrix[counter][i];
				index = counter;
			}
		}

		//Interchanging with the first row		
		for(int lc = 0;lc<dimensions;lc++)
		{
			float temp = coefficient_matrix[i][lc];
			coefficient_matrix[i][lc] = coefficient_matrix[index][lc];
			coefficient_matrix[index][lc] = temp;
		}		

/*		for (int m = 0;m<no_of_equations;m++ )
		{
			for(int n =0;n<dimensions;n++)
			{
				cout<<coefficient_matrix[m][n]<<" ";
			}
			cout<<endl;
		}
*/
		//Making the elements below the pivot equal to zero
		for(int cc = i+1;cc<no_of_equations;cc++)
		{
			float ratio = coefficient_matrix[cc][i]/coefficient_matrix[i][i];			
			for(int temp = 0;temp<dimensions;temp++)
			{
				coefficient_matrix[cc][temp] = coefficient_matrix[cc][temp] - ratio*coefficient_matrix[i][temp];
			}
		}
		cout<<endl<<endl;			
	}

	//Printing the upper Triangular matrix	

	for (int m = 0;m<no_of_equations;m++)
	{
		for(int n =0;n<dimensions;n++)
		{
			cout<<coefficient_matrix[m][n]<<" ";
		}
		cout<<endl;
	}		

	float solution[dimensions-1];

	// Initialising the solution vector with zero values
	for(int ll = 0;ll<dimensions-1;ll++)
	{
		solution[ll] = 0;
	}		

	//Calculating last unknown value in system of equations
	solution[dimensions-2] = coefficient_matrix[no_of_equations-1][dimensions-1]/coefficient_matrix[no_of_equations-1][dimensions-2];
	
	for(int zz = 0;zz<dimensions-1;zz++)
	{
		cout<<solution[zz]<<" ";
	}

	cout<<endl<<endl;

	for(int jj = no_of_equations-2;jj>=0;jj--)
	{		
		float current_sum = 0;				
		for(int aa = 0;aa<dimensions-1;aa++)
		{						
			current_sum = current_sum + coefficient_matrix[jj][aa]*solution[aa];						
		}
		solution[jj] = (coefficient_matrix[jj][dimensions-1] - current_sum)/coefficient_matrix[jj][jj];		

/*		for(int zz = 0;zz<dimensions-1;zz++)
		{
			cout<<solution[zz]<<" ";
		}				
*/		cout<<endl<<endl;
	}

	cout<<"The solution is given by:"<<endl;
	for(int p = 0;p<dimensions-1;p++)		
	{
		cout<<"x"<<p+1<<" : "<<solution[p]<<endl;
	}
}


