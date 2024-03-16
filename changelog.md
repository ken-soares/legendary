# Engine Changes

## Feature Implementations

### 16/03/2024
- reworked `Scene` class to have a bool `shouldQuit` with getters and setters
- reworked `MenuScene` to add a quit button using the parent class getters and setters
- reworked `main.cpp` to break out of game loop if `shouldQuit` is true
 
## Design Changes
- recentered every element in the main menu