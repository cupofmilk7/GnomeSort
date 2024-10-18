#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include <sstream>

#include "checkData.h"

using namespace std;

enum addToFile {
    replaceFile = 1,
    append,
    useAnother
};

// Функция isReservedName(string path), для проверки зарезервированных виндовс названий
bool isReservedName(string path) {
    try {
        if (!filesystem::is_regular_file(path)) {
            return false;
        }
    }
    catch (filesystem::filesystem_error) {
        return true;
    }
    return true;
}


// Функция enteringPathToFile() для ввода пути файла
string enteringPathToFile() {
    cout << "Enter the file name or path to it " << endl;
    string nameOfFile;
    cin >> nameOfFile;
    if (nameOfFile.find(".txt") != nameOfFile.npos) {
        nameOfFile.erase(nameOfFile.find(".txt"), 4);
    }
    string forCheck = nameOfFile;
    reverse(forCheck.begin(), forCheck.end());
    istringstream iss(forCheck);
    if (forCheck.find('\\') != forCheck.npos) {
        getline(iss, forCheck, '\\');
    }
    reverse(forCheck.begin(), forCheck.end());
    while (forCheck.find_first_of("\\ / : ? \" < > | +") != forCheck.npos or isReservedName(forCheck)) {
        cout << "The file name must not contain \\ / : ? \" < > | + and the names reserved by the system" << endl;
        cout << "Enter the file name or path to it " << endl;
        cin >> nameOfFile;
        if (nameOfFile.find(".txt") != nameOfFile.npos) {
            nameOfFile.erase(nameOfFile.find(".txt"), 4);
        }
        forCheck = nameOfFile;
        reverse(forCheck.begin(), forCheck.end());
        iss.str(forCheck);
        if (forCheck.find('\\') != forCheck.npos) {
            getline(iss, forCheck, '\\');
        }
        reverse(forCheck.begin(), forCheck.end());
    }
    nameOfFile += ".txt";
    return nameOfFile;
}

// Функция openFile() для открытия файла
fstream openFile() {
    fstream file;
    string path;
    path = enteringPathToFile();
    while (filesystem::exists(path)) {
        int choice;
        cout << "1 - Replace file \n2 - Add more to an existing one \n3 - Use a different name" << endl;
        choice = checkInt();
        while (choice != 1 and choice != 2 and choice != 3) {
            while (getchar() != '\n');
            cout << "1 - Replace file \n2 - Add more to an existing one \n3 - Use a different name" << endl;
            choice = checkInt();
        }
        addToFile forAdding = static_cast<addToFile>(choice);
        switch (forAdding) {
            case replaceFile:
                file.open(path, fstream::out);
            if (file.is_open()) {
                return file;
            }
            else {
                cout << "File opening error" << endl;
                break;
            }
            case append:
                file.open(path, fstream::out | fstream::app);
            if (file.is_open()) {
                return file;
            }
            else {
                cout << "File opening error" << endl;
                break;
            }
            case useAnother:
                path = enteringPathToFile();
            break;
        }
    }
    file.open(path, fstream::out);
    return file;
}


// Функция addToFile(vector <int>& v) для вывода массива в файл
void addToFile(vector <int>& v) {
	fstream file = openFile();
	if (file.is_open()) {
	    file << endl;
	    for (int i = 0; i < v.size(); i++) {
	        file << v[i] << endl;
	    }
	    cout << "File opening successful" << endl;
	}
	else {
		cout << "Error" << endl;
	}
	file.close();
}