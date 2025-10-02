//Name: Pedro Vargas
//Date: 10/1/2025
//Description:
//Collaboration with: Daisy Ramon and Anthony herrera
//STL demonstration with Vector and List containers. 

#include <iostream>
#include <vector>
#include "input.h"
#include "Student.h"
#include "applicationList.h"
#include <list>
#include <fstream>
using namespace std;


const char INDENT = '\t';
char mainMenu();
char vectorMenu();
void optionOne();
vector<string> split(const string&, const char);


void optionTwo();
void displayList(const list<student>& container);
bool readStudentFromFile(ifstream& inputfile, student& s);

int listAndVectorMenu();
void optionThree();

int main() {
    do {
        char menuChoice = mainMenu();
        switch (menuChoice) {
        case 1: optionOne();break;
        case 2: optionTwo();break;
        case 3: optionThree();break;
        default:
            return EXIT_SUCCESS;
        }
    } while (true);
}




char mainMenu() {
	bool invalidChoice = true;

	//rh reference to avoid instancing a char

	int choice = 0;
		system("cls");
		cout << "\n";
        cout << INDENT << "CMPR131 Chapter 5: Vector and List Container by Pedro Vargas (9 / 18 / 25)\n";
        cout << INDENT << string(90, (char)205) << endl;
        cout << INDENT << "1 > Vector container\n";
        cout << INDENT << "2 > List container\n";
        cout << INDENT << "3 > Application using Vector and /or List container\n";
        cout << INDENT << string(90, (char)196) << endl;
        cout << INDENT << "0 > Exit\n";
        cout << INDENT << string(90, (char)205) << endl;
		choice = inputInteger("\tEnter choice:", 0,3);
	return choice;
}

char vectorMenu(){
	/*Needs validation of input Within A-S or 1 and 0. */


	cout << INDENT << "Vectors are sequence containers representing arrays that can change in size.\n\n";
	cout << INDENT << "1 > Vector's member functions\n";
	cout << INDENT<< string(100, (char)205) << endl;
	cout << INDENT << INDENT << "A > clear() - Removes all elements from the vector(which are destroyed)\n";
	cout << INDENT << INDENT << "B > reserve(n) - Requests that the vector capacity be at least enough to contain n elements\n";
	cout << INDENT << INDENT << "C > resize(n) - Resizes the container so that it contains n elements\n";
	cout << INDENT << INDENT << "D > Read input.dat and push_back(e) - Adds a new element at the end of the vector\n";
	cout << INDENT << INDENT << "E > pop_back() - Removes the last element in the vector\n";
	cout << INDENT << INDENT << "F > front() - Returns a reference to the first element in the vector\n";
	cout << INDENT << INDENT << "G > back() - Returns a reference to the last element in the vector\n";
	cout << INDENT << INDENT << "H > index using at() or []) - Returns a reference to the element at position n in the vector\n";
	cout << INDENT << INDENT << "I > begin() - Returns an iterator pointing to the first element in the vector\n";
	cout << INDENT << INDENT << "J > end() Returns an iterator referring to the past - the - end element in the vector\n";
	cout << INDENT << INDENT << "K > Using iterator begin() and end() returns all elements in the vector\n";
	cout << INDENT << INDENT << "L > rbegin() - Returns a reverse iterator pointing to the last element in the vector\n";
	cout << INDENT << INDENT << "M > rend() - Returns a reverse iterator pointing to the theoretical element preceding the first\n";
	cout << INDENT << INDENT << "element in the vector\n";
	cout << INDENT << INDENT << "N > Using iterator rbegin() and rend() returns all elements in the vector\n";
	cout << INDENT << INDENT << "O > erase(it) - Removes from the vector a single element(using an iterator)\n";
	cout << INDENT << INDENT << "P > erase(start_it, end_it) - Removes from the vector a range of elements(using iterators)\n";
	cout << INDENT << INDENT << "Q > insert(it, entry) - Insert a new entry at the iterator.\n";
	cout << INDENT << INDENT << "R > swap() - Exchanges the content of the container by another vector's content of the same type\n";
	cout << INDENT << INDENT << "S > Sort - Sorts the vector.\n";
	cout << INDENT << string(100, (char)196) << endl;
	cout << INDENT << INDENT << "0 > return\n";
	cout << INDENT << string(100, (char)205) << endl;
	char optionChoice = inputChar("\t\tOption:");
	return toupper(optionChoice);

}

void optionOne() {
	std::vector <student> studentDat;
    std::vector<student> v2;
	vector<string>tokens;
    vector<student>::iterator tempIter;
    vector<student>::reverse_iterator tempReverseIter;
	fstream fileReader;
	student newStudent;
    int tempVar = 0;
	std::string tempStr = "";
    string tempName = "";
    string tempYear = "";
    double gpa = 0;

	bool endProgram = false;
	do {
		system("cls");

		char vectorOption = vectorMenu();

		switch (vectorOption) {
		case 'A':
			studentDat.clear();
			cout << "\n" << INDENT << "The Vector has been cleared. \n\n";
			break;
		case 'B':
			studentDat.reserve(inputInteger("\tEnter the capacity (1...100):",1,100));
			cout << "\n" << INDENT << "Vector has been reserved " << studentDat.capacity() << " elements.\n\n";
			break;
		case 'C':
			studentDat.resize(inputInteger("\tEnter the new size (1...100):", 1, 100));
			cout << "\n" << INDENT << "vector has been resized to " << studentDat.size() << " elements.\n\n";
			break;
		case 'D':
			fileReader.open("input.dat");
			if (fileReader.is_open()) {
				while (getline(fileReader, tempStr)) {
					tokens = split(tempStr, ',');
					try {
						newStudent.setName(tokens[0]);
						newStudent.setGradeLevel(tokens[1]);
						newStudent.setGPA(stof(tokens[2]));
					}
					catch (...) {
						cerr << "\n\t" << "ERROR TRANSLATING FILE. \n\n";
					}
					studentDat.emplace_back(newStudent);
				}
				fileReader.close();
			}
			else {
				cerr << "\n" << INDENT << "Input file: input.dat wasn't found.\n";
			}
            cout << "\n\t" << "The vector now has " << studentDat.size() << " elements. " << "\n\n";
			for (int i = 0; i < studentDat.size();i++) {
				cout << INDENT << "[" <<i <<  "]" << ": " << studentDat[i] << endl;
			}
            cout << "\n";
			break;
		case 'E':
            cout << "\n" << INDENT;
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                cout << "Element [" << studentDat.size() - 1 << "]: " << studentDat.back() << ", has been removed from the vector. \n\n";
                studentDat.pop_back();
                cout << INDENT << "The vector now has " << studentDat.size() << " elements. \n\n";
                for (int i = 0; i < studentDat.size();i++) {
                    cout << INDENT << "[" << i << "]" << ": " << studentDat[i] << endl;
                }
            }
            cout << "\n";
			break;
		case 'F':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                cout << "\n\n" << INDENT << "The element from the front of the vector: [0] " << studentDat.front() << "\n\n";
            }
			break;
		case 'G':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                cout << "\n\n" << INDENT << "The element from the back of the vector: [" << studentDat.size() - 1 << "] " << studentDat.back() << "\n\n";
            }
			break;
		case 'H':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                printf("\n\tEnter the index (0...%d):", ((int)studentDat.size() - 1));
                tempVar = inputInteger("", 0, (int)studentDat.size() - 1);
                cout << "\n\t" << "vector.at(" << tempVar << "): " << studentDat.at(tempVar);
                cout << "\n\t" << "Vector[" << tempVar << "]: " << studentDat[tempVar] << "\n\n";
            }
			break;
		case 'I':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                tempIter = studentDat.begin();
                cout << "\n\t" << "The iterator referring the first element: " << &tempIter << "(" << *tempIter << ")\n\n";
            }
			break;
		case 'J':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                tempIter = studentDat.end();
                cout << "\n\t" << "The iterator referring the past-the-end element: " << &tempIter << "\n\n";
            }
            break;
		case 'K':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                cout << "\n\t" << "using begin() and end(), the vector contains: \n";
                for (auto iter = studentDat.begin();iter != studentDat.end();iter++) {
                    cout << INDENT << INDENT << &iter << "(" << *iter << ")\n";
                }
                cout << "\n";
            }
			break;
		case 'L':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                tempReverseIter = studentDat.rbegin();
                cout << "\n\t" << "The reverse iterator pointing to the last element: " << &tempReverseIter << "(" << *tempReverseIter << ")\n\n";
            }
            break;
		case 'M':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                tempReverseIter = studentDat.rend();
                cout << "\n\t" << "The reverse iterator pointing to the theoretical element preceding the first element in the vector: " << &tempReverseIter << "\n\n";
            }
			break;
		case 'N':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                cout << "\n\t" << "Using rbegin() and rend(), the vector contains reversed elements: \n";
                for (auto reverse_iter = studentDat.rbegin();reverse_iter != studentDat.rend();reverse_iter++) {
                    cout << "\t\t" << &reverse_iter << "(" << *reverse_iter << ")\n";
                }
                cout << "\n";
            }
			break;
		case 'O':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                tempIter = studentDat.begin();
                studentDat.erase(tempIter + 1);
                cout << "\n\tAn Element after the begin iterator " << &tempIter << " has been removed.\n\n";
            }
            
			break;
		case 'P':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                tempIter = studentDat.begin();
                cout << "\n\tAll elements starting at begin iterator " << &tempIter;
                tempIter = studentDat.end();
                cout << " and going up to end iterator " << &tempIter << " have been removed.\n\n";
                studentDat.erase(studentDat.begin(), studentDat.end());
            }
			break;
		case 'Q':
           
            cout << "\n\n";
            tempName = inputString("\tEnter student name: ", true);
            tempYear = (string() + (char)('0'+inputInteger("\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior):", 1, 4)));
            gpa = inputDouble("\tEnter his/her GPA (0.0...4.0):", 0.0, 4.0);
            newStudent.setName(tempName);
            newStudent.setGradeLevel(tempYear);
            newStudent.setGPA(gpa);

            if (studentDat.size() >= 1) {
                cout << "\n\t" << "The new element has been inserted after the begin iterator.\n\n";
                studentDat.insert(studentDat.begin()+1, newStudent);
            }
            else {
                cout << "\n\t" << "The new element has been inserted at the begin iterator. \n\n";
                studentDat.push_back(newStudent);
            }
			break;
		case 'R':
            cout << "\n\t" << "Vector (V2) is initially empty. \n\n";
            cout << "\t" << "Vector (V1) is empty after swapped with vector (V2) \n\n";
            cout << "\t" << "Vector (V2) after being swapped with vector (V1)\n\n";
            v2.swap(studentDat);
            if (!v2.empty()) {
                for (int i = 0; i < v2.size();i++) {
                    cout << INDENT << "[" << i << "]: " << v2[i] << endl;
                }
            }
			break;
		case 'S':
            if (studentDat.empty()) {
                cout << "\n\tVector is empty. \n\n";
            }
            else {
                cout << "\n\t" << "Vector has been sorted:\n\n";
                std::sort(studentDat.begin(), studentDat.end());
                for (int i = 0; i < studentDat.size();i++) {
                    cout << INDENT << "[" << i << "]: " << studentDat[i] << endl;
                }
                cout << "\n\n";
            }

			break;
		default:
			cout << INDENT << "Sending you back to main menu...\n\n";
			endProgram = true;
			break;
		}
		system("pause");
	} while (!endProgram);

}

//precondition: valid string to split
//postcondition: vector split by the delimiter. 
vector<string> split(const string& target, const char delimiter) {
	string tempStr = "";
	vector<string> tokens;
	auto flush = [&]()->void {
		if (!tempStr.empty()) {
			tokens.push_back(tempStr);
			tempStr.clear();
		}
		};
	for (char c : target) {
		if (c == delimiter) {
			flush();
		}
		else {
			tempStr += c;
		}
	}
	flush();
	return tokens;
}



int listAndVectorMenu() {
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

void optionThree()
{
	applicationList list;
	do {
		switch (listAndVectorMenu()) {

        case 0: return;
		case 1: {
			int n = inputInteger("\nAdd an integer: ");
			list.add(n);
			cout << "\n\tInteger added: " << n << "\n";
			system("pause");
			break;
		}
		case 2: {
			int n = inputInteger("\nDelete an integer: ");

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
}



void optionTwo()
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
                int startPos = inputInteger("\n\tEnter the starting position (0-based): ", 0, (int)container.size() - 1);
                int endPos = inputInteger("\n\tEnter the ending position (0-based, greater than start): ",(int) startPos + 1, (int)container.size());

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
    } while (true);


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
