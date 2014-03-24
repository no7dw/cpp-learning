#include <stdio.h>
#include <iostream>
#include <pthread.h>
#include <sched.h>
#include <assert.h>

using namespace std;
pthread_attr_t *pattr;
int m_current_policy ;
int rs;
static int get_thread_policy( pthread_attr_t &attr )
{
        int policy;
        int rs = pthread_attr_getschedpolicy( &attr, &policy );
        assert( rs == 0 );
        switch ( policy )
        {
        case SCHED_FIFO:
                cout << "policy = SCHED_FIFO" << endl;
                break;

        case SCHED_RR:
                cout << "policy = SCHED_RR" << endl;
                break;

        case SCHED_OTHER:
                cout << "policy = SCHED_OTHER" << endl;
                break;

        default:
                cout << "policy = UNKNOWN" << endl;
                break;
        }

        return policy;
}

static void show_thread_priority( pthread_attr_t &attr, int policy )
{
        int priority = sched_get_priority_max( policy );
        assert( priority != -1 );
        cout << "max_priority = " << priority << endl;

        priority = sched_get_priority_min( policy );
        assert( priority != -1 );
        cout << "min_priority = " << priority << endl;
}

static int get_thread_priority( pthread_attr_t &attr )
{
        struct sched_param param;

        int rs = pthread_attr_getschedparam( &attr, &param );
        assert( rs == 0 );
        cout << "priority = " << param.__sched_priority << endl;

        return param.__sched_priority;
}

static int set_thread_priority( pthread_attr_t &attr ,const struct sched_param param )
{
        
	
        int rs = pthread_attr_setschedparam( &attr, &param );
        assert( rs == 0 );
        cout << "set priority = " << param.__sched_priority << endl;

        return rs;
}


static int set_thread_policy( pthread_attr_t &attr,  int policy )
{
        int rs = pthread_attr_setschedpolicy( &attr, policy );
        assert( rs == 0 );
        get_thread_policy( attr );
	return rs;
}
static void InitAttr(pthread_attr_t &attr )
{
	pattr = &attr;
	m_current_policy = get_thread_policy( attr );
}

static int SetPriority(int priority)
{
	cout << "set priority of current thread to "<< priority << endl;
	return set_thread_policy( *pattr, SCHED_RR );	
}

static void UnitAttr()
{
	cout << "Restore current policy" << endl;
        set_thread_policy( *pattr, m_current_policy );
	rs = pthread_attr_destroy( pattr );
        assert( rs == 0 );
}
void * thread_test(void* param)
{
	for(int i=0;i<20;i++)
	{
		printf("---------\n");
		sleep(1);
	}
	
}
int main(void)
{
	pthread_attr_t attr;
	pattr = &attr;
	pthread_t test_pid ;
	pthread_create(&test_pid, pattr, thread_test, NULL);
	printf("waiting for thread end\n");
	pthread_join(test_pid, NULL);
	printf("main end\n");
	return 0;
}

/*
int main( void )
{
        pthread_attr_t attr;
        struct sched_param sched;
        

        rs = pthread_attr_init( &attr );
        assert( rs == 0 );

        m_current_policy = get_thread_policy( attr );

        cout << "Show current configuration of priority" << endl;
        show_thread_priority( attr, m_current_policy );

        cout << "Show SCHED_FIFO of priority" << endl;
        show_thread_priority( attr, SCHED_FIFO );

        cout << "Show SCHED_RR of priority" << endl;
        show_thread_priority( attr, SCHED_RR );

        cout << "Show priority of current thread" << endl;
        int priority = get_thread_priority( attr );


        cout << "Set thread policy" << endl;
        cout << "Set SCHED_FIFO policy" << endl;
        set_thread_policy( attr, SCHED_FIFO );
        cout << "Set SCHED_RR policy" << endl;
        set_thread_policy( attr, SCHED_RR );	

	cout << "set priority of current thread to  90" << endl;
	struct sched_param param;
	param.__sched_priority = 90;
	set_thread_priority(attr, param);

        cout << "Restore current policy" << endl;
        set_thread_policy( attr, m_current_policy );

        rs = pthread_attr_destroy( &attr );
        assert( rs == 0 );

        return 0;
}
*/
