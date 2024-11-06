#ifndef CHESS_H
#define CHESS_H

struct Square {
    unsigned row ;
    unsigned col ;

    Square ( unsigned r , unsigned c ) {
        row = r ;
        col = c ;
    }
    
    bool operator==(const Square& other) const{
        return row == other.row && col == other.col;
    }
};

class ChessBoard {
private :
    int board [8][8] = {
 {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,
 {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,
 {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,
 {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,
 {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,
 {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,
 {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0} ,
 {0 , 0 , 0 , 0 , 0 , 0 , 0 , 0}
    };
    unsigned int _sz = 8;

public:
    // Construtor
    ChessBoard(){
        fill(0);
    }

    // Size
    unsigned int size() const {
        return _sz ;
    }

    // Testa se a posição é possível
    bool square_valid(const Square& posi){
        unsigned n = size();
        return posi.col < n and posi.row < n;
    }

    bool mark(const Square& posi){
        bool valido = square_valid(posi);

        if (valido){
            if (board[posi.row][posi.col] == 0){
                // Marcando Valor
                board[posi.row][posi.col] = 1;
                return true;
            }
        }
        // Valor Marcado ou Inválido
        return false;
    }

    int* operator []( unsigned i ) {
        /* Enables the use of [] operator for ChessBoard objects */
        return board[i];
    }

    void fill ( int value ) {
        /* Fills all the board with a specific value */
        for ( unsigned i = 0; i < size () ; ++ i ) {
            for ( unsigned j = 0; j < size () ; ++ j ) {
                board[i][j] = value ;
            }
        }
    }
};

#endif