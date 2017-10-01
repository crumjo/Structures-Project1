/*****************************************************************
 Output the contents of a text based file in reverse to a new file
 or choose to overwrite an existing one.
 
 @author Joshua Crum
 @version 9/27/17
 *****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "file_utils.h"

int main( int argc, char** argv )
{
    if (argv[1] == NULL) {
        fprintf(stderr, "\nPlease enter an input file.\n\n");
        return -1;
        
    } else if (argv[2] == NULL) {
        fprintf( stderr, "\nPlease enter an output file.\n\n");
        return -1;
        
    } else if (argv[3] != NULL) {
        fprintf( stderr, "\nPlease enter two files only, "
                "an input and an output.\n\n");
        return -1;
    }
    
    /** Char pointer to pass to file_read. */
    char *file_buffer = malloc(sizeof(char));
    if (file_buffer == NULL) {
        fprintf( stderr, "\nMemory allocation failed.\n" );
        return -1;
    }
    
    /** Number of elements in the file. */
    int size = read_file(argv[1], &file_buffer);
    backwards(file_buffer, size);
    write_file(argv[2], file_buffer, size);
    
    free(file_buffer);
    
    return 0;
}
