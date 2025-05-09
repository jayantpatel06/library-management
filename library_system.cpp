#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    Book(int i, const string& t, const string& a)
        : id(i), title(t), author(a), isIssued(false) {}

    void display() const {
        cout << "ID: " << id
             << ", Title: " << title
             << ", Author: " << author
             << ", Status: " << (isIssued ? "Issued" : "Available")
             << endl;
    }
};

// Node for manual singly-linked list
struct Node {
    Book data;
    Node* next;
    Node(int i, const string& t, const string& a)
        : data(i, t, a), next(nullptr) {}
};

Node* head = nullptr;

// Add a book node at the end
void pushBack(int id, const string& title, const string& author) {
    Node* newNode = new Node(id, title, author);
    if (!head) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = newNode;
    }
}

// Initialize library with predefined books
void initLibrary() {
    pushBack(1, "Steve Jobs", "Walter Issacson");
    pushBack(2, "Discovery of India", "Jawaharlal Nehru");
    pushBack(3, "My Experiments with Truth", "Mahatma Gandhi");
    pushBack(4, "Object Oriented Programming with C++", "E Balagurusamy");
    pushBack(5, "Thinking with type", "Ellen Lupton");
    pushBack(6, "The Photographer's", "Lindsay Adler");
    pushBack(7, "Think and Grow", "Napoleon Hill");
    pushBack(8, "The Fifth Discipline : The Art", "Peter M.Senge");
    pushBack(9, "A Theory of Justice", "John Rawls");
    pushBack(10, "Eat to Live", "Joel Fuhrman");
    pushBack(11, "City of Heavenly Fire", "Cassandra Clare");
    pushBack(12, "Da Vinci Code", "Dan Brown");
    pushBack(13, "War and Peace", "Leo Tolstoy");
    pushBack(14, "Python For All", "John Shovic");
    pushBack(15, "Automate The Boring Stuff With Python", "Al Sweigart");
    pushBack(16, "Wings Of Fire", "APJ Abdul Kalam");
    pushBack(17, "Ikigai", "Hector Garcia");
    pushBack(18, "Who Will Cry When You Will Die", "Robin Sharma");
    pushBack(19, "Rich Dad Poor Dad", "Robert T. Kiyosaki");
    pushBack(20, "Immortals of Meluha", "Amish Tirpathi");
    pushBack(21, "A Brief History Of Time", "Stephen Hawking");
    pushBack(22, "I Know Why The Cage Bird Sings", "Maya Anguelo");
    pushBack(23, "Lord Of Files", "William Golding");
    pushBack(24, "Loara Dune", "R. D Blackmore");
    pushBack(25, "Jamacia Inn", "Daphne");
    pushBack(26, "Kidnapped", "Robert Louis");
    pushBack(27, "Treasure Island", "Robert Louis");
    pushBack(28, "The Call Of Wild", "Jack London");
    pushBack(29, "Charlottes Web", "E. B White");
    pushBack(30, "The Wind In Willows", "Kenneth Grahame");
    pushBack(31, "Being and Time", "Martin Heldegger");
    pushBack(32, "The Republic", "Rocha Pereia");
    pushBack(33, "Critique For Pure Reason", "Paul Guyer");
    pushBack(34, "The Prince", "Rufus Godwin");
    pushBack(35, "Ethics", "Stuart Hampshire");
    pushBack(36, "Long Walk To Freedom", "Nelson Mandela");
    pushBack(37, "The Diary Of A Young Girl", "Anne Frank");
    pushBack(38, "Mark Twain", "Mark Twain");
    pushBack(39, "Mein Kampf", "Adolf Hitler");
    pushBack(40, "Freakonomics", "Steven D. Levitt");
    pushBack(41, "Thinking Fast and Slow", "Daniel Kahneman");
    pushBack(42, "Tell You About Capitalism", "Ha-Joon Chang");
    pushBack(43, "Animal Spirits", "Akerlof and Shiller");
    pushBack(44, "The Black Swan", "Nassim Nicholas Taleb");
    pushBack(45, "1984", "George Orwell");
    pushBack(46, "The Lord Of Wings", "J.R.R. Tolkien");
    pushBack(47, "Kite Runner", "Khaled Hosseini");
    pushBack(48, "Harry Potter", "J.K. Rowling");
    pushBack(49, "The Book Thief", "Markus Zusak");
    pushBack(50, "History Of 20th Century", "Martin Gilbert");
    pushBack(51, "Guns, Germs, and Steel", "Jared Diamond");
    pushBack(52, "A World Lit Only by Fire", "William Manchester");
    pushBack(53, "The Crusades", "Thomas Asbridge");
    pushBack(54, "Over The Edge Of The World", "Laurence Bergreen");
    pushBack(55, "A Beautiful Mind", "Sylvia Nasar");
    pushBack(56, "The Enigma", "Andrew Hodges");
    pushBack(57, "Alexander Hamilton", "Ron Chernow");
    pushBack(58, "Barracoon", "Zora Neale Hurston");
    pushBack(59, "Churchill: A Life", "Martin Gilbert");
    pushBack(60, "A Tale of Two Cities", "Charles Dickens");
    pushBack(61, "Les Misérables", "Victor Hugo");
}

void displayBooks() {
    Node* curr = head;
    while (curr) {
        curr->data.display();
        curr = curr->next;
    }
}

void issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    Node* curr = head;
    while (curr) {
        if (curr->data.id == id) {
            if (!curr->data.isIssued) {
                curr->data.isIssued = true;
                cout << "Book issued successfully!\n";
            } else {
                cout << "Book already issued!\n";
            }
            return;
        }
        curr = curr->next;
    }
    cout << "Book not found!\n";
}

void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    Node* curr = head;
    while (curr) {
        if (curr->data.id == id) {
            if (curr->data.isIssued) {
                curr->data.isIssued = false;
                cout << "Book returned successfully!\n";
            } else {
                cout << "Book was not issued.\n";
            }
            return;
        }
        curr = curr->next;
    }
    cout << "Book not found!\n";
}

void addBook() {
    int id;
    string title, author;
    cout << "Enter ID (greater than 61), Title, Author: ";
    cin >> id;
    cin.ignore();
    if (id <= 61) {
        cout << "ID must be greater than 61. Re-enter.\n";
        return;
    }
    getline(cin, title);
    getline(cin, author);
    pushBack(id, title, author);
}

int main() {
    initLibrary();
    int choice;
    do {
        cout << "\n1. Add Book\n2. Display Books\n3. Issue Book\n4. Return Book\n0. Exit\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: issueBook(); break;
            case 4: returnBook(); break;
            case 0: cout << "Exiting program.\n"; break;
            default:
                cout << "Enter valid choice between 0-4\n";
        }
    } while (choice != 0);
    return 0;
}
