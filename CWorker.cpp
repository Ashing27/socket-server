#include "CWorker.h"
#include <iostream>

CWorker::CWorker()
    : m_WorkerThread(nullptr)
{
}

CWorker::~CWorker()
{
    m_WorkerThread->join();
}

std::mutex CWorker::m_InstanceLock;

CWorker* CWorker::m_pInstance = nullptr;

CWorker* CWorker::GetInstance()
{
    if ( m_pInstance == nullptr )
    {
        m_InstanceLock.lock();

        if ( m_pInstance == nullptr )
        {
            m_pInstance = new CWorker();
            m_InstanceLock.unlock();
            return m_pInstance;
        }       
    }
    m_InstanceLock.unlock();
    return m_pInstance;
}

bool CWorker::InitWorker()
{
    m_WorkerThread = new (std::nothrow) std::thread(&BusiThread, this);
    if ( m_WorkerThread == nullptr )
    {
        std::cout<<" Error when create InitWorker thread. "<<std::endl;
    }
    return true;
}

unsigned int CWorker::BusiThread( void * Para )
{



    std::cout<< "AAA" <<std::endl;
    return 0;
}
