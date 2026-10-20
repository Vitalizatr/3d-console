
# 3D Console

A small C++ console-based pseudo-3D maze game made as a personal coding experiment and challenge.
<img width="734" height="583" alt="Снимок экрана 2026-10-20 в 21 17 49" src="https://github.com/user-attachments/assets/bdfc5cc0-721b-4a0d-8a44-01bcc9324497" />

## Project background

This project was created as a personal challenge: build a simple first-person-style 3D scene from scratch using only my own reasoning, mathematics, and problem-solving, without relying on tutorials, copy-paste solutions, or external guidance.

The goal was not to create a polished engine or production-ready game, but to revisit the fundamentals:
- ray casting
- geometry and projection
- map traversal
- wall collision
- terminal rendering

It was a hands-on exercise in logic and math, and it was a great way to stay sharp and keep the brain active. The challenge turned out to be both useful and enjoyable: it helped me remember how to think through spatial problems and how to build a system from basic principles instead of relying on ready-made patterns.

This project is intentionally minimal and experimental. The README itself was written with GitHub Copilot as a documentation aid, but the actual project logic, implementation, and experimentation were done independently.

## Description

This project renders a maze in a pseudo-3D view directly in the terminal. It uses a simplified ray-casting approach to simulate a first-person perspective inside a 2D map.

The player can:
- move through the maze
- rotate direction
- observe walls projected as height-based columns
- explore a small environment from a first-person point of view

## Features

- 2D map-based level
- pseudo-3D console rendering
- simple ray-casting logic
- player movement and rotation
- wall collision detection
- lightweight C++ implementation
- no external graphics libraries required

## Controls

- `W` — move forward
- `A` — turn left
- `D` — turn right
- `Q` — quit

## Project structure

- `main.cpp` — game loop, setup, and main execution
- `map.h`, `map.cpp` — map storage and basic map logic
- `player.h`, `player.cpp` — player position, direction, movement, and vision calculation
- `column.h`, `column.cpp` — wall projection and terminal rendering

## How it works

The project uses a simplified ray-casting method:

1. The player has a position and direction.
2. Rays are cast across the field of view.
3. Each ray checks whether it intersects a wall in the map.
4. The distance to the wall is calculated.
5. The wall is projected into a pseudo-3D column and drawn in the console.

This creates a basic first-person-style view using only text characters and simple math.

## Build and run

### Linux / macOS

```bash
g++ main.cpp map.cpp player.cpp column.cpp -o 3d_console
./3d_console
```

### Windows (MinGW / MSYS2 / similar)

```bash
g++ main.cpp map.cpp player.cpp column.cpp -o 3d_console.exe
3d_console.exe
```


## Notes

- This is an experimental project, not a production game engine.
- **The "NO AI" Challenge:** This entire project was built completely from scratch without using AI, tutorials, guides, or external help. The only thing Copilot was allowed to touch was writing this README!
- The code is intentionally simple, educational, and stands as a testament to pure, independent problem-solving.
- The project is useful for learning how ray-casting works in practice and how 2D maps can be turned into a 3D-like representation in the terminal.

## Future

This challenge was a perfect way to break away from modern assists and push my limits. Developing everything blindly from my own head was an amazing exercise that forced me to dust off my math and logic skills, keeping my engineering brain in perfect tone. 

I absolutely loved the experience, and I definitely plan to do more of these "scratch-built / no-AI" projects in the future to keep learning, improving, and keeping my skills sharp.
