#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN32) || defined(_WIN64)  
    // 包含Windows特定的头文件  
    #include <windows.h>  
    // 以及其他Windows特有的代码或声明  
#elif defined(__linux__) || defined(__unix__)  
    // 包含Linux或Unix特定的头文件  
    #include <unistd.h>  
    #include <sys/types.h>  
    // 以及其他Linux或Unix特有的代码或声明  
#else  
    // 其他平台的处理，或者错误处理  
    #error "Unsupported platform"  
#endif
