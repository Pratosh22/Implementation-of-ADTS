#include <iostream>
#define n 100    //creation of static array
using namespace std;
int array[n], front = -1, rear = -1; 
void enqueue(int x)   //inserts element to the rear
{
    if (rear == n - 1)
    {
        cout << " queue is empty" << endl;
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        array[rear] = x;
    }
}

void dequeue()                      //deletes element from the front
{
    if (front == -1 && rear == -1)
    {
        cout << "queue is empty " << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        cout << array[front] << endl;
        front++;
    }
}
void display()    //display elements in queue
{
    if (front == -1)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << "queue elemeents are: ";
        for (int i = front; i <= rear; i++)
        {
            cout << array[i] << " ";
            cout << endl;
        }
    }
}
void peek()    //prints the top element i.e front
{
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << array[front];
    }
}
int main()
{
    int ch,val;
    cout << "Enter the option to be performed: \n1.Insert element \n2.Delete element\n3.Display stack\n4.showtop\n5.Exit " << endl; // switch statement for menu
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to enqueue" << endl;
            cin >> val;
            enqueue(val);
            break;
        }
        case 2:
        {
            dequeue();
            break;
        }
        case 3:
        {
            display();
            break;
        }
        case 4:
        {
            peek();
            break;
        }
        case 5:
        {
            cout << "Exit " << endl;
            break;
        }
        default:
        {
            cout << "Invalid choice" << endl;
        }
        }
    } while (ch != 5);
    return 0;
}
