#include <iostream>
#include <string>
#include <chrono>
#include <math.h>
#include <vector>
using namespace std;

void first_method(string &word) {

    string reword(word);

    reverse(reword.begin(), reword.end());
    cout << reword << ' ';

}

void second_method(string &word) {

    string reword(word);
    int l = word.size();
    int lastindex=word.size()-1;

    for (int i = 0; i < floor(l*0.5); i++) {
        std::swap(reword[i], reword[lastindex-i]);

    }

    cout << reword << ' ';
}

void third_method(string &word) {

    string reword(word);
    int l = word.size();
    int lastindex=word.size()-1;

    for (int i = 0; i < floor(l*0.5); i++) {
        char tmp = reword[i];
        reword[i] = reword[lastindex-i];
        reword[lastindex-i] = tmp;

    }
    cout << reword << ' ';

}


int main(int argc, char **argv) {

    string words("day and night");
    cout << words << '\n';

    vector<string> tokens;
    for (auto i = strtok(&words[0], " "); i != NULL; i = strtok(NULL, " "))
        tokens.push_back(i);

    //First method
    auto start = std::chrono::high_resolution_clock::now();
    for (vector<string>::iterator t=tokens.begin(); t!=tokens.end(); ++t) {
        first_method(*t);
    }
    auto end = chrono::high_resolution_clock::now();
    auto int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nfirst_method() elapsed time is " << int_s.count() << " microseconds" << endl;


    //Second method
    start = std::chrono::high_resolution_clock::now();
    for (vector<string>::iterator t=tokens.begin(); t!=tokens.end(); ++t) {
        second_method(*t);
    }
    end = chrono::high_resolution_clock::now();
    int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nsecond_method() elapsed time is " << int_s.count() << " microseconds" << endl;
    start = std::chrono::high_resolution_clock::now();

    //Third method
    start = std::chrono::high_resolution_clock::now();
    for (vector<string>::iterator t=tokens.begin(); t!=tokens.end(); ++t) {
        third_method(*t);
    }
    end = chrono::high_resolution_clock::now();
    int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "\nthird_method() elapsed time is " << int_s.count() << " microseconds" << endl;
    start = std::chrono::high_resolution_clock::now();


    return 0;
}
