#include<iostream>
using namespace std;
#define MAXSIZE 3
class CircularQueue
{
    int front;
    int rear;
    int count;
    string arr[MAXSIZE];
    public:
    CircularQueue()
    {
        front=0;
        rear=0;
        count=0;
    }
    void enQueue(string x)
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
    void deQueue()
    {
        if(count==0)
        {
            cout<<"Underflow of Queue"<<endl;
        }
        else
        {
            front=(front+1)%MAXSIZE;
            count--;
        }
    }
    void display()
    {
        int i=front;
        for(int k=0;k<count;k++)
        {
            cout<<arr[i]<<'\t';
            i=(i+1)%MAXSIZE;
        }
    }
};
int main()
{
    CircularQueue q;
    q.enQueue("Circular");
    q.enQueue("Queue");
    q.enQueue("Implementation");
    cout<<"Circular Queue Details:"<<endl;
    q.display();
    q.deQueue();
    q.enQueue("Modified");
    cout<<"\nModified Circular Queue Details:"<<endl;
    q.display();
    return 0;
}
