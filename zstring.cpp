#include "zstring.h"

#include <QFile>
#include <QDebug>

ZString::ZString(QObject *parent) : QObject(parent)
{

}

QString ZString::getFileCoding(const QString &filePath)
{
    QFile *file = new QFile(filePath);
    if (!file->open(QFile::ReadOnly)) {
        return "";
    }

    qint64 size = file->size();
    char *buf = new char[size];
    file->read(buf, size);
    file->close();

    // 读取文件头
    ///
    /// ANSI: 没有文件头(2字节/汉字,1字节/英文)
    /// UTF-8: 文件头[0xEF,0xBB,0xBF](3字节/汉字,1字节/英文)
    /// Unicode: 文件头[0xFF,0xFE](2字节/汉字,2字节/英文)
    /// Unicode big endian: 文件头[0xFE,0xFF](同Unicode,字节序相反)
    ///
    uchar *p = (uchar*)buf;
    if (0xEF == p[0] && 0xBB == p[1] && 0xBF == p[2]) {
        qDebug() << QString::fromUtf8(buf + 3, size -3);
        return "UFT-8";
    } else if (0xFF == p[0] && 0xFE == p[1]) {
        qDebug() << QString::fromWCharArray((wchar_t*)(buf + 2), (size - 2) / 2);
        return "Unicode";
    } else if (0xFE == p[0] && 0xFF == p[1]) {
        qDebug() << QString::fromWCharArray((wchar_t*)(buf + 2), (size - 2) / 2);
        return "Unicode big endian";
    } else {
        qDebug() << QString::fromLocal8Bit(buf, size);
        return "ANSI";
    }
}
