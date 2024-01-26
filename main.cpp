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
*/

#include <iostream>
#include <vector>
#include <array>

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
    Tile(const int x, const int y, const int value);
    int getValue() const;
    void setValue(const int);
    Pair getPosition() const;
    void setPosition(const int, const int);
    friend std::ostream& operator<<(std::ostream&, const Tile&);
};

int main()
{
    Pair myPair(1,3);
    std::cout << myPair;
    myPair.setX(0);
    std::cout << myPair << std::endl;

    Tile myTile(0, 5, 10);
    std::cout << myTile;
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
Tile::Tile(const int x, const int y, const int value) 
{
    this->value = value;
    this->position.setValues(x, y);
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
    out << tile.getPosition() << " : " << tile.getValue();
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