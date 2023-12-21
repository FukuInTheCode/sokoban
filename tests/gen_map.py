import random

def generate_sokoban_map():
    # Generate random rows and columns
    rows = random.randint(5, 15)
    cols = random.randint(10, 25)

    # Initialize an empty map
    sokoban_map = [[' ' for _ in range(cols)] for _ in range(rows)]

    # Add random walls to the map
    for _ in range(rows * cols // 4):
        wall_position = (random.randint(1, rows - 2), random.randint(1, cols - 2))
        sokoban_map[wall_position[0]][wall_position[1]] = '#'

    # Add player (P)
    player_position = (random.randint(1, rows - 2), random.randint(1, cols - 2))
    sokoban_map[player_position[0]][player_position[1]] = 'P'

    # Calculate the number of boxes (X) and storage locations (O)
    num_boxes = random.randint(1, min(rows, cols) // 2)
    num_storage_locations = num_boxes

    # Add boxes (X) and storage locations (O)
    for _ in range(num_boxes):
        box_position = (random.randint(1, rows - 2), random.randint(1, cols - 2))
        while sokoban_map[box_position[0]][box_position[1]] != ' ':
            box_position = (random.randint(1, rows - 2), random.randint(1, cols - 2))
        sokoban_map[box_position[0]][box_position[1]] = 'X'

    for _ in range(num_storage_locations):
        storage_position = (random.randint(1, rows - 2), random.randint(1, cols - 2))
        while (
            sokoban_map[storage_position[0]][storage_position[1]] != ' '
            or storage_position == player_position
        ):
            storage_position = (
                random.randint(1, rows - 2),
                random.randint(1, cols - 2),
            )
        sokoban_map[storage_position[0]][storage_position[1]] = 'O'

    return sokoban_map

def print_sokoban_map(sokoban_map):
    for row in sokoban_map:
        print(''.join(row))

if __name__ == "__main__":
    sokoban_map = generate_sokoban_map()
    print_sokoban_map(sokoban_map)

