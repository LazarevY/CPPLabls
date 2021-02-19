#include "mysnprintf.h"
#include <string>
#include <string.h>
#include <math.h>

int my_snprintf(char *s, size_t n, const char *format,  ...)
{

    if (!s || !format)
        return -1;

    int startSize = strlen(format) * 2;
    int currentSize = startSize;
    char *stringBuffer = new char[startSize](); //origin function always return length


    char *stringBufferPointer = stringBuffer;
    const char *formatPointer = format;
    bool isEscapeDetected = false;
    bool isCorrectSpecifier = false;

    int symCounter  = 0;

    va_list argsList;

    va_start(argsList, format);

    while (*formatPointer != '\0' &&  n > 1){

        const char *strValue;
        char bufferSymbol;
        if (*formatPointer == '%')
            isEscapeDetected = true;
        else {
            if (isEscapeDetected){
                isEscapeDetected = false;
                switch (*formatPointer) {
                case 'd':{
                    isCorrectSpecifier = true;
                    int digitValue = va_arg(argsList, int);
                    strValue = std::to_string(digitValue).c_str();
                    break;
                }
                case 's':
                    isCorrectSpecifier = true;
                    strValue = va_arg(argsList, const char*);
                    break;
                case 'c':{
                    isCorrectSpecifier = true;
                    int charToInteger = va_arg(argsList, int);
                    bufferSymbol = charToInteger;
                    strValue = &bufferSymbol;
                    break;
                }
                default:
                    isEscapeDetected = false;
                    isCorrectSpecifier = false;
                    *(stringBufferPointer) = '%';
                    stringBufferPointer++;
                    *stringBufferPointer = *formatPointer;
                    stringBufferPointer++;
                    symCounter +=2 ;
                }


                if (isCorrectSpecifier){
                    isCorrectSpecifier = false;
                    int countSymbols = strlen(strValue);
                    if (symCounter + countSymbols > currentSize){
                        currentSize += startSize;
                        char *swapBuffer;
                        resize_string(stringBuffer, swapBuffer, currentSize);
                        delete[] stringBuffer;
                        stringBuffer = swapBuffer;
                        stringBufferPointer = (stringBuffer + symCounter);
                    }
                    concat_str(stringBufferPointer, strValue, fmaxl(0, n -1));
                    stringBufferPointer += countSymbols;
                    symCounter += countSymbols;
                }
            }
            else {
                *stringBufferPointer = *formatPointer;
                stringBufferPointer++;
                symCounter++;
            }
        }


        formatPointer++;

    }
    strncpy(s, stringBuffer, fmaxl(0, n -1));
    *(s + static_cast<int>(fminl(symCounter + 1, n))) = '\0';
    delete[] stringBuffer;

    return symCounter;
}

int concat_str(char *dist, const char *src, int maxLen)
{
    char *dc = dist;
    const char *csrc = src;

    int count = 0;

    while (*csrc != '\0' && maxLen != 0) {
        *dc = *csrc;
        dc++;
        csrc++;
        count++;
        maxLen--;
    }
    return count;

}

int resize_string(char *old_ptr, char *new_ptr, int newSize)
{

    new_ptr = new char[newSize];

    strcpy(new_ptr, old_ptr);

    return 0;
}
