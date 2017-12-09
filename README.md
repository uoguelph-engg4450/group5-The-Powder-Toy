The Powder Toy - ENGG4450 Group 5 Branch
==========================

Fixed issue #524: Setting disable pressure being included in saves.

Added automated and unit testing.


Build instructions
===========================================================================

    sudo apt-get install build-essential libsdl1.2-dev libbz2-dev zlib1g-dev liblua5.1.0-dev git scons libfftw3-dev libcppunit-dev

    scons -c && scons -j10

Thanks
===========================================================================

* Stanislaw K Skowronek - Designed the original
* Simon Robertshaw
* Skresanov Savely
* cracker64
* Catelite
* Bryan Hoyle
* Nathan Cousins
* jacksonmj
* Felix Wallin
* Lieuwe Mosch
* Anthony Boot
* Matthew "me4502"
* MaksProg
* jacob1
* mniip


Instructions
===========================================================================

Click on the elements with the mouse and draw in the field, like in MS Paint. The rest of the game is learning what happens next.


Controls
===========================================================================

| Key                     | Action                                                          |
| ----------------------- | --------------------------------------------------------------- |
| TAB                     | Switch between circle/square/triangle brush                     |
| Space                   | Pause                                                           |
| Q / Esc                 | Quit                                                            |
| Z                       | Zoom                                                            |
| S                       | Save stamp (+ Ctrl when STK2 is out)                            |
| L                       | Load last saved stamp                                           |
| K                       | Stamp library                                                   |
| 1-9                     | Set view mode                                                   |
| P / F2                  | Save screenshot to .png                                         |
| E                       | Bring up element search                                         |
| F                       | Pause and go to next frame                                      |
| G                       | Increase grid size                                              |
| Shift + G               | Decrease grid size                                              |
| H                       | Show/Hide HUD                                                   |
| Ctrl + H / F1           | Show intro text                                                 |
| D / F3                  | Debug mode (+ Ctrl when STK2 is out)                            |
| I                       | Invert Pressure and Velocity map                                |
| W                       | Toggle gravity modes (+ Ctrl when STK2 is out)                  |
| Y                       | Toggle air modes                                                |
| B                       | Enter decoration editor menu                                    |
| Ctrl + B                | Toggle decorations on/off                                       |
| N                       | Toggle Newtonian Gravity on/off                                 |
| U                       | Toggle ambient heat on/off                                      |
| Ctrl + I                | Install powder toy, for loading saves/stamps by double clicking |
| ~                       | Console                                                         |
| =                       | Reset pressure and velocity map                                 |
| Ctrl + =                | Reset Electricity                                               |
| [                       | Decrease brush size                                             |
| ]                       | Increase brush size                                             |
| Alt + [                 | Decrease brush size by 1                                        |
| Alt + ]                 | Increase brush size by 1                                        |
| Ctrl + C/V/X            | Copy/Paste/Cut                                                  |
| Ctrl + Z                | Undo                                                            |
| Ctrl + Y                | Redo                                                            |
| Ctrl + Cursor drag      | Rectangle                                                       |
| Shift + Cursor drag     | Line                                                            |
| Middle click            | Sample element                                                  |
| Alt + Left click        | Sample element                                                  |
| Mouse scroll            | Change brush size                                               |
| Ctrl + Mouse scroll     | Change vertical brush size                                      |
| Shift + Mouse scroll    | Change horizontal brush size                                    |
| Shift + R               | Horizontal mirror for selected area when pasting stamps         |
| Ctrl + Shift + R        | Vertical mirror for selected area when pasting stamps           |
| R                       | Rotate selected area counterclockwise when pasting stamps       |



Command Line
---------------------------------------------------------------------------

| Command                  |                                                                |
| ------------------------ | -------------------------------------------------------------- |
| scale:<size>             | Change window scale                                            |
| kiosk                    | Fullscreen mode                                                |
| proxy:server[:port]      | Proxy server to use [Example: proxy:wwwcache.lancs.ac.uk:8080] |
| open <file>              | Opens the file as a stamp or game save                         |
| ddir <directory>         | Directory used for saving stamps and preferences               |
| ptsave:<save id>#[name]  | [Example: ptsave:2198#Destroyable_city_5_wth_metro~dima-gord]  |
