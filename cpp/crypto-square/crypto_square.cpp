#include "crypto_square.h"

#include <regex>
#include <cctype>
#include <cmath>

namespace crypto_square {
    cipher::cipher(std::string inputSentence){
        //Checking for length cause empty inputs are accepted
        if(inputSentence.length()==0)
            return;
        
        //remove all special chars
        inputSentence = std::regex_replace(inputSentence, std::regex("[^a-zA-Z0-9]"), "$1");
        
        //cast to lowercase
        std::transform(inputSentence.begin(), inputSentence.end(), inputSentence.begin(),[](unsigned char c){ 
            return std::tolower(c); 
        });

        normalizedPlainText = inputSentence;

        //plain text segments
        //colums >= rows
        //colums-rows <= 1
        float sqrtOfLength = sqrt(normalizedPlainText.length());
        
        int rows, columns, blankSpaces = 0;
        rows = columns = (int)sqrtOfLength;

        //adjust num of rows and blank spaces if solution of sqrt isn't even
        if((float)rows < sqrtOfLength){
            columns++;
            //length%rows is the rest of chars left, so rows-restOfChar is number of blank spaces
            blankSpaces = rows - normalizedPlainText.length()%rows;
        }

        //assign plain text segments
        for(int i=0; i<rows; i++){
            plainTextSegments.push_back(normalizedPlainText.substr(i*columns, columns));
        }
        
        //add blank spaces to final text segment

        //cipher text
        for(int column=0; column<columns; column++){
            for(int row=0; row<rows; row++){
                //if we aren't trying to access unexisting characters cause of blank spaces
                if(!(row==rows-1 && column>=columns-blankSpaces))
                    //add letter at column from plain text segment at row
                    cipherText += plainTextSegments[row][column];
            }
        }

        //normalized cipher text
        int skippedLetters = 0;
        for(int i=0; i<columns; i++){
            if(i >= columns-blankSpaces){
                normalizedCipherText += cipherText.substr(i*rows-skippedLetters, rows-1) + "  ";
                skippedLetters++;
            }
            else
                normalizedCipherText += cipherText.substr(i*rows-skippedLetters, rows) + ' ';
        }
        
        //remove the last whitespace
        normalizedCipherText.pop_back();
    }

    std::string cipher::normalize_plain_text() const{
        return normalizedPlainText;
    }

    std::vector<std::string> cipher::plain_text_segments() const{
        return plainTextSegments;
    }

    std::string cipher::cipher_text() const{
        return cipherText;
    }

    std::string cipher::normalized_cipher_text() const{
        return normalizedCipherText;
    }
}  // namespace crypto_square
