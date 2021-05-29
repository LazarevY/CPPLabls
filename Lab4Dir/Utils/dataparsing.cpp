#include "dataparsing.h"
#include <string>
#include <QDebug>
#include <QTextStream>
#include "appexception.h"

nlohmann::json DataParsing::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        throw AppException(QString("Can't open ") + fileName);
    }


    std::string data = file.readAll().toStdString();
    file.close();

    try {
        nlohmann::json json = nlohmann::json::parse(data);
        return json;
    } catch (nlohmann::json::exception &e) {
        throw e;
    }

    return nlohmann::json();
}

bool DataParsing::fillCaseTableFromJson(CaseTable &table, const nlohmann::json &json)
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

    try {
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
        return true;
    } catch (nlohmann::json::exception &e) {
        throw e;
    }
    return false;
}

void DataParsing::fillCaseTableFromFile(CaseTable &table, const QString &fileName)
{
    fillCaseTableFromJson(table, readFile(fileName));
}


void DataParsing::readCaseList(CaseList &lst, const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        throw AppException(QString("Can't open ") + fileName);
    }

    QTextStream in(&file);

    while (!in.atEnd()) {
        auto word = in.readLine().trimmed();
        lst.addCase(word);
    }

}
