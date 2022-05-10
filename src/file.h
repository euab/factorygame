#ifndef FILE_H
#define FILE_H

#include <string>
#include <vector>
#include <cstring>
#include <fstream>

class File
{
public:
    File();
    File(const std::string &file, bool trunc = false);
    ~File();

    bool Open(const std::string &file, bool trunc = false);
    void Close();

    bool Read(std::vector<char> &data) const;
    bool Read(char *data, std::size_t length) const;

    bool Write(const std::vector<char> &data, bool append = false,
        bool create_if_nexists = false);
    bool Write(const char* data, std::size_t length, bool append = false,
        bool create_if_nexists = false);

    bool IsOpen() const;
    std::size_t GetSize() const;

private:
    std::string _s_file;
    mutable std::fstream _file;
};

#endif // FILE_H