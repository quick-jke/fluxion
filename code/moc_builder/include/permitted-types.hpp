#ifndef MOC_BUILDER_PERMITTED_H
#define MOC_BUILDER_PERMITTED_H



enum PERMITTED_TYPES{
    CHAR = "char",
    SIGNED_CHAR = "signed char",
    UNSIGNED_CHAR = "unsigned char",
    SHORT = "short",
    UNSIGNED_SHORT = "unsigned short",
    INT = "int",
    UNSIGNED_INT = "unsigned int",
    LONG = "long",
    UNSIGNED_LONG = "unsigned long",
    LONG_LONG = "long long",
    UNSIGNED_LONG_LONG = "unsigned long long",

    FLOAT = "float",
    DOUBLE = "double",
    LONG_DOUBLE = "long double",


    STRING = "string" | "std::string",
    
    BOOL = "bool",


};


#endif