#include "patient.h"
#include <iostream>

using namespace std;

Patient::Patient(QString _filename,QString _name)
{
     name=_name;
     filename=_filename;
}

Patient::Patient(){

}

Patient::~Patient()
{

}

