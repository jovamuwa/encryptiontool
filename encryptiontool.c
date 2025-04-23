#include <stdio.h>
#include <stdlib.h>

int file_exists(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}
void process_file(const char *input_filename, const char *output_filename, unsigned char key){
    if (!file_exists(input_filename)) {
        printf("Error: File '%s' not found!\n", input_filename);
        return;
    }
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");

    if (!input_file || !output_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch ^ key, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    printf("Process completed! Output file: %s\n", output_filename);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <mode> <input_file> <output_file> <key>\n", argv[0]);
        printf("Mode: -e for encrypt, -d for decrypt\n");
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *input_filename = argv[2];
    char *output_filename = argv[3];
    unsigned char key = (unsigned char) atoi(argv[4]);

    if (mode[0] == '-' && (mode[1] == 'e' || mode[1] == 'd')) {
        process_file(input_filename, output_filename, key);
    } else {
        printf("Invalid mode! Use -e to encrypt or -d to decrypt.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}