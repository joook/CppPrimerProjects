#include <iostream>
#include "shared_string_queue_class.h"
#include "shared_string_queue_ptr_class.h"

using namespace std;

int main()
{
    SharedStringQueuePtr TempQueue;

    try
    {
        {
            SharedStringQueue OriQueue({"cat", "dog"});
            TempQueue = OriQueue;

            TempQueue.popStr();
            //TempQueue.popStr();
            //TempQueue.popStr();
            cout << "Front str: " << TempQueue.frontStr() << endl;
        }

        cout << "Front str: " << TempQueue.frontStr() << endl;
    }
    catch(runtime_error Err)
    {
        cerr << Err.what() << endl;
    }

    return 0;
}
