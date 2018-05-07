#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include "static_arrays.h"


using namespace std;
/* https://github.com/Fizban/COMP3260_Assignment_2/commits/master
 * 1.Fileread/Write
 * 2.Parser
 * 3.E-Table
 * 4.XOR
 * 5.S-Box
 * 6.Permutate
 * 7.Avalanche Analysis
 *
 *
 * Initial Permutation:

            58    50   42    34    26   18    10    2
            60    52   44    36    28   20    12    4
            62    54   46    38    30   22    14    6
            64    56   48    40    32   24    16    8
            57    49   41    33    25   17     9    1
            59    51   43    35    27   19    11    3
            61    53   45    37    29   21    13    5
            63    55   47    39    31   23    15    7
 *
 *
 *
 * Inverse Permutation:
 *
 *                              IP-1

            40     8   48    16    56   24    64   32
            39     7   47    15    55   23    63   31
            38     6   46    14    54   22    62   30
            37     5   45    13    53   21    61   29
            36     4   44    12    52   20    60   28
            35     3   43    11    51   19    59   27
            34     2   42    10    50   18    58   26
            33     1   41     9    49   17    57   25
 *
 *
 */

/* ==========================================================================================================
 * ----------------------------------------------------------------------------------------------------------
 * ----------------------------------------------FUNCTION DECLARATIONS---------------------------------------
 * ----------------------------------------------------------------------------------------------------------
 * ==========================================================================================================*/

/*-----------------------------------------------------------------------------------------------------------
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
 *
 *
 *
 */
vector<int> ReadFile(string line);

vector<int> GetLeftSplit(vector<int> target);
vector<int> GetRightSplit(vector<int> target);

vector<int> Permutatekey(vector<int> target,vector<int> permutatemap);
vector<int> swapvectors(vector<int> V1,vector<int> V2);
vector<int> XOR(vector<int> Plaintext,vector<int> Key);

vector<int> RoundFunction(vector<int> Plaintext,vector<int> Key);

void PrintArray(vector<int> target);

vector<int> LeftShift(vector<int> target,int Shiftcount);

vector<int> ConcatenateVectors(vector<int> firsthalf,vector<int> secondhalf);

vector<int> Sbox(vector<int> target);

vector<int> slice(const vector<int>& v, int start, int end);
int binary_to_int(vector<int> input);
vector<int> int_to_binary(int number);

/* ==========================================================================================================
 * ----------------------------------------------------------------------------------------------------------
 * ----------------------------------------------MAIN BODY OF PROGRAM---------------------------------------
 * ----------------------------------------------------------------------------------------------------------
 * ==========================================================================================================*/



int main() {
    string yesno="z";
    vector<int> Key;
    vector<int> plaintext;
    string Temp,filename;


    cout<<"Please enter the file name you wish to read from(default 'input'):";
    cin >> filename;

    ifstream input(filename+".txt");
    if (input.is_open())
    {
        getline(input,Temp);
        plaintext = ReadFile(Temp);
        getline(input,Temp);
        Key = ReadFile(Temp);


       input.close();
    }
    else
    {
        cout << "unable to openfile";
    }

    cout<<"Inital Key:"<<endl;
    PrintArray(Key);
    cout<<"Initial Message:"<<endl;
    PrintArray(plaintext);


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
    //Printing keys
    cout<<"Inital Key:"<<endl;
    PrintArray(Key);
    cout<<"Permutate Key;"<<endl;
    PrintArray(PermKey);

    //Split the permutated key into left and right halves
    vector<int> LeftPermKey = GetLeftSplit(PermKey);
    vector<int> RightPermKey = GetRightSplit(PermKey);
    cout<<"Left Half of permutated Key:"<<endl;
    PrintArray(LeftPermKey);
    cout<<"Right Half of permutated Key:"<<endl;
    PrintArray(RightPermKey);

    //Set an array for the shift counts
    //eg for 11010 shift of 1 will result in "10101" and shift of 2 will result in "01011"
    int shiftcount[16]={1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
    //Define vectors to hold these shifts
    vector<int> LeftPermKeyShift[16];
    vector<int> RightPermKeyShift[16];

    vector<int> Prepermutatedkeys[16];
    vector<int> FinalKeys[16];

    int shiftcounter=0;
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
        //Print out values for testing purposes
        cout<<"Shift#"<<i<<" forcount"<<shiftcount[i]<<": ";
        cout<<endl;
        cout<<"LeftKey:";
        PrintArray(LeftPermKeyShift[i]);
        cout<<"RightKey:";
        PrintArray(RightPermKeyShift[i]);
        //Concatenate the left and right halves before the are permutated and readly to XOR with plaintext
        Prepermutatedkeys[i]=ConcatenateVectors(LeftPermKeyShift[i],RightPermKeyShift[i]);
        //Print these values for testing.
        cout<<"Prepermutateded concatenation:";
        PrintArray(Prepermutatedkeys[i]);

        FinalKeys[i]=Permutatekey(Prepermutatedkeys[i],KeyPerm2);
    }


    cout<<"Final Keys"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int i=0;i<16;i++)
    {
        cout<<"Key["<<i<<"]:";
        PrintArray(FinalKeys[i]);

    }
    cout<<"--------------------------------------------------------"<<endl;
    //Initialising the Inital table to swap bits with the PlainText Bit-stream
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
    vector<int> Temppt;
    for(int j=0;j<16;j++)
    {
        cout<<"================================================================================"<<endl;
        cout<<"==============================Round Funct #"<<j<<"===================================="<<endl;
        cout<<"================================================================================"<<endl;
        //Empties temppt incase of lingering values.
        Temppt.clear();
        //Pass the right half of plaintext and the 1st of the generated subkeys into round function.
        Temppt = RoundFunction(PlainR[j], FinalKeys[j]);
        //Swaps values of left Plaintext onto right plaintext
        PlainR[j+1] = XOR(PlainL[j],Temppt);
        //Swaps values of Rounded right plaintext onto left Plaintext.
        PlainL[j+1] = PlainR[j];
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
    vector<int> FinalPT =  Permutatekey(ConcatenateVectors(PlainR[16],PlainL[16]),InversePerm);

    cout<<"Permutated for Final Encypted String (Size "<< FinalPT.size()<< "bits):"<<endl;
    PrintArray(FinalPT);



    return 0;
}


/* ==========================================================================================================
 * ----------------------------------------------------------------------------------------------------------
 * ----------------------------------------------FUNCTION IMPLEMENTATIONS------------------------------------
 * ----------------------------------------------------------------------------------------------------------
 * ==========================================================================================================*/


vector<int> ReadFile(string line)
{
    int bit;
    string bithold;
    vector<int> Result;
    int bits = line.length();
    for(int i = 0;i<bits-1;i++)
    {
        bithold = line.substr(0,1);
        bit = stoi(bithold);
        Result.push_back(bit);
        line = line.substr(1);
    }
    return Result;
}

vector<int> GetLeftSplit(vector<int> target)
{
  //Initialize the array to be returned
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
    int a,b,c,d = 0;
    //Clear the vector because for some reason re-declaring it does not clear its previous values
    Result.clear();
    for(int i=0;i<permutatemap.size();i++)
    {
        a=target[i];
        b=permutatemap[i];
        c=target[permutatemap[i]];
        //Each iteration push the item from the permutation map to the vector
        Result.push_back(target[permutatemap[i]-1]);
        d=Result[i];
    }

    return Result;
}

vector<int> swapvectors(vector<int> V1,vector<int> V2)
{
    V2.clear();
    unsigned long size = V1.size();
    for(unsigned int i=0;i<size;i++)
    {
        V2.push_back(V1[i]);
    }

    return V2;

}

vector<int> XOR(vector<int> Plaintext,vector<int> Key)
{
    vector<int> Result;
    unsigned long size = Plaintext.size();
    for(unsigned int i=0;i<size;i++)
    {
        Result.push_back(Plaintext[i]^Key[i]);
    }

    return Result;


}

vector<int> RoundFunction(vector<int> Plaintext,vector<int> Key)
{

    cout<<endl<<"Pre Expanded right half of plaintext"<<endl;
    PrintArray(Plaintext);
    vector<int> Result;
    vector<int> expandedpt;
    vector<int> expandedXORpt;
    vector<int> expandedXORsubbedpt;
    Result.clear();
    expandedpt.clear();
    expandedXORpt.clear();
    expandedXORsubbedpt.clear();
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

    expandedpt = Permutatekey(Plaintext,ETable);
    cout<<endl<<"Post Expanded right half of plaintext"<<endl;
    PrintArray(expandedpt);
    expandedXORpt = XOR(expandedpt,Key);
    PrintArray(Key);
    cout<<endl<<"Post XORED right half of plaintext"<<endl;
    PrintArray(expandedXORpt);
    expandedXORsubbedpt = Sbox(expandedXORpt);
    cout<<endl<<"Post S-Boxed right half of plaintext"<<endl;
    PrintArray(expandedXORsubbedpt);
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
    Result=Permutatekey(expandedXORsubbedpt,postsubperm);
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