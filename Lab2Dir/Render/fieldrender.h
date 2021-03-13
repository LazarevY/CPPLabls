#ifndef FIELDRENDER_H
#define FIELDRENDER_H
#include "Logic/field.h"

class FieldRender
{
public:
    FieldRender();
    virtual ~FieldRender();

    virtual void renderField(const Field *field) = 0;

};

#endif // FIELDRENDER_H
