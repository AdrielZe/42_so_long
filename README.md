# So Long

## Description

**So Long** is a project from 42 that aims to develop a small 2D game using the **MinilibX** library. The game is based on a simple mechanic: the player must control a character to collect items, avoid enemies (if any), and reach the exit of a map while ensuring all rules and functionalities comply with the required specifications.

---

## Project Objectives

- Learn about graphic rendering and window management using **MinilibX**.
- Work with file manipulation to load and validate maps.
- Apply memory management concepts and prevent leaks.
- Develop a functional and visually appealing game in C.

---

## Requirements

- **MinilibX Library**: The project uses MinilibX to render the game.
- **Valid Maps**: The map must be a `.ber` file containing a rectangular representation of the game area. Each map must include:
  - A `P` character to indicate the player's starting position.
  - At least one `C` to represent collectible items.
  - An `E` character to indicate the exit.
  - Walls represented by `1` and empty spaces by `0`.
- **User Events**: The game must respond to keyboard inputs and close gracefully upon receiving the appropriate command.

---

## Features

- **Player Movement**: The player can move in four directions (up, down, left, and right).
- **Item Collection**: The player must collect all items (`C`) to unlock the exit (`E`).
- **Collision Detection**: The player cannot pass through walls (`1`).
- **Move Counter**: The game displays the total number of moves made by the player.
- **Map Validation**: The program must verify the validity of the map before starting the game.

---

## Compiling the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/YOUR_USERNAME/so_long.git
   cd so_long
   ```

2. Ensure that you have **MinilibX** installed on your system.

3. Compile the project using the `Makefile`:

   ```bash
   make
   ```

4. Run the game:

   ```bash
   ./so_long maps/example_map.ber
   ```

---

## Game Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **ESC**: Close the game
