# BitArchiveEditor

*Oz edited this page on Sep 26, 2024 · 10 revisions*

---

`BitArchiveEditor` 类允许创建新的文件归档或更新旧的归档。支持的更新操作包括添加新项，以及重命名/更新/删除旧项。

`#include <bit7z/bitarchiveeditor.hpp>`

继承自 **BitArchiveWriter**。

## 所有成员列表

### 公共成员

| 返回类型 | 名称 |
|---|---|
| `void` | `BitArchiveEditor( const Bit7zlibrary& lib, const tstring& inFile, const BitInOutFormat& format, const tstring& password = {} )` |
| `void` | `addDirectory( const tstring& inDir )` |
| `void` | `addDirectoryContents( const tstring& inDir, const tstring& filter, bool recursive )` |
| `void` | `addDirectoryContents( const tstring& inDir, const tstring& filter = "*", FilterPolicy policy = FilterPolicy::Include, bool recursive = true )` |
| `void` | `addFile( const std::vector< byte_t >& inBuffer, const tstring& name )` |
| `void` | `addFile( const tstring& inFile, const tstring& name = {} )` |
| `void` | `addFile( std::istream& inStream, const tstring& name )` |
| `void` | `addFiles( const std::vector< tstring >& inFiles )` |
| `void` | `addFiles( const tstring& inDir, const tstring& filter, bool recursive )` |
| `void` | `addFiles( const tstring& inDir, const tstring& filter = "*", FilterPolicy policy = FilterPolicy::Include, bool recursive = true )` |
| `void` | `addItems( const std::map< tstring, tstring >& inPaths )` |
| `void` | `addItems( const std::vector< tstring >& inPaths )` |
| `void` | `applyChanges()` |
| `void` | `clearPassword() noexcept` |
| `const BitInOutFormat&` | `compressionFormat() const noexcept` |
| `BitCompressionLevel` | `compressionLevel() const noexcept` |
| `BitCompressionMethod` | `compressionMethod() const noexcept` |
| `void` | `compressTo( const tstring& outFile )` |
| `void` | `compressTo( std::ostream& outStream )` |
| `void` | `compressTo( std::vector< byte_t >& outBuffer )` |
| `const BitAbstractArchiveCreator&` | `creator() const noexcept` |
| `bool` | `cryptHeaders() const noexcept` |
| `void` | `deleteItem( const tstring& itemPath, DeletePolicy policy = DeletePolicy::ItemOnly )` |
| `void` | `deleteItem( uint32_t index, DeletePolicy policy = DeletePolicy::ItemOnly )` |
| `uint32_t` | `dictionarySize() const noexcept` |
| `FileCallback` | `fileCallback() const` |
| `const BitInFormat&` | `format() const noexcept` |
| `const BitAbstractArchiveHandler&` | `handler() const noexcept` |
| `bool` | `isPasswordDefined() const noexcept` |
| `uint32_t` | `itemsCount() const` |
| `const Bit7zlibrary&` | `library() const noexcept` |
| `OverwriteMode` | `overwriteMode() const` |
| `tstring` | `password() const` |
| `PasswordCallback` | `passwordCallback() const` |
| `ProgressCallback` | `progressCallback() const` |
| `RatioCallback` | `ratioCallback() const` |
| `void` | `renameItem( const tstring& oldPath, const tstring& newPath )` |
| `void` | `renameItem( uint32_t index, const tstring& newPath )` |
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
| `void` | `setUpdateMode( UpdateMode mode ) override` |
| `void` | `setVolumeSize( uint64_t volumeSize ) noexcept` |
| `void` | `setWordSize( uint32_t wordSize )` |
| `bool` | `solidMode() const noexcept` |
| `bool` | `storeSymbolicLinks() const noexcept` |
| `uint32_t` | `threadsCount() const noexcept` |
| `TotalCallback` | `totalCallback() const` |
| `void` | `updateItem( const tstring& itemPath, const std::vector< byte_t >& inBuffer )` |
| `void` | `updateItem( const tstring& itemPath, const tstring& inFile )` |
| `void` | `updateItem( const tstring& itemPath, std::istream& inStream )` |
| `void` | `updateItem( uint32_t index, const std::vector< byte_t >& inBuffer )` |
| `void` | `updateItem( uint32_t index, const tstring& inFile )` |
| `void` | `updateItem( uint32_t index, std::istream& inStream )` |
| `UpdateMode` | `updateMode() const noexcept` |
| `uint64_t` | `volumeSize() const noexcept` |
| `uint32_t` | `wordSize() const noexcept` |

## 成员函数文档

### `BitArchiveEditor( const Bit7zlibrary& lib, const tstring& inFile, const BitInOutFormat& format, const tstring& password = {} )`

构造一个 `BitArchiveEditor` 对象，读取给定的归档文件路径。

**参数：**

- `lib`: 要使用的 7z 库。
- `inFile`: 输入归档文件的路径。
- `format`: 输入/输出归档格式。
- `password`: (可选) 读取输入归档所需的密码。

### `void addDirectory( const tstring& inDir )`

添加给定的目录路径及其所有内容。

**参数：**

- `inDir`: 要添加到归档中的目录路径。

### `void addDirectoryContents( const tstring& inDir, const tstring& filter, bool recursive )`

添加给定目录路径的内容。此函数遍历指定目录，并根据提供的通配符过滤器添加其内容。可选地，操作可以是递归的，意味着它将包括子目录及其内容。

**参数：**

- `inDir`: 要在其中搜索要添加到输出归档的文件的目录。
- `filter`: 用于搜索文件的通配符过滤器。
- `recursive`: 在给定目录及其所有子目录中递归搜索文件。

### `void addDirectoryContents( const tstring& inDir, const tstring& filter = "*", FilterPolicy policy = FilterPolicy::Include, bool recursive = true )`

添加给定目录路径的内容。此函数遍历指定目录，并根据提供的通配符过滤器和策略添加其内容。可选地，操作可以是递归的，意味着它将包括子目录及其内容。

**参数：**

- `inDir`: 要在其中搜索要添加到输出归档的文件的目录。
- `filter`: (可选) 用于搜索文件的通配符过滤器。
- `recursive`: (可选) 在给定目录及其所有子目录中递归搜索文件。
- `policy`: (可选) 要应用于匹配项的过滤策略。

### `void addFile( const std::vector< byte_t >& inBuffer, const tstring& name )`

添加给定的缓冲区文件，在输出归档中压缩时使用给定的名称作为路径。

**参数：**

- `inBuffer`: 包含要添加到输出归档的文件的缓冲区。
- `name`: 要在输出归档内部使用的用户定义路径。

### `void addFile( const tstring& inFile, const tstring& name = {} )`

添加给定的文件路径，带有一个可选的用户定义路径以在输出归档中使用。

**注意**
如果给定的是目录路径，则会抛出 `BitException`。

**参数：**

- `inFile`: 要添加到输出归档的文件系统文件路径。
- `name`: (可选) 要在输出归档内部使用的用户定义路径。

### `void addFile( std::istream& inStream, const tstring& name )`

添加给定的标准输入流，在输出归档中压缩时使用给定的名称作为路径。

**参数：**

- `inStream`: 要添加的输入流。
- `name`: 输出归档内部文件的名称。

### `void addFiles( const std::vector< tstring >& inFiles )`

添加给定文件系统路径向量中的所有文件。

**注意**
指向目录的路径将被忽略。

**参数：**

- `inFiles`: 文件路径的向量。

### `void addFiles( const tstring& inDir, const tstring& filter, bool recursive )`

添加给定目录路径内与给定通配符过滤器匹配的所有文件。

**参数：**

- `inDir`: 要在其中搜索要添加到输出归档的文件的目录。
- `filter`: 用于搜索文件的通配符过滤器。
- `recursive`: 在给定目录及其所有子目录中递归搜索文件。

### `void addFiles( const tstring& inDir, const tstring& filter = "*", FilterPolicy policy = FilterPolicy::Include, bool recursive = true )`

添加给定目录路径内与给定通配符过滤器匹配的所有文件。

**参数：**

- `inDir`: 要在其中搜索要添加到输出归档的文件的目录。
- `filter`: (可选) 用于搜索文件的通配符过滤器。
- `recursive`: (可选) 在给定目录及其所有子目录中递归搜索文件。
- `policy`: (可选) 要应用于匹配项的过滤策略。

### `void addItems( const std::map< tstring, tstring >& inPaths )`

添加通过索引给定文件系统路径映射的键可以找到的所有项；相应的映射值是希望在输出归档内部使用的用户定义路径。

**参数：**

- `inPaths`: 文件系统路径的映射，其对应的值是希望在输出归档内部使用的用户定义路径。

### `void addItems( const std::vector< tstring >& inPaths )`

添加通过索引给定文件系统路径向量可以找到的所有项。

**参数：**

- `inPaths`: 文件系统路径的向量。

### `void applyChanges()`

将请求的更改（即重命名/更新/删除操作）应用到输入归档。

### `void clearPassword() noexcept`

清除处理程序当前使用的密码。调用 `clearPassword()` 将禁用归档的加密/解密。

**注意**
这等效于调用 `setPassword(L"")`。

### `const BitInOutFormat& compressionFormat() const noexcept`

返回用于创建/更新归档的格式。

### `BitCompressionLevel compressionLevel() const noexcept`

返回用于创建/更新归档的压缩级别。

### `BitCompressionMethod compressionMethod() const noexcept`

返回用于创建/更新归档的压缩方法。

### `void compressTo( const tstring& outFile )`

将此对象添加的所有项压缩到指定的归档文件路径。

**注意**
如果此对象是通过传递输入归档文件路径创建的，并且该路径与 `outFile` 路径参数相同，则该文件将被更新。

**参数：**

- `outFile`: 输出归档文件路径。

### `void compressTo( std::ostream& outStream )`

将此对象添加的所有项压缩到指定的缓冲区。

**参数：**

- `outStream`: 输出标准流。

### `void compressTo( std::vector< byte_t >& outBuffer )`

将此对象添加的所有项压缩到指定的缓冲区。

**参数：**

- `outBuffer`: 输出缓冲区。

### `const BitAbstractArchiveCreator& creator() const noexcept`

返回一个包含写入输出归档设置的 `BitAbstractArchiveHandler` 对象的常量引用。

### `bool cryptHeaders() const noexcept`

返回创建者是否也加密归档的头信息。

### `void deleteItem( const tstring& itemPath, DeletePolicy policy = DeletePolicy::ItemOnly )`

将具有指定路径的归档项标记为已删除。

**注意**
默认情况下，如果标记的项是文件夹，则仅删除其元数据，而不删除其中的文件。要同时删除文件夹内容，请将 `policy` 设置为 `DeletePolicy::RecurseDirs`。

**注意**
指定的路径不能以路径分隔符开头。

**注意**
带有尾随分隔符的路径仅当策略为 `DeletePolicy::RecurseDirs` 时才会被考虑，并且只会匹配文件夹；对于 `DeletePolicy::ItemOnly`，带有尾随分隔符的路径不会匹配任何项。

**注意**
通常，归档可能包含多个具有相同路径的项。如果是这种情况，所有匹配的项将根据指定的策略被标记为已删除。

**参数：**

- `itemPath`: 要删除的项在归档中的路径。
- `policy`: 删除项时使用的策略。

**重要**
如果指定的路径为空或无效，或者找不到匹配的项，该函数将抛出 `BitException`。

### `void deleteItem( uint32_t index, DeletePolicy policy = DeletePolicy::ItemOnly )`

将给定索引处的项标记为已删除。

**注意**
默认情况下，如果该项是文件夹，则仅删除其元数据，而不删除其中的文件。如果策略设置为 `DeletePolicy::RecurseDirs`，则文件夹内的项也将被删除。

**参数：**

- `index`: 要删除的项的索引。
- `policy`: 删除项时使用的策略。

**重要**
如果索引无效，该函数将抛出 `BitException`。

### `uint32_t dictionarySize() const noexcept`

返回用于创建/更新归档的字典大小。

### `FileCallback fileCallback() const`

返回当前的文件回调。

### `[virtual] const BitInFormat& format() const noexcept`

返回用于创建/更新归档的格式。

### `const BitAbstractArchiveHandler& handler() const noexcept`

返回一个包含写入输出归档设置的 `BitAbstractArchiveHandler` 对象的常量引用。

### `bool isPasswordDefined() const noexcept`

返回一个布尔值，指示是否已定义密码。

### `uint32_t itemsCount() const`

返回添加到输出归档对象的总项数。

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

### `void renameItem( const tstring& oldPath, const tstring& newPath )`

请求将项的路径从 `oldPath` 更改为 `newPath`。

**参数：**

- `oldPath`: 要重命名的项在归档中的旧路径。
- `newPath`: 项在归档中期望的新路径。

### `void renameItem( uint32_t index, const tstring& newPath )`

请求将指定索引处的项的路径更改为给定的路径。

**参数：**

- `index`: 要重命名的项的索引。
- `newPath`: 项在归档中期望的新路径。

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

### `[virtual] void setUpdateMode( UpdateMode mode ) override`

设置编辑器如何执行归档中项的更新。

**注意**
`BitArchiveEditor` 不支持 `UpdateMode::None`。

**参数：**

- `mode`: 期望的更新模式（`UpdateMode::Append` 或 `UpdateMode::Overwrite`）。

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

### `void updateItem( const tstring& itemPath, const std::vector< byte_t >& inBuffer )`

请求使用来自给定缓冲区的数据更新指定路径处的项的内容。

**参数：**

- `itemPath`: 要更新的项在归档中的路径。
- `inBuffer`: 包含项新数据的缓冲区。

### `void updateItem( const tstring& itemPath, const tstring& inFile )`

请求使用来自给定文件的数据更新指定路径处的项的内容。

**参数：**

- `itemPath`: 要更新的项在归档中的路径。
- `inFile`: 包含项新数据的文件路径。

### `void updateItem( const tstring& itemPath, std::istream& inStream )`

请求使用来自给定流的数据更新指定路径处的项的内容。

**参数：**

- `itemPath`: 要更新的项在归档中的路径。
- `inStream`: 项的新数据流。

### `void updateItem( uint32_t index, const std::vector< byte_t >& inBuffer )`

请求使用来自给定缓冲区的数据更新指定索引处的项的内容。

**参数：**

- `index`: 要更新的项的索引。
- `inBuffer`: 包含项新数据的缓冲区。

### `void updateItem( uint32_t index, const tstring& inFile )`

请求使用来自给定文件的数据更新指定索引处的项的内容。

**参数：**

- `index`: 要更新的项的索引。
- `inFile`: 包含项新数据的文件路径。

### `void updateItem( uint32_t index, std::istream& inStream )`

请求使用来自给定流的数据更新指定索引处的项的内容。

**参数：**

- `index`: 要更新的项的索引。
- `inStream`: 项的新数据流。

### `UpdateMode updateMode() const noexcept`

返回更新现有归档时使用的更新模式。

### `uint64_t volumeSize() const noexcept`

返回创建多卷归档时使用的卷大小（以字节为单位）（值为 0 表示所有文件都将放入单个归档中）。

### `uint32_t wordSize() const noexcept`

返回用于创建/更新归档的字大小。

---

# BitArchiveReader

*Oz edited this page on Dec 16, 2024 · 9 revisions*

---

`BitArchiveReader` 类允许读取归档的元数据，以及提取它们。

`#include <bit7z/bitarchivereader.hpp>`

继承自 **BitAbstractArchiveOpener**, **BitInputArchive**。

## 所有成员列表

### 公共成员

| 返回类型 | 名称 |
|---|---|
| | `BitArchiveReader( const Bit7zlibrary& lib, const buffer_t& inArchive, ArchiveStartOffset archiveStart, const BitInFormat& format = BitFormat::Auto, const tstring& password = {} )` |
| | `BitArchiveReader( const Bit7zlibrary& lib, const std::vector< byte_t >& inArchive, const BitInFormat& format = BitFormat::Auto, const tstring& password = {} )` |
| | `BitArchiveReader( const Bit7zlibrary& lib, const tstring& inArchive, ArchiveStartOffset archiveStart, const BitInFormat& format = BitFormat::Auto, const tstring& password = {} )` |
| | `BitArchiveReader( const Bit7zlibrary& lib, const tstring& inArchive, const BitInFormat& format = BitFormat::Auto, const tstring& password = {} )` |
| | `BitArchiveReader( const Bit7zlibrary& lib, std::istream& inArchive, ArchiveStartOffset archiveStart, const BitInFormat& format = BitFormat::Auto, const tstring& password = {} )` |
| | `BitArchiveReader( const Bit7zlibrary& lib, std::istream& inArchive, const BitInFormat& format = BitFormat::Auto, const tstring& password = {} )` |
| | `~BitArchiveReader() override = default` |
| `const tstring&` | `archivePath() const noexcept` |
| `std::map<BitProperty, BitPropVariant>` | `archiveProperties() const` |
| `BitPropVariant` | `archiveProperty( BitProperty property ) const` |
| `BitInputArchive::ConstIterator` | `begin() const noexcept` |
| `BitInputArchive::ConstIterator` | `cbegin() const noexcept` |
| `BitInputArchive::ConstIterator` | `cend() const noexcept` |
| `void` | `clearPassword() noexcept` |
| `bool` | `contains( const tstring& path ) const noexcept` |
| `const BitInFormat&` | `detectedFormat() const noexcept` |
| `BitInputArchive::ConstIterator` | `end() const noexcept` |
| `const BitInFormat&` | `extractionFormat() const noexcept` |
| `void` | `extractTo( byte_t* buffer, std::size_t size, uint32_t index = 0 ) const` |
| `void` | `extractTo( byte_t (&buffer)[N], uint32_t index = 0 ) const` |
| `void` | `extractTo( const tstring& outDir ) const` |
| `void` | `extractTo( const tstring& outDir, const std::vector< uint32_t >& indices ) const` |
| `void` | `extractTo( std::array< byte_t, N >& buffer, uint32_t index = 0 ) const` |
| `void` | `extractTo( std::map< tstring, std::vector< byte_t >>& outMap ) const` |
| `void` | `extractTo( std::ostream& outStream, uint32_t index = 0 ) const` |
| `void` | `extractTo( std::vector< byte_t >& outBuffer, uint32_t index = 0 ) const` |
| `FileCallback` | `fileCallback() const` |
| `uint32_t` | `filesCount() const` |
| `BitInputArchive::ConstIterator` | `find( const tstring& path ) const noexcept` |
| `uint32_t` | `foldersCount() const` |
| `[virtual] const BitInFormat&` | `format() const noexcept` |
| `const BitAbstractArchiveHandler&` | `handler() const noexcept` |
| `bool` | `hasEncryptedItems() const` |
| `bool` | `isEncrypted() const` |
| `bool` | `isItemEncrypted( uint32_t index ) const` |
| `bool` | `isItemFolder( uint32_t index ) const` |
| `bool` | `isMultiVolume() const` |
| `bool` | `isPasswordDefined() const noexcept` |
| `bool` | `isSolid() const` |
| `BitArchiveItemOffset` | `itemAt( uint32_t index ) const` |
| `BitPropVariant` | `itemProperty( uint32_t index, BitProperty property ) const` |
| `std::vector<BitArchiveItemInfo>` | `items() const` |
| `uint32_t` | `itemsCount() const` |
| `const Bit7zlibrary&` | `library() const noexcept` |
| `OverwriteMode` | `overwriteMode() const` |
| `uint64_t` | `packSize() const` |
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
| `uint64_t` | `size() const` |
| `void` | `test() const` |
| `void` | `testItem( uint32_t index ) const` |
| `TotalCallback` | `totalCallback() const` |
| `void` | `useFormatProperty( const wchar_t* name, const BitPropVariant& property ) const` |
| `void` | `useFormatProperty( const wchar_t* name, T&& value ) const` |
| `uint32_t` | `volumesCount() const` |

### 静态公共成员

| 返回类型 | 名称 |
|---|---|
| `bool` | `isEncrypted( const Bit7zlibrary& lib, T&& inArchive, const BitInFormat& format = BitFormat::Auto )` |
| `bool` | `isHeaderEncrypted( const Bit7zlibrary& lib, T&& inArchive, const BitInFormat& format = BitFormat::Auto )` |

## 成员函数文档

### `BitArchiveReader( const Bit7zlibrary& lib, const buffer_t& inArchive, ArchiveStartOffset archiveStart, const BitInFormat& format = BitFormat::Auto, const tstring& password = {} )`

构造一个 `BitArchiveReader` 对象，打开输入缓冲区中的归档。

**注意**
当 bit7z 使用 `BIT7Z_AUTO_FORMAT` 选项编译时，`format` 参数具有默认值 `BitFormat::Auto`（自动检测输入归档的格式）。相反，当 `BIT7Z_AUTO_FORMAT` 未定义时（即没有自动格式检测可用），必须指定 `format` 参数。

**参数：**

- `lib`: 使用的 7z 库。
- `inArchive`: 包含要读取的归档的输入缓冲区。
- `archiveStart`: 是在整个文件中搜索归档的开始，还是仅在开头搜索。
- `format`: 输入归档的格式。
- `password`: (可选) 打开输入归档所需的密码。

*(其他构造函数文档格式类似，描述其参数和用途，此处省略以节省空间)*

### `~BitArchiveReader() override = default`

`BitArchiveReader` 析构函数。

**注意**
它释放输入归档文件。

### `const tstring& archivePath() const noexcept`

返回到归档的路径（对于缓冲区/流归档，返回空字符串）。

### `std::map<BitProperty, BitPropVariant> archiveProperties() const`

返回所有可用（即非空）归档属性及其各自值的映射。

### `BitPropVariant archiveProperty( BitProperty property ) const`

获取指定的归档属性。

**参数：**

- `property`: 要检索的属性。

返回归档属性的当前值，如果没有指定值，则返回空的 `BitPropVariant`。

### `BitInputArchive::ConstIterator begin() const noexcept`

返回到归档第一个元素的迭代器；如果归档为空，则返回的迭代器将等于 `end()` 迭代器。

### `BitInputArchive::ConstIterator cbegin() const noexcept`

返回到归档第一个元素的迭代器；如果归档为空，则返回的迭代器将等于 `end()` 迭代器。

### `BitInputArchive::ConstIterator cend() const noexcept`

返回到归档最后一个元素之后元素的迭代器；此元素充当占位符：尝试访问它会导致未定义行为。

### `void clearPassword() noexcept`

清除处理程序当前使用的密码。调用 `clearPassword()` 将禁用归档的加密/解密。

**注意**
这等效于调用 `setPassword(L"")`。

### `bool contains( const tstring& path ) const noexcept`

查找归档中是否存在具有给定路径的项。

**参数：**

- `path`: 要在归档中搜索的路径。

当且仅当归档中存在具有给定路径的项时返回 `true`。

### `const BitInFormat& detectedFormat() const noexcept`

返回文件的检测到的格式。

### `BitInputArchive::ConstIterator end() const noexcept`

返回到归档最后一个元素之后元素的迭代器；此元素充当占位符：尝试访问它会导致未定义行为。

### `const BitInFormat& extractionFormat() const noexcept`

返回归档打开器使用的归档格式。

### `void extractTo( byte_t* buffer, std::size_t size, uint32_t index = 0 ) const`

将文件提取到预分配的输出缓冲区。

**参数：**

- `buffer`: 预分配的输出缓冲区。
- `size`: 输出缓冲区的大小（必须等于要提取的项的未打包大小）。
- `index`: 要提取的文件的索引。

*(其他 `extractTo` 重载文档格式类似，描述其参数和用途，此处省略以节省空间)*

### `FileCallback fileCallback() const`

返回当前的文件回调。

### `uint32_t filesCount() const`

返回归档中包含的文件数。

### `BitInputArchive::ConstIterator find( const tstring& path ) const noexcept`

在归档中查找具有给定路径的项。

**参数：**

- `path`: 要在归档中搜索的路径。

返回到具有给定路径的项的迭代器，如果未找到项，则返回到等于 `end()` 迭代器的迭代器。

### `uint32_t foldersCount() const`

返回归档中包含的文件夹数。

### `[virtual] const BitInFormat& format() const noexcept`

返回归档打开器使用的归档格式。

### `const BitAbstractArchiveHandler& handler() const noexcept`

返回包含读取归档设置的 `BitAbstractArchiveHandler` 对象。

### `bool hasEncryptedItems() const`

当且仅当归档至少有一个加密项时返回 `true`。

### `bool isEncrypted() const`

当且仅当归档只有加密项时返回 `true`。

### `bool isItemEncrypted( uint32_t index ) const`

**参数：**

- `index`: 归档中项的索引。

当且仅当给定索引处的项已加密时返回 `true`。

### `bool isItemFolder( uint32_t index ) const`

**参数：**

- `index`: 归档中项的索引。

当且仅当给定索引处的项是文件夹时返回 `true`。

### `bool isMultiVolume() const`

当且仅当归档由多个卷组成时返回 `true`。

### `bool isPasswordDefined() const noexcept`

返回一个布尔值，指示是否已定义密码。

### `bool isSolid() const`

当且仅当归档是使用固实压缩创建时返回 `true`。

### `BitArchiveItemOffset itemAt( uint32_t index ) const`

检索给定索引处的项。

**参数：**

- `index`: 要检索的项的索引。

返回归档内给定索引处的项。

### `BitPropVariant itemProperty( uint32_t index, BitProperty property ) const`

获取归档中项的指定属性。

**参数：**

- `index`: 项在归档中的索引。
- `property`: 要检索的属性。

返回项属性的当前值，如果该项没有该属性的值，则返回空的 `BitPropVariant`。

### `std::vector<BitArchiveItemInfo> items() const`

返回所有归档项的向量，作为 `BitArchiveItem` 对象。

### `uint32_t itemsCount() const`

返回归档中包含的项数。

### `const Bit7zlibrary& library() const noexcept`

返回处理程序使用的 `Bit7zlibrary` 对象。

### `OverwriteMode overwriteMode() const`

返回当前的 `OverwriteMode`。

### `uint64_t packSize() const`

返回归档内容的总压缩大小。

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

### `uint64_t size() const`

返回归档内容的总未压缩大小。

### `void test() const`

测试归档而不提取其内容。如果归档无效，则抛出 `BitException`！

### `void testItem( uint32_t index ) const`

测试归档内给定索引处的项而不提取它。如果归档无效，或者给定索引处没有项，则抛出 `BitException`！

**参数：**

- `index`: 要测试的文件的索引。

### `TotalCallback totalCallback() const`

返回当前的总回调。

### `void useFormatProperty( const wchar_t* name, const BitPropVariant& property ) const`

使用给定的格式属性来读取归档。

**参数：**

- `name`: 属性的名称。
- `property`: 属性值。

### `void useFormatProperty( const wchar_t* name, T&& value ) const`

使用给定的格式属性来读取归档。

**参数：**

- `name`: 属性的名称。
- `value`: 属性值。

### `uint32_t volumesCount() const`

返回组成归档的卷数。

### `[static] bool isEncrypted( const Bit7zlibrary& lib, T&& inArchive, const BitInFormat& format = BitFormat::Auto )`

检查给定归档是否仅包含加密项。

**注意**
头加密的归档也是加密的，但反之则不一定成立。

**注意**
归档可能同时包含明文和加密文件；在这种情况下，此函数将返回 `false`。

**参数：**

- `lib`: 使用的 7z 库。
- `inArchive`: 要读取的归档。
- `format`: 输入归档的格式。

当且仅当归档只有加密项时返回 `true`。

### `[static] bool isHeaderEncrypted( const Bit7zlibrary& lib, T&& inArchive, const BitInFormat& format = BitFormat::Auto )`

检查给定归档是否头加密。

**参数：**

- `lib`: 使用的 7z 库。
- `inArchive`: 要读取的归档。
- `format`: 输入归档的格式。

当且仅当归档至少有一个加密项时返回 `true`。

---

# BitArchiveWriter

*Oz edited this page on Dec 16, 2024 · 10 revisions*

---

`BitArchiveWriter` 类允许创建新归档或使用新项更新旧归档。

`#include <bit7z/bitarchivewriter.hpp>`

*继承自 **BitAbstractArchiveCreator**, **BitOutputArchive**。*

## 所有成员列表

### 公共成员

| 返回类型 | 名称 |
|---|---|
| | `BitArchiveWriter( const Bit7zlibrary& lib, const BitInOutFormat& format )` |
| | `BitArchiveWriter( const Bit7zlibrary& lib, const buffer_t& inArchive, ArchiveStartOffset startOffset, const BitInOutFormat& format, const tstring& password = {} )` |
| | `BitArchiveWriter( const Bit7zlibrary& lib, const std::vector< byte_t >& inArchive, const BitInOutFormat& format, const tstring& password = {} )` |
| | `BitArchiveWriter( const Bit7zlibrary& lib, const tstring& inArchive, ArchiveStartOffset startOffset, const BitInOutFormat& format, const tstring& password = {} )` |
| | `BitArchiveWriter( const Bit7zlibrary& lib, const tstring& inArchive, const BitInOutFormat& format, const tstring& password = {} )` |
| | `BitArchiveWriter( const Bit7zlibrary& lib, std::istream& inArchive, ArchiveStartOffset startOffset, const BitInOutFormat& format, const tstring& password = {} )` |
| | `BitArchiveWriter( const Bit7zlibrary& lib, std::istream& inArchive, const BitInOutFormat& format, const tstring& password = {} )` |
| `void` | `addDirectory( const tstring& inDir )` |
| `void` | `addDirectoryContents( const tstring& inDir, const tstring& filter, bool recursive )` |
| `void` | `addDirectoryContents( const tstring& inDir, const tstring& filter = "*", FilterPolicy policy = FilterPolicy::Include, bool recursive = true )` |
| `void` | `addFile( const std::vector< byte_t >& inBuffer, const tstring& name )` |
| `void` | `addFile( const tstring& inFile, const tstring& name = {} )` |
| `void` | `addFile( std::istream& inStream, const tstring& name )` |
| `void` | `addFiles( const std::vector< tstring >& inFiles )` |
| `void` | `addFiles( const tstring& inDir, const tstring& filter, bool recursive )` |
| `void` | `addFiles( const tstring& inDir, const tstring& filter = "*", FilterPolicy policy = FilterPolicy::Include, bool recursive = true )` |
| `void` | `addItems( const std::map< tstring, tstring >& inPaths )` |
| `void` | `addItems( const std::vector< tstring >& inPaths )` |
| `void` | `clearPassword() noexcept` |
| `const BitInOutFormat&` | `compressionFormat() const noexcept` |
| `BitCompressionLevel` | `compressionLevel() const noexcept` |
| `BitCompressionMethod` | `compressionMethod() const noexcept` |
| `void` | `compressTo( const tstring& outFile )` |
| `void` | `compressTo( std::ostream& outStream )` |
| `void` | `compressTo( std::vector< byte_t >& outBuffer )` |
| `const BitAbstractArchiveCreator&` | `creator() const noexcept` |
| `bool` | `cryptHeaders() const noexcept` |
| `uint32_t` | `dictionarySize() const noexcept` |
| `FileCallback` | `fileCallback() const` |
| `[virtual] const BitInFormat&` | `format() const noexcept` |
| `const BitAbstractArchiveHandler&` | `handler() const noexcept` |
| `bool` | `isPasswordDefined() const noexcept` |
| `uint32_t` | `itemsCount() const` |
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

### `BitArchiveWriter( const Bit7zlibrary& lib, const BitInOutFormat& format )`

构造一个空的 `BitArchiveWriter` 对象，可以写入指定格式的归档。

**参数：**

- `lib`: 要使用的 7z 库。
- `format`: 输出归档格式。

*(其他构造函数文档格式类似，描述其参数和用途，此处省略以节省空间)*

### `void addDirectory( const tstring& inDir )`

添加给定的目录路径及其所有内容。

**参数：**

- `inDir`: 要添加到归档中的目录路径。

*(`addDirectoryContents`, `addFile`, `addFiles`, `addItems` 等方法与 `BitArchiveEditor` 中的对应方法非常相似，文档也类似，此处省略以节省空间)*

### `void clearPassword() noexcept`

清除处理程序当前使用的密码。调用 `clearPassword()` 将禁用归档的加密/解密。

**注意**
这等效于调用 `setPassword(L"")`。

### `const BitInOutFormat& compressionFormat() const noexcept`

返回用于创建/更新归档的格式。

### `BitCompressionLevel compressionLevel() const noexcept`

返回用于创建/更新归档的压缩级别。

### `BitCompressionMethod compressionMethod() const noexcept`

返回用于创建/更新归档的压缩方法。

### `void compressTo( const tstring& outFile )`

将此对象添加的所有项压缩到指定的归档文件路径。

**注意**
如果此对象是通过传递输入归档文件路径创建的，并且该路径与 `outFile` 路径参数相同，则该文件将被更新。

**参数：**

- `outFile`: 输出归档文件路径。

### `void compressTo( std::ostream& outStream )`

将此对象添加的所有项压缩到指定的缓冲区。

**参数：**

- `outStream`: 输出标准流。

### `void compressTo( std::vector< byte_t >& outBuffer )`

将此对象添加的所有项压缩到指定的缓冲区。

**参数：**

- `outBuffer`: 输出缓冲区。

### `const BitAbstractArchiveCreator& creator() const noexcept`

返回一个包含写入输出归档设置的 `BitAbstractArchiveHandler` 对象的常量引用。

### `bool cryptHeaders() const noexcept`

返回创建者是否也加密归档的头信息。

### `uint32_t dictionarySize() const noexcept`

返回用于创建/更新归档的字典大小。

### `FileCallback fileCallback() const`

返回当前的文件回调。

### `[virtual] const BitInFormat& format() const noexcept`

返回用于创建/更新归档的格式。

### `const BitAbstractArchiveHandler& handler() const noexcept`

返回一个包含写入输出归档设置的 `BitAbstractArchiveHandler` 对象的常量引用。

### `bool isPasswordDefined() const noexcept`

返回一个布尔值，指示是否已定义密码。

### `uint32_t itemsCount() const`

返回添加到输出归档对象的总项数。

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

*(`setCompressionLevel`, `setCompressionMethod`, `setDictionarySize`, `setFileCallback`, `setFormatProperty`, `setOverwriteMode`, `setPassword`, `setPasswordCallback`, `setProgressCallback`, `setRatioCallback`, `setRetainDirectories`, `setSolidMode`, `setStoreSymbolicLinks`, `setThreadsCount`, `setTotalCallback`, `setUpdateMode`, `setVolumeSize`, `setWordSize` 等方法与 `BitArchiveEditor` 中的对应方法非常相似，文档也类似，此处省略以节省空间)*

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
