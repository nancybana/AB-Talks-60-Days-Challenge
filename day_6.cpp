#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int N;
    cin >> N;

    ofstream file("output.txt");

    for (int i = 1; i <= N; i++) {
        if (i % 3 == 0 && i % 5 == 0)
            file << "FizzBuzz";
        else if (i % 3 == 0)
            file << "Fizz";
        else if (i % 5 == 0)
            file << "Buzz";
        else
            file << i;

        file << endl;
    }

    file.close();
    return 0;
}