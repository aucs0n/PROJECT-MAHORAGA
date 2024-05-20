
#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct      // struct declaration
{
    char name[50];
    int cost;
    int pcs;
} Item;

void showSelection(Item items[4]);
void sellProduct(Item items[4]);       //function prototypes
void loadData(Item items[4]);
void saveData(Item items[4]);
void clrscrn();

#endif
