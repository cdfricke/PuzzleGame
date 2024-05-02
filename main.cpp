#include <iostream>
#include <cstdlib>
#include <map>
#include <random>
#include <cmath>
using namespace std;

// *** HELPER FUNCS ***
void show(const pair<int,int>& val) { cout << '(' << val.first << ',' << val.second << ')' << endl; }

// *** CLASSES ***
class Config
{
public:
    Config();
    Config(const int *);
    ~Config();
    friend ostream& operator<<(ostream&, const Config&);
    void Show() const;
    void Shuffle();
    int getHeuristic(const Config*);
    pair<int,int> Find(const int&) const;
private:
    int** _puzzle;
    int _heuristic;
    const int DIM = 3;
};

int main() {
    
    int target[9] = {
                    1, 2, 3,
                    8, 0, 4,
                    7, 6, 5
                    };
    Config* TARGET = new Config(target);
    cout << *TARGET << endl;

    Config* INITIAL_STATE = new Config;
    INITIAL_STATE->Shuffle();

    cout << *INITIAL_STATE << endl;
    cout << INITIAL_STATE->getHeuristic(TARGET) << endl;
    return EXIT_SUCCESS;
}

// initializes 2D array to zeros
Config::Config()
{
    _puzzle = new int*[DIM];
    for (int i = 0; i < DIM; i++)
    {
        _puzzle[i] = new int[DIM];
        for (int j = 0; j < DIM; j++)
        {
            _puzzle[i][j] = 0;
        }
    }
}

// converts 1D initializer array into 2D member array. Only works for 3x3
Config::Config(const int *array)
{
    _puzzle = new int *[DIM];
    for (int i = 0; i < DIM*DIM; i++)
    {
        _puzzle[i] = new int[DIM];
        if (i < 3) {_puzzle[0][i] = array[i];}
        else if (i < 6) {_puzzle[1][i-3] = array[i];}
        else {_puzzle[2][i-6] = array[i];}
    }
}

Config::~Config()
{
    for (int i = 0; i < DIM; i++)
        delete[] _puzzle[i];
    delete[] _puzzle;
}

// displays rows and columns
void Config::Show() const
{
    for (int row = 0; row < DIM; row++)
    {
        cout << _puzzle[row][0];
        for (int col = 1; col < DIM; col++)
        {
            cout << ' ' << _puzzle[row][col];
        }
        cout << '\n';
    }
    return;
}

void Config::Shuffle()
{
    // INIT
    for (int i = 0; i < DIM; i++)
        for (int j = 0; j < DIM; j++)
            _puzzle[i][j] = 0;
    int tilesToAssign[DIM*DIM - 1];
    for (int i = 0; i < DIM*DIM - 1; i++) {tilesToAssign[i] = i + 1;}
    // GENERATE RANDOM VALUES FOR ROW AND COL
    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, DIM-1);
    int candidateRow = distribution(generator);
    int candidateCol = distribution(generator);

    // POPULATE RANDOMLY
    for (const int val : tilesToAssign) {
        while (_puzzle[candidateRow][candidateCol] != 0)
        {
            candidateRow = distribution(generator);
            candidateCol = distribution(generator);
        }
        _puzzle[candidateRow][candidateCol] = val;
    }
}

// TODO: REWORK. Heuristic should be the sum of tile distances from the target locations.
int Config::getHeuristic(const Config* target) 
{
    int sumSeparations = 0;
    for (int row = 0; row < DIM; row++)
    {
        for (int col = 0; col < DIM; col++)
        {
            int value = _puzzle[row][col];
            pair<int, int> targetLoc = target->Find(value);
            int rowSep = abs(targetLoc.first - row);
            int colSep = abs(targetLoc.second - col);
            sumSeparations += rowSep + colSep;
        }
    }

    return _heuristic = sumSeparations;
}

pair<int,int> Config::Find(const int& val) const
{
    for (int row = 0; row < DIM; row++)
    {
        for (int col = 0; col < DIM; col++)
        {
            if (_puzzle[row][col] == val) return {row, col};
        }
    }
    return {-1, -1};
}

ostream& operator<<(ostream& out, const Config& val)
{
    for (int row = 0; row < val.DIM; row++)
    {
        out << val._puzzle[row][0];
        for (int col = 1; col < val.DIM; col++)
        {
            out << ' ' << val._puzzle[row][col];
        }
        out << '\n';
    }
    return out;
}