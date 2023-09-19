# C++ Hash Table Application

This is a C++ console-based application for a hash table that allows users to insert, search, and delete elements. The application uses a hash function to manage a list of strings in different buckets based on their hash values.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [License](#license)

## Introduction

This C++ application consists of the following components:

- `hashFunc`: A hash function that calculates the hash value for a given string.

- `hashTable`: An array of vectors that represents the hash table data structure. Each vector stores strings with the same hash value.

- `search`: A function to search for a specific string in the hash table.

- `insert`: A function to insert a string into the hash table.

- `delet`: A function to delete a specific string from the hash table.

The main function (`main.cpp`) is responsible for handling user interactions with the hash table application, including inserting, searching, and deleting strings.

## Features

- Insert strings into the hash table.
- Search for a specific string in the hash table.
- Delete a specific string from the hash table.
- Display the lengthiest string and its index.
- Display the last inserted string and its index.
- Navigate through a menu to perform operations.

## Installation

To run this application, you need a C++ compiler installed on your system.

1. Clone or download the repository to your local machine.

2. Open a terminal or command prompt and navigate to the project directory.

For Linux/macOS:
```bash
g++ main.cpp -o hash_table_app
./hash_table_app
```

For Windows (using MinGW):
```bash
g++ main.cpp -o hash_table_app
hash_table_app.exe
```

## Usage

1. Launch the application by running the compiled executable.

2. Use the menu to perform the following operations:
   - Option 1: Insert a string into the hash table.
   - Option 2: Search for a string in the hash table.
   - Option 3: Delete a string from the hash table.
   - Option 4: Exit the application.

3. When inserting a string, enter the string without spaces.

4. The application will display information about the lengthiest and last inserted strings.

5. Perform operations as needed and exit the application when done.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
