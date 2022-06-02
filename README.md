# Job Creator


### Cargo Market job creator for ETS2 with lots of features, including:

- Teleport function for editing position of a truck + trailer
- Automatic profile and saves discovery
- Editing of many job parameters
- Auto-fill of parameters
- Quick and optimised save reading/writing
- ... and more!

<br>

### How it works?

This program is reading and rewriting chosen save with set parameters of a teleport position/job. The process of reading or writing a save takes a few seconds, depending on many factors (CPU speed/load, disk speed/load, save size after decoding, ...)

<br>

### How to use it?

0. Make sure you don't have enabled Steam Cloud on the save you want to edit.
    - In case you have, turn off Steam Cloud on your save, load into a game, make a save/drive a bit, and your save shoudl appear in Documents.
1. Launch the program. It'll try to detect saves automatically in your Documents. In case it can't find in a default path, you can enter it manually.
2. Select a correct map set and load a save
3. Choose a parameters, hit a button, and enjoy!

<br>

### Notes

This program uses [SQLite](https://www.sqlite.org/index.html) for database manipulation and [Boost C++ libraries](https://www.boost.org/) for easier development.

If you wish to edit and compile code by yourself, you have to enter a correct path for the libraries above in the project settings. Boost libraries need to be compiled as well.
