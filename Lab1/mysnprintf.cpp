#include "mysnprintf.h"
#include <string>
#include <string.h>
#include <math.h>

int my_snprintf(char *s, size_t n, const char *format,  ...)
{

    if (!s || !format)
        return -1;


    char *stringBuffer = s;
    int maxLen = n;
    int intN = n;


    char *stringBufferPointer = stringBuffer;
    const char *formatPointer = format;
    bool isEscapeDetected = false;
    bool isCorrectSpecifier = false;

    int symCounter  = 0;

    va_list argsList;

    va_start(argsList, format);

    while (*formatPointer != '\0'){ //>1 - reserve

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
                    if (intN > 1){
                        int toWrite = fmin(countSymbols, intN - 1);
                        int writed = concat_str(stringBufferPointer, strValue, toWrite);
                        stringBufferPointer += writed;
                        intN -= writed;
                    }
                    symCounter += countSymbols;
                }
            }
            else {
                symCounter++;
                if (intN > 1){
                    *stringBufferPointer = *formatPointer;
                    stringBufferPointer++;
                    intN--;
                }
            }
        }


        formatPointer++;

    }
    *(s + static_cast<int>(fminl(symCounter + 1, maxLen - 1))) = '\0';

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

int resize_string(char *old_ptr, char **new_ptr, int newSize)
{

    *new_ptr = new char[newSize];

    strcpy(*new_ptr, old_ptr);

    return 0;
}
