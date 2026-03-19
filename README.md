#  LinkedListInfinityEngine_CPP

![Language](https://img.shields.io/badge/language-C%2B%2B-blue?style=flat-square&logo=c%2B%2B) ![License](https://img.shields.io/badge/license-MIT-green?style=flat-square) ![Stars](https://img.shields.io/github/stars/GeekyChirag-030/LinkedListInfinityEngine_CPP?style=flat-square) ![Forks](https://img.shields.io/github/forks/GeekyChirag-030/LinkedListInfinityEngine_CPP?style=flat-square)

![Topic](https://img.shields.io/badge/topic-Data%20Structures-orange?style=flat-square) ![Topic](https://img.shields.io/badge/topic-Linked%20List-orange?style=flat-square) ![Topic](https://img.shields.io/badge/topic-OOP-orange?style=flat-square) ![Topic](https://img.shields.io/badge/topic-CLI-orange?style=flat-square) ![Topic](https://img.shields.io/badge/topic-DSA-orange?style=flat-square) ![Topic](https://img.shields.io/badge/topic-Algorithms-orange?style=flat-square)

A fully-featured, menu-driven, CLI-based, object-oriented Linked List Engine built in C++.  
This is not just another linked list program — this is a **structure-level simulation framework** that lets you interactively build, manage, manipulate, and visualize how linked lists work under the hood with memory-safe pointer manipulation and operator overloading.

---

## Overview

This engine was engineered and structured to provide a **clear understanding of how Linked Lists behave** from insertion to deletion, with intuitive, keyboard-based controls, all running in the **command-line interface (CLI)** — efficient, powerful, and distraction-free.

>  Tailored for **DSA learners**, **competitive programmers**, ** Problem Solvers ** and those who want to **master pointers , DSA Linked List and OOP structure**.

---

## 📌 Project Summary

`LinkedListInfinityEngine_CPP` is a **Linked List toolkit simulator** built completely manually using pure `Node*` pointer logic.

Not just a DSA-project — it’s a **command-line engine** where users can take full control of:
- creation,
- deletion,
- insertion,
- reverse,
- search,
- and validation of linked list nodes.

Easy-to-understand printed interface + clean OOP-based structure makes it perfect for:
-  Learning  
-  Problem Solving  
-  Academic Demonstration  
-  Terminal Tooling  

---

##  Features & Functionalities

| Category            | Description |
|---------------------|-------------|
| Create List         | Create new linked list with user-defined size and data |
| Insert Node         | At head, tail, or any custom index |
| Delete Node         | From head, tail, or any index |
| Operator Overload   | `+`, `++`, `-`, `--`, `>>`, `<<` |
| Reverse Print       | Print the list in reverse using recursion |
| InPlace Reverse     | InPlace Reversing of the Linked List |
| Search Node         | Find a node by data and return its 1-based index |
| Size Tracking       | Auto-tracks list size with every insert/delete |
| Head & Tail Access  | Print head and tail data directly |
| Clear List          | Completely deletes list and frees memory |
| Rules Interface     | Prints full rules and command menu anytime |
| Menu Driven System  | Interactive CLI experience with command prompts |

---

##  Technologies Used

- **Language**: C++
- **Paradigm**: Object-Oriented Programming (OOP)
- **Data Structure**: Singly Linked List
- **Environment**: Console / Terminal / CMD / PowerShell
- **Memory Management**: Manual (via `new` and `delete`)
- **Build Type**: CLI Executable or Source-based

---

##  Operator Overloading Reference

| Operator | Use Case |
|----------|----------|
| `>>`     | Input: Create linked list from scratch |
| `<<`     | Output: Print linked list from head to null |
| `+`      | Add node at a user-specified index |
| `-`      | Delete node from a specified index |
| `++`     | Append node to tail |
| `--`     | Delete node from tail |

---

##  Preview: Menu UI

```txt
__________________________________________________________________________________

                            Linked List Implementation

__________________________________________________________________________________


 *-*-*-*-*-*-*-*-*-*-*-*- Operations Menu *-*-*-*-*-*-*-*-*-*-*-*-

 [1]  Creation of Linked List From Scratch
 [2]  Adding Node in the Beginning of Linked List
 [3]  Adding Node by Default at the End (Tail)
 [4]  Adding Node at Any Valid Index
 [5]  Delete Node from the Beginning (Head)
 [6]  Delete Last Node (Tail) - Default
 [7]  Delete Node From Any Index
 [8]  Print Linked List
 [9]  Get Size of Linked List
 [h]  Show Data at Head
 [t]  Show Data at Tail
 [r]  Print Reverse (Recursive)
 [R]  inPlace Reversal of the Linked List 
 [s]  Search Node by Data
 [#]  Clear Entire Linked List
 [?]  Show Rules and Operator Usage
 [!]  Exit

Please Enter Your Input From Menu Each Time (To Stop Press !) =>

--------------------------------------------------------------------------


🎮 Commands — Terminal Controls

>>     Create List
<<     Display List
+      Add Node at Custom Index
-      Delete Node from Custom Index
++     Add Node at the End (Tail)
--     Delete Last Node (Tail)
addBegin()   Add at start
remBegin()   Remove from start
prHead()     Data at Head
prTail()     Data at Tail
printRevLList()  Recursive Reverse Print
reverseLList() inPlace reversal of the Linked List 
searchNodeLList(value)  Find node by data
getSize()     Total Nodes
#       Clear Entire List
?       Show All Rules and Output Info
!       Exit Program```

```

## Object-Oriented Design
Concept	Applied
-  Encapsulation	✅ All data members are private
-  Public API Access	✅ Interactions happen only through public member methods
-  Operator Overloading	✅ +, -, ++, --, <<, >> for intuitive usage
-  Class - solLList	✅ Manages full linked list lifecycle: creation to flushing
-  Recursion	✅ Used in reverse printing logic

---

## Internal Architecture

| Component       | Description |
|-----------------|-------------|
| `headNode`      | Points to first node |
| `tailNode`      | Points to last node |
| `linkedList`    | Main list pointer, used for traversals |
| `nNodesSize`    | Auto-updated list size |
| `Node struct`   | Contains `int Data` and `Node* next` |
| `class solLList`| Fully encapsulates all list logic |

---

## Object-Oriented Blueprint

This project obeys OOP principles strictly:

- **Encapsulation** ✅  
- **Data Hiding** ✅ (`private` members only accessible via public helpers)  
- **Operator Overloading** ✅ (C++ power in action)  
- **Modular Design** ✅ (core logic separated cleanly)  


---

## Sample Outputs
```txt
Enter the Size of Linked List: 3
Input Node 1: 10
Input Node 2: 20
Input Node 3: 30

Linked List:
10 --> 20 --> 30 --> NULL

Adding Node at Index 2:
Updated List:
10 --> NEW --> 20 --> 30 --> NULL

Deleting Node at Index 3:
Updated List:
10 --> NEW --> 30 --> NULL

Recursive Reverse:
NULL <-- 30 <-- NEW <-- 10
```


---

## 📝 License

This project is licensed under the **MIT License**.  
See `LICENSE.txt` for full usage permissions.

---

## Author

**Problem Solver**  
> _"Built not just to run… but to **learn, simulate and master.**"_  

---

## 📦 Setup Wizard 

- A fully prepared `.exe` and Setup Wizard available under `Setup LList`
- Launches the CLI app with full menu system.
- Clean install/uninstall supported.

## Edge Cases 
---

| ✅ Edge Case | Handled? |
|-------------|----------|
| Insertion at invalid index | ✅ |
| Deletion from invalid index | ✅ |
| Operations on empty list | ✅ |
| Deleting last remaining node | ✅ |
| Adding to empty list | ✅ |
| List size = 0 update | ✅ |

---
## ❤️ Contributions
💬 Open to ideas and improvements
- You’re free to fork and extend!
---
###  Star this Repo
Show your support by:
- Starring the repository ⭐
- Sharing it to inspire other devs 
- Forking and evolving it 
---
 Let the Linked List Engine Run...
**Thank you for visiting LinkedListInfinityEngine_CPP**

##### Built by  A Problem Solver.
##### Designed for Structured Thinking.
##### Lives Forever in Memory and Logic.


![G__LinkedListInfinityEnginev1 0 1_useLList exe2026-03-1916-08-061-ezgif com-optimize](https://github.com/user-attachments/assets/b238ac5f-f8a0-45c2-9a3b-2a25cadc4542)
