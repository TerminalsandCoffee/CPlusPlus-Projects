#include <iostream>
#include <iomanip>  
using namespace std;
int main()
{
    const float PI = 3.14159;
    int user_choice;

    cout << "Architect Area Calculator:"
         << "\n*************************\n" 
         << "   1. Rectangle\n"
         << "   2. Triangle\n"
         << "   3. Circle\n"
         << "   4. Quit\n"
         << "\nPlease enter a menu item (1-4): ";
    cin >> user_choice;
    cout << endl;

    switch (user_choice)
    {
        float area;

        case 1:
        
        float width, length;
            cout << "Rectangle ";
            cout << "What is the length? " << endl;
            cin >> length;

            if (length > 0) 
            {
                cout << "What is the width? " << endl;
                cin >> width;

                if (width > 0) {
                    area = length * width;
                    
                    cout << fixed << showpoint << setprecision(2);
                    
                    cout << "The area of rectangle is " 
                         << area 
                         << endl;
                }
                else {
                    cout << "\nWe're sorry. \nWidth must be greater than 0." 
                    << endl;
                    cout << "Rerun the program and try again." << endl;
                }
                
            }
            else
            {
                cout << "\nWe're sorry. \nLength must be greater that 0." << endl;
                cout << "Rerun the program and try again." << endl;
            }
            break;

      
        case 2:

        float height,
                  base;

            cout << "What is the base? ";
            cin >> base;

            if (base > 0)
            {
                cout << "What is the height? ";
                cin >> height;

                if (height > 0) 
                {
                    area = (base * height) * .5;
                   
                    cout << fixed << showpoint << setprecision(2);
                    
                    cout << "Area of triangle is " 
                         << area 
                         << endl;
                         
                }
                else 
                {
                    cout << "\nWe're sorry. \nHeight must "
                         << " be greater than 0.\n"
                         << "Rerun the program and "
                         << "try again." 
                         << endl;
                }
                
            }
            else
            {
                cout << "\nWe're sorry. \nBase length must"
                     << " be greater than 0.\n"
                     << "Rerun the program and try again." << endl;
            }
            break;

        case 3:

                int radius;

            cout << "What is the radius: ";
            cin >> radius;

            if (radius < 0)
            {
                cout << "We're sorry. \nThe radius must be "
                     << "a positive number.\n"
                     << "Rerun the program and try again.\n" 
                     << endl;
            }
            else
            {
                area = PI * radius * radius;
               
                cout << fixed << showpoint << setprecision(2);

                cout << "The area of the circle is  " 
                     <<  area << endl;
            }
            break;
            
            
            case 4:
            cout << "Good-bye." << endl;
            break;
    
        default:
            cout << "We're sorry. \nYour choice must "
                 << "between 1 and 4.\n"
                 << "Rerun the program and try again." 
                 << endl;
            break;
    }

    cout << endl;

    return 0;
}