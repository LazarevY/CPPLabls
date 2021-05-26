#ifndef PATHUTILS_H
#define PATHUTILS_H
#include <QDir>
#include <QString>

class PathUtils
{
public:
    PathUtils();

    static QString getStartPath();
    static void setStartPath(const QString &value);

    static QString makeFromStartPath(const QString &path);
    static void replaceFromStartPath(QString &path);

private:
    static QString startPath;
};

#endif // PATHUTILS_H
