#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "patient.h"
#include <QFile>


class FileHelper
{
public:
    FileHelper();
    ~FileHelper();
    static QList<Patient> getPatients();
    static QFile processPicture();
    static void saveToPgm();
};

#endif // FILEHELPER_H
