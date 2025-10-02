
#include <iostream>
#include "input.h"
#include <list>
#include "Student.h"
#include <fstream>
using namespace std; 

// Anthony Herrera 
// 09/28/2025
// CMPR 131 
// Prof Quach
// List container 

void listContainerMenu();
int menuOption();
void displayList(const list<student>& container);
bool readStudentFromFile(ifstream& inputfile, student& s);

int main()
{
    do
    {
        switch (menuOption())
        {
        case 0: exit(0); break;
        //case 1: vectorContainer(); break;
        case 2: listContainerMenu(); break;
        //case 3: application(); break;

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
    cout << "\n\t CMPR131 Chapter 5: Vector and List Container by Prof Q (1/6/21)";
    cout << "\n\t" << string(105, char(205));
    cout << "\n\t1> Vector container";
    cout << "\n\t2> List container";
    cout << "\n\t3> Application using Vector and/or List container";
    cout << "\n\t" << string(105, char(196));
    cout << "\n\t0.Exit";
    cout << "\n\t" << string(105, char(205));
    return inputInteger("\n\tOption: ", 0, 3);
}

void listContainerMenu()
{
    list<student> container;

    
        do 
        {
            system("cls");

        cout << "\n\tLists are sequence containers that allow constant time insert and erase operations anywhere within the"
            << "\n\tsequence, and iteration in both directions.";

        cout << "\n\t2> List container";
        cout << "\n\t" << string(105, char(205));
        cout << "\n\tA> clear() - Destroys all elements from the list";
        cout << "\n\tB> resize(n) - Changes the list so that it contains n elements";
        cout << "\n\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list";
        cout << "\n\tD> pop_front() - Deletes the first element";
        cout << "\n\tE> front() - Accesses the first element";
        cout << "\n\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list";
        cout << "\n\tG> pop_back() - Delete the last element";
        cout << "\n\tH> back() Accesses the last element";
        cout << "\n\tI> begin() - Returns an iterator refereing to the first element in the list";
        cout << "\n\tJ> end() Returns an iterator referring to the past-the-end element in the list";
        cout << "\n\tK> Using iterator begin() and end() returns all elements in the list";
        cout << "\n\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list";
        cout << "\n\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element in the list ";
        cout << "\n\tN> Using iterator rbegin() and rend() returns all elements in the list";
        cout << "\n\tO> erase(it) - Removes from the vector a single element(using an iterator)";
        cout << "\n\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)";
        cout << "\n\tQ> insert(it, entry) - Insert a new entry at the iterator.";
        cout << "\n\tR> swap() - Exchanges the content of the container by another list's content of the same type";
        cout << "\n\tS> Sort - Sorts the list.";
        cout << "\n\t" << string(105, char(196));
        cout << "\n\t0> return";
        cout << "\n\t" << string(105, char(205));


        char choice = toupper(inputChar("\n\tOption: "));
        switch (choice)
        {
        case '0':
            return;

        case 'A':
        {
            container.clear();
            if (container.empty())
            {
                cout << "\n\tList has been cleared\n\n";
            }
            break;
        }

        case 'B':
        {
            int n = inputInteger("\n\tEnter the new size (1-100): ", 1, 100);
            container.resize(n);
            cout << "\n\tThe list has been resized to " << n << " elements\n\n";
            break;
        }

        case 'C':
        {
            ifstream inputfile("input.dat");
            if (!inputfile)
            {
                cerr << "\n\tError: Could not open the file\n";
                break;
            }
             
            student s; 
            while (readStudentFromFile(inputfile, s)) 
            {
                container.push_front(s); 
            }
            cout << "\n\tThe list now has " << container.size() << " elements\n\n";
            break;
        }

        case 'D':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                container.pop_front();
                cout << "\n\tThe list now has " << container.size() << " elements\n\n";
                displayList(container);
            }
            break;
        }

        case 'E':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                cout << "\n\tFirst element from the list is (" << container.front() << ")\n\n";
            }
            break;
        }

        case 'F':
        {
            ifstream inputfile("input.dat");
            if (!inputfile)
            {
                cerr << "\n\tError: Could not open the file\n";
                break;
            }

            student s;
            while (readStudentFromFile(inputfile, s))
            {
                container.push_back(s);
            }
            cout << "\n\tThe list now has " << container.size() << " elements\n\n";
            break;
        }

        case 'G':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                container.pop_back();
                cout << "\n\tThe list now has " << container.size() << " elements\n\n";
                displayList(container);
            }
            break;
        }

        case 'H':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                cout << "\n\tLast element from the list is (" << container.back() << ")\n\n";
            }
            break;
        }

        case 'I':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                list<student>::iterator it = container.begin();
                if (it != container.end())
                    cout << "\n\tThe iterator referring the first element: " << &(*it) << "(" << *it << ")\n\n";
            }

            break;
        }

        case 'J':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                list<student>::iterator it;
                for (it = container.begin(); it != container.end(); ++it)
                {
                    cout << "\n\tThe iterator referring the last element: " << &(*it) << "(" << *it << ")\n\n";
                }
            }
            break;
        }

        case 'K': // Using iterator begin() and end() returns all elements
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                cout << "\n\tStudents (forward iteration):\n";
                list<student>::iterator it;
                for (it = container.begin(); it != container.end(); ++it)
                {
                    cout << "\t" << *it << "\n";
                }
            }
            break;
        }

        case 'L':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                list<student>::reverse_iterator rit = container.rbegin();
                cout << "\n\tThe iterator referring the reverse first element: " << &(*rit) << "(" << *rit << ")\n\n";
            }
            break;
        }

        case 'M':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                list<student>::reverse_iterator rit;
                for (rit = container.rbegin(); rit != container.rend(); ++rit)
                {
                    cout << "\n\tThe iterator referring to the reverse past-the-end element: " << &(*rit) << "(" << *rit << ")\n\n";;
                }
            }
            break;
        }

        case 'N': // Using iterator rbegin() and rend() returns all elements
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                cout << "\n\tStudents (reverse iteration):\n";
                list<student>::reverse_iterator rit;
                for (rit = container.rbegin(); rit != container.rend(); ++rit)
                {
                    cout << "\t" << *rit << "\n";
                }
            }
            break;
        }

        case 'O':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                list<student>::iterator it = container.begin();
                if (it != container.end())
                {
                    container.erase(it);
                    cout << "\n\tThe iterator referring the first element: " << &(*it) << "(" << *it << ")\n\n";
                }
            }
            break;
        }

        case 'P':
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                int startPos = inputInteger("\n\tEnter the starting position (0-based): ", 0, container.size() - 1);
                int endPos = inputInteger("\n\tEnter the ending position (0-based, greater than start): ", startPos + 1, container.size());

                // set iterators to the right positions
                list<student>::iterator start_it = container.begin();
                list<student>::iterator end_it = container.begin();

                // move start_it forward startPos steps
                for (int i = 0; i < startPos; ++i)
                    ++start_it;

                // move end_it forward endPos steps
                for (int i = 0; i < endPos; ++i)
                    ++end_it;

                container.erase(start_it, end_it);

                cout << "\n\tElements from position " << startPos
                    << " to " << (endPos - 1) << " have been erased.\n";
            }
            break;
        }

        case 'Q': // insert(it, entry) - Insert a new entry at the iterator
        {

            // Get student details
            string name, grade;
            double gpa;

            name = inputString("\n\tEnter student name: ", true);

            int gradeChoice = inputInteger("\tEnter grade level (1-Freshman, 2-Sophomore, 3-Junior, 4-Senior): ", 1, 4);
            if (gradeChoice == 1) grade = "Freshman";
            else if (gradeChoice == 2) grade = "Sophomore";
            else if (gradeChoice == 3) grade = "Junior";
            else if (gradeChoice == 4) grade = "Senior";

            gpa = inputDouble("\n\tEnter GPA (0.0 - 4.0): ", 0.0, 4.0);

            student entry;
            entry.setName(name);
            entry.setGradeLevel(grade);
            entry.setGPA(gpa);

            // Move iterator into place
            list<student>::iterator it = container.begin();
            for (int i = 0; i < container.size(); ++i)
                ++it;

            container.insert(it, entry);

            cout << "\n\tThe new element has been inserted after the begin iterator.\n";
            break;
        }


        case 'R': // swap() - Exchanges the content of the container by another list's content
        {
            list<student> other; // this is l2

            cout << "\n\tlist (l2) is initially ";
            if (other.empty())
                cout << "empty.\n";
            else
                cout << "has " << other.size() << " element(s).\n";

            container.swap(other); // swap container (l1) with other (l2)

            cout << "\n\tlist (l1) is ";
            if (container.empty())
                cout << "empty after swapped with list (l2).\n";
            else
                cout << "has " << container.size() << " element(s) after swapped with list (l2).\n";

            cout << "\n\tlist (l2) ";
            if (other.empty())
                cout << "is empty.\n";
            else
                cout << "now has " << other.size() << " element(s).\n";

            break;
        }

        case 'S': // sort() - Sorts the list
        {
            if (container.empty())
            {
                cout << "\n\tThe list is empty.\n";
            }
            else
            {
                container.sort(); 
                cout << "\n\tSorted List\n";
                displayList(container);
            }
            break;
        }


        }
        system("pause");
    }while (true);


}

bool readStudentFromFile(ifstream& inputfile, student& s)
{
    string name, grade, gpaStr;

    if (getline(inputfile, name, ',') &&
        getline(inputfile, grade, ',') &&
        getline(inputfile, gpaStr))
    {
        double gpa = atof(gpaStr.c_str());
        s.setName(name);
        s.setGradeLevel(grade);
        s.setGPA(gpa);
        return true;
    }
    return false; // no more lines
}

void displayList(const list<student>& container)
{
    if (container.empty())
    {
        cout << "\n\tThe list is empty.\n";
        return;
    }

    cout << "\n\tCurrent students in the list:\n";
    for (const auto& s : container)
    {
        cout << "\t" << s << "\n"; // uses your overloaded operator<<
    }
}
