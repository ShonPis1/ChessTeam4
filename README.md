# ChessTeam4

A two-player chess game made of two programs that talk to each other over a Windows named pipe:

- **Engine** (C++, `ChessGame/`) – holds the board, validates moves and reports the result of each move.
- **Graphics frontend** (C# WinForms, `ChessGame/chessGraphics/`) – draws the board, lets the players click a piece and a destination, and shows the engine's answer.

A prebuilt frontend is included as `chessGraphics.exe`.

## Features

- Movement rules for all pieces (king, queen, rook, bishop, knight, pawn), including blocked paths
- Turn order enforcement (white starts)
- Check detection, and rejection of moves that leave your own king in check
- Castling
- Checkmate detection
- Highlighting of selected pieces, check and checkmate in the UI

Not implemented yet: pawn promotion, en passant, stalemate / draw detection.

## Requirements

- Windows (the pipe code uses the Win32 API and the frontend is WinForms)
- Visual Studio 2022 (C++ toolset `v143` for the engine, .NET Framework 4.5+ for the frontend)

## Running the game

The frontend is the pipe server and the engine is the client, so **start the frontend first**.

1. Run `chessGraphics.exe`, or build and run `ChessGame/chessGraphics/chessGraphics/chessGraphics.csproj`. It shows a "waiting for engine" message.
2. Open `ChessGame/ChessGame.sln` in Visual Studio, then build and run the engine. It connects to the pipe `\\.\pipe\chessPipe`.
3. Play by clicking a piece and then its destination square.

If the engine cannot connect, it asks whether to retry (`0`) or exit (`1`).

## How the two programs communicate

1. After connecting, the engine sends the board as a 65-character string. The first 64 characters are the squares from rank 8 down to rank 1 (a to h within each rank). Uppercase is white, lowercase is black, `#` is an empty square. The last character is the player to move: `0` white, `1` black.
2. The frontend sends a move as four characters, for example `e2e4`, or `quit` to end the session.
3. The engine answers with a single digit:

| Code | Meaning |
|------|---------|
| 0 | Valid move |
| 1 | Valid move, the opponent is in check |
| 2 | Invalid: not your piece / not your turn |
| 3 | Invalid: destination holds one of your own pieces |
| 4 | Invalid: the move leaves your own king in check |
| 5 | Invalid: out of bounds or malformed move |
| 6 | Invalid: illegal movement for that piece |
| 7 | Invalid: source and destination are the same |
| 8 | Checkmate |

## Project structure

```
ChessGame/
  main.cpp, Communicator.*       pipe loop, board serialization, move parsing
  Pipe.h                         Win32 named pipe client
  Board.*                        board state, move validation, check / castling / mate
  Piece.*, King.*, Queen.*,      one class per piece type, all derived from Piece
  Rook.*, Bishop.*, Knight.*, Pawn.*
  Coord.*                        (row, column) position on the board
  chessGraphics/                 C# WinForms frontend
tests/board_tests.cpp            engine tests (no Windows needed)
ChessGame_frontend_UML.drawio    UML diagram (open it at draw.io)
```

## Tests

The engine logic does not depend on Windows, so the tests build with any C++17 compiler. From the repository root:

```bash
g++ -std=c++17 -IChessGame tests/board_tests.cpp ChessGame/Board.cpp ChessGame/Communicator.cpp \
    ChessGame/Coord.cpp ChessGame/Piece.cpp ChessGame/Pawn.cpp ChessGame/King.cpp ChessGame/Queen.cpp \
    ChessGame/Rook.cpp ChessGame/Bishop.cpp ChessGame/Knight.cpp -o board_tests
./board_tests
```

## Known issues

- `Board::isMate` only approximates checkmate detection (for example, the diagonal block check uses the wrong column), so some mates may be missed or reported incorrectly.
- Castling does not report check or checkmate to the frontend, and does not verify that the king is not in check or does not pass through an attacked square.
