/*
Created by: Connor Fricke (cd.fricke23@gmail.com)
Created on: 25-Jan-2024
Program starts with an unsolved puzzle, which looks like a 3x3 array
of tiles which are unsorted. Each of the tiles has a number 1-8 except
for one random space within the array that has a 'zero' or empty space.
Computer will attempt to rearrange tiles until they are ordered
according to the goal state:

  1 2 3
  8   4
  7 6 5

# matrix locations are according to the following map
[[00, 01, 02]]
[[10, 11, 12]]
[[20, 21, 22]]
*/

#include <iostream>
#include <vector>
#include <array>
#include <assert.h>

class Pair
{
private:
    int x, y;
public:
    Pair();
    Pair(const int, const int);
    void setValues(const int, const int);
    void setX(const int x) {this->x = x;}
    void setY(const int y) {this->y = y;}
    int getX() const {return x;}
    int getY() const {return y;}
    friend std::ostream& operator<<(std::ostream&, const Pair&);
};

class Tile
{
private:
    int value;
    Pair position;
public:
    Tile();
    Tile(const int row, const int col, const int value);
    int getValue() const;
    void setValue(const int);
    Pair getPosition() const;
    void setPosition(const int, const int);
    friend std::ostream& operator<<(std::ostream&, const Tile&);
};

class Matrix
{
private:
    const int numrows = 3;
    const int numcols = 3;
    Tile state[3][3];
public:
    Matrix();
    Tile at(const int, const int) const;
    void set(const Pair& position, const Tile&);
    friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

int main()
{
    // let's create nine tiles
    Tile zero(1, 1, 0);
    Tile one(0, 0, 1);
    Tile two(0, 1, 2);
    Tile three(0, 2, 3);
    Tile four(1, 2, 4);
    Tile five(2, 2, 5);
    Tile six(2, 1, 6);
    Tile seven(2, 0, 7);
    Tile eight(1, 0, 8);

    // and output them manually
    std::cout << one << two << three << std::endl
              << eight << zero << four << std::endl
              << seven << six << five << std::endl;

    return 0;
}

//
//  TILE CLASS IMPLEMENTATION
//
Tile::Tile()
{
    value = 0;
    position.setValues(0, 0);
}
Tile::Tile(const int row, const int col, const int value) 
{
    this->value = value;
    this->position.setValues(row, col);
}
int Tile::getValue() const
{
    return this->value;
}
void Tile::setValue(const int val)
{
    this->value = val;
}
Pair Tile::getPosition() const
{
    return position;
}
void Tile::setPosition(const int val1, const int val2)
{
    position.setValues(val1, val2);
}
std::ostream &operator<<(std::ostream& out, const Tile& tile)
{
    if (tile.getValue() == 0)
    {
        out << ": :";
        return out;
    }
    out << ":" << tile.getValue() << ":";
    return out;
}

//
//  PAIR CLASS IMPLEMENTATION
//
Pair::Pair()
{
    x = 0;
    y = 0;
}
Pair::Pair(const int val1, const int val2)
{
    x = val1;
    y = val2;
}
void Pair::setValues(const int val1, const int val2)
{
    x = val1;
    y = val2;
}
std::ostream& operator<<(std::ostream& out, const Pair& pair)
{
    out << "(" << pair.getX() << ", " << pair.getY() << ")";
    return out;
}

//
//  MATRIX CLASS IMPLEMENTATION
//
Matrix::Matrix()
{
    for (int i = 0; i < numrows; i++)
    {
        for (int j = 0; j < numcols; j++)
        {
            state[i][j].setValue(0);
            state[i][j].setPosition(i, j);
        }
    }
}
Tile Matrix::at(const int row, const int col) const
{
    assert(row < numrows and row > -1  and col < numcols and col > -1);

    return state[row][col];
}
void Matrix::set(const Pair &position, const Tile &)
{

}
std::ostream& operator<<(std::ostream &out, const Matrix &aMat)
{
    for (int i = 0; i < aMat.numrows; i++)
    {
        for (int j = 0; j < aMat.numcols; j++)
        {
            out << aMat.at(i, j);
        }
        out << std::endl;
    }
}