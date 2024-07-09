//
// Created by Hyeonjun on 2024-05-25.
// Name: Hyeonjun Son
// Email: hson15@myseneca.ca
// Student ID: 123526238

#ifndef SENECA_FILE_H_
#define SENECA_FILE_H_
namespace seneca {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
   // TODO: Declare read prototypes
   bool read(char* name);
   bool read(int* empNo);
   bool read(double* salary);

}
#endif // !SENECA_FILE_H_