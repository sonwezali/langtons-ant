*This README file was written with the help of AI.*

# Langton's Ant (Raylib)

This project is an implementation of Langton's Ant using the Raylib graphics library. Langton's Ant is a two-dimensional universal Turing machine with a very simple set of rules but complex emergent behavior. The ant moves on a grid of black and white cells, turning and flipping the color of the cell according to simple rules.


https://github.com/user-attachments/assets/ba00e805-6925-4af7-9097-c03798feec22


## Features
- Visual simulation of Langton's Ant

## Requirements
- [Raylib](https://www.raylib.com/) (C graphics library)
- C compiler (e.g., gcc)

## Building
1. Make sure Raylib is installed on your system.
2. Compile the project using gcc:
   ```bash
   gcc ant.c -o ant -lraylib -lm
   ```
   (You may need to adjust the linker flags depending on your system.)

## Running
After building, run the simulation with:
```bash
./ant
```

## Files
- `ant.c`: Main source code for the simulation

## License
This project is open source, released under the MIT License. See the [LICENSE](LICENSE) file for details.

## References
- [Langton's Ant - Wikipedia](https://en.wikipedia.org/wiki/Langton%27s_ant)
- [Raylib](https://www.raylib.com/)
