#include <BankAccount.hpp>

// ===== BankAccount =====
BankAccount::BankAccount(double initial_balance) : balance_(initial_balance) {
    std::cout << "BankAccount Creation, Balance: " << balance_ << std::endl;
}

BankAccount::~BankAccount() {
    std::cout << "BankAccount Destroyed" << std::endl;
}

void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance_ += amount;
    }
}

void BankAccount::withdraw(double amount) {
    if (amount > 0 && balance_ >= amount) {
        balance_ -= amount;
    } else {
        std::cout << "Not enough balance" << std::endl;
    }
}

double BankAccount::get_balance() const {
    return balance_;
}

void BankAccount::print_details() const {
    std::cout << "Balance: " << balance_ << std::endl;
}

// ===== SavingsAccount =====

SavingsAccount::SavingsAccount(double init_bal, double rate)
    : BankAccount(init_bal), rate_(rate) {}

SavingsAccount::~SavingsAccount() {
    std::cout << "SavingsAccount destroyed" << std::endl;
}

void SavingsAccount::apply_interest() {
    balance_ += balance_ * rate_;
}
void SavingsAccount::print_details() const {
    BankAccount::print_details();
    std::cout << "Interest Rate: " << rate_ * 100 << "%" << std::endl;
}

// ===== CheckingAccount =====

CheckingAccount::CheckingAccount(double initial_balance, double overdraft_limit)
    : BankAccount(initial_balance), overdraft(overdraft_limit) {}

CheckingAccount::~CheckingAccount() {
    std::cout << "CheckingAccount destroyed" << std::endl;
}

void CheckingAccount::withdraw(double amount){
    if (amount > 0 && balance_ + overdraft >= amount) {
        balance_ -= amount;
    } else {
        std::cout << "Not enough balance" << std::endl;
    }
}
void CheckingAccount::print_details() const{
    BankAccount::print_details();
    std::cout << "Overdraft : " << overdraft << std::endl;
}

// ===== Transaction =====

Transaction::Transaction() : count{0} {}

void Transaction::add_transaction(const std::string& str){
    logs.push_back(str);
    ++count;
} 

void Transaction::print_transaction(){
    std::cout << "Transactions: " << std::endl;
    for(auto& item : logs){
        std::cout << item << std::endl;
    }
}


// ===== Account_Transaction =====

Account_Transaction::Account_Transaction(double initial_balance)
    : BankAccount(initial_balance),tr_{std::make_unique<Transaction>()} {}

Account_Transaction::~Account_Transaction() {
    std::cout << "Account_Transaction destroyed" << std::endl;
}
void Account_Transaction::deposit(double amount) {
    BankAccount::deposit(amount);
    tr_->add_transaction("Deposit " + std::to_string(amount));
}
void Account_Transaction::withdraw(double amount) {
    BankAccount::withdraw(amount);
    tr_->add_transaction("Withdrew: " + std::to_string(amount));
}

void Account_Transaction::print_details() const {
    BankAccount::print_details();
    tr_->print_transaction();
}