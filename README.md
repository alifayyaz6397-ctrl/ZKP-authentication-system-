
# Galaxy Cinema Hall Management System 🎬

A comprehensive **C++ command-line application** that simulates the core operations of a cinema hall.  
This project is designed for academic purposes and demonstrates concepts such as **file handling, functions, structures, arrays, and role-based access control**.

---

## 📌 Features

### 🔐 Authentication System
- Separate **Admin** and **User** roles
- Secure login using stored credentials

### 🎥 Movie Management (Admin)
- Add new movies
- View ongoing movies
- Delete movies
- Save and load movie data from files

### 🎟️ Booking System (User)
- View available movies
- Book tickets
- Seat allocation
- View booking details

### 💰 Revenue & Records
- Persistent storage using files
- Load/save users, movies, and bookings
- View booking history

### 🖥️ User-Friendly Console UI
- Menu-driven interface
- Console colors and headers (Windows-based)

---

## 🧑‍💼 Roles & Permissions

### Admin
- Manage movies
- View all bookings
- Control cinema operations

### User
- Browse movies
- Book tickets
- View personal bookings

---

## 🛠️ Technologies Used

- **Language:** C++  
- **IDE:** Dev-C++ / Visual Studio / Code::Blocks  
- **Platform:** Windows  
- **Libraries:**  
  - `<iostream>`  
  - `<fstream>`  
  - `<iomanip>`  
  - `<string>`  
  - `<conio.h>`  
  - `<windows.h>`  

---

## ▶️ How to Run

1. Clone or download the project
2. Open the `.cpp` file in a C++ compiler (Windows recommended)
3. Compile and run the program
4. Follow on-screen menu instructions

```bash
g++ CS-2025-76ZKP.cpp -o cinema
cinema
```

---

## 📂 File Structure

```
├── CS-2025-76ZKP.cpp
├── users.txt
├── movies.txt
├── bookings.txt
└── README.md
```

---

## 📖 Learning Outcomes

- File handling in C++
- Menu-driven program design
- Role-based system implementation
- Real-world system simulation

---

## 👨‍🎓 Author

**Ali Fayyaz**  
Computer Science Student  
Academic Project – 2025

---

## 📜 License

This project is for **educational use only**.
