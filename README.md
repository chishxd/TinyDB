# TinyDB

**TinyDB** is a lightweight, file-based database management system written in C.  
It’s built for learning how database engines work under the hood — no SQL, no dependencies, just structs and binary files.

---

## ✨ Features

- 📦 Add, search, update, and delete records
- 💾 Stores data in a binary `.dat` file using C `structs`
- 📂 Simple CLI interface for interacting with the database
- 🔐 (Planned) Password-protected access and file encryption

---

## 📁 Project Structure

```

include/     → Header files (db.h, utils.h)
src/         → Source files (main.c, db.c, utils.c)
data/        → Stores `records.dat` (binary file of records)
CMakeLists.txt → Build instructions for CMake

````

---

## 🚀 Getting Started

### Prerequisites

- C compiler (like GCC or Clang)
- [CMake](https://cmake.org/download/) ≥ 3.10

### Build

```bash
mkdir build
cd build
cmake ..
cmake --build .
````

### Run

```bash
./tinydb
```

---

## 🧠 Learning Goals

* Practice with structs, file I/O, and modular C
* Understand how databases manage records without SQL
* Learn basics of system design, architecture, and CLI tools

---

## 🛠️ Tech

* Language: C (C99 or above)
* Build: CMake
* OS: Cross-platform (Linux preferred for dev)

---

## 🧱 Built by

* Chinmay - [GitHub](https://github.com/chishxd)
* Vedant - [GitHub](https://github.com/VedantParte23)

---

## 📌 License

MIT — feel free to fork, extend, or remix for learning.

---