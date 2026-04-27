# VirusGame
### VirusGame is a simple console game written in C++

You play as a virus that needs to infect all files 
while avoiding antiviruses and scanners.

## Enemies

### Antivirus
Chases the player within a small radius. 
Moves randomly when the player is far away. Fast.

### Scanner
Sees the player across the entire map. Slow.

### Firewall
Acts as a wall. Spawns randomly on the map.

## Goal
Infect all files on the map and reach the exit `>`.
Files disappear after infection.

## Controls
| Key | Action |
|-----|--------|
| WASD / Arrow keys | Move |
| ~ | Cheat menu (if enabled) |
| ESC | Exit |

## Custom Maps
Place your map in `levels/custom.txt` and enable **Custom map** in settings.


### Map format
Symbols:
| Symbol | Description |
|--------|-------------|
| `#` | Wall |
| ` ` | Empty space |

Example maps included in `levels/` folder ([example-levels.zip](https://github.com/v0idDuck/VirusGame/releases/latest)).
