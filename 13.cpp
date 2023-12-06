#include <iostream>

using namespace std;

class Books {
public:
    Books(string author, string title, float price, string publisher, int stock_position) {
        this->author = author;
        this->title = title;
     
   
this->price = price;
        this->publisher = publisher;
        this->stock_position = stock_position;
    }

    bool
 
search_book(string title, string author)
 
{
        if (this->title == title && this->author == author) {
            return true;
        } else {
            return false;
        }
    }

    void display_book_details() {
        cout << "Author: " << this->author << endl;
        cout << "Title: " << this->title << endl;
        cout << "Price: " << this->price << endl;
        cout << "Publisher: " << this->publisher << endl;
        cout << "Stock Position: " << this->stock_position << endl;
    }

    bool check_stock(int copies_required) {
        if (this->stock_position >= copies_required) {
            return true;
        } else {
            return false;
        }
    }

    float calculate_total_cost(int copies_required) {
        float total_cost = this->price * copies_required;
        return total_cost;
    }

private:
    string author;
    string title;
    float price;
    string publisher;
    int stock_position;
};

int main() {
    Books book1("J.K. Rowling", "Harry Potter and the Sorcerer's Stone", 29.99, "Bloomsbury Publishing", 50);
    Books book2("J.R.R. Tolkien", "The Lord of the Rings", 39.99, "HarperCollins", 30);
    Books book3("Harper Lee", "To Kill a Mockingbird", 14.99, "Penguin Random House", 20);

    string title = "Harry Potter and the Sorcerer's Stone";
    string author = "J.K. Rowling";

    if (book1.search_book(title, author)) {
        book1.display_book_details();

        int copies_required = 2;

        if (book1.check_stock(copies_required)) {
            float total_cost = book1.calculate_total_cost(copies_required);
            cout << "Total Cost: " << total_cost << endl;
        } else {
            cout << "Required copies not in stock" << endl;
        }
    } else {
        cout << "Book not found" << endl;
    }

    return 0;
}
