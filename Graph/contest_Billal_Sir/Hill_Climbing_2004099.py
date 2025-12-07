import random
from collections import Counter

# Goal state of the 8-puzzle
goal_state = [
    [1, 2, 3],
    [4, 0, 4],
    [7, 6, 5]
]

# Function to calculate Manhattan distance heuristic
def manhattan_distance(state):
    distance = 0
    for r in range(3):
        for c in range(3):
            value = state[r][c]
            if value != 0:  # Skip the empty space (0)
                goal_r, goal_c = divmod(value - 1, 3)
                distance += abs(r - goal_r) + abs(c - goal_c)
    return distance

# Function to get the possible moves for the empty space
def get_neighbors(state):
    neighbors = []
    empty_r, empty_c = [(r, c) for r in range(3) for c in range(3) if state[r][c] == 0][0]

    # Moves are defined as (row change, column change)
    moves = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # Up, Down, Left, Right

    for move in moves:
        new_r, new_c = empty_r + move[0], empty_c + move[1]
        if 0 <= new_r < 3 and 0 <= new_c < 3:  # Ensure the move is within bounds
            new_state = [row[:] for row in state]  # Create a copy of the current state
            # Swap the empty space (0) with the adjacent tile
            new_state[empty_r][empty_c], new_state[new_r][new_c] = new_state[new_r][new_c], new_state[empty_r][empty_c]
            neighbors.append((new_state, manhattan_distance(new_state)))

    return neighbors

def hill_climbing(initial_state):
    current_state = initial_state
    path = [current_state]
    current_heuristic = manhattan_distance(current_state)
    move_count = 0  # Initialize move counter

    while current_heuristic > 0:
        neighbors = get_neighbors(current_state)

        # Find the minimum heuristic value among the neighbors
        min_heuristic = min(heuristic for _, heuristic in neighbors)

        # Count the frequency of the minimum heuristic value
        heuristic_counts = Counter(heuristic for _, heuristic in neighbors)
        min_heuristic_freq = heuristic_counts[min_heuristic]

        # Print all neighbors and their heuristic values
        # print(f"Move {move_count}: Neighbors of current state:")
        # for neighbor, heuristic in neighbors:
        #     print(f"State:")
        #     for row in neighbor:
        #         print(row)
        #     print(f"Heuristic (Manhattan distance): {heuristic}\n")

        # If 3 neighbors have the same minimum heuristic value, we have a plateau
        if min_heuristic_freq == 3:
            print("Plateau problem: 3 neighbors have the same heuristic value, no progress.")
            break

        # If the frequency of the minimum heuristic is 2, select the neighbor with the maximum heuristic
        if min_heuristic_freq == 2:
            print("Selecting the neighbor with the maximum heuristic value among those with the minimum distance.")
            best_neighbors = [neighbor for neighbor, heuristic in neighbors if heuristic == min_heuristic]
            current_state = max(best_neighbors, key=lambda x: manhattan_distance(x))

        # If the frequency of the minimum heuristic is 1, select the neighbor with the minimum heuristic value
        if min_heuristic_freq == 1:
            print("Selecting the neighbor with the minimum heuristic value.")
            best_neighbors = [neighbor for neighbor, heuristic in neighbors if heuristic == min_heuristic]
            current_state = min(best_neighbors, key=lambda x: manhattan_distance(x))

        path.append(current_state)
        current_heuristic = manhattan_distance(current_state)
        move_count += 1  # Increment the move counter

    return path, current_heuristic, move_count


initial_state = [
    [2, 3, 4],
    [5, 0, 7],
    [8, 1, 6]
]

path, final_heuristic, move_count = hill_climbing(initial_state)

# for idx, state in enumerate(path):
#     print(f"Move {idx}:")
#     for row in state:
#         print(row)
    # print(f"Manhattan distance: {manhattan_distance(state)}\n")

if final_heuristic == 0:
    print(f"Goal state reached in {move_count} moves!")
else:
    print(f"Could not reach the goal state")
