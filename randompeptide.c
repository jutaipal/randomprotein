//
//  randompeptide.c
//  
//
//  Created by Jussi Taipale on 21/02/2023.
//

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// AMINO ACIDS WITH THEIR PROBABILITIES IN NATURE
char amino_acids[] = {'A', 'R', 'N', 'D', 'C', 'E', 'Q', 'G', 'H', 'I', 'L', 'K', 'M', 'F', 'P', 'S', 'T', 'W', 'Y', 'V'};
short int cut_offs[] = {74, 116, 160, 219, 252, 310, 347, 421, 450, 488, 564, 636, 654, 694, 744, 825, 887, 900, 933, 1001};

/* MAIN PROGRAM */

int main(int argc, const char * argv[]) {
    
    // long double t0 = time((void *)0);
    // long double t1;
    
    // variables
    short int length_of_peptide;
    short int random;
    short int i;
    
    // help if no parameter given
    if (argc < 2) {printf ("randompeptide prints out a random peptide, with amino-acid frequencies similar to those found in nature \nUsage: ./randompeptide [number of amino-acids]\n"); exit(1);}
    
    // string for peptide
    // char *tempstring;
    // tempstring = malloc(1000);
    // tempstring[0] = '\0';

    // Asks for length of peptide
    // printf("Length of peptide: ");
    // scanf("%hd", &length_of_peptide);

    // randomizes seed
    srand(time((void *) 0) + getpid());
    
    length_of_peptide = atoi(argv[1]);
    
    // prints out peptide
    for (; length_of_peptide > 0; length_of_peptide--)
    {
        random = (short int) (rand() % 1000 + 1);
        // printf("\n%hd", random);
        for (i = 0; random > cut_offs[i]; i++);
        printf("%c", amino_acids[i]);
    }

// free(tempstring);
printf("\n");
}
