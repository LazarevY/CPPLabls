#ifndef ABSTARCTUI_H
#define ABSTARCTUI_H


class AbstarctUI
{
public:
    AbstarctUI();
    virtual ~AbstarctUI();

    virtual int show() = 0;
};

#endif // ABSTARCTUI_H
