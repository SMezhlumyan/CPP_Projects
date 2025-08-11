#pragma once

#include <vector>
#include <memory>
#include <iostream>
#include <string>

// ===== BankAccount =====
class BankAccount {
protected:
    double balance_;
public:
    BankAccount(double initial_balance);
    virtual ~BankAccount();

    virtual void deposit(double amount);
    virtual void withdraw(double amount);

    double get_balance() const;
    virtual void print_details() const;
};

// ===== SavingsAccount =====

class SavingsAccount : public BankAccount {
private:
    double rate_;
public:
    SavingsAccount(double init_bal, double rate);
    ~SavingsAccount();

    void apply_interest();
    void print_details() const override;
};

// ===== CheckingAccount =====

class CheckingAccount : public BankAccount {
private:
    double overdraft;
public:
    CheckingAccount(double initial_balance, double overdraft_limit);
    ~CheckingAccount();

    void withdraw(double amount) override;
    void print_details() const override;
};

// ===== Transaction =====

class Transaction {
private:
    size_t count;
    std::vector<std::string> logs;
public:
    Transaction();

    void add_transaction(const std::string& str);
    void print_transaction();
};

// ===== Account_Transaction =====

class Account_Transaction : public BankAccount {
private:
    std::unique_ptr<Transaction> tr_;
public:
    Account_Transaction(double initial_balance);
    ~Account_Transaction();

    void deposit(double amount) override;
    void withdraw(double amount) override;
    void print_details() const override;
};
