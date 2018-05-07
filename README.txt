COMP3260 ASSIGNMENT TWO - README.txt

Files included in this project:

	main.cpp
  README.txt

------------------------------------------------------------------------------------------------------

Students responsible:
Jack McKew - c3232675
Sebastian Webster -  c3175527

------------------------------------------------------------------------------------------------------

Main:
This class takes input from a file* using a command line parser** and uses the DES algorithm to either
encrypyt or decrypt plaintext/ciphertext and avalanche analysis in the window. The plaintext/ciphertext
is then outputted as text.

------------------------------------------------------------------------------------------------------
* The input file should be in the format:

	<64 bit Plaintext/Ciphertext>
	<56 bit Key>


** OutputFileEncryption.txt format

	<Encryption Header>
	<64 bit Plaintext>
    <56 bit Key>
    <64 bit Ciphertext>
    <Avalanche Header>
    <Avalanche Analysis> x 16 rounds for P and P_i under K
    <Avalanche Analysis> x 16 rounds for P and K under K_i

** OutputFileDecryption.txt format

	<Decryption Header>
	<64 bit Ciphertext>
    <56 bit Key>
    <64 bit Plaintext>


