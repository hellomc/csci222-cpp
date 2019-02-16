//
//  main.cpp
//  inventory-tracking
//
//  Created by Michelle Adea on 02/15/19.
//  Copyright © 2019 Michelle Adea. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
#include <iomanip>

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

struct list {
    item *first;
    item *last;
};

//function prototypes
int menu_display();
void build_list(list *inventory_list);
void strsub(char source[], char destination[], int start, int length);
void append(item *i, list *p);
void print_list(list *inventory_list);
void total_quantity(list *inventory_list);
void total_quantity_per_category(list *inventory_list);

int main(int argc, const char * argv[]) {
    list inventory_list;
    
    inventory_list.first = 0; //null pointer
    inventory_list.last = 0;  //null pointer
    
    build_list(&inventory_list);
    
    int choice;
    do {
        choice = menu_display();
        switch(choice) {
            case 1: print_list(&inventory_list); break;
            case 2: total_quantity(&inventory_list); break;
            case 3: total_quantity_per_category(&inventory_list);
            case 4: cout << "Program Exited" << endl;
        }
    } while (choice != 4);
    return 0;
}

int menu_display() {
    cout << "\n*****Inventory Menu*****"
    << "\n1. Display Inventory"
    << "\n2. Total Quantity Report"
    << "\n3. Category Summary Report"
    << "\n4. Exit the Program"
    << "\nEnter an option from 1 to 4: " << endl;
    
    int option;
    cin >> option;
    
    return option;
}

void strsub(char source[], char destination[], int start, int length) {
    int i;
    for (i = 0; i < length; ++i)
        destination[i] = source[start++];
    destination[i] = '\0';
}

// creates the linked list that contains information from the "invent.dat" file
void build_list(list *inventory_list) {
    ifstream infile;
    infile.open("Invent.dat");
    
    const int MAX = 100;
    char line[MAX];
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
        infile.getline(line, MAX);
    }
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

// each struct item's information is printed out from the struct list
void print_list(list *inventory_list) {
    item *p = inventory_list->first;
    
    if (p) {
        cout << "*********Inventory List*********" << endl;
        cout << setw(10) << left << "Item No."
        << setw(25) << left << "Item Description"
        << setw(10) << left << "Quantity"
        << setw(15) << "Category Code"
        << setw(15) << "Supplier Code"
        << setw(11) << right << "Unit Cost"
        << setw(11) << right << "Unit Price"
        << endl;
        cout << showpoint << setprecision(2) << fixed;
    }
    
    while (p != 0) {
        cout << setw(10) << left << p->numId
        << setw(25) << left << p->name
        << setw(10) << left << p->quantity
        << setw(15) << p->categoryCode
        << setw(15) << p->supplierCode
        << setw(11) << right << p->unitCost
        << setw(11) << right << p->unitPrice
        << endl;
        p = p->next;
    }
}

// determines the total amount of items in the inventory list
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
    for (int i = 0; i < 8; i++) {
        cout << "The total quantity in Category "
        << i + 1 << " is " << total_quantity_in_category[i] << "." << endl;
    }
}
