#include "users.h"
#include "system.h"

Users::Users(const string & name, const string & pass, Address & add) : add(add)
{ // default c'tor
	setName(name);
	setPassword(pass);
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
}
//----------------------------------------------------------------------------------------//
void Users::setName(const string & name) noexcept(false)
{
	//the function sets the name
	for (int i = 0; i < name.length(); i++)
	{
		if (name[i] < 65 || name[i] > 122 || (name[i] < 97 && name[i] > 90)) //Name contains a digit not from the ABC
		{
			throw NameException(name);
		}
	}
	this->name = name;
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
void Users::setPassword(const string & pass)
{
	if (pass.length() < MIN_PASSWORD_SIZE)
	{
		throw PasswordException(password); //password didn't match requierments
	}
	else
	{
		this->password = pass;
	}
}
//----------------------------------------------------------------------------------------//

const string & Users::getName() const
{
	return this->name;
}
//----------------------------------------------------------------------------------------//
const Address & Users::getAddress() const
{
	return this->add;
}
//----------------------------------------------------------------------------------------//
const string & Users::getPassword() const
{
	return this->password;
}
//----------------------------------------------------------------------------------------//
const Users & Users::operator=(const Users & other)
{
	if (this != &other)
	{
		setName(other.name);;
		setPassword(other.password);
		setAddress(other.add);
	}

	return *this;
}
//----------------------------------------------------------------------------------------//
const Users & Users::operator=(Users && other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->password = other.password;
		this->add = other.add;
	}
	return *this;
}
//----------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------//

ostream & operator<<(ostream & out, Users & u)
{

	if (typeid(out) == typeid(ofstream))
		out << u.getName() << " " << u.getPassword() << " " << u.add;
	else //(typeid(out)==typeid(ostream)
		out << "User name:" << u.getName() << " User Password:" << u.getPassword() << " User Adress:" << u.add;
	return out;

}
//----------------------------------------------------------------------------------------//
void saveUsers(vector<Users *> & users, int size, const string & filename)
{
	ofstream outFile(filename, ios::trunc);
	outFile << users.size() << endl;
	vector<Users *> ::iterator itr = users.begin();
	vector<Users *> ::iterator itrend = users.end();
	for (; itr != itrend; ++itr)
		outFile << typeid(*(*itr)).name() + 6 << " " << *(*itr) << endl;
	outFile.close();
}
//----------------------------------------------------------------------------------------//

Users * loadUser(ifstream & inFile)
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
vector <Users *> loadAllUsers(const string & filename, int &numOfusers)
{
	Users *temp;
	ifstream inFile(filename, ios::in);
	inFile >> numOfusers;
	vector<Users *> UsersFromFile;
	UsersFromFile.reserve(numOfusers);// new Users[numOfusers];
	vector<Users *> ::iterator itr = UsersFromFile.begin();
	vector<Users *> ::iterator itrend = UsersFromFile.end();
	for (int i=0;i<numOfusers;i++)
	{
		temp=loadUser(inFile);
		UsersFromFile.push_back(temp);
	}
	inFile.close();
	return UsersFromFile;
}
