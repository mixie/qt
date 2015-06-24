#include "filehelper.h"
#include <QFile>
#include <QStringList>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
#include <QDir>
#include <QString>
using namespace std;

static QString initpath="data/init.csv";
static QString path="data/";

FileHelper::FileHelper()
{

}

FileHelper::~FileHelper()
{

}

QList<Patient>FileHelper::getPatients(){
    QFile fr(initpath);
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
    return patients;
}

void FileHelper::getPatientDeviations(QString filename,QString patientName,QList<PictureDeviation *> & picture_dev){
    QFile fr(path+filename+".csv");
    if(!(fr.open(QIODevice::ReadOnly))){
        QMessageBox::information(0, "error", "Nepodarilo sa otvoriť súbor s údajmi pacienta");
    }
    QTextStream in(&fr);
  //  picture_dev.clear();
    if(!in.atEnd()){
         QString line = in.readLine();
         if(patientName!=line){
             QMessageBox::information(0, "error", "Meno pacienta sa nezhoduje, previedli ste zly import.");
         }
    }
    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(",");
        picture_dev.append(new PictureDeviation(fields.takeFirst().toDouble(),fields.takeLast().toInt()));
    }
    fr.close();
}

void FileHelper::addPatientDeviationToFile(PictureDeviation pd,QString filename){
    QFile fw(path+filename+".csv");
    if(!(fw.open(QIODevice::Append))){
        QMessageBox::information(0, "error", "Nepodarilo sa otvoriť súbor s údajmi pacienta");
    }
    QString line=QString::number(pd.deviation)+","+QString::number(pd.count)+"\n";
    QTextStream str(&fw);
    str <<line;
    str.flush();
 //   fw.write(line.toStdString().data(), qstrlen(line.toStdString().data()));
    fw.close();
}

void FileHelper::addPatientOverallDevToFIle(PictureDeviation pd,QString filename){
    QFile fw(path+filename+"_sum.csv");
    if(!(fw.open(QIODevice::WriteOnly))){
        QMessageBox::information(0, "error", "Nepodarilo sa otvoriť súbor s údajmi pacienta");
    }
    QString line=QString::number(pd.deviation)+","+QString::number(pd.count)+"\n";
    QTextStream str(&fw);
    str <<line;
    str.flush();
  //  fw.write(line.toStdString().data(), qstrlen(line.toStdString().data()));
    fw.close();
}

void FileHelper::createNewPatient(QString patientName,QString filename){
    QFile fw(path+filename+".csv");
    if(!(fw.open(QIODevice::WriteOnly))){
        QMessageBox::information(0, "error", "Nepodarilo sa vytvoriť súbor s údajmi pacienta");
    }
    QString line=patientName+"\n";
   // fw.write(line.toStdString().data(), qstrlen(line.toStdString().data()));
    QTextStream str(&fw);
    str <<line;
    str.flush();
    fw.close();
    QFile fa(initpath);
    if(!(fa.open(QIODevice::Append))){
        QMessageBox::information(0, "error", "Nepodarilo sa otvoriť inicializačný súbor");
    }
    line=filename+","+patientName+"\n";
    QTextStream str2(&fw);
    str2 <<line;
    str2.flush();
   // fa.write(line.toStdString().data(), qstrlen(line.toStdString().data()));
    fa.close();
}

void FileHelper::addPatientDataToFile(vector<int> columns, QString filename){
    QFile fw(path+filename+"col.csv");
    if(!(fw.open(QIODevice::Append))){
        QMessageBox::information(0, "error", "Nepodarilo sa otvoriť súbor s údajmi pacienta");
    }
    QString line;
    for(int i=0;i<columns.size();i++){
        line.append(QString::number(columns[i]));
        if(i<columns.size()-1){
            line.append(",");
        }else{
            line.append("\n");
        }
    }
    QTextStream str(&fw);
    str <<line;
    str.flush();
    fw.close();
}

//void FileHelper::saveToPgm()
