XOR File Encryptor/Decryptor
This is a simple command-line tool written in C that performs XOR-based encryption and decryption on files.

Features
XOR encryption and decryption using a user-specified key i.e encryption key.

Processes binary files.

Minimal and portable (uses only standard C libraries).

How It Works
The program reads each byte from the input file, applies an XOR operation with the given key, and writes the result to the output file. This technique can be used for both encryption and decryption since XOR is its own inverse.

Parameters
<mode>:

-e for encryption

-d for decryption

<input_file>: Path to the input file to process.

<output_file>: Path where output will be written.

<key>: An integer key (0-255) used for XOR. This specifies the encryption key

**N/B:**__
This program uses a very simple form of encryption and should not be used for securing sensitive data.

The same key must be used for both encryption and decryption.

Output is binary-safe; it works for any type of file (text, image et al
