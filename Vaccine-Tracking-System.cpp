#include<iostream>
#include "Linked.cpp"
#include<cstring>
#include<string>
#include"Vaccine Tracking System.h"
#include<fstream>
#include<conio.h>
#include<assert.h>

using namespace std;

struct User
{
	string fullName;
	string Gender;
	string Governorate;
	string ID;
	string Password;
	int Age;
	char vaccinated;
	int numberOfDoses;
};

bool data_change = false;
string current_user="";

Linked<User> userList;
Linked<User> waitingList;

void vaccine_mangament::writeUserList(string str) {
	ofstream fout(str, ios_base::app);
	//Node<User>* temp;
	fout << "\t" << userList.length() << "\t-";
	fout << userList.at(userList.length() - 1).fullName << "\t \t-";
	fout << "\t" << userList.at(userList.length() - 1).Age << "\t-";
	fout  /*"\t"*/ << userList.at(userList.length() - 1).ID << "-";
	fout << "\t" << userList.at(userList.length() - 1).Password << "\t-";
	fout << "\t" << userList.at(userList.length() - 1).Gender << "\t-";
	fout << "\t" << userList.at(userList.length() - 1).Governorate << "\t \t-";
	fout << "\t\t" << userList.at(userList.length() - 1).numberOfDoses << endl;
	fout.close();
}

void vaccine_mangament::writewaitingList(string str) {
	ofstream fout(str, ios_base::app);
	//Node<User>* temp;
	fout << "\t" << waitingList.length() - 1 << "\t-";
	fout << waitingList.at(waitingList.length()).fullName << "\t \t-";
	fout << "\t" << waitingList.at(waitingList.length() - 1).Age << " \t-";
	fout << "\t" << waitingList.at(waitingList.length() - 1).ID << "\t -";
	fout << "\t" << waitingList.at(waitingList.length() - 1).Password << "\t-";
	fout << "\t" << waitingList.at(waitingList.length() - 1).Gender << "\t-";
	fout << "\t" << waitingList.at(waitingList.length() - 1).Governorate << endl;
	fout.close();
}

void vaccine_mangament::readUserList(string str) {
	ifstream fout;
	fout.open(str);
	if (fout.is_open()) {
		while (fout.good()) {
			User newUser;
			string s;
			getline(fout, s, '-');
			newUser.fullName = s;
			getline(fout, s, '-');
			newUser.Age = atoi(s.c_str());
			getline(fout, s, '-');
			newUser.ID = s;
			getline(fout, s, '-');
			newUser.Password = s;
			getline(fout, s, '-');
			newUser.Gender = s;
			getline(fout, s, '-');
			newUser.Governorate = s;
			getline(fout, s);
			newUser.numberOfDoses = atoi(s.c_str());
			newUser.vaccinated = 'y';
			userList.append(newUser);
		}
		fout.close();
	}
}

void vaccine_mangament::readwaitingList(string str) {
	ifstream fout;
	fout.open(str);
	if (fout.is_open()) {
		while (fout.good()) {
			User newUser;
			string s;
			getline(fout, s, '-');
			newUser.fullName = s;
			getline(fout, s, '-');
			newUser.Age = atoi(s.c_str());
			getline(fout, s, '-');
			newUser.ID = s;
			getline(fout, s, '-');
			newUser.Password = s;
			getline(fout, s, '-');
			newUser.Gender = s;
			getline(fout, s);
			newUser.Governorate = s;
			newUser.vaccinated = 'n';
			waitingList.append(newUser);
		}
		fout.close();
	}
}

void vaccine_mangament::Organizer()
{
	User user_OP;

	cout << "Enter name :";
	cin.ignore();
	getline(cin, user_OP.fullName);

	cout << "Enter Gender :";
	cin >> user_OP.Gender;

	cout << "Enter GOV :";
	cin >> user_OP.Governorate;

	cout << "Enter Id :";	
		cin >> user_OP.ID;

	cout << "Enter age :";
	cin >> user_OP.Age;

	cout << "Enter passowrd :";
	cin >> user_OP.Password;

	{
		cout << " If Already Vaccinated \"Y\",  If NOT \"N\" ";
		cin >> user_OP.vaccinated;
		if (user_OP.vaccinated == 'y' || user_OP.vaccinated == 'Y')
		{
			cout << " How Many Doses Had Taken: ";
			cin >> user_OP.numberOfDoses;
			userList.append(user_OP);
			data_change = true;
		}

		else if (user_OP.vaccinated == 'n' || user_OP.vaccinated == 'N')
		{
			waitingList.append(user_OP);
			data_change = true;
		}
	}

	cout <<"\n\n\Information saved successfully\n";
	system("PAUSE");
	user();

}

void vaccine_mangament::menu() {
	system("cls");
	int choice;
	cout << "\n\t\t\t\t\t\t* Vaccine Mangament System *";
	cout << "\n\n\t\t-->> MAIN MENU <<--";
	cout << "\n\n\t\t -->>1.Admin";
	cout << "\n\t\t -->>2.User";
	cout << "\n\t\t -->>3.Exit";
	cout << "\n\n\t\t Enter choice:";
	cin >> choice;

	switch (choice)
	{
	case 1:
		admin_verfiy();
		break;
	case 2:
		user();
		break; 
	case 3: {
		if (data_change) {
			writeUserList("fileUserList.txt");
			writewaitingList("filewaitingList.txt");
		}
		system("cls");
		exit(0);
		break;
	}

	default:
		cout << "\n\n\t\t Invalid Choice";
		cout << "\n\n\t\t Press Any Key To Continue";
		menu();
	}

}

void vaccine_mangament::admin_verfiy() {
	system("cls");
	char a_name[20];
	char a_pass[20];
	int ch, i = 0;
	cout << "\n\t\t\t\t\t\t* Vaccine Mangament System *";
	cout << "\n\n\t\t-->> Logi Admin <<--";
	cout << "\n\n\t\tEnter Your Name ";
	cin >> a_name;
	cout << "\n\n\t\tEnter Your Passwrod ";
	while ((ch = _getch()) != 13) {
		cout << "*";
		a_pass[i] = ch;
		i++;
	}
	a_pass[i] = '\0';
	

	if ((strcmp(a_name, "admin") == 0) && (strcmp(a_pass, "admin") == 0)) {
		cout << "\n\nAccess Granted\n\n";
		system("PAUSE");
		system("cls");
		admin();
	}

	else {
		cout << "\n\nAccess Denied\n\n";
		system("PAUSE");
		system("cls");
		menu();

	}
	
}

void vaccine_mangament::admin() {
	system("cls");
	//admin_verfiy();
	int admin_choice;
	cout << "\n\t\t\t\t\t\t* Vaccine Mangament System *";
	cout << "\n\n\t\t ADMIN MENU";
	cout << "\n\n\t\t -->>1. View Reocrds";
	cout << "\n\t\t -->>2. View records filtered by the number of doses";
	cout << "\n\t\t -->>3. Delete Reocrds";
	cout << "\n\t\t -->>4. View records of vaccinated users ordered by the age of the user";
	cout << "\n\t\t -->>5. View the record of the user that needs to be vaccinated from the waiting list";
	cout << "\n\t\t -->>6. Percentage of people registered in the system that have received the first dose";
	cout << "\n\t\t -->>7. Percentage of people registered in the system that have received both doses";
	cout << "\n\t\t -->>8. Percentage of Females and Males registered in the system";
	cout << "\n\n\t\t -->>9. LOG OUT";
	cout << "\n\n\t\t Enter Choice:";
	cin >> admin_choice;
	switch (admin_choice)
	{
		char ch;
		case 1:
			cout << "\n\t\t\t\t\t\t* Vaccine Mangament System *";
			cout << "\n\n\t\t ADMIN MENU\n\n";
			search_by_id();
			cout << "\n\n\t\t -->>enter esc to Get Back. ";
			if (ch = _getch() == 27) {
				admin();
			}
			break;
			
		case 2:
			cout << "\n\t\t\t\t\t\t* Vaccine Mangament System *";
			cout << "\n\n\t\t ADMIN MENU\n\n";
			filter_data_number_of_dose();
			cout << "\n\n\t\t -->>enter esc to Get Back. ";
			if (ch = _getch() == 27) {
				admin();
			}
			break;

		case 3:
			break;

		case 4:
			Calc_vac_under18();
			Calc_vac_above50();
			cout << "\n\n\t\t -->>enter esc to Get Back. ";
			if (ch = _getch() == 27) {
				admin();
			}
			break;
		case 5:
			break;
		case 6:
			Calc_Vac_oneDose();
			cout << "\n\n\t\t -->>enter esc to Get Back. ";
			if (ch = _getch() == 27) {
				admin();
			}
			break;
		case 7:
			Calc_Vac_twoDose();
			cout << "\n\n\t\t -->>enter esc to Get Back. ";
			if (ch = _getch() == 27) {
				admin();
			}
			break;
		case 8:
			Calc_males_females();
			cout << "\n\n\t\t -->>enter esc to Get Back. ";
			if (ch = _getch() == 27) {
				admin();
			}
			break;
		case 9:

			break;
	default:
		break;
	}




}

void vaccine_mangament::user() {
	bool verfiy=user_verfiy();
	if (verfiy) {
		system("cls");
		int user_choice;
		cout << "\n\t\t\t\t\t\t* Vaccine Mangament System *";
		cout << "\n\n\t\t USER MENU";
		cout << "\n\t\t -->>1. Apply for vaccine";
		cout << "\n\t\t -->>2. Display My Reocrds";
		cout << "\n\t\t -->>3. Update My Records";
		cout << "\n\t\t -->>4. Delete My Records";
		cout << "\n\t\t -->>5. LOG OUT";
		cout << "\n\n\t\t Enter Choice:";
		cin >> user_choice;
		switch (user_choice)
		{
		case 1:
			system("cls");
			cout << "\n\t\t\t\t\t\t* Vaccine Mangament System *";
			cout << "\n\n\t\t Please Enter Your  Information\n\n";
			Organizer();
			break;
		case 2:
			search_by_id();
			break;
		case 3:
			editUser();
			user();
			break;
		case 4:
		default:
			break;
		}
	}
	else {
		cout << "Try Again";
	}
}

bool vaccine_mangament::user_verfiy() {
	system("cls");
	int user_choice, ch, i = 0;
	string fname;
	ofstream fileo;
	ifstream filei;
	cout << "\n\t\t\t\t\t\t* Vaccine Mangament System *";
	cout << "\n\n\t\t USER SUB-MENU";
	cout << "\n\n\t\t -->>1.Create Account";
	cout << "\n\t\t -->>2.Login";
	cout << "\n\t\t -->>3.Back";
	cout << "\n\n\t\t Enter Choice:";
	cin >> user_choice;
	if (user_choice == 1) {
		system("cls");
		cout << "\n\n\t\t REGISTRATION";
		cout << "\n\n\t\t Enter Your Name:";
		cin.ignore();
		getline(cin, username);
		cout << "\n\n\t\t Enter Your Password:";
		while ((ch = _getch()) != 13) {
			cout << "*";
			passwrod[i] = ch;
			i++;
		}
		passwrod[i] = '\0';
		fname = username + ".txt";
		fileo.open(fname);
		fileo << endl << username << endl << passwrod;
		cout << "\n\n\t\t You Are Successfully Registered ";
		system("PAUSE");
		fileo.close();
		user();
	}
	else if (user_choice == 2) {
		system("cls");
		string u_name;
		string u_password;
		cout << "\n\t\t\t\t\t\t* Vaccine Mangament System *";
		cout << "\n\n\t\t --> Login User <-- ";
		cout << "\n\n\t\t Enter Your Username: ";
		cin >> u_name;
		cout << "\n\n\t\t Enter Your Password: ";
		cin >> u_password;
		fname = u_name + ".txt";
		filei.open(fname);
		if (!filei.is_open() && filei.fail()) {
			cout << "\n You Are Not Registered, Please Create an Account.";
			system("PAUSE");
			filei.close();
			user_verfiy();
		}

		if (u_name == username && u_password == passwrod) {
			current_user = u_name;
			cout << "\n\tLogin Successfually as "<<current_user<<endl;
			system("PAUSE");
			return true;
		}
	}

	else if (user_choice == 3) {
		menu();
	}
	else {
	}
}

void vaccine_mangament::search_by_id() {
	system("cls");
	string id;
	bool found = false;
	cout << "Please Enter The User ID You want To Display Their Records:\n\n";
	cin >> id;
	for (int i = 0; i < userList.length(); i++) {
		if (userList.at(i).ID == id) {
			cout << "\tName:" << userList.at(i).fullName << endl;
			cout << "\tAge:" << userList.at(i).Age << endl;
			cout << "\tID:" << userList.at(i).ID << endl;
			cout << "\tGender:" << userList.at(i).Gender << endl;
			cout << "\tNumber Of Doses:" << userList.at(i).numberOfDoses << endl;
			cout << "\tGovernorate:" << userList.at(i).Governorate << "\n\n";
			found = true;
			system("PAUSE");
			menu();
			break;
		}
	}

	if (!found) {
		cout << "The ID you entered was not found. Please enter a valid ID.\n";
		system("PAUSE");
		user();
	}

}

void vaccine_mangament::editUser() {
	string userId;
	cout << "Enter your ID to edit: ";
	cin >> userId;

	int pos = -1;
	for (int i = 0; i < userList.length(); i++) {
		User user = userList.at(i);
		if (user.ID == userId) {
			pos = i;
			break;
		}
	}

	if (pos == -1) {
		cout << "Error: User not found" << endl;
		system("PAUSE");
		return;
	}

	userList.delete_fun(pos);

	User currentUser = userList.at(pos);


	cout << "Current User Data:" << endl;
	cout << "Full Name: " << currentUser.fullName << endl;
	cout << "Gender: " << currentUser.Gender << endl;
	cout << "Age: " << currentUser.Age << endl;
	cout << "ID: " << currentUser.ID << endl;
	cout << "Password: " << currentUser.Password << endl;
	cout << "Governorate: " << currentUser.Governorate << endl;
	cout << "Vaccinated: " << currentUser.vaccinated << endl;
	cout << "Number of Doses: " << currentUser.numberOfDoses << endl;

	int field;
	cout << "Fields to edit: " << endl;
	cout << "1. Full Name" << endl;
	cout << "2. Gender" << endl;
	cout << "3. Age" << endl;
	cout << "4. ID" << endl;
	cout << "5. Password" << endl;
	cout << "6. Governorate" << endl;
	cout << "7. Vaccinated" << endl;
	cout << "8. Number of Doses" << endl;
	cout << "Enter the number of the field you want to edit: ";
	cin >> field;

	string newValue;
	cout << "Enter the new value: ";
	cin.ignore();
	getline(cin, newValue);

	switch (field) {
	case 1:
		currentUser.fullName = newValue;
		data_change = true;
		break;
	case 2:
		currentUser.Gender = newValue;
		data_change = true;
		break;
	case 3:
		currentUser.Age = stoi(newValue);
		data_change = true;
		break;
	case 4:
		currentUser.ID = newValue;
		data_change = true;
		break;
	case 5:
		currentUser.Password = newValue;
		data_change = true;
		break;
	case 6:
		currentUser.Governorate = newValue;
		data_change = true;
		break;
	case 7:
		currentUser.vaccinated = newValue[0];
		data_change = true;
		break;
	case 8:
		currentUser.numberOfDoses = stoi(newValue);
		data_change = true;
		break;
	default:
		cout << "Invalid field number" << endl;
		editUser();
	}

	userList.update(pos, currentUser);

	cout << "Updated User Data:" << endl;
	cout << "Full Name: " << currentUser.fullName << endl;
	cout << "Gender: " << currentUser.Gender << endl;
	cout << "Age: " << currentUser.Age << endl;
	cout << "ID: " << currentUser.ID << endl;
	cout << "Password: " << currentUser.Password << endl;
	cout << "Governorate: " << currentUser.Governorate << endl;
	cout << "Vaccinated: " << currentUser.vaccinated << endl;
	cout << "Number of Doses: " << currentUser.numberOfDoses << endl;

	system("PAUSE");
}

void vaccine_mangament::filter_data_number_of_dose() {
		system("cls");
		int num;
		cout << "Enter Number Of Dose 1 Or 2\n";
		cin >> num;
		if (num != 1 && num != 2) {
			cout << "Wrong Choice Please Enter 1 Or Two\n";
			system("PAUSE");
			return filter_data_number_of_dose();
		}

		for (int i = 0; i < userList.length(); i++) {
			if (userList.at(i).numberOfDoses == num) {
				cout << "\tName:" << userList.at(i).fullName << endl;
				cout << "\tAge:" << userList.at(i).Age << endl;
				cout << "\tID:" << userList.at(i).ID << endl;
				cout << "\tGender:" << userList.at(i).Gender << endl;
				cout << "\tNumber Of Doses:" << userList.at(i).numberOfDoses << endl;
				cout << "\tGovernorate:" << userList.at(i).Governorate << "\n\n";
			}
		}
		
	}

void vaccine_mangament::Calc_Vac_oneDose()
	{

		int  count_of_onevac = 0;

		assert(!userList.isEmpty());
		for (int i = 0; i < userList.length(); i++)
		{
			if (userList.at(i).vaccinated == 'Y' && userList.at(i).numberOfDoses == 1)
				count_of_onevac++;
		
		}

		int percentage = (count_of_onevac / userList.length()) * 100;
		cout << "percentage of vaccined people with one dose = " << percentage << " %" << endl;
	}

void vaccine_mangament::Calc_Vac_twoDose()
	{
		
		int  count_of_vac = 0;

		assert(!userList.isEmpty());
		for (int i = 0; i < userList.length(); i++)
		{
			if (userList.at(i).vaccinated == 'Y' && userList.at(i).numberOfDoses == 2)
				count_of_vac++;
				
		}
		int percentage = (count_of_vac / userList.length()) * 100;
		cout << "percentage of vaccined people with two doses = " << percentage << " %" << endl;
	}

void vaccine_mangament::Calc_males_females()
	{
		
		int count_male = 0;
		int count_female = 0;
		
		assert(!userList.isEmpty());
		for (int i = 0; i < userList.length(); i++)
		{
			if (userList.at(i).Gender == "male")
			{
				count_male++;
			}
			else if (userList.at(i).Gender == "female")
			{
				count_female++;
			}
				
			
		}
		int percentage_of_males = (count_male / userList.length());
		int percentage_of_females = (count_female / userList.length());
		cout << "percentage of Males and Females  = " << percentage_of_males + percentage_of_females << "%" << endl;
		cout << "percentage of Males  = " << percentage_of_males << "%" << endl;
		cout << "percentage of Females  = " << percentage_of_females << "%" << endl;
	}

void vaccine_mangament::Calc_vac_Governorate()
	{
		string Gov;
		int count_vac = 0;
		int count_people = 0;

		assert(!userList.isEmpty());
		cout << " Enter name of Governorate " << endl;
		cin >> Gov;
		for (int i = 0; i < userList.length(); i++)
		{
			if (userList.at(i).Governorate == Gov)
			{
				count_people++;
				if (userList.at(i).vaccinated == 'Y')
				{
					 count_vac++ ;
					
				}
			}
		}
		int percentage = (count_vac / count_people) * 100;
		cout << "percentage of vaccined people in = " << Gov << " is " << percentage << " %" << endl;
	}

void vaccine_mangament::Calc_vac_above50()
	{
		int count_people = 0;

		assert(!userList.isEmpty());

		for (int i = 0; i < userList.length(); i++)
		{
			if (userList.at(i).Age > 50)
				count_people++;
		}
		int percentage = (count_people / userList.length()) * 100;
		cout << " People who have received the vaccine over the age of 50  = " << percentage << " %" << endl;
	}

void vaccine_mangament::Calc_vac_under18()
	{
		int count_people = 0;

		assert(!userList.isEmpty());

		for (int i = 0; i < userList.length(); i++)
		{
			if (userList.at(i).Age < 18)
				count_people++;
		}
		int percentage = (count_people / userList.length()) * 100;
		cout << " People who have received the vaccine under the age of 18  = " << percentage << " %" << endl;
	}

int main() {
	system("color B");
	vaccine_mangament system;
	system.readUserList("fileUserList.txt");
	//system.readwaitingList("filewaitingList.txt");
	system.menu();
	return 0;
}