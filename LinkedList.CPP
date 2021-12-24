#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
void print(node *head)     //prints the list
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
}
node *inputtail()    //inserts at tail
{
    int data;
    cin >> data;

    node *head = NULL;
    node *tail = NULL;

    while (data != -1)
    {
        node *n = new node(data);

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        cin >> data;
    }
    return head;
}

node *inputhead()   //inserts at head
{
    int data;
    cin >> data;

    node *head = NULL;
    node *tail = NULL;

    while (data != -1)       //-1 is entered for termination of input
    {
        node *n = new node(data);

        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
        cin >> data;
    }
    return head;
}

int length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
node *printith(node *head, int i)  //prints the Ith element
{
    int n = length(head);

    if (i < 0 && i > n)      //checks if the index is out of bounds(i=index)
    {
        cout << "-1" << endl;
    }
    for (int j = 0; j <= i; j++)   //traverse the list
    {
        head = head->next;
    }

    return head;
}
node *insertith(node *head, int i, int data)
{
    if (i < 0)
    {
        return head;
    }
    if (i == 0)
    { 
        node *n = new node(data);     //when index is 0 element is directly inserted into head
        n->next = head;
        head = n;
        return head;
    }
    node *temp = head;
    int count = 1;
    while (count <= i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if (head)
    {
        node *n = new node(data);
        n->next = head->next;
        head->next = n;
        return head;
    }
    return head;
}
node *deleteith(node *head, int i)
{
    if (i < 0)
    {
        return head;
    }
    if (i == 0 && head)
    {
        return head->next;
    }

    node *temp = head;
    int count = 1;
    while (count <= i - 1 && temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    if (temp)
    {
        temp->next = temp->next->next;
        return head;
    }
    return head;
}
int main()
{
    int x;
    cout << "Enter the option to be performed: \n1.Print the List \n2.Insert at Head \n3.Insert at tail \n4.Length of the list \n5.Print ith Element \n6.Insert at Ith position \n7. Delete At Ith position " << endl;
    cin >> x;

    if (x == 1)
    {
        cout << "Enter the list to be printed: " << endl;
        node *head = inputtail();
        print(head);
    }
    else if (x == 2)
    {
        cout << "Enter the list: " << endl;
        node *head = inputhead();
        print(head);
    }
    else if (x == 3)
    {
        cout << "Enter the list: " << endl;
        node *head = inputtail();
        print(head);
    }
    else if (x == 4)
    {
        node *head = inputtail();
        cout << "The lenghth of the list is: " << length(head);
    }
    else if (x == 5)
    {
        int k;
        cout << "Enter the list: " << endl;
        node *head = inputtail();
        print(head);
        cout << "Enter the position to be printed: " << endl;
        cin >> k;
        cout << "The element at Ith position is: " << printith(head, k) << endl;
    }
    else if (x == 6)
    {
        int i, data;
        cout << "Enter the list: " << endl;
        node *head = inputtail();
        cout << "List: "<<endl;
        print(head);
        cout<<endl;
        cout << "Enter the data to be inserted: "<<endl;
        cin >> data;
        cout << "Enter the position to be inserted: "<<endl;
        cin >> i;
        insertith(head, i, data);
        cout << "The list after insertion: "<<endl;
        print(head);
    }
    else if (x == 7)
    {
        int i;
        cout << "Enter the list: " << endl;
        node *head = inputtail();
        cout << "List: "<<endl;
        print(head);
        cout << "Enter the position to be Deleted: "<<endl;
        cin >> i;
        deleteith(head, i);
        cout << "The list after Deletion: "<<endl;
        print(head);
    }
    else
    {
        cout << "Invalid operation " << endl;
    }
}
