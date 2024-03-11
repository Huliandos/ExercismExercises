#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <utility>
#include <string>

namespace queen_attack {
    class chess_board{
private:
        enum square_type { WHITE_QUEEN = 'W', BLACK_QUEEN = 'B', EMPTY = '_'};
        square_type board[8][8];
        std::pair<int, int> whiteQueen;
        std::pair<int, int> blackQueen;

        void setupBoard();
public:

        chess_board();
        chess_board(std::pair<int, int>, std::pair<int, int>);
        std::pair<int, int> white() const;
        std::pair<int, int> black() const;
        bool can_attack() const;
        operator std::string() const;
    };
}  // namespace queen_attack

#endif // QUEEN_ATTACK_H