#include "mainwindow.h"
#include <QApplication>

#include <QTextCodec>
#include <QByteArray>
#include <QLabel>
#include <QDebug>

#include "zstring.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Qt程序全局编码设置
//    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
//    QTextCodec::setCodecForTr(codec);  // QObject::tr("我是中文");
//    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());  // 外部字符串全部采用本地编码
//    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());

//    QString str = QString::fromUtf8("我是汉字");
//    qDebug() << str;

    // 测试文件编码
//    QString coding = ZString::getFileCoding("./test.txt");
//    qDebug() << coding;

    // 程序里直接显示中文
    QTextCodec *c = QTextCodec::codecForName("UTF-8");
    qDebug() << c->toUnicode("我是中文");

    return a.exec();
}
