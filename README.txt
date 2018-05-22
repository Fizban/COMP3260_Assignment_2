COMP3260 ASSIGNMENT TWO - README.txt

Files included in this project:

	Application.cpp
  README.txt
  static_arrays.h
  Makefile
  input.txt (used for testing)
  output.txt (used for testing)
  COMP3260_Assignment_2.exe
  cygwin dependency files
  ** A zip of the entire project in case of compatibility issues **

------------------------------------------------------------------------------------------------------

Students responsible:
Jack McKew - c3232675
Sebastian Webster -  c3175527

------------------------------------------------------------------------------------------------------

Application:
This class takes input from a file* using a command line parser** and uses the DES algorithm to either
encrypt or decrypt plaintext/ciphertext and avalanche analysis in the window. The plaintext/ciphertext
is then outputted as text.

Static_Arrays.h:
Contains Substitution box table since it cannot be altered

------------------------------------------------------------------------------------------------------
* The input file should be in the format:

    <Encryption / Decryption Header>
	<64 bit Plaintext/Ciphertext>
	<56 bit Key>


** OutputFileEncryption.txt format

	<64 bit Plaintext>
    <56 bit Key>
    <64 bit Ciphertext>
    <Avalanche Header>
    <Avalanche Analysis> x 16 rounds for P and P_i under K
    <Avalanche Analysis> x 16 rounds for P and K under K_i

** OutputFileDecryption.txt format

	<64 bit Ciphertext>
    <56 bit Key>
    <64 bit Plaintext>


