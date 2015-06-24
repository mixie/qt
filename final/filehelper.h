#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "patient.h"
#include "picturedeviation.h"
#include <QFile>
#include <QPixmap>
#include <vector>

using namespace std;

class FileHelper
{
public:
    FileHelper();
    ~FileHelper();
    static QList<Patient> getPatients();
    static QFile processPicture();
    static void saveToPgm(QPixmap im);
    static void getPatientDeviations(QString filename,QString patientName,QList<PictureDeviation*> &);
    static void addPatientDeviationToFile(PictureDeviation pd,QString filename);
    static void addPatientOverallDevToFIle(PictureDeviation pd,QString filename);
    static void addPatientDataToFile(vector<int> columns,QString filename);
    static void createNewPatient(QString patientName,QString filename);
};

#endif // FILEHELPER_H
