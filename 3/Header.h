#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN32) || defined(_WIN64)  
    // ����Windows�ض���ͷ�ļ�  
    #include <windows.h>  
    // �Լ�����Windows���еĴ��������  
#elif defined(__linux__) || defined(__unix__)  
    // ����Linux��Unix�ض���ͷ�ļ�  
    #include <unistd.h>  
    #include <sys/types.h>  
    // �Լ�����Linux��Unix���еĴ��������  
#else  
    // ����ƽ̨�Ĵ������ߴ�����  
    #error "Unsupported platform"  
#endif
