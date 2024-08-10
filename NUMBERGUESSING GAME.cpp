#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
    srand(time(0));  
    int number = rand() % 100 + 1, guess;
cout << "Guess the number between 1 and 100: ";
    do {
        cin >> guess;
        cout << (guess > number ? "Too high! " : guess < number ? "Too low! " : "Correct!") << endl;
    } while (guess != number);
 return 0;
}
