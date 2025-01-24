#include <stdio.h>
#include <stdlib.h>

// This program prints the size of a specified file in bytes
int main(int argc, char** argv) {
    // Ensure that the user supplied exactly one command line argument
    if (argc != 2) { 
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file in binary mode
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Seek to the end of the file
    if (fseek(file, 0, SEEK_END) != 0) {
        perror("Error seeking to the end of the file");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Get the file size
    long file_size = ftell(file);
    if (file_size == -1L) {
        perror("Error determining file size");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Print the file size in bytes
    printf("File size: %ld bytes\n", file_size);

    // Close the file
    fclose(file);
    return EXIT_SUCCESS;
}
