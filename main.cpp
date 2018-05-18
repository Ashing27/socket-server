#include <iostream>
#include <thread>
#include <mutex>
#include "CWorker.h"

int main(_In_ int _Argc, _In_reads_(_Argc) _Pre_z_ char ** _Argv, _In_z_ char ** _Env)
{
    
    CWorker* pWorker = CWorker::GetInstance();
    pWorker->InitWorker();
    
    getchar();
    return 0;
}

