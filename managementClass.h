
#ifndef Scribble_1_2_20_2026_managementClass
#define Scribble_1_2_20_2026_managementClass
#include <string>;



class Bank {

private:
	long double m_funds{ 944'333'332.00 };
public:

	Bank();

	double getFunds() ;
	void setFunds(double funds);

};


class Client {

	std::string m_name{};
	 std::string m_accountNumber{ "" };
	std::string m_routingNumber{ "000-089-830" };
	double m_balance{};
	double m_interest{};
	double m_principle{};
	double m_owe{};
	int m_year{};


public:
	Client(std::string_view name, std::string_view accountNumber, double balance);
	
	std::string_view getName() const ;
	std::string_view getAccountNumber() const;
	std::string_view getRoutingNumber() const;

	double getOwe()const { return m_owe; };
	void setOwe(double owe) { m_owe = owe; };



	int getYear()const { return m_year; };
	void setYear(int year) { m_year = year; };
	
	double getBalance() const;
	void setBalance(double balance) { m_balance = balance; };
	
	void setPrinciple(double principle) {m_principle = principle;};
	double getPrinciple() {return m_principle;}

	double getInterest() const { return m_interest; };
	void setInterest(double amount) {m_interest = amount;}


	bool operator==(const Client& cl) const {return this->m_accountNumber == cl.m_accountNumber;};
	bool operator==(std::string_view key) const {return this->m_accountNumber == key;};
};

#endif
