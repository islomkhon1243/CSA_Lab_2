#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//-----------------------------------------------CONVERSIONS----------------------------------------------

    static string fromDecimalToBinary(int num){
        string result = "";
        while(num >= 1){
            if(num == 1){
                result = "1" + result;
                break;
            }
            else if(num % 2 == 1){
                num = num / 2;
                result = "1" + result;
            }
            else{
                num = num / 2;
                result = "0" + result;
            }
        }
        return result;
    }

    static int fromBinaryToDecimal(string num){
        int result = 0;
        int len = num.size() - 1;
        int start = 0;
        
        while(len >= 0){
            char charElement = num[len];
            int intElement = charElement - '0';
            int number = pow(2, start) * intElement;
            result = number + result;
            len--;
            start++;
        }
        return result;
    }

    static int fromDecimalToOctal(int num){
        string tempString = "";
        while(num >= 1){
            if(num == 1){
                tempString = "1" + tempString;
                break;
            }
            else{
                int element = num % 8;
                string stringElement = to_string(element);
                tempString = stringElement + tempString;
                num = num / 8;
            }
        }
        return stoi(tempString);
    }

    static int fromOctalTodecimal(string num){
        int result = 0;
        int len = num.size() - 1; 
        int start = 0;
        while(len >= 0){
            char element = num[len];
            int intElement = element - '0';
            int number = pow(8, start) * intElement;
            result = number + result;
            len--;
            start++;

        }
        return result;
    }
    
    static string fromDecimalToHexadecimal(int num){
        string result = "";
        while(num >= 0){
            if(num == 0){
                break;
            }
            else if(num % 16 == 10){
                result = "A" + result;
                num = num / 16;
            }
            else if(num % 16 == 11){
                result = "B" + result;
                num = num / 16;
            }
            else if(num % 16 == 12){
                result = "C" + result;
                num = num / 16;
            }
            else if(num % 16 == 13){
                result = "D" + result;
                num = num / 16;
            }
            else if(num % 16 == 14){
                result = "E" + result;
                num = num / 16;
            }
            else if(num % 16 == 15){
                result = "F" + result;
                num = num / 16;
            }
            else{
                int element = num % 16;
                string stringElement = to_string(element);
                result = stringElement + result;
                num = num / 16;
            }
        }
        return result;
    }

    static int fromHexadecimalToDecimal(string num){
        int result = 0;
        int len = num.length() - 1;
        int start = 0;
        while(len >= 0){
            char element = num[len];
            int intElement;
            if(element == 'A'){
                intElement = 10;
            }
            else if(element == 'B'){
                intElement = 11;
            }
            else if(element == 'C'){
                intElement = 12;
            }
            else if(element == 'D'){
                intElement = 13;
            }
            else if(element == 'E'){
                intElement = 14;
            }
            else if(element == 'F'){
                intElement = 15;
            }
            else{
                intElement = element - '0';
            }
            int number = pow(16, start) * intElement;
            result = number + result;
            len--;
            start++;
        }
        return result;
    } 

//-----------------------------------------------ADDITIONS----------------------------------------------

    static string additionOfBinary(string x1, string x2){
        string result = "";
        string otherHalf = "";

        if(x1.size() < x2.size()){
            string temp = x2;
            x2 = x1;
            x1 = temp;
        }

        int len1 = x1.size();
        int len2 = x2.size();

        int first[len1];
        int second[len2];


        for(int i = 0; i < len1; i++){
            char el = x1[i];
            int num = el - '0';
            first[i] = num;
        }

        for(int i = 0; i < len2; i++){
            char el = x2[i];
            int num = el - '0';
            second[i] = num;
        }

        if(len1 > len2){
            int category = 0;
            int biggestArrayPointer = len1 - 1;
            int smallestArrayPointer = len2 - 1;

            for(int i = smallestArrayPointer; i >= 0; i--){
                if(second[i] + first[biggestArrayPointer] > 1){
                    if(category > 0){
                        result = "1" + result;
                        biggestArrayPointer--;
                    }
                    else if(category == 0){
                        result = "0" + result;
                        category++;
                        biggestArrayPointer--;
                    }
                }
                else if(second[i] + first[biggestArrayPointer] == 1){
                    if(category > 0){
                        category--;
                        result = "0" + result;
                        category++;
                        biggestArrayPointer--;
                    }
                    else if(category == 0){
                        result = "1" + result;
                        biggestArrayPointer--;
                    }
                }
                else if(second[i] + first[biggestArrayPointer] == 0){
                    if(category > 0){
                        category--;
                        result = "1" + result;
                        biggestArrayPointer--;
                    }
                    else if(category == 0){
                        result = "0" + result;
                        biggestArrayPointer--;
                    }
                }
            }
            for(int i = biggestArrayPointer; i > 0; i--){
                if(first[biggestArrayPointer] == 0){
                    if(category > 0){
                        category--;
                        otherHalf = "1" + otherHalf;
                    }
                    else if(category == 0){
                        otherHalf = "0" + otherHalf;
                    }
                }
                else if(first[biggestArrayPointer] == 1){
                    if(category > 0){
                        category--;
                        otherHalf = "0" + otherHalf;
                        category++;
                    }
                    else if(category == 0){
                        otherHalf = "1" + otherHalf;
                    }
                }
            }
            if(first[0] == 1){
                if(category > 0){
                    otherHalf = "10" + otherHalf;
                }
                else if(category == 0){
                    otherHalf = "1" + otherHalf;
                }
            }
            else if(first[0] == 0){
                if(category > 0){
                    otherHalf = "1" + otherHalf;
                }
                else if(category == 0){
                    otherHalf = "0" + otherHalf;
                }
            }
        }
    
        else if(len1 == len2){
            int category = 0;
            int pointer1 = len1 - 1;
            int pointer2 = len2 - 1;

            while(pointer1 >= 0 && pointer2 >= 0){

                if(first[pointer1] + second[pointer2] > 1){
                    if(category > 0){
                        result = "1" + result;
                        pointer1--;
                        pointer2--;
                    }
                    else if(category == 0){
                        result = "0" + result;
                        category++;
                        pointer1--;
                        pointer2--;
                    }
                }
                else if(first[pointer1] + second[pointer2] == 1){
                    if(category > 0){
                        category--;
                        result = "0" + result;
                        category++;
                        pointer1--;
                        pointer2--;
                    }
                    else if(category == 0){
                        result = "1" + result;
                        pointer1--;
                        pointer2--;
                    }
                }
                else if(first[pointer1] + second[pointer2] == 0){
                    if(category > 0){
                        category--;
                        result = "1" + result;
                        pointer1--;
                        pointer2--;
                    }
                    else if(category == 0){
                        result = "0" + result;
                        pointer1--;
                        pointer2--;
                    }
                }
            }
            if(category > 0){
                otherHalf = "1" + otherHalf;
            }
        }
        return otherHalf + result;
    }

    static string additionOfOctal(int x1, int x2){
        string num1 = to_string(x1);
        string num2 = to_string(x2);

        string result = "";
        string otherHalf = "";

        if(num1.size() < num2.size()){
            string temp = num2;
            num2 = num1;
            num1 = temp;
        }

        int len1 = num1.size();
        int len2 = num2.size();

        int first[len1];
        int second[len2];

        for(int i = 0; i < len1; i++){
            char el = num1[i];
            int num = el - '0';
            first[i] = num;
        }

        for(int i = 0; i < len2; i++){
            char el = num2[i];
            int num = el - '0';
            second[i] = num;
        }

        if(len1 > len2){
            int category = 0;
            int biggestArrayPointer = len1 - 1;
            int smallestArrayPointer = len2 - 1;

            for(int i = smallestArrayPointer; i >= 0; i--){
                if(first[biggestArrayPointer] + second[i] < 8){
                    int num = first[biggestArrayPointer] + second[i];
                    if(category > 0){
                        num++;
                        if(num == 8){
                            result = "0" + result;
                            category++;
                            biggestArrayPointer--;
                        }
                        else{
                            category--;
                            string stringNum = to_string(num);
                            result = stringNum + result;
                            biggestArrayPointer--;
                        }
                    }
                    else{
                        string stringNum = to_string(num);
                        result = stringNum + result;
                        biggestArrayPointer--;
                    }
                }
                else if(first[biggestArrayPointer] + second[i] == 8){
                    int num = first[biggestArrayPointer] + second[i];
                    if(category > 0){
                        category--;
                        num++;
                        num = num - 8;
                        string stringNum = to_string(num);
                        result = stringNum + result;
                        category++;
                        biggestArrayPointer--;
                    }
                    else if(category == 0){
                        category++;
                        result = "0" + result;
                        biggestArrayPointer--;
                    }
                }
                else if(first[biggestArrayPointer] + second[i] > 8){
                    int num = first[biggestArrayPointer] + second[i];
                    if(category > 0){
                        category--;
                        num++;
                        num = num - 8;
                        string stringNum = to_string(num);
                        result = stringNum + result;    
                        category++;
                        biggestArrayPointer--;
                    }
                    else if(category == 0){
                        num = num - 8;
                        string stringNum = to_string(num);
                        result = stringNum + result;
                        category++;
                        biggestArrayPointer--;
                    }
                }
            }
            for(int i = biggestArrayPointer; i >= 0; i--){
                if(category > 0){
                    int num = first[i];
                    num++;
                    string stringNum = to_string(num);
                    result = stringNum + result;
                    otherHalf = stringNum + otherHalf;
                    category--;
                }
                else{
                    string stringNum = to_string(first[i]);
                    otherHalf = stringNum + otherHalf;
                }
            }
        }
        else{
            int category = 0;
            int pointer1 = len1 - 1;
            int pointer2 = len2 - 1;

            while(pointer1 >= 0 && pointer2 >= 0){
                if(first[pointer1] + second[pointer2] < 8){
                    int num = first[pointer1] + second[pointer2];
                    if(category > 0){
                        num++;
                        if(num == 8){
                            result = "0" + result;
                            category++;
                            pointer1--;
                            pointer2--;
                        }
                        else{
                            category--;
                            string stringNum = to_string(num);
                            result = stringNum + result;
                            pointer1--;
                            pointer2--;
                        }
                    }
                    else{
                        string stringNum = to_string(num);
                        result = stringNum + result;
                        pointer1--;
                        pointer2--;
                    }
                }
                else if(first[pointer1] + second[pointer2] == 8){
                    int num = first[pointer1] + second[pointer2];
                    if(category > 0){
                        category--;
                        num++;
                        num = num - 8;
                        string stringNum = to_string(num);
                        result = stringNum + result;
                        category++;
                        pointer1--;
                        pointer2--;
                    }
                    else if(category == 0){
                        category++;
                        result = "0" + result;
                        pointer1--;
                        pointer2--;
                    }
                }
                else if(first[pointer1] + second[pointer2] > 8){
                    int num = first[pointer1] + second[pointer2];
                    if(category > 0){
                        category--;
                        num++;
                        num = num - 8;
                        string stringNum = to_string(num);
                        result = stringNum + result;
                        category++;
                        pointer1--;
                        pointer2--;
                    }
                    else if(category == 0){
                        num = num - 8;
                        string stringNum = to_string(num);
                        result = stringNum + result;
                        category++;
                        pointer1--;
                        pointer2--;
                    }
                }
            }
            if(category > 0){
                otherHalf = "1" + otherHalf;
            }
        }
        return otherHalf + result;
    }

    static string additionOfHexadecimal(string x1, string x2){
        string result = "";
        string otherHalf = "";

        if(x1.size() < x2.size()){
            string temp = x2;
            x2 = x1;
            x1 = temp;
        }

        int len1 = x1.size();
        int len2 = x2.size();

        string first[len1];
        string second[len2];

        for(int i = 0; i < len1; i++){
            char el = x1[i];
            string stringElement(1, el);
            first[i] = stringElement;
        }

        for(int i = 0; i < len2; i++){
            char el = x2[i];
            string stringElement(1, el);
            second[i] = stringElement;
        }

        if(len1 > len2){
            int category = 0;
            int biggestArrayPointer = len1 - 1;
            int smallestArrayPointer = len2 - 1;
            

            for(int i = smallestArrayPointer; i >= 0; i--){
                if(fromHexadecimalToDecimal(first[biggestArrayPointer]) + fromHexadecimalToDecimal(second[i]) < 16){
                    int num = fromHexadecimalToDecimal(first[biggestArrayPointer]) + fromHexadecimalToDecimal(second[i]);
                    if(category > 0){
                        category--;
                        num++;
                        if(num == 16){
                            category++;
                            result = "0" + result;
                            biggestArrayPointer--;
                        }
                        else{
                            result = fromDecimalToHexadecimal(num) + result;
                            biggestArrayPointer--;
                        }
                    }
                    else{
                        result = fromDecimalToHexadecimal(num) + result;
                        biggestArrayPointer--;
                    }
                }
                else if(fromHexadecimalToDecimal(first[biggestArrayPointer]) + fromHexadecimalToDecimal(second[i]) == 16){
                    int num = fromHexadecimalToDecimal(first[biggestArrayPointer]) + fromHexadecimalToDecimal(second[i]);
                    if(category > 0){
                        category--;
                        num++;
                        num = num - 16;
                        result = fromDecimalToHexadecimal(num) + result;
                        biggestArrayPointer--;
                        category++;
                    }
                    else{
                        category++;
                        result = "0" + result;
                        biggestArrayPointer--;
                    }
                }
                else if(fromHexadecimalToDecimal(first[biggestArrayPointer]) + fromHexadecimalToDecimal(second[i]) > 16){
                    int num = fromHexadecimalToDecimal(first[biggestArrayPointer]) + fromHexadecimalToDecimal(second[i]);
                    if(category > 0){
                        category--;
                        num++;
                        num = num - 16;
                        result = fromDecimalToHexadecimal(num) + result;
                        biggestArrayPointer--;
                        category++;
                    }
                    else if(category == 0){
                        num = num - 16;
                        result = fromDecimalToHexadecimal(num) + result;
                        biggestArrayPointer--;
                        category++;
                    }
                }
            }

            for(int i = biggestArrayPointer; i >= 0; i--){
                if(category > 0){
                    category--;
                    int num = fromHexadecimalToDecimal(first[i]);
                    num++;
                    if(num < 16){
                        otherHalf = fromDecimalToHexadecimal(num) + otherHalf;
                    }
                    else if(num == 16){
                        otherHalf = "0" + otherHalf;
                        category++;
                    }
                    else{
                        num = num - 16;
                        otherHalf = fromDecimalToHexadecimal(num) + otherHalf;
                        category++;
                    }
                }
                else{
                    int num = fromHexadecimalToDecimal(first[i]);
                    otherHalf = fromDecimalToHexadecimal(num) + otherHalf;
                }
            }
            if(category > 0){
                otherHalf = "1" + otherHalf;
            }
        }

        else{
            int category = 0;
            int pointer1 = len1 - 1;
            int pointer2 = len2 - 1;

            while(pointer1 >= 0 && pointer2 >= 0){
                if(fromHexadecimalToDecimal(first[pointer1]) + fromHexadecimalToDecimal(second[pointer2]) < 16){
                    int num = fromHexadecimalToDecimal(first[pointer1]) + fromHexadecimalToDecimal(second[pointer2]);
                    if(category > 0){
                        category--;
                        num++;
                        if(num == 16){
                            category++;
                            result = "0" + result;
                            pointer1--;
                            pointer2--;
                        }
                        else{
                            result = fromDecimalToHexadecimal(num) + result;
                            pointer1--;
                            pointer2--;
                        }
                    }
                    else{
                        result = fromDecimalToHexadecimal(num) + result;
                        pointer1--;
                        pointer2--;
                    }
                }
                else if(fromHexadecimalToDecimal(first[pointer1]) + fromHexadecimalToDecimal(second[pointer2]) == 16){
                    int num = fromHexadecimalToDecimal(first[pointer1]) + fromHexadecimalToDecimal(second[pointer2]);
                    if(category > 0){
                        category--;
                        num++;
                        num = num - 16;
                        result = fromDecimalToHexadecimal(num) + result;
                        pointer1--;
                        pointer2--;
                        category++;
                    }
                    else{
                        category++;
                        result = "0" + result;
                        pointer1--;
                        pointer2--;
                    }
                }
                else if(fromHexadecimalToDecimal(first[pointer1]) + fromHexadecimalToDecimal(second[pointer2]) > 16){
                    int num = fromHexadecimalToDecimal(first[pointer1]) + fromHexadecimalToDecimal(second[pointer2]);
                    if(category > 0){
                        category--;
                        num++;
                        num = num - 16;
                        result = fromDecimalToHexadecimal(num) + result;
                        pointer1--;
                        pointer2--;
                        category++;
                    }
                    else if(category == 0){
                        num = num - 16;
                        result = fromDecimalToHexadecimal(num) + result;
                        pointer1--;
                        pointer2--;
                        category++;
                    }
                }
            }
            if(category > 0){
                otherHalf = "1" + otherHalf;
            }
        }
        return otherHalf + result;
    }

//-----------------------------------------------SUBTRACTIONS----------------------------------------------

    static string subtractionOfBinary(string x1, string x2){
        string result = "";
        string otherHalf = "";

        if(x1.size() < x2.size()){
            string temp = x2;
            x2 = x1;
            x1 = temp;
        }

        int len1 = x1.size();
        int len2 = x2.size();

        int first[len1];
        int second[len2];

        for(int i = 0; i < len1; i++){
            char el = x1[i];
            int num = el - '0';
            first[i] = num;
        }

        for(int i = 0; i < len2; i++){
            char el = x2[i];
            int num = el - '0';
            second[i] = num;
        }

        if(len1 > len2){
            int category = 0;
            int biggestArrayPointer = len1 - 1;
            int smallestArrayPointer = len2 - 1;

            for(int i = smallestArrayPointer; i >= 0; i--){
                if(first[biggestArrayPointer] - second[i] < 0){
                    if(category > 0){
                        result = "0" + result;
                        biggestArrayPointer--;
                    }
                    else if(category == 0){
                        result = "1" + result;
                        category++;
                        biggestArrayPointer--;
                    }
                }
                else if(first[biggestArrayPointer] - second[i]  == 1){
                    if(category > 0){
                        category--;
                        result = "0" + result;
                        biggestArrayPointer--;
                    }
                    else if(category == 0){
                        result = "1" + result;
                        biggestArrayPointer--;
                    }
                }
                else if(first[biggestArrayPointer] - second[i]  == 0){
                    if(category > 0){
                        category--;
                        result = "1" + result;
                        biggestArrayPointer--;
                    }
                    else if(category == 0){
                        result = "0" + result;
                        biggestArrayPointer--;
                    }
                }
            }
            for(int i = biggestArrayPointer; i > 0; i--){
                if(first[biggestArrayPointer] == 0){
                    if(category > 0){
                        otherHalf = "1" + otherHalf;
                    }
                    else if(category == 0){
                        otherHalf = "0" + otherHalf;
                    }
                }
                else if(first[biggestArrayPointer] == 1){
                    if(category > 0){
                        category--;
                        otherHalf = "0" + otherHalf;
                        category++;
                    }
                    else if(category == 0){
                        otherHalf = "1" + otherHalf;
                    }
                }
            }
            if(first[0] == 1){
                if(category == 0){
                    otherHalf = "1" + otherHalf;
                }
            }
            else if(first[0] == 0){
                if(category > 0){
                    otherHalf = "1" + otherHalf;
                }
            }
        }
        return otherHalf + result;
    }

    static string subtractionOfOctal(int x1, int x2){
        string num1 = to_string(x1);
        string num2 = to_string(x2);

        string result = "";
        string otherHalf = "";

        if(num1.size() < num2.size() || (x1 < x2)){
            string temp = num2;
            num2 = num1;
            num1 = temp;
        }

        int len1 = num1.size();
        int len2 = num2.size();

        int first[len1];
        int second[len2];

        for(int i = 0; i < len1; i++){
            char el = num1[i];
            int num = el - '0';
            first[i] = num;
        }

        for(int i = 0; i < len2; i++){
            char el = num2[i];
            int num = el - '0';
            second[i] = num;
        }

        if(len1 > len2){
            int category = 0;
            int biggestArrayPointer = len1 - 1;
            int smallestArrayPointer = len2 - 1;

            for(int i = smallestArrayPointer; i >= 0; i--){
                if(first[biggestArrayPointer] - second[i] < 0 && first[biggestArrayPointer] == 0){
                    if(category > 0){
                        category--;
                        first[biggestArrayPointer] = 7;
                        int num = first[biggestArrayPointer] - second[i];
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        biggestArrayPointer--;
                        category++;
                    }
                    else{
                        category++;
                        first[biggestArrayPointer] = 8;
                        int num = first[biggestArrayPointer] - second[i];
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        biggestArrayPointer--;
                    }
                }
                else if(first[biggestArrayPointer] - second[i] < 0 && first[biggestArrayPointer] > 0){
                    if(category > 0){
                        category--;
                        first[biggestArrayPointer]--;
                        int num = second[i] - first[biggestArrayPointer];
                        num = 8 - num;
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        biggestArrayPointer--;
                    }
                    else{
                        category++;
                        int num = second[i] - first[biggestArrayPointer];
                        num = 8 - num;
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        biggestArrayPointer--;
                    }
                }
                else if(first[biggestArrayPointer] - second[i] >= 0){
                    if(category > 0){
                        category--;
                        first[biggestArrayPointer]--;
                        if(first[biggestArrayPointer] - second[i] < 0){
                            category++;
                            int num = second[i] - first[biggestArrayPointer];
                            num = 8 - num;
                            string stringElement = to_string(num);
                            result = stringElement + result;
                            biggestArrayPointer--;
                        }
                        else{
                            int num = second[i] - first[biggestArrayPointer];
                            string stringElement = to_string(num);
                            result = stringElement + result;
                            biggestArrayPointer--;
                        }
                    }
                    else{
                        int num = second[i] - first[biggestArrayPointer];
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        biggestArrayPointer--;
                    }
                }
            }
            for(int i = biggestArrayPointer; i > 0; i--){
                if(category > 0){
                    category--;
                    first[biggestArrayPointer]--;
                    int num = first[biggestArrayPointer];
                    string stringElement = to_string(num);
                    result = stringElement + result;
                }
                else{
                    int num = first[biggestArrayPointer];
                    string stringElement = to_string(num);
                    result = stringElement + result;
                }
            }
            
            if(category > 0){
                category--;
                first[0]--;
                if(first[0] > 0){
                    int num = first[0];
                    string stringElement = to_string(num);
                    result = stringElement + result;
                }
            }
        }

        else{
            int category = 0;
            int pointer1 = len1 - 1;
            int pointer2 = len2 - 1;

            while(pointer1 >= 0 && pointer2 >= 0){
                if(first[pointer1] - second[pointer2] < 0 && first[pointer1] == 0){
                    if(category > 0){
                        category--;
                        first[pointer1] = 7;
                        int num = first[pointer1] - second[pointer1];
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        pointer1--;
                        pointer2--;
                        category++;
                    }
                    else{
                        category++;
                        first[pointer1] = 8;
                        int num = first[pointer1] - second[pointer1];
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        pointer1--;
                        pointer2--;
                    }
                }
                else if(first[pointer1] - second[pointer1] < 0 && first[pointer1] > 0){
                    if(category > 0){
                        category--;
                        first[pointer1]--;
                        int num = second[pointer1] - first[pointer1];
                        num = 8 - num;
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        pointer1--;
                        pointer2--;
                    }
                    else{
                        category++;
                        int num = second[pointer1] - first[pointer1];
                        num = 8 - num;
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        pointer1--;
                        pointer2--;
                    }
                }
                else if(first[pointer1] - second[pointer1] >= 0){
                    if(category > 0){
                        category--;
                        first[pointer1]--;
                        if(first[pointer1] - second[pointer1] < 0){
                            category++;
                            int num = second[pointer1] - first[pointer1];
                            num = 8 - num;
                            string stringElement = to_string(num);
                            result = stringElement + result;
                            pointer1--;
                            pointer2--;
                        }
                        else{
                            int num = second[pointer1] - first[pointer1];
                            string stringElement = to_string(num);
                            result = stringElement + result;
                            pointer1--;
                            pointer2--;
                        }
                    }
                    else{
                        int num = second[pointer1] - first[pointer1];
                        string stringElement = to_string(num);
                        result = stringElement + result;
                        pointer1--;
                        pointer2--;
                    }
                }
            }
            result.erase(0, 1);
            
        }

        return otherHalf + result;
    }

    static string subtractionOfHexadecimal(string x1, string x2){
        string result = "";
        string otherHalf = "";

        if(x1.size() < x2.size() || fromHexadecimalToDecimal(x1) < fromHexadecimalToDecimal(x2)){
            string temp = x2;
            x2 = x1;
            x1 = temp;
        }
      
        int len1 = x1.size();
        int len2 = x2.size();

        string first[len1];
        string second[len2];

        for(int i = 0; i < len1; i++){
            char el = x1[i];
            string stringElement(1, el);
            first[i] = stringElement;
        }

        for(int i = 0; i < len2; i++){
            char el = x2[i];
            string stringElement(1, el);
            second[i] = stringElement;
        }

        if(len1 > len2){
            int category = 0;
            int biggestArrayPointer = len1 - 1;
            int smallestArrayPointer = len2 - 1;
            

            for(int i = smallestArrayPointer; i >= 0; i--){
                if(fromHexadecimalToDecimal(first[biggestArrayPointer]) - fromHexadecimalToDecimal(second[i]) < 0){
                    if(category > 0){
                        category--;
                        int num = fromHexadecimalToDecimal(first[biggestArrayPointer]);
                        num--;
                        num = num + 16;
                        num = num - fromHexadecimalToDecimal(second[i]);
                        result = fromDecimalToHexadecimal(num) + result;
                        category++;
                        biggestArrayPointer--;
                    }
                    else{
                        int num = fromHexadecimalToDecimal(first[biggestArrayPointer]) + 16;
                        num = num - fromHexadecimalToDecimal(second[i]);
                        result = fromDecimalToHexadecimal(num) + result;
                        category++;
                        biggestArrayPointer--;
                    }
                }
                else if(fromHexadecimalToDecimal(first[biggestArrayPointer]) - fromHexadecimalToDecimal(second[i]) >= 0){
                    if(category > 0){
                        category--;
                        int num = fromHexadecimalToDecimal(first[biggestArrayPointer]);
                        num--;
                        if(fromHexadecimalToDecimal(first[biggestArrayPointer]) - fromHexadecimalToDecimal(second[i]) < 0){
                            num = num + 16;
                            num = num - fromHexadecimalToDecimal(second[i]);
                            result = fromDecimalToHexadecimal(num) + result;
                            category++;
                            biggestArrayPointer--; 
                        }
                        else{
                            num = num - fromHexadecimalToDecimal(second[i]);
                            result = fromDecimalToHexadecimal(num) + result;
                            biggestArrayPointer--;

                        }
                    }
                    else{
                        int num = fromHexadecimalToDecimal(first[biggestArrayPointer]) - fromHexadecimalToDecimal(second[i]);
                        result = fromDecimalToHexadecimal(num) + result;
                        biggestArrayPointer--;
                    }
                }
            }

            for(int i = biggestArrayPointer; i >= 0; i--){
                if(category > 0){
                    category--;
                    int num = fromHexadecimalToDecimal(first[i]);
                    num--;
                    otherHalf = fromDecimalToHexadecimal(num) + otherHalf;
                }
                else{
                    int num = fromHexadecimalToDecimal(first[i]);
                    otherHalf = fromDecimalToHexadecimal(num) + otherHalf;
                }
            }
        }

        else{
            int category = 0;
            int pointer1 = len1 - 1;
            int pointer2 = len2 - 1;

            while(pointer1 >= 0 && pointer2 >= 0){
                if(fromHexadecimalToDecimal(first[pointer1]) - fromHexadecimalToDecimal(second[pointer2]) < 0){
                    if(category > 0){
                        category--;
                        int num = fromHexadecimalToDecimal(first[pointer1]);
                        num--;
                        num = num + 16;
                        num = num - fromHexadecimalToDecimal(second[pointer2]);
                        result = fromDecimalToHexadecimal(num) + result;
                        category++;
                        pointer1--;
                        pointer2--;
                    }
                    else{
                        int num = fromHexadecimalToDecimal(first[pointer1]) + 16;
                        num = num - fromHexadecimalToDecimal(second[pointer2]);
                        result = fromDecimalToHexadecimal(num) + result;
                        pointer1--;
                        pointer2--;
                        category++;
                    }
                }
                else if(fromHexadecimalToDecimal(first[pointer1]) - fromHexadecimalToDecimal(second[pointer2]) >= 0){
                    if(category > 0){
                        category--;
                        int num = fromHexadecimalToDecimal(first[pointer1]);
                        num--;
                        if(fromHexadecimalToDecimal(first[pointer1]) - fromHexadecimalToDecimal(second[pointer2]) < 0){
                            num = num + 16;
                            num = num - fromHexadecimalToDecimal(second[pointer2]);
                            result = fromDecimalToHexadecimal(num) + result;
                            category++;
                            pointer1--;
                            pointer2--; 
                        }
                        else{
                            num = num - fromHexadecimalToDecimal(second[pointer2]);
                            result = fromDecimalToHexadecimal(num) + result;
                            pointer1--;
                            pointer2--;
                        }
                    }
                    else{
                        int num = fromHexadecimalToDecimal(first[pointer1]) - fromHexadecimalToDecimal(second[pointer2]);
                        result = fromDecimalToHexadecimal(num) + result;
                        pointer1--;
                        pointer2--;
                    }
                }
            }
           
        }
        return otherHalf + result;
    }




    int main(){

        cout << additionOfHexadecimal("1FB", "A54");
        
        return 0;
    }
    







