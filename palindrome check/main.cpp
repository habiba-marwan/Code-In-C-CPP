//
//  main.cpp
//  palindrome check
//
//  Created by Habiba Elkamary on 29/08/2025.
//

#include <iostream>
#include <string.h>
using namespace::std;

bool check_palindrome(string s){
    bool flag = true ;
    unsigned long x = s.length();
    for (unsigned long i = 0; i < x; i++) {
        if (s[i] != s[x-i-1]) {
            printf("not a palindrome");
            flag = false;
            break;
        }
    }
    
    if (flag) {
        printf("a palindrome!\n");
    }
    return flag;
}
int main(int argc, const char * argv[]) {
    string s;
    printf("please enter the palindrome string");
    cin >> s;
    
    
    return 0;
}
