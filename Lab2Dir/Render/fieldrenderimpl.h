#ifndef FIELDRENDERIMPL_H
#define FIELDRENDERIMPL_H

#include "Render/fieldrender.h"
#include "Functions/function.h"

class FieldRenderImpl : public FieldRender
{
public:
    FieldRenderImpl(Function<char, int> *digitCodeToCharFunction);

    // FieldRender interface
public:
    void renderField(const Field *field) override;

    Function<char, int> *digitCodeToCharFunction() const;
    void setDigitCodeToCharFunction(Function<char, int> *digitCodeToCharFunction);

private:
    Function<char, int> *m_digitCodeToCharFunction;
};

#endif // FIELDRENDERIMPL_H
