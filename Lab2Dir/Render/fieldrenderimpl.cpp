#include "fieldrenderimpl.h"
#include <iostream>

FieldRenderImpl::FieldRenderImpl(Function<char, int> *digitCodeToCharFunction) :
    m_digitCodeToCharFunction(digitCodeToCharFunction)
{

}


void FieldRenderImpl::renderField(const Field *field)
{
    system("clear");

    size_t w = field->width();
    size_t h = field->height();
    size_t strSize = (w + 1) * h + 1;
    char *fieldStr = new char[strSize]();
    memset(fieldStr, 0, strSize);

    size_t strSymCounter = 0;

    for (size_t row = 0; row < h; ++row, ++strSymCounter){
        for (size_t col = 0; col < w; ++col, ++strSymCounter)
            fieldStr[strSymCounter] =
                    m_digitCodeToCharFunction->calculate(field->operator()(row, col).cellDigitCode());
        fieldStr[strSymCounter] = '\n';
    }

    std::cout << fieldStr << std::endl;
    delete [] fieldStr;
}
