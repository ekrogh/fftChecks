/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#include <cstring>

namespace BinaryData
{

//================== cmp_version.h.in ==================
static const unsigned char temp_binary_data_0[] =
"#pragma once\r\n"
"\r\n"
"#cmakedefine PROJECT_VERSION_MAJOR @PROJECT_VERSION_MAJOR@\r\n"
"#cmakedefine PROJECT_VERSION_MINOR @PROJECT_VERSION_MINOR@\r\n"
"#cmakedefine PROJECT_VERSION_PATCH @PROJECT_VERSION_PATCH@\r\n"
"\r\n"
"#ifndef PROJECT_VERSION_MINOR\r\n"
"#define PROJECT_VERSION_MINOR 0\r\n"
"#endif\r\n"
"\r\n"
"#ifndef PROJECT_VERSION_PATCH\r\n"
"#define PROJECT_VERSION_PATCH 0\r\n"
"#endif\r\n"
"\r\n"
"#define VERSION_V v\r\n"
"\r\n"
"#define API_VERSION_MAJOR VERSION_V ## PROJECT_VERSION_MAJOR";

const char* cmp_version_h_in = (const char*) temp_binary_data_0;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes);
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0xcb5b45bc:  numBytes = 429; return cmp_version_h_in;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "cmp_version_h_in"
};

const char* originalFilenames[] =
{
    "cmp_version.h.in"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
        if (strcmp (namedResourceList[i], resourceNameUTF8) == 0)
            return originalFilenames[i];

    return nullptr;
}

}
