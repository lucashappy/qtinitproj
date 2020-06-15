#ifndef COMMAND_H
#define COMMAND_H

#include <functional>

#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <qtinitproj-lib_global.h>

namespace qtinitproj {
namespace framework {

/**
 * @brief The Command class models an UI command like Save
 */
class QTINITPROJLIB_EXPORT Command : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString ui_iconCharacter READ iconCharacter CONSTANT)
    Q_PROPERTY(QString ui_description READ description CONSTANT)
    Q_PROPERTY(bool ui_canExecute READ canExecute NOTIFY canExecuteChanged)

public:
    explicit Command(QObject *parent = nullptr,
                     const QString& iconCharacter = "",
                     const QString& description = "",
        std::function<bool()> canExecute = [](){ return true; });
    ~Command();
    /// The icon string to illustrate the command (like a floppy disk for Save)
    const QString& iconCharacter() const;
    /// The name of the command ("Save")
    const QString& description() const;
    /// Whether the command is available or not
    bool canExecute() const;

signals:
    void canExecuteChanged();
    void executed();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}

#endif // COMMAND_H
