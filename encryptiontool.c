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

int main() {
    char input_filename[100], output_filename[100];
    unsigned char key;  // Add this line
    int choice;

    printf("Enter encryption key (0-255): ");
    scanf("%hhu", &key);  // Add these two lines

    printf("1. Encrypt a file\n2. Decrypt a file\nEnter choice: ");
    scanf("%d", &choice);
    printf("Enter input file name: ");
    scanf("%s", input_filename);
    printf("Enter output file name: ");
    scanf("%s", output_filename);

    process_file(input_filename, output_filename, key); // Pass key here
    return 0;
}