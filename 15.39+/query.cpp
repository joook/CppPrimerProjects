#include "query.h"

using namespace std;

SharedText QueryBase::m_Text;

//cannot use make_shared<QueryBase> here, because make_shared will
//try to make a new QueryBase object, while QueryBase is a virtual class
Query::Query(const std::string &KeyWord)
: m_QueryBasePtr(shared_ptr<QueryBase>(new WordQuery(KeyWord)))
{
}

SearchResult WordQuery::getResult()
{
    return getText().search(m_KeyWord);
}

SearchResult AndQuery::getResult()
{
    return (m_Query1.getResult() & m_Query2.getResult());
}

SearchResult OrQuery::getResult()
{
    return (m_Query1.getResult() | m_Query2.getResult());
}

Query operator&(const Query &Query1, const Query &Query2)
{
    return Query(make_shared<AndQuery>(Query1, Query2));
}

Query operator|(const Query &Query1, const Query &Query2)
{
    return Query(make_shared<OrQuery>(Query1, Query2));
}

