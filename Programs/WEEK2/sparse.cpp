#include<iostream>
using namespace std;
struct sparse
{
        int row,col,val;
};
int main()
{
        int m,n;
        cout<<"Enter the no of rows and columns of your matrix, respectively:"<<endl;
        cin>>m>>n;
        int A[m][n],count1=0,C[m][n];
        cout<<"Enter the elements of your 2D sparse matrix:"<<endl;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cin>>A[i][j];
                        if(A[i][j]!=0)
                                count1++;
                }
        }
        struct sparse s[count1+1];
        s[0].row=m,s[0].col=n,s[0].val=count1;
        int k=1;
        while(k<=count1)
        {
                for(int i=0;i<m;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                if(A[i][j]!=0)
                                {
                                        s[k].row=i;
                                        s[k].col=j;
                                        s[k].val=A[i][j];
                                        k++;
                                }
                        }
                }
        }
         cout<<"The Sparse Matrix reconstructed as 1D array of triplets:"<<endl;
        for(k=0;k<count1+1;k++)
        {
                cout<<s[k].row<<"\t"<<s[k].col<<"\t"<<s[k].val<<"\n";
        }
        k=1;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        if(k<=count1)
                        {
                                if((s[k].row==i)&&(s[k].col==j))
                                {
                                        C[i][j]=s[k].val;
                                        k++;
                                }
                                else
                                        C[i][j]=0;
                        }
                        else
                                C[i][j]=0;
                }
        }
        cout<<"The newly constructed sparse matrix is:"<<endl;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        cout<<C[i][j]<<"\t";
                }
                cout<<"\n";
        }

        return 0;
}

