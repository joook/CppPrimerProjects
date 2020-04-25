#ifndef _ACCESS_SPECIFER_H_
#define _ACCESS_SPECIFER_H_

class Base
{
public:
    int m_PublicMember = 2;
protected:
    int m_ProtectedMember = 1;
private:
    int m_PrivateMember = 0;
};

class Pub : public Base
{
};

class Prot : protected Base
{
};

class Priv : private Base
{
};

class DerivedFromPub : public Pub
{
public:
    int func() { return m_PublicMember; }
};

class DerivedFromProt : public Prot
{
public:
    int func() { return m_PublicMember; }
};

class DerivedFromPriv : public Priv
{
public:
    //int func() { return m_PublicMember; }
};

#endif
