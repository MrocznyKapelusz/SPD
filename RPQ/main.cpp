// RPQ.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Czas.h"
#include "dane.h"
#include "klasa.h"

int main()
{
    int n1, n2, n3, n4;
    RPQ tab1[64];  
    RPQ tab2[64];  
    RPQ tab3[64];  
    RPQ tab4[64];  
    RPQ *wsktab1, *wsktab2, *wsktab3, *wsktab4;
    wsktab1 = tab1;
    wsktab2 = tab2;
    wsktab3 = tab3;
    wsktab4 = tab4;
    wczytaj(&n1, wsktab1, DATA_1);
    wczytaj(&n2, wsktab2, DATA_2);
    wczytaj(&n3, wsktab3, DATA_3);
    wczytaj(&n4, wsktab4, DATA_4);
    RPQ_Sort(n1, wsktab1);
    RPQ_Sort(n2, wsktab2);
    RPQ_Sort(n3, wsktab3);
    RPQ_Sort(n4, wsktab4);
    wypisz(&n1, wsktab1);
    wypisz(&n2, wsktab2);
    wypisz(&n3, wsktab3);
    wypisz(&n4, wsktab4);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
