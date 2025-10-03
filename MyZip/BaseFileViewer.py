import tkinter as tk
from tkinter import ttk
import ttkthemes

import abc

import picture

class BaseFileViewer(abc.ABC):
    def __init__(self, parent):
        self.frame = ttk.Frame(parent)
        self.setup_ui()
        self.archive = ''
        self.fn_list = []
        self.dn_set = set()
        self.fp_info = dict()
        self.folder_icon = picture.FOLDER_PNG
        self.file_icon = picture.FILE_PNG
    
    def setup_ui(self):
        #创建父目录显示
        self.parent_dir_area = ttk.Frame(self.frame)
        #创建表格
        self.file_table = ttk.Treeview(self.frame, columns=('文件名', '压缩前大小', '压缩后大小',\
                                                            '压缩率', '修改日期', 'CRC32校验值',\
                                                            '压缩方式/算法'),\
                                                            show='headings')
        self.file_table.column('文件名', width=500, anchor='w')
        self.file_table.column('压缩前大小', width=80, anchor='center')
        self.file_table.column('压缩后大小', width=80, anchor='center')
        self.file_table.column('压缩率', width=60, anchor='center')
        self.file_table.column('修改日期', width=180, anchor='center')
        self.file_table.column('CRC32校验值', width=100, anchor='center')
        self.file_table.column('压缩方式/算法', width=100, anchor='center')
        #创建滚动条
        self.scr_vertical = ttk.Scrollbar(self.frame, orient='vertical', command=self.file_table.yview)
        self.scr_horizontal = ttk.Scrollbar(self.frame, orient='horizontal', command=self.file_table.xview)
        #配置表格滚动条
        self.file_table.configure(xscrollcommand=self.scr_horizontal.set,\
                                  yscrollcommand=self.scr_vertical.set)
        #文件显示区域放置
        self.file_table.grid(column=0, row=1, sticky='nsew')
        self.scr_horizontal.grid(column=0, row=2, sticky='ew')
        self.scr_vertical.grid(column=1, row=1, sticky='ns')
        ##
        ##
        #设置状态显示区
        self.status_area = ttk.Frame(self.frame)
        self.status_area.grid(column=0, row=3, columnspan=2, sticky='ew')
        #设置状态
        self.status_var = tk.StringVar(value='UI就绪')
        self.status_label = ttk.Label(self.status_area, textvariable=self.status_var, width=20)
        self.status_label.grid(column=0, row=0)
        #设置加载进度条
        self.load_progress_bar = ttk.Progressbar(self.status_area, mode='determinate')
        self.load_progress_bar.grid(column=1, row=0)

    @abc.abstractmethod
    def analysis_archive(self) -> tuple[list[str], set[str], dict[str, tuple]]:
        '''用于解析压缩文件, 返回值为元组, 依次包含以下内容:
            文件名列表: 其中list型的数据
            目录名集合: 其中set型数据
            文件信息: 其中dict型数据'''
        pass

    def open(self, archive_path:str):
        '''用于打开压缩文件并设置UI显示'''
        self.archive = archive_path
        data = self.analysis_archive()
        self.fn_list = data[0]
        self.dn_set = data[1]
        self.fp_info = data[2]

    def show_update(self, dirs:list[tuple[str]], files:list[tuple[str]]):
        '''用于刷新表格显示, 参数:
            dirs: 所有目录信息的元组
            files: 所有文件信息的元组'''
        try:
            self.file_table.delete(*self.file_table.get_children())
        except:
            pass
        
        for d in dirs:
            self.file_table.insert("", "end", values=d, image=self.folder_icon)
        
        for f in files:
            self.file_table.insert("", "end", values=f, image=self.file_icon)