def display_board(board):
    for row in board:
        print(" | ".join(row))
        print("-" * 5)

def is_winner(board, player):
    for row in board:
        if all(slot == player for slot in row):
            return True

    for col in range(3):
        if all(board[row][col] == player for row in range(3)):
            return True

    if all(board[i][i] == player for i in range(3)) or all(board[i][2 - i] == player for i in range(3)):
        return True

    return False

def is_draw(board):
    return all(all(slot != " " for slot in row) for row in board)

def play_game():
    board = [[" " for _ in range(3)] for _ in range(3)]
    current_player = "X"

    while True:
        display_board(board)
        row = int(input(f"Player {current_player}, choose your row (0-2): "))
        col = int(input(f"Player {current_player}, choose your column (0-2): "))

        if board[row][col] == " ":
            board[row][col] = current_player
            if is_winner(board, current_player):
                display_board(board)
                print(f"Player {current_player} wins!")
                break
            elif is_draw(board):
                display_board(board)
                print("The game is a draw!")
                break
            current_player = "O" if current_player == "X" else "X"
        else:
            print("That cell is already occupied, try again.")

if __name__ == "__main__":
    play_game()
