#include <iostream>
#include "shared_string_queue_class.h"
#include "shared_string_queue_ptr_class.h"
#include <fstream>
#include <string>

using namespace std;

#define RET_FAIL (0u)
#define RET_OK (1u)

int readInput(const string FileName, SharedStringQueuePtr &StrQueuePtr)
{
    int Ret = RET_OK;

    ifstream FileStream(FileName);
    if(FileStream.is_open())
    {
        string Line;
        while(getline(FileStream, Line))
        {
            StrQueuePtr.pushStr(Line);
        }

        FileStream.close();
    }
    else
    {
        cout << "Cannot open file." << endl;
        Ret = RET_FAIL;
    }

    return Ret;
}

void printText(SharedStringQueuePtr &StrQueuePtr)
{
    while(StrQueuePtr.isEmpty() == false)
    {
        cout << StrQueuePtr.frontStr() << endl;
        StrQueuePtr.popStr();
    }
    cout << endl;
}

int main()
{
    string FileName = "./text.txt";
    SharedStringQueue StrQueue;
    SharedStringQueuePtr StrQueuePtr(StrQueue);

    try
    {
        if(RET_OK == readInput(FileName, StrQueuePtr))
        {
            printText(StrQueuePtr);
        }
        else
        {
        }
    }
    catch(runtime_error Err)
    {
        cerr << Err.what() << endl;
    }

    return 0;
}
