#include <iostream>
#include <vector>
#include <map>

using namespace std;

void countFrequencyBruteForce (const vector<int>& numbers){
    for (size_t i = 0; i < numbers.size(); ++i) {
        bool alreadyCounted = false;
        for (size_t j = 0; j < i; ++j) {
            if (numbers[j] == numbers[i]) {
                alreadyCounted = true;
                break;
            }
        }

        if (!alreadyCounted) {
            int frequency = 0;
            for (int number : numbers) {
                if (number == numbers[i]) {
                    ++frequency;
                }
            }
            cout << numbers[i] << ":-" << frequency << "-times" << endl;
        }
    }
}

map<int,int> countFrequencyOptimal (const vector<int>& numbers){
        map<int, int> frequencyMap;
    for (int number : numbers) {
        ++frequencyMap[number];
    }
    return frequencyMap;
}

int main(){
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};
    cout<<"Frequency-(Brute-Force):"<<endl;
    countFrequencyBruteForce(numbers);
    cout<<"\nFrequency-(Optimal):"<<endl;
    map<int,int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry:frequencyMapOptimal){
        cout<<entry.first<<":-"<<entry.second<<"-times"<<endl;
    }
    return 0;
}