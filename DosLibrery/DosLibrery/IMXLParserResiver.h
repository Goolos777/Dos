#pragma once
#include <string>
using namespace std;
class IMXLParserResiver
{

public:
	virtual void onBeginTag(const string& tag) = 0;
	virtual void onEndTag() = 0;
	virtual void onContent(const string& content) = 0;
	virtual void onAttribute(const string& name, const string& value) = 0;
	virtual void onError() = 0;
	~IMXLParserResiver();
};

