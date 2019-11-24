#include <memory>
#include <string>
#include <set>

class Folder;

class Message
{
friend class Folder;

friend void pushMsg(Message &Msg, Folder &NewFolder);
friend void popMsg(Message &Msg, Folder &OldFolder);
friend void destroyMsg(Message &Msg);
friend void destroyFolder(Folder &Folder);

public:
    Message(const std::string &Text);
    Message(const Message &OriMsg);
    Message & operator=(const Message &OriMsg);
    ~Message();

private:
    void pushMsgToAllFolders();
    void popMsgFromAllFolders();

private:
    inline void addFolder(Folder *pNewFolder)
    {
        m_FolderGroup.insert(pNewFolder);
    }

    inline void deleteFolder(Folder *pOldFolder)
    {
        m_FolderGroup.erase(pOldFolder);
    }

public:
    void printText();
    void printLocation();

private:
    std::shared_ptr<std::string> m_Text;
    std::set<Folder *> m_FolderGroup;
};




void pushMsg(Message &Msg, Folder &NewFolder);
void popMsg(Message &Msg, Folder &OldFolder);
void destroyMsg(Message &Msg);
void destroyFolder(Folder &Folder);
