#ifndef QAESWRAP_H
#define QAESWRAP_H

extern "C" {
#include "aes.h"
}
#include <QByteArray>


class QAesWrap
{
public:
    enum AesBit {
        AES_128 = 128,
        AES_192 = 192,
        AES_256 = 256
    };
    enum AesMode {
        AES_ECB,
        AES_CBC,
        AES_CTR
    };
    enum PaddingMode {
        None,
        ANSIX923,
        PKCS7
    };
public:
    QAesWrap(const QByteArray & passwprd,const QByteArray & salt,AesBit bit);

    bool encrypt(const QByteArray & in, QByteArray & out, AesMode mode,PaddingMode pad = PKCS7) const;
    bool decrypt(const QByteArray & in, QByteArray & out, AesMode mode,PaddingMode pad = PKCS7) const;

    inline QByteArray encrypt(const QByteArray & data,AesMode mode,PaddingMode pad = PKCS7) const {
          QByteArray out;
          encrypt(data,out,mode,pad);
          return out;
    }

    inline QByteArray decrypt(const QByteArray & data,AesMode mode,PaddingMode pad = PKCS7) const {
          QByteArray out;
          decrypt(data,out,mode,pad);
          return out;
    }
private:
    void ecbencrypt(const BYTE *in, size_t size, BYTE *blcok, QByteArray & out) const;
    void ecbdecrypt(const BYTE *in, size_t size, QByteArray & out) const;
    void initPadding(const QByteArray & in,QByteArray & out,AesMode mode,PaddingMode pad) const;
private:
    AesBit mbit;
    WORD32 mpass[60];
    BYTE msalt[AES_BLOCK_SIZE];
};

#endif // QAESWRAP_H
