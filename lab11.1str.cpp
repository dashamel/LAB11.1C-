#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int hasAdjacentPairs(const string& fname) {
    ifstream file(fname);
    if (!file.is_open())
    {
        cout << "Cannot open file.\n";
        return -1;
    }

    string line;

    while (getline(file, line)) 
    {
        for (size_t i = 0; i < line.length() - 1; i++) 
        {
            if ((line[i] == 'a' && line[i + 1] == 'a') ||
                (line[i] == 'b' && line[i + 1] == 'b') ||
                (line[i] == 'c' && line[i + 1] == 'c')) {
                file.close();
                return 1;
            }
        }
    }

    file.close();
    return 0;
}

int main() {
    string fname;
    cout << "Type filename: ";
    cin >> fname;

    int result = hasAdjacentPairs(fname);
    if (result == -1) 
    {
        cout << "Cannot open file.\n";
    }
    else if (result == 1) {
        cout << "File contains adjacent pairs 'aa', 'bb' or 'cc'.\n";
    }
    else {
        cout << "File does not contain adjacent pairs 'aa', 'bb' or 'cc'.\n";
    }

    return 0;
}
