<h1 align = "center">Logic Legends</h1>

<p align="center">
<img width="524" height="524" alt="Logo" src="https://github.com/user-attachments/assets/7b263cb7-0cfc-4c0f-a739-ada2a1027607" />
</p>

<h2 align="center">📑 Table of Contents</h2>

<p align="center">
  <a href="#about-the-game">
    <img src="https://img.shields.io/badge/About%20The%20Game-181818?style=for-the-badge&color=blue" />
  </a>
  <a href="#executing-program">
    <img src="https://img.shields.io/badge/Executing%20Program-181818?style=for-the-badge&color=green" />
  </a>
  <a href="#technologies">
    <img src="https://img.shields.io/badge/Technologies-181818?style=for-the-badge&color=orange" />
  </a>
  <a href="#our-team">
    <img src="https://img.shields.io/badge/Our%20Team-181818?style=for-the-badge&color=purple" />
  </a>
</p>

<hr>

<h2 align="center" id="about-the-game">🧠 About The Game</h2>

- You start at (0,0). The goal is the bottom-right cell.
- Pick a difficulty. Harder modes have bigger grids and trickier problems.
- When you try to move into a cell, you get a math question for that cell.
- Answer right: you move and earn points. Answer wrong: you stay and lose a life.
- Controls: `W` up, `A` left, `S` down, `D` right. Press `q` to quit a run.

### Difficulty Vibe
- **Easy (4x4)**: only + and -; 4 lives; 5–10 points.
- **Normal (5x5)**: + - × ÷; 3 lives; 8–15 points; some bonus cells and extra-life cells.
- **Hard (7x7)**: all normal stuff plus mixed expressions, squares, modulo; 2 lives; 10–25 points; traps ask an extra question and can cost 2 lives.

<hr>

## How to Build and Play
From the project folder:
```bash
# Linux/macOS
g++ -std=c++17 main.cpp Game.cpp Problems.cpp -o main
./main

# Windows (MinGW)
g++ -std=c++17 main.cpp Game.cpp Problems.cpp -o main.exe
main.exe
```
If `g++` is missing, install a C++ compiler (Ubuntu/Debian: `sudo apt install build-essential`; Windows: install MinGW-w64 and use its `g++`).

<hr>

<h2 align="center" id="technologies">🛠️ Technologies</h2>
<h3 align="center">These are the tools we used:</h3>

<p align="center">
    <a href="https://git-scm.com/"><img src="https://git-scm.com/images/logos/downloads/Git-Icon-Black.png" alt="Git logo" width="70"/></a>
    <a href="https://github.com/"><img src="https://cdn-icons-png.flaticon.com/512/2111/2111612.png" alt="GitHub logo" width="70"/></a>
    <a href="https://www.cplusplus.com/"><img src="https://brandslogos.com/wp-content/uploads/thumbs/c-logo-vector.svg" alt="C++ logo" width="70"/></a>
    <a href="https://visualstudio.microsoft.com/vs/"><img src="https://visualstudio.microsoft.com/wp-content/uploads/2021/10/Product-Icon.svg" alt="Visual Studio logo" width="70"/></a>
    <a href="https://www.microsoft.com/en/microsoft-teams/group-chat-software"><img src="https://img.icons8.com/color/344/microsoft-teams.png" alt="MS Teams logo" width="70" /></a>
    <a href="https://www.microsoft.com/en-ww/microsoft-365/word"><img src="https://img.icons8.com/color/344/ms-word.png" alt="MS Word logo" width="70" /></a>
    <a href="https://www.microsoft.com/en-ww/microsoft-365/powerpoint"><img src="https://img.icons8.com/color/344/ms-powerpoint.png" alt="MS PowerPoint logo" width="70" /></a>
</p>
<hr>

<h2 align="center" id="our-team">👥 Our Team</h2>

<p align="center">
 <a href="https://github.com/Martin-Zhelev"> Мартин Атанасов Желев </a> — 🧭 Scrum Trainer<br>
 <a href="https://github.com/DimitarNyagalov"> Димитър Пламенов Нягалов </a> — 🎨 Front-End Developer<br>
 <a href="https://github.com/Georgi-Ivaylov-Nikolov"> Георги Ивайлов Николов </a> — ⚙️ Back-End Developer<br>
 <a href="https://github.com/PNRusev24"> Пламен Николаев Русев </a> — 🖌️ Designer<br>
</p>
<hr>