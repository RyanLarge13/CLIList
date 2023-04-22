#include <iostream>
#include <vector>
using namespace std;

class List {
    private:
    protected:
    public:
        List() {
            //constructor
        }
        ~List() {
            //destructor
        }
        void printMenu();
        void printList();
        void addItem();
        void deleteItem();
        bool findUserList();
        void saveList();
        int currentUserIndex;
        vector<vector<string>> mainList;
        vector<string> list;
        string username;
};