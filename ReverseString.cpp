#include <iostream>
#include <string>
#include <chrono>
#include <math.h>
using namespace std;

void first_method(string &words) {

    string rewords(words);

    reverse(rewords.begin(), rewords.end());
    cout << words << '\n' << rewords << '\n';

}

void second_method(string &words) {

    string rewords(words);
    int l = words.size();
    int lastindex=words.size()-1;

    for (std::string::size_type i = 0; i < floor(l*0.5); i++) {
        std::swap(rewords[i], rewords[lastindex-i]);

    }

    cout << words << '\n' << rewords << '\n';

}

void third_method(string &words) {

    cout << words << '\n';
    int l = words.size();
    int lastindex=words.size()-1;

    for (std::string::size_type i = 0; i < floor(l*0.5); i++) {
        char tmp = words[i];
        words[i] = words[lastindex-i];
        words[lastindex-i] = tmp;

    }
    cout << words << '\n';

}


int main(int argc, char **argv) {
    string words("day and night");

    auto start = std::chrono::high_resolution_clock::now();
    first_method(words);
    auto end = chrono::high_resolution_clock::now();
    auto int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "first_method() elapsed time is " << int_s.count() << " microseconds" << endl;

    start = std::chrono::high_resolution_clock::now();
    second_method(words);
    end = chrono::high_resolution_clock::now();
    int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "second_method() elapsed time is " << int_s.count() << " microseconds" << endl;

    start = std::chrono::high_resolution_clock::now();
    third_method(words);
    end = chrono::high_resolution_clock::now();
    int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "third_method() elapsed time is " << int_s.count() << " microseconds" << endl;

    return 0;
}
