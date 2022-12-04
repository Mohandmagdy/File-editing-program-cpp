#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <string.h>
#include<vector>
#include <algorithm>
#include<cmath>
#include<array>
#include<fstream>
#define ll long long

using namespace std;

string filename;

string append(string &filename){
   cout << "Please Enter The text you want to add: ";
   string text, original, line;
   getline(cin >> ws, text);
   ofstream myfile;
   myfile.open (filename, std::ios_base::app);
   myfile << " " << text;
   myfile.close();
   cout << "Done" << endl;
   return filename;
}

string filecontent(string &filename){
   char chr;
   fstream myfile;
   myfile.open(filename, fstream::in);
   cout << "\nContent of " << filename << " is:-\n";
   while(myfile>>noskipws>>chr)
      cout<<chr;
   myfile.close();
   cout<<endl;
   return filename;
}

string clear(string &filename){
   char chr;
   fstream myfile;
   myfile.open(filename, std::ofstream::out | std::ofstream::trunc);
   myfile.close();
   cout << "Done" << endl;
   return filename;
}

string encrypt(string &filename){
   string line, encrypted;
   fstream myfile;
   myfile.open(filename, fstream::in);
   while(getline(myfile, line))
      for (int i = 0; i < line.length(); i++){
         line[i] += 1;
         encrypted += line[i];
      }
   myfile.close();
   myfile.open(filename, std::ofstream::out | std::ofstream::trunc);
   myfile.close();
   myfile.open (filename, std::ios_base::app);
   myfile << encrypted;
   myfile.close();
   cout << "The file is encrypted" << endl;
   return filename;
}

string decrypt(string &filename){
   char chr;
   string line, encrypted;
   fstream myfile;
   myfile.open("example.txt", fstream::in);
   while(getline(myfile, line))
      for (int i = 0; i < line.length(); i++){
         line[i] -= 1;
         encrypted += line[i];
      }
   myfile.close();
   myfile.open(filename, std::ofstream::out | std::ofstream::trunc);
   myfile.close();
   myfile.open (filename, std::ios_base::app);
   myfile << encrypted;
   myfile.close();
   cout << "The file is decrypted" << endl;
   return filename;
}

string merge(string &filename){
   string line1, line2, original, addition, filename2;
   cout << "Please enter the second filename you want: ";
   getline(cin >> ws, filename2);
   fstream myfile, myfile2;
   myfile.open(filename, fstream::in);
   myfile2.open(filename2, fstream::in);
   if (!myfile2){
      cout << "Invalid File Name";
   }
   else{
      while(getline(myfile, line1))
         for (int i = 0; i < line1.length(); i++){
            original += line1[i];
         }
      while(getline(myfile2, line2))
         for (int i = 0; i < line2.length(); i++){
            addition += line2[i];
         }
      myfile.close();
      myfile.open(filename, std::ofstream::out | std::ofstream::trunc);
      myfile.close();
      myfile.open (filename, std::ios_base::app);
      myfile << original << " " << addition << endl;
      myfile.close();
   }
   cout << "Done" << endl;
   return filename;
}

string count_words(string &filename){
   string line;
   int sum = 0;
   fstream myfile;
   myfile.open(filename);
   while(getline(myfile, line))
      for (int i = 0; i < line.length(); i++){
            if (line[i] == ' '){
               sum++;
            }
      }
      cout << "The number of words is: " << ++sum << endl;
   return filename;
}

string count_char(string& filename){
   string line;int sum = 0;fstream myfile;
   myfile.open(filename);
   while(getline(myfile, line)){
      for (int i = 0; i < line.length(); i++){
         if (isalpha(line[i])){
            ++sum;
         }
      }
   }
   cout << "The number of characters is: " << sum << endl;
   return filename;
}

string count_lines(string& filename){
   string line;int sum = 0;
   fstream myfile;
   myfile.open(filename);
   while(getline(myfile, line)){
      ++sum;
   }
   cout << "The number of lines is: " << sum << endl;
   return filename;
}

string find_word(string& filename){
   string line, word, text, wordl;fstream myfile;bool found = false;
   cout << "Please enter the word you want to search for: ";cin >> word;
   for (int i = 0; i < word.length(); i++){
      wordl += tolower(word[i]);
   }
   myfile.open(filename);
   while(getline(myfile, line)){
      for (int i = 0; i < line.length(); i++){
         if (isalpha(line[i])){
            if(i == line.length()-1){ 
               text += tolower(line[i]);
               if (wordl.compare(text) == 0){
               found = true;
               break;
               }
            }
            else{
               text += tolower(line[i]);
            }        
         }
         else {
            
            if (wordl.compare(text) == 0){
               found = true;
               break;
            }
            else{
               text = "";
            }
         }
      }
      if (found) break;
   }
   if (found) {cout << "Word was found in the file." << endl;}
   else {cout << "Word was not found in the file." << endl;}
   return filename;
}

string count_found_word(string& filename){
   string line, word, text, wordl;fstream myfile;int sum = 0;
   cout << "Please enter the word you want to search for: ";cin >> word;
   for (int i = 0; i < word.length(); i++){
      wordl += tolower(word[i]);
   }
   myfile.open(filename);
   while(getline(myfile, line)){
      for (int i = 0; i < line.length(); i++){
         if (isalpha(line[i])){
            if(i == line.length()-1){
               text += tolower(line[i]);
               if (wordl.compare(text) == 0){
               ++sum;
               text = "";
               }
            }
            else{
               text += tolower(line[i]);
            }  
         }
         else if (!isalpha(line[i])) {
            if (wordl.compare(text) == 0){
               ++sum;
               text = "";
            }
            else{
               text = "";
            }
         }
      }
   }
   cout << "The word " << word << " was found " << sum << " time(s) in the file." << endl;
   return filename;
}

string upper(string& filename){
   string line, text;
   fstream myfile;
   myfile.open(filename, fstream::in);
   while(getline(myfile,line)){
      for(int i=0; i < line.length(); i++){
         text += toupper(line[i]);
      }
   }
   myfile.close();
   myfile.open(filename, std::ofstream::out | std::ofstream::trunc);
   myfile.close();
   myfile.open (filename, std::ios_base::app);
   myfile << text << endl;
   myfile.close();
   cout << "Done\n";
   return filename;
}

string lower(string& filename){
   string line, text;
   fstream myfile;
   myfile.open(filename, fstream::in);
   while(getline(myfile,line)){
      for(int i=0; i < line.length(); i++){
         text += tolower(line[i]);
      }
   }
   myfile.close();
   myfile.open(filename, std::ofstream::out | std::ofstream::trunc);
   myfile.close();
   myfile.open (filename, std::ios_base::app);
   myfile << text << endl;
   myfile.close();
   cout << "Done\n";
   return filename;
}

string capitalize(string& filename){
   string line, text;
   fstream myfile;
   myfile.open(filename);
   while(getline(myfile,line)){
      for (int i =0; i < line.length(); i++){
         if (i == 0){
            text += toupper(line[i]);
         }
         else if (line[i-1] == ' '){
            text += toupper(line[i]);
         }
         else{
            text += tolower(line[i]);
         }
      }
   }
   myfile.close();
   myfile.open(filename, std::ofstream::out | std::ofstream::trunc);
   myfile.close();
   myfile.open (filename, std::ios_base::app);
   myfile << text << endl;
   myfile.close();
   cout << "Done\n";
   return filename;
}

int main(){
   string filename;int complete = 1, choice;
   cout << "Hello Users :)\nPlease Enter the name of the file you want to edit: ";
   getline(cin >> ws, filename);
   fstream test;
   test.open(filename);
   if (!test){
      std::ofstream test(filename);
      cout << "This is a new file. I created it for you :)\nPlease choose what do you want..\n";
   }
   else{
      cout << "This File Already Exists\nPlease choose what do you want..\n";
   }
   fstream file;string line;
   
   cout << "1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n4. Encrypt the file content\n5. Decrypt the file content\n6. Merge another file\n7. Count the number of words in the file\n8. Count the number of characters in the file\n9. Count the number of lines in the file\n10. Search for a word in the file\n11. Count the number of times a word exists in the file\n12. Turn the file content to upper case.\n13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital)\n15. Save\n16. Exit\n";
   while(complete){
      cin >> choice;
      if (choice == 1){
         append(filename);
      }
      else if (choice == 2){
         filecontent(filename);
      }
      else if (choice == 3){
         clear(filename);
      }
      else if (choice == 4){
         encrypt(filename);
      }
      else if (choice == 5){
         decrypt(filename);
      }
      else if (choice == 6){
         merge(filename);
      }
      else if (choice == 7){
         count_words(filename);
      }
      else if (choice == 8){
         count_char(filename);
      }
      else if (choice == 9){
         count_lines(filename);
      }
      else if (choice == 10){
         find_word(filename);
      }
      else if (choice == 11){
         count_found_word(filename);
      }
      else if (choice == 12){
         upper(filename);
      }
      else if (choice == 13){
         lower(filename);
      }
      else if (choice == 14){
         capitalize(filename);
      }
      else if (choice == 15 || choice == 16){
         system("CLS");
         cout << "Thank you for using our program :)";
         return 0;
      }
      cout << "1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n4. Encrypt the file content\n5. Decrypt the file content\n6. Merge another file\n7. Count the number of words in the file\n8. Count the number of characters in the file\n9. Count the number of lines in the file\n10. Search for a word in the file\n11. Count the number of times a word exists in the file\n12. Turn the file content to upper case.\n13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital)\n15. Save\n16. Exit\n";
   }
}
