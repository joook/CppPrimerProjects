#ifndef _QUERY_H_
#define _QUERY_H_

#include <string>
#include <memory>
#include "shared_text.h"
#include "search_result.h"

class QueryBase
{
friend class Query;

protected:
    QueryBase() = default;
public:
    virtual ~QueryBase() = default;

    virtual SearchResult getResult() = 0;
    static const SharedText &getText() { return m_Text; }

private:
    static void setText(const SharedText &Text) { m_Text = Text; }

private:
    static SharedText m_Text;
};

class Query
{
friend Query operator~(const Query &OriQuery);
friend Query operator&(const Query &Query1, const Query &Query2);
friend Query operator|(const Query &Query1, const Query &Query2);

private:
    Query(std::shared_ptr<QueryBase> QueryBasePtr)
    : m_QueryBasePtr(QueryBasePtr)
    {
    }

public:
    Query(const std::string &KeyWord);

    static void setText(const SharedText &Text)
    {
        QueryBase::setText(Text);
    }
    SearchResult getResult() { return m_QueryBasePtr->getResult(); }

private:
    std::shared_ptr<QueryBase> m_QueryBasePtr;
};

class WordQuery : public QueryBase
{
public:
    WordQuery(const std::string &KeyWord)
    : QueryBase()
    , m_KeyWord(KeyWord)
    {
    }

protected:
    virtual SearchResult getResult() override;

private:
    std::string m_KeyWord;
};

class NotQuery : public QueryBase
{
public:
    NotQuery(const Query &OriQuery)
    : QueryBase()
    , m_OriQuery(OriQuery)
    {
    }

protected:
    virtual SearchResult getResult() override;

private:
    Query m_OriQuery;
};

class BinaryQuery : public QueryBase
{
public:
    BinaryQuery(const Query &Query1, const Query &Query2)
    : QueryBase()
    , m_Query1(Query1)
    , m_Query2(Query2)
    {
    }

public:
    Query m_Query1;
    Query m_Query2;
};

class AndQuery: public BinaryQuery
{
public:
    AndQuery(const Query &Query1, const Query &Query2)
    : BinaryQuery(Query1, Query2)
    {
    }

protected:
    virtual SearchResult getResult() override;
};

class OrQuery : public BinaryQuery
{
public:
    OrQuery(const Query &Query1, const Query &Query2)
    : BinaryQuery(Query1, Query2)
    {
    }

protected:
    virtual SearchResult getResult() override;
};

#endif
