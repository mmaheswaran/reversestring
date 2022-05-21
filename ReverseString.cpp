#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <stack>
using namespace std;

void stdreverse(const string &word) {

    string reword(word);

    reverse(reword.begin(), reword.end());
    cout << reword << ' ';

}

void stdswap(const string &word) {

    string reword(word);
    int l = word.size();
    int lastindex=word.size()-1;

    for (int i = 0; i < l/2; i++) {
        std::swap(reword[i], reword[lastindex-i]);

    }

    cout << reword << ' ';
}

void manualswap(const string &word) {

    string reword(word);
    int l = word.size();
    int lastindex=word.size()-1;

    for (int i = 0; i < l/2; i++) {
        char tmp = reword[i];
        reword[i] = reword[lastindex-i];
        reword[lastindex-i] = tmp;

    }
    cout << reword << ' ';

}


void recursive_swap(string &word, int l, int h) {
    if (l < h) {
        swap(word[l], word[h]);
        recursive_swap(word, l + 1, h - 1);
    }
}

void stack_swap(string &word) {
    string reword(word);

    stack<char> s;
    for (int i = 0; i <word.length(); i++) {
        s.push(word[i]);
    }

    for (int i = 0; i < word.length(); i++) {
        reword[i] = s.top();
        s.pop();
    }
    cout << reword << ' ';
}


int main(int argc, char **argv) {

    string words("day and night");
    cout << words << '\n';

    vector<string> tokens;
    for (auto i = strtok(&words[0], " "); i != NULL; i = strtok(NULL, " "))
        tokens.push_back(i);

    //std::reverse method
    auto start = std::chrono::high_resolution_clock::now();
    for (vector<string>::iterator t=tokens.begin(); t!=tokens.end(); ++t) {
        stdreverse(*t);
    }
    auto end = chrono::high_resolution_clock::now();
    auto int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "stdreverse() elapsed time is " << int_s.count() << " microseconds" << endl;


    //std::swap method
    start = std::chrono::high_resolution_clock::now();
    for (vector<string>::iterator t=tokens.begin(); t!=tokens.end(); ++t) {
        stdswap(*t);
    }
    end = chrono::high_resolution_clock::now();
    int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "stdswap() elapsed time is " << int_s.count() << " microseconds" << endl;
    start = std::chrono::high_resolution_clock::now();

    //manual swap method
    start = std::chrono::high_resolution_clock::now();
    for (vector<string>::iterator t=tokens.begin(); t!=tokens.end(); ++t) {
        manualswap(*t);
    }
    end = chrono::high_resolution_clock::now();
    int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "manualswap() elapsed time is " << int_s.count() << " microseconds" << endl;
    start = std::chrono::high_resolution_clock::now();


    //recursive swap method
    start = std::chrono::high_resolution_clock::now();
    for (vector<string>::iterator t=tokens.begin(); t!=tokens.end(); ++t) {
        string w = *t;
        recursive_swap(w, 0, w.length() - 1);
        cout << w << " ";
    }
    end = chrono::high_resolution_clock::now();
    int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "recursive_swap() elapsed time is " << int_s.count() << " microseconds" << endl;

    //stack swap method
    start = std::chrono::high_resolution_clock::now();
    for (vector<string>::iterator t=tokens.begin(); t!=tokens.end(); ++t) {
        stack_swap(*t);
    }
    end = chrono::high_resolution_clock::now();
    int_s = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << "stack_swap() elapsed time is " << int_s.count() << " microseconds" << endl;

    return 0;
}
