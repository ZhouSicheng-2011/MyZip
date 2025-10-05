import tkinter as tk
from tkinter import ttk
from tkinter import messagebox

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
        self.last_dir = ''

        self.folder_icon = picture.FOLDER_PNG
        self.file_icon = picture.FILE_PNG
        self.last_icon = picture.LAST_PNG
    
    def setup_ui(self):
        #创建父目录显示
        self.parent_dir_area = ttk.Frame(self.frame)
        self.parent_dir_area.grid(column=0, columnspan=2, row=0, sticky='ew')
        #创建上一级目录按钮
        self.last_btn = ttk.Button(self.parent_dir_area, image=self.last_icon, command=self.last)
        self.last_btn.grid(column=0, row=0)
        #创建当前目录显示
        self.now_dir = tk.StringVar(value='')
        self.now_dir_label = ttk.Label(self.parent_dir_area, textvariable=self.now_dir, width=80)
        self.now_dir_label.grid(column=1, row=0)
        ##
        ##
        #创建表格
        self.file_table = ttk.Treeview(self.frame, columns=('文件名/目录名', '压缩前大小', '压缩后大小',\
                                                            '压缩率', '修改日期', 'CRC32校验值',\
                                                            '压缩方式/算法'),\
                                                            show='headings')
        self.file_table.column('文件名/目录名', width=500, anchor='w')
        self.file_table.column('压缩前大小', width=80, anchor='center')
        self.file_table.column('压缩后大小', width=80, anchor='center')
        self.file_table.column('压缩率', width=60, anchor='center')
        self.file_table.column('修改日期', width=180, anchor='center')
        self.file_table.column('CRC32校验值', width=100, anchor='center')
        self.file_table.column('压缩方式/算法', width=100, anchor='center')

        self.file_table.bind('Double-1', self.next)
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
        ...

    @abc.abstractmethod
    def analysis_archive(self) -> tuple[list[str], set[str], dict[str, tuple]]:
        '''用于解析压缩文件, 返回值为元组, 依次包含以下内容:
            文件名列表: 其中list型的数据
            目录名集合: 其中set型数据
            文件信息: 其中dict型数据'''
        pass

    def open(self, archive_path:str):
        '''用于打开压缩文件并设置初始UI显示'''
        self.archive = archive_path
        self.status_var.set('正在解析文件...')
        data = self.analysis_archive()
        self.fn_list = data[0]
        self.dn_set = data[1]
        self.fp_info = data[2]

        self.status_var.set('正在初始化文件显示...')        
        initial_files, initial_dirs = self.find_fd_in_one_dir('')
        ifwi = [(f,)+self.fp_info.get(f, tuple()) for f in initial_files] #ifwi是initial file with information的缩写
        idwi = [(d,)+self.fp_info.get(d, tuple()) for d in initial_dirs] #idwi是initial directory with information的缩写
        
        self.show_update(idwi, ifwi, '')

    def show_update(self, dirs:list[tuple[str]], files:list[tuple[str]], now_dir:str):
        '''用于刷新表格显示, 参数:
            dirs: 包含所有目录信息的元组组成的列表
            files: 包含所有文件信息的元组组成的列表'''
        try:
            self.file_table.delete(*self.file_table.get_children())
        except:
            pass
        
        for d in dirs:
            self.file_table.insert("", "end", values=d, image=self.folder_icon)
        
        for f in files:
            self.file_table.insert("", "end", values=f, image=self.file_icon)

        self.now_dir.set(now_dir)

    def last(self):
        if self.now_dir.get() == '':
            messagebox.showerror('错误', '压缩文件当前显示目录没有上一级目录了!')
        else:
            target_dir = '/'.join(self.now_dir.get().split('/')[:-1])
            self.get_fd_and_info_and_update(target_dir)

    def find_fd_in_one_dir(self, target_dir:str):
        '''寻找在压缩文件里在同一个目录下的文件和目录'''
        num = target_dir.count('/')
        files = [k for k in self.fn_list if k.startswith(target_dir) and k.count('/')==num]
        dirs = [p for p in self.dn_set if p.startswith(target_dir) and p.count('/')==num+1]
        return tuple(files), tuple(dirs)
    
    def get_fd_and_info_and_update(self, path:str):
        self.status_var.set('正在加载文件与信息...')
        files, dirs = self.find_fd_in_one_dir(path)
        fwi = [(f,)+self.fp_info.get(f, tuple()) for f in files] #fwi是file with information的缩写
        dwi = [(d,)+self.fp_info.get(d, tuple()) for d in dirs] #dwi是directory with information的缩写

        self.show_update(fwi, dwi, path)

    def next(self, event):
        w = event.widget
        try:
            item_id = w.identify("item", event.x, event.y)
            filename = w.item(item_id, "values")[0]
        except:
            return
        
        if filename.endswith('/'):
            fn = f"{self.now_dir.get()}/{filename}" if self.now_dir.get() else filename
            self.get_fd_and_info_and_update(fn)
        else:
            fn = f"{self.now_dir.get()}/{filename}" if self.now_dir.get() else filename
            self.extract_file(fn)

    @abc.abstractmethod
    def extract_file(self, file:str):
        pass