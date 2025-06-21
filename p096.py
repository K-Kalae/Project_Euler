def is_valid(board, row, col, num):
    if num in board[row]:
        return False
    for r in range(9):
        if board[r][col] == num:
            return False
    start_row, start_col = 3 * (row // 3), 3 * (col // 3)
    for r in range(start_row, start_row + 3):
        for c in range(start_col, start_col + 3):
            if board[r][c] == num:
                return False
    return True


def solve_sudoku(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if is_valid(board, row, col, num):
                        board[row][col] = num
                        if solve_sudoku(board):
                            return True
                        board[row][col] = 0  # backtrack
                return False
    return True


def read_boards(filename):
    with open(filename, 'r') as f:
        lines = [line.strip() for line in f if line.strip()]
    
    boards = []
    board = []
    for line in lines:
        if line.startswith("Grid"):
            if board:
                boards.append(board)
                board = []
        else:
            board.append([int(c) for c in line])
    if board:
        boards.append(board)
    return boards


def write_boards(boards, filename):
    with open(filename, 'w') as f:
        for i, board in enumerate(boards, start=1):
            f.write(f"Grid {i:02d}\n")
            for row in board:
                f.write(''.join(str(num) for num in row) + "\n")

def sum_top_left_triples(filename):
    with open(filename, 'r') as f:
        lines = [line.strip() for line in f if line.strip()]
    
    total = 0
    i = 0
    while i < len(lines):
        if lines[i].startswith("Grid"):
            top_row = lines[i + 1]  # The first row of the current grid
            first_three_digits = int(top_row[:3])  # Take first 3 digits as number
            total += first_three_digits
            i += 10  # Move to the next "Grid" line (1 + 9 rows)
        else:
            i += 1  # Skip malformed lines if any

    return total



def main():
    boards = read_boards('p096_sudoku.txt')
    solved_boards = []
    for idx, board in enumerate(boards, start=1):
        print(f"Solving Grid {idx:02d}...")
        if solve_sudoku(board):
            solved_boards.append(board)
        else:
            print(f"Grid {idx:02d} has no solution!")
            solved_boards.append(board)  # still append to keep numbering consistent
    write_boards(solved_boards, 'solved.txt')
    print("All boards processed. Solutions saved in 'solved.txt'.")
    print(sum_top_left_triples("solved.txt"))


if __name__ == "__main__":
    main()
