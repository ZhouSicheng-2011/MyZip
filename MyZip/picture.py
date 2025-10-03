from PIL import Image, ImageTk

def load_image(image_path:str, size=(16,16)):
    img = Image.open(image_path)
    img = img.resize(size, Image.Resampling.LANCZOS)
    return ImageTk.PhotoImage(img)

FILE_PNG = load_image('./icons/file.png')
FILE_ICO = load_image('./icons/file.ico')

FOLDER_PNG = load_image('./icons/folder.png')
FOLDER_ICO = load_image('./icons/folder.ico')

LAST_PNG = load_image('./icons/last.png')