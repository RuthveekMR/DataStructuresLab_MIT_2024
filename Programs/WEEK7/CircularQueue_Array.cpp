#include<iostream>
using namespace std;
#define MAXSIZE 3
class CircularQueue
{
    int front;
    int rear;
    int count;
    int arr[MAXSIZE];
    public:
    CircularQueue()
    {
        front=0;
        rear=0;
        count=0;
    }
    void enQueue(int x)
    {
        if(count==MAXSIZE)
        {
            cout<<"Overflow of Queue"<<endl;
        }
        else
        {
            arr[rear]=x;
            rear=(rear+1)%MAXSIZE;
            count++;
        }
    }
    int deQueue()
    {
        if(count==0)
        {
            cout<<"Underflow of Queue"<<endl;
            return 0;
        }
        else
        {
            int z=arr[front];
            front=(front+1)%MAXSIZE;
            count--;
            return z;
        }
    }
    bool isEmpty()
    {
        if(count==0)
        {
            cout<<"Queue is Empty(";
            return true;
        }
        else
        {
            cout<<"Queue is not Empty(";
            return false;
        }
    }
    int Front()
    {
        return arr[front];
    }
    int size()
    {
        return count;
    }
};
int main()
{
    CircularQueue q;
    q.enQueue(50);
    q.enQueue(60);
    q.enQueue(70);
    cout<<"Circular Queue Details:"<<endl;
    int n=q.size();
    cout<<"Size="<<n<<endl;
    cout<<"Front="<<q.Front()<<endl;
    cout<<"Queue Contents:";
    for(int i=0;i<n;i++)
    {
        cout<<q.deQueue()<<'\t';
    }
    cout<<"\nIs Queue Empty or not?\nAnswer:"<<q.isEmpty()<<")"<<endl;
    return 0;
}
