#include "nocasefoundexception.h"
#include <QDebug>

NoCaseFoundException::NoCaseFoundException(Case case_, const QString &word) :
    m_case(case_), m_word(word)
{
    m_msg = QString("No found case %1 to word %2").arg(
                CaseTools::caseEnumToStr(m_case)).arg(m_word);
}

Case NoCaseFoundException::case_() const
{
    return m_case;
}

QString NoCaseFoundException::word() const
{
    return m_word;
}

QString NoCaseFoundException::msg() const
{
    return m_msg;
}

const char *NoCaseFoundException::what() const noexcept
{
    return m_msg.toStdString().data();
}
