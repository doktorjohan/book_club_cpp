#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


class book {
private:
    char *author, *title, *publisher;
    float *price;
    int *stock;
public:
    book() {
        author = new char[20];
        title = new char[20];
        publisher = new char[20];
        price = new float;
        stock = new int;
    }
    void feeddata();
    void editdata();
    void showdata();
    int search(char[],char[]);
    void buybook();

};


void book::feeddata()
{
    cin.ignore();
    cout << "\nEnter Author name: "; cin.getline(author, 20);
    cout << "Enter title name: "; cin.getline(title, 20);
    cout << "Enter publisher name: "; cin.getline(publisher, 20);
    cout <<  "Enter price: "; cin >> *price;
    cout << "Enter stock position: "; cin >> *stock;
}

void book::editdata()
{
    cout << "\nEnter Author name: "; cin.getline(author, 20);
    cout << "Enter title name: "; cin.getline(title, 20);
    cout << "Enter publisher name: "; cin.getline(publisher, 20);
    cout <<  "Enter price: "; cin >> *price;
    cout << "Enter stock position: "; cin >> *stock;
}

void book::showdata()
{
    cout << "\nAuthor name: " << author;
    cout << "\nTitle name: " << title;
    cout << "\nPublisher name: " << publisher;
    cout << "\nPrice: " << *price;
    cout << "\nStock position: " << *stock;
}

int book::search(char tbuy[20], char abuy[20])
{
    if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)
        return 1;
    else return 0;
}

void book::buybook()
{
    int count;
    cout << "\nEnter number of books to buy: ";
    cin >> count;
    if (count <= *stock) {
        // *stock -= ei toimi millegipärast. ilmselt kuna tegu private muutujaga??
        *stock = *stock - count;
        cout << "\nBooks bought successfully!";
        cout << "\nAmount: € " << (*price)*count;
    }
    else
        cout << "\nRequired copies not in stock.";
}


int main()
{
    book *B[20];
    int i=0,t,choice;
    char titlebuy[20], authorbuy[20];
    while(true)
    {
        cout << "\n\n\t\tMENU"
        << "\n1. Entry of new book"
        << "\n2. Buy book"
        << "\n3. Search for book"
        << "\n4. Edit details of book"
        << "\n5. Exit"
        << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: B[i] = new book;
                    B[i] -> feeddata();
                    i++;
                    break;

            case 2: cin.ignore();
                    cout << "\nEnter title of book: "; cin.getline(titlebuy, 20);
                    cout << "Enter Author of book: "; cin.getline(authorbuy, 20);

                    for (t=0; t<i; t++) {
                        if(B[t]->search(titlebuy,authorbuy)){
                            B[t]->buybook();
                            break;
                        }
                    }
                    if (t==1)
                        cout << "\nThis book is not in stock";

                    break;

            case 3: cin.ignore();
                    cout <<"\nEnter title of book: "; cin.getline(titlebuy, 20);
                    cout << "Enter author of book: "; cin.getline(authorbuy, 20);

                    for(t=0; t<i;t++) {
                        if (B[t] -> search(titlebuy, authorbuy)) {
                            cout << "\nBook found successfully";
                            B[t] -> showdata();
                            break;
                        }
                    }
                    if (t==i)
                        cout << "\nThis book is not in stock";
                    break;

            case 4: cin.ignore();
                cout <<"\nEnter title of book: "; cin.getline(titlebuy, 20);
                cout << "Enter author of book: "; cin.getline(authorbuy, 20);

                for (t=0; t<i; t++) {
                    if (B[t]->search(titlebuy,authorbuy)) {
                        cout << "\nBook found successfully";
                        B[t]->editdata();
                        break;

                    }
                }
                if (t==i)
                    cout << "\nThis book is not in stock";
                break;

            case 5: exit(0);
            default: cout << "\nInvalid choice";
        }
    }
}
