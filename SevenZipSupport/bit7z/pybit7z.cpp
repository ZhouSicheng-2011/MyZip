#include "pybit7z.hpp"
#include <filesystem>
#include <fstream>
#include <sstream>

namespace fs = std::filesystem;

// PyBit7z 实现
PyBit7z::PyBit7z(const std::string& lib_path) {
    try {
        if (lib_path.empty()) {
            library_ = std::make_unique<bit7z::Bit7zLibrary>();
        } else {
            library_ = std::make_unique<bit7z::Bit7zLibrary>(std::wstring(lib_path.begin(), lib_path.end()));
        }
    } catch (const bit7z::BitException& e) {
        throw py::value_error("Failed to initialize 7z library: " + std::string(e.what()));
    }
}

PyBit7z::~PyBit7z() {
    // 自动清理
}

bit7z::BitFormat PyBit7z::get_format(const std::string& format) {
    static std::map<std::string, bit7z::BitFormat> format_map = {
        {"7z", bit7z::BitFormat::SevenZip},
        {"zip", bit7z::BitFormat::Zip},
        {"gzip", bit7z::BitFormat::GZip},
        {"bzip2", bit7z::BitFormat::BZip2},
        {"rar", bit7z::BitFormat::Rar},
        {"tar", bit7z::BitFormat::Tar}
    };
    
    auto it = format_map.find(format);
    if (it != format_map.end()) {
        return it->second;
    }
    throw py::value_error("Unsupported format: " + format);
}

bit7z::BitCompressionLevel PyBit7z::get_compression_level(int level) {
    switch (level) {
        case 0: return bit7z::BitCompressionLevel::None;
        case 1: return bit7z::BitCompressionLevel::Fastest;
        case 5: return bit7z::BitCompressionLevel::Normal;
        case 7: return bit7z::BitCompressionLevel::Maximum;
        case 9: return bit7z::BitCompressionLevel::Ultra;
        default: return bit7z::BitCompressionLevel::Normal;
    }
}

bit7z::BitCompressionMethod PyBit7z::get_compression_method(const std::string& method) {
    static std::map<std::string, bit7z::BitCompressionMethod> method_map = {
        {"copy", bit7z::BitCompressionMethod::Copy},
        {"deflate", bit7z::BitCompressionMethod::Deflate},
        {"deflate64", bit7z::BitCompressionMethod::Deflate64},
        {"bzip2", bit7z::BitCompressionMethod::BZip2},
        {"lzma", bit7z::BitCompressionMethod::Lzma},
        {"lzma2", bit7z::BitCompressionMethod::Lzma2},
        {"default", bit7z::BitCompressionMethod::Default}
    };
    
    auto it = method_map.find(method);
    if (it != method_map.end()) {
        return it->second;
    }
    return bit7z::BitCompressionMethod::Default;
}

void PyBit7z::compress_files(const std::string& archive_path, 
                            const std::vector<std::string>& files,
                            const std::string& format,
                            const std::string& password,
                            int compression_level,
                            const std::string& compression_method) {
    try {
        bit7z::BitFileCompressor compressor(*library_, get_format(format));
        
        if (!password.empty()) {
            compressor.setPassword(std::wstring(password.begin(), password.end()));
        }
        
        compressor.setCompressionLevel(get_compression_level(compression_level));
        compressor.setCompressionMethod(get_compression_method(compression_method));
        
        std::vector<std::wstring> wfiles;
        for (const auto& file : files) {
            wfiles.push_back(std::wstring(file.begin(), file.end()));
        }
        
        compressor.compress(wfiles, std::wstring(archive_path.begin(), archive_path.end()));
        
    } catch (const bit7z::BitException& e) {
        throw py::value_error("Compression failed: " + std::string(e.what()));
    }
}

void PyBit7z::compress_directory(const std::string& archive_path,
                                const std::string& directory_path,
                                const std::string& format,
                                const std::string& password,
                                int compression_level,
                                const std::string& compression_method) {
    try {
        bit7z::BitFileCompressor compressor(*library_, get_format(format));
        
        if (!password.empty()) {
            compressor.setPassword(std::wstring(password.begin(), password.end()));
        }
        
        compressor.setCompressionLevel(get_compression_level(compression_level));
        compressor.setCompressionMethod(get_compression_method(compression_method));
        
        compressor.compressDirectory(std::wstring(directory_path.begin(), directory_path.end()),
                                   std::wstring(archive_path.begin(), archive_path.end()));
        
    } catch (const bit7z::BitException& e) {
        throw py::value_error("Directory compression failed: " + std::string(e.what()));
    }
}

py::bytes PyBit7z::compress_data(const py::buffer& data,
                                const std::string& archive_name,
                                const std::string& format,
                                const std::string& password,
                                int compression_level,
                                const std::string& compression_method) {
    try {
        py::buffer_info buf_info = data.request();
        if (buf_info.ndim != 1) {
            throw py::value_error("Buffer must be 1-dimensional");
        }
        
        const char* data_ptr = static_cast<const char*>(buf_info.ptr);
        size_t data_size = buf_info.size * buf_info.itemsize;
        
        std::vector<byte_t> buffer(data_ptr, data_ptr + data_size);
        
        bit7z::BitMemCompressor compressor(*library_, get_format(format));
        
        if (!password.empty()) {
            compressor.setPassword(std::wstring(password.begin(), password.end()));
        }
        
        compressor.setCompressionLevel(get_compression_level(compression_level));
        compressor.setCompressionMethod(get_compression_method(compression_method));
        
        std::vector<byte_t> compressed_data;
        compressor.compress(buffer, compressed_data, std::wstring(archive_name.begin(), archive_name.end()));
        
        return py::bytes(reinterpret_cast<const char*>(compressed_data.data()), compressed_data.size());
        
    } catch (const bit7z::BitException& e) {
        throw py::value_error("Data compression failed: " + std::string(e.what()));
    }
}

void PyBit7z::extract_all(const std::string& archive_path,
                         const std::string& output_dir,
                         const std::string& password) {
    try {
        bit7z::BitFileExtractor extractor(*library_, get_format("auto"));
        
        if (!password.empty()) {
            extractor.setPassword(std::wstring(password.begin(), password.end()));
        }
        
        std::wstring output = output_dir.empty() ? 
            fs::current_path().wstring() : 
            std::wstring(output_dir.begin(), output_dir.end());
            
        extractor.extract(std::wstring(archive_path.begin(), archive_path.end()), output);
        
    } catch (const bit7z::BitException& e) {
        throw py::value_error("Extraction failed: " + std::string(e.what()));
    }
}

py::bytes PyBit7z::extract_file(const std::string& archive_path,
                               const std::string& file_in_archive,
                               const std::string& password) {
    try {
        bit7z::BitMemExtractor extractor(*library_, get_format("auto"));
        
        if (!password.empty()) {
            extractor.setPassword(std::wstring(password.begin(), password.end()));
        }
        
        std::vector<byte_t> extracted_data;
        extractor.extract(std::wstring(archive_path.begin(), archive_path.end()),
                         extracted_data,
                         std::wstring(file_in_archive.begin(), file_in_archive.end()));
        
        return py::bytes(reinterpret_cast<const char*>(extracted_data.data()), extracted_data.size());
        
    } catch (const bit7z::BitException& e) {
        throw py::value_error("File extraction failed: " + std::string(e.what()));
    }
}

std::vector<std::string> PyBit7z::list_files(const std::string& archive_path,
                                            const std::string& password) {
    try {
        bit7z::BitFileExtractor extractor(*library_, get_format("auto"));
        
        if (!password.empty()) {
            extractor.setPassword(std::wstring(password.begin(), password.end()));
        }
        
        auto items = extractor.items(std::wstring(archive_path.begin(), archive_path.end()));
        std::vector<std::string> result;
        
        for (const auto& item : items) {
            std::wstring wname = item.name();
            result.push_back(std::string(wname.begin(), wname.end()));
        }
        
        return result;
        
    } catch (const bit7z::BitException& e) {
        throw py::value_error("Failed to list archive contents: " + std::string(e.what()));
    }
}

py::dict PyBit7z::get_file_info(const std::string& archive_path,
                               const std::string& file_in_archive,
                               const std::string& password) {
    try {
        bit7z::BitFileExtractor extractor(*library_, get_format("auto"));
        
        if (!password.empty()) {
            extractor.setPassword(std::wstring(password.begin(), password.end()));
        }
        
        auto items = extractor.items(std::wstring(archive_path.begin(), archive_path.end()));
        
        for (const auto& item : items) {
            std::wstring wname = item.name();
            std::string name(wname.begin(), wname.end());
            
            if (name == file_in_archive) {
                py::dict info;
                info["filename"] = name;
                info["file_size"] = static_cast<long long>(item.size());
                info["compress_size"] = static_cast<long long>(item.packSize());
                info["CRC"] = item.crc();
                
                // 转换时间
                auto time = item.time();
                // 这里可以添加时间转换逻辑
                
                return info;
            }
        }
        
        throw py::value_error("File not found in archive: " + file_in_archive);
        
    } catch (const bit7z::BitException& e) {
        throw py::value_error("Failed to get file info: " + std::string(e.what()));
    }
}

bool PyBit7z::test_archive(const std::string& archive_path,
                          const std::string& password) {
    try {
        bit7z::BitFileExtractor extractor(*library_, get_format("auto"));
        
        if (!password.empty()) {
            extractor.setPassword(std::wstring(password.begin(), password.end()));
        }
        
        extractor.test(std::wstring(archive_path.begin(), archive_path.end()));
        return true;
        
    } catch (const bit7z::BitException&) {
        return false;
    }
}

// PyZipFile 实现
PyZipFile::PyZipFile(const std::string& filename, 
                     const std::string& mode,
                     const std::string& compression,
                     int compresslevel,
                     const std::string& password)
    : filename_(filename), mode_(mode), password_(password), is_open_(true) {
    
    for_reading_ = (mode == "r" || mode == "a");
    for_writing_ = (mode == "w" || mode == "x" || mode == "a");
    
    bit7z_ = std::make_unique<PyBit7z>();
    
    if (for_reading_) {
        // 验证文件存在且可读
        if (!fs::exists(filename)) {
            if (mode == "r") {
                throw py::value_error("File does not exist: " + filename);
            }
        } else {
            load_file_list();
        }
    }
    
    if (for_writing_ && mode != "a" && fs::exists(filename)) {
        if (mode == "x") {
            throw py::value_error("File already exists: " + filename);
        } else if (mode == "w") {
            // 删除现有文件
            fs::remove(filename);
        }
    }
}

PyZipFile::~PyZipFile() {
    if (is_open_) {
        close();
    }
}

void PyZipFile::close() {
    if (!is_open_) {
        return;
    }
    
    file_list_.clear();
    file_info_cache_.clear();
    is_open_ = false;
}

void PyZipFile::load_file_list() {
    try {
        file_list_ = bit7z_->list_files(filename_, password_);
        
        // 预加载文件信息
        for (const auto& name : file_list_) {
            file_info_cache_[name] = bit7z_->get_file_info(filename_, name, password_);
        }
    } catch (const std::exception& e) {
        throw py::value_error("Failed to load archive contents: " + std::string(e.what()));
    }
}

py::list PyZipFile::namelist() {
    if (!is_open_) {
        throw py::value_error("ZipFile is closed");
    }
    
    if (!for_reading_) {
        throw py::value_error("Can't read from a write-only ZipFile");
    }
    
    py::list result;
    for (const auto& name : file_list_) {
        result.append(name);
    }
    return result;
}

py::dict PyZipFile::getinfo(const std::string& name) {
    if (!is_open_) {
        throw py::value_error("ZipFile is closed");
    }
    
    if (!for_reading_) {
        throw py::value_error("Can't read from a write-only ZipFile");
    }
    
    auto it = file_info_cache_.find(name);
    if (it == file_info_cache_.end()) {
        throw py::value_error("File not found in archive: " + name);
    }
    
    return it->second;
}

py::list PyZipFile::infolist() {
    if (!is_open_) {
        throw py::value_error("ZipFile is closed");
    }
    
    if (!for_reading_) {
        throw py::value_error("Can't read from a write-only ZipFile");
    }
    
    py::list result;
    for (const auto& name : file_list_) {
        result.append(file_info_cache_[name]);
    }
    return result;
}

py::bytes PyZipFile::read(const std::string& name, const std::string& password) {
    if (!is_open_) {
        throw py::value_error("ZipFile is closed");
    }
    
    if (!for_reading_) {
        throw py::value_error("Can't read from a write-only ZipFile");
    }
    
    std::string pwd = password.empty() ? password_ : password;
    return bit7z_->extract_file(filename_, name, pwd);
}

void PyZipFile::extract(const std::string& member, const std::string& path, const std::string& password) {
    if (!is_open_) {
        throw py::value_error("ZipFile is closed");
    }
    
    if (!for_reading_) {
        throw py::value_error("Can't extract from a write-only ZipFile");
    }
    
    // 这里简化实现，实际应该只解压单个文件
    std::string pwd = password.empty() ? password_ : password;
    std::vector<std::string> files = {member};
    // 注意：这里需要修改bit7z接口以支持单文件解压
    // 简化实现是解压全部然后移动目标文件
    std::string temp_dir = fs::temp_directory_path().string();
    bit7z_->extract_all(filename_, temp_dir, pwd);
    
    std::string source_path = temp_dir + "/" + member;
    std::string dest_path = path.empty() ? member : path + "/" + member;
    
    if (fs::exists(source_path)) {
        fs::create_directories(fs::path(dest_path).parent_path());
        fs::rename(source_path, dest_path);
    }
}

void PyZipFile::extractall(const std::string& path, const std::string& password) {
    if (!is_open_) {
        throw py::value_error("ZipFile is closed");
    }
    
    if (!for_reading_) {
        throw py::value_error("Can't extract from a write-only ZipFile");
    }
    
    std::string pwd = password.empty() ? password_ : password;
    bit7z_->extract_all(filename_, path, pwd);
}

void PyZipFile::write(const std::string& filename, const std::string& arcname, const std::string& compress_type) {
    if (!is_open_) {
        throw py::value_error("ZipFile is closed");
    }
    
    if (!for_writing_) {
        throw py::value_error("Can't write to a read-only ZipFile");
    }
    
    std::string target_name = arcname.empty() ? filename : arcname;
    std::vector<std::string> files = {filename};
    
    // 简化实现 - 实际应该追加到现有档案
    bit7z_->compress_files(filename_, files, "zip", password_, 5, "default");
    
    // 更新文件列表
    if (for_reading_) {
        load_file_list();
    }
}

void PyZipFile::writestr(const std::string& arcname, const py::buffer& data, const std::string& compress_type) {
    if (!is_open_) {
        throw py::value_error("ZipFile is closed");
    }
    
    if (!for_writing_) {
        throw py::value_error("Can't write to a read-only ZipFile");
    }
    
    // 简化实现 - 实际应该使用内存压缩并追加
    py::bytes compressed = bit7z_->compress_data(data, arcname, "zip", password_, 5, "default");
    
    // 这里需要将压缩数据写入档案
    // 由于bit7z的限制，这需要更复杂的实现
}

bool PyZipFile::testzip() {
    if (!is_open_) {
        throw py::value_error("ZipFile is closed");
    }
    
    if (!for_reading_) {
        throw py::value_error("Can't test a write-only ZipFile");
    }
    
    return bit7z_->test_archive(filename_, password_);
}

void PyZipFile::setpassword(const std::string& password) {
    password_ = password;
}

std::string PyZipFile::getfilename() {
    return filename_;
}

std::string PyZipFile::getmode() {
    return mode_;
}

// Pybind11 模块定义
PYBIND11_MODULE(pybit7z, m) {
    m.doc() = "Python binding for bit7z library using pybind11";
    
    // PyBit7z 类绑定
    py::class_<PyBit7z>(m, "Bit7z")
        .def(py::init<const std::string&>(), 
             py::arg("lib_path") = "")
        .def("compress_files", &PyBit7z::compress_files,
             py::arg("archive_path"),
             py::arg("files"),
             py::arg("format") = "zip",
             py::arg("password") = "",
             py::arg("compression_level") = 5,
             py::arg("compression_method") = "default")
        .def("compress_directory", &PyBit7z::compress_directory,
             py::arg("archive_path"),
             py::arg("directory_path"),
             py::arg("format") = "zip",
             py::arg("password") = "",
             py::arg("compression_level") = 5,
             py::arg("compression_method") = "default")
        .def("compress_data", &PyBit7z::compress_data,
             py::arg("data"),
             py::arg("archive_name"),
             py::arg("format") = "zip",
             py::arg("password") = "",
             py::arg("compression_level") = 5,
             py::arg("compression_method") = "default")
        .def("extract_all", &PyBit7z::extract_all,
             py::arg("archive_path"),
             py::arg("output_dir") = "",
             py::arg("password") = "")
        .def("extract_file", &PyBit7z::extract_file,
             py::arg("archive_path"),
             py::arg("file_in_archive"),
             py::arg("password") = "")
        .def("list_files", &PyBit7z::list_files,
             py::arg("archive_path"),
             py::arg("password") = "")
        .def("get_file_info", &PyBit7z::get_file_info,
             py::arg("archive_path"),
             py::arg("file_in_archive"),
             py::arg("password") = "")
        .def("test_archive", &PyBit7z::test_archive,
             py::arg("archive_path"),
             py::arg("password") = "");
    
    // PyZipFile 类绑定 - 类似Python zipfile接口
    py::class_<PyZipFile>(m, "ZipFile")
        .def(py::init<const std::string&, const std::string&, const std::string&, int, const std::string&>(),
             py::arg("filename"),
             py::arg("mode") = "r",
             py::arg("compression") = "zip",
             py::arg("compresslevel") = 5,
             py::arg("password") = "")
        .def("close", &PyZipFile::close)
        .def("namelist", &PyZipFile::namelist)
        .def("getinfo", &PyZipFile::getinfo)
        .def("infolist", &PyZipFile::infolist)
        .def("read", &PyZipFile::read,
             py::arg("name"),
             py::arg("password") = "")
        .def("extract", &PyZipFile::extract,
             py::arg("member"),
             py::arg("path") = "",
             py::arg("password") = "")
        .def("extractall", &PyZipFile::extractall,
             py::arg("path") = "",
             py::arg("password") = "")
        .def("write", &PyZipFile::write,
             py::arg("filename"),
             py::arg("arcname") = "",
             py::arg("compress_type") = "")
        .def("writestr", &PyZipFile::writestr,
             py::arg("arcname"),
             py::arg("data"),
             py::arg("compress_type") = "")
        .def("testzip", &PyZipFile::testzip)
        .def("setpassword", &PyZipFile::setpassword)
        .def("getfilename", &PyZipFile::getfilename)
        .def("getmode", &PyZipFile::getmode)
        .def("__enter__", [](PyZipFile &self) { return &self; })
        .def("__exit__", [](PyZipFile &self, py::args) { self.close(); });
    
    // 模块级别函数
    m.def("is_zipfile", [](const std::string& filename) {
        try {
            PyBit7z bit7z;
            return bit7z.test_archive(filename);
        } catch (...) {
            return false;
        }
    });
    
    // 定义一些常量
    m.attr("ZIP_STORED") = py::int_(0);
    m.attr("ZIP_DEFLATED") = py::int_(8);
    m.attr("ZIP_BZIP2") = py::int_(12);
    m.attr("ZIP_LZMA") = py::int_(14);
}