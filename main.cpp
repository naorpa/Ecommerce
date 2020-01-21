#include "system.h"
#include "product.h"
#include"Operation.h"

/* Omer Zidkoni 316498294 
	Naor Pashay 313524886
	Class A Keren Kalif sunday 10:15
*/
int main()
{
	int numOfUsers = 0;
	System A;
	A.SetUserArray(loadAllUsers("Users.txt", numOfUsers));
	Menu(A);
	saveUsers(A.getUserArray(), A.getLogicSize(), "Users.txt");
}


