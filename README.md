# 3D Console

A small C++ console-based pseudo-3D maze game made as a personal coding experiment and challenge.

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
- The code is intentionally simple and educational.
- The project is useful for learning how ray-casting works in practice and how 2D maps can be turned into a 3D-like representation in the terminal.

## Future

This challenge was a good reminder that building something from scratch is one of the best ways to strengthen logic, math, and problem-solving skills. It was a valuable exercise, and I plan to do more projects like this in the future to keep learning and improving.
