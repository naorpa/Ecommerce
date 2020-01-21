#include "users.h"
#include "system.h"

Users::Users(const char * name, const char * password, Address & add) : add(add)
{ // default c'tor
	setName(name);
	setPassword(password);
}
//----------------------------------------------------------------------------------------//
Users::Users(const Users & other) : add(other.add)
{
	setName(other.name);
	setPassword(other.password);
}
//----------------------------------------------------------------------------------------//
Users::~Users()
{
	delete[] this->password;
	delete[] this->name;
}
//----------------------------------------------------------------------------------------//
void Users::setName(const char * name)
{
	//the function sets the name
	this->name = strdup(name);
}
//----------------------------------------------------------------------------------------//
void Users::setAddress(const Address & address)
{
	//the function sets the address
	this->add.setCity(address.getCity());
	this->add.setState(address.getState());
	this->add.setStreet(address.getStreet());
}
//----------------------------------------------------------------------------------------//
bool Users::setPassword(const char * password)
{
	if (strlen(password) < MIN_PASSWORD_SIZE)
	{
		cout << "The password must contain a least 6 digits or numbers, please enter a new one" << endl;
		return 0; //password didn't match requierments
	}
	else
	{
		this->password = strdup(password);
		return 1; //password has set
	}
}
//----------------------------------------------------------------------------------------//

const char * Users::getName() const
{
	return this->name;
}
//----------------------------------------------------------------------------------------//
const Address & Users::getAddress() const
{
	return this->add;
}
//----------------------------------------------------------------------------------------//
const char * Users::getPassword() const
{
	return this->password;
}
//----------------------------------------------------------------------------------------//
const Users & Users::operator=(const Users & other)
{
	if (this != &other)
	{
		delete[] this->name;
		setName(other.name);
		delete[]this->password;
		setPassword(other.password);
		setAddress(other.add);//
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const Users & Users::operator=(Users && other)
{
	if (this != &other)
	{
		delete[] this->name;
		this->name = other.name;
		delete[]this->password;
		this->password = other.password;
		other.name = nullptr;
		other.password = nullptr;
		this->add = other.add;
	}
	return *this;
}

//----------------------------------------------------------------------------------------//

ostream & operator<<(ostream & out, Users & u)
{
		
		if (typeid(out) == typeid(ofstream))
			out << u.getName() << " " << u.getPassword() << " "<<u.add;
		else //(typeid(out)==typeid(ostream)
			out << "User name:" << u.getName() << " User Password:" << u.getPassword() << " User Adress:" << u.add;
		return out;
	
}
//----------------------------------------------------------------------------------------//
void saveUsers(Users ** users, int size, const char * filename)
{
	ofstream outFile(filename, ios::trunc);
	outFile << size << endl;
	for (int i = 0; i < size; i++)
		outFile << typeid(*users[i]).name() + 6 << " " << *users[i] << endl;
	outFile.close();
}
//----------------------------------------------------------------------------------------//
Users ** loadAllUsers(const char * filename, int &numOfusers)
{

	ifstream inFile(filename, ios::in);
	inFile >> numOfusers;
	Users ** UsersFromFile = new Users*[numOfusers];
	for (int i = 0; i < numOfusers; i++)
	{
			UsersFromFile[i] = loadUser(inFile);
	}
	inFile.close();
	return UsersFromFile;
}
Users *loadUser(ifstream & inFile)
{
	Users *temp;
	char type[Users::TYPE_LEN + 1];
	inFile >> type;
	type[Users::TYPE_LEN] = '\0';
	if (strcmp(typeid(BNS).name() + 6, type) == 0)
	{
		temp = new BNS(inFile);
		return temp;
	}
	if (strcmp(typeid(Buyer).name() + 6, type) == 0)
	{
		temp = new Buyer(inFile);
		return temp;
	}
	if (strcmp(typeid(Seller).name() + 6, type) == 0)
	{
		temp = new Seller(inFile);
		return temp;
	}
	else
		return NULL;
}




