#include <iostream>
#include <cstdlib>
#include <map>
using namespace std;

class Config
{
public:
    Config();
    Config(const int *);
    void Show();
    void ShuffleConfig();
    void assignHeuristic(const Config& target);
private:
    std::map<int, int> _puzzle;
    int _heuristic;
};

int main() {

    const int target[9] = {1, 2, 3, 8, 0, 4, 7, 6, 5};
    Config targetConfig(target);
    targetConfig.Show();

    return EXIT_SUCCESS;
}

Config::Config()
{
    for (int i = 0; i < 9; i++)
    {
        _puzzle.insert({i, 0});
    }
}

Config::Config(const int *array)
{
    for (int i = 0; i < 9; i++)
    {
        _puzzle.insert({i, array[i]});
    }
}

void Config::Show()
{
    int column = 0;
    for (const pair<int, int> &val : _puzzle)
    {
        switch (column)
        {
        case 0:
        case 1:
            cout << val.second << ' ';
            column++;
            break;
        case 2:
            cout << val.second << '\n';
            column = 0;
            break;
        }
    }
    return;
}
