#include "nocasefoundexception.h"

NoCaseFoundException::NoCaseFoundException(Case case_, const QString &word) :
    m_case(case_), m_word(word)
{

}

Case NoCaseFoundException::case_() const
{
    return m_case;
}

QString NoCaseFoundException::word() const
{
    return m_word;
}
