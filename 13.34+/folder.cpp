#include <iostream>
#include "folder.h"
#include "message.h"

using namespace std;

Folder::Folder(const string &FolderName)
: m_FolderName(FolderName)
{
}

Folder::Folder(const Folder &OriFolder)
: m_FolderName(OriFolder.m_FolderName)
, m_MsgGroup(OriFolder.m_MsgGroup)
{
    addFolderToAllMsgs();
}

Folder &Folder::operator=(const Folder &OriFolder)
{
    deleteFolderFromAllMsgs();

    m_FolderName = OriFolder.m_FolderName;
    m_MsgGroup = OriFolder.m_MsgGroup;
    addFolderToAllMsgs();

    return *this;
}

Folder::~Folder()
{
    deleteFolderFromAllMsgs();
}

void Folder::deleteFolderFromAllMsgs()
{
    for(auto pMsg : m_MsgGroup)
    {
        if(pMsg)
        {
            pMsg->deleteFolder(this);
        }
        else
        {
        }
    }
}

void Folder::addFolderToAllMsgs()
{
    for(auto pMsg : m_MsgGroup)
    {
        if(pMsg)
        {
            pMsg->addFolder(this);
        }
        else
        {
        }
    }
}

void Folder::printFolderName()
{
    cout << m_FolderName << endl;
}

void Folder::printAllMsg()
{
    for(auto pMsg : m_MsgGroup)
    {
        if(pMsg)
        {
            pMsg->printText();
        }
        else
        {
        }
    }
}

