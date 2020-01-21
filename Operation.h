#ifndef __OPERATION_H
#define __OPERATION_H
#include "string.h"
#include "system.h"
#include "product.h"
#include "SystemExceptions.h"

void PrintMenu();
void Menu(System & user);
void MenuOpertaion(int oper, System & system);
void logIn(string & name, string & pass, System & user);
void Case0(System & user);
void Case3(System & user);
void Case4(System & user);
void Case5(System & user);
void Case6(System & user);
void Case7(System & user);
void Case8(System & user);
void Case9(System & user);
void Case10(System & user);
void Case11(System & user);
void Case12(System & user);
void Case1_Or_14(System & user);
void Case2_Or_15(System & user);
void logIn(char name[], char pass[], System & user);





#endif  // !OPERATION_H