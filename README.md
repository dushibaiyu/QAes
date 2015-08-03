# QAes
Qt AES encrypt decrypt <br/>
QByteArry直接使用的AES加密解密。
##########################
###支持的模式：
		ECB,CBC,CTR
###填充模式：
		ANSIX923，PKCS7，None（不填充）
		None：模式下，不是16字节的整数倍的多余的部分不加密。不足16个字节的，都不加密。
		（CTR模式是流式模式，不需要填充。）
###密码模式：
		传进去参数支持任意长度：
		密码：传进去密码后进行Sha3_256计算出hash值作为密码。对于AES256则是全部hash值，128和192则是去前面相应的16个和24个字节值。
		salt: 传进去的salt进行Sha3_256计算出hash值的前16个字节作为salt。（ecb模式下不用salt值的）。

