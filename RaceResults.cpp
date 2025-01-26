//Name: Rafael Martinez
//Data: 03/13/2020
//Class: Virtual
//Provides the winner of a race by comparing three time stamps


#include <iostream>
#include <string>
using namespace std;

void welcome();
void getRaceTimes(string&, double&);
void findWinner(string, string, string, double, double, double);
double raceAverage(double, double, double);

int main()
{
    double time1;
    double time2;
    double time3;
    double average;
    
    string racer1;
    string racer2;
    string racer3;
    
    welcome();
    getRaceTimes(racer1, time1);
    cout << endl;
  
    getRaceTimes(racer2, time2);
    cout << endl;
    
    getRaceTimes(racer3, time3);
    cout << endl;
    
    findWinner(racer1, racer2, racer3, time1, time2, time3);
    
    double result = raceAverage(time1, time2, time3);
    cout << endl;
    cout << "The overall average race time is" << " " << result;
    
    return 0;
}

void getRaceTimes(string& racerName, double& raceTime)
{
    cout << "Please enter the name of the racer > ";
    cin >> racerName;
    cout << "Please enter the time of the racer > ";
    cin >> raceTime;
    while (raceTime <= 0)
    {
        cout << "Sorry, that time is invalid, Please enter a valid race time > ";
        cin >> raceTime;
    }
    return;
}

void findWinner(string racer1, string racer2, string racer3, double time1, double time2, double time3)
{
    if ((time1 < time2) && (time1 < time3))
    {
        cout << "Congratulations" << " " << racer1 << " " << "you are the winner!!\n";
    }
    if ((time2 < time1) && (time2 < time3))
    {
        cout << "Congratulations" << " " << racer2 << " " << "you are the winner!!\n";
    }
    if ((time3 < time1) && (time3 < time2))
    {
        cout << "Congratulations" << " " << racer3 << " " << "you are the winner!!\n";
    }
    if ((time2 < time1) && (time2 == time3))
    {
        cout << "Congratulations" << " " << racer2 << " " << "and" << " " << racer3 << " " << "you are the winners!!\n";
    }
    if ((time3 < time2) && (time3 == time1))
    {
        cout << "Congratulations" << " " << racer1 << " " << "and" << " " << racer3 << " " << "you are the winners!!\n";
    }
    if ((time2 < time3) && (time2 == time1))
    {
        cout << "Congratulations" << " " << racer1 << " " << "and" << " " << racer2 << " " << "you are the winners!!\n";
    }
    if ((time1 == time2) && (time1 == time3))
    {
        cout << "We have a 3 way tie!! There is no winner for this race\n";
    }
    return;
}

void welcome()
{
    cout << "************************************************\n";
    cout << "Welcome to Race Results Program.\n";
    cout << "You are Asked to Enter the Three Racer’s Names\n";
    cout << "and Their Associated Race Time.\n";
    cout << "Please enter a real number for Race Time (the Race Time Must be > 0).\n";
    cout << "Program Developed by : Rafael Martinez\n";
    cout << "************************************************\n";
    cout << endl;
    return;
}

double raceAverage(double time1, double time2, double time3)
{
    double average = 0;
    average = (time1 + time2 + time3) / 3;
    return average;
}