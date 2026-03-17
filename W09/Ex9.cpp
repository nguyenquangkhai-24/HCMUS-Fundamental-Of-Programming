#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct Node {
    int id;
    string title;
    string artist;
    int duration;
    bool isPlaying;
    Node* next;
    Node* prev;
};

Node* makeNode(int id, string title, string artist, int duration) {
    Node* newNode = new Node();
    newNode->id = id;
    newNode->title = title;
    newNode->artist = artist;
    newNode->duration = duration;
    newNode->isPlaying = false;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

bool isDuplicate(Node* head, string title, string artist) {
    Node* p = head;
    while (p != nullptr) {
        if (p->title == title && p->artist == artist) {
            return true;
        }
        p = p->next;
    }
    return false;
}

bool isIdUnique(Node* head, int id) {
    Node* p = head;
    while (p != nullptr) {
        if (p->id == id) {
            return false;
        }
        p = p->next;
    }
    return true;
}

int countSongs(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

void insertSong(Node*& head, Node*& tail, int k, int id, string title, string artist, int duration) {
    if (!isIdUnique(head, id)) {
        cout << "Error: ID already exists.\n";
        return;
    }
    if (isDuplicate(head, title, artist)) {
        cout << "Error: Song already exists.\n";
        return;
    }

    Node* newNode = makeNode(id, title, artist, duration);
    int n = countSongs(head);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    if (k == 0) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else if (k == -1 || k >= n) {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < k - 1; i++) {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }
}

void deleteByTitle(Node*& head, Node*& tail, string title) {
    Node* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->title == title) {
            found = true;
            Node* toDelete = current;
            if (current == head) {
                head = head->next;
                if (head) head->prev = nullptr;
                else tail = nullptr;
            }
            else if (current == tail) {
                tail = tail->prev;
                if (tail) tail->next = nullptr;
                else head = nullptr;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            current = current->next;
            delete toDelete;
        }
        else {
            current = current->next;
        }
    }
    if (!found) cout << "Song not found.\n";
}

void deleteByArtist(Node*& head, Node*& tail, string artist) {
    Node* current = head;
    bool found = false;
    while (current != nullptr) {
        if (current->artist == artist) {
            found = true;
            Node* toDelete = current;
            if (current == head) {
                head = head->next;
                if (head) head->prev = nullptr;
                else tail = nullptr;
                current = head;
            }
            else if (current == tail) {
                tail = tail->prev;
                if (tail) tail->next = nullptr;
                else head = nullptr;
                current = nullptr;
            }
            else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                Node* temp = current->next;
                current = temp;
            }
            delete toDelete;
        }
        else {
            current = current->next;
        }
    }
    if (!found) cout << "No songs found by this artist.\n";
}

void clearPlaylist(Node*& head, Node*& tail) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

void editSong(Node* head, int id) {
    Node* p = head;
    while (p != nullptr) {
        if (p->id == id) {
            cout << "Editing song ID " << id << endl;
            cout << "Enter new Title: "; getline(cin, p->title);
            cout << "Enter new Artist: "; getline(cin, p->artist);
            cout << "Enter new Duration: "; cin >> p->duration;
            return;
        }
        p = p->next;
    }
    cout << "Song ID not found.\n";
}

void showStats(Node* head) {
    int count = 0;
    int totalDuration = 0;
    Node* p = head;
    while (p != nullptr) {
        count++;
        totalDuration += p->duration;
        p = p->next;
    }
    cout << "Total Songs: " << count << endl;
    cout << "Total Duration: " << totalDuration << " seconds" << endl;
}

void searchSong(Node* head, string keyword) {
    Node* p = head;
    bool found = false;
    while (p != nullptr) {
        if (p->title == keyword || p->artist == keyword) {
            cout << "Found: [" << p->id << "] " << p->title << " - " << p->artist << endl;
            found = true;
        }
        p = p->next;
    }
    if (!found) cout << "No match found.\n";
}

void swapData(Node* a, Node* b) {
    swap(a->id, b->id);
    swap(a->title, b->title);
    swap(a->artist, b->artist);
    swap(a->duration, b->duration);
    swap(a->isPlaying, b->isPlaying);
}

void sortPlaylist(Node* head, int type) {
    if (head == nullptr) return;
    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            bool condition = false;
            if (type == 1) condition = (ptr1->title > ptr1->next->title);
            else if (type == 2) condition = (ptr1->artist > ptr1->next->artist);
            else condition = (ptr1->duration > ptr1->next->duration);

            if (condition) {
                swapData(ptr1, ptr1->next);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

void stopAll(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        p->isPlaying = false;
        p = p->next;
    }
}

void playSongById(Node* head, int id) {
    stopAll(head);
    Node* p = head;
    while (p != nullptr) {
        if (p->id == id) {
            p->isPlaying = true;
            cout << "Playing: " << p->title << endl;
            return;
        }
        p = p->next;
    }
    cout << "ID not found.\n";
}

void nextSong(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        if (p->isPlaying) {
            p->isPlaying = false;
            if (p->next != nullptr) {
                p->next->isPlaying = true;
                cout << "Next: " << p->next->title << endl;
            }
            else {
                cout << "End of playlist.\n";
            }
            return;
        }
        p = p->next;
    }
    if (head != nullptr) {
        head->isPlaying = true;
        cout << "Playing first song: " << head->title << endl;
    }
}

void prevSong(Node* tail) {
    Node* p = tail;
    while (p != nullptr) {
        if (p->isPlaying) {
            p->isPlaying = false;
            if (p->prev != nullptr) {
                p->prev->isPlaying = true;
                cout << "Prev: " << p->prev->title << endl;
            }
            else {
                cout << "Start of playlist.\n";
            }
            return;
        }
        p = p->prev;
    }
    if (tail != nullptr) {
        tail->isPlaying = true;
        cout << "Playing last song: " << tail->title << endl;
    }
}

void printCurrentPlaying(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        if (p->isPlaying) {
            cout << "Currently Playing: " << p->title << " - " << p->artist << endl;
            return;
        }
        p = p->next;
    }
    cout << "No song is playing.\n";
}

void displayList(Node* head) {
    Node* p = head;
    cout << "--- Playlist ---\n";
    while (p != nullptr) {
        cout << p->id << ". " << p->title << " - " << p->artist
            << " (" << p->duration << "s) "
            << (p->isPlaying ? "[PLAYING]" : "") << endl;
        p = p->next;
    }
    cout << "----------------\n";
}

void exportToCSV(Node* head, string filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file.\n";
        return;
    }
    Node* p = head;
    while (p != nullptr) {
        file << p->id << "," << p->title << "," << p->artist << "," << p->duration << endl;
        p = p->next;
    }
    file.close();
    cout << "Exported successfully.\n";
}

void importFromCSV(Node*& head, Node*& tail, string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Cannot open file.\n";
        return;
    }
    clearPlaylist(head, tail);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string segment;
        int id, duration;
        string title, artist;

        if (getline(ss, segment, ',')) id = stoi(segment);
        if (getline(ss, title, ','));
        if (getline(ss, artist, ','));
        if (getline(ss, segment, ',')) duration = stoi(segment);

        insertSong(head, tail, -1, id, title, artist, duration);
    }
    file.close();
    cout << "Imported successfully.\n";
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int choice;

    while (true) {
        cout << "\n1. Add Song\n2. Delete Song\n3. Edit Song\n4. Stats\n5. Search\n6. Sort\n7. Playback Control\n8. Show List\n9. CSV I/O\n0. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) break;

        if (choice == 1) {
            int k, id, duration;
            string title, artist;
            cout << "Position (-1 for end): "; cin >> k;
            cout << "ID: "; cin >> id; cin.ignore();
            cout << "Title: "; getline(cin, title);
            cout << "Artist: "; getline(cin, artist);
            cout << "Duration (s): "; cin >> duration;
            insertSong(head, tail, k, id, title, artist, duration);
        }
        else if (choice == 2) {
            int sub;
            cout << "1. By Title\n2. By Artist\n3. Clear All\nOption: "; cin >> sub; cin.ignore();
            if (sub == 1) {
                string t; cout << "Enter Title: "; getline(cin, t);
                deleteByTitle(head, tail, t);
            }
            else if (sub == 2) {
                string a; cout << "Enter Artist: "; getline(cin, a);
                deleteByArtist(head, tail, a);
            }
            else {
                clearPlaylist(head, tail);
            }
        }
        else if (choice == 3) {
            int id; cout << "Enter ID to edit: "; cin >> id; cin.ignore();
            editSong(head, id);
        }
        else if (choice == 4) {
            showStats(head);
        }
        else if (choice == 5) {
            string key; cout << "Enter Title/Artist: "; getline(cin, key);
            searchSong(head, key);
        }
        else if (choice == 6) {
            int type; cout << "1. Title\n2. Artist\n3. Duration\nOption: "; cin >> type;
            sortPlaylist(head, type);
        }
        else if (choice == 7) {
            int sub;
            printCurrentPlaying(head);
            cout << "1. Play ID\n2. Next\n3. Prev\nOption: "; cin >> sub;
            if (sub == 1) {
                int id; cout << "ID: "; cin >> id;
                playSongById(head, id);
            }
            else if (sub == 2) nextSong(head);
            else if (sub == 3) prevSong(tail);
        }
        else if (choice == 8) {
            displayList(head);
        }
        else if (choice == 9) {
            int sub; cout << "1. Export\n2. Import\nOption: "; cin >> sub; cin.ignore();
            string fname; cout << "Filename: "; getline(cin, fname);
            if (sub == 1) exportToCSV(head, fname);
            else importFromCSV(head, tail, fname);
        }
    }
    clearPlaylist(head, tail);
    return 0;
}