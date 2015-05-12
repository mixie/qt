#ifndef FILEHELPER_H
#define FILEHELPER_H
#include "patient.h"
#include <QFile>
#include <QPixmap>


class FileHelper
{
public:
    FileHelper();
    ~FileHelper();
    static QList<Patient> getPatients();
    static QFile processPicture();
    static void saveToPgm(QPixmap im);
};

#endif // FILEHELPER_H
