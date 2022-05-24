#include "io/file.h"

File::File()
{
    _s_file = "";
}

File::File(const std::string &file, bool trunc)
{
    Open(file, trunc);
}

File::~File()
{
    Close();
}

bool File::Open(const std::string &file, bool trunc)
{
    _s_file = file;

    Close();

    if (trunc) {
        _file.open(_s_file, std::fstream::in
                   | std::fstream::out
                   | std::fstream::binary
                   | std::fstream::trunc);
    } else {
        _file.open(_s_file, std::fstream::in
                   | std::fstream::out
                   | std::fstream::binary);
    }

    return IsOpen();
}

void File::Close()
{
    if (_file.is_open())
        _file.close();
}

bool File::IsOpen() const
{
    return _file.is_open();
}

size_t File::GetSize() const
{
    std::ifstream in(_s_file, std::ios::binary | std::ios::ate);
    return (in.good() ? static_cast<size_t>(in.tellg()) : 0);
}

bool File::Read(std::vector<char> &data) const
{
    size_t size = GetSize();

    data.reserve(size);
    data.resize(size);

    return Read(&data[0], size);
}

bool File::Read(char *data, std::size_t length) const
{
    if (IsOpen() && _file.good()) {
        _file.read(data, length);
        _file.seekg(0, std::ios::beg);
        return !_file.fail();
    }

    return false;
}

bool File::Write(const std::vector<char> &data, bool append,
                 bool create_if_nexists)
{
    return Write(&data[0], data.size(), append, create_if_nexists);
}

bool File::Write(const char* data, size_t length, bool append,
                 bool create_if_nexists)
{
    // Try to create a new file if one doesn't exist.
    if ((!IsOpen() || !_file.good()) && create_if_nexists)
        Open(_s_file, true);
    
    // Write to the file
    if (IsOpen() && _file.good()) {
        if (append)
            // Set pointer to the file so we can append on the end of it
            _file.seekp(0, std::ios::end);
        
        // Write the buffer to the file
        _file.write(data, length);
        _file.flush();

        // Set pointer back to beginning
        _file.seekp(0, std::ios::beg);

        return (!_file.fail());
    }

    return false;
}
