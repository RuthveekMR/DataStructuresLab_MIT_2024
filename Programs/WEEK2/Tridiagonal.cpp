#include<iostream>
using namespace std;
int main()
{
        int n;
        cout<<"Enter the order of your tri-diagonal matrix:"<<endl;
        cin>>n;
        int a[n][n],b[n];
        cout<<"Enter "<<3*n-2<<" number of elements:"<<endl;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        if((i==j)||(i==j+1)||(i==j-1))
                        {
                                cin>>a[i][j];
                        }
                        else
                                a[i][j]=0;
                }
        }
        cout<<"The entered 2-D matrix:"<<endl;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cout<<a[i][j]<<"\t";
                }
                cout<<"\n";
        }
        cout<<"The mapped 1-D list:"<<endl;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        if((i==j)||(i==j+1)||(i==j-1))
                        {
                                b[2*i+j]=a[i][j];
                        }
                }
        }
       for(int i=0;i<3*n-2;i++)
                cout<<b[i]<<"\t";
        cout<<"\nEnter the row & column for retrieval, respectively:"<<endl;
        int i,j,index;
        cin>>i>>j;
        if((i==j)||(i==j+1)||(i==j-1))
        {
                index=2*i+j;
                cout<<"Located at index "<<index<<" in the 1D array.";
        }
        else
                cout<<"Invalid Input";
return 0;
}
