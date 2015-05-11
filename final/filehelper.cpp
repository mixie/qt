#include "filehelper.h"
#include <QFile>
#include <QStringList>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QDir>
using namespace std;

static QString initpath="../final/data/init.csv";

FileHelper::FileHelper()
{

}

FileHelper::~FileHelper()
{

}

QList<Patient>FileHelper::getPatients(){
    QFile fr(initpath);
    QDir dir;
    if(!(fr.open(QIODevice::ReadOnly))){
        QMessageBox::information(0, "error", "Neexistuje inicializačný súbor (data/init.csv)");
    }
    QTextStream in(&fr);
    QList<Patient>patients;
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        patients.append(Patient(fields.takeFirst(),fields.takeLast()));
    }
    fr.close();
    cout << patients.size()<< patients[0].filename.toStdString();
    return patients;
}
