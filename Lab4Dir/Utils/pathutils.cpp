#include "pathutils.h"

QString PathUtils::startPath = "";

PathUtils::PathUtils()
{

}

QString PathUtils::getStartPath()
{
    return startPath;
}

void PathUtils::setStartPath(const QString &value)
{
    startPath = value;
}

QString PathUtils::makeFromStartPath(const QString &path)
{
    return QDir(startPath).filePath(path);
}

void PathUtils::replaceFromStartPath(QString &path)
{
    path = QDir(startPath).filePath(path);
}








