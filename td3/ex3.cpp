#include <iostream>
#include <queue>
#include <stack>
#include <cctype>

using namespace std;

bool isPalindrome(const string& input) {
    for (size_t i = 0; i < input.length() / 2; i++) {
        if (input[i] != input[input.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << boolalpha;
    cout << "Is 'racecar' a plaindrome?"
         << isPalindrome("racecar") << endl;
    cout << "Is 'hello' a plaindrome?"
         << isPalindrome("hello") << endl;
    return 0;
}