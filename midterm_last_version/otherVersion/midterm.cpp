/*
Michael Matthews
netID: mjm287


Important = this program uses a lot of true false statments in the logic

This program is designed to take whatever the user puts in and then
output it into piglatin. If you the user puts in a vowel it'll add
a "yay" to the end. If you user puts in a constant it will take the first
part of that constant and put it to the end of the word. 

For example never = everay

Please enter phrase to be translated: Running Is the Thing Two To
Here is the phrase: Running Is the Thing Two To 
Here is the translation: Unningray Isyay ethay Ingthay Otway Otay 

Please enter phrase to be translated: Woooords "can" b " be" "solong" '%said %$ the duck;
Here is the phrase: Woooords "can" b " be" "solong" '%said %$ the duck; 
Here is the translation: Oooordsway "canyay" bay " beyay" "solongyay" '%aidsay %$ ethay duckyay; 

Please enter phrase to be translated: everything....
Here is the phrase: everything.... 
Here is the translation: everythingyay.... 

Please enter phrase to be translated: Okay! "this" works ":" 
Here is the phrase: Okay! "this" works ":"  
Here is the translation: Okayyay! "thisyay" orksway ":"  

Please enter phrase to be translated: wrds oooo """    
Here is the phrase: wrds oooo """ 
Here is the translation: wrdsay ooooyay """ 

Please enter phrase to be translated: united we can make a differnce "said the Oppersor"
Here is the phrase: united we can make a differnce "said thee Oppersor" 
Here is the translation: unitedyay eway ancay akemay ayay iffernceday "aidsay eethay Oppersoryay" 

Please enter phrase to be translated: Never too late is the promise ""
Here is the phrase: Never too late is the promise "" 
Here is the translation: Eernay ootay atelay isyay ethay omisepray "" 

Please enter phrase to be translated: Opstay is not enought !!! "okay" """okay"""
Here is the phrase: Opstay is not enought !!! "okay" """okay""" 
Here is the translation: Opstayyay isyay otnay enoughtyay !!! "okayyay" """okayyay""" 

Please enter phrase to be translated: Running
Here is the phrase: Running 
Here is the translation: Unningray 

Please enter phrase to be translated: "this"
Here is the phrase: "this" 
Here is the translation: "thisyay" 

Please enter phrase to be translated: Start with Vowel : ostrich
Here is the phrase: Start with Vowel : ostrich 
Here is the translation: Artstay ithway Owelvay : ostrichyay 

Please enter phrase to be translated: Start with Constant constant
Here is the phrase: Start with Constant constant 
Here is the translation: Artstay ithway Onstantcay onstantcay 

Please enter phrase to be translated: All Vowels oioei
Here is the phrase: All Vowels oioei 
Here is the translation: Allyay Owelsvay oioeiyay 

Please enter phrase to be translated: All Consts rrrnyhw
Here is the phrase: All Consts rrrnyhw 
Here is the translation: Allyay Onstscay rrrnyhway 

Please enter phrase to be translated: trailing punct alright....
Here is the phrase: trailing punct alright.... 
Here is the translation: ailingtray unctpay alrightyay.... 

Please enter phrase to be translated: not that : ! case
Here is the phrase: not that : ! case 
Here is the translation: otnay atthay : ! asecay 

Please enter phrase to be translated: "before"
Here is the phrase: "before" 
Here is the translation: "beforeyay" 

Please enter phrase to be translated: !After!
Here is the phrase: !After! 
Here is the translation: !Afteryay! 

Please enter phrase to be translated: ""ecvery
Here is the phrase: ""ecvery 
Here is the translation: ""ecveryyay 

Please enter phrase to be translated: """not
Here is the phrase: """not 
Here is the translation: """otnay 


Please enter phrase to be translated: opstay
logout

including necessary libraries to run the code
//can we assume that we'll never get more than one space to output
// can we assume that a word will never begin with punctuation


 

*/

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <cctype>

using namespace std;

/*this function prints out all of the information the vector
It does it once in order to let the user know what they put in and 
it does it again to after the pig latin translation */
int printVector(vector<string>& list_of_words){

int vectorLength = list_of_words.size();
for (int i = 0; i < vectorLength; i++){
//puts a space after each item in the vector
cout << list_of_words[i] << " ";
}

return 0;
}

int capitalization(vector<string>& list_of_words){

string putIn;
string capital_letter;
int vectorLength = list_of_words.size();
string firstNewLetter;
int numberNewLetter = false;
for (int i = 0; i < vectorLength; i++){
int went = false;
int vectorLength = list_of_words.size();
ostringstream stream;
stream << list_of_words[i];
string word = stream.str();
string nextCharacter;
string the_first_character;

int lengthOfWord = word.length();
int count = false;
int capitalLetter = false;
int wentOnce = false;

for (int x = 0; x < lengthOfWord; x++){

nextCharacter = word[x];
 
if (count == false){
 
if( "B"== nextCharacter){ nextCharacter = "b"; count = true; }
if( "C"== nextCharacter){ nextCharacter = "c"; count = true; }
if( "D"== nextCharacter){ nextCharacter = "d"; count = true; }
if( "F"== nextCharacter){ nextCharacter = "f"; count = true; }
if( "G"== nextCharacter){ nextCharacter = "g"; count = true; }
if( "H"== nextCharacter){ nextCharacter = "h"; count = true; }
if( "J"== nextCharacter){ nextCharacter = "j"; count = true; }
if( "K"== nextCharacter){ nextCharacter = "k"; count = true; }
if( "L"== nextCharacter){ nextCharacter = "l"; count = true; }
if( "M"== nextCharacter){ nextCharacter = "m"; count = true; }
if( "N"== nextCharacter){ nextCharacter = "n"; count = true; }
if( "P"== nextCharacter){ nextCharacter = "p"; count = true; }
if( "Q"== nextCharacter){ nextCharacter = "q"; count = true; }
if( "R"== nextCharacter){ nextCharacter = "r"; count = true; }
if( "S"== nextCharacter){ nextCharacter = "s"; count = true; }
if( "T"== nextCharacter){ nextCharacter = "t"; count = true; }
if( "V"== nextCharacter){ nextCharacter = "v"; count = true; }
if( "W"== nextCharacter){ nextCharacter = "w"; count = true; }
if( "X"== nextCharacter){ nextCharacter = "x"; count = true; }
if( "Y"== nextCharacter){ nextCharacter = "y"; count = true; }
if( "Z"== nextCharacter){ nextCharacter = "z"; count = true; }
//cout << nextCharacter << " ";
putIn = nextCharacter;
}

if (wentOnce == false){
if (count == true){

capitalLetter = x;
wentOnce = true;
//cout << capitalLetter;
}
}

if (went == false){
if (isalnum(word[x])){
firstNewLetter = word[x];
went = true;
numberNewLetter = x;
}
}

}
 
//cout << putIn;
if (count == true){
int moverOver = capitalLetter;
int nextStart = moverOver + 1;
int rest = lengthOfWord - moverOver;
 
int moveOverMinus = moverOver - 1;
int counter = 0;

for (int r = 0; r < lengthOfWord; r++){

the_first_character = word[r];
 
if (counter == false){

if( "a"== the_first_character){ the_first_character = "A"; counter = true;  }
if( "e"== the_first_character){ the_first_character = "E"; counter = true;   }
if( "i"== the_first_character){ the_first_character = "I"; counter = true;   }
if( "o"== the_first_character){ the_first_character = "O"; counter = true;   }
if( "u"== the_first_character){ the_first_character = "U";  counter = true;  }
if( "b"== the_first_character){ the_first_character = "B"; counter = true;  }
if( "c"== the_first_character){ the_first_character = "C"; counter = true;   }
if( "d"== the_first_character){ the_first_character = "D"; counter = true;   }
if( "f"== the_first_character){ the_first_character = "F"; counter = true;   }
if( "g"== the_first_character){ the_first_character = "G";  counter = true;  }
if( "h"== the_first_character){ the_first_character = "H"; counter = true;  }
if( "j"== the_first_character){ the_first_character = "J"; counter = true;   }
if( "k"== the_first_character){ the_first_character = "K"; counter = true;   }
if( "l"== the_first_character){ the_first_character = "L"; counter = true;   }
if( "m"== the_first_character){ the_first_character = "M";  counter = true;  }
if( "n"== the_first_character){ the_first_character = "N"; counter = true;  }
if( "p"== the_first_character){ the_first_character = "P"; counter = true;   }
if( "q"== the_first_character){ the_first_character = "Q"; counter = true;   }
if( "r"== the_first_character){ the_first_character = "R"; counter = true;   }
if( "s"== the_first_character){ the_first_character = "S";  counter = true;  }
if( "t"== the_first_character){ the_first_character = "T";  counter = true;  }
if( "v"== the_first_character){ the_first_character = "V"; counter = true;  }
if( "w"== the_first_character){ the_first_character = "W"; counter = true;   }
if( "x"== the_first_character){ the_first_character = "X"; counter = true;   }
if( "y"== the_first_character){ the_first_character = "Y"; counter = true;   }
if( "z"== the_first_character){ the_first_character = "Z";  counter = true;  }
 
//cout << the_first_character << " ";
capital_letter = the_first_character;
}


} 
int startSecond = numberNewLetter + 1;
list_of_words[i] = word.substr(0, numberNewLetter) + capital_letter + word.substr(startSecond, moveOverMinus) + putIn + word.substr(nextStart, rest);

} 

if (count == false){

list_of_words[i] = word;
}
 

} 


cout << "Here is the translation: ";
printVector(list_of_words);
return 0;

}

/*This funciton translates the vector into pig latin. Here is the logic
for vowels, constants, punctuation, etc 
*/

int translateVector(vector<string>& list_of_words){
 
//Here is the vector with the vowel information
vector<string> vowels;
vowels.push_back("a");
vowels.push_back("e");
vowels.push_back("i");
vowels.push_back("o");
vowels.push_back("u");
vowels.push_back("A");
vowels.push_back("E");
vowels.push_back("I");
vowels.push_back("O");
vowels.push_back("U");
int vowelsLength = vowels.size();
int vectorLength = list_of_words.size();
int wordLength;


for (int i = false; i < vectorLength; i++){

int last_character_punct = false;
int hasVowel = false;
int counter_punct_beg = false;
int backwards_punct_end = false;
 

//true false statents
int starts_with_vowel = false;
int starts_with_punct = false;
int hit_start_punct = false;
int started_wordLength = false;
int start_position = false;
int end_position = false;
int actual_word_length = false;
int found_punct_after_word = false;
int last_letter_punctEnd = false;
int countDownContinue = true;
int hasLetter = false;
int beenReplaced = false;
int firstVowelFound = false;
int after_word_punct;
int keepgoing = true;
int isConst = true;
int zeroHere = 0;
 
ostringstream stream;
stream << list_of_words[i];
string word = stream.str();

wordLength = word.length();

//do logic first for the very first charcter of the string
//if it is vowel, const, or punctuation

if (isalnum(word[zeroHere])){
string firstCharacter = word.substr(zeroHere,true);
//if it is either a vowel or const
 
for (int y = 0; y < vowelsLength; y++){
if (vowels[y] == firstCharacter){
starts_with_vowel = true;
}
}
//if starts_with_vowel = false then it starts with const;
} else {

starts_with_punct = true;
}

last_character_punct = wordLength - 1;
 
if (!isalnum(word[last_character_punct])){
//if last character is punctuation
last_character_punct = true;
}

int start = false;
for (int x = 0; x < wordLength; x++){

for (int n = 0; n < vowelsLength; n++){
int oneMore = 1;
if (vowels[n] == word.substr(start,oneMore)){
hasVowel = true;
 
}
}
start++;
}

//taking care of punctuation at the beginning

if (starts_with_punct == true){
counter_punct_beg = false;
for (int c = false; c < wordLength; c++){
if(!isalnum(word[c])){
 
if (hit_start_punct != true){
//make sure that we are counting the ending of the punctuation
counter_punct_beg++;
}

}else {
hit_start_punct = true;
}
}
counter_punct_beg = counter_punct_beg;
}

//taking care if it ends with punctuation


 

//finding out how long the word is, independent of whether or not it has a vowel or const
for (int q = false; q < wordLength; q++){

if(isalnum(word[q])){
 
if (started_wordLength == false){
started_wordLength = true;
start_position = q;
}

}

 
}
//this loop needs to go after the q one;
if (last_character_punct == true){

int lastCharcter = wordLength - true;

for (int z = start_position; z < wordLength; z++){

if (!isalnum(word[z])){
if (found_punct_after_word == false){
found_punct_after_word = true;
last_letter_punctEnd = z;
 
}
}
}


//you'll need to start at the end of the lastLetter and go over backwards_punct_end

} 


//okay here I am going to try and simply sitch the words around without adding the "ay" at the end;
 
int starting_vowel_loop = false;
if (starts_with_vowel == false){
for (int f = false; f < wordLength; f++){
for (int w = false; w < vowelsLength; w++){
if (vowels[w] == word.substr(starting_vowel_loop,true)){
if (firstVowelFound == false){
firstVowelFound = f;
} 
}
}
starting_vowel_loop++;
}
} 

 
int end = wordLength - last_letter_punctEnd;

//cout << last_letter_punctEnd;
//cout << start_position;
 
 
//logic to define if it is a const or not

for (int b = false; b < vowelsLength; b++){

if (word.substr(start_position,true) == vowels[b]){
isConst = false;

}
}
 

 
 
 
 
//cout << word.substr(false,start_position);
 
//cout << "ay";
//cout << word.substr(,end);
 
//cout << (last_letter_punctEnd - start_position);
//cout << endl;
//cout << word.substr(false,start_position) << " ";
//cout << word.substr(start_position, end);
//cout << word.substr(last_letter_punctEnd,end);
 



//cout << last_letter_punctEnd;

//taking care if it starts with vowel
//keep in mind this is saying that there is no punctuation before

///////starts replacing

for (int s = false; s < wordLength; s++){

if (isalnum(word[s])){
hasLetter = true;
}
}

if (hasLetter == false){
list_of_words[i] = list_of_words[i];
cout << list_of_words[i];
beenReplaced = true;
}

if (isConst == true && beenReplaced == false){
if (starts_with_vowel == false){

int length = wordLength - firstVowelFound;
if (last_letter_punctEnd == false){
 
list_of_words[i] = word.substr(zeroHere, start_position) + word.substr((firstVowelFound), length) + word.substr(start_position, (firstVowelFound - start_position)) + "ay";
beenReplaced = true;
}
}
}
 
int punctuation_at_end = wordLength - last_letter_punctEnd;
if (hasVowel == true && beenReplaced == false){
 
if (starts_with_vowel == true){
//this works and this is only if the first character starts with a vowel
if (last_letter_punctEnd == false){
//if it has trailing
list_of_words[i] = list_of_words[i] + "yay";
beenReplaced = true;
}else
{//if it starts with a vowel put has no trailing

list_of_words[i] =word.substr(start_position,(last_letter_punctEnd - start_position)) + "yay" + word.substr(last_letter_punctEnd, punctuation_at_end);
//cout << list_of_words[i];
beenReplaced = true;

}


}
//if has vowel
if (starts_with_vowel == false && beenReplaced == false){
//starts with punct
if (last_letter_punctEnd == false){
// doesn't end with punct
list_of_words[i] = word.substr(zeroHere, counter_punct_beg) + word.substr(start_position,(last_letter_punctEnd - start_position))  + "yay";

beenReplaced = true;

}else{

if (beenReplaced == false){
//starts and ends with
list_of_words[i] = word.substr(zeroHere, counter_punct_beg) + word.substr(start_position,(last_letter_punctEnd - start_position)) + "yay" + word.substr(last_letter_punctEnd, punctuation_at_end);
beenReplaced = true;
}
}
}

}else{

if (beenReplaced == false){
//if does not have any vowels
list_of_words[i] = list_of_words[i] + "ay";
beenReplaced = true;
}
}


}

 


 
capitalization(list_of_words);
//printVector(list_of_words);
return 0;
}

int divideString (string output){
 

vector<string> list_of_words;
int stringLength = output.length();


int noSpaces = false;
int another = false;
int start = false;
int again = false;
int end = stringLength - 1;
int total = false;

while (end != start){

start = another;

while (!isspace(output[start])) {
start++;
}
 
again = start - another;
 
total = another + again;

if (total < end){
 
string word = output.substr(another, again);
list_of_words.push_back(word);

}else{

string word = output.substr(another, end);
list_of_words.push_back(word);
start = end;

}
another = start;
 
while (isspace(output[another])){
another++;
noSpaces = true;
}
if (noSpaces == false){
int addOne = end + noSpaces;
string word = output.substr(0, addOne);
list_of_words[0] = word;
}
 
}

cout << "Here is the phrase: ";
printVector(list_of_words);
cout << endl;
translateVector(list_of_words);
 

return 0;
} 

int main (){

 
int lengthOfStop = 6;

//needs to be six because opstay has six characters

string input;
int start = 0;
int inputLength = start;
string output = "onetwo";
string whileTest = output.substr(false,6);
 
int outputLength = 0;


int zero = 0;
int continue_asking = false;
while (zero == continue_asking){
cout << endl << endl << "Please enter phrase to be translated: ";
input = "";
cin.sync();
getline(cin, input);
ostringstream strm;

strm << input;
output = strm.str();
whileTest = output.substr(zero,lengthOfStop);
int stringLength = output.length();
 
if (stringLength == lengthOfStop){
if (whileTest == "opstay"){
exit(0);
}
}
 
if (stringLength < true){
cout << "Enter value " << endl;
}else {
 
//calling dividestring
divideString(output);
}
}



return 0;

}