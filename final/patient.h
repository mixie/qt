#ifndef PATIENT_H
#define PATIENT_H
#include<QString>


class Patient
{
public:
    Patient(QString _name, QString _filename);
    Patient();
    ~Patient();
    QString name;
    QString filename;
};

#endif // PATIENT_H
