#include "HttpOp.h"
// set send data for class member
HttpOp* HttpOp::data(QString sdata)
{
    this->mdata = sdata;
    this->mQdataArray.append(sdata.toStdString());
    this->mNetRequest.setHeader(QNetworkRequest::ContentLengthHeader, this->mQdataArray);
    return this;
}
// set send mode (post or get)
HttpOp* HttpOp::mode(QString smode)
{
    this->mmode = smode;
    return this;
}
void HttpOp::init()
{
    mNetManager = new QNetworkAccessManager();
    //this->mNetRequest.setRawHeader("Accept","*/*");
    //this->mNetRequest.setRawHeader("Accept-Language","zh-CN,zh;q=0.8,gl;q=0.6,zh-TW;q=
    //this->mNetRequest.setRawHeader("Connection","keep-alive");
    //this->mNetRequest.setRawHeader("Host","music.163.com");
    this->mNetRequest.setRawHeader(QByteArray("Last-Modified"), QByteArray("Sun, 06 Nov 1994 08:49:37 GMT"));
    this->mNetRequest.setHeader(QNetworkRequest::UserAgentHeader,"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.84 Safari/537.36");
    this->mNetRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    //this->mNetRequest.setHeader(QNetworkRequest::CookieHeader,"appver=1.5.2");
}
HttpOp* HttpOp::url(QString surl)
{
    this->mUrl = surl;
    this->mNetRequest.setUrl(QUrl(surl));
    return this;
}
// Structure function
HttpOp::HttpOp()
{
    this->mode(GET);
    this->init();
}
HttpOp::~HttpOp()
{
    delete this->mNetManager;
}
// send data
QNetworkAccessManager* HttpOp::send(QNetworkReply* &reply)
{
    if(this->mmode == POST)
        reply = mNetManager->post(this->mNetRequest,this->mQdataArray);
    else
    {
        this->mNetRequest.setUrl(QUrl(QString(this->mUrl)));
        reply = mNetManager->get(this->mNetRequest);
    }
    return mNetManager;
}
