# Space Invaders (SFML)

Space Invaders is a 2D vertical shooter game developed in C++ using the Simple and Fast Multimedia Library (SFML). The project recreates the classic arcade-style Space Invaders experience while extending it with modern gameplay elements such as wave-based progression, multiple enemy types, boss battles, parallax scrolling backgrounds, and a persistent high score system.

## Project Overview

The game is built using a scene-based architecture that manages transitions between the Main Menu, Gameplay, Pause Screen, High Score Screen, and Game Over Screen. Object-oriented programming principles are applied throughout the project to organize core components, including the player, enemies, bullets, power-ups, and user interface elements. This design keeps the code modular, readable, and easy to extend.

## Features

The game progresses through multiple waves and phases, with difficulty increasing as the player advances. Different enemy types such as Alpha, Beta, and Gamma are implemented, each having unique movement patterns and attack behaviors. Boss enemies appear at specific progression thresholds and feature increased health along with distinct movement logic. A persistent high score system stores player scores in a local text file named `highscores.txt`, which is loaded, sorted, and displayed to show the top ten scores. The visual experience is enhanced using a parallax scrolling background implemented with multiple layers to create a depth effect. Randomly generated power-ups assist the player during combat. The game also includes a mouse-interactive user interface with buttons for navigation such as Play, Pause, Continue, Quit, and Back.

## Dependencies

To build and run this project, a C++ compiler compatible with C++17 or later is required, such as MSVC, GCC, or Clang. The project depends on SFML version 2.5.1, specifically the Graphics, Window, and System modules.

## Build and Run Instructions

SFML 2.5.1 must be downloaded and extracted to a known directory on the system. The Visual Studio solution file (`.sln`) should be opened to configure the project. The source code currently contains absolute include paths pointing to a specific user directory, so these paths must be updated or replaced by configuring the project settings. In Visual Studio, the SFML include directory should be added under C/C++ → General → Additional Include Directories, and the SFML library directory should be added under Linker → General → Additional Library Directories. The linker input must include `sfml-graphics.lib`, `sfml-window.lib`, and `sfml-system.lib`. Once configured, the project can be built using Ctrl + Shift + B and run using F5. The `Assets` folder and the `ARCADECLASSIC.TTF` font file must be present in the working or executable directory.

## Controls

The mouse is used to navigate menus and interact with user interface buttons. Keyboard controls include Arrow Keys or WASD for movement, Spacebar for shooting, and the Enter key to restart the game from the Game Over screen.

## Project Structure

The project includes an `Assets` directory containing images and font files, `main.cpp` as the application entry point and screen state manager, `GameScene.cpp` for the core gameplay loop and collision handling, `HighScoreScene.cpp` for high score file input and output, `Enemy.cpp` defining enemy behavior and shooting logic, `MainMenu.cpp` for menu handling, `Global.h` for global constants and configuration, and `README.md` for documentation.

## Data Persistence

The game generates two text files in the working directory. The file `highscores.txt` stores the top player scores, while `data.txt` logs player-related data for tracking and debugging purposes.

## License

This project is open-source and intended for educational purposes, demonstrating C++ game development concepts, object-oriented programming, and multimedia application design using SFML.
