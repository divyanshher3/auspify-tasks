#include <iostream>
using namespace std;

int main() {
float a ,b;
char operations ;

//taking inputs
cout<<"Enter two numbers "<<endl;
cin>> a >>b ;
//validate the input must be numaric
if (cin.fail()) {
    cout << "Invalid input! Enter numeric values only.";
    return 1;
}


//operators
cout<<"enter the operation eg: + , - , / , *"<<endl;
cin>>operations;

switch (operations){
    case '+':{
        cout<<"asnwer : "<<a+b <<endl;
        break;
    }
    case '-':{
        cout<<"asnwer : "<<a-b <<endl;
        break;
    }
    case '/':{
        if(b==0){
            cout << "Cannot divide by zero";
            break;
        }
        cout<<"asnwer : "<<a/b <<endl;
        break;
    }
   
    case '*':{
        cout<<"asnwer : "<<a*b <<endl;
        break;
    }
    default:
    {
        cout<<"enter a valid operation !"<<endl;
    }
}
    return 0;
}