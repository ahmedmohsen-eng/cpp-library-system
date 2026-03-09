# C++ Library Management System

![C++17](https://img.shields.io/badge/C++-17-00599C?style=flat&logo=c%2B%2B&logoColor=white)
![License: MIT](https://img.shields.io/badge/License-MIT-green?style=flat)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20Windows-lightgrey?style=flat)
![Status](https://img.shields.io/badge/Status-Active-brightgreen?style=flat)
![CS50x](https://img.shields.io/badge/CS50x-Final%20Project-red?style=flat)

A command-line library management system built in C++ — demonstrating object-oriented design,
a **hand-rolled hash map** (djb2 hashing + open addressing + tombstone deletion),
and persistent file I/O. Submitted as the final project for [CS50x Harvard](https://cs50.harvard.edu/x/).

---

## Features

- **Book management** — add, remove, search by ISBN / title keyword / author keyword
- **Member management** — register members, enforce a 5-book borrow limit per member
- **Transactions** — borrow and return books with full validation at every step
- **Custom HashMap** — O(1) average lookup built from scratch using djb2 + linear probing
- **Persistence** — all data saved to plain-text files on every write, auto-loaded on startup
- **Interactive CLI** — nested menus, clean input handling, no external libraries required

---

## Project Structure

```
cpp-library-system/
├── main.cpp              # CLI entry point and menus
├── include/
│   ├── Book.h            # Book class interface
│   ├── Member.h          # Member class interface
│   ├── Librarian.h       # Orchestrator interface
│   └── HashMap.h         # Custom hash map interface
├── src/
│   ├── Book.cpp          # Book implementation + serialization
│   ├── Member.cpp        # Member implementation + borrow/return logic
│   ├── Librarian.cpp     # All operations + file I/O
│   └── HashMap.cpp       # djb2 hash + open addressing + tombstone deletion
├── data/                 # Auto-created at first run (git-ignored)
│   ├── books.txt         # Pipe-delimited book records
│   └── members.txt       # Pipe-delimited member records
└── Makefile
```

---

## Build & Run

**Requirements:** g++ with C++17 support (GCC 7+ or Clang 5+)

```bash
# Clone the repository
git clone https://github.com/ahmedmohsen-eng/cpp-library-system.git
cd cpp-library-system

# Build
make

# Run
./library

# Build and run in one step
make run

# Clean compiled files
make clean
```

---

## HashMap Design

The core data structure is a custom `HashMap` mapping string keys to integer indices.
Both ISBN→book and memberID→member lookups use this structure.

| Property | Detail |
|---|---|
| Hash function | djb2 (`h = h * 33 ^ c`, seed 5381) |
| Collision resolution | Linear probing: `(h + i) % capacity` |
| Deletion | Tombstone marking — avoids breaking probe chains |
| Load factor threshold | 0.7 — triggers rehash into larger prime capacity |
| Default capacity | 101 (prime reduces clustering) |
| Average complexity | O(1) insert, search, delete |

This avoids `std::unordered_map` and was built from scratch to demonstrate understanding
of hash table internals — including why naive deletion breaks search and how tombstones fix it.

---

## OOP Design

| Class | Responsibility |
|---|---|
| `Book` | Data fields + availability state + serialize/deserialize |
| `Member` | Data fields + borrowed ISBNs list + borrow/return validation |
| `Librarian` | Orchestrates all operations, owns two HashMaps and the data vectors |
| `HashMap` | Generic `string → int` index table, fully reusable |

---

## Data Format

Books and members are stored in pipe-delimited plain text, one record per line:

```
# data/books.txt
978-0-13-468599-1|The C++ Programming Language|Bjarne Stroustrup|2013|1
978-0-13-235088-4|The Pragmatic Programmer|David Thomas|2019|0

# data/members.txt
1|Ahmed Mohamed|ahmed@email.com|978-0-13-468599-1
2|Sara Ali|sara@email.com|
#3
```

The `#N` line at the end of members.txt stores the next available member ID across sessions.

---

## Example Session

```
╔══════════════════════════════════════╗
║      C++ Library Management System   ║
╚══════════════════════════════════════╝

═══ Main Menu ═════════════════════════
  1. Books
  2. Members
  3. Borrow / Return
  4. Stats
  0. Exit
Choice: 1

── Book Menu ──────────────────
  3. Search by ISBN
ISBN: 978-0-13-468599-1
  ISBN   : 978-0-13-468599-1
  Title  : The C++ Programming Language
  Author : Bjarne Stroustrup
  Year   : 2013
  Status : Available
```

---

## Author

**Ahmed Mohamed** — Competitive Programmer · ICPC Trainee · AI & Data Science Engineering @ UFE

[![GitHub](https://img.shields.io/badge/GitHub-ahmedmohsen--eng-181717?style=flat&logo=github)](https://github.com/ahmedmohsen-eng)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-ahmedmohsen--eng-0A66C2?style=flat&logo=linkedin)](https://linkedin.com/in/ahmedmohsen-eng)
[![Codeforces](https://img.shields.io/badge/Codeforces-hackgg106-1F8ACB?style=flat)](https://codeforces.com/profile/hackgg106)
