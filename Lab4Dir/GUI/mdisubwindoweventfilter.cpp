#include "mdisubwindoweventfilter.h"
#include "caselistwidget.h"

MdiSubwindowEventFilter::MdiSubwindowEventFilter(QObject *parent) : QObject(parent)
{

}

bool MdiSubwindowEventFilter::eventFilter(QObject * obj, QEvent * e)
{
    switch (e->type())
    {
        case QEvent::Close:
        {
            QMdiSubWindow * subWindow = dynamic_cast<QMdiSubWindow*>(obj);
            if (subWindow){
                auto widget = dynamic_cast<CaseListWidget *>(subWindow->widget());
                if (widget){
                    widget->callBeforeClose();
                }
            }
            break;
        }
        default:
            qt_noop();
    }
    return QObject::eventFilter(obj, e);
}
