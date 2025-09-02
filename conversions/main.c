//
//  main.c
//  conversions
//
//  Created by Habiba Elkamary on 02/09/2025.
//

#include <stdio.h>
#include <math.h>

int convert_from_Hex (char* string, int index){
    // array for the letters
    int array[6];
    int n = 10;
    for (int i = 0 ; i<6; i++,n++) {
        array[i] = n ;
    }
    
    // The conversion
    int power = 0;
    int num = 0;
    for (int i = index - 1 ; i > 1 ; i--) {
        if (string[i] >= 48 && string[i] <= 57) {
            num += (string[i] - '0') * pow(16,power);
        }
        else{
            string[i] = string[i] < 97 ? string[i] = string[i] + 32 : string[i];
            num+= array[string[i] - 'a'] * pow(16,power);
        }
        
        power++;
    }
    
    printf("you decimal number is %d\n",num);
    return num;
}
int main(int argc, const char * argv[]) {
    char string[25];
    int index = 0;
    char c;
    printf("please enter your numerical Hex string\n");
    while (( c = getchar()) != '\n' && c != EOF) {
        string[index++] = c;
    }
    string[index] = '\0';
    convert_from_Hex(string, index);
    return 0;
}
