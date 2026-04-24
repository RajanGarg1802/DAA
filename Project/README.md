# 🧭 Browser History Simulator (C++ Win32)

A simple desktop application that simulates browser navigation using **stack data structures**, built with **C++ and Win32 API**.

---

## 📌 Overview

This project demonstrates how real browsers handle navigation using:

* **Back stack**
* **Forward stack**

It provides a minimal GUI where users can:

* Enter a page name (URL)
* Navigate backward and forward through history

---

## 🧠 Data Structures Used

### 🔹 Stack (LIFO)

Two stacks are used:

* **Back Stack**

  * Stores previously visited pages
* **Forward Stack**

  * Stores pages when navigating back

---

## ⚙️ Features

* 🔗 Visit a new page
* ⬅️ Navigate back
* ➡️ Navigate forward
* 🔄 Forward history clears on new visit
* 🖥️ Simple Windows GUI
* 🎯 Buttons enable/disable based on state

---

## 🏗️ Working Logic

### Visit

* Push current page → back stack
* Clear forward stack
* Set new page as current

### Back

* Push current page → forward stack
* Pop from back stack → current

### Forward

* Push current page → back stack
* Pop from forward stack → current

---

## 🖼️ User Interface

The application includes:

* Input field for page name
* **Go** button to visit
* **Back** button
* **Forward** button
* Display showing current page

---

## 🛠️ Technologies

* **C++**
* **Win32 API**
* STL:

  * `stack`
  * `string`

---

## ▶️ How to Run

### Requirements

* Windows OS
* C++ compiler (MinGW or MSVC)

---

### Compile

#### Using MinGW:

```bash
g++ browserHistory.cpp -o browserHistory.exe -mwindows -lgdi32 -luser32
```

#### Using MSVC:

```bash
cl browserHistory.cpp user32.lib gdi32.lib
```

---

### Run

```bash
browserHistory.exe
```

---

## 📂 Project Structure

```
Browser-History-Simulator/
│── browserHistory.cpp
│── README.md
```

---

## 🚀 Possible Improvements

* Show full back and forward history visually
* Improve UI layout and styling
* Add keyboard shortcuts
* Add persistent history (file storage)

---

## 📚 Learning Outcomes

* Understanding **stack-based navigation**
* Applying DSA concepts to real-world problems
* Basics of **Win32 GUI programming**
* Event-driven programming in C++

---

## 📄 License

This project is intended for educational purposes.
