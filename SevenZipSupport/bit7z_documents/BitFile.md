# BitFileCompressor

*Oz edited this page on Sep 26, 2024 · 8 revisions*

---

`BitFileCompressor` 类允许压缩文件和目录。压缩的归档可以保存到文件系统、标准流或内存缓冲区。

`#include <bit7z/bitfilecompressor.hpp>`

继承自 **BitCompressor** < **const** **tstring & >**。

## 所有成员列表

### 公共成员

| 返回类型 | 名称 |
|---|---|
| `void` | `BitFileCompressor( const Bit7zlibrary& lib, const BitInOutFormat& format )` |
| `void` | `clearPassword() noexcept` |
| `void` | `compress( const std::map< tstring, tstring >& inPaths, const tstring& outFile ) const` |
| `void` | `compress( const std::map< tstring, tstring >& inPaths, std::ostream& outStream ) const` |
| `void` | `compress( const std::vector< tstring >& inPaths, const tstring& outFile ) const` |
| `void` | `compress( const std::vector< tstring >& inPaths, std::ostream& outStream ) const` |
| `void` | `compressDirectory( const tstring& inDir, const tstring& outFile ) const` |
| `void` | `compressDirectoryContents( const tstring& inDir, const tstring& outFile, bool recursive = true, const tstring& filter = "*" ) const` |
| `void` | `compressFile( const tstring& inFile, const tstring& outFile, const tstring& inputName = {} ) const` |
| `void` | `compressFile( const tstring& inFile, std::ostream& outStream, const tstring& inputName = {} ) const` |
| `void` | `compressFile( const tstring& inFile, std::vector< byte_t >& outBuffer, const tstring& inputName = {} ) const` |
| `void` | `compressFiles( const std::vector< tstring >& inFiles, const tstring& outFile ) const` |
| `void` | `compressFiles( const tstring& inDir, const tstring& outFile, bool recursive = true, const tstring& filter = "*" ) const` |
| `const BitInOutFormat&` | `compressionFormat() const noexcept` |
| `BitCompressionLevel` | `compressionLevel() const noexcept` |
| `BitCompressionMethod` | `compressionMethod() const noexcept` |
| `bool` | `cryptHeaders() const noexcept` |
| `uint32_t` | `dictionarySize() const noexcept` |
| `FileCallback` | `fileCallback() const` |
| `[virtual] const BitInFormat&` | `format() const noexcept` |
| `bool` | `isPasswordDefined() const noexcept` |
| `const Bit7zlibrary&` | `library() const noexcept` |
| `OverwriteMode` | `overwriteMode() const` |
| `tstring` | `password() const` |
| `PasswordCallback` | `passwordCallback() const` |
| `ProgressCallback` | `progressCallback() const` |
| `RatioCallback` | `ratioCallback() const` |
| `bool` | `retainDirectories() const noexcept` |
| `void` | `setCompressionLevel( BitCompressionLevel level ) noexcept` |
| `void` | `setCompressionMethod( BitCompressionMethod method )` |
| `void` | `setDictionarySize( uint32_t dictionarySize )` |
| `void` | `setFileCallback( const FileCallback& callback )` |
| `void` | `setFormatProperty( const wchar_t (&name)[N], const T& value ) noexcept` |
| `void` | `setFormatProperty( const wchar_t (&name)[N], T value ) noexcept` |
| `void` | `setOverwriteMode( OverwriteMode mode )` |
| `void` | `setPassword( const tstring& password ) override` |
| `void` | `setPassword( const tstring& password, bool cryptHeaders )` |
| `void` | `setPasswordCallback( const PasswordCallback& callback )` |
| `void` | `setProgressCallback( const ProgressCallback& callback )` |
| `void` | `setRatioCallback( const RatioCallback& callback )` |
| `void` | `setRetainDirectories( bool retain ) noexcept` |
| `void` | `setSolidMode( bool solidMode ) noexcept` |
| `void` | `setStoreSymbolicLinks( bool storeSymlinks ) noexcept` |
| `void` | `setThreadsCount( uint32_t threadsCount ) noexcept` |
| `void` | `setTotalCallback( const TotalCallback& callback )` |
| `void` | `setUpdateMode( bool canUpdate )` |
| `void` | `setUpdateMode( UpdateMode mode )` |
| `void` | `setVolumeSize( uint64_t volumeSize ) noexcept` |
| `void` | `setWordSize( uint32_t wordSize )` |
| `bool` | `solidMode() const noexcept` |
| `bool` | `storeSymbolicLinks() const noexcept` |
| `uint32_t` | `threadsCount() const noexcept` |
| `TotalCallback` | `totalCallback() const` |
| `UpdateMode` | `updateMode() const noexcept` |
| `uint64_t` | `volumeSize() const noexcept` |
| `uint32_t` | `wordSize() const noexcept` |

## 成员函数文档

### `BitFileCompressor( const Bit7zlibrary& lib, const BitInOutFormat& format )`

构造一个 `BitFileCompressor` 对象。需要 `Bit7zlibrary` 参数来访问 7z DLL 的功能。相反，需要 `BitInOutFormat` 来了解输出归档的格式。

**参数：**

- `lib`: 使用的 7z 库。
- `format`: 输出归档格式。

### `void clearPassword() noexcept`

清除处理程序当前使用的密码。调用 `clearPassword()` 将禁用归档的加密/解密。

**注意**
这等效于调用 `setPassword(L"")`。

### `void compress( const std::map< tstring, tstring >& inPaths, const tstring& outFile ) const`

使用指定的别名压缩给定的文件或目录。第一个参数中的项必须是文件系统上存在的文件或目录的相对或绝对路径。映射中的每个对必须遵循以下格式：`{"文件系统中文的路径", "归档中的别名路径"}`。

**参数：**

- `inPaths`: 路径和相应别名的映射。
- `outFile`: 输出归档文件的路径（相对或绝对）。

### `void compress( const std::map< tstring, tstring >& inPaths, std::ostream& outStream ) const`

使用指定的别名压缩给定的文件或目录。第一个参数中的项必须是文件系统上存在的文件或目录的相对或绝对路径。映射中的每个对必须遵循以下格式：`{"文件系统中文的路径", "归档中的别名路径"}`。

**参数：**

- `inPaths`: 路径和相应别名的映射。
- `outStream`: 输出归档文件的标准 ostream。

### `void compress( const std::vector< tstring >& inPaths, const tstring& outFile ) const`

压缩给定的文件或目录。第一个参数中的项必须是文件系统上存在的文件或目录的相对或绝对路径。

**参数：**

- `inPaths`: 路径的向量。
- `outFile`: 输出归档文件的路径（相对或绝对）。

### `void compress( const std::vector< tstring >& inPaths, std::ostream& outStream ) const`

压缩给定的文件或目录。第一个参数中的项必须是文件系统上存在的文件或目录的相对或绝对路径。

**参数：**

- `inPaths`: 路径的向量。
- `outStream`: 将输出归档的标准 ostream。

### `void compressDirectory( const tstring& inDir, const tstring& outFile ) const`

压缩整个目录。

**注意**
此方法等效于将过滤器设置为 `L""` 的 `compressFiles`。

**参数：**

- `inDir`: 输入目录的路径（相对或绝对）。
- `outFile`: 输出归档文件的路径（相对或绝对）。

### `void compressDirectoryContents( const tstring& inDir, const tstring& outFile, bool recursive = true, const tstring& filter = "*" ) const`

压缩目录的内容。

**注意**
与 `compressFiles` 不同，此方法还包括子文件夹的元数据。

**参数：**

- `inDir`: 输入目录的路径（相对或绝对）。
- `outFile`: 输出归档文件的路径（相对或绝对）。
- `recursive`: (可选) 如果为 true，则在 `inDir` 的子文件夹中搜索内容。
- `filter`: (可选) 在 `inDir` 内搜索内容时使用的过滤器。

### `void compressFile( const tstring& inFile, const tstring& outFile, const tstring& inputName = {} ) const`

压缩单个文件。

**参数：**

- `inFile`: 要压缩的文件。
- `outFile`: 输出归档文件的路径（相对或绝对）。
- `inputName`: (可选) 在输出归档中给压缩文件的名称。

### `void compressFile( const tstring& inFile, std::ostream& outStream, const tstring& inputName = {} ) const`

将输入文件压缩到输出流。

**参数：**

- `inFile`: 要压缩的文件。
- `outStream`: 输出流。
- `inputName`: (可选) 在输出归档中给压缩文件的名称。

### `void compressFile( const tstring& inFile, std::vector< byte_t >& outBuffer, const tstring& inputName = {} ) const`

将输入文件压缩到输出缓冲区。

**参数：**

- `inFile`: 要压缩的文件。
- `outBuffer`: 将包含输出归档的缓冲区。
- `inputName`: (可选) 在输出归档中给压缩文件的名称。

### `void compressFiles( const std::vector< tstring >& inFiles, const tstring& outFile ) const`

压缩一组文件。

**注意**
任何指向目录或不存在的文件的路径将被忽略！

**参数：**

- `inFiles`: 输入文件的路径（相对或绝对）。
- `outFile`: 输出归档文件的路径（相对或绝对）。

### `void compressFiles( const tstring& inDir, const tstring& outFile, bool recursive = true, const tstring& filter = "*" ) const`

压缩目录中包含的文件。

**参数：**

- `inDir`: 输入目录的路径（相对或绝对）。
- `outFile`: 输出归档文件的路径（相对或绝对）。
- `recursive`: (可选) 如果为 true，则在 `inDir` 的子文件夹中搜索文件。
- `filter`: (可选) 在 `inDir` 内搜索文件时使用的过滤器。

### `const BitInOutFormat& compressionFormat() const noexcept`

返回用于创建/更新归档的格式。

### `BitCompressionLevel compressionLevel() const noexcept`

返回用于创建/更新归档的压缩级别。

### `BitCompressionMethod compressionMethod() const noexcept`

返回用于创建/更新归档的压缩方法。

### `bool cryptHeaders() const noexcept`

返回创建者是否也加密归档的头信息。

### `uint32_t dictionarySize() const noexcept`

返回用于创建/更新归档的字典大小。

### `FileCallback fileCallback() const`

返回当前的文件回调。

### `[virtual] const BitInFormat& format() const noexcept`

返回用于创建/更新归档的格式。

### `bool isPasswordDefined() const noexcept`

返回一个布尔值，指示是否已定义密码。

### `const Bit7zlibrary& library() const noexcept`

返回处理程序使用的 `Bit7zlibrary` 对象。

### `OverwriteMode overwriteMode() const`

返回当前的 `OverwriteMode`。

### `tstring password() const`

返回用于打开、提取或加密归档的密码。

### `PasswordCallback passwordCallback() const`

返回当前的密码回调。

### `ProgressCallback progressCallback() const`

返回当前的进度回调。

### `RatioCallback ratioCallback() const`

返回当前的比率回调。

### `bool retainDirectories() const noexcept`

返回一个布尔值，指示在提取或压缩归档时是否必须保留目录结构。

### `void setCompressionLevel( BitCompressionLevel level ) noexcept`

设置创建/更新归档时要使用的压缩级别。

**参数：**

- `level`: 期望的压缩级别。

### `void setCompressionMethod( BitCompressionMethod method )`

设置创建/更新归档时要使用的压缩方法。

**参数：**

- `method`: 期望的压缩方法。

### `void setDictionarySize( uint32_t dictionarySize )`

设置创建/更新归档时要使用的字典大小。

**参数：**

- `dictionarySize`: 期望的字典大小。

### `void setFileCallback( const FileCallback& callback )`

设置当正在处理的当前文件发生变化时要调用的函数。

**参数：**

- `callback`: 要使用的文件回调。

### `void setFormatProperty( const wchar_t (&name)[N], const T& value ) noexcept`

设置输出归档格式的属性，如 7-zip 文档所述（例如，https://sevenzip.osdn.jp/chm/cmdline/switches/method.htm）。例如，在创建 .7z 归档时传递字符串 `L"tm"` 和 `false` 值将禁用存储压缩文件的最后修改时间戳。

**参数：**

- `name`: 要设置的属性的字符串名称。
- `value`: 要用于该属性的值。

### `void setFormatProperty( const wchar_t (&name)[N], T value ) noexcept`

设置输出归档格式的属性，如 7-zip 文档所述（例如，https://sevenzip.osdn.jp/chm/cmdline/switches/method.htm）。

**参数：**

- `name`: 要设置的属性的字符串名称。
- `value`: 要用于该属性的值。

### `void setOverwriteMode( OverwriteMode mode )`

设置当处理程序尝试输出到现有文件或缓冲区时应如何行为。

**参数：**

- `mode`: 处理程序要使用的 `OverwriteMode`。

### `[virtual] void setPassword( const tstring& password ) override`

为输出归档设置密码。设置密码后，生成的归档将使用输出格式的默认加密方法进行加密。与调用 `setPassword(tstring, bool)` 方法时发生的情况不同，"crypt headers" 选项保持不变。

**注意**
当输出格式不支持归档加密（例如，GZip、BZip2 等）时调用 `setPassword` 没有任何效果（换句话说，它不会抛出异常，并且对压缩操作没有影响）。

**注意**
设置密码后，它将在每个后续操作中使用。要禁用密码的使用，您需要调用 `clearPassword` 方法（继承自 `BitAbstractArchiveHandler`），这等效于 `setPassword(L"")`。

**参数：**

- `password`: 创建/更新归档时要使用的密码。

### `void setPassword( const tstring& password, bool cryptHeaders )`

为输出归档设置密码。设置密码后，生成的归档将使用输出格式的默认加密方法进行加密。如果格式是 7z，并且选项 "cryptHeaders" 设置为 true，则归档的头信息将被加密，导致每次打开输出文件时都需要输入密码。

**注意**
当输出格式不支持归档加密（例如，GZip、BZip2 等）时调用 `setPassword` 没有任何效果（换句话说，它不会抛出异常，并且对压缩操作没有影响）。

**注意**
将 "cryptHeaders" 设置为 true 调用 `setPassword` 对不同于 7z 的格式没有影响。

**注意**
设置密码后，它将在每个后续操作中使用。要禁用密码的使用，您需要调用 `clearPassword` 方法（继承自 `BitAbstractArchiveHandler`），这等效于 `setPassword(L"")`。

**参数：**

- `password`: 创建/更新归档时要使用的密码。
- `cryptHeaders`: 如果为 true，输出归档的头信息将被加密（仅在使用 7z 格式时有效）。

### `void setPasswordCallback( const PasswordCallback& callback )`

设置当需要密码来完成正在进行的操作时要调用的函数。

**参数：**

- `callback`: 要使用的密码回调。

### `void setProgressCallback( const ProgressCallback& callback )`

设置当正在进行的操作的已处理大小更新时要调用的函数。

**注意**
当前操作的完成百分比可以通过计算 `static_cast<int>(100.0 * processed_size / total_size)` 获得。

**参数：**

- `callback`: 要使用的进度回调。

### `void setRatioCallback( const RatioCallback& callback )`

设置当已知正在进行的操作的输入处理大小和当前输出大小时要调用的函数。

**注意**
压缩操作的比率百分比可以通过计算 `static_cast<int>(100.0 * output_size / input_size)` 获得。

**参数：**

- `callback`: 要使用的比率回调。

### `void setRetainDirectories( bool retain ) noexcept`

设置操作的输出是否将保留输入的目录结构。

**参数：**

- `retain`: 是否保留输入目录结构的设置。

### `void setSolidMode( bool solidMode ) noexcept`

设置是否使用固实压缩。

**注意**
将固实压缩模式设置为 true 仅在使用 7z 格式且具有多个输入文件时有效。

**参数：**

- `solidMode`: 如果为 true，将使用"固实压缩"方法。

### `void setStoreSymbolicLinks( bool storeSymlinks ) noexcept`

设置创建者是否将符号链接作为链接存储在输出归档中。

**参数：**

- `storeSymlinks`: 如果为 true，符号链接将作为链接存储。

### `void setThreadsCount( uint32_t threadsCount ) noexcept`

设置创建/更新归档时要使用的线程数。

**参数：**

- `threadsCount`: 期望的线程数。

### `void setTotalCallback( const TotalCallback& callback )`

设置当操作的总大小可用时要调用的函数。

**参数：**

- `callback`: 要使用的总回调。

### `void setUpdateMode( bool canUpdate )`

设置创建者是否可以更新现有归档。

**警告**
自 v4.0 起已弃用；提供它只是为了更轻松地从旧的 v3 API 过渡。

**注意**
如果设置为 false，后续的压缩操作如果目标是现有归档，则可能抛出异常。

**参数：**

- `canUpdate`: 如果为 true，压缩操作将更新现有归档。

### `[virtual] void setUpdateMode( UpdateMode mode )`

设置创建者是否可以以及如何更新现有归档。

**注意**
如果设置为 `UpdateMode::None`，后续的压缩操作如果目标是现有归档，则可能抛出异常。

**参数：**

- `mode`: 期望的更新模式。

### `void setVolumeSize( uint64_t volumeSize ) noexcept`

设置输出归档卷的 `volumeSize`（以字节为单位）。

**注意**
此设置仅当目标归档位于文件系统上时才有效。

**参数：**

- `volumeSize`: 卷的尺寸。

### `void setWordSize( uint32_t wordSize )`

设置创建/更新归档时要使用的字大小。

**参数：**

- `wordSize`: 期望的字大小。

### `bool solidMode() const noexcept`

返回归档创建者是否使用固实压缩。

### `bool storeSymbolicLinks() const noexcept`

返回归档创建者是否将符号链接作为链接存储在输出归档中。

### `uint32_t threadsCount() const noexcept`

返回创建/更新归档时使用的线程数（值为 0 表示将使用 7-zip 默认值）。

### `TotalCallback totalCallback() const`

返回当前的总回调。

### `UpdateMode updateMode() const noexcept`

返回更新现有归档时使用的更新模式。

### `uint64_t volumeSize() const noexcept`

返回创建多卷归档时使用的卷大小（以字节为单位）（值为 0 表示所有文件都将放入单个归档中）。

### `uint32_t wordSize() const noexcept`

返回用于创建/更新归档的字大小。

---

# BitFileExtractor

*Oz edited this page on Sep 26, 2024 · 7 revisions*

---

`BitFileExtractor` 是 `BitExtractor< const tstring & >` 的别名。

`BitFileExtractor` 别名允许提取文件系统上的归档。

`#include <bit7z/bitfileextractor.hpp>`

## 所有成员列表

### 公共成员

| 返回类型 | 名称 |
|---|---|
| `void` | `BitExtractor( const Bit7zlibrary& lib, const BitInFormat& format = BitFormat::Auto )` |
| `void` | `clearPassword() noexcept` |
| `void` | `extract( const tstring& inArchive, const tstring& outDir = {} ) const` |
| `void` | `extract( const tstring& inArchive, std::map< tstring, std::vector< byte_t >>& outMap ) const` |
| `void` | `extract( const tstring& inArchive, std::ostream& outStream, uint32_t index = 0 ) const` |
| `void` | `extract( const tstring& inArchive, std::vector< byte_t >& outBuffer, uint32_t index = 0 ) const` |
| `const BitInFormat&` | `extractionFormat() const noexcept` |
| `void` | `extractItems( const tstring& inArchive, const std::vector< uint32_t >& indices, const tstring& outDir = {} ) const` |
| `void` | `extractMatching( const tstring& inArchive, const tstring& itemFilter, const tstring& outDir = {}, FilterPolicy policy = FilterPolicy::Include ) const` |
| `void` | `extractMatching( const tstring& inArchive, const tstring& itemFilter, std::vector< byte_t >& outBuffer, FilterPolicy policy = FilterPolicy::Include ) const` |
| `void` | `extractMatchingRegex( const tstring& inArchive, const tstring& regex, const tstring& outDir = {}, FilterPolicy policy = FilterPolicy::Include ) const` |
| `void` | `extractMatchingRegex( const tstring& inArchive, const tstring& regex, std::vector< byte_t >& outBuffer, FilterPolicy policy = FilterPolicy::Include ) const` |
| `FileCallback` | `fileCallback() const` |
| `[virtual] const BitInFormat&` | `format() const noexcept` |
| `bool` | `isPasswordDefined() const noexcept` |
| `const Bit7zlibrary&` | `library() const noexcept` |
| `OverwriteMode` | `overwriteMode() const` |
| `tstring` | `password() const` |
| `PasswordCallback` | `passwordCallback() const` |
| `ProgressCallback` | `progressCallback() const` |
| `RatioCallback` | `ratioCallback() const` |
| `bool` | `retainDirectories() const noexcept` |
| `void` | `setFileCallback( const FileCallback& callback )` |
| `void` | `setOverwriteMode( OverwriteMode mode )` |
| `void` | `setPassword( const tstring& password )` |
| `void` | `setPasswordCallback( const PasswordCallback& callback )` |
| `void` | `setProgressCallback( const ProgressCallback& callback )` |
| `void` | `setRatioCallback( const RatioCallback& callback )` |
| `void` | `setRetainDirectories( bool retain ) noexcept` |
| `void` | `setTotalCallback( const TotalCallback& callback )` |
| `void` | `test( const tstring& inArchive ) const` |
| `TotalCallback` | `totalCallback() const` |

## 成员函数文档

### `BitExtractor( const Bit7zlibrary& lib, const BitInFormat& format = BitFormat::Auto )`

构造一个 `BitExtractor` 对象。需要 `Bit7zlibrary` 参数来访问 7z DLL 的功能。相反，需要 `BitInFormat` 来了解输入文件归档的格式。

**注意**
当 bit7z 使用 `BIT7Z_AUTO_FORMAT` 宏定义编译时，`format` 参数具有默认值 `BitFormat::Auto`（自动检测输入文件归档的格式）。否则，当 `BIT7Z_AUTO_FORMAT` 未定义时（即没有自动格式检测可用），必须指定 `format` 参数。

**参数：**

- `lib`: 要使用的 7z 库。
- `format`: 输入文件归档的格式。

### `void clearPassword() noexcept`

清除处理程序当前使用的密码。调用 `clearPassword()` 将禁用归档的加密/解密。

**注意**
这等效于调用 `setPassword(L"")`。

### `void extract( const tstring& inArchive, const tstring& outDir = {} ) const`

将给定的归档提取到所选目录。

**参数：**

- `inArchive`: 要提取的输入归档。
- `outDir`: 提取文件将放置的输出目录。

### `void extract( const tstring& inArchive, std::map< tstring, std::vector< byte_t >>& outMap ) const`

将给定归档的内容提取到内存缓冲区的映射中，其中键是文件的路径（在归档内部），值是它们的解压缩内容。

**参数：**

- `inArchive`: 要提取的输入归档。
- `outMap`: 输出映射。

### `void extract( const tstring& inArchive, std::ostream& outStream, uint32_t index = 0 ) const`

从给定归档中提取文件到输出流。

**参数：**

- `inArchive`: 要从中提取的输入归档。
- `outStream`: 提取文件内容将放置的（二进制）流。
- `index`: 要从归档中提取的文件的索引。

### `void extract( const tstring& inArchive, std::vector< byte_t >& outBuffer, uint32_t index = 0 ) const`

从给定归档中提取文件到输出缓冲区。

**参数：**

- `inArchive`: 要从中提取的输入归档。
- `outBuffer`: 提取文件内容将放置的输出缓冲区。
- `index`: 要从归档中提取的文件的索引。

### `const BitInFormat& extractionFormat() const noexcept`

返回归档打开器使用的归档格式。

### `void extractItems( const tstring& inArchive, const std::vector< uint32_t >& indices, const tstring& outDir = {} ) const`

从给定归档中提取指定的项到所选目录。

**参数：**

- `inArchive`: 要从中提取的输入归档。
- `indices`: 归档中应提取的文件的索引。
- `outDir`: 提取文件将放置的输出目录。

### `void extractMatching( const tstring& inArchive, const tstring& itemFilter, const tstring& outDir = {}, FilterPolicy policy = FilterPolicy::Include ) const`

将归档中与给定通配符模式匹配的文件提取到所选目录。

**参数：**

- `inArchive`: 要从中提取的输入归档。
- `itemFilter`: 用于匹配归档内部文件路径的通配符模式。
- `outDir`: 提取文件将放置的输出目录。
- `policy`: 要应用于匹配项的过滤策略。

### `void extractMatching( const tstring& inArchive, const tstring& itemFilter, std::vector< byte_t >& outBuffer, FilterPolicy policy = FilterPolicy::Include ) const`

将归档中与给定通配符模式匹配的第一个文件提取到输出缓冲区。

**参数：**

- `inArchive`: 要从中提取的输入归档。
- `itemFilter`: 用于匹配归档内部文件路径的通配符模式。
- `outBuffer`: 要提取文件的输出缓冲区。
- `policy`: 要应用于匹配项的过滤策略。

### `void extractMatchingRegex( const tstring& inArchive, const tstring& regex, const tstring& outDir = {}, FilterPolicy policy = FilterPolicy::Include ) const`

将归档中与给定正则表达式模式匹配的文件提取到所选目录。

**注意**
仅在编译 bit7z 时使用 `BIT7Z_REGEX_MATCHING` 预处理器定义才可用。

**参数：**

- `inArchive`: 要从中提取的输入归档。
- `regex`: 用于匹配归档内部文件路径的正则表达式。
- `outDir`: 提取文件将放置的输出目录。
- `policy`: 要应用于匹配项的过滤策略。

### `void extractMatchingRegex( const tstring& inArchive, const tstring& regex, std::vector< byte_t >& outBuffer, FilterPolicy policy = FilterPolicy::Include ) const`

将归档中与给定正则表达式模式匹配的第一个文件提取到输出缓冲区。

**注意**
仅在编译 bit7z 时使用 `BIT7Z_REGEX_MATCHING` 预处理器定义才可用。

**参数：**

- `inArchive`: 要从中提取的输入归档。
- `regex`: 用于匹配归档内部文件路径的正则表达式。
- `outBuffer`: 提取文件将放置的输出缓冲区。
- `policy`: 要应用于匹配项的过滤策略。

### `FileCallback fileCallback() const`

返回当前的文件回调。

### `[virtual] const BitInFormat& format() const noexcept`

返回归档打开器使用的归档格式。

### `bool isPasswordDefined() const noexcept`

返回一个布尔值，指示是否已定义密码。

### `const Bit7zlibrary& library() const noexcept`

返回处理程序使用的 `Bit7zlibrary` 对象。

### `OverwriteMode overwriteMode() const`

返回当前的 `OverwriteMode`。

### `tstring password() const`

返回用于打开、提取或加密归档的密码。

### `PasswordCallback passwordCallback() const`

返回当前的密码回调。

### `ProgressCallback progressCallback() const`

返回当前的进度回调。

### `RatioCallback ratioCallback() const`

返回当前的比率回调。

### `bool retainDirectories() const noexcept`

返回一个布尔值，指示在提取或压缩归档时是否必须保留目录结构。

### `void setFileCallback( const FileCallback& callback )`

设置当正在处理的当前文件发生变化时要调用的函数。

**参数：**

- `callback`: 要使用的文件回调。

### `void setOverwriteMode( OverwriteMode mode )`

设置当处理程序尝试输出到现有文件或缓冲区时应如何行为。

**参数：**

- `mode`: 处理程序要使用的 `OverwriteMode`。

### `[virtual] void setPassword( const tstring& password )`

设置供归档处理程序使用的密码。该密码将使用归档格式的默认加密方法来加密/解密归档。

**注意**
当输入归档未加密时调用 `setPassword` 对提取过程没有任何影响。

**注意**
当输出格式不支持归档加密（例如，GZip、BZip2 等）时调用 `setPassword` 没有任何效果（换句话说，它不会抛出异常，并且对压缩操作没有影响）。

**注意**
设置密码后，它将在每个后续操作中使用。要禁用密码的使用，您需要调用 `clearPassword` 方法，这等效于调用 `setPassword(L"")`。

**参数：**

- `password`: 要使用的密码。

### `void setPasswordCallback( const PasswordCallback& callback )`

设置当需要密码来完成正在进行的操作时要调用的函数。

**参数：**

- `callback`: 要使用的密码回调。

### `void setProgressCallback( const ProgressCallback& callback )`

设置当正在进行的操作的已处理大小更新时要调用的函数。

**注意**
当前操作的完成百分比可以通过计算 `static_cast<int>(100.0 * processed_size / total_size)` 获得。

**参数：**

- `callback`: 要使用的进度回调。

### `void setRatioCallback( const RatioCallback& callback )`

设置当已知正在进行的操作的输入处理大小和当前输出大小时要调用的函数。

**注意**
压缩操作的比率百分比可以通过计算 `static_cast<int>(100.0 * output_size / input_size)` 获得。

**参数：**

- `callback`: 要使用的比率回调。

### `void setRetainDirectories( bool retain ) noexcept`

设置操作的输出是否将保留输入的目录结构。

**参数：**

- `retain`: 是否保留输入目录结构的设置。

### `void setTotalCallback( const TotalCallback& callback )`

设置当操作的总大小可用时要调用的函数。

**参数：**

- `callback`: 要使用的总回调。

### `void test( const tstring& inArchive ) const`

测试给定的归档而不提取其内容。如果归档无效，则抛出 `BitException`！

**参数：**

- `inArchive`: 要测试的输入归档。

### `TotalCallback totalCallback() const`

返回当前的总回调。