#include <iostream>
using namespace std;

#define size 5

class pizza
{
    int porder[size];
    int front, rear;

public:
    pizza()
    {
        front = rear = -1;
    }
    int qfull()
    {
        if (front == (rear + 1) % size)
            return 1;
        else
            return 0;
    }
    int qempty()
    {
        if (front == -1)
            return 1;
        else
            return 0;
    }
    void accept_order(int item)
    {
        if (qfull())
            cout << "\nVery Sorry !!!! No more orders....\n";
        else
        {
            if (front == -1)
            {
                front = rear = 0;
            }
            else
            {
                rear = (rear + 1) % size;
            }
            porder[rear] = item;
        }
    }
    void make_payment()
    {
        int item;
        char ans;
        int ct=1;
        if (qempty())
            cout << "\nSorry !!! order is not there...\n";
        else
        {
            int temp = front,n;

            cout << "\nPending Order as follows..\n";
            while (temp != rear){
                ct++;
                temp = (temp + 1) % size;
            }
            cout<<"There are "<<ct<< " orders in pizza parlor."<<endl;
            cout << "\nHow many Pizza ?";
            cin >> n;
          
            cout << "\nDeliverd orders as follows...\n";
            
                for (int i = 0; i < n; i++)
                {
                    item = porder[front];
                    if (front == rear)
                    {
                        front = rear = -1;
                    }
                    else
                    {
                        front = (front + 1) % size;
                    }
                    cout << "\t" << item;
                    
                }
            
            cout << "\nTotal amount to pay : " << n * 100;
            cout << "\nThank you visit Again....\n";
        }
    }
    void order_in_queue()
    {
        int temp;
        if (qempty())
        {
            cout << "\nSorry !! There is no pending order...\n";
        }
        else
        {
            temp = front;
            cout << "\nPending Order as follows..\n";
            while (temp != rear){
                cout << "\t" << porder[temp];
                temp = (temp + 1) % size;
            }
            cout << "\t" << porder[temp];
        }
    }
};

int main(){
    pizza p1;
    int ch, k;
    do{
        cout << "\n\t***** Welcome To Pizza Parlor *******\n";
        cout << "\n1.Accept order\n2.Make_payment\n3.Pending Orders\n4. Exit\nEnter u r choice:";
        cin >> ch;
        switch (ch){
        case 1:
            cout << "\nWhich Pizza would do u like to have today\n";
            cout << "\n1.Veg Soya Pizza\n2.Veg butter Pizza\n3.Egg_Pizza";
            cout << "\nPlease enter your order: ";
            cin >> k;
            p1.accept_order(k);
            break;
        case 2:
            
            p1.make_payment();
            break;
        case 3:
            cout << "\n Following orders are in queue to deliver....as follows..\n";
            p1.order_in_queue();
            break;
        }
    } while (ch != 4);

    return 0;
}
