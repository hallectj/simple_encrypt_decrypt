/*Travis Halleck
  7/21/2015
  Encrypt & Decrypt Program
  Basic encryption and decryption program
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isFile(fstream &, string);
int filesize(const string &);
void encryptFunc(fstream &);
void decryptFunc(fstream &);

int main() {
    fstream afterSecret, beforeSecret;
    char answer;

    cout << "Would you like to begin the encrypting process or decryption process" <<endl;
    cout << "Type in 'E' for encryption and 'D' for decryption" <<endl;
    cin >> answer;

    while (  (answer != 'E') || (answer != 'D')  ) {
       if ((answer == 'E') || (answer == 'D')) {
           break;
       }
       cout << "Invalid entry, please type in a 'E' or a 'D'." <<endl;
       cin >> answer;
    }
       if (answer == 'E'){
          encryptFunc(beforeSecret);
       }else if(answer == 'D'){
          decryptFunc(afterSecret);
       }

    cout << endl;
    //system("pause");
    return 0;
}

//validate that a file exist or not
bool isFile(fstream &file, string name){
   file.open(name.c_str(), ios::in);
      if(file.fail()){
         return false;
      }else{
         return true;
      }
}

//get file size in terms of chars
int filesize(const string &file_name) {
    fstream file(file_name.c_str(), fstream::in | fstream::binary);
    file.seekg(0, ios::end);
    int length = file.tellg();
    return length;
}


void encryptFunc(fstream &file){
   int length = 0;
   fstream encryptFile;
   string filename;
   string encryptFileName;   // name given to the file that contains encrypted code

   cout << "What is the name of the file you want to encrypt" <<endl;
   cin >> filename;

   cout << endl;

   cout << "Before the encryption takes place, what will you name the new file that\nwill contain the encrypted code" <<endl;
   cin >> encryptFileName;


   //=================================================//

    if(isFile(file, filename)){
       cout << "File Processed Successfully\n\n";
       length = filesize(filename);

       char c[length];
       int asciiNums[length];      //each individual ascii nums
       char asciiCodes[length];    //each individual ascii code
       for(int i = 0; i<length; i++){
          if(file >> noskipws >> c[i]){
             asciiNums[i] =  c[i];
             asciiCodes[i] = asciiNums[i] + 10;
             //cout << c[i];
          }
      }


      encryptFile.open(encryptFileName.c_str(), ios::out | ios::binary);
      cout << "Encrypting file now. . ." <<endl;

      for(int i = 0; i<length; i++){
         encryptFile << asciiCodes[i];
      }

      cout << "Encryption is complete" <<endl;

      encryptFile.close();

    }else{
       cout << "ERROR in obtaining file, contact system administrator\n\n";
    }
}


void decryptFunc(fstream &file){
   int length = 0;
   fstream decryptFile;
   string filename;
   string decryptFileName;   // name given to the file that contains encrypted code

   cout << "What is the name of the file you want to decrypt" <<endl;
   cin >> filename;

   cout << endl;

   cout << "Before the decryption takes place, what will you name the new file that\nwill contain the decrypted text?" <<endl;
   cin >> decryptFileName;


   //=================================================//

    if(isFile(file, filename)){
       cout << "File Processed Successfully\n\n";
       length = filesize(filename);

       char c[length];
       int asciiNums[length];      //each individual ascii nums
       char asciiCodes[length];    //each individual ascii code
       for(int i = 0; i<length; i++){
          if(file >> noskipws >> c[i]){
             asciiNums[i] =  c[i];
             asciiCodes[i] = asciiNums[i] - 10;
             //cout << c[i];
          }
      }

      decryptFile.open(decryptFileName.c_str(), ios::out | ios::binary);
      cout << "Decrypting file now. . ." <<endl;

      for(int i = 0; i<length; i++){
         decryptFile << asciiCodes[i];
      }

      cout << "Decryption is complete" <<endl;

      decryptFile.close();

    }else{
       cout << "ERROR in obtaining file, contact system administrator\n\n";
    }
}
