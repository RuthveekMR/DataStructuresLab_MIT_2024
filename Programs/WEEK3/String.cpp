#include<iostream>
using namespace std;
void strlength(char arr[])
{
        int i=0;
        while(arr[i]!='\0')
                i++;
        cout<<"Length of String="<<i<<endl;
}
void strconcat(char arr1[],char arr2[])
{
        int i=0,j=0;
        while(arr1[i]!='\0')
                i++;
        while(arr2[j]!='\0')
        {
                arr1[i]=arr2[j];
                j++,i++;
        }
        arr1[i]='\0';
        cout<<"After concatenation,the string formed is:\n";
        cout<<arr1<<endl;
}
void strcomp(char arr1[],char arr2[])
{
        int i=0;
        while(arr1[i]!='\0'||arr2[i]!='\0')
        {
                if(arr1[i]==arr2[i])
                {
                        i++;
                }
                else if(arr1[i]>arr2[i])
                {
                        cout<<arr1<<" is greater than "<<arr2<<endl;
                        break;
                }
                else if(arr1[i]<arr2[i])
                {
                        cout<<arr1<<" is lesser than "<<arr2<<endl;
                        break;
                }
        }
        if(arr1[i]=='\0' || arr2[i]=='\0')
                cout<<"Both "<<arr1<<" and "<<arr2<<" are equal"<<endl;
}
void strinsert(char arr1[],char arr2[],int index)
{
        int i=index,j=0;
        char arr3[50];
        while(arr1[i]!='\0')
        {
                arr3[j]=arr1[i];
                i++,j++;
        }
        arr3[j]='\0';
        i=index,j=0;
        while(arr2[j]!='\0')
        {
                arr1[i]=arr2[j];
                i++;j++;
        }
        j=0;
        while(arr3[j]!='\0')
        {
                arr1[i]=arr3[j];
                i++;j++;
        }
        arr1[i]='\0';
        cout<<"After insertion, the string formed is "<<arr1<<endl;
}
void strdelete(char arr1[],char arr2[])
{
        int length=0,i=0,j=0,k,l;
        while(arr2[length]!='\0')
        {
                length++;
        }
        while(arr1[i]!='\0')
        {
                while(arr1[i]==arr2[j])
                {
                        if(j==length-1)
                        {
                                k=i-length+1;
                                l=k;
                                while(arr1[i]!='\0')
                                {
                                        arr1[l++]=arr1[++i];
                                }
                                i=k-2;
                                arr1[l]='\0';
                        }
                        i++;
                        j++;
                }
                i++;
                j=0;
        }
        cout<<"The String after deletion="<<arr1<<endl;
}
int main()
{
        int choice,pos;
        cout<<"Enter 1 to find the length of the string, 2 to concatenate two strings, 3 to compare two strings, 4 to insert a substring and 5 to delete a substring:\n";
        cin>>choice;
        char str1[50],str2[50];
        if(choice==1)
        {
                cout<<"Enter a string:"<<endl;
                cin>>str1;
                strlength(str1);
        }
        else if(choice==2)
        {
                cout<<"Enter two strings for string concatenation:"<<endl;
                cin>>str1>>str2;
                strconcat(str1,str2);
        }
        else if(choice==3)
         {
                cout<<"Enter two strings for their comparision:"<<endl;
                cin>>str1>>str2;
                strcomp(str1,str2);
        }
        else if(choice==4)
        {
                cout<<"Enter your main string and substring respectively:"<<endl;
                cin>>str1>>str2;
                cout<<"Enter the position you want to insert your substring:"<<endl;
                cin>>pos;
                strinsert(str1,str2,pos);
        }
        else if(choice==5)
        {
                cout<<"Enter your main string and substring, respectively:"<<endl;
                cin>>str1;
                cin>>str2;
                strdelete(str1,str2);
        }
        else
            cout<<"Invalid Input";
        return 0;
}

