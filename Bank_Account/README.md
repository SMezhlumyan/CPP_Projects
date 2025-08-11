# BankAccount Project — Overview

This C++ project implements a simple banking system demonstrating core object-oriented concepts such as inheritance, polymorphism, and resource management. It provides multiple bank account types with specialized behaviors and supports transaction logging.

Key features:

- **Account hierarchy:** Base class `BankAccount` with derived classes `SavingsAccount` (interest support), `CheckingAccount` (overdraft protection), and `Account_Transaction` (transaction logging).
- **Transaction logging:** `Transaction` class records deposits and withdrawals as textual logs.
- **Polymorphism:** Virtual methods allow customized behavior for deposits, withdrawals, and printing.
- **Resource management:** Uses `std::unique_ptr` for safe, automatic memory handling of transactions.
- **Example usage:** Demo code in `main.cpp` exercises all account types.
- **Build system:** CMake configuration for building with C++17 standard.

---

Project Hierarchy:  
BankAccountProject/  
├── include/  
│   └── BankAccount.hpp         # Class declarations for accounts and transactions  
├── src/  
│   ├── BankAccount.cpp         # Class method implementations  
│   └── main.cpp                # Example program demonstrating features  
├── build/                      # Build output directory (gitignored)  
├── CMakeLists.txt              # CMake build configuration  
└── README.md                   # This project overview and instructions  

---

### Build & Run Instructions

To build and run the project:

```bash
make
./bank_app
