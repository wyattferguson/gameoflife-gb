# :joystick: Conway's Game of Life - Game Boy Edition

This is a working version of Conway's Game of Life for the classic Game Boy. Simply fire up your favorite Game Boy emulator and load the `game.gb` file.

<br>

## :rocket: Coding for the Game Boy

For curious its built with GBDK 2020 and heres the [GBDK 2020 C Guidelines](https://gbdk-2020.github.io/gbdk-2020/docs/api/docs_coding_guidelines.html#docs_c_tutorials). So if your wondering why so many things are globals or alive_neighbours doesnt use loops, or why I avoid using mods its because the game boy hardware really doesnt like those things. I rewrote the alive_neighbours function and unrolled all the loops and removed and fancy math tricks that a normal CPU would be fine with and got like a 10x improvement in performance.

<br>

## :goggles: Credit, Contact & Support

Created by [Wyatt Ferguson](https://twitter.com/wyattxdev)

### [:coffee: Buy Me A Coffee](https://www.buymeacoffee.com/wyattferguson)

### [:zap: Follow me on Twitter](https://twitter.com/wyattxdev)

<br>
