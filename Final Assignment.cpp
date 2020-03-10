#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<iomanip>
using namespace std;

void WelcomeMessageForYou();
void endFunctionMessage();
void replayFunction(char *replay);
int getLotteryNumbers(int lotteryNumbers[]);
int getUserNumbers(int userNumbers[]);
int sortNumbers(int sortNumbers[]);
void checkNumbers(int lotteryNumbers[], int userNumbers[] );
void resultsMessage (int counter);


int main()
{
    int lotteryNumbers[7];
    int UserNumbers[4];
    char replay;

    WelcomeMessageForYou();

    do {
        getLotteryNumbers(lotteryNumbers);
        getUserNumbers( UserNumbers);
        sortNumbers (lotteryNumbers);
        sortNumbers (UserNumbers);
        checkNumbers(lotteryNumbers,UserNumbers);
        replayFunction(&replay);
    }
    while (replay=='y' || replay=='y');

    endFunctionMessage();

    return 0;

}

void WelcomeMessageForYou()
{
    cout<<setw(45)<<"Welcome to Fahid Khans lottery Machine!!"<<endl<<endl;

}

void endFunctionMessage()
{
    cout<<setw(49)<<"thanks for playing Fahid Khans Lottery Machine :) !! "<<endl<<endl;
}

void replayFunction(char *replay)
{
    cout<<setw(51)<<"Would you like to play the game again? (Yes/No)"<<endl;

    do{
        cin>> *replay ;
    } while
            (*replay !='y' &&
             *replay !='Y' &&
             *replay !='n' &&
             *replay !='N');
}


int getLotteryNumbers(int lotteryNumbers[])
{
    srand (time_t(0));


    for (int i=0;i<7;i++)
    {
        lotteryNumbers [i]=1+(rand() %39);

        while(lotteryNumbers [i]==lotteryNumbers[i-1])
        {
            lotteryNumbers [i]=1+(rand() %39);
        }
    }
return 0;
}

int getUserNumbers(int UserNumbers[])
{

    cout << setw(55)<<"enter 7 numbers from 1-39 :"<<endl;

    for(int i=0;i<7;i++){
        cin>>UserNumbers[i];
        while(UserNumbers[i]<1 || 39<!UserNumbers[i])
        {
            cout<<"Invalid Number Baby!"<<endl;
            cout<<"Can you please choose between 1-39 numbers:";
            cin>>UserNumbers[i];
        }
    }
    return 0;
}




int sortNumbers(int sortNumbers[]){
    int temp;
    for (int counter=6;counter>0;counter--){
        for(int i=0;i<6;i++){
            if(sortNumbers[i]>sortNumbers[i+1])
            {
                temp=sortNumbers[i+1];
                sortNumbers[i+1]=sortNumbers[i];
                sortNumbers[i]=temp;
            }
        }
}
    return 0;
}


void checkNumbers(int lotteryNumbers[] , int UserNumbers[])
{
    string yes="YES YO";
    string no="NO NO";
    int counter = 0;

    cout<<endl;

    cout<<"Lottery Numbers------------------Your Numbers---------------------Results"<<endl;


    for ( int i=0;i<7;i++){


        if(lotteryNumbers[i]==UserNumbers[i])
        {
            cout<<setw(11)<<lotteryNumbers[i]<<setw(18)<<"_____________"<<setw(6)<<UserNumbers[i]<<setw(19)<<"-------------"<<setw(7)<<yes<<endl;
            counter++;

        }
        else
        {
            cout<<setw(11)<<lotteryNumbers[i]<<setw(18)<<"-------------"<<setw(6)<<UserNumbers[i]<<setw(19)<<"--------------"<<setw(7)<<no<<endl;
        }
    }
    resultsMessage(counter);
}




void resultsMessage(int counter){

    cout<<endl;
    if(counter==7){
        cout<<setw(28)<<"You have gotten"<<counter<<"numbers out of 7"<<endl;
        cout<<setw(41)<<"You win my boy,the day is yours"<<endl<<endl;
    }
    else{
        cout<<setw(28)<<"You have gotten"<<counter<<"numbers out of 7" <<endl;
        cout<<setw(41)<<"You lose,better luck for next time"<<endl<<endl;
    }
}







