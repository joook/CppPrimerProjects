#include "message.h"
#include "folder.h"
#include <iostream>

using namespace std;

int main()
{
    Folder SendBox1("SendBox1");
    Message Msg1("Go to Beijing.");
    Message Msg2("Book a hotel.");
    pushMsg(Msg1, SendBox1);
    pushMsg(Msg2, SendBox1);

    Folder SendBox2("SendBox2");
    Message Msg3(Msg1);
    Message Msg4("Book a ticket.");
    pushMsg(Msg3, SendBox2);
    pushMsg(Msg4, SendBox2);

    Msg4 = Msg2;
    popMsg(Msg2, SendBox1);

    cout << "Msg1: " << endl;
    Msg1.printText();
    cout << "Msg1 locates at folder: " << endl;
    Msg1.printLocation();

    cout << endl;

    cout << "Msg2: " << endl;
    Msg2.printText();
    cout << "Msg2 locates at folder: " << endl;
    Msg2.printLocation();

    cout << endl;

    cout << "Msg3: " << endl;
    Msg3.printText();
    cout << "Msg3 locates at folder: " << endl;
    Msg3.printLocation();

    cout << endl;

    cout << "Msg4: " << endl;
    Msg4.printText();
    cout << "Msg4 locates at folder: " << endl;
    Msg4.printLocation();

    return 0;
}
