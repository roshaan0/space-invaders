\# Space Invaders



A 2D vertical shooter game developed in \*\*C++\*\* using the \*\*Simple and Fast Multimedia Library (SFML)\*\*. This project recreates the classic arcade-style Space Invaders experience while extending it with modern gameplay elements such as multiple enemy types, boss encounters, parallax scrolling backgrounds, and a persistent high score system.



---



\## Project Overview



The game is built using a scene-based architecture that cleanly separates different states of the application, including the Main Menu, Gameplay, Pause Screen, High Score display, and Game Over screen. Object-oriented programming principles are used throughout the codebase to manage game entities such as the player, enemies, bullets, power-ups, and UI components.



This structure improves maintainability, scalability, and clarity of the overall game logic.



---



\## Features



\* \*\*Wave-Based Progression\*\*

&nbsp; The game advances through multiple phases and levels. As phases are completed, difficulty increases and level transitions occur.



\* \*\*Enemy Variety\*\*

&nbsp; Includes multiple enemy types (Alpha, Beta, Gamma), each with distinct movement patterns, shooting behavior, and difficulty scaling.



\* \*\*Boss Battles\*\*

&nbsp; Boss enemies appear at specific progression thresholds (enemy types greater than 12), featuring increased health pools and unique movement logic.



\* \*\*High Score System\*\*

&nbsp; Player scores are stored in a local text file (`highscores.txt`). Scores are loaded, sorted, and displayed, showing the top 10 records.



\* \*\*Parallax Background\*\*

&nbsp; Implements a multi-layer scrolling background to create a depth effect during gameplay.



\* \*\*Power-Up System\*\*

&nbsp; Randomly generated power-ups enhance player abilities and assist during combat.



\* \*\*User Interface System\*\*

&nbsp; Mouse-interactive buttons enable navigation across menus including Play, Pause, Continue, Quit, and Back.



---



\## Dependencies



To build and run this project, the following are required:



\* \*\*C++ Compiler\*\* compatible with C++17 or later (MSVC, GCC, or Clang)

\* \*\*SFML 2.5.1\*\*, including the following modules:



&nbsp; \* Graphics

&nbsp; \* Window

&nbsp; \* System



---



\## Configuration and Build Instructions



\### Important Note on Include Paths



The source code contains absolute include paths referencing a specific user directory (for example, `C:\\Users\\rosha\\...`). Before compiling, these paths must be updated or replaced by configuring your IDE to reference your local SFML installation.



---



\### Build Steps (Visual Studio)



1\. Install \*\*SFML 2.5.1\*\* and extract it to a known directory.



2\. Open the provided Visual Studio solution file (`.sln`).



3\. Open \*\*Project Properties\*\* and configure the following:



&nbsp;  \* \*\*C/C++ → General → Additional Include Directories\*\*

&nbsp;    Add the path to:



&nbsp;    ```

&nbsp;    SFML-2.5.1/include

&nbsp;    ```



&nbsp;  \* \*\*Linker → General → Additional Library Directories\*\*

&nbsp;    Add the path to:



&nbsp;    ```

&nbsp;    SFML-2.5.1/lib

&nbsp;    ```



&nbsp;  \* \*\*Linker → Input → Additional Dependencies\*\*

&nbsp;    Add:



&nbsp;    ```

&nbsp;    sfml-graphics.lib

&nbsp;    sfml-window.lib

&nbsp;    sfml-system.lib

&nbsp;    ```



4\. Build the project using \*\*Ctrl + Shift + B\*\*.



---



\### Assets Configuration



Ensure the following resources are present in the executable directory or correctly configured as the project working directory:



\* `Assets/` folder (sprites, textures, background images)

\* `ARCADECLASSIC.TTF` font file



---



\## Controls



\### Mouse Controls



\* Navigate menus

\* Click UI buttons such as Play, Pause, Continue, Quit, and Back



\### Keyboard Controls



\* \*\*Movement:\*\* Arrow Keys or WASD

\* \*\*Shoot:\*\* Spacebar

\* \*\*Enter:\*\* Restart the game from the Game Over screen



---



\## File Structure



```

Space-Invaders/

│

├── main.cpp              # Application entry point and screen state management

├── GameScene.cpp         # Core gameplay loop, collisions, and level logic

├── HighScoreScene.cpp    # High score file I/O and display logic

├── Enemy.cpp             # Enemy behavior, movement, and shooting logic

├── MainMenu.cpp          # Main menu screen handling

├── Global.h              # Global constants and configuration

├── Assets/               # Game assets (images, fonts)

└── README.md

```



---



\## Data Persistence



The game generates and maintains the following files in the working directory:



1\. \*\*highscores.txt\*\*

&nbsp;  Stores the top player scores used for ranking and display.



2\. \*\*data.txt\*\*

&nbsp;  Logs player-related data for tracking and debugging purposes.



---



\## License



This project is open-source and intended for educational use, demonstrating game development concepts, object-oriented design, and multimedia programming using C++ and SFML.



