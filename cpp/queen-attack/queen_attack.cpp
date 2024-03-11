#include "queen_attack.h"

#include <stdexcept>
#include <stdlib.h> 

namespace queen_attack {
    chess_board::chess_board(){
        //default values
        whiteQueen = std::make_pair(0, 3);
        blackQueen = std::make_pair(7, 3);

        setupBoard();
    }

    chess_board::chess_board(std::pair<int, int> whiteQueen, std::pair<int, int> blackQueen){
        if(whiteQueen == blackQueen) throw std::domain_error("Queen positions must be distinct");
        
        this->whiteQueen = whiteQueen;
        this->blackQueen = blackQueen;

        setupBoard();
    }

    void chess_board::setupBoard(){
        int rows = sizeof(board)/sizeof(board[0]);
        int cols = sizeof(board[0])/sizeof(board[0][0]);
        for(int x=0; x<cols; x++){
            for(int y=0; y<rows; y++){
                if(x == whiteQueen.first && y == whiteQueen.second)
                    board[x][y] = square_type::WHITE_QUEEN;
                else if(x == blackQueen.first && y == blackQueen.second)
                    board[x][y] = square_type::BLACK_QUEEN;
                else
                    board[x][y] = square_type::EMPTY;
            }
        }
    }

    std::pair<int, int> chess_board::white() const{
        return whiteQueen;
    }

    std::pair<int, int> chess_board::black() const{
        return blackQueen;
    }

    bool chess_board::can_attack() const{
        //same column
        if(whiteQueen.first == blackQueen.first) return true;
        //same row
        if(whiteQueen.second == blackQueen.second) return true;
        //diagonal
        if(abs(whiteQueen.first-blackQueen.first) == abs(whiteQueen.second-blackQueen.second)) return true;
        
        return false;
    }

    chess_board::operator std::string() const{
        int rows = sizeof(board)/sizeof(board[0]);
        int cols = sizeof(board[0])/sizeof(board[0][0]);
        std::string boardAsString = "";
        for(int x=0; x<cols; x++){
            for(int y=0; y<rows; y++){
                std::string seperator = " ";
                if(y==rows-1) seperator = "\n";
                boardAsString += std::string() + static_cast<char>(board[x][y]) + seperator;
            }
        }
        return boardAsString;
    }
}  // namespace queen_attack
