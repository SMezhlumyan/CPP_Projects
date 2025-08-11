#include "BankAccount.hpp"

int main() {
    std::cout << "=== BankAccount Example ===" << std::endl;
    BankAccount ba(1000);
    ba.deposit(500);
    ba.withdraw(200);
    ba.print_details();

    std::cout << "\n=== SavingsAccount Example ===" << std::endl;
    SavingsAccount sa(2000, 0.05);
    sa.apply_interest();
    sa.print_details();

    std::cout << "\n=== CheckingAccount Example ===" << std::endl;
    CheckingAccount ca(500, 300);
    ca.withdraw(700);
    ca.print_details();

    std::cout << "\n=== Account_Transaction Example ===" << std::endl;
    Account_Transaction at(1500);
    at.deposit(400);
    at.withdraw(1000);
    at.print_details();

    return 0;
}
