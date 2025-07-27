#include<iostream>
using namespace std;
int main()
{
        int n;
        cout<<"Enter the order of your lower triangular matrix:"<<endl;
        cin>>n;
        int a[n][n],b[n];
        cout<<"Enter "<<(n*(n+1))/2<<" number of elements:"<<endl;
        for(int i=0;i<n;i++)
        {
                for(int j=0;j<n;j++)
                {
                        if(i<j)
                        {
                                a[i][j]=0;
                        }
                        else
                                cin>>a[i][j];
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
                        if(i>=j)
                        {
                                b[((i*(i+1))/2)+j]=a[i][j];
                        }
                }
        }
        for(int i=0;i<(n*(n+1))/2;i++)
                cout<<b[i]<<"\t";
        cout<<"\nEnter the row & column for retrieval, respectively:"<<endl;
        int i,j,index;
        cin>>i>>j;
        if(i>=j)
        {
                index=((i*(i+1))/2)+j;
                cout<<"Located at index "<<index<<" in the 1D array.";
        }
        else
                cout<<"Invalid Input";
return 0;
}
