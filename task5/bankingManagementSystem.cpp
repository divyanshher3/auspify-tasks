#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;
struct account{
   int accnum;
   string name;
   double balance;
   int PIN;
};
struct Transaction{
    int accnum;
    string type;
    double amount; 
};
const string FILE_NAME ="accountrecord";
const string Transaction_FILE_NAME ="TransactionRecord";

 void savetoaccount(const vector<account>& accou){ //<-creating a file for storing recored of accounts
    ofstream out(FILE_NAME);
    if(!out){
        cout<<"Error while saving account data!"<<endl;
        return;
    }

    for(const account& ac : accou){
        out << ac.accnum << " " << ac.balance << " " << ac.PIN << " " << ac.name << "\n"; 
    }
 }

 bool verifyPIN(const account& a){ //<-checking the PIN
    int n;
    cout<<"Please enter the PIN for verification: ";
    cin>>n;
    if(a.PIN != n){
        cout<<"Incorrect PIN!"<<endl;
        return false;
    }
    return true;
}

 void saveToTransaction( const Transaction & tr){  //<-creating a file for storing recored of Transaction
     ofstream out(Transaction_FILE_NAME , ios::app);
    if(!out){
        cout<<"Error while saving Transaction data!"<<endl;
        return;
    }

   
        out<<tr.accnum<<" "<<tr.amount<<" "<<tr.type<<" "<<"\n"; 
    
 }
void LoadAccount(vector<account>& accounts){ 
    ifstream in(FILE_NAME);
    if(!in){return;}

    account a;
    while(in>> a.accnum >> a.balance>>a.PIN){
        getline(in >> ws, a.name);
        accounts.push_back(a);
    }
}
void LoadTransaction(vector <Transaction>& transec){
    ifstream in(Transaction_FILE_NAME);
    if(!in){
        return;
    }

    Transaction t;
    while(in>>t.accnum>>t.amount>>t.type){
        transec.push_back(t);
    }
}

 void createAccount( vector<account>& acco){  //<-creating  account
    account at;
   
    cout<<"Welcome!!!"<<endl;
    cout<<"Enter account number"<<endl;
    cin>>at.accnum;
    for( const account& a : acco){
        if(a.accnum == at.accnum){ //checking if account number already exist
            cout<<"Account number already exist "<<endl;
            return;
        }
    }
    cout<<"Enter the name of account holder "<<endl;
    getline(cin>>ws ,at.name);
    cout<<"Enter the initial balance "<<endl;
    cin>>at.balance;
    if (at.balance < 0) {
    cout << "Initial balance cannot be negative" << endl;
    return;
    }
    cout<<"create the PIN for your account "<<endl;
    cin>>at.PIN;
    if (at.PIN < 1000 || at.PIN > 9999) {
    cout << "PIN must contain exactly 4 digits" << endl;
    return;
    }
    acco.push_back(at);  //pushing acocunt to account vector
 }
 void DisplayAccountDetails(const vector<account>& acco){ //to display specific account details
    int num;
    cout<<"Enter the account number to Check Details "<<endl;
    cin>>num;

    for(const account act : acco){
        if(act.accnum == num){ //checking if account number entered by the user is valid!!!
            cout<<"Account number: "<<act.accnum<<endl;
            cout<<"Account Name: "<<act.name<<endl;
            cout<<"Account Balance: "<<act.balance<<endl;
            return;
        }
    }
    cout<<"Account number entered by you does not exist "<<endl;
 }
 void Deposit(vector<account>& acco , vector<Transaction>& tan){ //deposit money to a account
    int n ;
    double amount;
    cout<<"Please enter the account number"<<endl;
    cin>>n;

    for( account& act  : acco){
        if(act.accnum == n){
            

            if(!verifyPIN(act)){ //verifying PIN
                cout<<"Error: Incorrect PIN! Transaction cancelled "<<endl;
                return;
            }
            cout<<"Verification done!! "<<endl;
            cout<<"Please enter the amount to deposit "<<endl;
            cin>>amount;

            if(amount<=0){ //validate amount must not be negative
                cout<<"Invalid amount! It must be greater than 0 "<<endl;
                return;
            }

            act.balance += amount; //adding balance to entered account

            Transaction tr;  
            //saving transaction History 
            tr.accnum = act.accnum; 
            tr.type ="Deposit";
            tr.amount = amount;
            tan.push_back(tr);

            savetoaccount(acco);
            saveToTransaction(tr);

            cout<<"Deposit successful "<<endl;
            return;
        }
    }
    cout<<"Account number does not exist "<<endl;

 }
 void withdraw(vector<account>& acco , vector<Transaction>& tran){ //<-withdraw amount from account
    int  num;
    double amount;

    cout<<"Enter the account number "<<endl;
    cin>>num;
    for(account& act : acco){
        if(act.accnum == num){ //check if valid account number
            if(!verifyPIN(act)){
                cout<<"Invalid PIN ! Transaction cancelled!!"<<endl;
                return;
            }

            cout<<"Enter the withdraw amount "<<endl;
            cin>> amount;
            if(amount<=0){  //<- validate amount must not be negative
                cout<<"Invalid amount! It must be greater than 0 "<<endl;
                return;
            }
            if (amount > act.balance) { //<-validate withdraw amount must be less then user's current balance
             cout << "Insufficient balance!" << endl;
             return;
                }

            act.balance-=amount; //Deducting withdraw amount from account

            Transaction tr;
                //Saving transantion History
            tr.accnum = act.accnum;
            tr.type ="withdraw";
            tr.amount = amount;

            tran.push_back(tr);

            savetoaccount(acco);
            saveToTransaction(tr);

            cout<<"Withdraw successful ! Have a nice day "<<endl;
            return;
        }
    }

    cout<<"Entered Account number does not exist "<<endl;
    
 }
 void checkbalance(const vector<account>& acco){
    int n;
    cout<<"Enter the account number "<<endl;
    cin>>n;

    for(const account& act : acco){
        if(act.accnum == n){

            if(!verifyPIN(act)){
                cout<<"Invalid PIN ! Transaction cancelled!!"<<endl;
                return;
            }

            cout<<"Your current balance is :"<<act.balance<<endl;
            return;
        }
    }
    cout<<"Entered Account number does not exist "<<endl;
 }

 void tHistory(const vector<account>& acco , const vector<Transaction>& trans){ //<- Display transaction history
     int n;
    cout<<"Enter the account number "<<endl;
    cin>>n;

    for(const account& act : acco){
        if(act.accnum == n){
            
            if(!verifyPIN(act)){
                cout<<"Invalid PIN ! Transaction cancelled!!"<<endl;
                return;
            }
            bool found =false;
            cout<<"-------------Transaction History------------"<<endl;
            for(Transaction tran : trans){
                if(tran.accnum == n){
                    cout<<tran.type << ":" <<tran.amount<<endl;
                    found = true;                
                }
            }
            if(!found){
                cout<<"No Transaction found for this account "<<endl;
            }
            return;
        }
    }
    cout<<"Acount number does not exits "<<endl;

 }
 
void trasferMoney(vector<account>& acco, vector<Transaction>& trans) { //function for money transfer
    int n, num;
    double amount;

    cout << "Enter Your account number: " << endl;
    cin >> n;

    for (account& act : acco) {
        if (act.accnum == n) {

            if (!verifyPIN(act)) {
                cout << "Invalid PIN! Transaction cancelled!!" << endl;
                return;
                }

            cout << "Enter the account number to whom you want to send money: ";
            cin >> num;

            if (n == num) {
                cout << "You can't transfer money to your own account!" << endl;
                return;
            }

            cout << "Enter the amount to transfer: ";
            cin >> amount;

            if (amount <= 0) { //<-validate amount must not be negative
                cout << "Invalid amount! It must be greater than 0" << endl;
                return;
            }

            if (amount > act.balance) {  //<-validate amount must be less then user's current balance
                cout << "Insufficient balance!" << endl;
                return;
            }

            account* receiver = nullptr;

            for (account& ac : acco) {
                if (ac.accnum == num) { //checking if receiver's account exist
                    receiver = &ac;
                    break;
                }
            }

            if (receiver == nullptr) {
                cout << "Receiver account does not exist" << endl;
                return;
            }

            receiver->balance += amount; //adding amount to receiver's account
            act.balance -= amount; //deducting amount from sender's account

            //transaction History of sender
            Transaction out;
            out.accnum = n;
            out.amount = amount;
            out.type = "SEND_MONEY";

            //transaction History of receiver
            Transaction in;
            in.accnum = num;
            in.amount = amount;
            in.type = "RECEIVED_MONEY";

            trans.push_back(out);
            trans.push_back(in);

            savetoaccount(acco);
            saveToTransaction(out);
            saveToTransaction(in);

            cout << "Money transferred successfully!" << endl;
            return;
        }
    }

    cout << "Account does not exist" << endl;
}

 void sreachAccount(const vector<account>& acco){ //search account by account number or account name
    
int n;
cout<<"1. search by Account number "<<endl
    <<"2. Search by Holder's Name"<<endl;
    cout<<"Choice :";
    cin>>n;

switch (n){
    
    case 1:{
        DisplayAccountDetails(acco);
        break;
    }
    case 2:{
        string name;
   cout << "Enter the account holder's name: " << endl;
    getline(cin>>ws,name);

     bool found = false;
    for(const account& act : acco){
        if(act.name == name){
            cout<<"Account number: "<<act.accnum<<endl;
            cout<<"Account Name: "<<act.name<<endl;
            cout<<"Account Balance: "<<act.balance<<endl;
            found =true;
        }
    }
     if(!found){
                cout<<"No account found with that name"<<endl;
            }
            break;
    }
    default :{
        cout<<"invalid opratoin !!!"<<endl;;
        
    }
}

}
 void DisplayAccount(const vector<account>& acco){
if(acco.empty()){
    cout<<"No Account is created at this moment "<<endl;
    return;
}

for(account act : acco){
    cout<<"Account name :"<<act.name<<endl; 
    cout<<"Account Number :"<<act.accnum<<endl; 
    cout<<"------------------------------------------ "<<endl; 
}

 }
 void closeAccount( vector<account>& acco){
    int n;
    cout<<"Enter the account number "<<endl;
    cin>>n;

    for(auto i = acco.begin() ; i!=acco.end() ; i++){ //searching in whole vector
        if(i->accnum==n){
            if(!verifyPIN(*i)){
                cout<<"Incorrect PIN "<<endl;
                return;                      // verifyPIN prints "Incorrect PIN!"
            }
            if(i->balance!=0){
                cout<<"Account balance must be zero before closing it"<<endl;
                return;
            }
            acco.erase(i);
            savetoaccount(acco);
            cout<<"Account removed successfully "<<endl;
            return;
        }
    }
    cout<<"Account number does not exist"<<endl;
 }
 

int main() {
    vector<account> acc;
    vector<Transaction> tran;

    LoadAccount(acc);
    LoadTransaction(tran);
    int n;
while(true){
    cout<<"\n=======BANK MANAGEMENT SYSTEM========="<<endl
    <<"1.create account" <<endl
    <<"2.Display account details"<<endl
    <<"3. Deposit "<<endl
    <<"4. Withdraw "<<endl
    <<"5. Balance Inquiry" <<endl
    <<"6. Transaction History"<<endl
    <<"7. Transfer Money "<<endl
    <<"8. search account (by ID or name)"<<endl
    <<"9. Display All Account "<<endl
    <<"10. close Account "<<endl
    <<"11. Exit"<<endl;

    cout<<"Enter your choice : ";
    
    if(!(cin>>n)){ //validate input must be a number
        cin.clear();
        cin.ignore(10000 , '\n');
        cout<<"You must enter the number Provided in the option "<<endl;
        continue;
    }

    switch(n){
        case 1:{createAccount(acc);      savetoaccount(acc); break;}
        case 2:{DisplayAccountDetails(acc);      break;}
        case 3:{Deposit(acc,tran);       break;}
        case 4:{withdraw(acc,tran);     break;}
        case 5:{checkbalance(acc);       break;}
        case 6:{tHistory(acc,tran);       break;}
        case 7:{trasferMoney(acc,tran)  ;    break;}
        case 8:{sreachAccount(acc) ;     break;}
        case 9:{DisplayAccount(acc) ;     break;}
        case 10:{closeAccount(acc)  ;    break;}
        case 11:{ savetoaccount(acc); 
        cout<<"Good bye"<<endl; 
        return 0;}
        default :{
            cout<<"Invalid choise"<<endl;
        }
    }
    

}
   
}