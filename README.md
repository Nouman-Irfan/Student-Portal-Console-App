# Student-Portal-Console-App
A console-based Student Portal System in C++ that supports registration, login, result calculation, and record management using file handling. It demonstrates core programming concepts including file I/O, control structures, and a menu-driven interface for efficient data processing.
# 🎓 Student Portal System (C++)

A professionally designed **console-based Student Portal System** developed in **C++**, built to simulate a real-world academic environment. This project allows students to register, log in securely, calculate their academic results, and manage records using file handling for persistent data storage.

---

## 📥 GitHub Repository

Clone the project to your local machine:

```bash
git clone https://github.com/Nouman-Irfan/Student-Portal-Console-App.git
```

## ✨ Key Features

🔐 **Authentication System**  
- Student registration with unique ID  
- Secure login using ID & password  
- Credential verification through file matching  

📊 **Result Management**  
- Calculate percentage based on 5 subjects  
- Prevent duplicate result entries  
- Store results permanently in files  

📄 **Data Retrieval**  
- View individual student result after login  
- Print formatted result card  
- Display all results (filtered by odd serial numbers)  

💾 **Persistent Storage**  
- Data stored using text files  
- Maintains records even after program closes  

---

## 🧠 Core Concepts Used

- 📁 File Handling (`ifstream`, `ofstream`)  
- 🔁 Loops & Conditional Logic  
- 🔤 Arrays & C-Strings  
- 🧩 Menu-Driven Programming  
- 🔍 String Comparison & Data Matching  
- 💡 Basic Data Management System Design  

---

## 📂 Project Structure & Required Files

⚠️ **Important:** The following files must be placed in the **same directory as `main.cpp`** for the program to function properly.

- `reg.txt` → Stores registered Student IDs  
- `pswd.txt` → Stores corresponding passwords  
- `result.txt` → Stores calculated student results  

📌 These files act as a simple database for the system.

---

## ⚙️ Prerequisites

Before running the project, ensure you have:

- ✅ A C++ Compiler (GCC, MinGW, or Visual Studio)  
- ✅ Basic understanding of C++  
- ✅ All required `.txt` files present in the project directory  

---

## ▶️ How to Run

1. Open the project in any C++ IDE (VS Code, Dev C++, Visual Studio, etc.)  
2. Place all required `.txt` files in the same folder as `main.cpp`  
3. Compile the program  
4. Run the executable  
5. Use the interactive menu to navigate features  

---

## ⚠️ Disclaimer

This project is developed strictly for **educational purposes**.  
Passwords are stored in **plain text**, making it unsuitable for production-level security systems.

---

## 🚀 Future Improvements

- 🔒 Implement password encryption (hashing)  
- 🧵 Replace C-style arrays with `string`  
- 🗃️ Use a structured database instead of text files  
- 🖥️ Develop a GUI version (Qt / C++ GUI frameworks)  
- 🔁 Refactor code using functions and modular design  

---

## 👨‍💻 Developed By

**MUHAMMAD NOUMAN **
**(BSCS STUDENT)**

