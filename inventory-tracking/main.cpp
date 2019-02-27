//
//  main.cpp
//  inventory-tracking
//  From start-up, the program reads a data file of inventory records,
//  builds a single linked list with structs and pointers. The program
//  then displays a simple menu of choices for processing the linked
//  list data structure.
//
//  Created by Michelle Adea on 2/17/19.
//  Copyright © 2019 Michelle Adea. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
#include <iomanip>

// defines struct item
struct item {
    int numId;
    char name[21];
    int quantity;
    int categoryCode;
    char supplierCode[1];
    float unitCost;
    float unitPrice;
    item *next;
};

// defines struct list
struct list {
    item *first;
    item *last;
};

//function prototypes
void menu_display();
int menu_selection();
void build_list(list *inventory_list);
void strsub(char source[], char destination[], int start, int length);
void append(item *i, list *p);
void print_list(list *inventory_list);
void total_quantity(list *inventory_list);
void total_quantity_per_category(list *inventory_list);

int main(int argc, const char * argv[]) {
    // declares struct list inventory_list
    list inventory_list;
    
    inventory_list.first = 0; // sets to null pointer
    inventory_list.last = 0;  // sets to null pointer
    
    build_list(&inventory_list);
    
    // declares output stream object myfile
    //ofstream myfile;
    //myfile.open("Output.txt");
    
    int choice;
    do {
        menu_display();
        choice = menu_selection();
        switch(choice) {
            case 1: print_list(&inventory_list); break;
            case 2: total_quantity(&inventory_list); break;
            case 3: total_quantity_per_category(&inventory_list); break;
            case 4: cout << "Program Exited" << endl; break;
        }
    } while (choice != 4);
    
    // closes output stream object
    //myfile.close();
    
    return 0;
}

// shows the menu options
void menu_display() {
    cout << "\n*****Inventory Menu*****"
         << "\n1. Display Inventory"
         << "\n2. Total Quantity Report"
         << "\n3. Category Summary Report"
         << "\n4. Exit the Program"
         << "\nEnter an option from 1 to 4: " << endl;
}

// prompts the user to enter an int option
int menu_selection() {
    int option;
    cin >> option;
    return option;
}

// creates a substring from the source from index start for a certain length and stores in destination
void strsub(char source[], char destination[], int start, int length) {
    int i;
    for (i = 0; i < length; ++i)
        destination[i] = source[start++];
    destination[i] = '\0';
}

// creates the linked list inventory_list that contains information from the "invent.dat" file
void build_list(list *inventory_list) {
    // declares input stream object infile
    ifstream infile;
    infile.open("Invent.dat");
    
    const int MAX = 100;
    char line[MAX];
    // gets the first line from infile and stores in string line
    infile.getline(line, MAX);
    
    while(infile.fail() == false) {
        item *i = new item;
        char temp[MAX];
        strsub(line, temp, 0, 5);
        i->numId = atoi(temp);
        strsub(line, i->name, 6, 20);
        strsub(line, temp, 27, 4);
        i->quantity = atoi(temp);
        strsub(line, temp, 32, 1);
        i->categoryCode = atoi(temp);
        strsub(line, i->supplierCode, 34, 1);
        strsub(line, temp, 36, 9);
        i->unitCost = atof(temp);
        strsub(line, temp, 46, 9);
        i->unitPrice = atof(temp);
        i->next = 0;
        
        append(i, inventory_list);
        // gets the next line from infile
        infile.getline(line, MAX);
    }
    // closes input stream object
    infile.close();
}

// struct item is added to struct list
void append(item *i, list *p) {
    if (p->last == 0)
        p->first = i;
    else
        p->last->next = i;
    p->last = i;
}

// prints out each struct item's information from the struct list
void print_list(list *inventory_list) {
    item *p = inventory_list->first;
    
    if (p) {
        cout << "\n*********Inventory List*********" << endl;
        cout << setw(10) << left << "Item No."
             << setw(25) << left << "Item Description"
             << setw(10) << left << "Quantity"
             << setw(15) << "Category Code"
             << setw(15) << "Supplier Code"
             << setw(10) << right << "Unit Cost"
             << setw(15) << right << "Unit Price" << endl;
        // shows any trailing zeroes, floating point, fixed at 2 decimal places
        cout << showpoint << setprecision(2) << fixed;
    }
    
    while (p != 0) {
        cout << setw(10) << left << p->numId
             << setw(25) << left << p->name
             << setw(10) << left << p->quantity
             << setw(15) << p->categoryCode
             << setw(15) << p->supplierCode
             << setw(10) << right << p->unitCost
             << setw(15) << right << p->unitPrice
             << endl;
        p = p->next;
    }
}

// determines the total quantity amount of items in the inventory list
void total_quantity(list *inventory_list) {
    long total_quantity = 0L;
    item * p = inventory_list->first;
    while (p != 0) {
        total_quantity += p->quantity;
        p = p->next;
    }
    
    // outputs the total quantity of the inventory
    cout << "\n*********Total Quantity Report*********" << endl;
    cout << "The total quantity is " << total_quantity << "." << endl;
}

// determines the total amount of items for each category in the inventory list
// given that there are only 8 categories
void total_quantity_per_category(list *inventory_list) {
    long total_quantity_in_category[8];
    
    // initializes array
    for (int i = 0; i < 8; i++)
        total_quantity_in_category[i] = 0L;
    
    item * p = inventory_list->first;
    int category;
    while(p != 0) {
        category = p->categoryCode;
        switch(category){
            // keep in mind that category is valued from 1 to 8, index of array is from 0 to 7
            case 1: total_quantity_in_category[0] += p->quantity; break;
            case 2: total_quantity_in_category[1] += p->quantity; break;
            case 3: total_quantity_in_category[2] += p->quantity; break;
            case 4: total_quantity_in_category[3] += p->quantity; break;
            case 5: total_quantity_in_category[4] += p->quantity; break;
            case 6: total_quantity_in_category[5] += p->quantity; break;
            case 7: total_quantity_in_category[6] += p->quantity; break;
            case 8: total_quantity_in_category[7] += p->quantity; break;
        }
        p = p->next;
    }
    
    // outputs the total quantity for each category
    cout << "\n*********Category Summary Report*********" << endl;
    cout << setw(20) << left << "Category"
         << setw(15) << right << "Quantity" << endl;
    cout << setw(20) << left << "1: Complete System"
         << setw(15) << right << total_quantity_in_category[0] << endl;
    cout << setw(20) << left << "2: CPU"
         << setw(15) << right << total_quantity_in_category[1] << endl;
    cout << setw(20) << left << "3: Memory"
         << setw(15) << right << total_quantity_in_category[2] << endl;
    cout << setw(20) << left << "4: Printer"
         << setw(15) << right << total_quantity_in_category[3] << endl;
    cout << setw(20) << left << "5: Monitor"
         << setw(15) << right << total_quantity_in_category[4] << endl;
    cout << setw(20) << left << "6: Hard Disk"
         << setw(15) << right << total_quantity_in_category[5] << endl;
    cout << setw(20) << left << "7: Tape"
         << setw(15) << right << total_quantity_in_category[6] << endl;
    cout << setw(20) << left << "8: Miscellaneous"
         << setw(15) << right << total_quantity_in_category[7] << endl;
    
    // different format for output
    /*for (int i = 0; i < 8; i++) {
        cout << "The total quantity in Category "
        << i + 1 << " is " << total_quantity_in_category[i] << "." << endl;
    }*/
}
