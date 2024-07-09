//
// Created by Hyeonjun son on 2024-07-06.
// Name: Hyeonjunson
// Email: hson15@myseneca.ca
// Student ID: 123526238

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "TextFile.h"

using namespace std;
namespace seneca {
    Line::operator const char *() const {
        return (const char *) m_value;
    }

    Line &Line::operator=(const char *lineValue) {
        if (m_value != nullptr) {
            delete[] m_value;
        }
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
        return *this;
    }

    Line::Line() {
        m_value = nullptr;
    }

    Line::~Line() {
        if (m_value != nullptr) {
            delete[] m_value;
            m_value = nullptr;
        }
    }

    void TextFile::setEmpty() {
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        m_noOfLines = 0;
    }

   
    void TextFile::setFilename(const char *fname, bool isCopy) {
        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        if (!isCopy) {
            m_filename = new char[strlen(fname) + 1];
            m_filename = strcpy(m_filename, fname);
        } else {
            m_filename = new char[strlen(fname) + 3];
            strcpy(m_filename, "C_");
            strcat(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        ifstream file(m_filename);
        if (file.is_open()) {
            while (!file.eof()) {
                if (file.get() == '\n')
                    m_noOfLines++;
            }
            m_noOfLines++;
            file.close();
        }
        if (m_noOfLines == 0) {
            setEmpty();
        }
    }

    void TextFile::loadText() {
        if (m_filename == nullptr)
            return;

        // To prevent memory leak
        if (m_textLines != nullptr)
            delete[] m_textLines;

        m_textLines = new Line[m_noOfLines];

        ifstream file(m_filename);
        if (file.is_open()) {
            string str;
            int index = 0;
            while (getline(file, str)) {
                m_textLines[index] = str.c_str();
                index++;
            }
            m_noOfLines = index + 1;
            file.close();
        }
    }

    void TextFile::saveAs(const char *fileName) const {
        ofstream file(fileName);

        if (file.is_open()) {
            unsigned i = 0;
            for (i = 0; i < m_noOfLines - 1; i++) {
                file << m_textLines[i].m_value << '\n';
            }
            file.close();
        }
    }
  
    TextFile::TextFile(unsigned int pageSize) {
        setEmpty();
        m_pageSize = pageSize;
    }

  
    TextFile::TextFile(const char *filename, unsigned int pageSize) {
        m_pageSize = pageSize;
        setEmpty();
        if (filename != nullptr && filename[0] != '\0') {
            setFilename(filename, false);
            setNoOfLines();
            loadText();
        }
    }


    TextFile::TextFile(const TextFile &textFile) {
        if (!textFile)
            return;

        setEmpty();
        m_pageSize = textFile.m_pageSize;

        // Set file to copy
        setFilename(textFile.name());
        setNoOfLines();
        loadText();

        // Set file to be copied
        setFilename(textFile.name(), true);
        saveAs(m_filename);
        setNoOfLines();
        loadText();
    }

    TextFile &TextFile::operator=(const TextFile &textFile) {
        if (*this && textFile) {
            char *originalFileName = new char[strlen(m_filename) + 1];
            strcpy(originalFileName, m_filename);

            setEmpty();
            m_pageSize = textFile.m_pageSize;

            // set file to copy
            setFilename(textFile.name());
            setNoOfLines();
            loadText();

            // Set file to be copied
            setFilename(originalFileName);
            saveAs(m_filename);
            setNoOfLines();
            loadText();

            delete[] originalFileName;
        }
        return *this;
    }


    TextFile::~TextFile() {
        if (m_textLines != nullptr) {
            delete[] m_textLines;
            m_textLines = nullptr;
        }

        if (m_filename != nullptr) {
            delete[] m_filename;
            m_filename = nullptr;
        }

    }


    unsigned TextFile::lines() const {
        return m_noOfLines;
    }


    std::ostream &TextFile::view(ostream &ostr) const {
        if (!(*this))
            return ostr;

        ostr << m_filename << endl;
        ostr << "==========" << endl;

        unsigned i = 0;
        unsigned page = 0;
        bool isFinish = false;

        while (page < (m_noOfLines / m_pageSize) + 1) {
            if (!isFinish) {
                for (i = 0; i < m_pageSize; i++) {
                    if (i + (page * m_pageSize) >= m_noOfLines - 1) {
                        isFinish = true;
                        break;
                    }

                    ostr << m_textLines[i + (page * m_pageSize)].m_value << endl;
                }

                if (!isFinish) {
                    ostr << "Hit ENTER to continue...";

                    // Clean the input buffer
                    char ch = 'x';
                    while(ch != '\n') {
                        ch = getchar();
                    }

                    // Input enter
                    char cstr[3];
                    scanf("%[^\n]", cstr);
                }
            }
            ++page;
        }
        return ostr;
    }


    std::istream &TextFile::getFile(istream &istr) {
        setEmpty();
        char buffer[100];
        istr >> buffer;
        setFilename(buffer);
        setNoOfLines();
        loadText();
        return istr;
    }

 
    const char *TextFile::operator[](unsigned int index) const {
        return !(*this) ? nullptr : m_textLines[index % (m_noOfLines - 1)].m_value;
    }

  
    TextFile::operator bool() const {
        return m_textLines != nullptr && m_filename != nullptr && m_noOfLines != 0;
    }

   
    const char *TextFile::name() const {
        return m_filename;
    }

  
    std::ostream &operator<<(std::ostream &ostr, const TextFile &text) {
        return text.view(ostr);
    }

  
    std::istream &operator>>(std::istream &istr, TextFile &text) {
        return text.getFile(istr);
    }
}