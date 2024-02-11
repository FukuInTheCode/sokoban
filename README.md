# my_sokoban

## Module: B-PSU-100 (Grade: N/A)

## Project Description
 Recreation of the famous game 'sokoban' but in C using the ncurses library

### USAGE
 ./my_sokoban map
# Result: 97% (Mark: 19.8)
<details>
<summary>Click to expand test results</summary>

### 01 - usage and input checks (75% Passed)
| Test | Status |
| --- | --- |
| Call with an argument which is not a file | PASSED |
| Call with an invalid map | PASSED |
| Call with no argument | PASSED |
| Display usage | FAILURE |

### 02 - basic moves (100% Passed)
| Test | Status |
| --- | --- |
| Mini Map : '#####n#PXO#n#####n' (Free test) | PASSED |
| Move around a map (Free test) | PASSED |
| Other mini Map : | PASSED |
| Simple move only | PASSED |

### 03 - basic collisions and box on targets (100% Passed)
| Test | Status |
| --- | --- |
| Move box on a target | PASSED |
| Move box on a target (Free test) | PASSED |
| Try move over wall | PASSED |
| Try move over wall (Free test) | PASSED |

### 04 - intermediate moves and collisions (100% Passed)
| Test | Status |
| --- | --- |
| Move 1 | PASSED |
| Move 2 | PASSED |
| Move 3 | PASSED |
| Move 4 | PASSED |
| Play in simple map | PASSED |
| Play in simple map and try go outside | PASSED |

### 05 - intermediate maps tests (100% Passed)
| Test | Status |
| --- | --- |
| Double map | PASSED |
| Map with lot of box and target | PASSED |
| No square map | PASSED |
| Star shaped map | PASSED |

### 06 - intermediate winning and losing conditions (100% Passed)
| Test | Status |
| --- | --- |
| Losing a game | PASSED |
| Winning a game | PASSED |

### 07 - final moves and collisions (100% Passed)
| Test | Status |
| --- | --- |
| Move 1 - final | PASSED |
| Move 2 - final | PASSED |
| Move 3 - final | PASSED |
| Move 4 - final | PASSED |
| Play in simple map - final | PASSED |
| Play in simple map and try go outside - final | PASSED |

### 08 - final maps tests (100% Passed)
| Test | Status |
| --- | --- |
| Double map - final | PASSED |
| Map with lot of box and target - final | PASSED |
| No square map - final | PASSED |
| Star shaped map - final | PASSED |

### 09 - final winning and losing conditions (100% Passed)
| Test | Status |
| --- | --- |
| Losing a game - final | PASSED |
| Winning a game - final | PASSED |

</details>

## Tests
a python script that generate sokoban map randomly

