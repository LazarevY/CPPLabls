#ifndef MDISUBWINDOWEVENTFILTER_H
#define MDISUBWINDOWEVENTFILTER_H

#include <QObject>
#include <QMdiSubWindow>
#include <QEvent>

class MdiSubwindowEventFilter: public QObject
{
    Q_OBJECT
public:
    MdiSubwindowEventFilter(QObject *parent = nullptr);
public slots:
    bool eventFilter(QObject *obj, QEvent *e);
};

#endif // MDISUBWINDOWEVENTFILTER_H
