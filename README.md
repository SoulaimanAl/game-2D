GAME-2D

Overview

Game-2D is project developed in C using the MinilibX (MLX) graphics library. The player navigates a character through a maze-like map, collecting coins, avoiding enemies, and reaching the exit while tracking their movements.

Features

	Loads and renders maps from .ber files.

	Uses MinilibX for graphical rendering.

	Supports movement using arrow keys.

	Displays a move counter on the screen.

	Implements a flood-fill algorithm to validate maps.

	Various sprites for the player, enemies, coins, walls, and exit.

Installation requirements :
 
	MinilibX (MLX)
	X11 and related libraries (libXext, libX11, libm)
	A Linux system or macOS
	Build Instructions

Clone the repository and compile the project:

	git clone <your-repo-link>
	cd so_long
	make

	Running the Game

	Run the executable with a map file:

	./so_long maps/example.ber

Game Controls keys

Move Left ←

Move Right →

Move Up ↑

Move Down ↓

Exit the game ESC or the exit in the right corner of window

File Structure

so_long
│── textures            # Game images (player, enemies, etc.)
│── maps                # Sample maps
│── Makefile            # Compilation script
│── README.md           # Project documentation

Map Format

The game expects a .ber map file formatted like this:

1111111 
1P00001 
1C1E0N1 
1111111 

1 → Wall

0 → Allowable path

P → Player spawn

C → Collectible (coin)

E → Exit

N → Enemy

Credits

This project was created as part of 42 School's curriculum.
