This is a simple 2D game that was made for Hive Helsinki's so_long project. It is using MLX42, a windowing graphics library made for the 42 network: https://github.com/codam-coding-college/MLX42.

The images used for the graphics are not my own, so I'd also like to thank the following artists for sharing their work for free on itch.io:

LuizMelo for the cat assets - https://luizmelo.itch.io/pet-cat-pack

Ma9ici4n for the bird - https://ma9ici4n.itch.io/pixel-art-bird-16x16

PXLer Game for the house - https://pxlergame.itch.io/pico8house

FrozenTaurus for the tree and grass assets - https://frozentaurus.itch.io/frozentauruss-grass-tile-set

***INSTALLATION***

The files necessary for the installation of MLX42 are included in this repository - however, MLX42 is dependant on glfw, which is NOT included.

1. Install glfw and cmake. (You can find OS-specific instructions for doing so on MLX42's github page)
2. Clone this repository
3. Open the Makefile at the root of the repository, and find the macro "GLFW_DIR". This is the file path to glfw - change it to reflect where you installed it on your system in the first step.
4. Open a terminal, and navigate to the root of the repository.
5. Run the command "make"

You should now have an executable of the name "so_long"

***HOW TO PLAY***

***Part I. - Prepare a valid map***

This game was made to be able to generate a playable map based on a text file ending in the .ber extension. A default map has been included, but this also enables the creatin of custom maps. The requirements for a map to be considered playable are the following:

1. It must have the .ber extension
2. It must only contain 5 types of character, which represent elements of the map. These are:
     '1' - trees
     '0' - open ground
     'C' - birds (collectibles)
     'E' - house (exit)
     'P' - the cat (the player's starting position)
3. It must have exactly one exit (E) and starting position (P), as well as at least one collectible (C)
4. The map must be surrounded by walls
5. The map must be a rectangle
6. There must be a valid path through the map: the exit and the collectibles must all be accessible.
7. The last line must not end with a newline / enter

An example of a valid map:

1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111

Note: This is a simple game, and my first graphics project, so there's a few limitations as to the size of map that can be properly displayed. All the grids in the map are drawn as a specific size, so large maps might not "fit" onto your screen, might not be fully visible. The grid size the program's using is specified as a macro in the file so_long.h as SCALE. Thus, to modify the "resolution", change this macro to a number of your choice, and then run the "make" command again for the change to take effect.

***Part II. - Launching the game***

The map you wish to use must be specified as a command line argument. When using the default map, open a terminal, navigate to the root of the repository where the so_long executable is, and run:
  ./so_long map/map.ber

If you are using a custom map, change "map/map.ber" to the file path and file name (FILE_PATH/FILE_NAME) of your own file.

***Part III. - Playing the game***

The goal of the game is to help the cat eat all the birds in the yard, and then return to the house. Until all birds are eaten, you cannot return to the house. If you have eaten all the birds and reached the house, the game will automatically exit. You can exit early by pressing Esc or simply closing the window.
The cat can be moved using the arrow keys: the number of moves you have made will be displayed on the terminal (NOTE: to have the moves be displayed directly on the game window, you need to use the command "make bonus" in the 5th step of the installation.)
The game window behaves as any other window: it can be minimised, moved around on the screen, etc. Note: even though it can be resized as well, this won't affect the game graphics' scale.
