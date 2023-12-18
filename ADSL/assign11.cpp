#include <iostream>
#include <fstream>
#include <string>

using namespace std;


class Student {
	int rollNumber;
	string name;
	string division;
	string address;
public:

	void addStudent() {
		Student student;  //student is object of class Student
		cout << "Enter Roll Number: ";
		cin >> student.rollNumber;

		cin.ignore(); // Ignore the newline character in the input buffer
		//even if user does not give input for a particular field flow continues

		cout << "Enter Name: ";
		getline(cin, student.name);//getline gets the line - name of student 
		cout << "Enter Division: ";//(used for string data type)
		getline(cin, student.division);
		cout << "Enter Address: ";
		getline(cin, student.address);

		ofstream outFile("student_info.txt", ios::app); //name of output(ofsteam)file is outfile
		outFile << student.rollNumber << endl;//app means append
		outFile << student.name << endl;
		outFile << student.division << endl;
		outFile << student.address << endl; //in file

		cout << "Student information added successfully." << endl; //kernel
		outFile.close();
	}

	void deleteStudent() {
		int rollNumber;
		cout << "Enter Roll Number of the student to delete: ";
		cin >> rollNumber;

		ifstream inFile("student_info.txt"); //input stream
		ofstream tempFile("temp.txt"); //output file
		//we make a temporary

		int currentRollNumber;
		bool found = false;

		while (inFile >> currentRollNumber) {
			string name, division, address;
			inFile.ignore(); // Ignore the newline character in the input buffer
			getline(inFile, name);
			getline(inFile, division);
			getline(inFile, address);

			if (currentRollNumber != rollNumber) {   // if roll in file is not equal to inputed roll
				tempFile << currentRollNumber << endl; //agar diff hai toh tempfile mai stud details add karte jana
				tempFile << name << endl;              
				tempFile << division << endl;
				tempFile << address << endl;
			} else {
				found = true;    //agar same so true print hota 
				                 //and uss particular stud ka detail tempfile mai nahi store hota
			}
		}

		inFile.close();
		tempFile.close();
       // all contents of a are present in b except a particular student_info
		remove("student_info.txt");
		rename("temp.txt", "student_info.txt");

		if (found) {
			cout << "Student information deleted successfully." << endl;
		} else {
			cout << "Student not found." << endl;
		}
	}

	void displayStudent() {
		int rollNumber;
		cout << "Enter Roll Number of the student to display: ";
		cin >> rollNumber;

		ifstream inFile("student_info.txt");

		int currentRollNumber;
		bool found = false;

		while (inFile >> currentRollNumber) {
			string name, division, address;
			inFile.ignore();
			getline(inFile, name);
			getline(inFile, division);
			getline(inFile, address);

			if (currentRollNumber == rollNumber) {  
				cout << "Roll Number: " << currentRollNumber << endl;
				cout << "Name: " << name << endl;
				cout << "Division: " << division << endl;
				cout << "Address: " << address << endl;
				found = true;
				break;
			}
		}

		inFile.close();

		if (!found) {
			cout << "Student not found." << endl;
		}
	}
};

int main() {
	int choice;
	Student s;
	do {
		cout << "\n***** Student Information System *****" << endl;
		cout << "1. Add Student" << endl;
		cout << "2. Delete Student" << endl;
		cout << "3. Display Student Information" << endl;
		cout << "4. Quit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			s.addStudent();
			break;
		case 2:
			s.deleteStudent();
			break;
		case 3:
			s.displayStudent();
			break;
		case 4:
			cout << "Exiting program. Goodbye!" << endl;
			break;
		case 5:
			remove("student_info.txt");
			cout<<"file removed";
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	} while (choice != 4);

	return 0;
}