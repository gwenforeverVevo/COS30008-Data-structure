#include <iostream>
using namespace std;

int main (int argc, char* argv[])
{
    cout << "List of inputs throught command arguments:\n";
    for (int counter = 1; counter < argc; counter++)
    {
        cout << argv[counter] << endl;
    };

    return 0;
}