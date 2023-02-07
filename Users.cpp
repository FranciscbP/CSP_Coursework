//Made By Francisco Pedrosa (N0883131)
#include <../../Users.h>

const string FILE_DEST = "users.txt";

Users::Users()
{

}

//Set User Num
void Users::setNum(int num)
{
	userNum = num;
}

//Create User -> Add User to txt File
void Users::createUser(string name, string password)
{
	//Encrypt Password
	string passwordHash;
	passwordHash = createHash(password);

	fstream f(FILE_DEST, ios::in | ios::out | ios::app);

	f << name << " PSWD: " << passwordHash << " MONEY: 0\n";
	f.close();
}

//Log User -> Check Name and Encrypted Password
int Users::logUser(string name, string password)
{
	int len = 0;
	string L = "";
	string dataUsername = "";
	string delimiter1 = " PSWD: ";
	string delimiter2 = " MONEY: ";
	string dataPasswordAndMoney = "";
	string dataPsswd = "";

	//User NUM
	int userLine = 0;
	userLine = checkUsername(name);

	//Encrypt Password
	string passwordHash;
	passwordHash = createHash(password);

	if (userLine != 0)
	{
		ifstream f(FILE_DEST);

		vector <string> userData;
		string line = "";
		int cont = 0;

		//Get File Lines
		while (getline(f, line))
		{
			userData.push_back(line);
			cont = cont + 1;
		}
		f.close();

		//Get Money on String
		L = userData[userLine - 1];
		dataUsername =  L.substr(0, L.find(delimiter1));
		len = dataUsername.size() + delimiter1.size() ;
		dataPasswordAndMoney = L.substr(len);
		dataPsswd = dataPasswordAndMoney.substr(0, dataPasswordAndMoney.find(delimiter2));

		if (passwordHash == dataPsswd)
		{
			return userLine;
		}
		else
		{
			return 0;
		}

	}
	else
	{
		return 0;
	}
}

//Check If User Exists -> Return User Number
int Users::checkUsername(string username)
{
	ifstream f(FILE_DEST);

	if (f.is_open())
	{
		vector <string> userData;
		string line = "";
		int cont = 0;

		string dataName;
		int vectLines = 0;
		int userLine = 0;

		//Get File Lines
		while (getline(f, line))
		{
			userData.push_back(line);
			cont = cont + 1;
		}

		f.close();

		vectLines = userData.size();

		//Get User Name and Compare It
		for (int cont = 0; cont < vectLines; cont++)
		{
			dataName = userData[cont].substr(0, userData[cont].find(" PSWD: "));

			if (dataName == username)
			{
				userLine = cont + 1;
			}

		}

		return userLine;
	}
	else
	{
		return 0;
	}

}

//Encrypt Password with Hash
string Users::createHash(string passwd)
{
	size_t hashedPasswd;
	string hashedStringPassword;

	// Creating hash
	hash <string> mystdhash;

	hashedPasswd = mystdhash(passwd);

	hashedStringPassword = convertHashtoString(hashedPasswd);

	return hashedStringPassword;
}

//Convert Hash to String
string Users::convertHashtoString(size_t hash)
{
	stringstream ss;

	ss << hash;

	return ss.str();
}

//Get User MOney
int Users::getMoney()
{	
	int money;
	int len = 0;
	string userLine = "";
	string dataNotMoney = "";
	string dataMoney = "";
	string delimiter = " MONEY: ";

	//Read File
	ifstream f(FILE_DEST);
	
	vector <string> userData;
	string line = "";
	int cont = 0;

	//Get File Lines
	while (getline(f, line))
	{
		userData.push_back(line);
		cont = cont + 1;
	}
	f.close();

	//Get Money on String
	userLine = userData[userNum - 1];
	dataNotMoney = userLine.substr(0, userLine.find(delimiter));
	len = dataNotMoney.size() + delimiter.size();
	dataMoney = userLine.substr(len);

	money = stoi(dataMoney);
	
	return money;

}

//Update Money in txt File
void Users::updateMoney(int updatedMoney)
{

	if (updatedMoney >= 9999999)
	{
		updatedMoney == 9999999;
	}

	int money = 0;
	int vectLines = 0;
	string moneyString;
	string updatedMoneyString;
	string lineToChange;
	
	int len;
	string dataToMoney="";
	string delimiter = " MONEY: ";

	//Read File
	ifstream f(FILE_DEST);

	vector <string> userData;
	string line = "";
	int cont = 0;

	//Get File Lines
	while (getline(f, line))
	{
		userData.push_back(line);
		cont = cont + 1;
	}
	f.close();

	//Get Money
	money = getMoney();

	//From int to String
	moneyString = to_string(money);
	updatedMoneyString = to_string(updatedMoney);

	lineToChange = userData[userNum - 1];

	//Get Lenght
	dataToMoney = lineToChange.substr(0, lineToChange.find(delimiter));
	len = dataToMoney.size() + delimiter.size();

	//Update Money
	lineToChange.replace(len,len,updatedMoneyString);

	//Replace it in Vector
	userData[userNum - 1] = lineToChange;

	//Write File
	ofstream file(FILE_DEST);
	vectLines = userData.size();

	for (int cont = 0; cont < vectLines; cont++)
	{
		file << userData[cont] << "\n";
	}

	file.close();
	

}

