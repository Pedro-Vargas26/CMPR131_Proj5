
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "input.h";
#include "applicationList.h";
using namespace std;

int optionThree();
int menuOption();

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(0); break;
       // case 1: one(); break;
       // case 2: two(); break;
        case 3: optionThree(); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
    return EXIT_SUCCESS;
}

int menuOption()
{
    system("cls");
    cout << "\n\tCMPR131 Chapter 5: Vector and List Container by Daisy (10/1/25)";
    cout << "\n\t" << string(105, char(205));
    cout << "\n\t1> Vector container";
    cout << "\n\t2> List container";
    cout << "\n\t3> Application using Vector and/or List container";
    cout << "\n\t" << string(105, char(196));
    cout << "\n\t0.Exit";
    cout << "\n\t" << string(105, char(205));
    return inputInteger("\n\tOption: ", 0, 3);
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int listMenu() {

    system("cls");
    cout << "\n\t3> Application using Vector and/or List container";
    cout << "\n\t" << string(105, char(205));
    cout << "\n\t1> Add an integer";
    cout << "\n\t2> Delete an integer";
    cout << "\n\t3> Display input integers";
    cout << "\n\t4> Display frequencies of integers";
    cout << "\n\t" << string(105, char(196));
    cout << "\n\t0>  Exit";
    cout << "\n\t" << string(105, char(205));
    return inputInteger("\n\tOption: ", 0, 4);
}

int optionThree()
{
    applicationList list;
    do {
        switch (listMenu()) {

        case 0: return 0;
        case 1: {
            int n = inputInteger("\nAdd an integer: ");
            list.add(n);
            cout << "\n\tInteger added: " << n<< "\n";
            system("pause");
            break;
        }
        case 2: {
           int n=  inputInteger("\nDelete an integer: ");

           if (!list.remove(n)) {
               cout << "\n\tList does not contain " << n << ".\n";
           }
           else {
               cout << "\n\tInteger deleted: " << n << "\n";
           }
           system("pause");
            break;
        }

        case 3:  
            // Display  integers list
            list.display();
            system("pause");
            break;
        
        case 4:
            // displays number and amount of times it repeats 
            list.frequencies();
            system("pause");
            break;

        default:
            cout << "\nERROR: Invalid option.\n";
        }
    } while (true);
    return EXIT_SUCCESS;
}
  
