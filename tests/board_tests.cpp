// Standalone tests for the chess engine logic (no graphics / Windows needed).
// Build & run from the repository root:
//   g++ -std=c++17 -IChessGame tests/board_tests.cpp ChessGame/Board.cpp ChessGame/Communicator.cpp \
//       ChessGame/Coord.cpp ChessGame/Piece.cpp ChessGame/Pawn.cpp ChessGame/King.cpp ChessGame/Queen.cpp \
//       ChessGame/Rook.cpp ChessGame/Bishop.cpp ChessGame/Knight.cpp -o board_tests && ./board_tests
#include "Communicator.h"
#include <iostream>
#include <string>

static int failures = 0;

static int play(Communicator& c, const std::string& move) {
	Coord* coords = c.getNewMove(move);
	int code = c.updateBoard(coords[0], coords[1]);
	delete[] coords;
	return code;
}

static void expect(Communicator& c, const std::string& move, int expected) {
	int actual = play(c, move);
	if (actual != expected) {
		std::cerr << "FAIL: " << move << " expected " << expected << " got " << actual << "\n";
		failures++;
	}
}

int main() {
	{   // opening moves and king-side castling
		Communicator c;
		for (const char* m : { "e2e4", "e7e5", "g1f3", "b8c6", "f1c4", "g8f6", "e1g1" }) expect(c, m, 0);
	}
	{   // fool's mate
		Communicator c;
		expect(c, "f2f3", 0); expect(c, "e7e5", 0); expect(c, "g2g4", 0);
		expect(c, "d8h4", 8);
	}
	{   // invalid moves return the protocol error codes
		Communicator c;
		expect(c, "e2e5", 6);  // illegal pawn move
		expect(c, "a1a3", 6);  // rook blocked by its own pawn
		expect(c, "e2e2", 7);  // source == destination
		expect(c, "e7e5", 2);  // not black's turn
		expect(c, "e1e2", 3);  // destination holds own piece
		expect(c, "z9z9", 5);  // out of bounds
	}
	{   // malformed input must not crash or read out of range
		Communicator c;
		expect(c, "", 5);
		expect(c, "e2", 5);
		expect(c, "e1b1", 3);  // king towards the queen-side knight: rook index must stay in range
	}

	if (failures == 0) std::cout << "All tests passed\n";
	return failures == 0 ? 0 : 1;
}
