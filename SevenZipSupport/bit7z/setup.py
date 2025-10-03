from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import pybind11
import sys
import os

# 获取bit7z路径
bit7z_include = "include/bit7z"
bit7z_lib_dir = "lib/x64/Release" if sys.platform == "win32" else "bit7z/lib"

# 编译参数
compile_args = []
link_args = []
if sys.platform == "win32":
    compile_args = ["/std:c++17", "/O2", "/W4"]
    link_args = [f"{bit7z_lib_dir}/bit7z.lib"]
else:
    compile_args = ["-std=c++17", "-O3", "-Wall", "-Wextra", "-fPIC"]
    link_args = [f"{bit7z_lib_dir}/libbit7z.a"]

# 定义扩展模块
ext_modules = [
    Extension(
        "pybit7z",
        ["pybit7z.cpp"],
        include_dirs=[
            bit7z_include,
            pybind11.get_include(),
        ],
        library_dirs=[bit7z_lib_dir],
        extra_compile_args=compile_args,
        extra_link_args=link_args,
        language="c++",
    ),
]

setup(
    name="pybit7z",
    ext_modules=ext_modules,
    zip_safe=False,
    python_requires=">=3.6",
)