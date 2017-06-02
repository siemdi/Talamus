#ifndef CERRORHANDLER
#define CERRORHANDLER
#include <iostream>

class CErrorHandler
{
public:
    CErrorHandler(){}
    enum EErrors { Debug, Warning, Critical, Fatal };
    void DEBUG(const char *errorMsg) { Write(Debug, errorMsg); }
    void WARNING(const char *errorMsg) { Write(Warning, errorMsg); }
    void CRITICAL(const char *errorMsg) { Write(Critical, errorMsg); }
    void FATAL(const char *errorMsg) { Write(Fatal, errorMsg); }
private:
    void Write(EErrors errorType, const char *errorMsg);
};
#endif // CERRORHANDLER

