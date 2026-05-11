# ASCII-Games

An ASCII implementation of Snake within C and Minesweeper within C#. All within your very own console!

## ASCII-Snake

This project uses `<windows.h>`, so it is only compatible with Windows OS.

![Image](./assets/animation.gif)

### How it works

A simple while loop with a `sleep` statment at the end of the logic moves the screen,
while ANSII escape codes handle "refreshing" the screen.

The program uses the Windows function `GetAsyncKeyState` to get keypresses that occured while the program was still refreshing.

### Running

Make sure you have `ninja`, `cmake`, and a `C compiler`.

Then run these commands:

``` txt
make snake-reset
make snake-run
```

ASCII-Snake uses classic `WASD` controls.

## ASCII-Minesweeper

Minesweeper game within terminal with ASCII characters

You play by inputting with `m` and then the coordinates of the square you wish to click to mark it with a flag or just type the coordinates of the square to click it.

### Running

To run the program, run `make ms-run`.
