# Connect Four AI using Minimax

Implementation of the classic **Connect Four** game in **C**, featuring an AI opponent based on the **Minimax algorithm**.

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
├── minimax.c
├── minimax.h
├── connect4.c
├── connect4.h
└── README.md
```

---

## Author

Álvaro Martorell Ortuño

B.Sc. in Mathematics  
Universitat Autònoma de Barcelona
