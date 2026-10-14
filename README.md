# Connect Four AI using Minimax

Implementation of the classic **Connect Four** game in **C**, played on an 8×8 board in the terminal against an AI opponent based on the **Minimax algorithm**.

This project was developed as part of the **Advanced Programming** course during my Bachelor's Degree in Mathematics. The objective was to implement an adversarial search algorithm capable of making intelligent decisions in a deterministic two-player game.

---

## Overview

The game allows a human player to compete against an AI that evaluates future game states using the **Minimax algorithm**.

Since exploring the complete game tree is computationally infeasible, the AI relies on a custom heuristic evaluation function to estimate the quality of non-terminal positions.

Before starting the game, the player can choose:

- Who makes the first move
- AI search depth (2, 4 or 6 plies)

---

## Features

- Interactive terminal-based Connect Four
- Human vs AI gameplay
- Minimax search algorithm
- Configurable search depth
- Custom heuristic evaluation function
- Modular implementation in C

---

## Example

The board is drawn in the terminal with box-drawing characters. This is the position after three moves each, with the human player as `X` and the AI as `O`:

```
Jugador 1: Elige una columna entre 1 y 8: 5

La IA tira en la columna 4

╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗
║     ║     ║     ║     ║     ║     ║     ║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║     ║     ║     ║     ║     ║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║     ║     ║     ║     ║     ║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║     ║     ║     ║     ║     ║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║     ║     ║     ║     ║     ║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║     ║  O  ║     ║     ║     ║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║     ║  O  ║  X  ║     ║     ║     ║
╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣
║     ║     ║  X  ║  X  ║  O  ║     ║     ║     ║
╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝
    1     2     3     4     5     6     7     8
```

The game's prompts are in Spanish.

---

## Build and Run

The code uses `conio.h` and code page 437 box-drawing characters, so it is meant to be compiled and run on **Windows**, for example with MinGW-w64 (`gcc`):

```bash
gcc *.c -o connect4
connect4.exe
```

The program then asks who moves first (1 = you, 2 = AI) and the search depth (2, 4 or 6). Each turn, type the number of the column where you want to drop your piece.

---

## Heuristic Evaluation

Since exploring the complete game tree is computationally infeasible, the AI evaluates non-terminal positions using a custom heuristic function.

The evaluation scans the entire board considering:

- Horizontal connections
- Vertical connections
- Both diagonal directions

For each possible sequence, the heuristic evaluates patterns of length **2**, **3**, and **4**, assigning progressively larger weights:

| Pattern | Weight |
|---------|-------:|
| Two connected pieces | 1 |
| Three connected pieces | 10 |
| Four connected pieces | 100 |

The final score reflects both offensive opportunities and defensive plays, rewarding favourable board positions while penalising dangerous situations created by the opponent.

A small random value is added to break ties between otherwise equivalent positions, making the AI's decisions less deterministic.

---

## Project Structure

```
.
├── main.c
├── Minimax.c
├── Minimax.h
├── connect4.c
├── connect4.h
└── README.md
```

---

## Author

Álvaro Martorell Ortuño

B.Sc. in Mathematics  
Universitat Autònoma de Barcelona
