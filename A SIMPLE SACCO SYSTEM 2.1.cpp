#include<iostream>
#include<string>
#include<vector>

using namespace std;
 
class Member{
	private:
		int Member_id;
		string address;
	public:
		string name;
		string email;
		string contact;
		
		Member(){}
		Member(string name,int Member_id,string contact,string email){
			this->name=name;
			this->Member_id=Member_id;
			this->contact=contact;
			this->email=email;
		}
		int get_Member_id() {
			return Member_id;
		}
		string get_name() {
			return name;
		}
		string get_contact(){
			return contact;
		}
		string get_email() {
			return email;
		}
};
class loan:public Member{
	private:
		int loan_id;
		float loan_amount;
		float interest_rate;
		int repayment_period;
		int Member_id;
	public:
		
		loan() {}
			loan(int loan_id,float loan_amount, float interest_rate, int repayment_period, int Member_id):Member(name, Member_id, contact, email){
				this->loan_id=loan_id;
				this->loan_amount=loan_amount;
				this->interest_rate=interest_rate;
				this->repayment_period=repayment_period;
				this->Member_id=Member_id;
			}
		int get_loan_id() {
			return loan_id;
		}
		float get_loan_amount() {
			return loan_amount;
		}
		float get_interest_rate() {
			return interest_rate;
		}
		int get_repayment_period() {
			return repayment_period;
		}
		int get_Member_id() {
			return Member_id;
		}
		
};
class Deposit:public Member{
	private:
		int deposit_id;
		float deposit_amount;
		int Member_id;
		string date;
	public:
		
		Deposit() {}
		    Deposit(int deposit_id, float deposit_amount, int Member_id, string date):Member(name, Member_id, contact, email){
		    	this->deposit_id=deposit_id;
		    	this->deposit_amount=deposit_amount;
		    	this->Member_id=Member_id;
		    	this->date=date;
			}
		int get_deposit_id() {
			return deposit_id;
		}
		float get_deposit_amount() {
			return deposit_amount;
		}
		int get_Member_id() {
			return Member_id;
		}
		string get_date() {
			return date;
		}
};
class Account:public Member{
	private:
		int account_id;
		float account_balance;
		int Member_id;
		float balance;
		vector<loan>loans;
		vector<Deposit>Deposits;
	public:
		
		Account() {}
		   Account(int account_id, int Member_id, float balance):Member(name, Member_id, contact, email){
		   	  this->account_id=account_id;
		   	  this->Member_id=Member_id;
		   	  this->balance=balance;
		   }
		int get_account_id() {
			return account_id;
		}
		int get_Member_id() {
			return Member_id;
		}
		void add_loan(loan loan) {
            loans.push_back(loan);
		}
		void add_deposit(Deposit deposit) {
            Deposits.push_back(deposit);
            balance += deposit.get_deposit_amount();
            }
		void print_transactions() {
        cout << "Transactions for Account:" << account_id << endl;
        for (int i = 0; i < Deposits.size(); i++) {
        cout << Deposits[i].get_date() << " Deposits of: " << Deposits[i].get_deposit_amount() << endl;
       }
        for (int i = 0; i < loans.size(); i++) {
        cout << "Loan ID: " << loans[i].get_loan_id() << " Amount: " << loans[i].get_loan_amount() << endl;
       }
    }

};
int main() {
    string name, contact, email, date;
    int member_id, loan_id, repayment_period, deposit_id, account_id, member_type;
    float loan_amount, interest_rate, deposit_amount, account_balance;
    vector<Account> accounts;
    vector<Member> members;
    vector<loan> loans;
    vector<Deposit> deposits;
    while (true) {
        cout << "Select an option:" << endl;
        cout << "1. Add a member" << endl;
        cout << "2. Add a loan" << endl;
        cout << "3. Add a deposit" << endl;
        cout << "4. Add an account" << endl;
        cout << "5. Print transactions for an account" << endl;
        cout << "6. Quit" << endl;

        int option;
        cin >> option;
        switch (option) {
            case 1:
                cout << "Enter the member name: ";
                cin >> name;
                cout << "Enter the member id: ";
                cin >> member_id;
                cout << "Enter the member contact number: ";
                cin >> contact;
                cout << "Enter the member email: ";
                cin >> email;
                cout << "Select the member type (1 for Member, 2 for Loan, 3 for Deposit): ";
                cin >> member_type;
                switch (member_type) {
                    case 1:
                        members.push_back(Member(name, member_id, contact, email));
                        break;
                    case 2:
                        loans.push_back(loan(loan_id, loan_amount, interest_rate, repayment_period, member_id));
                        break;
                    case 3:
                        deposits.push_back(Deposit(deposit_id, deposit_amount, member_id, date));
                        break;
                    default:
                        cout << "Invalid member type" << endl;
                        break;
                }
                break;
            case 2:
                cout << "Enter the loan id: ";
                cin >> loan_id;
                cout << "Enter the loan amount: ";
                cin >> loan_amount;
                cout << "Enter the interest rate: ";
                cin >> interest_rate;
                cout << "Enter the repayment period: ";
                cin >> repayment_period;
                cout << "Enter the member id: ";
                cin >> member_id;
                loans.push_back(loan(loan_id, loan_amount, interest_rate, repayment_period, member_id));
                break;
            case 3:
                cout << "Enter the deposit id: ";
                cin >> deposit_id;
                cout << "Enter the deposit amount: ";
                cin >> deposit_amount;
                cout << "Enter the member id: ";
                cin >> member_id;
                cout << "Enter the date (yyyy-mm-dd): ";
                cin >> date;
                deposits.push_back(Deposit(deposit_id, deposit_amount, member_id, date));
                break;
            case 4:
                cout << "Enter the account id: ";
                cin >> account_id;
                cout << "Enter the member id: ";
                cin >> member_id;
                cout << "Enter the account balance: ";
                cin >> account_balance;
                accounts.push_back(Account(account_id, member_id, account_balance));
                break;
            case 5:
                cout << "Enter the account id: ";
                cin >> account_id;
                for (int i = 0; i < accounts.size(); i++) {
                    if (accounts[i].get_account_id() == account_id) {
                        accounts[i].print_transactions();
                        break;
                    }
                }
        }
 }
return 0;
}

