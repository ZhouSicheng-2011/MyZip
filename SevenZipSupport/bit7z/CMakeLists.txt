cmake_minimum_required(VERSION 3.15)
project(pybit7z)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 在Windows上设置动态链接库的扩展名
if(WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif()

# 查找Python和pybind11
find_package(Python REQUIRED COMPONENTS Development Interpreter)

# 查找pybind11（三种方法，按优先级排序）
# 方法1：如果pybind11在项目子目录中
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/pybind11/CMakeLists.txt")
    add_subdirectory(pybind11)
    message(STATUS "Using pybind11 from subdirectory")
# 方法2：如果系统安装了pybind11
elseif(NOT pybind11_FOUND)
    find_package(pybind11 REQUIRED)
    if(pybind11_FOUND)
        message(STATUS "Using system pybind11")
    endif()
# 方法3：通过Python包管理器安装的pybind11
else()
    execute_process(
        COMMAND ${Python_EXECUTABLE} -c "import pybind11; print(pybind11.get_cmake_dir())"
        OUTPUT_VARIABLE pybind11_DIR
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    find_package(pybind11 REQUIRED)
    message(STATUS "Using pybind11 from Python package: ${pybind11_DIR}")
endif()

# 设置bit7z路径
set(BIT7Z_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bit7z/include")
set(BIT7Z_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bit7z/lib/x64/Release")  # Windows
if(UNIX)
    set(BIT7Z_LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/bit7z/lib")  # Linux/macOS
endif()

# 检查bit7z库是否存在
if(NOT EXISTS "${BIT7Z_LIB_DIR}/bit7z.lib" AND NOT EXISTS "${BIT7Z_LIB_DIR}/libbit7z.a")
    message(WARNING "bit7z library not found at ${BIT7Z_LIB_DIR}")
endif()

# 创建Python模块
pybind11_add_module(pybit7z
    pybit7z.cpp
)

# 包含目录
target_include_directories(pybit7z PRIVATE
    ${BIT7Z_INCLUDE_DIR}
)

# 链接库
if(WIN32)
    target_link_libraries(pybit7z PRIVATE
        "${BIT7Z_LIB_DIR}/bit7z.lib"
    )
else()
    target_link_libraries(pybit7z PRIVATE
        "${BIT7Z_LIB_DIR}/libbit7z.a"
    )
endif()

# 编译选项
if(MSVC)
    target_compile_options(pybit7z PRIVATE /W4 /WX)
else()
    target_compile_options(pybit7z PRIVATE -Wall -Wextra -Wpedantic)
endif()

# 设置输出目录
set_target_properties(pybit7z PROPERTIES
    OUTPUT_NAME "pybit7z"
    SUFFIX "${PYBIND11_EXTENSION_SUFFIX}"
)

# 安装目标（可选）
if(UNIX)
    install(TARGETS pybit7z DESTINATION lib)
endif()

message(STATUS "Python executable: ${Python_EXECUTABLE}")
message(STATUS "Python include dirs: ${Python_INCLUDE_DIRS}")
message(STATUS "Python library: ${Python_LIBRARIES}")