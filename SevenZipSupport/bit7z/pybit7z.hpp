#ifndef PYBIT7Z_HPP
#define PYBIT7Z_HPP

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <pybind11/buffer.h>
#include <string>
#include <vector>
#include <memory>
#include <map>

#include "bit7z.hpp"
#include "bit7zlibrary.hpp"
#include "bitfilecompressor.hpp"
#include "bitfileextractor.hpp"
#include "bitmemcompressor.hpp"
#include "bitmemextractor.hpp"
#include "bitformat.hpp"
#include "bitcompressionlevel.hpp"
#include "bitcompressionmethod.hpp"
#include "bitarchiveiteminfo.hpp"

namespace py = pybind11;

class PyBit7z {
public:
    PyBit7z(const std::string& lib_path = "");
    ~PyBit7z();

    // 压缩方法
    void compress_files(const std::string& archive_path, 
                       const std::vector<std::string>& files,
                       const std::string& format = "zip",
                       const std::string& password = "",
                       int compression_level = 5,
                       const std::string& compression_method = "default");

    void compress_directory(const std::string& archive_path,
                           const std::string& directory_path,
                           const std::string& format = "zip",
                           const std::string& password = "",
                           int compression_level = 5,
                           const std::string& compression_method = "default");

    py::bytes compress_data(const py::buffer& data,
                           const std::string& archive_name,
                           const std::string& format = "zip",
                           const std::string& password = "",
                           int compression_level = 5,
                           const std::string& compression_method = "default");

    // 解压方法
    void extract_all(const std::string& archive_path,
                    const std::string& output_dir = "",
                    const std::string& password = "");

    py::bytes extract_file(const std::string& archive_path,
                          const std::string& file_in_archive,
                          const std::string& password = "");

    std::vector<std::string> list_files(const std::string& archive_path,
                                       const std::string& password = "");

    py::dict get_file_info(const std::string& archive_path,
                          const std::string& file_in_archive,
                          const std::string& password = "");

    // 测试方法
    bool test_archive(const std::string& archive_path,
                     const std::string& password = "");

private:
    std::unique_ptr<bit7z::Bit7zLibrary> library_;
    
    bit7z::BitFormat get_format(const std::string& format);
    bit7z::BitCompressionLevel get_compression_level(int level);
    bit7z::BitCompressionMethod get_compression_method(const std::string& method);
};

// ZipFile 类 - 类似Python zipfile.ZipFile的接口
class PyZipFile {
public:
    PyZipFile(const std::string& filename, 
              const std::string& mode = "r",
              const std::string& compression = "zip",
              int compresslevel = 5,
              const std::string& password = "");
    
    ~PyZipFile();

    // 类似zipfile的方法
    void close();
    py::list namelist();
    py::dict getinfo(const std::string& name);
    py::list infolist();
    py::bytes read(const std::string& name, const std::string& password = "");
    void extract(const std::string& member, const std::string& path = "", const std::string& password = "");
    void extractall(const std::string& path = "", const std::string& password = "");
    void write(const std::string& filename, const std::string& arcname = "", const std::string& compress_type = "");
    void writestr(const std::string& arcname, const py::buffer& data, const std::string& compress_type = "");
    
    bool testzip();
    void setpassword(const std::string& password);
    std::string getfilename();
    std::string getmode();

private:
    std::string filename_;
    std::string mode_;
    std::string password_;
    std::unique_ptr<PyBit7z> bit7z_;
    std::vector<std::string> file_list_;
    std::map<std::string, py::dict> file_info_cache_;
    
    bool is_open_;
    bool for_reading_;
    bool for_writing_;
    
    void load_file_list();
    py::dict archive_item_to_dict(const bit7z::BitArchiveItemInfo& item);
};

#endif // PYBIT7Z_HPP