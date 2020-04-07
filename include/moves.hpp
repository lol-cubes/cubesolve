/*=======================================
 moves.hpp:                     lol-cubes
 last modified:               Tue, Mar 31
 
 Classes pertaining to moves and move
 notation. (Uses WCA standards)
========================================*/


#include <string>
#include <vector>
#include <map>

using std::vector;

#ifndef MOVES_H
#define MOVES_H


// Index of row or col of 3x3 face vector that contains stickers that
// would change as a result of each move.
static std::map<char, vector<int> > move_coords = {
    { 'L', {0, 0, 0, 2, 0, 0} },
    { 'R', {2, 0, 2, 0, 0, 2} },
    { 'D', {0, 0, 0, 0, 0, 0} },
    { 'U', {2, 2, 0, 2, 2, 0} },
    { 'B', {0, 0, 2, 2, 2, 0} },
    { 'F', {0, 2, 0, 0, 0, 2} }
};
static std::map<char, int> move_axes = {
    { 'L', 1 },
    { 'R', 1 },
    { 'D', 0 },
    { 'U', 0 },
    { 'B', 2 },
    { 'F', 2 }
};
// What direction attribute a move object should have for each face
// being moved if move is not prime.
static std::map<char, std::string> move_directions = {
    { 'L', "CC" },
    { 'R', "C" },
    { 'D', "CC" },
    { 'U', "C" },
    { 'B', "CC" },
    { 'F', "C" }
};
// Which face is being rotated on each kind of move.
static std::map<char, int> move_faces = {
    { 'F', 0 },
    { 'L', 1 },
    { 'U', 2 },
    { 'B', 3 },
    { 'R', 4 },
    { 'd', 5 }
};


class Move {
    public:
    char first_char;
    // C or CC
    // Perspectives:
    // U or D -> from above
    // R or L -> from the right
    // F or B -> from the front
    int rotations;
    std::string direction;

    // Axes:
    // x (U and D) -> 0
    // y (R and L) -> 1
    // z (F and B) -> 2
    int axis;

    // Index of row or col of 3x3 face vector that
    // contains stickers that are changing for each face.
    vector<int> coords;

    std::string move;  // String representation.
    Move(std::string move_string);
};


class MoveString {
    vector<Move> moves;
    vector<std::string> comments;

    public:
    std::string create_reconstruction();
    void add_comment(int index);
    MoveString(vector<Move> moves_string);
};

#endif