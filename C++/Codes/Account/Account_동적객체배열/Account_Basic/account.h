#ifndef ACCOUNT_H
#define ACCOUNT_H
const int NAME_LEN = 20;
class Account {
private:
	int id;
	int balance;
	char* name;
public:
	Account();
	Account(int _id, int _balance, const char* _name);
	Account(const Account& acc);
	~Account();
	Account& operator=(const Account& acc);
	void ShowAllData();
	int InMoney(int val);
	bool OutMoney(int val);
	int getId();
	int getBalance();
	char* getName();
	void setId(int _id);
	void setBalance(int _balance);
	void setName(const char* _name);
};

#endif