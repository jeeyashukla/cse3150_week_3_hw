#include <iostream>
#include <cstring>   // for strlen, strcpy
#include <string>

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity) {
	if (size >= capacity) {
        throw std::string("List full");
    }
	names[size] = name;
	gpas[size] = gpa;
	size++;
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa) {
	if (gpaPtr != nullptr){
		*gpaPtr = newGpa;
    }
}

// TODO: implement printStudent
void printStudent(const char* name, const double& gpa) {
	std::cout << "Name: " << name << std::endl;
	std::cout << "GPA: " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size) {
	if (size == 0){
		throw std::string("No students");
    }
	double sum = 0.0;
	for (int i = 0; i < size; i++) {
		sum += gpas[i];
	}
	return sum / size;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
		try {
			std::string n;
			std::cout << "Enter student name: ";
			std::cin >> n;
			char* name = new char[n.size() + 1];

			std::strcpy(name, n.c_str());

			double gpa;
			std::cout << "Enter student gpa: ";
			std::cin >> gpa;

			addStudent(name, gpa, names, gpas, size, capacity);
		} catch (std::string error_msg) {
			std::cout << error_msg << std::endl;
			return 1;
		}
                break;
            }
            case 2: {
                // TODO: implement menu logic
		int old_gpa_idx;
		std::cout << "Enter index to change: ";
		std::cin >> old_gpa_idx;
			    
		double new_gpa;
		std::cout << "Enter new GPA: ";
		std::cin >> new_gpa;

		if (old_gpa_idx >= 0 && old_gpa_idx < size) {
    		updateGPA(&gpas[old_gpa_idx], new_gpa);
		} else {
    		std::cout << "Invalid index!" << std::endl;
		}

		break;
            }
            case 3: {
                // TODO: implement menu logic
		for (int i = 0; i < size; i++) {
			printStudent(names[i], gpas[i]);
		}
                break;
            }
            case 4: {
                // TODO: implement menu logic
		try {
			std::cout << "Average GPA: " << averageGPA(gpas, size) << std::endl;
		} catch (std::string error) {
			std::cout << error << std::endl;
		}
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory 
    if (size > 0) {
    	for (int i = 0; i < size; i++) {
		delete[] names[i];
	    }
    }
    return 0;
}
