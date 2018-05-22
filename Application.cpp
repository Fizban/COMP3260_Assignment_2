/*
Project Name: COMP 3260 Assignment 2
Date:22/5/18

Students responsible:
Jack McKew - c3232675
Sebastian Webster - c3175527
*/


#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "static_arrays.h"
using namespace std;
/* ==========================================================================================================
 * ----------------------------------------------------------------------------------------------------------
 * ----------------------------------------------FUNCTION DECLARATIONS---------------------------------------
 * ----------------------------------------------------------------------------------------------------------
 * ==========================================================================================================*/

/*-----------------------------------------------------------------------------------------------------------
 *
 * Name:ReadFile(string filename)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a filename as a string
 *
 * Exit Conditions:
 * Returns the data contained in the file
 *
 * Description:
 * Reads the file specified at filename location, parses the data and returns accordingly
 * ----------------------------------------------------------------------------------------------------------
 *
 * Name:writetofile(vector<int> Plaintext, vector<int> Key, vector<vector<vector<int>>> Final,vector<vector<vector<int>>> Finali, string filename,int mode)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs all information from each version of DES and a file name to write to
 *
 * Exit Conditions:
 * Returns complete and file should be located in current directory
 *
 * Description:
 * Parses completed decryption/encryption from DES process and undertakes an avalanche analysis and finally writes results to a file
 * ----------------------------------------------------------------------------------------------------------
 *
 * Name:StringtoBitStream(string line,int endofstream)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a line and a length for how much of the string is to be converted
 *
 * Exit Conditions:
 * Returns a vector filled with string contents
 *
 * Description:
 * Parses a string for a specific length of characters and fills vector with contents
 * ----------------------------------------------------------------------------------------------------------
 *
 * Name:StringtoBitStream(string line,int endofstream)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a line and a length for how much of the string is to be converted
 *
 * Exit Conditions:
 * Returns a vector filled with string contents
 *
 * Description:
 * Parses a string for a specific length of characters and fills vector with contents
 * ----------------------------------------------------------------------------------------------------------
 *
 * Name:GetLeftSplit(vector<int> target)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a target vector
 *
 * Exit Conditions:
 * Returns the 1st half of the target vector
 *
 * Description:
 * Takes the target vector and creates another vector that copies targets values up until targets max size
 * /2, effectively copying the 1st half of the vector
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:GetRightSplit(vector<int> target)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a target vector
 *
 * Exit Conditions:
 * Returns the 2nd half of the target vector
 *
 * Description:
 * Takes the target vector and creates another vector that copies targets values starting at vec.size/2 until
 * vec.size, taking the second half od the vector
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:Permutatekey(vector<int> target)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a target vector and a schema to permutate it off in the form of a vector
 *
 * Exit Conditions:
 * Returns the target vector permutated to the map
 *
 * Description:
 * Takes the target vector and switches all the bits around depending on the 'map'. For example for an input
 * of 1,1,1,0,1,1,0,1 using map 8,5,4,3,2,6,7,1 resulting permutation will be 1,1,0,1,1,1,0,1
 *    1,2,3,4,5,6,7,8                                                         1,2,3,4,5,6,7,8
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:Compare(vector<int> target, vector<int> target2)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs 2 target vectors to compare
 *
 * Exit Conditions:
 * Returns the number of differences
 *
 * Description:
 * Compares the vectors against one another and counts number of differences
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:XOR(vector<int> Plaintext, vector<int> Key)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a plaintext vector and key vector to xor
 *
 * Exit Conditions:
 * Returns the resulting vector from the XOR process
 *
 * Description:
 * Completes a XOR on two vectors and returns the resulting vector
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:RoundFunction(vector<int> Plaintext, vector<int> Key, int DES)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a plaintext vector, a key vector and the mode DES to be used
 *
 * Exit Conditions:
 * Returns the resulting vector from the round function of the DES type specified
 *
 * Description:
 * Completes a round function as specified in the Assignment spec for either DES0, DES1, DES2, DES3
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:PrintArray(vector<int> target)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a target vector
 *
 * Exit Conditions:
 * Prints the entire contents of an vector
 *
 * Description:
 * takes a vector and checks each value then prints it out in chronological order
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:LeftShift(vector<int> target, int Shiftcount)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a target vector and number of shifts to be made
 *
 * Exit Conditions:
 * Returns the vector with shifted values
 *
 * Description:
 * Shifts a vector's contents by the number of shiftcount to the left and returns
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:ConcatenateVectors(vector<int> firsthalf, vector<int> secondhalf)
 * ----------------------------------------------------------------------------------------------------------
 * Inital Conditions:
 * Needs a two vectors to join
 *
 * Exit Conditions:
 * Returns the vector of the two vectors joined together
 *
 * Description:
 * Takes in two vectors and joins them together
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:SBox(vector<int> target)
 * ----------------------------------------------------------------------------------------------------------
 * Initial Conditions:
 * Needs a target vector
 *
 * Exit Conditions:
 * Returns the target vector mapped to the substitution box table
 *
 * Description:
 * Takes a vector, extracts the row and column from the input and maps to a output in the substitution box table
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name:slice(const vector<int>& v, int start, int end);
 * ----------------------------------------------------------------------------------------------------------
 * Initial Conditions:
 * Needs a target vector, needs given start and end points
 *
 * Exit Conditions:
 * Returns the 'slice' of a vector given within start and end points
 *
 * Description:
 * Slices a vector within given start and end points
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name: binary_to_int(vector<int> target)
 * ----------------------------------------------------------------------------------------------------------
 * Initial Conditions:
 * Needs a target vector
 *
 * Exit Conditions:
 * Returns the target vector converted to an integer
 *
 * Description:
 * Takes a vector and converts the binary equivalent to an integer
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name: int_to_binary(int number)
 * ----------------------------------------------------------------------------------------------------------
 * Initial Conditions:
 * Needs a given integer
 *
 * Exit Conditions:
 * Returns the target vector converted to binary equivalent
 *
 * Description:
 * Takes a vector and converts the integer to a binary equivalent vector
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name: Keygen(vector<int> Key)
 * ----------------------------------------------------------------------------------------------------------
 * Initial Conditions:
 * Needs a given Key
 *
 * Exit Conditions:
 * Returns a set of keys generated for avalanche analysis
 *
 * Description:
 * Takes a given key and generates multiple keys to be used in avalanche analysis
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name: GenKiPi(vector<int> target)
 * ----------------------------------------------------------------------------------------------------------
 * Initial Conditions:
 * Needs a given target vector
 *
 * Exit Conditions:
 * Returns the target vector with an decryption/encryption leading bit
 *
 * Description:
 * Takes a target vector for determining the process to be used
 * ----------------------------------------------------------------------------------------------------------
 *
 * ----------------------------------------------------------------------------------------------------------
 * Name: outterroundfunc(vector<int> plaintext, vector<vector<int>> FinalKeys, int mode, int DES)
 * ----------------------------------------------------------------------------------------------------------
 * Initial Conditions:
 * Needs a given plaintext, FinalKey, mode and DES scheme
 *
 * Exit Conditions:
 * Returns the completed first or last round of DES decryption/encryption
 *
 * Description:
 * Completes either the first or last round of DES decryption/encryption
 * ----------------------------------------------------------------------------------------------------------
 *
 *
 *
 *
 */
vector<vector<int>> ReadFile(string filename);
void writetofile(vector<int> Plaintext,vector<int> Key,vector<vector<vector<int>>> Final,vector<vector<vector<int>>> Finali,string filename,int mode);
vector<int> StringtoBitStream(string line,int endofstream);
vector<int> GetLeftSplit(vector<int> target);
vector<int> GetRightSplit(vector<int> target);

vector<int> Permutatekey(vector<int> target,vector<int> permutatemap);

int Compare(vector<int> target,vector<int> target2);


vector<int> XOR(vector<int> Plaintext,vector<int> Key);

vector<int> RoundFunction(vector<int> Plaintext,vector<int> Key,int DES);

void PrintArray(vector<int> target);

vector<int> LeftShift(vector<int> target,int Shiftcount);

vector<int> ConcatenateVectors(vector<int> firsthalf,vector<int> secondhalf);

vector<int> Sbox(vector<int> target);

vector<int> slice(const vector<int>& v, int start, int end);
int binary_to_int(vector<int> input);
vector<int> int_to_binary(int number);

vector<vector<int>> Keygen(vector<int> Key);

vector<int> GenKiPi(vector<int> target);

vector<vector<int>> outerroundfunc(vector<int> plaintext,vector<vector<int>> FinalKeys,int mode,int DES);

/* ==========================================================================================================
 * ----------------------------------------------------------------------------------------------------------
 * ----------------------------------------------MAIN BODY OF PROGRAM---------------------------------------
 * ----------------------------------------------------------------------------------------------------------
 * ==========================================================================================================*/



int main() {
    // Request the input file from the user
    string filename;
    cout<<"Please enter the file name you wish to read from(default 'input'):";
    cin >> filename;

    // Parse the file data read from the file into vectors
    vector<vector<int>> filedata=ReadFile(filename);
    vector<int> plaintext = filedata[1];
    vector<int> plaintexti = GenKiPi(plaintext);
    vector<int> Key = filedata[2];
    vector<int> Keyi = GenKiPi(Key);

    // Generate keys to used in round functions
    cout<<"Key\n";
    PrintArray(Key);
    vector<vector<int>> FinalKeys = Keygen(Key);
    vector<vector<int>> FinalKeysi = Keygen(Keyi);

    // Fill first/final round of DES vector
    vector<vector<vector<int>>> FinalPT;
    vector<vector<vector<int>>> FinalPTi;
    for(int i=0;i<8;i++)
    {
        FinalPT.push_back(vector<vector<int>>());
        FinalPTi.push_back(vector<vector<int>>());
    }

    // Run first/final round of DES depending on DES scenario eg(DES0, DES1, DES2, DES3)
    FinalPT[0] =  outerroundfunc(plaintext,FinalKeys,filedata[0][0],0);
    FinalPTi[0] =  outerroundfunc(plaintexti,FinalKeys,filedata[0][0],0);
    FinalPT[1] =  outerroundfunc(plaintext,FinalKeys,filedata[0][0],1);
    FinalPTi[1] =  outerroundfunc(plaintexti,FinalKeys,filedata[0][0],1);
    FinalPT[2] =  outerroundfunc(plaintext,FinalKeys,filedata[0][0],2);
    FinalPTi[2] =  outerroundfunc(plaintexti,FinalKeys,filedata[0][0],2);
    FinalPT[3] =  outerroundfunc(plaintext,FinalKeys,filedata[0][0],3);
    FinalPTi[3] =  outerroundfunc(plaintexti,FinalKeys,filedata[0][0],3);

    FinalPT[4] =  outerroundfunc(plaintext,FinalKeys,filedata[0][0],0);
    FinalPTi[4] =  outerroundfunc(plaintext,FinalKeysi,filedata[0][0],0);
    FinalPT[5] =  outerroundfunc(plaintext,FinalKeys,filedata[0][0],1);
    FinalPTi[5] =  outerroundfunc(plaintext,FinalKeysi,filedata[0][0],1);
    FinalPT[6] =  outerroundfunc(plaintext,FinalKeys,filedata[0][0],2);
    FinalPTi[6] =  outerroundfunc(plaintext,FinalKeysi,filedata[0][0],2);
    FinalPT[7] =  outerroundfunc(plaintext,FinalKeys,filedata[0][0],3);
    FinalPTi[7] =  outerroundfunc(plaintext,FinalKeysi,filedata[0][0],3);


    //Print functions for debugging
    cout<<"Permutated for Final Encypted String (Size "<< FinalPT.size()<< "bits):"<<endl;
    PrintArray(FinalPT[0][16]);

    cout<<"Plaintext\n";
    PrintArray(plaintext);
    cout<<"Key\n";
    PrintArray(Key);
    cout<<"Different bits: "<<Compare(plaintext,Key);

    //Request user input for file to write output to
    string savefile;
    cout<<"Enter the filename to save under:"<<endl;
    cin>>savefile;

    writetofile(plaintext,Key,FinalPT,FinalPTi,savefile,filedata[0][0]);


    return 0;
}


/* ==========================================================================================================
 * ----------------------------------------------------------------------------------------------------------
 * ----------------------------------------------FUNCTION IMPLEMENTATIONS------------------------------------
 * ----------------------------------------------------------------------------------------------------------
 * ==========================================================================================================*/


vector<vector<int>> ReadFile(string filename)
{
    // Parse file data into vectors and return list of vectors
    string Temp;
    vector<vector<int>> filedata;
    vector<int> line1;
    ifstream input(filename+".txt");
    if (input.is_open())
    {
        filedata.emplace_back(vector<int>());
        getline(input,Temp);
        line1 = StringtoBitStream(Temp,1);
        filedata[0] = line1;
        getline(input,Temp);
        filedata.emplace_back(vector<int>());
        filedata[1] = StringtoBitStream(Temp,1);
        getline(input,Temp);
        filedata.emplace_back(vector<int>());
        filedata[2] = StringtoBitStream(Temp,0);
        input.close();
    }
    else
    {
        cout << "unable to openfile";
        return filedata;
    }
    return filedata;
}

void writetofile(vector<int> Plaintext,vector<int> Key,vector<vector<vector<int>>> Final,vector<vector<vector<int>>> Finali,string filename,int mode)
{
    // Write header to file
    unsigned long size = Plaintext.size();
    ofstream save;
    save.open (filename+".txt");

    if(mode == 0)
    {save << "Plaintext P:";}
    if(mode == 1)
    {save << "CipherText      :";}

    for(int i=0;i<size;i++)
    {
        save << Plaintext[i];
    }
    if(mode == 0)
    {save << "\nKey K      :";}
    if(mode == 1)
    {save << "\nKey K           :";}

    for(int i=0;i<size;i++)
    {
        save << Key[i];
    }
    if(mode == 0)
    {save << "\nCipher-text:";}
    if(mode == 1)
    {save << "\nDecyphered Text :";}

    for(int i=0;i<size;i++)
    {
        save << Final[0][16][i];
    }

    // If encryption, complete avalanche analysis and write results to file
    if(mode==0)
    {
        vector<vector<int>> Avalanche;
        for(int i=0;i<8;i++)
        {
            Avalanche.emplace_back(vector<int>());
        }


        for(int z=0;z<8;z++)
        {
            for (int j = 0; j < 16; j++)
            {
                Avalanche[z].push_back(Compare(Final[z][j], Finali[z][j]));
            }
        }


        save<<"\n=-----------------------=\n";
        save<<"|:  AVALANCHE ANALYSIS  :|";
        save<<"\n=-----------------------=\n";
        save<<"======================================================================\n";
        save<<"P and Pi under K\n";
        save<<"======================================================================\n";
        save<<"ROUND            DES0            DES1            DES2            DES3\n";
        for(int k=0;k<16;k++)
        {
            save <<k<<"                 "<<Avalanche[0][k]<<"             "<<Avalanche[1][k]<<"                "<<Avalanche[2][k]<<"               "<<Avalanche[3][k]<<"\n";
        }
        save<<"======================================================================\n";
        save<<"P under K and Ki\n";
        save<<"======================================================================\n";
        save<<"ROUND            DES0            DES1            DES2            DES3\n";
        for(int k=0;k<16;k++)
        {
            save <<k<<"                 "<<Avalanche[4][k]<<"             "<<Avalanche[5][k]<<"                "<<Avalanche[6][k]<<"               "<<Avalanche[7][k]<<"\n";
        }
        save<<"======================================================================\n";
    }


    save.close();
    return;

}

vector<int> StringtoBitStream(string line,int endofstream)
{
    // Take string character by character and fill vector with contents for specified length
    int bit;
    int count=0;
    string bithold;
    vector<int> Result;
    unsigned long bits = line.length();
    if(endofstream==1)
    {
        for(int i = 0;i<bits-endofstream;i++)
        {
            bithold = line.substr(0,1);
            bit = stoi(bithold);
            Result.push_back(bit);
            line = line.substr(1);
        }
    }
    if(endofstream==0)
    {
        for(int i = 0;i<bits-endofstream;i++)
        {
            bithold = line.substr(0,1);
            bit = stoi(bithold);
            if(bit==1)
            {
                count++;
            }
            Result.push_back(bit);
            if(i%7==0)
            {
                if((count%2)!=0)
                {
                    Result.push_back(0);
                }
                if((count%2)==0)
                {
                    Result.push_back(1);
                }
                count=0;
            }
            line = line.substr(1);
        }
    }

    return Result;
}

vector<int> GetLeftSplit(vector<int> target)
{
  // Split vector in half and take the left half
    unsigned int size = (target.size())/2;
  static vector<int> LeftVec;
  LeftVec.clear();
  for(unsigned int i=0;i<size;i++)
  {
      LeftVec.push_back(target[i]);
  }
  return LeftVec;

}

vector<int> GetRightSplit(vector<int> target)
{
    // Split vector in half and take the right half
    unsigned int size = target.size();
    static vector<int> RightVec;
    RightVec.clear();
    int j=0;
    for(unsigned int i=size/2;i<size;i++)
    {
        RightVec.push_back(target[i]);
        j++;
    }
    return RightVec;
}


void PrintArray(vector<int> target)
{
    // Function used for debugging by printing the entire contents of array
    unsigned int size = target.size();
    //Step through the array until specified "size" is reached
    for(unsigned int i=0;i<size;i++)
    {
        //Just using this if else to make output look neat. Adds comma to end of each element unless its the last element, where it will add new line.
        if(i!=target.size()-1)
        {
            if((i-3)%4==0 && i>0)
            {
            cout<<target[i]<<" ";
            }
            else
            {
            cout<<target[i];
            }
        }
        else
        {
            cout<<target[i]<<endl;
        }
    }


}


vector<int> Permutatekey(vector<int> target,vector<int> permutatemap)
{
    //Define the vector to store the permutation
    static vector<int> Result;
    //Clear the vector because for some reason re-declaring it does not clear its previous values
    Result.clear();
    for(int i=0;i<permutatemap.size();i++)
    {
        //Each iteration push the item from the permutation map to the vector
        Result.push_back(target[permutatemap[i]-1]);
    }

    return Result;
}

int Compare(vector<int> target,vector<int> target2)
{
    // Take two vectors and compare each element by one another and count the number of differences
    // Function mainly used for avalanche analysis
    int Result;
    unsigned int size = target.size();
    for(int i=0;i<size;i++)
    {
        if(target[i]!=target2[i])
        {
            Result++;
        }
    }
    return Result;
}

vector<int> XOR(vector<int> Plaintext,vector<int> Key)
{
    // Take the XOR of two vectors and return the resulting vector
    vector<int> Result;
    unsigned long size = Plaintext.size();
    for(unsigned int i=0;i<size;i++)
    {
        Result.push_back(Plaintext[i]^Key[i]);
    }

    return Result;


}

vector<int> RoundFunction(vector<int> Plaintext,vector<int> Key,int DES)
{
    // Static array declaration
    vector<int> postsubperm
            {
                    16,   7,  20,  21,
                    29,  12,  28,  17,
                    1 ,  15,  23,  26,
                    5 ,  18,  31,  10,
                    2 ,  8 ,  24,  14,
                    32,  27,   3,   9,
                    19,  13,  30,   6,
                    22,  11,   4,  25,
            };
    vector<int> InverseEtable
            {
                    2,  3,  4,  5,
                    8,  9,  10, 11,
                    14, 15, 16, 17,
                    20, 21, 22, 23,
                    26, 27, 28, 29,
                    32, 33, 34, 35,
                    38, 39, 40, 41,
                    44, 45, 46, 47,
            };


    cout<<endl<<"Pre Expanded right half of plaintext"<<endl;
    PrintArray(Plaintext);
    vector<int> Result;
    Result.clear();
    //Initalizing the E-Table to expand the right block of the plaintext.
    vector<int> ETable
            {
                    32,    1 ,   2 ,    3 ,    4 ,   5 ,
                    4 ,    5 ,   6 ,    7 ,    8 ,   9 ,
                    8 ,    9 ,   10,    11,    12,   13,
                    12,    13,   14,    15,    16,   17,
                    16,    17,   18,    19,    20,   21,
                    20,    21,   22,    23,    24,   25,
                    24,    25,   26,    27,    28,   29,
                    28,    29,   30,    31,    32,    1,
            };

    Result = Permutatekey(Plaintext,ETable);
    Result = XOR(Result,Key);
    // Complete round function depending on DES scenario selected (eg DES0, DES1, DES2, DES3)
    if(DES==0|DES==1)
    {
    Result = Sbox(Result);
    }

    if(DES==2|DES==3)
    {
        Result = Permutatekey(Result, InverseEtable);
    }

    if(DES==0|DES==2)
    {
        Result = Permutatekey(Result, postsubperm);
    }
    cout<<endl<<"Final Result of the round(size "<<Result.size()<<"):"<<endl;
    PrintArray(Result);

    return Result;
}


vector<int> LeftShift(vector<int> target,int Shiftcount)
{
    //using std::algrithms inbuilt function to left shift the vectors
    //rotate(start,middle,end) where
    //start defines the start of the area to be rotated(in this case we need the whole array).
    //middle defines what will become the new start (we have used start+shiftcount as in some cases we need the rotation to start at the second bit).
    //end much like start defines the end of the area to be rotated.
    rotate(target.begin(),target.begin()+Shiftcount,target.end());
    //return the rotated vector
    return target;
}

vector<int> ConcatenateVectors(vector<int> firsthalf,vector<int> secondhalf)
{
    // Function used for joining to vectors together into a single vector
    for(int i=0;i<secondhalf.size();i++)
    {
        firsthalf.push_back(secondhalf[i]);
    }

    return firsthalf;
}

vector<int> Sbox(vector<int> target)
{
    //Define the vector to store the substitution result
    vector<int> Result;

    //Loop for eight rounds of substitution
    for(int i = 0;i<8;i++)
    {
        cout<<"----------------ROUND "<<i<<" of S Box-----------------"<<endl;
        // Take only 6 bits of given input
        vector<int> test = slice(target,(i*6),((i+1)*6));
        cout << "\nBefore Sub :";
        PrintArray(test);

        //Extract row number from only first bit and last bit of input
        vector<int> row = {test.front(),test.back()};
        cout << "\nRow Binary :";
        PrintArray(row);

        //Convert binary to integer for interoperability
        int rownum = binary_to_int(row);
        cout << "\nRow Integer :";
        cout << rownum;

        //Extract column number from 'inner' four bits of input
        vector<int> col = slice(test,1,5);
        cout << "\nColumn Binary :";
        PrintArray(col);

        //Convert binary to integer for interoperability
        int colnum = binary_to_int(col);
        cout << "\nColumn Integer :";
        cout << colnum;


        // Determine substitute
        int found = sbox_array[i][rownum][colnum];
        cout<<"\nNumber found at r:"<<rownum<<" c:"<<colnum<<" Is ==";
        cout << found;

        //Convert integer to binary for interoperability
        vector<int> actual = int_to_binary(found);
        cout<<"\nBinary equivalent found at r:"<<rownum<<" c:"<<colnum<<" Is ==";
        PrintArray(actual);

        //Store result in vector to return
        unsigned int size = actual.size();
        for(int i=0;i<size;i++)
        {
            Result.push_back(actual[i]);
        }

        //Print and clean up
        cout<<"\nResult so far:\n";
        PrintArray(Result);
        actual.clear();
        test.clear();
        row.clear();
    }
    return Result;
}

vector<int> slice(const vector<int>& v, int start=0, int end=-1)
{
    //Initialise size for pre-sliced array
    int oldlen = v.size();
    int newlen;

    //Error catching for invalid inputs
    if (end == -1 or end >= oldlen)
    {
        newlen = oldlen-start;
    }
    else
    {
        newlen = end-start;
    }

    //Declare vector to be returned
    vector<int> nv(newlen);

    //Fill new vector with only values between given input points
    for (int i=0; i<newlen; i++)
    {
        nv[i] = v[start+i];
    }
    return nv;
}

int binary_to_int(vector<int> input)
{
    //Convert binary to integer and return results
    int result = 0;
    for (auto d : input)
    {
        result = result * 2 + d;
    }
    return result;
}

vector<int> int_to_binary(int number)
{
    //Convert integer to binary vector equivalent
    vector<int> binary;
    binary.clear();
    int i;
    //Iterate through multiples of 2 to determine binary equivalent
    while (number > 0)
    {
        binary.push_back(number%2);
        number /= 2;
        i++;
    }

    //Fill array with zeros if smaller than 4 bits
    if(binary.size()!=4)
    {
        unsigned int pushcount = 4-binary.size();
        for(i=0;i<pushcount;i++)
        {
            binary.push_back(0);
        }


    }
    reverse(binary.begin(),binary.end());
    return binary;
}

vector<vector<int>> Keygen(vector<int> Key)
{

    //Initializing the array for which Keys will be permutated
    vector<int> KeyPerm
            {
                    57,49,41,33,25,17,9 ,
                    1 ,58,50,42,34,26,18,
                    10,2 ,59,51,43,35,27,
                    19,11,3 ,60,52,44,36,
                    63,55,47,39,31,23,15,
                    7 ,62,54,46,38,30,22,
                    14,6 ,61,53,45,37,29,
                    21,13,5 ,28,20,12,4 ,
            };
    //Used in final key permutation
    vector<int> KeyPerm2
            {

                    14,17,11,24,1 ,5 ,
                    3,28,15,6 ,21,10,
                    23,19,12,4, 26, 8,
                    16,7 ,27,20,13, 2,
                    41,52,31,37,47,55,
                    30,40,51,45,33,48,
                    44,49,39,56,34,53,
                    46,42,50,36,29,32,
            };
    //Permutate the key using function
    vector<int> PermKey = Permutatekey(Key,KeyPerm);

    //Split the permutated key into left and right halves
    vector<int> LeftPermKey = GetLeftSplit(PermKey);
    vector<int> RightPermKey = GetRightSplit(PermKey);

    //Set an array for the shift counts
    //eg for 11010 shift of 1 will result in "10101" and shift of 2 will result in "01011"
    int shiftcount[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    //Define vectors to hold these shifts
    vector<int> LeftPermKeyShift[16];
    vector<int> RightPermKeyShift[16];
    vector<int> Prepermutatedkeys[16];

    vector<vector<int>> FinalKeys;
    //Loop 16 times to generate 32 subkeys in total 16 of each half of the permutated key.
    for(int i=0;i<16;i++)
    {
        //For the first round we need to use the values of "LeftKeyPerm" and "RightKeyPerm"
        if(i==0)
        {
            LeftPermKeyShift[i]=LeftShift(LeftPermKey,shiftcount[i]);
            RightPermKeyShift[i]=LeftShift(RightPermKey,shiftcount[i]);
        }
        //Once the 1st round has been completed we can use the previously shifted vector (PermKeyShift[i-1])
        //Each iteration checking shiftcount[i] to control the amount of shifts per round
        if(i>0)
        {
            LeftPermKeyShift[i]=LeftShift(LeftPermKeyShift[i-1],shiftcount[i]);
            RightPermKeyShift[i]=LeftShift(RightPermKeyShift[i-1],shiftcount[i]);
        }
        //Concatenate the left and right halves before the are permutated and readly to XOR with plaintext
        Prepermutatedkeys[i]=ConcatenateVectors(LeftPermKeyShift[i],RightPermKeyShift[i]);
        //Print these values for testing.
        FinalKeys.push_back(vector<int>());
        FinalKeys[i] = Permutatekey(Prepermutatedkeys[i],KeyPerm2);
    }
    return FinalKeys;

}



vector<int> GenKiPi(vector<int> target)
{
    if(target[0]==0)
    {
        target[0]=1;
    }
    else
    {
        target[0]=0;
    }
    return target;
}

vector<vector<int>> outerroundfunc(vector<int> plaintext,vector<vector<int>> FinalKeys, int mode,int DES)
{
    vector<int> InitalPerm =
            {
                    58,    50,   42,    34,    26,   18,    10,    2,
                    60,    52,   44,    36,    28,   20,    12,    4,
                    62,    54,   46,    38,    30,   22,    14,    6,
                    64,    56,   48,    40,    32,   24,    16,    8,
                    57,    49,   41,    33,    25,   17,     9,    1,
                    59,    51,   43,    35,    27,   19,    11,    3,
                    61,    53,   45,    37,    29,   21,    13,    5,
                    63,    55,   47,    39,    31,   23,    15,    7,
            };

    cout<<endl<<"Plaintext:"<<endl;
    PrintArray(plaintext);

    vector<int> PermutatedMessage = Permutatekey(plaintext,InitalPerm);
    cout<<endl<<"Permuted Plaintext:"<<endl;
    PrintArray(PermutatedMessage);

//Left and right splits on the plaintext
//Left takes the 1st 32 bits, and right the last 32.
    vector<int> PlainL[16];
    vector<int> PlainR[16];
    PlainL[0] = GetLeftSplit(PermutatedMessage);
    PlainR[0] = GetRightSplit(PermutatedMessage);
    cout<<endl<<"Left split of plaintext:"<<endl;
    PrintArray(PlainL[0]);
    cout<<"Right split of plaintext:"<<endl;
    PrintArray(PlainR[0]);
//Holds values for the left and right plaintext swap
    vector<vector<int>> Result;


    vector<int> Temppt;
    if(mode==0)
    {
        for(int j=0;j<16;j++)
        {
            cout<<"================================================================================"<<endl;
            cout<<"==============================Round Funct #"<<j<<"===================================="<<endl;
            cout<<"================================================================================"<<endl;
            Result.push_back(vector<int>());
    //Empties temppt incase of lingering values.
            Temppt.clear();
    //Pass the right half of plaintext and the 1st of the generated subkeys into round function.
            Temppt = RoundFunction(PlainR[j], FinalKeys[j],DES);
    //Swaps values of left Plaintext onto right plaintext
            PlainR[j+1] = XOR(PlainL[j],Temppt);
    //Swaps values of Rounded right plaintext onto left Plaintext.
            PlainL[j+1] = PlainR[j];
            Result[j]=ConcatenateVectors(PlainR[j],PlainL[j]);
        }
    }
    if(mode==1)
    {
        for(int j=0;j<16;j++)
        {
            cout<<"================================================================================"<<endl;
            cout<<"==============================Round Funct #"<<j<<"===================================="<<endl;
            cout<<"================================================================================"<<endl;
            Result.push_back(vector<int>());
            //Empties temppt incase of lingering values.
            Temppt.clear();
            //Pass the right half of plaintext and the 1st of the generated subkeys into round function.
            Temppt = RoundFunction(PlainR[j], FinalKeys[15-j],0);
            //Swaps values of left Plaintext onto right plaintext
            PlainR[j+1] = XOR(PlainL[j],Temppt);
            //Swaps values of Rounded right plaintext onto left Plaintext.
            PlainL[j+1] = PlainR[j];
            Result[j]=ConcatenateVectors(PlainR[j],PlainL[j]);

        }
    }

//Initialising the Final table to swap bits with the PlainText Bit-stream
    vector<int> InversePerm=
            {
                    40,     8,   48,    16,    56,   24,    64,   32,
                    39,     7,   47,    15,    55,   23,    63,   31,
                    38,     6,   46,    14,    54,   22,    62,   30,
                    37,     5,   45,    13,    53,   21,    61,   29,
                    36,     4,   44,    12,    52,   20,    60,   28,
                    35,     3,   43,    11,    51,   19,    59,   27,
                    34,     2,   42,    10,    50,   18,    58,   26,
                    33,     1,   41,     9,    49,   17,    57,   25,
            };
    cout<<"Final Left:"<<endl;
    PrintArray(PlainL[16]);
    cout<<"Final Right:"<<endl;
    PrintArray(PlainR[16]);
    cout<<"Concatenated:"<<endl;
    PrintArray(ConcatenateVectors(PlainR[16],PlainL[16]));
    Result.push_back(vector<int>());
    Result[16] = Permutatekey(ConcatenateVectors(PlainR[16],PlainL[16]),InversePerm);
    return Result;
}


//
//0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111