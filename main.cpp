#include "src/basiccontroller.h"

#include <QApplication>
#include <QDir>
#include <QQmlApplicationEngine>
#include <QQmlContext>

namespace {

const QString REGISTER_OBJECT =
    QStringLiteral("Object called '%1' has been registered in QML part of application");

namespace MetaObjectUtils {
constexpr char BASIC_CONTROLLER[] = "BasicController";
constexpr char QUIZ_MENU_PAGE_MODEL[] = "QuizMenuPageModel";
constexpr char STUDY_MENU_PAGE_MODEL[] = "StudyMenuPageModel";
constexpr char QUIZ_QUESTION_MODEL[] = "QuizQuestionModel";
const QString UNCREATABLE_OBJECT =
    QStringLiteral("Couldn't create object %1, because it can be used only for accessing C++ enums");

void registerMetaObjects() {
  // Necessary to use C++ enums in QML part of application
  qmlRegisterUncreatableMetaObject(BasicController::staticMetaObject, BASIC_CONTROLLER, 1, 0,
                                   BASIC_CONTROLLER, UNCREATABLE_OBJECT.arg(BASIC_CONTROLLER));
  qmlRegisterUncreatableMetaObject(QuizMenuPageModel::staticMetaObject, QUIZ_MENU_PAGE_MODEL, 1, 0,
                                   QUIZ_MENU_PAGE_MODEL, UNCREATABLE_OBJECT.arg(QUIZ_MENU_PAGE_MODEL));
  qmlRegisterUncreatableMetaObject(StudyMenuPageModel::staticMetaObject, STUDY_MENU_PAGE_MODEL, 1, 0,
                                   STUDY_MENU_PAGE_MODEL, UNCREATABLE_OBJECT.arg(STUDY_MENU_PAGE_MODEL));
  qmlRegisterUncreatableMetaObject(QuizQuestionModel::staticMetaObject, QUIZ_QUESTION_MODEL, 1, 0,
                                   QUIZ_QUESTION_MODEL, UNCREATABLE_OBJECT.arg(QUIZ_QUESTION_MODEL));
}
} // namespace MetaObjectUtils

} // namespace

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

  QObject::connect(&engine, &QQmlApplicationEngine::exit, &app, &QApplication::exit, Qt::QueuedConnection);
  QObject::connect(&engine, &QQmlApplicationEngine::quit, &app, &QApplication::quit, Qt::QueuedConnection);

  BasicController* basicController = new BasicController(&app);

  for (const auto& [name, object] : basicController->getObjectsToRegister()) {
    engine.rootContext()->setContextProperty(name, object);
    qDebug() << REGISTER_OBJECT.arg(name);
  }

  MetaObjectUtils::registerMetaObjects();

  engine.load(QUrl("qrc:/main.qml"));

  return app.exec();
}
