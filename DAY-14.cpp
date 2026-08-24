#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string names[] = {"Alice", "Bob", "Charlie", "David", "Emma"};
    int marks[] = {85, 72, 91, 68, 78};

    int n = 5;
    int total = 0;
    int highest = marks[0];
    string topper = names[0];

    unordered_map<string, int> gradeCount;

    for (int i = 0; i < n; i++) {
        total += marks[i];

        if (marks[i] > highest) {
            highest = marks[i];
            topper = names[i];
        }

        if (marks[i] >= 90)
            gradeCount["A"]++;
        else if (marks[i] >= 75)
            gradeCount["B"]++;
        else
            gradeCount["C"]++;
    }

    double average = (double)total / n;

    cout << "Average Marks: " << average << endl;
    cout << "Topper: " << topper << " (" << highest << ")" << endl;

    cout << "\nGrade Distribution:\n";
    for (auto x : gradeCount) {
        cout << x.first << " : " << x.second << endl;
    }

    return 0;
}