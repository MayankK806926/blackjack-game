# 🃖 Blackjack Simulator

A lightweight, terminal-based Blackjack (21) game implemented in C++ that follows standard casino rules with simplified gameplay mechanics.

## 📖 Table of Contents
- [Features](#-features)
- [How to Play](#-how-to-play)
- [Installation](#-installation)
- [Game Rules](#-game-rules)
- [Project Structure](#-project-structure)
- [Future Improvements](#-future-improvements)

## ✨ Features
- **Multiplayer support**: Play with any number of players against the dealer
- **Auto-dealer**: Dealer follows standard casino rules (hits on ≤16)
- **Card value system**: 
  - Number cards = face value
  - Face cards (J,Q,K) = 10
  - Ace = 1 (simplified)
- **Instant results**: Automatic bust detection and winner determination

## 🎮 How to Play
1. Enter total number of players (including dealer)
2. Input card values when prompted:
   - A, 2-10, J, Q, or K
3. For each turn:
   - Type `Hit` to draw another card
   - Type `Stand` to keep your hand
4. View final results (Winner/Busted/Loser)

**Example Gameplay:**
```plaintext
Enter number of players (including dealer): 2

Initial Deal:
Player 1 cards: A 5
Dealer cards: J ?

Player 1's turn:
Hit or Stand? Hit
New card: 8
Hit or Stand? Stand

Dealer reveals: J 2
Dealer hits: 6

Results:
Player 1: winner (14 vs 18)
