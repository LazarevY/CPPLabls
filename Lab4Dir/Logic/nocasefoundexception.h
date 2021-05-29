#ifndef NOCASEFOUNDEXCEPTION_H
#define NOCASEFOUNDEXCEPTION_H

#include <exception>
#include <QString>

#include "case.h"

class NoCaseFoundException: public std::exception
{
public:
    NoCaseFoundException(Case case_, const QString &word);
    Case case_() const;

    QString word() const;

private:
    Case m_case;
    QString m_word;
    QString m_msg;

    // exception interface
public:
    const char *what() const noexcept override;
    QString msg() const;
};

#endif // NOCASEFOUNDEXCEPTION_H
