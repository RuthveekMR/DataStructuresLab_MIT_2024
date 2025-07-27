#include<iostream>
using namespace std;
#define MAXSIZE 3
class Queue
{
    int front;
    int rear;
    int arr[MAXSIZE];
    public:
    Queue()
    {
        front=0;
        rear=0;
    }
    void enQueue(int x)
    {
        if(rear==MAXSIZE)
        {
            cout<<"Overflow of Queue"<<endl;
            return;
        }
        else
        {
            arr[rear++]=x;
        }
    }
    int deQueue()
    {
        if(front==rear)
        {
            cout<<"Underflow of Queue"<<endl;
            return 0;
        }
        else
        {
            return arr[front++];
        }
    }
    bool isEmpty()
    {
        if(front==rear)
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
        return (rear-front);
    }
};
int main()
{
    Queue q;
    q.enQueue(50);
    q.enQueue(60);
    int n=q.size();
    cout<<"Size="<<n<<endl;
    cout<<"Front="<<q.Front()<<endl;
    cout<<"Queue Contents:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<q.deQueue()<<'\t';
    }
    cout<<"\nIs Queue Empty or not?\nAnswer:-"<<q.isEmpty()<<")"<<endl;
    return 0;
}
