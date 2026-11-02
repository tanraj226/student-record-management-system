# student-record-management-system

A simple and efficient Student Record Management System developed using the C programming language. This project helps manage student information, including personal details, academic marks, percentage, and grades.

The system uses file handling to store student records permanently, allowing users to access the data even after the program is closed.

## 📌 Project Overview

The Student Record Management System is a console-based application designed to simplify the management of student records.

It provides basic operations such as adding, displaying, searching, updating, and deleting student information.

This project demonstrates the practical implementation of fundamental C programming concepts.

## 🎯 Objectives

- To maintain student records efficiently.
- To reduce manual record-keeping.
- To provide easy access to student information.
- To calculate student percentages and grades.
- To understand structures and file handling in C.

## ✨ Features

- Add new student records.
- Display all student records.
- Search students using roll number.
- Update existing student details.
- Delete student records.
- Store marks of five subjects.
- Calculate total marks and percentage.
- Automatically assign grades.
- Prevent duplicate roll numbers.
- Store data permanently using file handling.

## 🛠️ Technologies Used

- Programming Language: C
- Compiler: GCC
- Concepts Used:
  - Structures
  - Functions
  - Conditional Statements
  - Loops
  - File Handling
  - Binary Files
  - Arrays

## 📋 System Requirements

### Hardware Requirements
- Computer or Laptop
- Minimum 2 GB RAM

### Software Requirements
- Windows, Linux, or macOS
- GCC Compiler
- VS Code, Code::Blocks, or any C editor

## 🚀 Installation and Execution

### Step 1: Clone the Repository

```bash
git clone https://github.com/tanraj226/student-record-management-system.git
```

### Step 2: Open the Project Folder

```bash
cd student-record-management-system
```

### Step 3: Compile the Program

```bash
gcc student_management.c -o student_management
```

### Step 4: Run the Program

For Windows:

```bash
student_management.exe
```

For Linux or macOS:

```bash
./student_management
```

## 📖 Menu Options

The application provides the following menu:

1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit

## 📊 Grading System

| Percentage | Grade |
|------------|-------|
| 90% and above | A |
| 75% – 89.99% | B |
| 60% – 74.99% | C |
| 40% – 59.99% | D |
| Below 40% | F |

## 💾 Data Storage

Student records are stored in a binary file named `students.dat`.

The file is automatically created when a new student record is added.

The program uses file handling functions such as:

- `fopen()`
- `fread()`
- `fwrite()`
- `fclose()`
- `remove()`
- `rename()`

## 🎓 Learning Outcomes

Through this project, we learn:

- How to use structures in C.
- How to implement file handling.
- How to perform CRUD operations.
- How to manage student information.
- How to develop a menu-driven application.

## 🔮 Future Improvements

- Add a graphical user interface.
- Implement password-based authentication.
- Add database connectivity.
- Generate student report cards.
- Export records to CSV or PDF.

## 📝 Conclusion

The Student Record Management System is a useful educational project that demonstrates the application of C programming concepts in a real-world scenario.

It provides a simple and effective way to manage student information and academic records using file handling.

This project improves programming skills and provides practical knowledge of data management.

## 👨‍💻 Author

**Student Record Management System**

Developed as a C Programming Project.
