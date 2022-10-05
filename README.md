# puzzle_solver
---
🧩🧩🧩🧩🧩

---
## This project programmatically solves the puzzles of different sizes

Search algorithm finds a valid sequence of moves in order to reach the
final state, a.k.a the "snail solution", which depends on the size of the puzzle.

🐌 
![Image snail_position](https://github.com/bchelste/puzzle_solver/blob/main/additional/snail_position.png)

---
- 🔹 A* search algorithm is used
- 🔹 Various puzzle sizes
- 🔹 The cost associated with each transition is always 1
- 🔹 It is possible to choose one heuristic from:
    - manhattan
    - euclidian
    - hamming
- 🔹 If puzzle is unsolvable, program detects this and exit

---

- make
- ./n-puzzle args
    - -n size (3, 4, 5, ...)
    - -h heuristic (manhtn, euclid, hamm)
    - -s search (greedy, uniform (for uniform-cost search)
 - also you can put file with puzzle from generator (make gen3s - for solvable, make gen3u - for unsolvable)

---
"open" set is emplemented with std::priority_queue
"closed" set is emplemented with std::unordered_set
