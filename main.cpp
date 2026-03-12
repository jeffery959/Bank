#include <iostream>
#include <string>
#include <string_view>
#include <array>
#include <vector>
#include <iomanip>
#include <sstream>
#include <limits>
#include <format>
#include "managementClass.h"
#include "prompt_prints.h"
#include <algorithm>
#include <iomanip>

using namespace std::string_view_literals;
void clientSection();

template <typename T>
T getInput() {
	T x{};

	while (true) {

		std::cin >> x;



		if (!std::cin) {
			if (std::cin.eof()) {
				std::exit(0);
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Input: ";
			continue;

		}

		if (!std::cin.eof() && std::cin.peek() != '\n') {
			std::cout << "Too many inputs: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;

		}


		//if no extra inputs , not in a failed state or selected a good choice exit loop
		break;
	}

	return x;
}

template <typename T>
T getInput(std::string_view str) {
	T x{};
	std::cout << str;


	while (true) {

		std::cin >> x;


		if (!std::cin) {
			if (std::cin.eof()) {
				std::exit(0);
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid Input: ";
			continue;

		}
		if (!std::cin.eof() && std::cin.peek() != '\n') {
			std::cout << "Too many inputs: ";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;

		}



		//if no extra inputs , not in a failed state or selected a good choice exit loop
		break;
	}






	return x;
}

static std::vector<Client> clients{
Client { "Jane Smith", "92-410-8821-0034", 150.75 },
Client { "Michael Chen", "11-592-0043-7721", 5.00 },
Client { "Sarah Jenkins", "45-110-6394-8255", 1200.43 },
Client { "Oscar Vaca", "30-884-1290-3367", 45.10 },
Client { "Emily Rivera", "77-203-5518-9942", 89.22 },
Client { "David Miller", "54-661-0039-2180", 310.00 },
Client { "Aisha Khan", "88-332-7741-5509", 750.50 },
Client { "Liam O'Connor", "21-905-4428-1136", 12.99 },
Client { "Sofia Martinez", "63-118-9904-2271", 430.25 },
Client { "Jordan Taylor", "10-447-2185-6639", 0.95 },
Client { "Marcus Wright", "55-302-1194-8842", 2150.00 },
Client { "Elena Rossi", "39-772-5510-4403", 67.80 }
};


void loanSection(Bank& bank);
static int Year{2026};

std::string clientDetails(const Client& client) {

	int spacing{20};
	std::ostringstream os;

	os <<std::setw(spacing) << client.getName()<<" |" << std::setw(spacing) << client.getAccountNumber() << " |" << std::setw(spacing) << client.getRoutingNumber() << " |" << std::setw(spacing) << "$" << client.getBalance() << '\n';

	return os.str();
}
std::ostream& operator<<(std::ostream& out, Client& client) {
	return out << clientDetails(client);
}


void timeMachine() {
	retry:
	clearScreen();
	noclear:
	int years{ getInput<int>("How far in the future are we going? ") };

	if (years > 10) {
		std::cout << "Too far\n";

		goto noclear;
	}
	if (years <= 0)
		return;


	for (int i = 0; i <= years;++i) {
		std::cout<<"Year: "<<Year++<<'\n';
		for (Client& person : clients) {

			if (person.getOwe() > 0) {

				person.setOwe(person.getOwe() + (person.getPrinciple() * person.getInterest()));
				std::cout << "Name: " << person.getName() << " Owes: " << person.getOwe() << '\n';



			}

		}

		
		std::cout << "\n";

	}


	if (getInput<char>("Enter b to return to main menu: ")=='b') {
		return;
	 }


	goto retry;

	
}





//Options Handling
bool handleUserOption(char option,  Bank& bank) {
	switch (option) {
	case '0':
		clientSection();
		return true;

	case '1':
		loanSection(bank);
		return true;

	case '2':
		timeMachine();
			return true;

	case '3':
		std::exit(0);
		return false;

	default: return true;
	}
}
void handleLoanNavigation() {

}







//Sections
void mainSection( Bank& bank) {
	clearScreen();
	std::cout << "Welcome to JB Bank.ltd ";
	std::cout << std::setw(20) << std::setprecision(15) << "Funds: $" << bank.getFunds() <<std::setw(20) <<"Year: "<<Year <<'\n';
	
}





void clientSection() {

	//Template
	std::sort(clients.begin(), clients.end(), []( const Client& cl1,const Client& cl2) {

		return cl1.getName() > cl2.getName();
		});

	clearScreen();
	while(true){

	int spacing{20};
	std::cout<<'\n' << std::setw(spacing) << "Name" << std::setw(spacing) << "Account number" << std::setw(spacing) << "Routing number" << std::setw(spacing) << "Balance" << "\n";

	printLine(80);
	

	for(auto person: clients) {

		std::cout << person;
	}

	std::cout << "\nEnter b to return to main menu: ";
	
	if (getInput<char>() == 'b') {
		clearScreen();
		break;
	}
	else
		continue;

	
	}

}






void loanManager(bool collect,Bank& bank) {
	
	std::string accountNum{ getInput <std::string> ("\nEnter user account number: ") };
		
	
	auto person = std::find(clients.begin(), clients.end(), accountNum);
	if (person == clients.end()) {
		std::cout << "Client not found \n";
		while(true)
		if(getInput<char>("Enter b to go back: ")=='b')
			return;

	}

		
	while (true) {
	if (collect) {
	    
		
/*
		double owes{ person->getPrinciple() + ((Year - 2026) * person->getInterest() * person->getPrinciple()) };*/

		std::cout << person->getName() << " balance: " << person->getBalance() << " Owes: " << person->getOwe() << "\n";

		int amount = getInput<int>("Collect amount: ");
		if (person->getOwe() == 0) {
			std::cout << person->getName() << " does not owe anything";
			break;
		}
		
	    else if(amount<=person->getOwe()){

		person->setBalance(person->getBalance() - amount);


		person->setOwe(person->getOwe() - amount);


		bank.setFunds(bank.getFunds() + amount);
		
		std::cout << person->getName() << " balance: " << person->getBalance() << " Owes: " << person->getOwe() << "\n";



	
	}
	
	else {
		retry:
		std::cout << "Can not collect more than " << person->getOwe();
		if(getInput<char>("Enter b to go back: ")=='b')
		break;
		goto retry;
	}

	 
	}

	else {

		if (person->getOwe() > 0) {
			std::cout << "In order to get aprroved client has to payoff a current loan: " << person->getOwe()<<"\n";

			getInput<char>("Enter any key to proceed: ");

			return;
		}
		  
		double loan_amount = getInput<double>("loan amount: ");
		person->setPrinciple(loan_amount);
		person->setBalance(person->getBalance()+person->getPrinciple());

		
		do {

			person->setInterest(getInput<double>("Set interest rate: ")/100);
			person->setYear(Year);
			if (person->getInterest() > 100) {
				std::cout << "An interest rate this high would kill the client try something lower than or equal to 10 \n\n";


			}


		} while (person->getInterest() > 100);
		

		
	
		person->setOwe(person->getPrinciple() + ((Year - person->getYear())+1)*(person->getPrinciple() * person->getInterest())
		
		);

		bank.setFunds(bank.getFunds() - loan_amount);
		std::cout <<"\n"<<"Name: "<< person->getName() << " balance: " << person->getBalance() << " Interest: " << person->getInterest() << " Owe: " << person->getOwe() << "\n";


	};


		if (getInput<char>("Enter b to go back: ") == 'b')
		break;

	}





}
void loanSection(Bank& bank) {
	clearScreen();
	std::array options{ "Give loan"sv ,"Collect loan"sv,"Return to main menu"sv};

	while (true) {

		std::cout << std::setw(50) << "Loan Section\n";
		printOptions(options);
		
		
		char option{getInput<char>("\nEnter Option: ")};
		

		switch (option) {

		case '0':
			loanManager(false,bank);
			clearScreen();
			break;
		case '1':
			loanManager(true,bank);
			clearScreen();
			break;
		case'2':			
			return;

		default:
			std::cout << "Invalid Input:";
			
		}


		
	}


}





void runApp(Bank& bank) {
	bool runing{ true };
	while (runing) {
		std::cout <<std::setprecision(2);
		mainSection(bank);

		const std::array Options{ "View Clients"sv,"Loans"sv,"Time Machine"sv,"Exit program"sv };
		char option{ promptNOptions(Options) };
		runing =handleUserOption(option, bank);
	}
}

int main() {
	
	Bank bank{};
	runApp(bank);
	return 0;
}