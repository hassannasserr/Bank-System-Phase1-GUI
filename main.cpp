#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void display();
const int Max_size=1000;
class Transactions{
    int last_transactions;
    string transactions[Max_size];
public:
    Transactions(){
        last_transactions=-1;
    }
    void add_Transaction(string e){
        if(last_transactions<Max_size-1){
            last_transactions++;
            transactions[last_transactions]=e;
        }
        else{
            cout<<"you can not add transactions";
        }
    }
    bool is_Empty(){
        if(last_transactions==-1){
            return true;
        }
        else{
            return false;
        }
    }
    string get_LastTransaction(){
        if(is_Empty()){
            cout<<"there is no transactions";
        }
        else{
            return transactions[last_transactions];
        }
    }
    void Delete_Transaction(){
        if(is_Empty()){
            cout<<"there is no transactions to delete ";
        }
        else {
            last_transactions--;
        }
    }
};
class  ManagingCustomers{
    int front;
    int rear;
    string q[Max_size];
public:
    ManagingCustomers(){
        front=-1;
        rear=-1;
    }

    void addCustomer(string e){
        if((rear+1)%Max_size==front){
            cout<<"Queue is full";
        }
        else if(front==-1 && rear==-1){
            front=0;
            rear=0;
            q[rear]=e;
        }
        else{
            rear=(rear+1)%Max_size;
            q[rear]=e;
        }
    }
    bool is_Empty(){
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }
    string get_front(){
        if(is_Empty()){
            cout<<"Queue is empty";
        }
        else{
            return q[front];
        }
    }
    void AcceptCustomer(){
        if(is_Empty()){
            cout<<"Queue is empty";
        }
        else if(front==rear){
            front=-1;
            rear=-1;
        }
        else{
            front=(front+1)%Max_size;
        }
    }
    void Showlist(){
        if(is_Empty()){
            cout<<"Queue is empty";
        }
        else{
            int j=1;
            for(int i=front;i!=rear;i=(i+1)%Max_size){

                cout<<j<<"-"<<q[i]<<endl;
                j++;
            }
            cout<<q[rear];
        }
    }

};

Transactions st;
ManagingCustomers queue1;
void showlistqueue()
{
    cout<<"-----------------------------------------------------"<<endl;
    queue1.Showlist();
    cout<<endl<<"-----------------------------------------------------"<<endl;
}

void Employee()
{
    cout<<"Please enter your Job number"<<endl;
    int jnumber;
    cin>>jnumber;
    if(jnumber==11576||jnumber==17105||jnumber==98755)
    {
        list:
        {
            cout << "this is the pending list" << endl;
            showlistqueue();
            cout << "if you want to accept the first user click 1" << endl;
            int choice;
            cin >> choice;

            if (choice == 1) {
                queue1.AcceptCustomer();
               if(queue1.is_Empty()){
                     cout<<"the list is empty"<<endl;
                     cout<<"if you want to back to the main menu choose 1"<<endl;
                     cout<<"if you want to exit choose 2"<<endl;
                     int choice ;
                     cin>>choice;

                     if(choice==1)
                     {
                          display();
                     }
                     else if(choice==2)
                     {
                          return;
                     }
                     else
                     {
                          cout<<"invalid number please try again!"<<endl;
                          display();
                     }
                }
                else{
                        cout<<"User has accepted"<<endl;
                     goto list;
               }
            } else {
                cout << "invalid number please try again!" << endl;
                Employee();
            }
        }

    }
    else
    {
        cout<<"invalid  number please try again!"<<endl;
        Employee();
    }
}
void display()
{
    st.add_Transaction("withdrawl 100");
    st.add_Transaction("deposite 1000");
    st.add_Transaction("withdrawl 300");
    cout<<"if you a new user click 1"<<endl;
    cout<<"if you an old user click 2 "<<endl;
    cout<<"if you an employee click 3"<<endl;
    int x;
    cin >> x;
    cin.ignore();
    if(x==1){
        cout << "Please Enter your name:";
        string name;
        getline(cin, name);
        cout << "Please Enter your SSN:";
        string ssn;
        cin >> ssn;
        string newuser = "Full name: " + name + "  " + "SSN: " + ssn;
        queue1.addCustomer(newuser);
        cout<<"if you want to back to the main menu choose 1"<<endl;
        cout<<"if you want to exit choose 2"<<endl;
        int choice ;
        cin>>choice;

        if(choice==1)
        {
            display();
        }
        else if(choice==2)
        {
            return;
        }
        else
        {
            cout<<"invalid number please try again!"<<endl;
            display();
        }
    }

    else if(x==2) {
        bool keeprunning = true;
        while (keeprunning) {
            cout << "if you want to deposite click 1" << endl;
            cout << "if you want to withdrawl click 2" << endl;
            cout << "if you want to know your last process click 3" << endl;
            cout << "if you want to know the process before the last process click 4" << endl;
            cout<<"if you want to exit click 5"<<endl;
            int y;
            cin >> y;
            if (y == 1) {
                cout << "Enter the amount" << endl;
                string s;
                cin >> s;
                st.add_Transaction("deposite " + s);
            } else if (y == 2) {
                cout << "Enter the amount" << endl;
                string s;
                cin >> s;
                st.add_Transaction("withdrawl " + s);
            } else if (y == 3) {
                cout << st.get_LastTransaction();
            } else if (y == 4) {
                st.Delete_Transaction();
                cout << st.get_LastTransaction();
            }
            else if(y==5){
                display();
            }
            cout<<endl;
            cout<<endl;
        }
    }
    else if(x==3){
        Employee();
    }
}

int main() {
    display();
    return 0;
}