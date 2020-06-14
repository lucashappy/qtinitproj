#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QScopedPointer>
#include <QString>

#include <qtinitproj-lib_global.h>
#include <controllers/navigation-controller.h>

namespace qtinitproj{
namespace controllers {

/**
 * @brief The MasterController class is the main controller of the
 * qtinitproj-lib objects used by the ui.
 */
class QTINITPROJLIB_EXPORT MasterController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString ui_welcomeMessage READ welcomeMessage CONSTANT)
    Q_PROPERTY(qtinitproj::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT)

public:
    explicit MasterController(QObject *parent = nullptr);
    ~MasterController();

    /**
     * @brief Controller that handles the signals for navigating between pages
     * @return
     */
    NavigationController* navigationController();

    const QString& welcomeMessage() const;

    //public slots:

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}
#endif // MASTERCONTROLLER_H
