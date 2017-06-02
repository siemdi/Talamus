#include "errorhandler.h"

void CErrorHandler::Write(EErrors errorType, const char *errorMsg)
{
    switch (errorType)
    {
    case Debug:
        std::cout<<"\033[1;32mDebug: "<<errorMsg<<"\033[0m"<<std::endl;
        break;
    case Warning:
        std::cout<<"\033[1;33mWarning: "<<errorMsg<<"\033[0m"<<std::endl;
        break;
    case Critical:
        std::cout<<"\033[1;35mCritical: "<<errorMsg<<"\033[0m"<<std::endl;
        break;
    case Fatal:
        std::cout<<"\033[1;31mFatal: "<<errorMsg<<"\033[0m"<<std::endl;
        break;
    default:
        break;
    }
}
