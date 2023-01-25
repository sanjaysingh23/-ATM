#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

class atm{
private :                              
    //  -------------------------------------member variables ----------                                                                  
    long int acc_no;                                                                                 
    int pin;
    string name;
    double balance;
    string mob_no;
public :
    //  ------------------------------------ member functions -------------                                                              
    void set_data(long int acc_no_a, int pin_a, string name_a, double balance_a, string mob_no_a){
        acc_no = acc_no_a;      // assigning the formal argumenns to private member variables
        pin = pin_a;
        name = name_a;
        balance = balance_a;
        mob_no = mob_no_a;
    }

    long int get_acc_no(){
        return acc_no;
    }
    int get_pin(){
        return pin;
    }
    string get_name(){
        return name;
    }
    double get_balance(){
        return balance;
    }
    string get_mob_no(){
        return mob_no;
    }

    void set_mobile(string mob_pri, string mob_new){
        if(mob_pri == mob_new){
            mob_no = mob_new;
            cout<<"Succesfully updated mobile number";
            _getch();
        }
        else{
            cout<<"Incorrect old mobile number";
            _getch();
        }
    }

    void withdraw(int amount_a){
        if(amount_a > 0 && amount_a < balance){
            balance = balance - amount_a;
            cout<<"Collect your balance";
            cout<<"Your remain balance is :- "<<balance;
            _getch();
        }
        else{
            cout<<"Invalid input or Insufficient balance";
            _getch();
        }
    }
};
int main(){
    int choice = 0, enter_pin;
    long int enter_acc_no;

    system("cls");                  // ----  system function use to clear the screan

    atm user1;                      // ----  creat object
    user1.set_data(1234567, 1111, "sanjay", 954600.25, "7906225445");      //  ----  set default data

    do{
        system("cls");
        

        cout<<"Welcome to atm"<<endl;
        cout<<"Enter your acount number  ";
        cin>>enter_acc_no;

        cout<<"Enter PIN ";
        cin>>enter_pin;
        if((enter_acc_no == user1.get_acc_no()) && (enter_pin == user1.get_pin())){
            do{
                int amount = 0;
                string oldMobileNo,newMobileNo;

                system("cls");

                cout<<"****** Welcome To ATM ******"<<endl;
                cout<<"Select option"<<endl;
                cout<<"1. Check Balance"<<endl;
                cout<<"2. Cash withdraw"<<endl;
                cout<<"3. Show user detail"<<endl;
                cout<<"4. Update Mobile Number"<<endl;
                cout<<"5. Exit"<<endl;
                cin>>choice;

                switch (choice)
                {
                case 1:
                    cout<<"Your bank balance is :- "<<user1.get_balance();
                    _getch();
                    break;
                case 2:
                    cout<<"Enter your amount ";
                    cin>>amount;
                    user1.withdraw(amount);
                    break;
                case 3:;
                    cout<<"User details"<<endl;
                    cout<<"User name - "<<user1.get_name()<<endl;
                    cout<<"User acount number - "<<user1.get_acc_no()<<endl;
                    cout<<"Your balance is - "<<user1.get_balance()<<endl;
                    cout<<"User mobile number - "<<user1.get_mob_no()<<endl;
                    _getch();
                case 4:
                    cout<<endl<<"Enter your old mobile number ";
                    cin>>oldMobileNo;
                    cout<<endl<<"Enter your new mobile number ";
                    cin>>newMobileNo;

                    user1.set_mobile(oldMobileNo,newMobileNo);
                    break;
                case 5:
                    exit(0);            
                default:
                    cout<<"Enter valid data ";
                   
                }
            }
            while (1);
                
        }
        else{
            cout<<endl<<"User delails are Invalid ";
            _getch();
        }
    }
    while(1);

    return 0;
}