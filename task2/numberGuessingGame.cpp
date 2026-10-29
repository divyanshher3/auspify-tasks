#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main() {
    srand(time(0));
    int number=rand() % 50+1;
    int n;
    int count=0;
    cout<<"Guess the number from 1 to 50 "<<endl;
    while(true){
        cout<<"Enter your guess "<<endl;
        cin>>n;

        if(cin.fail()){
            cout<<"Input must be a number "<<endl;
            break;
        }
        if(n< 1 || n > 50){
            cout<<"Please guess between 1 to 50 only !"<<endl;
            continue;
        }

        if(n == number){
            count++;
            cout<<"Yeah !! you guessed right number "<<endl;
            cout<<"Number of gusses :"<<count<<endl;
            break;
        }
        else if(n < number){
            cout<<" HINT: Think of a higher number "<<endl;
            count++;
        }
        else{
            cout<<"HINT: think of a lower number "<<endl;
            count++;
        }


    }
    return 0;

    }
