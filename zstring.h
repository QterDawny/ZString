#ifndef ZSTRING_H
#define ZSTRING_H

#include <QObject>

///
/// QString 是Unicode, 故给他赋值时需告诉它是什么类型的编码, 取值显示时则from相应编码就好
///
/// QTextCodec QString QByteArray
///
class ZString : public QObject
{
    Q_OBJECT
public:
    explicit ZString(QObject *parent = 0);

    static QString getFileCoding(const QString &file);

signals:

public slots:
};

#endif // ZSTRING_H
