#include <atlcore.h>
#include <atlbase.h>
#include <thread>
#include <mutex>


class CWorker
{

public:

    static CWorker * GetInstance();

    bool InitWorker();

private:
    
    static unsigned int __stdcall BusiThread( void * Para );

private:

    CWorker( void );

    ~CWorker( void );

    CWorker( const CWorker& ){}
    ;
    CWorker & operator = ( const CWorker & );

    static CWorker * m_pInstance;

    static std::mutex m_InstanceLock;

    std::thread* m_WorkerThread;

};
