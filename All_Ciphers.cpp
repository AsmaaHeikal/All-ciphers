#include<iostream>
#include<map>
#include<string>
#include<sstream>
#include <algorithm>
#include <string>
#include<cstdlib>
#include<iomanip>
#include<ctype.h>
#include<cstring>

using namespace std;

// 0. Affine Cipher

// this function check if the c satisfy the condition (a*c)%26=1
bool check(int a ,  int c)
{
    if ((a * c) % 26==1)
    {
        return true;
    }
    return false;
}
void affine_cipher()
{
    int a;
    int b;
    int c;

    while (true) {
        string msg, new_msg;
        int opp;
        // to choose an option
        cout << "1-cipher\n2-decipher\n3-exit" << endl;
        cin >> opp;
        if (opp == 3) {
            break;
        }
        // to accept a several line message
        cout << "enter the message: ";
        cin.ignore();
        getline(cin, msg);
        //to transform the message into capital letters
        transform(msg.begin(), msg.end(), msg.begin(), ::toupper);

        if (opp == 1) {
            cout <<"enter a and b \n";
            cin >> a >> b;
            for (int i = 0; i < msg.length(); i++) {
                //to encrypt letters
                if(msg[i]<='Z'&& msg[i]>='A'){
                    char new_char = (char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
                    new_msg += new_char;
                    //to encrypt other characters
                } else {
                    new_msg += msg[i];
                }

            }
        }
        if (opp == 2) {
            check:
            cout <<"enter  a , b and c \n";
            cin >> a >> b >> c;
            // check if c satisfy the equation ((a*c)%26=1)
            if (check(a, c)) {
                for (int i = 0; i < msg.length(); i++) {
                    //to decrypt letters
                    if (msg[i] <= 'Z' && msg[i] >= 'A') {
                        char new_char = (char) (((c * ((msg[i] + 'A' - b)) % 26)) + 'A');
                        new_msg += new_char;
                        //to decrypt other characters
                    } else {
                        new_msg += msg[i];

                    }
                }

            }else{
                // to return it to the line containing check if the c doesn't satisfy the equation
                cout << "not a correct value for c \n";
                goto check;
            }
        }
        // print the encrypted or decrypted message
        cout << new_msg << endl;
    }
}


// 1. Caesar Cipher

void ceaser_cipher()
{
    while(true){
        int op,key;
        string msg,newMsg;
        // to choose an option
        cout<<"1-cipher\n2-decipher\n3-exit\n-->";
        cin >> op;
        if(op==3)
            break;
        //enter the number of shifts
        cout<<" enter shift value **positive value for shifting right, negative value for shifting left**:  ";
        cin >> key;
        // to accept a several line message
        cout<<"enter message : ";
        cin.ignore();
        getline(cin,msg);
        //to transform the message into capital letters
        transform(msg.begin(), msg.end(), msg.begin(), ::toupper);

        if(op==1){
            for(int i = 0;i<msg.length();i++){
                //to encrypt letters
                if(msg[i]<='Z'&& msg[i]>='A'){
                    char newC=(char)((msg[i]+ key));
                    if (newC >90){
                        newC-=26;
                    }
                    if (newC <65){
                        newC+=26;
                    }
                    newMsg += newC;
                    //to encrypt other characters
                }else{
                    newMsg +=msg[i];
                }
            }
        }else if(op==2){
            for(int i = 0;i<msg.length();i++){
                //to decrypt letters
                if(msg[i]<='Z'&& msg[i]>='A'){
                    char newC=(char)((msg[i]-key));
                    if (newC<65){
                        newC +=26;
                    }
                    if (newC >90){
                        newC-=26;
                    }
                    newMsg += newC;
                    //to decrypt other characters
                }else{
                    newMsg +=msg[i];
                }
            }
        }
        // print the encrypted or decrypted message
        cout<<newMsg<<endl;
    }
}


// 2. Atbash Cipher

void atbash_cipher()
{
    // strings of letters and its corresponding letters
    string alpha =   {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string alpha_2 = {"ZYXWVUTSRQPONMLKJIHGFEDCBA"};
    while(true){
        int op;
        string msg,newMsg;
        // to choose an option
        cout<<"1-cipher\n2-decipher\n3-exit\n-->";
        cin >> op;
        if(op==3)
            break;
        // to accept a several line message
        cout<<"enter message : ";
        cin.ignore();
        getline(cin,msg);
        //to transform the message into capital letters
        transform(msg.begin(), msg.end(), msg.begin(), ::toupper);

        if(op==1){
            for(int i = 0;i<msg.length();i++){
                // to encrypt letters
                if(msg[i]<='Z'&& msg[i]>='A'){
                    char newC= alpha_2[alpha.find(msg[i])];
                    newMsg += newC;
                    // to encrypt other characters
                }else{
                    newMsg +=msg[i];
                }
            }
        }else if(op==2){
            for(int i = 0;i<msg.length();i++){
                // to decrypt letters
                if(msg[i]<='Z'&& msg[i]>='A'){
                    char newC= alpha[alpha_2.find(msg[i])];
                    newMsg += newC;
                }else{
                    // to decrypt other characters
                    newMsg +=msg[i];
                }
            }
        }
        // to print the encrypted or decrypted message
        cout<<newMsg<<endl;
    }
}


// 3. Vignere Cipher

// This function generates the key in until it's length is
// equal to the length of message
string generateKey(string msg, string key)
{
    int x = msg.size();

    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == msg.size())
            break;
        key.push_back(key[i]);

    }
    return key;
}

void vingere_cipher()
{
    while (true) {
        string msg, key, new_msg;
        int opp;
        // to choose an option
        cout << "1-cipher\n2-decipher\n3-exit" << endl;
        cin >> opp;
        if (opp == 3) {
            break;
        }
        // to accept a several line message
        cout << "enter the message: ";
        cin.ignore();
        getline(cin, msg);
        cout << "enter the keyword: ";
        getline(cin, key);
        //to transform keyword and message into capital letters
        transform(msg.begin(), msg.end(), msg.begin(), ::toupper);
        transform(key.begin(), key.end(), key.begin(), ::toupper);
        // to repeat the key until its length equal the length of the message
        key = generateKey(msg, key);
        if (opp == 1) {
            for (int i = 0; i < msg.length(); i++) {
                //to encrypt letters
                if(msg[i]<='Z'&& msg[i]>='A'){
                    char new_char = (char) ((msg[i] + key[i]) % 26 + 65);
                    new_msg += new_char;
                } else {
                    //to encrypt other characters
                    new_msg += msg[i];
                }

            }
        }
        if (opp == 2) {
            for (int i = 0; i < msg.length(); i++) {
                if(msg[i]<='Z'&& msg[i]>='A'){
                    //to decrypt letters
                    char new_char = (char) ((msg[i] - key[i] + 26) % 26 + 65);
                    new_msg += new_char;
                } else {
                    //to decrypt other characters
                    new_msg += msg[i];

                }
            }

        }
        // print the encrypted or decrypted message
        cout << new_msg << endl;
    }
}


// 4. Baconian Cipher

void baconian_cipher()
{
    string word, code, choice;
    // creat dictionary for all alphapet binnary codes
    map<char , string> cipher {
        {'A', "aaaaa"},
        {'B', "aaaab"},
        {'C', "aaaba"},
        {'D', "aaabb"},
        {'E', "aabaa"},
        {'F', "aabab"},
        {'G', "aabba"},
        {'H', "aabbb"},
        {'I', "abaaa"},
        {'J', "abaab"},
        {'K', "ababa"},
        {'L', "ababb"},
        {'M', "abbaa"},
        {'N', "abbab"},
        {'O', "abbba"},
        {'P', "abbbb"},
        {'Q', "baaaa"},
        {'R', "baaab"},
        {'S', "baaba"},
        {'T', "baabb"},
        {'U', "babaa"},
        {'V', "babab"},
        {'W', "babba"},
        {'X', "babbb"},
        {'Y', "bbaaa"},
        {'Z', "bbaab"},
    };

    cout<<"Welcome user \n ";

    // creat while loop to ask user what to do
    while(choice != "3")
    {
        cout<<"\n\nWhat do you wanna do? \n1- Cipher a message \n2- Decipher a message \n3- End\n"<<endl;

        getline(cin, choice);

        // if the user chooses 1-cipher a message
        if (choice == "1")
        {
            // get the message with spaces
            cout<<"\nEnter your message: ";
            getline(cin,word);
            // loop on the message and replace each character with its binnary code and tha space with '\'
            cout<<"\nYour encrypted message is:\n";
            for (char letter: word)
            {
                if (isspace(letter))
                {
                    cout<<"\\";
                }
                letter = toupper(letter);
                cout<<cipher[letter]<<" ";
            }
            cout<<"\n---------------------------------------------";

        }
        // if user chooses 2-decipher a message
        else if (choice == "2")
        {
            istringstream scin("");
            string  taken;
            cout<<"\n\nEnter your encrypted message: ";
            getline(cin, code);
            // get the message in isstringstream library to take every string in the message as an input
            scin.str(code);
            scin >> taken;
            cout<<"\nThe message is: \n";
            // loop if isstingstream is not empty, loop and print the equavelnt of each binnary code
            while (scin)
            {
                for (char letter = 65; letter<91; letter++)
                {
                    if (cipher[letter]==taken)
                    {
                        cout<<letter;
                    }
                }
                scin>>taken;
            }
            cout<<"\n---------------------------------------------";

        }
        // if user chooses 3-end the programme , close it
        else if (choice == "3")
        {
            cout<< "\nThanks for using our programme";
            cout<<"\n---------------------------------------------";
        }
    }
}


// 5. Simple Substitution Cipher.

// create a function to check if keyword is unique or not
bool if_unique (string str)
{
    for (int i=0; i<str.length()-1; i++)
    {
        for (int j= i+1; j<str.length(); j++ )
        {
            if (str[i]==str[j])
            {
                return false;
            }
        }
    }
    return true;
}

void simple_substitution_cipher()
{
    //define 2 alphabet variables , 1st will change to be cipher source and 2nd will be used to know the real indeces
    string alpha1 = "abcdefghijklmnopqrstuvwxyz", alpha2 = "abcdefghijklmnopqrstuvwxyz";
    string choice, kword, message;
    int letter_index, index;

    cout<<"Welcome user \n";
    // do while loop to choose the mission till be 3 then end
    while(choice != "3")
    {
        cout<<"\n\nWhat do you wanna do? \n1- Cipher a message \n2- Decipher a message \n3- End\n"<<endl;

        getline(cin, choice);
        // if user chooses to encrypt a message
        if (choice == "1")
        {
            //define the encrypted message variable in this scope to be empty every loop
            string enc_message="";
            // take the keyword
            cout<<"\nEnter your keyword (5 keys): ";
            getline(cin, kword);
            // check length keyword is 5 or not
            while (kword.length()!=5)
            {
                cout<< "\nplz enter 5 keys: ";
                getline(cin, kword);
            }
            //call check unique function
            while (!if_unique(kword))
            {
                cout<< "\nplz enter unique keys: ";
                getline(cin, kword);
            }
            //remove the keyword from 1st alphabet V
            for (char i : kword)
            {
                alpha1.erase(remove(alpha1.begin(), alpha1.end(), i), alpha1.end());
            }
            //reassign alpha1 to be cipher table
            alpha1 = kword + alpha1;
            //take the message
            cout<<"\nEnter your message to encrypt: ";
            getline(cin, message);
            // get the index of each char in alpha2, and use it to know the encrypted char
            for (char i : message)
            {
                if (isalpha(i))
                {
                    letter_index = i - 97;
                    enc_message += alpha1[letter_index];
                }

                else if(isspace(i))
                {
                    enc_message+=" ";
                }
                    else
                {
                    enc_message += i;
                }
            }
            // print the encrypted message
            cout<<"\nyour encrypted message is: ";
            cout<< enc_message<<endl;

            cout<<"\n---------------------------------------------";
        }
        // if user chooses to decrypt a message
        else if (choice == "2")
        {
            //define the decrypted message variable in this scope to be empty every loop
            string dec_message="";
            // take the keyword
            cout<<"\nEnter your keyword (5 keys): ";
            getline(cin, kword);
            // check length keyword is 5 or not
            while (kword.length()!=5)
            {
                cout<< "\nplz enter 5 keys: ";
                getline(cin, kword);
            }
            //call check unique function
            while (!if_unique(kword))
            {
                cout<< "\nplz enter unique keys: ";
                getline(cin, kword);
            }
            //remove the keyword from 1st alphabet V
            for (char i : kword)
            {
                alpha1.erase(remove(alpha1.begin(), alpha1.end(), i), alpha1.end());
            }
            //reassign alpha1 to be cipher table
            alpha1 = kword + alpha1;
            //take the message
            cout<<"\nEnter your message to decrypt: ";
            getline(cin, message);
            // find the index of each char, and use it know the original char
            for (int i =0; i< message.length(); i++)
            {
                index = alpha1.find(message[i]);
                if (isalpha(message[i]))
                {
                    dec_message += alpha2[index];
                }
                else if (isspace(message[i]))
                {
                    dec_message +=" ";
                }
                else
                {
                    dec_message += message[i];
                }
            }
            // print the original message
            cout<<"\nyour original message is: ";
            cout<< dec_message<<endl;

            cout<<"\n---------------------------------------------";

        //if user chooses to end
        }
        else if (choice == "3")
        {
            cout<< "\nThanks for using our programme";
            cout<<"\n---------------------------------------------";
        }
    }
}


// 6. Polybius Square Cipher

void ploybius_square_cipher()
{
    char alpha_arr[5][5];
    int row_arr[5], col_arr[5], n1, n2;
    string choice, cipher_code, message1, message2;
    int index, counter =0;

    cout<<"Welcome user \n";

    while (choice != "3")
    {

        cout<<"\nWhat do you wanna do? \n\n1- Cipher a message \n2- Decipher a message \n3- End\n"<<endl;
        getline(cin, choice);

        //if user wants to encrypt a meesage
        if (choice == "1")
        {

            // take the cipher code from the user
            cout<< "\nenter your cipher code: ";
            getline(cin, cipher_code);
            for(char dig :cipher_code )
            {
                index = dig - '0';
                row_arr[counter] = index;
                col_arr[counter] = index;
                counter++;

            }

            // build his cipher table
            map <char , int>cipher
            {

                {'a', ((row_arr[0])*10)+(col_arr[0])},
                {'b', ((row_arr[0])*10)+(col_arr[1])},
                {'c', ((row_arr[0])*10)+(col_arr[2])},
                {'d', ((row_arr[0])*10)+(col_arr[3])},
                {'e', ((row_arr[0])*10)+(col_arr[4])},
                {'f', ((row_arr[1])*10)+(col_arr[0])},
                {'g', ((row_arr[1])*10)+(col_arr[1])},
                {'h', ((row_arr[1])*10)+(col_arr[2])},
                {'i', ((row_arr[1])*10)+(col_arr[3])},
                {'k', ((row_arr[1])*10)+(col_arr[4])},
                {'l', ((row_arr[2])*10)+(col_arr[0])},
                {'m', ((row_arr[2])*10)+(col_arr[1])},
                {'n', ((row_arr[2])*10)+(col_arr[2])},
                {'o', ((row_arr[2])*10)+(col_arr[3])},
                {'p', ((row_arr[2])*10)+(col_arr[4])},
                {'q', ((row_arr[3])*10)+(col_arr[0])},
                {'r', ((row_arr[3])*10)+(col_arr[1])},
                {'s', ((row_arr[3])*10)+(col_arr[2])},
                {'t', ((row_arr[3])*10)+(col_arr[3])},
                {'u', ((row_arr[3])*10)+(col_arr[4])},
                {'v', ((row_arr[4])*10)+(col_arr[0])},
                {'w', ((row_arr[4])*10)+(col_arr[1])},
                {'x', ((row_arr[4])*10)+(col_arr[2])},
                {'y', ((row_arr[4])*10)+(col_arr[3])},
                {'z', ((row_arr[4])*10)+(col_arr[4])},

            };


            // take the message
            cout<< "\nwrite the message to encrypt: ";
            getline(cin, message1);
            // replace each character with its index in the cipher table
            // print the encrypted message
            cout<< "\nyour encrypted message is: ";
            for (char letter : message1)
            {
                if (isspace(letter))
                {
                    cout<<" ";
                }
                else if (letter == 'j')
                {
                    cout<<cipher['i'];
                }
                else
                {
                    cout<<cipher[letter];
                }
            }
            cout<<"\n---------------------------------------------";

        }

        // if user wants to discrypt a message
        else if (choice == "2")
        {

            string discrypted_message_i = "", discrypted_message_j = "";
;
            // take the code from the user
            cout<< "\nenter your cipher code: ";
            getline(cin, cipher_code);
            for(char dig :cipher_code )
            {
                index = dig - '0';
                row_arr[counter] = index;
                col_arr[counter] = index;
                counter++;

            }
            // build cipher table
            alpha_arr[row_arr[0]-1][col_arr[0]-1] = 'a';
            alpha_arr[row_arr[0]-1][col_arr[1]-1] = 'b';
            alpha_arr[row_arr[0]-1][col_arr[2]-1] = 'c';
            alpha_arr[row_arr[0]-1][col_arr[3]-1] = 'd';
            alpha_arr[row_arr[0]-1][col_arr[4]-1] = 'e';
            alpha_arr[row_arr[1]-1][col_arr[0]-1] = 'f';
            alpha_arr[row_arr[1]-1][col_arr[1]-1] = 'g';
            alpha_arr[row_arr[1]-1][col_arr[2]-1] = 'h';
            alpha_arr[row_arr[1]-1][col_arr[3]-1] = 'i';
            alpha_arr[row_arr[1]-1][col_arr[4]-1] = 'k';
            alpha_arr[row_arr[2]-1][col_arr[0]-1] = 'l';
            alpha_arr[row_arr[2]-1][col_arr[1]-1] = 'm';
            alpha_arr[row_arr[2]-1][col_arr[2]-1] = 'n';
            alpha_arr[row_arr[2]-1][col_arr[3]-1] = 'o';
            alpha_arr[row_arr[2]-1][col_arr[4]-1] = 'p';
            alpha_arr[row_arr[3]-1][col_arr[0]-1] = 'q';
            alpha_arr[row_arr[3]-1][col_arr[1]-1] = 'r';
            alpha_arr[row_arr[3]-1][col_arr[2]-1] = 's';
            alpha_arr[row_arr[3]-1][col_arr[3]-1] = 't';
            alpha_arr[row_arr[3]-1][col_arr[4]-1] = 'u';
            alpha_arr[row_arr[4]-1][col_arr[0]-1] = 'v';
            alpha_arr[row_arr[4]-1][col_arr[1]-1] = 'w';
            alpha_arr[row_arr[4]-1][col_arr[2]-1] = 'x';
            alpha_arr[row_arr[4]-1][col_arr[3]-1] = 'y';
            alpha_arr[row_arr[4]-1][col_arr[4]-1] = 'z';

            // take the encrypted message
            cout<<"\nEnter your encrypted message to discrypt:";
            getline(cin,message2);
            // print the real message
            // take each two digits and as row and column and print its letter
            cout<<"\nYour discrypted message is (with 'i'): ";

            for (int j= 0; j<message2.length(); j++)
            {
                if (isspace(message2[j]))
                {
                    discrypted_message_i += ' ';
                    j++;
                }

                n1 = message2[j] - '1';
                n2 = message2[j+1] - '1';
                discrypted_message_i += alpha_arr[n1][n2];
                j++;

            }
            cout<<discrypted_message_i<<"\n";

            cout<<"\nYour discrypted message is (with 'j'): ";

            for (int j= 0; j<message2.length(); j++)
            {
                if (isspace(message2[j]))
                {
                    discrypted_message_j += ' ';
                    j++;
                }

                n1 = message2[j] - '1';
                n2 = message2[j+1] - '1';
                if (alpha_arr[n1][n2]== 'i')
                {
                discrypted_message_j += 'j';
                j++;

                }
                else
                {
                discrypted_message_j += alpha_arr[n1][n2];
                j++;
                }


            }
            cout<<discrypted_message_j;

            cout<<"\n---------------------------------------------";


        }

        // if user chooses to end
        else if (choice == "3")
        {
            cout<< "\nThanks for using our programme";
            cout<<"\n---------------------------------------------";
        }
    }
}


// 7. Morse Code

void morse_code()
{
    //create a map for the Morse code of each character
    map<char,string>m{{'A',".-"},{'B',"-..."},{'C',"-.-."},{'D',"-.."},{'E',"."},{'F',"..-."},{'G',"--."},{'H',"...."},{'I',".."},{'J',".---"},{'K',"-.-"},{'L',".-.."},{'M',"--"},{'N',"-."},
    {'O',"---"},{'P',".--."},{'Q',"--.-"},{'R',".-."},{'S',"..."},{'T',"-"},{'U',"..-"},{'V',"...-"},{'W',".--"},{'X',"-..-"},{'Y',"-.--"},{'Z',"--.."},{'1',".----"},{'2',"..---"},{'3',"...--"},
    {'4',"....-"},{'5',"....."},{'6',"-...."},{'7',"--..."},{'8',"---.."},{'9',"----."},{'0',"-----"}};

    //creating input stream with name morse
    istringstream morse("");

    cout << "Hello!\n";
    while(true)
    {
        cout << "What do you like to do now?\n 1- Cipher a message\n 2- Decipher a message\n 3- End \n" << "Enter a number : ";
        int n;
        cin >> n;
        if (n==1)
        {
            //clear the terminal
            system("CLS");
            string s;
            cout << "English text : ";
            cin.ignore();
            getline(cin,s);
            cout << "Morse text : \n";
            //converting each character with its code in the map m
            for(int i=0;i< s.length();i++)
            {
                if(s[i]==' ')
                {
                    cout << "   ";
                }
                else
                {
                    s[i]=(char)toupper(s[i]);
                    cout << m[s[i]] << ' ';
                }
            }
            cout << "\n\n\n";
        }
        else if (n==2)
        {
            system("CLS");
            cin.ignore();
            cout << "Morse text : "<<endl;
            string mo;
            getline(cin,mo);
            morse.str(mo);
            string l;
            cout << "English text : ";
            //getting stream of inputs
            while(morse>>l)
            {
                //searching for the equivalent character in the map to the code
                for(int i=65; i<91;i++)
                {
                    if(m[char(i)]==l)
                    {
                        cout << char(tolower(char(i)));
                        break;
                    }
                }
            }
            cout << "\n\n\n";
        }
        else if (n==3)
        {
            break;
        }
        else
        {
            cout << "\n\nInvalid input . Please, try again\n\n"<< endl;
        }
    }
}


// 8. XOR Cipher

void xor_cipher()
{
    //the user will chose to cipher or decipher and the key
    cout << "what do you want to do now ?\n  1-cipher \n  2-decipher \n Enter a number : ";
    int n;
    cin >> n;
    cout << "Please, Enter a character as key : ";
    char key;
    cin >> key;
    if(n==1)
    {
        //we use the bitwise operator xor to encrypt the message
        cout << "enter message to encrypt : ";
        string s;
        cin.ignore();
        getline(cin,s);
        cout << "cipher message is : \n  1- In text : ";
        for(char letter : s)
        {
            cout << char((int)letter ^ (int)key);
        }
        cout << "\n  2- In Hexa : ";
        //printing the hexa of the ciphered message int 2 digits for each character
        for(char letter : s)
        {
            cout <<setw(2)<<setfill('0')<<hex<< ((int)letter ^ (int)key);
        }
    }
    else if(n==2)
    {
        //the user must chose if his message in hexa or text
        cout << "your message is in : \n  1- In Text \n  2- In Hexa \n enter a number : ";
        int x;
        cin >> x;
        if (x==1)
        {
            cout << "enter message in text to decrypt : ";
            string s;
            cin.ignore();
            getline(cin,s);
            cout << "The original message was : ";
            for(char letter : s)
            {
                //we use the bitwise operator xor to decrypt the message
                cout << char((int)letter ^ (int)key);
            }
        }
        else if(x==2)
        {
            cout << "enter message in Hexa to decrypt : ";
            string s;
            cin >> s;
            int arrLen=(s.length())/2;
            int arr[arrLen];
            int h=0;

            for(int i=0 ; i<s.length();i=i+2)
            {
                //we will store each two digits in array
                char *end;
                int k=2;
                char str[5]="0x";
                for(int j=0;j<2;j++)
                {
                    str[k]=s[i+j];
                    k++;
                }
                //this convert each two hex digits to its equivalent in decimal
                int num = strtol(str, &end, 16);
                arr[h]=num;
                h++;
            }
            cout << "The original message was : ";
            for(int i=0; i<arrLen ;i++)
            {
                //printing it as characters
                cout << (char)(arr[i]^(int)key);
            }
        }
    }
}


// 9. Rail-fence Cipher

void rail_fence_cipher()
{
     cout << "what do you want to do now ?\n  1-cipher \n  2-decipher \n Enter a number : ";
     int n;
     cin >> n;
     cout << "Our Fixed Key is 3"<< endl;
     cout << "Enter the message : ";
     string str;
     cin.ignore();
     //get the input as a line
     getline(cin,str);
     //remove all spaces from the input
     str.erase(remove(str.begin(), str.end(), ' '), str.end());
     int len =str.length();
     //convert each uppercase to lowercase
     for(int i=0;i<len;i++)
     {
         str[i]=tolower(str[i]);
     }
     int len1=0,len2=0,len3=0;
     //calculating the length of the character in first ,second and third line.
     if(len%4==1)
     {
         len1=(len/4)+1;
     }
     else
     {
         len1=len/4;
     }
     len2=len/2;
     len3=len-(len1+len2);

     if(n==1)
     {
         char arr1[len1];
         char arr2[len2];
         char arr3[len3];
         cout << "ciphered message is : ";
         int j=0;
         for(int i=0;i<len;i=i+4)
         {
             //this array will have the characters in first line
             arr1[j]=str[i];
             j++;
         }
         int k=0;
         for(int i=1;i<len;i=i+2)
         {
             //this array will have the characters in second line
             arr2[k]=str[i];
             k++;
         }
         int h=0;
         for(int i=2;i<len;i=i+4)
         {
             //this array will have the characters in third line
             arr3[h]=str[i];
             h++;
         }
         for(int i=0;i<len1;i++)
         {
             cout << arr1[i];
         }
         for(int i=0; i<len2;i++)
         {
             cout << arr2[i];
         }
         for(int i=0;i<len3;i++)
         {
             cout << arr3[i];
         }
     }
     else if(n==2)
     {
         char arr4[len1];
         char arr5[len2];
         char arr6[len3];
         cout << "the origin message was : ";
         //we will divide the string into 3 arrays each array have line of three lines
         for(int i=0;i<len1;i++)
         {
             arr4[i]=str[i];
         }
         int c=0;
         for(int k=len1;k<(len1+len2);k++)
         {
             arr5[c]=str[k];
             c++;
         }
         int c1=0;
         for(int j=(len1+len2);j<len;j++)
         {
             arr6[c1]=str[j];
             c1++;
         }
         int t=0,r=0,e=0;

         while(true)
         {
             //printing the arrays in this way will enable us to get the origin message
             if(t<len1)
             {
                 cout << arr4[t];
                 t++;
             }
             if((t+r+e)==len)
             {
                 break;
             }
             if(r<len2)
             {
                 cout << arr5[r];
                 r++;
             }
             if((t+r+e)==len)
             {
                 break;
             }
             if(e<len3)
             {
                 cout << arr6[e];
                 e++;
             }
             if((t+r+e)==len)
             {
                 break;
             }
             if(r<len2)
             {
                 cout << arr5[r];
                 r++;
             }
             if((t+r+e)==len)
             {
                 break;
             }
         }
     }
}


int main()
{
    cout << "Which Cipher Do You Want To Use It Now? \n 1- Affine Cipher \n 2- Caesar Cipher \n 3- Atbash Cipher \n 4- Vignere Cipher \n 5- Baconian Cipher \n 6- Simple Substitution Cipher \n 7- Polybius Square Cipher \n 8- Morse Code \n 9- XOR Cipher \n 10- Rail-fence Cipher \n ---> Enter a number : ";
    int q;
    cin >> q;
    if(q==1) affine_cipher();
    else if(q==2) ceaser_cipher();
    else if(q==3) atbash_cipher();
    else if(q==4) vingere_cipher();
    else if(q==5) baconian_cipher();
    else if(q==6) simple_substitution_cipher();
    else if(q==7) ploybius_square_cipher();
    else if(q==8) morse_code();
    else if(q==9) xor_cipher();
    else if(q==10) rail_fence_cipher();
    else cout << "Invalid Input, Please try again .";
    return 0;
}
