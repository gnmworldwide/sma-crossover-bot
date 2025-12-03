# SMA Crossover Bot (C++)

This project simulates a simple trading strategy using two moving averages. It buys when the short-term SMA crosses above the long-term SMA, and sells when it crosses below.

---

## What It Does

- Uses simulated price data (vector of doubles)
- Computes:
  - Short-term SMA (e.g., 3-period)
  - Long-term SMA (e.g., 5-period)
- Buys when short SMA > long SMA
- Sells when short SMA < long SMA
- Tracks total profit or loss (PnL)

---

## Quant Concepts Demonstrated

- Simple Moving Averages (SMA)
- Crossover-based entry/exit signals
- Trade simulation and strategy evaluation
- Profit and loss calculation

---

## How to Run

Make sure you have a C++ compiler installed (like `g++`), then run:

```bash
g++ main.cpp -o sma_bot
./sma_bot
```

---

## Sample Output

```
Day 5: Price = 99.50 | SMA(3) = 100.80, SMA(5) = 100.80 → BUY @ 99.50
Day 8: Price = 98.20 | SMA(3) = 98.00, SMA(5) = 99.00 → SELL @ 98.20 | PnL: -1.30

Total Strategy PnL: 2.50
```

---

## Possible Extensions

- Load real price data from CSV
- Use exponential moving averages (EMA)
- Add stop-loss and take-profit rules
- Plot signals on a graph with timestamps

---

## Built With

- C++
- STL: `vector`, `iostream`, `iomanip`

---

## Project Type

- Quant Micro-Project #4
- Strategy Simulation Prototype
