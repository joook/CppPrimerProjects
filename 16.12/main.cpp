#include <iostream>
#include <string>

#include "shared_queue_template.h"
#include "shared_queue_ptr_template.h"

int main()
{
    SharedQueue<std::string> queue1{"ab", "cd"};
    SharedQueue<std::string> queue2{queue1};

    queue1.pushItem("ef");
    queue2.pushItem("gh");
    queue2.popItem();

    SharedQueuePtr<std::string> queuePtr{queue2};
    if (queuePtr.isNull())
    {
        std::cout << "String queue ptr error." << std::endl;
    }
    else
    {
        while (queuePtr.isEmpty() == false)
        {
            std::cout << queuePtr.frontItem() << std::endl;
            queuePtr.popItem();
        }
    }

    return 0;
}
