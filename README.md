# So_long
>A small top-down, 2D game with textures, sprites, and basic gameplay.
<img width="1001" alt="screenshot" src="https://github.com/mpeterson114/so_long/assets/109201695/397569f0-f871-4672-a858-8d05cab715f0">

## ⚙️ Usage

Clone the repository:

```
git clone git@github.com:mpeterson114/so_long.git
```

Enter the repository with ```cd``` and compile:

  * Mandatory version: ```make```
  * Bonus version: ```make bonus```

Run the program executable with the map of your choice as a parameter:

  * Ex. mandatory version: ```./so_long maps/map1.ber ```
  * Ex. bonus version: ```./so_long maps_bonus/map1_bonus.ber```

## 📌 Game Rules
  * The map extension must be of type '.ber'
  * The game map must be square or rectangular, surrounded by closed walls
  * The map must have only one exit, one player and at least one collectable

Permitted map characters:
| Character | Game Element |
|-----------|-------------|
| 1         | Wall        |
| 0         | Floor       |
| P         | Player's starting position     |
| C         | Collectable |
| E         | Exit        |
| B (bonus only) | Barrier |

### Controls
  * You can move up, down, left or right using the arrow keys or the ```W S A D``` keys respectively.
