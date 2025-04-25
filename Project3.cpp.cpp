//including necessary librzries
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;


//function declations
void displayMenu(map<string, int> itemList);
void option1 (map<string, int> itemList);
void option2 (map<string, int> itemList);
void option3 (map<string, int> itemList);

//displayMenu function definition
void displayMenu(map<string, int> itemList) {
    
    cout << "CORNER GROCER SALES TRACKER" << endl;
    cout << "Press 1 to search and item and" << endl;
    cout << "find out how many times it has" << endl;
    cout << "been purchased recently." << endl;
    cout << "Press 2 to print a list of all" << endl;
    cout << "items recently sold and how many times" << endl;
    cout << "they've been purchased." << endl;
    cout << "Press 3 to view a graph of recently" << endl;
    cout << "purchased items and their sales." << endl;
    cout << "Press 4 or any non-number to exit program." << endl;
    
    int choice;
    cin >> choice;
    
    while ((choice > 0) && (choice < 5)) {
    
        if (choice == 1) {
            option1(itemList);
        }
        else if (choice == 2) {
            option2(itemList);
        }
        else if (choice == 3) {
            option3(itemList);
        }
        else if (choice == 4) {
            return;
        }
        else {
            cout << "There's been an error! Press 1," << endl;
            cout << "2, or 3 to choose a menu item," << endl;
            cout << "or press 4 to exit program." << endl;
            cin >> choice;
        }
    
    }
    cout << "Error. Next time, type 1, 2, 3, or 4 to choose a menu option." << endl;
    
}

//option1 function definition
void option1 (map<string, int> itemList) {
    
    string item;
    int choice;
    choice = 1;
    cout << "Menu Option 1" << endl;
    while (choice == 1) {
        cout << "Which item do you want to find the frequency of?" << endl;
        cin >> item;
        while (itemList.count(item) == 0) {
            cout << "That item isn't on the list! Remember every item has a" <<endl;
            cout << "capitalized first letter and is plural." << endl;
            cout << "Try again." << endl;
            cin >> item;
        }
        cout << "That item appears " << itemList.at(item) << " times on this list." << endl;
        cout << "Press 1 to find the frequency of another" << endl;
        cout << "item or 2 to return to display menu." << endl;
        cin >> choice;
    }
    if (choice == 2) {
        displayMenu(itemList);
    }
    else {
        cout << "There's been an error. Returning to menu." << endl;
        displayMenu(itemList);
    }
}

//option2 Function Definition
void option2 (map<string, int> itemList) {
    
    int choice = 1;
    
    cout << "Menu Option 2" << endl;
    while (choice == 1) {
        for (auto item : itemList) {
            cout << item.first << "  " << item.second << endl;
        }
        cout << "That's all the items and their frequencies." << endl;
        cout << "Press 1 to view frequencies again or 2 to" << endl;
        cout << "return to display menu." << endl;;
        cin >> choice;
    }
    if (choice == 2) {
        displayMenu(itemList);
    }
    else {
        cout << "There's been an error. Returning to menu." << endl;
        displayMenu(itemList);
    }
    
}


//option3 Function Definition
void option3 (map<string, int> itemList) {
    
    int choice = 1;
    
    cout << "Menu Option 3" << endl;
    while (choice == 1) {
        for (auto item : itemList) {
            cout << setw(12) << item.first << "  ";
            for (int i = 0; i < item.second; i++) {
                cout << "#";
            }
            cout << endl;
        }
        cout << "That's a graph of the items and their" << endl;
        cout << "frequencies. Press 1 to view the graph" << endl;
        cout << "again or 2 to return to display menu." << endl;
        cin >> choice;
    }
    if (choice == 2) {
        displayMenu(itemList);
    }
    else {
        cout << "There's been an error. Returning to menu." << endl;
        displayMenu(itemList);
    }
    
}

int main () {
    
    ifstream inFS;
    ofstream outFS;
    map<string, int> items;
    inFS.open("InputFile.txt");
    outFS.open("frequency.dat");
    string itemName;
    //int itemCounter;
    
    if (!inFS.is_open()) {
        cout << "Do better." << endl;
        return 0;
    }
    
    if (!outFS.is_open()) {
        cout << "Ugh" << endl;
        return 0;
    }
    
    inFS >> itemName;
    while (!inFS.fail()) {
        items[itemName] = items[itemName] + 1;
        inFS >> itemName;
    }
    
    for(auto item : items) {
        outFS << item.first << " " << item.second << endl;
    }
    
    inFS.close();
    outFS.close();
    
    displayMenu(items);
    
    return 0;
    
}
