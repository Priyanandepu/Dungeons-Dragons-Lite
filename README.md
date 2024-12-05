# Dungeons-Dragons-Lite

A simple text-based RPG game implemented in C. Players create a character, face off against a randomly generated monster, and engage in a turn-based combat system.

## Features
- **Character Creation**: Randomly generates player stats (Strength and Health) using 3d6 rolls.
- **Monster Creation**: Generates monster stats with added base values for strength and health.
- **Turn-Based Combat**: Players and monsters alternately attack and defend, with outcomes determined by dice rolls.

## How to Run the Game

### Prerequisites
1. A C compiler such as GCC installed on your system.
2. Basic understanding of command-line tools.

### Compilation and Execution
1. Save the program in a file named `dnd-lite.c`.
2. Open a terminal and navigate to the directory containing the file.
3. Compile the program using the following command:
   ```bash
   gcc dnd-lite.c -o dnd-lite
