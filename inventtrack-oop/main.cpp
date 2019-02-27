//main.cpp
//Controls the inventory tracking program.
//
//author    Michelle Adea
//version   03/10/2019

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
#include "list.h"

//function prototypes
void build_list(List &records);
void strsub(char source[], char destination[], int start, int length);

int main(int argc, const char *argv[]) {
    List inventory_list; // creates empty List object

    build_list(inventory_list);
    inventory_list.show();

    return 0;
}

void build_list(List &records) {
    ifstream infile;
    infile.open("Invent.dat");

    const int MAX = 100;
    char line[MAX];
    infile.getline(line, MAX);

    while (infile.fail() == false) {
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

        records.append(i);
        infile.getline(line, MAX);
    }

    infile.close();
}

void strsub(char source[], char destination[], int start, int length) {
    int i;
    for (i = 0; i < length; ++i)
        destination[i] = source[start++];
    destination[i] = '\0';
}