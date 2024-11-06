# include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>

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


std :: ostream & operator << ( std :: ostream & out , ChessBoard & board ) {
    /* Enables the use of std :: cout << board
    * to print the board . May be used for debugging .
    */
    for ( auto i = 0u ; i < board.size () ; ++i ) {
        for ( auto j = 0u ; j < board.size() ; ++ j ) {
            out << board[ i ][ j ] << "";
        }
        out << "\n";
    }
    return out ;
}

bool square_valid ( const Square& s , const ChessBoard& board ) {
    unsigned n = board.size () ;
    return s.row < n and s.col < n ;
    // Since we are using unsigned for the squares , there is no need to check
    // whether values are >= 0.
}

const int knight_moves[8][2] = {
    {1, 2},
    {2, 1},
    {-1,2},
    {2, -1},
    {-2,1},
    {1, -2},
    {-1,-2},
    {-2,-1}
};

unsigned get_knight_path_length ( const Square& origin , const Square& dest ) {
    // Posição final é a posição inicial
    if (origin == dest) return 0;

    // Lista de Posições
    std::queue<std::pair<Square, unsigned int>> passos;

    // Criando o tabuleiro e marcando a posição inicial 
    ChessBoard visited;
    visited.mark(origin);

    // Primeira Posição da Fila
    std::pair<Square, int> inicio = {origin, 0};
    passos.push(inicio);

    while (!passos.empty()){
        Square posicao_atual = passos.front().first;
        unsigned int movimentos = passos.front().second;
        passos.pop();

        for (int i=0; i<8; ++i){
            int new_row = posicao_atual.row + knight_moves[i][0];
            int new_col = posicao_atual.col + knight_moves[i][1];
            Square proximo(new_row, new_col);

            if (visited.mark(proximo)){
                if (proximo == dest){
                    return movimentos+1;
                }
                passos.push({proximo, movimentos+1});
            }
        }
    }
    return 0;
}

int main ( void ){
// Used to map the squares as char to indices of the board
 std::unordered_map<char,unsigned> table = {
 { 'a' , 0} ,
 { 'b' , 1} ,
 { 'c' , 2} ,
 { 'd' , 3} ,
 { 'e' , 4} ,
 { 'f' , 5} ,
 { 'g' , 6} ,
 { 'h' , 7}
 };
 char icol , ocol ;
 unsigned irow , orow ;
 std :: cin >> icol >> irow ;
 std :: cin.ignore (1) ; // Skip the ’\ n ’ char at the input ;
 std :: cin >> ocol >> orow ;

 Square origin ( irow -1 , table [ icol ]) ;
 Square dest ( orow -1 , table [ ocol ]) ;

 unsigned nmoves = get_knight_path_length ( origin , dest ) ;
 std :: cout << "Movimentos: " << nmoves << "\n";
 return 0;
}