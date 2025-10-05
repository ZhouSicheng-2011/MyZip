import tkinter as tk
from tkinter import ttk

import abc

import picture

class BaseFileCreator(abc.ABC):
    def __init__(self, parent:tk.Tk):
        self.window = tk.Toplevel(parent)
        self.window.title('创建压缩文件')
        self.window.geometry('800x500')
        self.window.resizable(False, False)

        self.window.transient(parent)