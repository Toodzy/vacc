class vaccine_mangament {
protected:
	string username;
	char passwrod[20];
public:
	void menu();
	void admin();
	void admin_verfiy();
	void user();
	bool user_verfiy();
	void writeUserList(string str);
	void writewaitingList(string str);
	void readUserList(string str);
	void readwaitingList(string str);
	void Organizer();
	void search_by_id();
	void filter_data_number_of_dose();
	void Calc_Vac_oneDose();
	void Calc_Vac_twoDose();
	void Calc_males_females();
	void Calc_vac_Governorate();
	void Calc_vac_above50();
	void Calc_vac_under18();
	void editUser();
};