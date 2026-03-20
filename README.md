# 🏦 Bank Management System (C++ Console Application - OOP)

A comprehensive, object-oriented console-based Bank Management System built with C++. It provides a complete suite of tools for managing clients, users, transactions, and currency exchange, simulating a real-world banking back-office and teller system.

This project is a practical demonstration of advanced C++ concepts, including inheritance, polymorphism, file handling, data encryption, and complex menu-driven user interfaces.

---

## 📌 Project Idea

The goal of this project is to create a secure and feature-rich banking management system. It allows administrators and users with specific permissions to manage client accounts, perform financial transactions, track user activity, and even handle currency exchange. All data is persistently stored in text files, ensuring data integrity across sessions.

---

## 👤 What Can Users Do?

The system's functionality is divided into several menus, accessible based on user permissions:

🏠 Main Menu
- **Show Clients List:** View a list of all registered clients.
- **Add New Client:** Register a new client with a unique account number.
- **Delete Client:** Remove an existing client from the system.
- **Update Client:** Modify a client's personal information.
- **Find Client:** Search for a client by their account number.

💰 Transactions Menu
- **Deposit:** Add funds to a client's account.
- **Withdraw:** Withdraw funds from a client's account (with balance check).
- **Total Balances:** View a list of all client balances and the total sum.
- **Transfer:** Transfer funds between two client accounts.
- **Transfers Log:** View a detailed history of all transfers, including date, source, destination, amount, and the user who performed it.

👥 Manage Users Menu
- **Show Users List:** View a list of all system users.
- **Add New User:** Create a new system user with a unique username and password.
- **Delete User:** Remove an existing user.
- **Update User:** Modify a user's information or permissions.
- **Find User:** Search for a user by their username.

💱 Currency Exchange Menu
- **Show Currencies List:** View a list of all available currencies with their exchange rates.
- **Find Currency:** Search for a currency by its code or country name.
- **Update Currency Rate:** Update the exchange rate for a specific currency.
- **Currency Calculator:** Calculate the converted value between two currencies.

📜 Other Features
- **Login Registers:** A log of all successful user logins, showing the username, date, and time.
- **Secure Logout:** End the current user session.

---

## ⚙️ Features
- **Object-Oriented Design:** Built using core OOP principles like classes, inheritance (`clsPerson` -> `clsClient`, `clsUser`), and encapsulation.
- **User Permissions:** Granular access control with bitwise permissions. Users can be given full access or specific permissions for each major function.
- **File-Based Data Persistence:** Data for clients, users, currencies, login registers, and transfer logs are stored in separate, human-readable text files.
- **Data Encryption:** User passwords are encrypted when stored in the `Users.txt` file for basic security.
- **Colorful Console UI:** Uses ANSI escape codes to provide a visually appealing and user-friendly interface.
- **Robust Input Validation:** Prevents invalid inputs and ensures data integrity.
- **Transaction Logging:** Every financial transfer is recorded with full details, including the user who performed it.
- **Currency Exchange Engine:** Supports dynamic currency conversion based on configurable exchange rates.
- **Date & Time Handling:** Automatically timestamps all login and transaction logs.

---

## 🧠 How the System Works
1.  **Login:** The system starts with a login screen. Users are validated against the `Users.txt` file.
2.  **Permissions:** Upon login, the user's permissions are loaded. Menus and options will be hidden or inaccessible based on these permissions.
3.  **Main Menu:** The user is presented with the main menu, which acts as a hub for all other modules.
4.  **Data Operations:** All operations (Add, Update, Delete, etc.) interact with the corresponding `.txt` files to read, modify, or save data.
5.  **Transaction Handling:** When a transfer occurs, the system ensures atomicity by attempting to withdraw from one account and deposit into the other. If any step fails, the operation is rolled back. The transaction is then logged in `TransfersLog.txt`.
6.  **Logout:** Logging out clears the current user session and returns to the login screen.

---

## 📁 Files Used in the Project
- **`Clients.txt`**: Stores all client data (FirstName, LastName, Email, Phone, AccountNumber, PinCode, Balance).
- **`Users.txt`**: Stores all system user data (FirstName, LastName, Email, Phone, UserName, EncryptedPassword, Permissions).
- **`Currencies.txt`**: Stores all currency data (Country, CurrencyCode, CurrencyName, Rate).
- **`LoginRegister.txt`**: Stores the login history for all users (DateTime, UserName, EncryptedPassword, Permissions).
- **`TransfersLog.txt`**: Stores a log of all financial transfers (DateTime, SourceAccount, DestinationAccount, Amount, SourceBalanceAfter, DestinationBalanceAfter, UserName).

---

## ▶️ How to Run the Project (Visual Studio)
1.  Open Visual Studio.
2.  Click **Create a new project**.
3.  Choose **Console App**.
4.  Select **C++**.
5.  Click **Next**.
6.  Name the project (e.g., `BankManagementSystem`).
7.  Replace the auto-generated `.cpp` file with the project's `main.cpp` file.
8.  Add all other `.h` files to the project (you can do this by dragging them into the Solution Explorer).
9.  Ensure the following text files exist in the same directory as the executable (the `x64/Debug` or `x64/Release` folder after building):
    - `Clients.txt`
    - `Users.txt`
    - `Currencies.txt`
    - *(The `LoginRegister.txt` and `TransfersLog.txt` will be created automatically by the program.)*
10. Click **Run ▶️** or press **Ctrl + F5**.

**Default Admin Login:**
- UserName: `admin`
- Password: `admin123`
*(You can change this in the `Users.txt` file after the first run, or you can create a new admin user.)*

---

## 🛠 Requirements
- **Operating System:** Windows 10 or later.
- **IDE:** Visual Studio 2019/2022 (or any C++17-compatible IDE).
- **Compiler:** MSVC (Visual Studio C++ Compiler).

---

## ⚠️ Notes & Warnings
- **Text Files Must Exist:** The three main data files (`Clients.txt`, `Users.txt`, `Currencies.txt`) must exist and be properly formatted before the program runs for the first time.
- **Data Format:** Do not change the internal structure or separator (`//`) in the data files, as this will break the program's ability to read them.
- **Permissions:** The default admin has full permissions. Other users' permissions are controlled by the `Permissions` field in `Users.txt`.
- **Console Colors:** The vibrant console colors rely on ANSI escape codes, which are supported in modern Windows Terminals. If the colors don't appear correctly, ensure you are using Windows Terminal or a compatible console.

---

## 🎓 Educational Value
This project is an excellent resource for learning and practicing:

- **Object-Oriented Programming:** Classes, inheritance, polymorphism, encapsulation.
- **Advanced File I/O:** Reading, writing, updating, and deleting records in text files.
- **Bitwise Operations:** Implementing user permissions.
- **Data Validation:** Creating robust input validation functions.
- **String Manipulation:** Parsing and formatting data for file storage.
- **Date & Time Handling:** Logging events with timestamps.
- **Algorithmic Logic:** Implementing a rollback mechanism for financial transfers.
- **Large-Scale Project Structure:** Managing a complex codebase with many interdependent classes and screens.
