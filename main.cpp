#include <iostream>
#include <string>
#include <iomanip> // For setw
using namespace std;

int main() {
	const int MAX = 100;
	string name[MAX], fatherName[MAX], cnic[MAX], gender[MAX];
	string address[MAX], contact[MAX], field[MAX], level[MAX], program[MAX];
	int age[MAX], interMarks[MAX];
	string semester[MAX], department[MAX];
	float gpa[MAX];
	int studentID[MAX];
	string hostel[MAX], transport[MAX];

	int totalStudents = 0;
	int idCounter = 1;

	while (true) {
		system("cls");
		cout << "\n\t\t\t\t\t\t\t===== STUDENT MANAGEMENT SYSTEM =====" << endl;
		cout << "\n\n\n-----MAIN MENU -----\n\n";
		cout << "1. Student\n\n2. Admin\n\n3. Exit\n\n";
		cout << "Enter your choice: ";
		string input;
		getline(cin, input);

		// Convert input to lowercase for case-insensitive comparison
		for (int i = 0; input[i]; i++) {
			if (input[i] >= 'A' && input[i] <= 'Z') {
				input[i] = input[i] + 32;
			}
		}

		if (input == "1" || input == "s" || input == "student") {
			while (true) {
				system("cls");
				cout << "\n\n\n-- Student Level Selection --\n\n";
				cout << "1. Undergraduate\n\n2. Graduate\n\n3. Postgraduate\n\n4. Back\n\n";
				cout << "Enter choice: ";
				string levelChoice;
				getline(cin, levelChoice);

				// Convert to lowercase
				for (int i = 0; levelChoice[i]; i++) {
					if (levelChoice[i] >= 'A' && levelChoice[i] <= 'Z') {
						levelChoice[i] += 32;
					}
				}

				if (levelChoice == "1" || levelChoice == "u" || levelChoice == "undergraduate") {
					string selectedLevel = "Undergraduate";
					while (true) {
						system("cls");
						cout << "\n\n-- Program Selection --\n\n";
						cout << "1. AI\n\n2. CS\n\n3. SE\n\n4. DS\n\n5. Back\n\n";
						cout << "Enter choice: ";
						string programChoice;
						getline(cin, programChoice);

						// Convert to lowercase
						for (int i = 0; programChoice[i]; i++) {
							if (programChoice[i] >= 'A' && programChoice[i] <= 'Z') {
								programChoice[i] += 32;
							}
						}

						string selectedProgram;
						if (programChoice == "1" || programChoice == "ai") {
							selectedProgram = "AI";
						}
						else if (programChoice == "2" || programChoice == "cs") {
							selectedProgram = "CS";
						}
						else if (programChoice == "3" || programChoice == "se") {
							selectedProgram = "SE";
						}
						else if (programChoice == "4" || programChoice == "ds") {
							selectedProgram = "DS";
						}
						else if (programChoice == "5" || programChoice == "b" || programChoice == "back") {
							break;
						}
						else {
							cout << "\nInvalid choice. Press Enter to try again...";
							cin.ignore();
							continue;
						}

						system("cls");
						cout << "\n\n--- Enter Student Information ---\n";

						// Name (with validation)
						while (true) {
							cout << "\nName:";
							getline(cin, name[totalStudents]);
							bool valid = true;
							for (int i = 0; name[totalStudents][i]; i++) {
								char c = name[totalStudents][i];
								if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
									valid = false;
									break;
								}
							}
							if (valid && name[totalStudents][0] != '\0') {
								break;
							}
							cout << "\nInvalid name. Only alphabets and spaces allowed. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Student Information ---\n\n";
						}

						// Father's Name (with validation)
						while (true) {
							cout << "\nFather's Name: ";
							getline(cin, fatherName[totalStudents]);
							bool valid = true;
							for (int i = 0; fatherName[totalStudents][i]; i++) {
								char c = fatherName[totalStudents][i];
								if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
									valid = false;
									break;
								}
							}
							if (valid && fatherName[totalStudents][0] != '\0') {
								break;
							}
							cout << "\nInvalid father's name. Only alphabets and spaces allowed. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
						}

						// CNIC (with validation)
						while (true) {
							cout << "\nCNIC (13 digits without dashes): ";
							getline(cin, cnic[totalStudents]);
							bool valid = true;
							int digits = 0;
							for (int i = 0; cnic[totalStudents][i]; i++) {
								if (cnic[totalStudents][i] < '0' || cnic[totalStudents][i] > '9') {
									valid = false;
									break;
								}
								digits++;
							}
							if (valid && digits == 13) {
								break;
							}
							cout << "\nInvalid CNIC. Must be exactly 13 digits. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
						}

						// Gender (with validation)
						while (true) {
							cout << "\nGender (M/F): ";
							getline(cin, gender[totalStudents]);
							if (gender[totalStudents][0] && !gender[totalStudents][1]) {
								char g = gender[totalStudents][0];
								if (g >= 'A' && g <= 'Z') {
									g += 32;
								}
								if (g == 'm') {
									gender[totalStudents] = "Male";
									break;
								}
								else if (g == 'f') {
									gender[totalStudents] = "Female";
									break;
								}
							}
							cout << "\nInvalid gender input. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
						}

						// Address
						cout << "\nAddress: ";
						getline(cin, address[totalStudents]);

						// Age (with validation)
						while (true) {
							cout << "\nAge: ";
							string ageInput;
							getline(cin, ageInput);
							bool valid = true;
							for (int i = 0; ageInput[i]; i++) {
								if (ageInput[i] < '0' || ageInput[i] > '9') {
									valid = false;
									break;
								}
							}
							if (valid && ageInput[0] != '\0') {
								age[totalStudents] = 0;
								for (int i = 0; ageInput[i]; i++) {
									age[totalStudents] = age[totalStudents] * 10 + (ageInput[i] - '0');
								}
								if (age[totalStudents] > 0) break;
							}
							cout << "\nInvalid age. Please enter a positive number. Press Enter to continue...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
						}

						// Contact (with validation)
						while (true) {
							cout << "\nContact Number (11 digits): ";
							getline(cin, contact[totalStudents]);
							bool valid = true;
							int digits = 0;
							for (int i = 0; contact[totalStudents][i]; i++) {
								if (contact[totalStudents][i] < '0' || contact[totalStudents][i] > '9') {
									valid = false;
									break;
								}
								digits++;
							}
							if (valid && digits == 11) {
								break;
							}
							cout << "\nInvalid contact number. Must be exactly 11 digits. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
						}

						// Intermediate Marks (with validation)
						while (true) {
							cout << "\nIntermediate Marks (out of 1200): ";
							string marksInput;
							getline(cin, marksInput);
							bool valid = true;
							for (int i = 0; marksInput[i]; i++) {
								if (marksInput[i] < '0' || marksInput[i] > '9') {
									valid = false;
									break;
								}
							}
							if (valid && marksInput[0] != '\0') {
								interMarks[totalStudents] = 0;
								for (int i = 0; marksInput[i]; i++) {
									interMarks[totalStudents] = interMarks[totalStudents] * 10 + (marksInput[i] - '0');
								}
								if (interMarks[totalStudents] >= 0 && interMarks[totalStudents] <= 1200) {
									gpa[totalStudents] = -1;
									break;
								}
								else if (interMarks[totalStudents] > 1200) {
									cout << "\nObtained marks cannot be greater than total marks (1200). ";
								}
							}
							cout << "\nInvalid marks. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
							cout << "\nContact: " << contact[totalStudents] << endl;
						}

						// Hostel (with validation)
						while (true) {
							cout << "\nRequire Hostel (Y/N/1/0): ";
							getline(cin, hostel[totalStudents]);
							if (hostel[totalStudents][0] && !hostel[totalStudents][1]) {
								char h = hostel[totalStudents][0];
								if (h >= 'A' && h <= 'Z') {
									h += 32;
								}
								if (h == 'y' || h == '1' || h == 'yes') {
									hostel[totalStudents] = "Yes";
									break;
								}
								else if (h == 'n' || h == '0' || h == 'no') {
									hostel[totalStudents] = "No";
									break;
								}
							}
							cout << "Invalid input. Please enter Y/N or 1/0. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
							cout << "\nContact: " << contact[totalStudents] << endl;
							cout << "\nIntermediate Marks: " << interMarks[totalStudents] << "/1200" << endl;
						}

						// Transport (with validation)
						while (true) {
							cout << "\nRequire Transport (Y/N/1/0): ";
							getline(cin, transport[totalStudents]);
							if (transport[totalStudents][0] && !transport[totalStudents][1]) {
								char t = transport[totalStudents][0];
								if (t >= 'A' && t <= 'Z') {
									t += 32;
								}
								if (t == 'y' || t == '1') {
									transport[totalStudents] = "Yes";
									break;
								}
								else if (t == 'n' || t == '0') {
									transport[totalStudents] = "No";
									break;
								}
							}
							cout << "\nInvalid input. Please enter Y/N or 1/0. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
							cout << "\nContact: " << contact[totalStudents] << endl;
							cout << "\nIntermediate Marks: " << interMarks[totalStudents] << "/1200" << endl;
							cout << "\nHostel: " << hostel[totalStudents] << endl;
						}

						// Assign remaining fields
						studentID[totalStudents] = idCounter++;
						program[totalStudents] = selectedProgram;
						level[totalStudents] = selectedLevel;
						semester[totalStudents] = "1st";
						department[totalStudents] = "FOIT";
						field[totalStudents] = selectedProgram;

						totalStudents++;

						cout << "\nStudent added successfully!\n";
						cout << "\nPress Enter to return to Main Menu...";
						cin.ignore();
						break;
					}
					break;
				}
				else if (levelChoice == "2" || levelChoice == "g" || levelChoice == "graduate") {
					string selectedLevel = "Graduate";
					while (true) {
						system("cls");
						cout << "\n\n-- Graduate Program Selection --\n\n";
						cout << "1. AI\n\n2. CS\n\n3. SE\n\n4. DS\n\n5. Back\n\n";
						cout << "\nEnter choice: ";
						string programChoice;
						getline(cin, programChoice);

						// Convert to lowercase
						for (int i = 0; programChoice[i]; i++) {
							if (programChoice[i] >= 'A' && programChoice[i] <= 'Z') {
								programChoice[i] += 32;
							}
						}

						string selectedProgram;
						if (programChoice == "1" || programChoice == "ai") {
							selectedProgram = "AI";
						}
						else if (programChoice == "2" || programChoice == "cs") {
							selectedProgram = "CS";
						}
						else if (programChoice == "3" || programChoice == "se") {
							selectedProgram = "SE";
						}
						else if (programChoice == "4" || programChoice == "ds") {
							selectedProgram = "DS";
						}
						else if (programChoice == "5" || programChoice == "b" || programChoice == "back") {
							break;
						}
						else {
							cout << "\n\nInvalid program choice. Press Enter to try again...";
							cin.ignore();
							continue;
						}

						system("cls");
						cout << "\n\n--- Enter Graduate Student Information ---\n\n";

						// Name (with validation)
						while (true) {
							cout << "\nName: ";
							getline(cin, name[totalStudents]);
							bool valid = true;
							for (int i = 0; name[totalStudents][i]; i++) {
								char c = name[totalStudents][i];
								if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
									valid = false;
									break;
								}
							}
							if (valid && name[totalStudents][0] != '\0') {
								break;
							}
							cout << "\n\nInvalid name. Only alphabets and spaces allowed. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Graduate Student Information ---\n";
						}

						// Father's Name (with validation)
						while (true) {
							cout << "\nFather's Name: ";
							getline(cin, fatherName[totalStudents]);
							bool valid = true;
							for (int i = 0; fatherName[totalStudents][i]; i++) {
								char c = fatherName[totalStudents][i];
								if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
									valid = false;
									break;
								}
							}
							if (valid && fatherName[totalStudents][0] != '\0') {
								break;
							}
							cout << "\nInvalid father's name. Only alphabets and spaces allowed. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Graduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
						}

						// CNIC (with validation)
						while (true) {
							cout << "\nCNIC (13 digits without dashes): ";
							getline(cin, cnic[totalStudents]);
							bool valid = true;
							int digits = 0;
							for (int i = 0; cnic[totalStudents][i]; i++) {
								if (cnic[totalStudents][i] < '0' || cnic[totalStudents][i] > '9') {
									valid = false;
									break;
								}
								digits++;
							}
							if (valid && digits == 13) {
								break;
							}
							cout << "\nInvalid CNIC. Must be exactly 13 digits. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Graduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
						}

						// Gender (with validation)
						while (true) {
							cout << "\nGender (M/F): ";
							getline(cin, gender[totalStudents]);
							if (gender[totalStudents][0] && !gender[totalStudents][1]) {
								char g = gender[totalStudents][0];
								if (g >= 'A' && g <= 'Z') {
									g += 32;
								}
								if (g == 'm' || g == 'male' || g == 'MALE') {
									gender[totalStudents] = "Male";
									break;
								}
								else if (g == 'f' || g == 'F') {
									gender[totalStudents] = "Female";
									break;
								}
							}
							cout << "\nInvalid gender input. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Graduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
						}

						// Address
						cout << "\nAddress: ";
						getline(cin, address[totalStudents]);

						// Age (with validation)
						while (true) {
							cout << "\nAge: ";
							string ageInput;
							getline(cin, ageInput);
							bool valid = true;
							for (int i = 0; ageInput[i]; i++) {
								if (ageInput[i] < '0' || ageInput[i] > '9') {
									valid = false;
									break;
								}
							}
							if (valid && ageInput[0] != '\0') {
								age[totalStudents] = 0;
								for (int i = 0; ageInput[i]; i++) {
									age[totalStudents] = age[totalStudents] * 10 + (ageInput[i] - '0');
								}
								if (age[totalStudents] > 0) break;
							}
							cout << "\nInvalid age. Please enter a positive number. Press Enter to continue...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Graduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
						}

						// Contact (with validation)
						while (true) {
							cout << "\nContact Number (11 digits): ";
							getline(cin, contact[totalStudents]);
							bool valid = true;
							int digits = 0;
							for (int i = 0; contact[totalStudents][i]; i++) {
								if (contact[totalStudents][i] < '0' || contact[totalStudents][i] > '9') {
									valid = false;
									break;
								}
								digits++;
							}
							if (valid && digits == 11) {
								break;
							}
							cout << "\nInvalid contact number. Must be exactly 11 digits. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Graduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
						}

						// CGPA validation for graduate
						interMarks[totalStudents] = -1; // Not applicable for graduate
						while (true) {
							cout << "\nEnter CGPA (0.0-4.0): ";
							string gpaInput;
							getline(cin, gpaInput);
							bool valid = true;
							bool hasDecimal = false;
							for (int i = 0; gpaInput[i]; i++) {
								if ((gpaInput[i] < '0' || gpaInput[i] > '9') && gpaInput[i] != '.') {
									valid = false;
									break;
								}
								if (gpaInput[i] == '.') {
									if (hasDecimal) {
										valid = false;
										break;
									}
									hasDecimal = true;
								}
							}
							if (valid && gpaInput[0] != '\0') {
								gpa[totalStudents] = 0;
								float decimalPlace = 0.1;
								bool afterDecimal = false;
								for (int i = 0; gpaInput[i]; i++) {
									if (gpaInput[i] == '.') {
										afterDecimal = true;
										continue;
									}
									if (!afterDecimal) {
										gpa[totalStudents] = gpa[totalStudents] * 10 + (gpaInput[i] - '0');
									}
									else {
										gpa[totalStudents] += (gpaInput[i] - '0') * decimalPlace;
										decimalPlace /= 10;
									}
								}
								if (gpa[totalStudents] >= 0.0 && gpa[totalStudents] <= 4.0) break;
							}
							cout << "\nInvalid CGPA (must be 0.0-4.0). Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Graduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
							cout << "\nContact: " << contact[totalStudents] << endl;
						}

						// Hostel (with validation)
						while (true) {
							cout << "\nRequire Hostel (Y/N/1/0): ";
							getline(cin, hostel[totalStudents]);
							if (hostel[totalStudents][0] && !hostel[totalStudents][1]) {
								char h = hostel[totalStudents][0];
								if (h >= 'A' && h <= 'Z') {
									h += 32;
								}
								if (h == 'y' || h == '1' || h == 'yes') {
									hostel[totalStudents] = "Yes";
									break;
								}
								else if (h == 'n' || h == '0' || h == 'no') {
									hostel[totalStudents] = "No";
									break;
								}
							}
							cout << "\nInvalid input. Please enter Y/N or 1/0. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Graduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
							cout << "\nContact: " << contact[totalStudents] << endl;
							cout << "\nCGPA: " << gpa[totalStudents] << endl;
						}

						// Transport (with validation)
						while (true) {
							cout << "\nRequire Transport (Y/N/1/0): ";
							getline(cin, transport[totalStudents]);
							if (transport[totalStudents][0] && !transport[totalStudents][1]) {
								char t = transport[totalStudents][0];
								if (t >= 'A' && t <= 'Z') {
									t += 32;
								}
								if (t == 'y' || t == '1' || t == 'yes' || t == 'YES') {
									transport[totalStudents] = "Yes";
									break;
								}
								else if (t == 'n' || t == '0' || t == 'no' || t == 'NO') {
									transport[totalStudents] = "No";
									break;
								}
							}
							cout << "\nInvalid input. Please enter Y/N or 1/0. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Graduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
							cout << "\nContact: " << contact[totalStudents] << endl;
							cout << "\nCGPA: " << gpa[totalStudents] << endl;
							cout << "\nHostel: " << hostel[totalStudents] << endl;
						}

						// Assign remaining fields
						studentID[totalStudents] = idCounter++;
						program[totalStudents] = selectedProgram;
						level[totalStudents] = selectedLevel;
						semester[totalStudents] = "1st";
						department[totalStudents] = "FOIT";
						field[totalStudents] = selectedProgram;

						totalStudents++;

						cout << "\n\nGraduate student added successfully!\n";
						cout << "\nPress Enter to return to Main Menu...";
						cin.ignore();
						break;
					}
					break;
				}
				else if (levelChoice == "3" || levelChoice == "p" || levelChoice == "postgraduate") {
					string selectedLevel = "Postgraduate";
					while (true) {
						system("cls");
						cout << "\n\n-- Postgraduate Program Selection --\n";
						cout << "1. AI\n\n2. CS\n\n3. SE\n\n4. DS\n\n5. Back\n\n";
						cout << "\nEnter choice: ";
						string programChoice;
						getline(cin, programChoice);

						// Convert to lowercase
						for (int i = 0; programChoice[i]; i++) {
							if (programChoice[i] >= 'A' && programChoice[i] <= 'Z') {
								programChoice[i] += 32;
							}
						}

						string selectedProgram;
						if (programChoice == "1" || programChoice == "ai") {
							selectedProgram = "AI";
						}
						else if (programChoice == "2" || programChoice == "cs") {
							selectedProgram = "CS";
						}
						else if (programChoice == "3" || programChoice == "se") {
							selectedProgram = "SE";
						}
						else if (programChoice == "4" || programChoice == "ds") {
							selectedProgram = "DS";
						}
						else if (programChoice == "5" || programChoice == "b" || programChoice == "back") {
							break;
						}
						else {
							cout << "\nInvalid program choice. Press Enter to try again...";
							cin.ignore();
							continue;
						}

						system("cls");
						cout << "\n\n--- Enter Postgraduate Student Information ---\n";

						// Name (with validation)
						while (true) {
							cout << "\nName: ";
							getline(cin, name[totalStudents]);
							bool valid = true;
							for (int i = 0; name[totalStudents][i]; i++) {
								char c = name[totalStudents][i];
								if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
									valid = false;
									break;
								}
							}
							if (valid && name[totalStudents][0] != '\0') {
								break;
							}
							cout << "\nInvalid name. Only alphabets and spaces allowed. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Postgraduate Student Information ---\n";
						}

						// Father's Name (with validation)
						while (true) {
							cout << "\nFather's Name: ";
							getline(cin, fatherName[totalStudents]);
							bool valid = true;
							for (int i = 0; fatherName[totalStudents][i]; i++) {
								char c = fatherName[totalStudents][i];
								if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
									valid = false;
									break;
								}
							}
							if (valid && fatherName[totalStudents][0] != '\0') {
								break;
							}
							cout << "\nInvalid father's name. Only alphabets and spaces allowed. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Postgraduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
						}

						// CNIC (with validation)
						while (true) {
							cout << "\nCNIC (13 digits without dashes): ";
							getline(cin, cnic[totalStudents]);
							bool valid = true;
							int digits = 0;
							for (int i = 0; cnic[totalStudents][i]; i++) {
								if (cnic[totalStudents][i] < '0' || cnic[totalStudents][i] > '9') {
									valid = false;
									break;
								}
								digits++;
							}
							if (valid && digits == 13) {
								break;
							}
							cout << "\nInvalid CNIC. Must be exactly 13 digits. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Postgraduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
						}

						// Gender (with validation)
						while (true) {
							cout << "\nGender (M/F): ";
							getline(cin, gender[totalStudents]);
							if (gender[totalStudents][0] && !gender[totalStudents][1]) {
								char g = gender[totalStudents][0];
								if (g >= 'A' && g <= 'Z') {
									g += 32;
								}
								if (g == 'm' || g == 'male' || g == 'MALE') {
									gender[totalStudents] = "Male";
									break;
								}
								else if (g == 'f') {
									gender[totalStudents] = "Female";
									break;
								}
							}
							cout << "\nInvalid gender input. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Postgraduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
						}

						// Address
						cout << "\nAddress: ";
						getline(cin, address[totalStudents]);

						// Age (with validation)
						while (true) {
							cout << "\nAge: ";
							string ageInput;
							getline(cin, ageInput);
							bool valid = true;
							for (int i = 0; ageInput[i]; i++) {
								if (ageInput[i] < '0' || ageInput[i] > '9') {
									valid = false;
									break;
								}
							}
							if (valid && ageInput[0] != '\0') {
								age[totalStudents] = 0;
								for (int i = 0; ageInput[i]; i++) {
									age[totalStudents] = age[totalStudents] * 10 + (ageInput[i] - '0');
								}
								if (age[totalStudents] > 0) break;
							}
							cout << "\nInvalid age. Please enter a positive number. Press Enter to continue...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Postgraduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
						}

						// Contact (with validation)
						while (true) {
							cout << "\nContact Number (11 digits): ";
							getline(cin, contact[totalStudents]);
							bool valid = true;
							int digits = 0;
							for (int i = 0; contact[totalStudents][i]; i++) {
								if (contact[totalStudents][i] < '0' || contact[totalStudents][i] > '9') {
									valid = false;
									break;
								}
								digits++;
							}
							if (valid && digits == 11) {
								break;
							}
							cout << "\nInvalid contact number. Must be exactly 11 digits. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Postgraduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
						}

						// CGPA validation for postgraduate
						interMarks[totalStudents] = -1; // Not applicable for postgraduate
						while (true) {
							cout << "\nEnter CGPA (0.0-4.0): ";
							string gpaInput;
							getline(cin, gpaInput);
							bool valid = true;
							bool hasDecimal = false;
							for (int i = 0; gpaInput[i]; i++) {
								if ((gpaInput[i] < '0' || gpaInput[i] > '9') && gpaInput[i] != '.') {
									valid = false;
									break;
								}
								if (gpaInput[i] == '.') {
									if (hasDecimal) {
										valid = false;
										break;
									}
									hasDecimal = true;
								}
							}
							if (valid && gpaInput[0] != '\0') {
								gpa[totalStudents] = 0;
								float decimalPlace = 0.1;
								bool afterDecimal = false;
								for (int i = 0; gpaInput[i]; i++) {
									if (gpaInput[i] == '.') {
										afterDecimal = true;
										continue;
									}
									if (!afterDecimal) {
										gpa[totalStudents] = gpa[totalStudents] * 10 + (gpaInput[i] - '0');
									}
									else {
										gpa[totalStudents] += (gpaInput[i] - '0') * decimalPlace;
										decimalPlace /= 10;
									}
								}
								if (gpa[totalStudents] >= 0.0 && gpa[totalStudents] <= 4.0) break;
							}
							cout << "\nInvalid CGPA (must be 0.0-4.0). Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Postgraduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
							cout << "\nContact: " << contact[totalStudents] << endl;
						}

						// Hostel (with validation)
						while (true) {
							cout << "\nRequire Hostel (Y/N/1/0): ";
							getline(cin, hostel[totalStudents]);
							if (hostel[totalStudents][0] && !hostel[totalStudents][1]) {
								char h = hostel[totalStudents][0];
								if (h >= 'A' && h <= 'Z') {
									h += 32;
								}
								if (h == 'y' || h == '1') {
									hostel[totalStudents] = "Yes";
									break;
								}
								else if (h == 'n' || h == '0') {
									hostel[totalStudents] = "No";
									break;
								}
							}
							cout << "\nInvalid input. Please enter Y/N or 1/0. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n\n--- Enter Postgraduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
							cout << "\nContact: " << contact[totalStudents] << endl;
							cout << "\nCGPA: " << gpa[totalStudents] << endl;
						}

						// Transport (with validation)
						while (true) {
							cout << "\nRequire Transport (Y/N/1/0): ";
							getline(cin, transport[totalStudents]);
							if (transport[totalStudents][0] && !transport[totalStudents][1]) {
								char t = transport[totalStudents][0];
								if (t >= 'A' && t <= 'Z') {
									t += 32;
								}
								if (t == 'y' || t == '1' || t == 'yes') {
									transport[totalStudents] = "Yes";
									break;
								}
								else if (t == 'n' || t == '0' || t == 'no') {
									transport[totalStudents] = "No";
									break;
								}
							}
							cout << "\nInvalid input. Please enter Y/N or 1/0. Press Enter to try again...";
							cin.ignore();
							system("cls");
							cout << "\n--- Enter Postgraduate Student Information ---\n";
							cout << "\nName: " << name[totalStudents] << endl;
							cout << "\nFather's Name: " << fatherName[totalStudents] << endl;
							cout << "\nCNIC: " << cnic[totalStudents] << endl;
							cout << "\nGender: " << gender[totalStudents] << endl;
							cout << "\nAddress: " << address[totalStudents] << endl;
							cout << "\nAge: " << age[totalStudents] << endl;
							cout << "\nContact: " << contact[totalStudents] << endl;
							cout << "\nCGPA: " << gpa[totalStudents] << endl;
							cout << "\nHostel: " << hostel[totalStudents] << endl;
						}

						// Assign remaining fields
						studentID[totalStudents] = idCounter++;
						program[totalStudents] = selectedProgram;
						level[totalStudents] = selectedLevel;
						semester[totalStudents] = "1st";
						department[totalStudents] = "FOIT";
						field[totalStudents] = selectedProgram;

						totalStudents++;

						cout << "\nPostgraduate student added successfully!\n";
						cout << "\nPress Enter to return to Main Menu...";
						cin.ignore();
						break;
					}
					break;
				}
				else if (levelChoice == "4" || levelChoice == "b" || levelChoice == "back") {
					break;
				}
				else {
					cout << "\nInvalid choice. Press Enter to try again...";
					cin.ignore();
				}
			}
		}
		else if (input == "2" || input == "a" || input == "admin") {
			system("cls");
			string adminID, adminPass;
			cout << "Enter Admin ID: ";
			getline(cin, adminID);
			cout << "Enter Password: ";
			getline(cin, adminPass);

			if (adminID == "admin" && adminPass == "1234") {
				while (true) {
					system("cls");
					cout << "\n-- Admin Panel --\n";
					cout << "\n1. Display All Students\n";
					cout << "\n2. Search by Name\n";
					cout << "\n3. Update Student\n";
					cout << "\n4. Remove Student\n";
					cout << "\n5. Back to Main Menu\n";
					cout << "\n\nEnter choice: ";
					string adminChoice;
					getline(cin, adminChoice);

					if (adminChoice == "1") {
						system("cls");
						if (totalStudents == 0) {
							cout << "\nNo student records available.\n";
						}
						else {
							cout << "\n" << string(100, '-') << "\n";
							cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Semester"
								<< setw(10) << "Dept" << setw(10) << "Field" << setw(15) << "Level"
								<< setw(15) << "Scholarship" << "\n";
							cout << string(100, '-') << "\n";

							for (int i = 0; i < totalStudents; i++) {
								cout << left << setw(10) << studentID[i]
									<< setw(20) << name[i].substr(0, 20)
									<< setw(10) << semester[i]
									<< setw(10) << department[i]
									<< setw(10) << field[i]
									<< setw(15) << level[i];

								string scholarship;
								if (level[i] == "Undergraduate") {
									float perc = (interMarks[i] / 1200.0f) * 100;
									if (perc >= 85) scholarship = "100%";
									else if (perc >= 80) scholarship = "75%";
									else if (perc >= 75) scholarship = "50%";
									else if (perc >= 70) scholarship = "25%";
									else scholarship = "None";
								}
								else {
									if (gpa[i] >= 4.0) scholarship = "100%";
									else if (gpa[i] >= 3.75) scholarship = "75%";
									else if (gpa[i] >= 3.5) scholarship = "50%";
									else if (gpa[i] >= 3.2) scholarship = "25%";
									else scholarship = "None";
								}

								cout << setw(15) << scholarship << endl;
							}
							cout << string(100, '-') << "\n";
						}
						cout << "\n\nPress Enter to return to Admin Panel...";
						cin.ignore();
					}
					else if (adminChoice == "2") {
						cout << "\n\nEnter student name to search: ";
						string searchName;
						getline(cin, searchName);
						bool found = false;
						for (int i = 0; i < totalStudents; i++) {
							// Convert both to lowercase for case-insensitive search
							bool match = true;
							for (int j = 0; searchName[j] && name[i][j]; j++) {
								char c1 = searchName[j];
								char c2 = name[i][j];
								if (c1 >= 'A' && c1 <= 'Z') c1 += 32;
								if (c2 >= 'A' && c2 <= 'Z') c2 += 32;
								if (c1 != c2) {
									match = false;
									break;
								}
							}
							if (match) {
								found = true;
								cout << "\nStudent Found:\n";
								cout << "\nID: " << studentID[i] << "\n";
								cout << "\nName: " << name[i] << "\n";
								cout << "\nFather's Name: " << fatherName[i] << "\n";
								cout << "\nCNIC: " << cnic[i] << "\n";
								cout << "\nGender: " << gender[i] << "\n";
								cout << "\nAddress: " << address[i] << "\n";
								cout << "\nAge: " << age[i] << "\n";
								cout << "\nContact: " << contact[i] << "\n";
								cout << "\nLevel: " << level[i] << "\n";
								cout << "\nProgram: " << program[i] << "\n";
								cout << "\nField: " << field[i] << "\n";
								cout << "\nDepartment: " << department[i] << "\n";
								cout << "\nSemester: " << semester[i] << "\n";
								if (level[i] == "Undergraduate") {
									cout << "Intermediate Marks: " << interMarks[i] << "/1200\n";
								}
								else {
									cout << "\nCGPA: " << gpa[i] << "/4.0\n";
								}
								cout << "\nHostel: " << hostel[i] << "\n";
								cout << "\nTransport: " << transport[i] << "\n";
								break;
							}
						}
						if (!found) cout << "\n\nStudent not found.\n";
						cout << "\n\nPress Enter to return to Admin Panel...";
						cin.ignore();
					}
					else if (adminChoice == "3") {
						// Update student
						cout << "\n\nEnter student ID to update: ";
						string idInput;
						getline(cin, idInput);
						bool validID = true;
						for (int i = 0; idInput[i]; i++) {
							if (idInput[i] < '0' || idInput[i] > '9') {
								validID = false;
								break;
							}
						}
						if (validID && idInput[0] != '\0') {
							int id = 0;
							for (int i = 0; idInput[i]; i++) {
								id = id * 10 + (idInput[i] - '0');
							}
							int index = -1;
							for (int i = 0; i < totalStudents; i++) {
								if (studentID[i] == id) {
									index = i;
									break;
								}
							}
							if (index == -1) {
								cout << "\nStudent not found with ID: " << id << endl;
							}
							else {
								cout << "\n\nCurrent student information:\n";
								cout << "\n1. Name: " << name[index] << endl;
								cout << "\n2. Father's Name: " << fatherName[index] << endl;
								cout << "\n3. CNIC: " << cnic[index] << endl;
								cout << "\n4. Gender: " << gender[index] << endl;
								cout << "\n5. Address: " << address[index] << endl;
								cout << "\n6. Age: " << age[index] << endl;
								cout << "\n7. Contact: " << contact[index] << endl;
								if (level[index] == "Undergraduate") {
									cout << "\n8. Intermediate Marks: " << interMarks[index] << endl;
								}
								else {
									cout << "\n8. CGPA: " << gpa[index] << endl;
								}
								cout << "\n9. Hostel: " << hostel[index] << endl;
								cout << "\n10. Transport: " << transport[index] << endl;

								cout << "\n\nEnter field number to update (1-10) or 0 to cancel: ";
								string fieldChoice;
								getline(cin, fieldChoice);
								bool validChoice = true;
								for (int i = 0; fieldChoice[i]; i++) {
									if (fieldChoice[i] < '0' || fieldChoice[i] > '9') {
										validChoice = false;
										break;
									}
								}
								if (validChoice && fieldChoice[0] != '\0') {
									int choice = 0;
									for (int i = 0; fieldChoice[i]; i++) {
										choice = choice * 10 + (fieldChoice[i] - '0');
									}
									if (choice == 0) {
										cout << "\nUpdate cancelled.\n";
									}
									else if (choice >= 1 && choice <= 10) {
										cout << "\nEnter new value: ";
										string newValue;
										getline(cin, newValue);

										switch (choice) {
										case 1:
										{
											bool valid = true;
											for (int i = 0; newValue[i]; i++) {
												char c = newValue[i];
												if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
													valid = false;
													break;
												}
											}
											if (valid && newValue[0] != '\0') {
												name[index] = newValue;
												cout << "\nName updated successfully.\n";
											}
											else {
												cout << "\nInvalid name. Only alphabets and spaces allowed. Update failed.\n";
											}
										}
										break;
										case 2:
										{
											bool valid = true;
											for (int i = 0; newValue[i]; i++) {
												char c = newValue[i];
												if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')) {
													valid = false;
													break;
												}
											}
											if (valid && newValue[0] != '\0') {
												fatherName[index] = newValue;
												cout << "\nFather's name updated successfully.\n";
											}
											else {
												cout << "\nInvalid father's name. Only alphabets and spaces allowed. Update failed.\n";
											}
										}
										break;
										case 3:
										{
											bool valid = true;
											int digits = 0;
											for (int i = 0; newValue[i]; i++) {
												if (newValue[i] < '0' || newValue[i] > '9') {
													valid = false;
													break;
												}
												digits++;
											}
											if (valid && digits == 13) {
												cnic[index] = newValue;
												cout << "\nCNIC updated successfully.\n";
											}
											else {
												cout << "\nInvalid CNIC. Must be exactly 13 digits. Update failed.\n";
											}
										}
										break;
										case 4:
											if (newValue[0] && !newValue[1]) {
												char g = newValue[0];
												if (g >= 'A' && g <= 'Z') {
													g += 32;
												}
												if (g == 'm') {
													gender[index] = "Male";
												}
												else if (g == 'f') {
													gender[index] = "Female";
												}
												else {
													cout << "\nInvalid gender. Update failed.\n";
													break;
												}
												cout << "\nGender updated successfully.\n";
											}
											else {
												cout << "\nInvalid gender. Update failed.\n";
											}
											break;
										case 5: address[index] = newValue; break;
										case 6: {
											bool valid = true;
											for (int i = 0; newValue[i]; i++) {
												if (newValue[i] < '0' || newValue[i] > '9') {
													valid = false;
													break;
												}
											}
											if (valid && newValue[0] != '\0') {
												age[index] = 0;
												for (int i = 0; newValue[i]; i++) {
													age[index] = age[index] * 10 + (newValue[i] - '0');
												}
												cout << "\nAge updated successfully.\n";
											}
											else {
												cout << "\nInvalid age. Update failed.\n";
											}
											break;
										}
										case 7:
										{
											bool valid = true;
											int digits = 0;
											for (int i = 0; newValue[i]; i++) {
												if (newValue[i] < '0' || newValue[i] > '9') {
													valid = false;
													break;
												}
												digits++;
											}
											if (valid && digits == 11) {
												contact[index] = newValue;
												cout << "\nContact updated successfully.\n";
											}
											else {
												cout << "\nInvalid contact. Must be exactly 11 digits. Update failed.\n";
											}
										}
										break;
										case 8:
											if (level[index] == "Undergraduate") {
												bool valid = true;
												for (int i = 0; newValue[i]; i++) {
													if (newValue[i] < '0' || newValue[i] > '9') {
														valid = false;
														break;
													}
												}
												if (valid && newValue[0] != '\0') {
													interMarks[index] = 0;
													for (int i = 0; newValue[i]; i++) {
														interMarks[index] = interMarks[index] * 10 + (newValue[i] - '0');
													}
													if (interMarks[index] >= 0 && interMarks[index] <= 1200) {
														cout << "\nMarks updated successfully.\n";
													}
													else {
														cout << "\nMarks must be between 0-1200. Update failed.\n";
													}
												}
												else {
													cout << "\nInvalid marks. Update failed.\n";
												}
											}
											else {
												bool valid = true;
												bool hasDecimal = false;
												for (int i = 0; newValue[i]; i++) {
													if ((newValue[i] < '0' || newValue[i] > '9') && newValue[i] != '.') {
														valid = false;
														break;
													}
													if (newValue[i] == '.') {
														if (hasDecimal) {
															valid = false;
															break;
														}
														hasDecimal = true;
													}
												}
												if (valid && newValue[0] != '\0') {
													gpa[index] = 0;
													float decimalPlace = 0.1;
													bool afterDecimal = false;
													for (int i = 0; newValue[i]; i++) {
														if (newValue[i] == '.') {
															afterDecimal = true;
															continue;
														}
														if (!afterDecimal) {
															gpa[index] = gpa[index] * 10 + (newValue[i] - '0');
														}
														else {
															gpa[index] += (newValue[i] - '0') * decimalPlace;
															decimalPlace /= 10;
														}
													}
													if (gpa[index] >= 0.0 && gpa[index] <= 4.0) {
														cout << "\nCGPA updated successfully.\n";
													}
													else {
														cout << "\nCGPA must be between 0.0-4.0. Update failed.\n";
													}
												}
												else {
													cout << "\nInvalid CGPA. Update failed.\n";
												}
											}
											break;
										case 9:
											if (newValue[0] && !newValue[1]) {
												char h = newValue[0];
												if (h >= 'A' && h <= 'Z') {
													h += 32;
												}
												if (h == 'y' || h == '1') {
													hostel[index] = "Yes";
													cout << "\nHostel requirement updated successfully.\n";
												}
												else if (h == 'n' || h == '0') {
													hostel[index] = "No";
													cout << "\nHostel requirement updated successfully.\n";
												}
												else {
													cout << "\nInvalid input. Update failed.\n";
												}
											}
											else {
												cout << "\nInvalid input. Update failed.\n";
											}
											break;
										case 10:
											if (newValue[0] && !newValue[1]) {
												char t = newValue[0];
												if (t >= 'A' && t <= 'Z') {
													t += 32;
												}
												if (t == 'y' || t == '1') {
													transport[index] = "Yes";
													cout << "\nTransport requirement updated successfully.\n";
												}
												else if (t == 'n' || t == '0') {
													transport[index] = "No";
													cout << "\nTransport requirement updated successfully.\n";
												}
												else {
													cout << "\nInvalid input. Update failed.\n";
												}
											}
											else {
												cout << "\nInvalid input. Update failed.\n";
											}
											break;
										}
									}
									else {
										cout << "\nInvalid choice. Please enter 0-10.\n";
									}
								}
								else {
									cout << "\nInvalid choice. Please enter a number.\n";
								}
							}
						}
						else {
							cout << "\nInvalid ID. Please enter a number.\n";
						}
						cout << "\nPress Enter to return to Admin Panel...";
						cin.ignore();
					}
					else if (adminChoice == "4") {
						// Remove student
						cout << "\n\nEnter student ID to remove: ";
						string idInput;
						getline(cin, idInput);
						bool validID = true;
						for (int i = 0; idInput[i]; i++) {
							if (idInput[i] < '0' || idInput[i] > '9') {
								validID = false;
								break;
							}
						}
						if (validID && idInput[0] != '\0') {
							int id = 0;
							for (int i = 0; idInput[i]; i++) {
								id = id * 10 + (idInput[i] - '0');
							}
							int index = -1;
							for (int i = 0; i < totalStudents; i++) {
								if (studentID[i] == id) {
									index = i;
									break;
								}
							}
							if (index == -1) {
								cout << "\nStudent not found with ID: " << id << endl;
							}
							else {
								cout << "\nAre you sure you want to remove " << name[index] << " (ID: " << id << ")? (Y/N): ";
								string confirm;
								getline(cin, confirm);
								if (confirm[0] && !confirm[1]) {
									char c = confirm[0];
									if (c >= 'A' && c <= 'Z') {
										c += 32;
									}
									if (c == 'y') {
										// Shift all elements after index to the left
										for (int i = index; i < totalStudents - 1; i++) {
											name[i] = name[i + 1];
											fatherName[i] = fatherName[i + 1];
											cnic[i] = cnic[i + 1];
											gender[i] = gender[i + 1];
											address[i] = address[i + 1];
											contact[i] = contact[i + 1];
											age[i] = age[i + 1];
											interMarks[i] = interMarks[i + 1];
											gpa[i] = gpa[i + 1];
											hostel[i] = hostel[i + 1];
											transport[i] = transport[i + 1];
											studentID[i] = studentID[i + 1];
											program[i] = program[i + 1];
											level[i] = level[i + 1];
											semester[i] = semester[i + 1];
											department[i] = department[i + 1];
											field[i] = field[i + 1];
										}
										totalStudents--;
										cout << "\nStudent removed successfully.\n";
									}
									else {
										cout << "\nRemoval cancelled.\n";
									}
								}
								else {
									cout << "\nInvalid input. Removal cancelled.\n";
								}
							}
						}
						else {
							cout << "\nInvalid ID. Please enter a number.\n";
						}
						cout << "\n\nPress Enter to return to Admin Panel...";
						cin.ignore();
					}
					else if (adminChoice == "5") {
						break;
					}
					else {
						cout << "\nInvalid admin panel choice. Press Enter to try again...";
						cin.ignore();
					}
				}
			}
			else {
				cout << "\nIncorrect admin input. Press Enter to return to Main Menu...";
				cin.ignore();
				cin.get();
			}
		}
		else if (input == "3" || input == "e" || input == "exit") {
			cout << "\nExiting program...\n";
			break;
		}
		else {
			cout << "\nInvalid main menu choice. Press Enter to try again...";
			cin.ignore();
			cin.get();
		}
	}


	return 0;
}