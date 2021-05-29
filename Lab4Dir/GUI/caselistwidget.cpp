#include "caselistwidget.h"

CaseListWidget::CaseListWidget(const CaseList &list, const QString name, QWidget *parent) :
    QWidget(parent),
    m_list(list),
    m_name(name)
{
    m_edit = new QTextEdit(this);
    m_edit->setReadOnly(true);
    m_layout = new QGridLayout(this);
    setLayout(m_layout);
    m_layout->addWidget(m_edit);
    updateText();

}

QString CaseListWidget::name() const
{
    return m_name;
}

void CaseListWidget::setName(const QString &name)
{
    m_name = name;
}

CaseList CaseListWidget::list() const
{
    return m_list;
}

void CaseListWidget::setList(const CaseList &list)
{
    m_list = list;
}

void CaseListWidget::updateText()
{
    QString str = "";

    auto map = m_list.cases();

    for (auto word: map){
        str.append(QString("%1\n").arg(word));
    }

    m_edit->setText(str);

}

void CaseListWidget::callBeforeClose()
{
    emit beforeClose(m_name);
}
