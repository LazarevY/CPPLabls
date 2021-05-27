#ifndef DATAPARSING_H
#define DATAPARSING_H

#include <QFile>
#include <QString>
#include "3rdparty/nlohmann/json.hpp"

#include "Logic/casetable.h"

namespace DataParsing
{
    nlohmann::json readFile(const QString &fileName);
    void fillCaseTableFromFile(CaseTable &table, const QString &fileName);
    void fillCaseTableFromJson(CaseTable &table, const nlohmann::json &json);

};

#endif // DATAPARSING_H
