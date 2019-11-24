#include <set>

class Message;

class Folder
{
friend class Message;

friend void pushMsg(Message &Msg, Folder &NewFolder);
friend void popMsg(Message &Msg, Folder &OldFolder);
friend void destroyMsg(Message &Msg);
friend void destroyFolder(Folder &Folder);

public:
    Folder(const std::string &FolderName);
    Folder(const Folder &OriFolder);
    Folder & operator=(const Folder &OriFolder);
    ~Folder();

private:
    void deleteFolderFromAllMsgs();
    void addFolderToAllMsgs();

private:
    inline void addMsg(Message *pNewMsg)
    {
        m_MsgGroup.insert(pNewMsg);
    }

    inline void deleteMsg(Message *pOldMsg)
    {
        m_MsgGroup.erase(pOldMsg);
    }

public:
    void printFolderName();
    void printAllMsg();

private:
    std::string m_FolderName;
    std::set<Message *> m_MsgGroup;
};
