#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>


using namespace std;

int main() {
    int choice;
    string fileName;
    string input;
    ofstream fileC;
    int array[100];
    int newArray[100];
    int arraySize = 0;
    int newArraySize = 0;

    // Print menu
    cout << "Enter 1 to enter data from keyboard" << endl;
    cout << "Enter 2 to process data from a text file" << endl;
    cin >> choice;

    if (choice == 1) {
        // Get input from user
        cout << "Enter data: ";
        cin >> input;

        // Process data
        cout << "Data entered: " << input << endl;
    }
    else if (choice == 2) {
        // Get file name from user
        cout << "Enter file name: ";
        cin >> fileName;

        // Open file
        ifstream inputFile;
        inputFile.open(fileName);

        // Check if file is open
        if (!inputFile.is_open()) {
            cout << "Unable to open file" << endl;
            return 1;
        }

        // Read data from file
        while (inputFile) {

            std::getline(inputFile, input);

            cout << "Data read from file:" << input << endl;
        }

        // Close file
        inputFile.close();
    }
    else {
        // Invalid choice
        cout << "Invalid choice" << endl;
        return 1;
    }

    // Get array from user
    cout << "Enter elements of the array, up to 100, enter -1 to stop input: " << endl;
    int element;
    while (cin >> element && element != -1) {
        array[arraySize++] = element;
    }
    cout << "Array entered: ";
    for (int i = 0; i < arraySize; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Store negative numbers and even numbers in new array
    for (int i = 0; i < arraySize; i++) {
        if (array[i] < 0 || array[i] % 2 == 0) {
            newArray[newArraySize++] = array[i];
        }
    }
    // Sort new array in ascending order
    sort(newArray, newArray + newArraySize);

  
    // Display new array
    cout << "New array sorted in ascending order: ";
    for (int i = 0; i < newArraySize; i++) {
        cout << newArray[i] << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}

/*int readFile(int x[], int* nx, string fname)
{
    *nx = 0;
    int i = 0;
    ifstream ifs;
    ifs.open(fname, ios::in); // отваря текстов файл за четене
    if (ifs.fail()) {
        cout << "Error opening file: " << fname << "!\n";
        return -1; // при грешка
    } 
    while (!ifs.eof())
    {
        ifs >> *(x + i); // запис на число в масива
        i++;
    }
    *nx = i - 1;
    ifs.close();
    return 1; //при коректно изпълнение
} */
