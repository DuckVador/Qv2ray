#pragma once

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QObject>
#include <functional>

namespace Qv2ray::common::network
{
    class NetworkRequestHelper : QObject
    {
        Q_OBJECT
      public:
        explicit NetworkRequestHelper(QObject *parent) : QObject(parent){};
        ~NetworkRequestHelper(){};
        void AsyncHttpGet(const QString &url, std::function<void(const QByteArray &)> funcPtr);
        static QByteArray HttpGet(const QUrl &url);

      private:
        static void setAccessManagerAttributes(QNetworkRequest &request, QNetworkAccessManager &accessManager);
        static void setHeader(QNetworkRequest &request, const QByteArray &key, const QByteArray &value);
        QNetworkAccessManager accessManager;
    };
} // namespace Qv2ray::common::network

using namespace Qv2ray::common::network;
