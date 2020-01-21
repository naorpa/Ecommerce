#include "system.h"
#include "product.h"
#include"Operation.h"

#include <iostream>
#include <string.h>
#include <ostream>
#include <fstream>
#include <string>

/* Omer Zidkoni 316498294 
	Naor Pashay 313524886
	Class A Keren Kalif sunday 10:15
*/
int main()
{
	int numOfUsers = 0;
	System A;
	A.SetUsersArray(loadAllUsers("Users.txt",numOfUsers));
	A.setLogicSize(numOfUsers);
	Menu(A);

   saveUsers(A.getUserArray(), A.getLogicSize(), "Users.txt");
}


