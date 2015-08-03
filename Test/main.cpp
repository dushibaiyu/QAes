#include <QCoreApplication>
#include <QCryptographicHash>
#include <QDebug>
#include "qaeswrap.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    QByteArray data = "12345678901234567890";
    qDebug() << "Sha3_256 size:" << data.size() << "  data:" << data;

     qDebug() << "\naes_ctr" ;
    QAesWrap aes("dushibaiyu","dushibaiyu.com",QAesWrap::AES_256);
    QByteArray mdata = aes.encrypt(data,QAesWrap::AES_CTR);
    qDebug() << "mdata size : " << mdata.size() << "  mdata:" <<  mdata.toHex();

    aes.decrypt(mdata,data,QAesWrap::AES_CTR);
    qDebug() << "data size:" << data.size() << "  data:" << data;

    qDebug() << "\n\naes_ecb None:" ;

    aes.encrypt(data,mdata,QAesWrap::AES_ECB,QAesWrap::None);
    qDebug() << "mdata size : " << mdata.size() << "  mdata:" <<  mdata.toHex();

    aes.decrypt(mdata,data,QAesWrap::AES_ECB,QAesWrap::None);
    qDebug() << "data size:" << data.size() << "  data:" << data;


    qDebug() << "\n\naes_cbc None:" ;

    aes.encrypt(data,mdata,QAesWrap::AES_CBC,QAesWrap::None);
    qDebug() << "mdata size : " << mdata.size() << "  mdata:" <<  mdata.toHex();

    aes.decrypt(mdata,data,QAesWrap::AES_CBC,QAesWrap::None);
    qDebug() << "data size:" << data.size() << "  data:" << data;


    qDebug() << "\n\naes_ecb PKCS7:" ;

    aes.encrypt(data,mdata,QAesWrap::AES_ECB,QAesWrap::PKCS7);
    qDebug() << "mdata size : " << mdata.size() << "  mdata:" <<  mdata.toHex();

    aes.decrypt(mdata,data,QAesWrap::AES_ECB,QAesWrap::PKCS7);
    qDebug() << "data size:" << data.size() << "  data:" << data;


    qDebug() << "\n\naes_cbc PKCS7:" ;

    aes.encrypt(data,mdata,QAesWrap::AES_CBC,QAesWrap::PKCS7);
    qDebug() << "mdata size : " << mdata.size() << "  mdata:" <<  mdata.toHex();

    aes.decrypt(mdata,data,QAesWrap::AES_CBC,QAesWrap::PKCS7);
    qDebug() << "data size:" << data.size() << "  data:" << data;

    qDebug() << "\n\naes_ecb ANSIX923:" ;

    aes.encrypt(data,mdata,QAesWrap::AES_ECB,QAesWrap::ANSIX923);
    qDebug() << "mdata size : " << mdata.size() << "  mdata:" <<  mdata.toHex();

    aes.decrypt(mdata,data,QAesWrap::AES_ECB,QAesWrap::ANSIX923);
    qDebug() << "data size:" << data.size() << "  data:" << data;


    qDebug() << "\n\naes_cbc ANSIX923:" ;

    aes.encrypt(data,mdata,QAesWrap::AES_CBC,QAesWrap::ANSIX923);
    qDebug() << "mdata size : " << mdata.size() << "  mdata:" <<  mdata.toHex();

    aes.decrypt(mdata,data,QAesWrap::AES_CBC,QAesWrap::ANSIX923);
    qDebug() << "data size:" << data.size() << "  data:" << data;

    return a.exec();
}
