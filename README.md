# :joystick: Conway's Game of Life - Game Boy Edition

This is a working version of Conway's Game of Life for the classic Game Boy. Simply fire up your favorite Game Boy emulator and load the `game.gb` file.

<br>

## :rocket: Coding for the Game Boy

For curious its built with GBDK 2020 and heres the [GBDK 2020 C Guidelines](https://gbdk-2020.github.io/gbdk-2020/docs/api/docs_coding_guidelines.html#docs_c_tutorials). So if your wondering why so many things are globals or why the sturctures a bit funny alot of it has to do with trying to save cycles on the GB. Also I havent really coded in C in like 15 years so that probably has something to do with it to.

The Game Boy is a bit under powered to really run this at any kind of speed, so I plan on adding an option to set the board size. Also the algorithm could probably be optimized by things like unrolling the alive_neighbours function to avoid using loops and remove the use of mod.

<br>

## :goggles: Credit, Contact & Support

Created by [Wyatt Ferguson](https://twitter.com/wyattxdev)

### [:coffee: Buy Me A Coffee](https://www.buymeacoffee.com/wyattferguson)

### [:zap: Follow me on Twitter](https://twitter.com/wyattxdev)

<br>
