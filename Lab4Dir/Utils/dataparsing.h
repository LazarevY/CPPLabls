#ifndef DATAPARSING_H
#define DATAPARSING_H

#include <QFile>
#include <QString>
#include "3rdparty/nlohmann/json.hpp"

#include "Logic/casetable.h"
#include "Logic/caselist.h"

namespace DataParsing
{
    nlohmann::json readFile(const QString &fileName);
    void fillCaseTableFromFile(CaseTable &table, const QString &fileName);
    bool fillCaseTableFromJson(CaseTable &table, const nlohmann::json &json);
    void readCaseList(CaseList &lst, const QString &fileName);

};

#endif // DATAPARSING_H
