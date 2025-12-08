#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>
#include "contact.h"

// режимы сохранения
// 1 — создать новый файл (перезаписать)
// 2 — дописать в конец
bool saveToFile(const std::string& filename, int mode);
bool loadFromFile(const std::string& filename);

#endif
