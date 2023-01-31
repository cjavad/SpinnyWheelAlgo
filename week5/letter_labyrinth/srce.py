def neighbors(grid, x, y):
    n = []
    b = len(grid)

    if x + 1 < b and grid[x + 1][y] != grid[x][y]:
        n.append((x + 1, y))
    if x - 1 >= 0 and grid[x - 1][y] != grid[x][y]:
        n.append((x - 1, y))
    if y + 1 < b and grid[x][y + 1] != grid[x][y]:
        n.append((x, y + 1))
    if y - 1 >= 0 and grid[x][y - 1] != grid[x][y]:
        n.append((x, y - 1))

    return n

def newfill(grid):
    rounds = 1
    n = len(grid)
    fill = [[0 for _ in range(n)] for _ in range(n)]

    active = [(0, 0)]

    while fill[n - 1][n - 1] == 0:
        next_active = []

        for p in active:
            for neighbor in neighbors(grid, p[0], p[1]):
                if fill[neighbor[0]][neighbor[1]] == 0:
                    fill[neighbor[0]][neighbor[1]] = 1
                    next_active.append(neighbor)

        active = next_active
        rounds += 1

    return rounds


if __name__ == "__main__":
    # Parse n x n grid of letters
    grid = [[ord(x) - 65 for x in list(input())] for _ in range(int(input()))]
    
    # Find shortest path
    path = newfill(grid)
    print(path)