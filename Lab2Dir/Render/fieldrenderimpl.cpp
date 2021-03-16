#include "fieldrenderimpl.h"
#include <iostream>

FieldRenderImpl::FieldRenderImpl(Function<char, int> *digitCodeToCharFunction) :
    m_digitCodeToCharFunction(digitCodeToCharFunction)
{

}


void FieldRenderImpl::renderField(const Field *field)
{
    size_t w = field->width();
    size_t h = field->height();
    size_t strSize = (w + 1) * h + 1;
    char *fieldStr = new char[strSize]();
    memset(fieldStr, 0, strSize);

    size_t strSymCounter = 0;

    for (size_t y = 0; y < h; ++y, ++strSymCounter){
        for (size_t x = 0; x < w; ++x, ++strSymCounter)
            fieldStr[strSymCounter] =
                    m_digitCodeToCharFunction->calculate(field->operator()(x, y).cellDigitCode());
        fieldStr[strSymCounter] = '\n';
    }

    std::cout << fieldStr << std::endl;
    delete [] fieldStr;
}

Function<char, int> *FieldRenderImpl::digitCodeToCharFunction() const
{
    return m_digitCodeToCharFunction;
}

void FieldRenderImpl::setDigitCodeToCharFunction(Function<char, int> *digitCodeToCharFunction)
{
    m_digitCodeToCharFunction = digitCodeToCharFunction;
}
