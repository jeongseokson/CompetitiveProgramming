/*
 * Basic string skills.
 *
 * Reference : http://www.comp.nus.edu.sg/~stevenha/myteaching/competitive_programming/ch6.zip
 */

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

int isvowel(char c) {
    char vowel[6] = "aeiou";
    for (int j = 0; vowel[j]; j++) {
        if (c == vowel[j])
            return 1;
    }
    return 0;
}

FILE *f;
char s[10010] = "", line[110];

void test_input() {
    f = fopen("string_input0.txt", "r");

    while (1) {
        fgets(line, 100, f);
        line[(int)strlen(line) - 2] = 0;
        if (strncmp(line, ".......", 7) == 0)
            break;

        strcat(s, line);
        strcat(s, " ");
    }

    assert(!strcmp(s, "I love CS3233 Competitiv Programming. i also lov AlGoRiTh "));
}

void test_find() {
    vector<int> occ;
    char *o = strstr(s, "lov");
    if (o == NULL) {
        printf("%d\n", -1);
    } else {
        do {
            occ.push_back((int)(o - s));
            o = strstr(o + 1, "lov");
        } while(o != NULL);
    }

    int ans[] = {2, 45};
    assert(equal(occ.begin(), occ.end(), ans));
}

void test_characters() {
    int digits = 0, vowels = 0, consonants = 0;
    for (int i = 0; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
        if (isdigit(s[i]))
            digits++;
        else if (isvowel(s[i]))
            vowels++;
        else if (isalpha(s[i]))
            consonants++;
    }
    assert(!strcmp(s, "i love cs3233 competitiv programming. i also lov algorith "));
    assert(digits == 4);
    assert(vowels == 17);
    assert(consonants == 27);
}

vector<string> tokens;
void test_tokenize() {
    char *token;
    tokens.push_back(strtok(s, " ."));
    while (token = strtok(NULL, " ."))
        tokens.push_back(token);

    const char *ans[] = {"i", "love", "cs3233", "competitiv", "programming", "i", "also", "lov", "algorith"};
    assert(equal(tokens.begin(), tokens.end(), ans));

    sort(tokens.begin(), tokens.end());
    assert(!strcmp(tokens[0].c_str(), "algorith"));
}

void test_string_map() {
    map<string, int> freq;
    for (int i = 0; i < tokens.size(); i++){
        freq[tokens[i]]++;
    }

    for (map<string, int>::iterator it = freq.begin(); it != freq.end(); it++) {
        printf("%s : %d\n", it->first.c_str(), it->second);
    }

    assert(freq["i"] == 2);
}

void test_character_input() {
    int chars = 0;
    char c;
    while (fscanf(f, "%c", &c) != EOF && c != '\n') {
        chars++;
    }

    assert(chars == 75);
}

int main() {
    // String input
    test_input();

    // Find string
    test_find(); 

    // Check characters
    test_characters();

    // Tokenizing
    test_tokenize();

    // String frequency
    test_string_map();

    // Character input
    test_character_input();

    return 0;
}
