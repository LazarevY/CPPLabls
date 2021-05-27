#include "dataparsing.h"
#include <string>
#include <QDebug>

nlohmann::json DataParsing::readFile(const QString &fileName)
{
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);

    std::string data = file.readAll().toStdString();
    file.close();

    nlohmann::json json = nlohmann::json::parse(data);
    return json;
}

void DataParsing::fillCaseTableFromJson(CaseTable &table, const nlohmann::json &json)
{

    QMap<std::string, Case> cases =
    {
        {"nominative", Case::Nominative},
        {"genetive", Case::Genitive},
        {"dative", Case::Dative},
        {"accusative", Case::Accusative},
        {"creative", Case::Creative},
        {"prepositional", Case::Prepositional},
    };

    for (auto it = json.begin(); it != json.end(); ++it){
        nlohmann::json v = it.value();
        WordCases c;
        for (auto kv = cases.begin(); kv != cases.end(); ++kv){
            if (v.find(kv.key()) != v.end()){
                c[kv.value()] = QString(v[kv.key()].get<std::string>().data());
            }
        }
        table.setCases(c);
    }
}

void DataParsing::fillCaseTableFromFile(CaseTable &table, const QString &fileName)
{
    fillCaseTableFromJson(table, readFile(fileName));
}
