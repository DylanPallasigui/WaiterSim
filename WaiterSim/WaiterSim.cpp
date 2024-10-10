/******************************************************************************
Author: Dylan Pallasigui
Date: 10/31/2022

*******************************************************************************/
#include <iostream>
using namespace std;

//main dish costs
const double costSpecial1 = 14.95;
const double costSpecial2 = 9.95;
const string special1 = "Chicken parmesean";
const string special2 = "Cheese ravioli";

//---------------------------------------------------------------------------
// Name: getTableOrder
// Parameters: const int numPeople, int & numSpecial1, int & numSpecial2
// Returns: none
// Purpose: This function asks how many people ordered special1, how many ordered
// special2, and updates through the pass-by-reference parameters
// There should be an error-checking loop to make sure that the total number of dishes
// ordered is less than the number of people sitting there (some people may just be
// eating unlimited breadsticks, so the number doesn't have to match exactly)
//---------------------------------------------------------------------------
void getTableOrder(const int numPeople, int & numSpecial1, int & numSpecial2)
{
    cout<<"How many will be ordering special 1 (Chicken parmesan) >>"<<endl;
    cin >> numSpecial1;
    cout<<"And how many will be ordering special 2 (Cheese ravioli) >>"<<endl;
    cin >> numSpecial2;
    // error checking for numPeople
    while(numSpecial1 + numSpecial2 > numPeople)
    {
        cout << "Whoops! It looks like that's too many dishes for your party! Let's try again." << endl;
        cout<<"How many will be ordering special 1 (Chicken parmesan) >>"<<endl;
        cin >> numSpecial1;
        cout<<"And how many will be ordering special 2 (Cheese ravioli) >>"<<endl;
        cin >> numSpecial2;
    }
}


//---------------------------------------------------------------------------
// Name: calculateTip
// Parameters: const int numPeople, const double bill, double & tip
// Returns: none
// Purpose: Calculate the tip.  If there are 8 or more people, 
// the tip was already added, but ask if they would like to add more.
// The user should be able to add a percentage or a specific amount.  
// (be sure to add to the tip that's possibly already there)
// Include error checking for inputs.
//---------------------------------------------------------------------------
void calculateTip(const int numPeople, const double bill, double & tip)
{
    char tipmore;
    char choicetip;
    cout<<"Would you like to add more? (y/n) >>"<<endl;
    cin>>tipmore;
    
    while(tipmore != 'y' && tipmore != 'n'){
            cout<<"Error, please enter y or n."<<endl;
            cin>>tipmore;
    }
    
    if(tipmore == 'y'){
        cout<<"Would you like to tip a percentage or a specific amount? (p/s) >>"<<endl;
        cin>>choicetip;
        if(choicetip == 's'){
            cout<<"Please input the specific amount you would like to add >>"<<endl;
            cin>>tip;
            while(tip <= 0.0 && tip >= 100.0){
                cout<<"Please input the specific amount you would like to add >>"<<endl;
            }
            tip = tip + bill;
        } else if(choicetip == 'p'){
            cout<<"Please input the percentage you would like to add (20% = .20) [0..1] >>"<<endl;
            cin>>tip;
            while(tip <= 0.0 && tip >= 1.0){
                cout<<"Please input the percentage you would like to add (20% = .20) [0..1] >>"<<endl;
            }
            tip = tip*bill;
        } else {
            cout<<"Error, please enter 1 or 2."<<endl;
        }
    } else {
        cout<<":("<<endl;
    }
}


//---------------------------------------------------------------------------
// Name: calculateCost
// Parameters: const int numPeople, const int numSpecial1, const int numSpecial2, double & tip
// Returns: the cost of the meal
// Purpose: Calculate the total cost of everyone's meals.  If there are more than
// 8 people dining, update the tip parameter to a mandatory 20%.  Then, call the calculateTip function
// to find out how much they tip
// Note: if there are more people than meals ordered, the extra people should be
// charged $5 each for unlimited breadsticks
//---------------------------------------------------------------------------
float calculateCost(const int numPeople, const int numSpecial1, const int numSpecial2, double & tip)
{
    if(numPeople >= 8){
        cout<<"Given the number of people with whom you're dining, you've already added 20% to your bill."<<endl;
        tip = tip * 0.2;
    }else if(numPeople < 8){
        tip = tip + (5 * numPeople -(numSpecial1+numSpecial2));
    }
    calculateTip(numPeople, numSpecial1 + numSpecial2, tip);
    
    return((numSpecial1 * 14.95) + (numSpecial2 * 9.95) + tip);
}

//---------------------------------------------------------------------------
// Name: displayFinalBill
// Parameters: const int numPeople, const int special1, const int special2, const double bill, const double tip
// Returns: nothing
// Purpose: This function prints the receipt information - how many people got which dish,
// how many just had breadsticks, the price of everyone's food, the tip, and the final bill
//---------------------------------------------------------------------------
void displayFinalBill(const int numPeople, const int numSpecial1, const int numSpecial2, const double bill, const double tip)
{
    cout<<"There were "<<numPeople<<" people in your party today."<<endl;
    cout<<numSpecial1<<" orders of Chicken parmesan for $14.95 each"<<endl;
    cout<<numSpecial2<<" orders of Cheese ravioli for $9.95 each"<<endl;
    if(numSpecial1 > numSpecial2){
        cout<<numSpecial1 - numSpecial2<<" orders of breadsticks for $5 each."<<endl;
    }else {
        cout<<numSpecial2 - numSpecial1<<" orders of breadsticks for $5 each."<<endl;
    }
    cout<<"Your total was "<< bill <<endl;
    cout<<"You tipped "<< tip <<endl;
    cout<<"For a total of "<< bill + tip <<endl;
    
}

//---------------------------------------------------------------------------
// Name: orderMoreEntrees
// Parameters: char & orderMore
// Returns: nothing
// Purpose: This function asks the user if they want to order more food, checks to 
// ensure that the user enters a 'y' or an 'n', and returns the answer (by updating the parameter)
// If they enter an uppercase letter, it gets converted to lowercase
//---------------------------------------------------------------------------
void orderMoreEntrees(char & orderMore)
{
    cout<<"Would you like to add more? (y/n) >>"<<endl;
    cin>>orderMore;
    
    if(orderMore == 'y'){
        orderMore = 'y';
    } else if(orderMore == 'n'){
        orderMore = 'n';
    } else{
        cout<<"Error, please enter y or n as your answer."<<endl;
    }
}

//---------------------------------------------------------------------------
// Name: resetVariables
// Parameters: double & totalBill, double & tip, int & numPeople, int & numSpecial1, int & numSpecial2
// Returns: nothing
// Purpose: This function resets the values of all variables passed in
//---------------------------------------------------------------------------
void resetVariables(double & totalBill, double & tip, int & numPeople, int & numSpecial1, int & numSpecial2)
{
    totalBill = 0.0;
    tip = 0.0;
    numPeople = 0;
    numSpecial1 = 0;
    numSpecial2 = 0;
}


int main()
{
    double totalBill, tip;
    int numPeople, numSpecial1, numSpecial2;
    char orderMore = 'n';

    do
    {
        cout << "How many people are in your party? >> ";
        cin >> numPeople;
        while(numPeople <= 0)
        {
            cout << "Invalid input.  How many people are in your party? >> ";
            cin >> numPeople;
        }
        cout << "\n\nWelcome to the Olive Garden!  It appears there are " << numPeople << " dining with us today.\n";
            
        getTableOrder(numPeople, numSpecial1, numSpecial2);
        totalBill = calculateCost(numPeople, numSpecial1, numSpecial2, tip);
        displayFinalBill(numPeople, numSpecial1, numSpecial2, totalBill, tip);
        orderMoreEntrees(orderMore);
        if(orderMore == 'y')
        {
            resetVariables(totalBill, tip, numPeople, numSpecial1, numSpecial2);
        }
    } while(orderMore != 'n');
    cout << "We hope you enjoyed your meal, and remember, when you're here, you're family!\n";
    return 0;
}
