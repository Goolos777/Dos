//// XMLParser.cpp : Defines the entry point for the console application.
////
//
//#include "stdafx.h"
//
//#include <string>
//
//using namespace std;
//
//class IXMLParserReciver
//{
//public:
//	virtual void onBeginTag(const string& tag) = 0;
//	virtual void onEndTag() = 0;
//
//	virtual void onContent(const string& content) = 0;
//
//	virtual void onAttribute(const string& name, const string& value) = 0;
//
//	virtual void onError() = 0;
//};
//
//class TestXMLParserReciver : public IXMLParserReciver
//{
//	virtual void onBeginTag(const string& tag)
//	{
//	}
//
//	virtual void onEndTag()
//	{
//	}
//
//	virtual void onContent(const string& content)
//	{
//	}
//
//	virtual void onAttribute(const string& name, const string& value)
//	{
//	}
//
//	virtual void onError()
//	{
//	}
//};
//
//class XMLParser
//{
//public:
//	XMLParser(const string& xml, IXMLParserReciver& reciver) :mXML(xml), mReciver(reciver){}
//
//	bool parse()
//	{
//		mError = false;
//
//		size_t position = 0;
//		string block;
//		while (getNextBlock(mXML, position, block))
//		{
//			bool isTag = false;
//			bool isOpenTag = false;
//			bool isCloseTag = false;
//
//			testIsTag(block, isTag, isOpenTag, isCloseTag);
//
//			if (isTag)
//			{
//				string tagName;
//				string attributes;
//
//				if (!getTagNameAndAttributes(block, tagName, attributes))
//				{
//					return false;
//				}
//
//				if (isOpenTag)
//				{
//					mReciver.onBeginTag(tagName);
//
//					size_t attributePosition = 0;
//					string attributeName;
//					string attributeValue;
//
//					while (getNextAttribute(attributes, attributePosition, attributeName, attributeValue))
//					{
//						mReciver.onAttribute(attributeName, attributeValue);
//					}
//				}
//
//				if (isCloseTag)
//				{
//					mReciver.onEndTag();
//				}
//			}
//			else
//			{
//				mReciver.onContent(block);
//			}
//		}
//
//		return !mError;
//	}
//
//private:
//
//	void onError()
//	{
//		mReciver.onError();
//
//
//		mError = true;
//	}
//
//	bool testIsTag(const string& block, bool& isTag, bool& isOpenTag, bool& isCloseTag)
//	{
//		if (mError)
//		{
//			return false;
//		}
//
//		isTag = block.find("<") == 0;
//
//		if (isTag)
//		{
//			isOpenTag = block.find("</") == string::npos;
//			isCloseTag = block.find("</") != string::npos || block.find("/>") != string::npos;
//		}
//
//		return true;
//	}
//
//	bool getTagNameAndAttributes(const string& block, string& tagName, string& attributes)
//	{
//		if (mError)
//		{
//			return false;
//		}
//
//		size_t beginName = block.find_first_not_of("</ ");
//		if (beginName == string::npos)
//		{
//			onError();
//			return false;
//		}
//
//		size_t endName = block.find_first_of(" />", beginName + 1);
//		if (endName == string::npos)
//		{
//			onError();
//			return false;
//		}
//
//		tagName = block.substr(beginName, endName - beginName);
//
//
//		size_t beginAttributes = block.find_first_not_of(" />", endName);
//
//		if (beginAttributes == string::npos)
//		{
//			attributes = "";
//		}
//		else
//		{
//			size_t endAttributes = block.find_first_of("/>", beginAttributes + 1);
//			if (endAttributes == string::npos)
//			{
//				onError();
//				return false;
//			}
//
//			attributes = block.substr(beginAttributes, endAttributes - beginAttributes);
//		}
//
//		return true;
//	}
//
//	bool getNextAttribute(string& atributes, size_t& position, string& name, string& value)
//	{
//		if (mError)
//		{
//			return false;
//		}
//
//		if (atributes.size() <= position)
//		{
//			position = string::npos;
//		}
//
//		if (position == string::npos)
//		{
//			return false;
//		}
//
//		size_t beginName = atributes.find_first_not_of(" ", position);
//
//		if (beginName == string::npos)
//		{
//			return false;
//		}
//
//		size_t endName = atributes.find_first_of(" =", beginName + 1);
//
//		if (endName == string::npos)
//		{
//			return false;
//		}
//
//		name = atributes.substr(beginName, endName - beginName);
//
//		size_t beginValue = atributes.find("\"", endName + 1);
//		if (beginValue == string::npos)
//		{
//			onError();
//			return false;
//		}
//
//		size_t endValue = atributes.find("\"", beginValue + 1);
//		if (beginValue == string::npos)
//		{
//			onError();
//			return false;
//		}
//
//		if (endValue - beginValue <= 1)
//		{
//			value = "";
//		}
//		else
//		{
//			value = atributes.substr(beginValue + 1, endValue - beginValue - 1);
//		}
//
//		position = endValue + 1;
//
//		return true;
//	}
//
//	bool getNextBlock(string& xml, size_t& position, string& result)
//	{
//		if (mError)
//		{
//			return false;
//		}
//
//		if (xml.size() <= position)
//		{
//			position = string::npos;
//		}
//
//		if (position == string::npos)
//		{
//			return false;
//		}
//
//		size_t posBegin = xml.find("<", position);
//
//		if (posBegin == string::npos)
//		{
//			result = xml.substr(position);
//			position = string::npos;
//			return true;
//		}
//		else
//		{
//			if (position != posBegin)
//			{
//				result = xml.substr(position, posBegin - position);
//				position = posBegin;
//				return true;
//			}
//			else
//			{
//				size_t posEnd = xml.find(">", position);
//				if (posEnd == string::npos)
//				{
//					onError();
//					return false;
//				}
//				else
//				{
//					result = xml.substr(position, posEnd - position + 1);
//					position = posEnd + 1;
//					return true;
//				}
//			}
//		}
//	}
//
//private:
//
//	bool mError;
//	string mXML;
//	IXMLParserReciver& mReciver;
//};
//
//
////int _tmain(int argc, _TCHAR* argv[])
////{
////	TestXMLParserReciver reciver;
////
////	// 123<a c="0" d="hello world">456</a><b></b>789<testTag a="123" b="456"/>
////	string xml = "123<a c=\"0\" d=\"hello world\">456</a><b></b>789<testTag a=\"123\" b=\"456\"/>";
////
////	XMLParser parser(xml, reciver);
////
////	bool result = parser.parse();
////
////	return 0;
////}