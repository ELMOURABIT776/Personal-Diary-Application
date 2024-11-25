#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct DiaryEntry {
    string date;
    string content;
};

class PersonalDiary {
private:
    vector<DiaryEntry> entries;

public:
    void addEntry(string date, string content) {
        DiaryEntry newEntry = {date, content};
        entries.push_back(newEntry);
    }

    void viewEntries() {
        if (entries.empty()) {
            cout << "No entries found.\n";
            return;
        }
        for (auto &entry : entries) {
            cout << "Date: " << entry.date << "\n";
            cout << "Content: " << entry.content << "\n\n";
        }
    }

    void deleteEntry(string date) {
        for (auto it = entries.begin(); it != entries.end(); ++it) {
            if (it->date == date) {
                entries.erase(it);
                cout << "Entry for " << date << " deleted.\n";
                return;
            }
        }
        cout << "Entry not found.\n";
    }
};

int main() {
    PersonalDiary diary;
    int choice;
    do {
        cout << "1. Add Entry\n2. View Entries\n3. Delete Entry\n4. Exit\n";
        cin >> choice;
        if (choice == 1) {
            string date, content;
            cout << "Enter date (DD/MM/YYYY): ";
            cin >> date;
            cin.ignore(); // to consume newline character
            cout << "Enter content: ";
            getline(cin, content);
            diary.addEntry(date, content);
        } else if (choice == 2) {
            diary.viewEntries();
        } else if (choice == 3) {
            string date;
            cout << "Enter date of entry to delete: ";
            cin >> date;
            diary.deleteEntry(date);
        }
    } while (choice != 4);

    return 0;
}
