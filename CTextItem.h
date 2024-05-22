#ifndef CTEXTITEM_H
#define CTEXTITEM_H

#include <QGraphicsItem>
#include <QDebug>
#include <QInputEvent>
#include <QFontMetrics>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QTextDocument>
#include <QTextCursor>
#include <QPlainTextDocumentLayout>
#include <QTimer>

class CTextItem : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    CTextItem(const QString &text = "please enter text!", QGraphicsItem *parent = Q_NULLPTR);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private slots:
    void test();
    void calcCursorPos();
    void cursorFlag();
protected:
    virtual void focusOutEvent(QFocusEvent *event);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    // 重写 输入法事件（中文）
    void inputMethodEvent(QInputMethodEvent *event);
    // 字符事件(英文）
    void keyPressEvent(QKeyEvent *event);
private:
    QRectF m_boundingRect;
    QString m_text;
    QTextDocument *m_textDocument;
    QTextCursor *m_textCursor;
    QFont m_font;
    QTimer m_timer; //光标闪烁计时
    QPointF m_textCursorPos1; //光标线段p1点
    QPointF m_textCursorPos2; //光标线段p2点
    bool m_isDisplayTextCursor; //是否显示文本光标
    bool m_isEditing;   //是否编辑状态
};

#endif // CTEXTITEM_H
