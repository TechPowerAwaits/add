/* Copyright 2020 Richard Johnston
   SPDX-license-identifier: 0BSD
   Add - Grabs Two Numbers and adds them together
*/

#include <stdio.h> // for input/output.
#include <ctype.h> // for Capitalize function.

/* The Program's Name */
int pname(); // define the pname function


int license(); // define the license function
int new_line(); // define the new_line function
int new_space(); // define the new_space function
char capitalize(char letter); // define the capitalize function
int cont(); // define the cont function


int ver(); // define the ver function

/* Version Definitions */
#define MAJOR_VER 1
#define MINOR_VER 0
#define PATCH_VER 0

/* ALPHA_VER should be increased when introducing new
new incomplete features. */
#define ALPHA_VER 0

/* BETA_VER should be increased when hunting and fixing major bugs,
as well as refractoring, feature complete but still pre-release code */
#define BETA_VER 0

/* RC_VER should be increased when only documentation or minor
bug fixes or refractoring are done. */
#define RC_VER 0


int main() {
pname(); // Print the name of the program.
new_space();
ver(); // Print the version number with program name.
new_line();
license();
    while (1 == 1) {
        double num1, num2, result;
        puts("Give me a number.");
        scanf("%lf", &num1);
        puts("Give me another number.");
        scanf("%lf", &num2);
        result = num1 + num2;
        puts("Thank You.");
        printf("Your result is: %lf\n", result);
        if ( !cont() ) { // is false
            break; // Break loop
        }
    }
return 0;
}

int cont() {
    while (1 == 1) {
        printf("\nDo you want to continue? ([Y]es or [N]o) ");
        char cont_var;
        getchar(); // Gets rid of whitespace
        cont_var = capitalize(getchar()); // The choice to continue.

/* capitalize function simplifies if statments so they only deal
with capital letters */

        if ( cont_var == 'Y' ) {
            new_line(); // Empty line.
            return 1; // Returns True.
        }
        else if (cont_var == 'N') {
            return 0; // Returns False.
        }
        else {
            puts("That is not valid.");
            // Loop the function again.

        }

    }
}

int pname() { // Prints program name
    printf("add"); // No new line.
    return 0;
}

int license() { // Prints license
    new_line();

    puts("Copyright 2020 Richard Johnston");
    new_line();
    puts("Permission to use, copy, modify, and/or distribute this software for any purpose");
    puts("with or without fee is hereby granted.");
    new_line();
    puts("THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH REGARD");
    puts("TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS.");
    puts("IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL");
    puts("DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN");
    puts("ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN");
    puts("CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.");
    new_line();
    return 0;
}

int ver() { // The Version API. Aims to be compliant with SemVer 2.0.0.
    printf("%d.%d.%d", MAJOR_VER, MINOR_VER, PATCH_VER); // Non pre-release version.
    
    /* if statements arranged to prevent multiple conflicting pre-release
    version information from being printed simultaneously. For example,
    if both ALPHA_VER and BETA_VER have a value of one or over, only
    ALPHA_VER will be printed. However, all version information should
    be looked over before publication. */
    
    if ( ALPHA_VER != 0 ) {
        printf("-alpha.%d", ALPHA_VER);
    }
    else if ( BETA_VER != 0 ) {
        printf("-beta.%d", BETA_VER);
    }
    else if ( RC_VER != 0 ) {
        printf("-rc.%d", RC_VER);
    }
    else {
    // Do nothing.
    }
    
    /* Build metadata currently is currently not used by this API.
    However, it will be added manually to the filename in all
    official binaries. ex. add-2.0.0-beta.1+i686.smusl-1.2.1
    which would be a beta binary statically linked with musl
    targeting i686 Linux.*/
return 0;
}

char capitalize(char letter) { /* Returns capital letters
                                Uses ctype.h */
    return toupper(letter);
}

int new_line() { // Forms new line
    puts("");
    return 0;
}

int new_space() { // Adds space
    printf(" ");
    return 0;
}
