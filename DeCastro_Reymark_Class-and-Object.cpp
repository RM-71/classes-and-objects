#include <iostream>
#include <iomanip>
using namespace std;


//Class For Library book Details
class Library {
private:
// Initilization of Book Details
    string Title;
    string Author;
    int Year;


public:
//Constructor For Book Details
    Library(string T = "", string A = "", int Y = 0) {
		Title = T;
		Author = A;
		Year = Y;
	}
	
//Returning The Title
    string GetTitle() {
        return Title;
    }
    
//Returning The Author
    string GetAuthor() {
        return Author;
    }
    
//Returning The Year
    int GetYear() {
        return Year;
    }
    
//To Display The Title
    void Display() {
        cout << Title << "\t" << Author << "\t\t" << Year << endl;
    }
};




//Void To Add a Book
void AddBook(Library books[], int& count) {
    
	if (count >= 30) {
        cout << "Library is full!" << endl;
        return;
    }

    string title;
    string author;
    int year;

    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Year: ";
    cin >> year;
    

    books[count++] = Library(title, author, year);
    cout << "Book Added Successfully" << endl;
}



//Void To Display The Book
void DisplayBooks(Library books[], int count) {
    cout << "Title\t\tAuthor\t\tYear" << endl;
    for (int i = 0; i < count; ++i) {
        books[i].Display();
    }
}




//Void To Search The Book
void SearchBooks(Library books[], int count) {
    
	string searchTitle; //For Searching
	bool found = false; 
     
    cout << "Enter a Book Title to Search: ";
    getline(cin, searchTitle);
	cout << endl;
	
		
    //Loop to run all the Book
    for (int i = 0; i < count; ++i) {
    	
       //Comparing all the Title to the Search Title to see if it exist
	    if (books[i].GetTitle() == searchTitle) {
           
		    cout << "Book Found!" << endl << endl;
            cout << "Title: " << books[i].GetTitle() << endl;
            cout << "Author: " << books[i].GetAuthor() << endl;
            cout << "Year: " << books[i].GetYear() << endl;
            
            	
			//if the book is found
			found = true;
            break;
        }
    }

	//If the book is not found
    if (!found) {
        cout << "Book not found!" << endl;
    }
}




//The Starting Point of Program Execution
int main() {
	
    Library books[30]; 
    int count = 0;
    int menuChoice;

	//Loop For the Menu Choices
    while (true) {
    	
       	system("cls"); // Clear Screen
  
    //Menu Display
	    cout << "Menu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Books" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> menuChoice;
		cin.ignore();
        cout << endl;
        
        
	    switch (menuChoice) {
            case 1:
            	
                AddBook(books, count);//Get The Void That Add all The Book
                
                system ("pause"); //To pause and display "Press Any Key..."
                break;
                
            case 2:
            	
                DisplayBooks(books, count); //Get The Void That Display all The Book
                
                system ("pause"); //To pause and display "Press Any Key..."
                break;
                
            case 3:
        
                SearchBooks(books, count); //Get The Void That Search The Book
                
                system ("pause"); //To pause and display "Press Any Key..."
                break;
                
            case 4:
            	
            	// To Exit The Program
                cout << "Exiting..." << endl;
                return 0;
                
            default:
            
                cout << "Invalid Input, Please Try Again" << endl ;
        }
    }

    return 0;
}
