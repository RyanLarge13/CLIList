#include "include/database.h"

void Database::write(vector<vector<string>> mainList) {
    ofstream db;
    db.open("db/lists.txt");
    if (db.is_open()) {
        for (int i = 0; i < (int)mainList.size(); i++) {
            for (int listIndex = 0; listIndex < (int)mainList[i].size(); listIndex++) {
                if (listIndex == 0) {
                    db << "#" << mainList[i][listIndex] << "\n";
                }
                else {
                    db << mainList[i][listIndex] << "\n";
                }
            }
            db << "%" << "\n";
        }
    }
    else {
        cout << "Cannot open file to store list items\n"; 
    }
    db.close();
};

vector<vector<string>> Database::read() {
    string line;
    ifstream db;
    vector<string> userList;
    db.open("db/lists.txt");
    if (db.is_open()) {
        while (getline(db, line, '\n')) {
            if (line.front() == '#') {
                line.erase(line.begin());
                userList.push_back(line);
            }
            else if (line.front() == '%') {
                mainList.push_back(userList);
                userList.clear();
             }
            else {
                userList.push_back(line);
            }
        }
    }
    else {
        cout << "We cannot open file for your lists\n";
    }
    db.close();
    return mainList;
};