# :joystick: Conway's Game of Life - Game Boy Edition

This is a working version of Conway's Game of Life for the classic Game Boy. Simply fire up your favorite Game Boy emulator and load the `game.gb` file. All the details of how the Game of Life works can be found [here](https://conwaylife.com/wiki/Conway%27s_Game_of_Life)
<br><br>
![t1](https://user-images.githubusercontent.com/503975/177911180-71f380c7-9d52-43a4-836a-510bcc4f770a.png)
![t2](https://user-images.githubusercontent.com/503975/177911181-3fa1645a-5620-4c9e-91b6-8306f2b82cc1.png)
![t3](https://user-images.githubusercontent.com/503975/177911183-39e210a9-1ff1-4da0-a9ae-4ea6e4b58d8d.png)
![t4](https://user-images.githubusercontent.com/503975/177911184-7077aa2d-7454-4c49-8253-69efa6f596c9.png)

## :rocket: Coding for the Game Boy

For curious its built with GBDK 2020 and heres the [GBDK 2020 C Guidelines](https://gbdk-2020.github.io/gbdk-2020/docs/api/docs_coding_guidelines.html#docs_c_tutorials) this will walk you through some of the limitations and tricks to make C run effeciently on the Game Boy. So if your wondering why so many things are globals or alive_neighbours doesnt use loops, or why I avoid using mods and other math functions its because the game boy hardware really doesnt like those things.

Since the Game Boy has a limit on how many sprites can be displayed on a line, the entire simulation works by moving background tiles around similar to how tetris works.

## :postbox: Contact & Support

Created by [Wyatt Ferguson](wyattxdev@duck.com)

For any comments or questions your can email me at [wyattxdev@duck.com](wyattxdev@duck.com)

[:coffee: Buy Me A Coffee](https://www.buymeacoffee.com/wyattferguson)

<br>
