//NOTES:
//import the necessary libraries
#include <iostream>
#include <cmath>
using namespace std;

int const COLS = 3;
void print(int arr[][COLS], int rows);

//create a main function (which always returns an int)
int main(){
    // int x; //define an integer variable called x.
    // x = sqrt(3); //assign x to the value of the expression on the right.

    // pow(3, 5); // pow(x, n) is x to the power of n.
    // int arr[3][2]; // 3 rows and 2 cols
    // for (int rows = 0; rows < 3; rows++){
    //     for (int cols = 0; cols < 2; cols++){
    //         arr[rows][cols] = 0;
    //         cout << arr[rows][cols] << " ";
    //     }
    //     cout << endl; 
    // }

    const int COUNTRIES = 4; //rows
    const int METALS = 3; //columns
    int counts[COUNTRIES][METALS];
    print(counts, COUNTRIES);

    return 0; //Means no error
}

void print(int arr[][COLS], int rows){ 
    for (int row = 0; row < rows; row++){
        for(int col = 0; col < COLS; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}



/*

NOTES:
    
    WHICH LOOP TO USE:
    • If you know in advance how many times a loop is repeated, use a for loop. 
    • If the loop body must be executed at least once, use a do loop.
    • Otherwise, use a while loop.

        DO-WHILE STATEMENTS:
            Sometimes you want to execute the body of a loop at least once and perform the loop 
            test after the body is executed. The do loop serves that purpose:
            The body of the do loop is executed first, then the condition is tested.  
            SYNTAX:
                initialize a variable
                do {
                statements;
                } 
                while (condition); --> the ; ends the whole do-while statement.
            
            PURPOSE:
                While this condition is true, do the statements in the do part.

    MATH FUNCTIONS:
        Import <cmath>
            pow(x, n) --> x to the power of n
            sin(x) --> sine of x (x in radians)
            cos(x) --> cosine of x
            tan(x) --> tangent of x
            log(x) --> (natural log) ln(x), x > 0
            log10(x) --> (decimal log) log10(x), x > 0
            abs(x) --> absolute value |x| 
 
    LENGTH FUNCTION:
        int n = name.length(); 
        The length function only takes in strings as varibles.

    SUBSTRING FUNCTION:
        s.substr(start, length) --> will print a substring of s from index [start] until [start + length]
            Example:
                string greeting = "Hello, World!";
                string sub = greeting.substr(0, 5);
                    // sub is "Hello"

    SETPRECISION FUNCTION:
        Must use the library: #include <iomanip>
        The following command instructs cout to use two digits after the decimal point for all 
        floating-point numbers:
        cout << fixed << setprecision(2)

    RAND FUNCTION:
        The rand function is declared in the <cstdlib> header.
        Simply make call "srand(time(0));" once in your program, before generating any random numbers. 
        Then the random numbers will be different in every program run. Also include the 
        <ctime> header that declares the time function.
        If you get a compiler warning for the call to srand, use
        srand(static_cast<int>(time(nullptr))); instead


    INPUT VALIDATION:
    Check if the input is valid. Otherwise return an error and exit the function.
            if (cin.fail())
        { 
        cout << "Error: Not an integer." << endl;
        return 1;
        }


ARRAYS:
        int myData[10];
    creates an array called myData with 10 cells each storing integer values.
    The cells of the array are indexed from 0 through 9, and can be accessed by 
    specifying their index in square brackets, myData[i]. You can treat arrays as 
    tables whose elements can be accessed by their index.


----------------------------------------------------------------------------------------------
string greeting = "Hello, World!";
string myWord = greeting.substr(7); // starts at index 7 until the end


 */


 /*
Reading Input:
A] Console Input:

    cin = console input
    Use the extractor operator (>>).
    This reads any variable (int, string, float etc), but stops at the first space (tab, space, or enter key)
    To enter a full line (until the enter key), use: 
        getline(cin, string variable) //Store the console input to variable.

B] File Input:


    Alternate. If you want the computer to read data from a file.
    TSV = Tab Seperated Values

    ifstream = input file stream
    ifstream is a class. need to include <fstream> header (f is for file)
    fstream is data steaming from a file.

    create an iftream object: 
        ifstream objName("fileName.txt");



        if (fin.fail()){
        cerr << "error. "; // standard error message
        exit(1); // you can also return 1; but exit(1) is stronger. if will go to operating system not caller.
        }

how to read from a file:
    1. instantiate an ifstream object (stream = flows)
        ex:
        ifstream fin(filename)

    2. test whether fin can read data from filename of not
    file must be corrupted, no permissino to opnen, etc
        ex:
        if (fin.fail()){
        cerr << "error"; //
        exit(1); // 
        }

    3. read data from fin

    4. whatever cin can do, fin can do.

    5. when you finish, close the stream
        ex:
        fin.close();

string header; // column header
getline(fin, header); // the forst line will be ignored _________________


string name;
int test1;

int currentMin = INT_MAX;

//read the data:
while (fin >> name && fin >> test1){ // can also write (fin >> name >> test1)
    fin.ignore(INT_MAX, '\n'); // This will ignore the rest of the colums ____________________________________

} 

fin.close();

cout << whatever you want

------------------------------------------
FEB 19:

primitive type vs class:
    for p, use variables. tthey have only values.
    for c, use objects (called instances)   
        some operations on classes are A] accessors = they get the value and some are B] modifiers /
        mutators / sorters = they chaneg the value

a class is encapsulates data and operations on that data

some methods may or may not take in parameters


motivations = diff data has diff operations

methods are functions of a class. they are ALWAYS followed by parenthesis

escape sequences:
    \t = tab key
    \n = new line character
    \" = quotes literal

string concatenation:
    order matters (1+2 = 2+1 but NOT for strings )
    "string " + "string" = "string string" ****************include the warnign from GTP

ifstream is a class:

string is also a class:
    to know tyhe size of a string (# of characters):
        use strobject.length() OR strvariable.size()

finding at what index is a specific charatcter ***************************ask

declarinf and initializing a string:
    since strings are a very oppular class, you can use the assignment variavle = to delcare one
    but the proper way is :
    string str("the words you want");
        *can also do:
        string str2 = "strhuefb"

METHODS FOR STRING CLASS:
    str.find()
    str.length() // str.size()
    str.at()
    str[]
    str.substr()
    concatenate operatpr +



find out whether a target string exists*****************what?
    npos = no position //not found

************naming variables, camel etc



if (spInd == string::npos){
    cout << "no last name";
    return 0;
    }



FEB 24:
catch up on brightsspace (slides and videos)

/////////////////////////////////
Mar 19
POINTERS:


each variable has type, name, value, and address(memory location)
a pointer is a varibale that holds the adress of another variable

a pointer is a derived type, its associated with a defined or existing type
Type* = pointer to that type

    int age = 60; 
    int* pAge = &age; //pAge is a pointer. its value is the adress of age
                    //*pAge is the variable whose address is (the value of) pAge
    *pAge += 20; //* = dereference operator. only applies to pointers
    cout << age << endl;

dereference operTOR BEFORE a pointer:

Type& = reference parameter. passed the actucal copy of tge vafribale
&variable = address of variable


///////////////////////////////////////////////////////////////////
march 20:
pointers can refer to values that are allocated on demand (dynamic memory allocation)

array: 
    collectin of elements of the same type (occupy same amount of memory)
    they are put in consecutive memory locations

    advantages:
        constant time to access each element
            arr + i * size of each element is the calculation behinf the scneces
            of the adress of the ith element in the array

cout << arr == cout << &arr[0] are the same.

&arr[i] == (arr + i) //its the address of arr[i]

cant calculate the size of an array in a function definition, need to pass that value in the 
paramateres

*(arr + i) = arr[i] //value of the element at index i 

void print(int arr[], int size) == void print(int *arr, int size);



cant call the dereference operator on a nullpinter (nullptr is the only
time you can explicitly set a value to a pinter variable)

DYNAMICALLY ALOCATED MEMORY:
use new and delete opeators

STATICALLY ALLOCATED MEMORY:
---------------------------------------------------------------------------------------------------------

MARCH 24:

two-dimensional arrays:

static allocated 2d array - cant have diff rows have diff cols

const int COUNTRIES = 4; //rows
const int METALS = 3; //columns
int counts[COUNTRIES][METALS]; //this is a 2d array. [rows][cols]. must be const

//you can also initialize the values :
// int counts[COUNTRIES][METALS] =
// { {0, 3, 0}, 
//   {0, 0, 1}. 
//   {3, 2, 1},
//   {0, 2, 5}  };

int arr[3][2]; // 3 rows and 2 cols
for (int rows = 0; rows < 3; rows++){ //nested for loop to access the rows and cols
    for (int cols = 0; cols < 2; cols++){
        arr[rows][cols] = 0;
    } 
}

//write a function to print out all elements in a 2d array
//calculate row sum
//calculate col sum

const int COL = 4; 
//COLS must be given, and must be const. will only eork for 4 cols
void print(int arr[][COLS], int rows){ 
    for (int row = 0; row < rows; row++){
        for(int col = 0; col < COLS; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}

//each row of a 2d array is a 1d array

numRows = sizeof(arr) / sizeof(arr[0]);

0 0 0 
0 0 0 
0 0 0 
0 0 0 

12 total / 3 in the first row = 4 ROWS

==========================================
int colSum(arr[][current_col], )
    int col_sum = 0;
    for(int row = 0; row < rows; row++){
        col_sum+= arr[row][current_col];
    }
    return sum;


MARCH 26:

galton board (copy down code from my lecture slip)

MARCH 27:
setw(6) // set the width to be 6. part of standardllibrary in in <iomanip>
cout << setw(6) << counts[row][col];

<ctime>
srand(int NULL)


APRIL 2:


*/ 