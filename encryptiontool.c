#include <stdio.h>
#include <stdlib.h>

#define KEY 0xAA  // Fixed encryption key

void process_file(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "rb");
    FILE *output_file = fopen(output_filename, "wb");

    if (!input_file || !output_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(input_file)) != EOF) {
        fputc(ch ^ KEY, output_file);
    }

    fclose(input_file);
    fclose(output_file);
    printf("Process completed! Output file: %s\n", output_filename);
}

int main() {
    char input_filename[100], output_filename[100];
    int choice;

    printf("1. Encrypt a file\n2. Decrypt a file\nEnter choice: ");
    scanf("%d", &choice);
    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    process_file(input_filename, output_filename);
    return 0;
}