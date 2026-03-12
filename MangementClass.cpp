#include <string>
#include "managementClass.h"








Bank::Bank() {};
double Bank::getFunds()  { return m_funds; };
void Bank::setFunds(double funds) { m_funds = funds; };



	Client::Client(std::string_view name, std::string_view accountNumber, double balance)
		:m_name{ name }, m_accountNumber{ accountNumber }, m_balance{ balance }
	{

	}

	std::string_view Client::getName() const { return m_name; };

	std::string_view Client::getAccountNumber() const { return  m_accountNumber; };

	std::string_view Client::getRoutingNumber() const { return m_routingNumber; };

	double Client::getBalance() const { return m_balance; };



