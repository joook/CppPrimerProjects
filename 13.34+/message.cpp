#include <iostream>
#include "message.h"
#include "folder.h"

using namespace std;

Message::Message(const string &Text = "")
: m_Text(make_shared<string>(Text))
{
}

Message::Message(const Message &OriMsg)
: m_Text(make_shared<string>(*OriMsg.m_Text))
, m_FolderGroup(OriMsg.m_FolderGroup)
{
    pushMsgToAllFolders();
}

Message & Message::operator=(const Message &OriMsg)
{
    popMsgFromAllFolders();

    m_Text = make_shared<string>(*OriMsg.m_Text);
    m_FolderGroup = OriMsg.m_FolderGroup;

    pushMsgToAllFolders();

    return *this;
}

Message::~Message()
{
    popMsgFromAllFolders();
}

void Message::pushMsgToAllFolders()
{
    for(auto pFolder : m_FolderGroup)
    {
        if(pFolder)
        {
            pFolder->addMsg(this);
        }
        else
        {
            //do nothing
        }
    }
}

void Message::popMsgFromAllFolders()
{
    for(auto pFolder : m_FolderGroup)
    {
        if(pFolder)
        {
            pFolder->deleteMsg(this);
        }
        else
        {
            //do nothing
        }
    }
}

void Message::printText()
{
    cout << *m_Text << endl;
}

void Message::printLocation()
{
    for(auto pFolder : m_FolderGroup)
    {
        if(pFolder)
        {
            pFolder->printFolderName();
        }
        else
        {
            //do nothing
        }
    }
}




void pushMsg(Message &Msg, Folder &NewFolder)
{
    Msg.addFolder(&NewFolder);
    NewFolder.addMsg(&Msg);
}

void popMsg(Message &Msg, Folder &OldFolder)
{
    Msg.deleteFolder(&OldFolder);
    OldFolder.deleteMsg(&Msg);
}
void destroyMsg(Message &Msg)
{
}

void destroyFolder(Folder &Folder)
{
}
