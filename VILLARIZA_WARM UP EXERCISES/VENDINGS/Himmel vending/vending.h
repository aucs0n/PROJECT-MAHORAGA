#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct Product
{
    char name[10];
    int stock;
    double cost;
} Product;

void showSelection(Product products[4]);
void sellProduct(Product product[4]);
void loadData(Product product[4]);
void saveData(Product product[4]);
void clrscrn();

#endif  //VENDING_MACHINE_H
